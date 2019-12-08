/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HK_INTERNAL_CONVEXPIECEMESH_BUILDER_H
#define HK_INTERNAL_CONVEXPIECEMESH_BUILDER_H

#include <Common/Base/Container/PointerMap/hkPointerMap.h>
#include <Physics2012/Collide/Agent/hkpProcessCollisionInput.h>
#include <Physics2012/Internal/Collide/ConvexPieceMesh/hkpConvexPieceStreamData.h>
#include <Physics2012/Collide/Shape/Compound/Collection/hkpShapeCollection.h>

#include <Physics2012/Collide/Agent/Query/hkpLinearCastCollisionInput.h>

class hkpClosestCdPointCollector;
class hkpTriangleShape;
class hkpMeshShape;

//#include <hkvisualize/shape/hkDisplayGeometry.h>


/// This is a helper class which allows the hkpConvexPieceMeshBuilder to query the material of individual childShapes
/// of the hkCollectionShape being converted to convex pieces. hkpConvexPieceMeshBuilder only merges childShapes
/// having the same material information.
class hkpShapeCollectionMaterialMediator
{
	public:
	HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_BASE,hkpShapeCollectionMaterialMediator);
		virtual ~hkpShapeCollectionMaterialMediator() { }
			/// Gets material ID for the child shape specified.
		virtual hkUint32 getMaterialOfShapeKey(hkpShapeKey key) const = 0;
};

/// This implementation returns hkpMeshMaterial::m_filterInfo associated with child shapes.
class hkpDefaultShapeCollectionMaterialMediator : public hkpShapeCollectionMaterialMediator
{
	public:
	HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_BASE,hkpDefaultShapeCollectionMaterialMediator);
		hkpDefaultShapeCollectionMaterialMediator(hkpMeshShape* meshShape) ;
		~hkpDefaultShapeCollectionMaterialMediator();

			/// Gets the hkpMeshMaterial::m_filterInfo of the specified child shape.
		hkUint32 getMaterialOfShapeKey(hkpShapeKey key) const;

	private:
		hkpMeshShape* m_meshShape;
};


