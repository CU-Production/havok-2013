/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

// Physics specific product patches applied before release 660.
// This file is #included by hkpPatches_Legacy.cpp

//=======
// 650b1
//=======

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpStorageExtendedMeshShapeMaterial", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpMeshMaterial")
	HK_PATCH_MEMBER_ADDED("restitution", TYPE_STRUCT, "hkHalf", 0)
	HK_PATCH_MEMBER_ADDED("friction", TYPE_STRUCT, "hkHalf", 0)
	HK_PATCH_MEMBER_ADDED("userData", TYPE_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkpMeshMaterial", 0)
	HK_PATCH_DEPENDS("hkHalf", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpFirstPersonGun", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED_CSTRING("name", "")
	HK_PATCH_MEMBER_ADDED_BYTE("keyboardKey", 113)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpBallGun", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpFirstPersonGun")
	HK_PATCH_MEMBER_ADDED_REAL("bulletRadius", 0.200000f)
	HK_PATCH_MEMBER_ADDED_REAL("bulletVelocity", 40.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("bulletMass", 50.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("damageMultiplier", 50.000000f)
	HK_PATCH_MEMBER_ADDED_INT("maxBulletsInWorld", 100)
	HK_PATCH_MEMBER_ADDED_VEC_4("bulletOffsetFromCenter", 0.000000f,0.000000f,0.000000f,0.000000f)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpFirstPersonGun", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpGravityGun", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpFirstPersonGun")
	HK_PATCH_MEMBER_ADDED_INT("maxNumObjectsPicked", 10)
	HK_PATCH_MEMBER_ADDED_REAL("maxMassOfObjectPicked", 200.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("maxDistOfObjectPicked", 50.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("impulseAppliedWhenObjectNotPicked", 100.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("throwVelocity", 50.000000f)
	HK_PATCH_MEMBER_ADDED_VEC_4("capturedObjectPosition", 2.500000f,0.600000f,0.000000f,0.000000f)
	HK_PATCH_MEMBER_ADDED_VEC_4("capturedObjectsOffset", 0.000000f,1.000000f,0.000000f,0.000000f)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpFirstPersonGun", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpProjectileGun", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpFirstPersonGun")
	HK_PATCH_MEMBER_ADDED_INT("maxProjectiles", 5)
	HK_PATCH_MEMBER_ADDED_REAL("reloadTime", 0.300000f)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpFirstPersonGun", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpMountedBallGun", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpBallGun")
	HK_PATCH_MEMBER_ADDED_VEC_4("position", 0.000000f,100.000000f,0.000000f,0.000000f)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpBallGun", 0)
	HK_PATCH_DEPENDS("hkpFirstPersonGun", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpShapeRayBundleCastInput", 0)
	HK_PATCH_MEMBER_ADDED("from", TYPE_TUPLE_VEC_4, HK_NULL, 3)
	HK_PATCH_MEMBER_ADDED("to", TYPE_TUPLE_VEC_4, HK_NULL, 3)
	HK_PATCH_MEMBER_ADDED("filterInfo", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("rayShapeCollectionFilter", TYPE_OBJECT, "hkpRayShapeCollectionFilter", 0)
	HK_PATCH_DEPENDS("hkpRayShapeCollectionFilter", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpExtendedMeshShape", 0, "hkpExtendedMeshShape", 1)
	HK_PATCH_MEMBER_ADDED("defaultCollisionFilterInfo", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpExtendedMeshShapeTrianglesSubpart", 0, "hkpExtendedMeshShapeTrianglesSubpart", 1)
	HK_PATCH_MEMBER_ADDED("userData", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpConstraintInstance", 0, "hkpConstraintInstance", 1)
	HK_PATCH_MEMBER_ADDED("destructionRemapInfo", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_FUNCTION(hkpConstraintInstance_0_to_1)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpStorageExtendedMeshShapeShapeSubpartStorage", 0, "hkpStorageExtendedMeshShapeShapeSubpartStorage", 1)
	HK_PATCH_MEMBER_RENAMED("materials", "int_materials")
	HK_PATCH_MEMBER_ADDED("materials", TYPE_ARRAY_STRUCT, "hkpStorageExtendedMeshShapeMaterial", 0)
	HK_PATCH_FUNCTION(hkpStorageExtendedMeshShapeShapeSubpartStorage_0_to_1)
	HK_PATCH_MEMBER_REMOVED("int_materials", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkpMeshMaterial", 0)
	HK_PATCH_DEPENDS("hkpStorageExtendedMeshShapeMaterial", 0)
	HK_PATCH_DEPENDS("hkHalf", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpStorageExtendedMeshShapeMeshSubpartStorage", 0, "hkpStorageExtendedMeshShapeMeshSubpartStorage", 1)
	HK_PATCH_MEMBER_RENAMED("materials", "int_materials")
	HK_PATCH_MEMBER_ADDED("materials", TYPE_ARRAY_STRUCT, "hkpStorageExtendedMeshShapeMaterial", 0)
	HK_PATCH_FUNCTION(hkpStorageExtendedMeshShapeMeshSubpartStorage_0_to_1)
	HK_PATCH_MEMBER_REMOVED("int_materials", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkpMeshMaterial", 0)
	HK_PATCH_DEPENDS("hkpStorageExtendedMeshShapeMaterial", 0)
	HK_PATCH_DEPENDS("hkHalf", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpWorldCinfo", 0, "hkpWorldCinfo", 1)
	HK_PATCH_MEMBER_ADDED_BOOL("useKdTree", false)
	HK_PATCH_MEMBER_ADDED_BOOL("autoUpdateKdTree", true)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpMotion", 0, "hkpMotion", 1)
	HK_PATCH_MEMBER_RENAMED("savedMotion", "max_savedMotion")
	HK_PATCH_MEMBER_ADDED("savedMotion", TYPE_OBJECT, "hkpMotion", 0)
	HK_PATCH_MEMBER_ADDED("gravityFactor", TYPE_STRUCT, "hkHalf", 0)
	HK_PATCH_FUNCTION(hkpMotion_0_to_1)
	HK_PATCH_MEMBER_REMOVED("max_savedMotion", TYPE_OBJECT, "hkpMaxSizeMotion", 0)
	HK_PATCH_DEPENDS("hkpKeyframedRigidMotion", 0)
	HK_PATCH_DEPENDS("hkpMaxSizeMotion", 0)
	HK_PATCH_DEPENDS("hkHalf", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpEntity", 0, "hkpEntity", 1)
	HK_PATCH_MEMBER_RENAMED("motion", "max_motion")
	HK_PATCH_MEMBER_ADDED("motion", TYPE_STRUCT, "hkpMotion", 0)
	HK_PATCH_FUNCTION(hkpEntity_0_to_1)
	HK_PATCH_MEMBER_REMOVED("max_motion", TYPE_STRUCT, "hkpMaxSizeMotion", 0)
	HK_PATCH_DEPENDS("hkpMotion", 0)
	HK_PATCH_DEPENDS("hkpKeyframedRigidMotion", 0)
	HK_PATCH_DEPENDS("hkpMaxSizeMotion", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpPairwiseCollisionFilterCollisionPair", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("a", TYPE_OBJECT, "hkpEntity", 0)
	HK_PATCH_MEMBER_REMOVED("b", TYPE_OBJECT, "hkpEntity", 0)
	HK_PATCH_DEPENDS("hkpEntity", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpWorldObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpPairwiseCollisionFilter", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkpCollisionFilter", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("disabledPairs", TYPE_ARRAY_STRUCT, "hkpPairwiseCollisionFilterCollisionPair", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkpCollisionFilter", 0)
	HK_PATCH_DEPENDS("hkpPairwiseCollisionFilterCollisionPair", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpCenterOfMassChangerModifierConstraintAtom", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpModifierConstraintAtom")
	HK_PATCH_MEMBER_ADDED("displacementA", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("displacementB", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkpModifierConstraintAtom", 0)
	HK_PATCH_DEPENDS("hkpConstraintAtom", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpMassChangerModifierConstraintAtom", 0, "hkpMassChangerModifierConstraintAtom", 1)
	HK_PATCH_MEMBER_RENAMED("factorA", "old_factorA")
	HK_PATCH_MEMBER_RENAMED("factorB", "old_factorB")
	HK_PATCH_MEMBER_ADDED("factorA", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("factorB", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_FUNCTION(hkpMassChangerModifierConstraintAtom_0_to_1)
	HK_PATCH_MEMBER_REMOVED("old_factorA", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("old_factorB", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpVehicleInstanceWheelInfo", 0, "hkpVehicleInstanceWheelInfo",1)
	HK_PATCH_MEMBER_RENAMED("contactShapeKey", "old_contactShapeKey")
	HK_PATCH_MEMBER_ADDED("contactShapeKey", TYPE_TUPLE_INT, HK_NULL, 8)
	HK_PATCH_FUNCTION(hkpVehicleInstanceWheelInfo_0_to_1)
	HK_PATCH_MEMBER_REMOVED("old_contactShapeKey", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpWorldCinfo", 1, "hkpWorldCinfo", 2)
	HK_PATCH_MEMBER_ADDED_REAL("numToisTillAllowedPenetrationSimplifiedToi", 3.0f)
	HK_PATCH_MEMBER_ADDED_REAL("numToisTillAllowedPenetrationToi", 3.0f)
	HK_PATCH_MEMBER_ADDED_REAL("numToisTillAllowedPenetrationToiHigher", 4.0f)
	HK_PATCH_MEMBER_ADDED_REAL("numToisTillAllowedPenetrationToiForced", 20.0f)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpConstraintInstanceSmallArraySerializeOverrideType", 0)
	HK_PATCH_MEMBER_ADDED("data", TYPE_OBJECT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("size", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("capacityAndFlags", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpBallSocketConstraintAtom", 0, "hkpBallSocketConstraintAtom", 1)
	// Unfortunately this needs to be treated as an int, the serialization
	// system won't convert implicitly from a float to a byte
	HK_PATCH_MEMBER_ADDED_BYTE("stabilizationFactor", 48) // 1.0f as hkUFloat8
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpBreakableBody", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpStorageExtendedMeshShapeMeshSubpartStorage", 1, "hkpStorageExtendedMeshShapeMeshSubpartStorage", 2)
	HK_PATCH_MEMBER_ADDED("indices8", TYPE_ARRAY_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpExtendedMeshShapeTrianglesSubpart", 1, "hkpExtendedMeshShapeTrianglesSubpart", 2)
	HK_PATCH_FUNCTION(hkpExtendedMeshShapeTrianglesSubpart_1_to_2)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpStorageExtendedMeshShapeMaterial", 0, "hkpStorageExtendedMeshShapeMaterial", 1)
	HK_PATCH_MEMBER_RENAMED("restitution", "old_restitution")
	HK_PATCH_MEMBER_RENAMED("friction", "old_friction")
	HK_PATCH_MEMBER_ADDED("restitution", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("friction", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_FUNCTION(hkpStorageExtendedMeshShapeMaterial_0_to_1)
	HK_PATCH_MEMBER_REMOVED("old_restitution", TYPE_STRUCT, "hkHalf", 0)
	HK_PATCH_MEMBER_REMOVED("old_friction", TYPE_STRUCT, "hkHalf", 0)
	HK_PATCH_DEPENDS("hkHalf", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpMotion", 1, "hkpMotion", 2)
	HK_PATCH_MEMBER_RENAMED("gravityFactor", "old_gravityFactor")
	HK_PATCH_MEMBER_ADDED("gravityFactor", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_FUNCTION(hkpMotion_1_to_2)
	HK_PATCH_MEMBER_REMOVED("old_gravityFactor", TYPE_STRUCT, "hkHalf", 0)
	HK_PATCH_DEPENDS("hkHalf", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpSpatialRigidBodyDeactivatorSample", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("refPosition", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("refRotation", TYPE_VEC_4, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpSpatialRigidBodyDeactivator", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkpRigidBodyDeactivator", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("highFrequencySample", TYPE_STRUCT, "hkpSpatialRigidBodyDeactivatorSample", 0)
	HK_PATCH_MEMBER_REMOVED("lowFrequencySample", TYPE_STRUCT, "hkpSpatialRigidBodyDeactivatorSample", 0)
	HK_PATCH_MEMBER_REMOVED("radiusSqrd", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minHighFrequencyTranslation", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minHighFrequencyRotation", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minLowFrequencyTranslation", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minLowFrequencyRotation", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpRigidBodyDeactivator", 0)
	HK_PATCH_DEPENDS("hkpEntityDeactivator", 0)
	HK_PATCH_DEPENDS("hkpSpatialRigidBodyDeactivatorSample", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpRigidBodyDeactivator", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkpEntityDeactivator", HK_NULL)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpEntityDeactivator", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpFakeRigidBodyDeactivator", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkpRigidBodyDeactivator", HK_NULL)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpRigidBodyDeactivator", 0)
	HK_PATCH_DEPENDS("hkpEntityDeactivator", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpEntityDeactivator", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkReferencedObject", HK_NULL)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpConvexVerticesShape", 0, "hkpConvexVerticesShape", 1)
	HK_PATCH_MEMBER_REMOVED("connectivity", TYPE_OBJECT, "hkpConvexVerticesConnectivity", 0) // force realloc
	HK_PATCH_MEMBER_ADDED("connectivity", TYPE_OBJECT, "hkpConvexVerticesConnectivity", 0) // force recalc
	HK_PATCH_DEPENDS("hkpConvexVerticesConnectivity", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpConvexDecompositionShapeConfig", 0)
	HK_PATCH_MEMBER_ADDED("createConnectivity", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("removeUnreferencedVertices", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("minCosAngle", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("minimumArea", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("radius", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()


HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpConvexDecompositionConfiguration2", 1)
	HK_PATCH_MEMBER_ADDED("minReachableDistance", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("minOverlapDistance", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("minExtrusion", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("maxExtrusion", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("minEdgeTetraVolume", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("maxMergeError", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("maxOverlapMergeError", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("maxOverlapPenetration", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("maxSkinError", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("maxOverlapVolume", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("maxPieces", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("maxDepth", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("forcedOverlapResolution", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("searchForTetrahedrons", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("enableFlooding", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("enableMerging", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("enableIterativeOverlapSolver", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpWorldCinfo", 2, "hkpWorldCinfo", 3)
	HK_PATCH_MEMBER_ADDED_BYTE("mtPostponeAndSortBroadPhaseBorderCallbacks", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpVehicleLinearCastWheelCollide", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpVehicleWheelCollide")
	HK_PATCH_MEMBER_ADDED("wheelCollisionFilterInfo", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("wheelStates", TYPE_ARRAY_STRUCT, "hkpVehicleLinearCastWheelCollideWheelState", 0)
	HK_PATCH_MEMBER_ADDED("rejectChassisListener", TYPE_STRUCT, "hkpRejectChassisListener", 0)
	HK_PATCH_MEMBER_ADDED("maxExtraPenetration", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("startPointTolerance", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkpVehicleWheelCollide", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkpVehicleLinearCastWheelCollideWheelState", 0)
	HK_PATCH_DEPENDS("hkpRejectChassisListener", 1)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpRejectRayChassisListener", 0, "hkpRejectChassisListener", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpVehicleRayCastBatchingManager", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpVehicleCastBatchingManager")
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpVehicleCastBatchingManager", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkpVehicleManager", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpVehicleManager", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("registeredVehicles", TYPE_ARRAY_OBJECT, "hkpVehicleInstance", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpVehicleInstance", 0)
	HK_PATCH_DEPENDS("hkpAction", 0)
	HK_PATCH_DEPENDS("hkpUnaryAction", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpVehicleRaycastWheelCollide", 0, "hkpVehicleRayCastWheelCollide", 1)
	HK_PATCH_DEPENDS("hkpAabbPhantom", 0)
	HK_PATCH_DEPENDS("hkpPhantom", 0)
	HK_PATCH_DEPENDS("hkpVehicleWheelCollide", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpWorldObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkpRejectChassisListener", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpVehicleLinearCastBatchingManager", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpVehicleCastBatchingManager")
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpVehicleCastBatchingManager", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkpVehicleManager", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpVehicleCastBatchingManager", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkpVehicleManager")
	HK_PATCH_MEMBER_ADDED("totalNumWheels", TYPE_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkpVehicleManager", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkpVehicleLinearCastWheelCollideWheelState", 0)
	HK_PATCH_MEMBER_ADDED("phantom", TYPE_OBJECT, "hkpAabbPhantom", 0)
	HK_PATCH_MEMBER_ADDED("shape", TYPE_OBJECT, "hkpShape", 0)
	HK_PATCH_MEMBER_ADDED("transform", TYPE_VEC_16, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("to", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkpAabbPhantom", 0)
	HK_PATCH_DEPENDS("hkpPhantom", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkpWorldObject", 0)
	HK_PATCH_DEPENDS("hkpShape", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpVehicleData", 0, "hkpVehicleData", 1)
	HK_PATCH_MEMBER_RENAMED("normalClippingAngle", "normalClippingAngleCos")
HK_PATCH_END()

HK_PATCH_BEGIN("hkpConvexDecompositionShapeConfig", 0, "hkpConvexDecompositionShapeConfig", 1)
	HK_PATCH_MEMBER_ADDED("margin", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpConvexDecompositionShapeConfig", 1, "hkpConvexDecompositionShapeConfig", 2)
	HK_PATCH_MEMBER_REMOVED("margin", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpStabilizedSphereMotion", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkpSphereMotion", HK_NULL)
	HK_PATCH_DEPENDS("hkpSphereMotion", 0)
	HK_PATCH_DEPENDS("hkpMotion", 2)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpStabilizedBoxMotion", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkpBoxMotion", HK_NULL)
	HK_PATCH_DEPENDS("hkpMotion", 2)
	HK_PATCH_DEPENDS("hkpBoxMotion", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpMotion", 2, "hkpMotion", 3)
	HK_PATCH_FUNCTION(hkpMotion_2_to_3)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpConvexDecompositionShapeConfig", 2, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("createConnectivity", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("removeUnreferencedVertices", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minCosAngle", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minimumArea", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("radius", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkpConvexDecompositionConfiguration2", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("minReachableDistance", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minOverlapDistance", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minExtrusion", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxExtrusion", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minEdgeTetraVolume", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxMergeError", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxOverlapMergeError", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxOverlapPenetration", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxSkinError", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxOverlapVolume", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxPieces", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxDepth", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("forcedOverlapResolution", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("searchForTetrahedrons", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("enableFlooding", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("enableMerging", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("enableIterativeOverlapSolver", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

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