///
/// Given a triangle based mesh, this class creates a simplified set of convex pieces
/// representing the same mesh.
///
///
/// The output can be passed to the hkpConvexPieceMeshShape which can then be wrapped in a
/// hkpMoppBvTreeShape and used as the simulation mesh in a game.
/// 
class hkpConvexPieceMeshBuilder: public hkReferencedObject
{
	public:
		HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_CDINFO);


			/// Constructs a new hkpConvexPieceMeshBuilder.
		hkpConvexPieceMeshBuilder();

			/// Destructs any mem allocated etc
		~hkpConvexPieceMeshBuilder();


			/// Creates a convex representation of the input mesh.
			/// The displayMesh must be a shapeCollection that returns
			/// children of type "hkpTriangleShape".
			/// 
			/// The maximum number of triangles in each convex piece can be
			/// specified here also. If maxTrianglesPerConvexPiece is -1, the max number
			/// of vertices that will fit in the shape buffer will be used.
		void convexifyLandscape( const hkpShapeCollection* inputMesh, hkpCollisionInput* collisionInput, hkpConvexPieceStreamData& convexPieceStreamDataOut, hkpShapeCollectionMaterialMediator* materialMediator = HK_NULL, int maxVerticesPerConvexPiece = -1 );


	protected:

		struct TriangleInfo
		{
			HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_CDINFO, TriangleInfo);
	
			char m_flags;
			hkBool m_vertsUsed[3];
			//hkUint16 m_lightInfo; /*HK_TRIANGLELIGHT_INFO*/

			// members used by the lighting algorithm
			int m_convexPieceOffset;
		};

			///
		struct BuilderInput
		{
			HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_CDINFO, BuilderInput);

			hkpCollidable* m_moppCollidable;
			hkpCollidable* m_sphereCollidable;
			hkReal m_sphereRadius;
			hkTransform* m_sphereTransform;
			const hkpShapeCollection* m_meshShape;
			const hkpShapeCollectionMaterialMediator* m_materialMediator;
			hkPointerMap<hkpShapeKey, hkUint32> m_shapeKeyToTriangleInfoIndex;
			hkArray< struct TriangleInfo > m_triangleInfo;
			struct hkpLinearCastCollisionInput m_collisionInput;

			BuilderInput() : m_moppCollidable(HK_NULL), m_sphereCollidable(HK_NULL),
			m_sphereRadius(0.0f), m_sphereTransform(HK_NULL) {}

			~BuilderInput() 
			{
				m_moppCollidable->getShape()->removeReference();
				delete m_moppCollidable;
				delete m_sphereCollidable;
				delete m_sphereTransform;
			}

		};


		/// Internal struct used to represent a convex piece.
		struct ConvexPiece
		{
			HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_CDINFO, ConvexPiece);

			///
			hkArray<hkpShapeKey> m_triangles;

			/// We store the vertices used in the convex piece here, since these
			/// are generated by calculating the convex hull of the convex piece.
			hkArray<hkVector4> m_vertices;

			/// Set true if this convex piece is not to be modified, e.g., it has
			/// been determined that this is the largest convex piece possible
			/// containing any of the triangles it has.
			hkBool m_fixedConvexPiece;

			/// There is also a bitfield in the triangleInfo for each triangle
			/// that indicates which vertices in that triangle are used here.
			char m_flags;

			ConvexPiece() : m_fixedConvexPiece(false), m_flags(0) {}
		};

	protected:

		hkBool isEqualNormal( const hkpTriangleShape* triangle, const hkpTriangleShape* neighbourTriangle, hkVector4& triNormal );

		void linearCastAgainstCentroid( hkpConvexPieceMeshBuilder::BuilderInput& input, const hkVector4& source, const hkpShapeKey& triKey, hkpClosestCdPointCollector& collector );

		void calcCentroidAndNormal( hkpConvexPieceMeshBuilder::BuilderInput& input, const hkpShapeKey& triKey, hkVector4& centroid, hkVector4& triNormal );

		bool canAssimilateVertex( const hkpShapeCollection* meshShape, const ConvexPiece& convexPiece, hkVector4Parameter vertex,
									hkVector4Parameter edge0, hkVector4Parameter edge1, hkVector4Parameter triNormal ) const;

		bool notEdgeVert( hkVector4Parameter vert1, hkVector4Parameter vert2, hkVector4Parameter vert3 ) const;

		bool canJoinConvexShapeToConvexShape( const hkpShapeCollection* meshShape, const hkpShapeCollectionMaterialMediator* materialMediator,
													const ConvexPiece& convexPiece, const ConvexPiece& neighbourConvexPiece );

		static inline TriangleInfo* getTriangleInfo(BuilderInput& input, hkpShapeKey key);

		void buildBuilderInput(const hkpShapeCollection* inputMesh, hkpCollisionInput* collisionInput, hkpConvexPieceMeshBuilder::BuilderInput& inputOut, hkpShapeCollectionMaterialMediator* materialMeidator = HK_NULL);

		void getConvexPieceAabb( BuilderInput& input, const ConvexPiece& convexPiece, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;

			/// Checks if the m_fixedConvexPiece flag has been set in the convex piece this triangle is in.
		hkBool isFixedTriangle( BuilderInput& input, const hkpShapeKey key );

		hkBool isNotDegenerateTriangle( BuilderInput& input, const hkpShapeKey key );

		hkBool isGoodTriangle( BuilderInput& input, const hkpShapeKey key );

		void joinFlatTriangles( BuilderInput& input );

		void filterCollinearVertices( BuilderInput& input, ConvexPiece& convexPiece );
		void generatePlaneEquationsForConvexPiece( BuilderInput& input, ConvexPiece& convexPiece, hkArray< hkVector4 >& planeEquations, hkBool runExtraCollinearFilter );

	protected:

		//
		// Optimised bit stream structure.
		//

		void convertArraysToStream( hkpConvexPieceMeshBuilder::BuilderInput& input,
									hkpConvexPieceStreamData& convexPieceMeshOut );

		int calcStreamSize( const hkArray< ConvexPiece* >& convexPieces );

			/// Build the stream data from the input arrays.
		void buildStreamData( hkpConvexPieceMeshBuilder::BuilderInput& input,
								const hkArray< ConvexPiece* >& convexPieces, 
								hkArray< hkUint32 >& stream, 
								hkArray< hkUint32 >& convexPieceOffsets,
								hkArray< hkUint32 >& convexPieceSingleTriangles );

		void deallocatePieces();

		// Intermediate structure used during construction of convex pieces.
		hkArray<struct ConvexPiece*>	m_convexPieces;

		int m_maxVerticesPerConvexPiece;

	public:
		hkpConvexPieceMeshBuilder( hkFinishLoadedObjectFlag flag ) {}

};


#endif // HK_INTERNAL_CONVEXPIECEMESH_BUILDER_H

/*
 * Havok SDK - NO SOURCE PC DOWNLOAD, BUILD(#20130718)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2013
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available at www.havok.com/tryhavok.
 * 
 */
