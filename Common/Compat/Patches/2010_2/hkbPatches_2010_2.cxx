/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

// Behavior specific product patches applied to release 2010_2.
// This file is #included by hkbPatches_2010_2.cpp

HK_PATCH_BEGIN("hkbVariableValueSet", 0, "hkbVariableValueSet", 1)
	HK_PATCH_MEMBER_RENAMED("variantVariableValues", "old_variantVariableValues")
	HK_PATCH_MEMBER_ADDED("variantVariableValues",  TYPE_ARRAY_OBJECT, "hkReferencedObject", 0)
	HK_PATCH_FUNCTION(hkbVariableValueSet_0_to_1)
	HK_PATCH_MEMBER_REMOVED("old_variantVariableValues", TYPE_ARRAY_OBJECT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbLuaModifier", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkbModifier")
	HK_PATCH_MEMBER_ADDED("luaScriptOnPrecompute", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("luaScriptOnActivate", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("luaScriptOnDeactivate", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("luaScriptOnModify", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("luaScriptOnPreUpdate", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("luaScriptOnUpdate", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("luaScriptOnHandleEvent", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbModifier", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbLuaModifier", 0, "hkbLuaModifier", 1)
	HK_PATCH_MEMBER_REMOVED("luaScriptOnPreUpdate", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbModifier", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterStringData", 5, "hkbCharacterStringData", 6)
	HK_PATCH_MEMBER_ADDED("luaScriptOnCharacterActivated", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("luaScriptOnCharacterDeactivated", TYPE_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbProjectStringData", 1, "hkbProjectStringData", 2)
	HK_PATCH_MEMBER_ADDED("scriptsPath", TYPE_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbGeneratorTransitionEffect", 1, "hkbGeneratorTransitionEffect", 2)
	HK_PATCH_MEMBER_ADDED("childState", TYPE_TUPLE_INT, HK_NULL, 2)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbDemoConfig", 3, "hkbDemoConfig", 4)
	HK_PATCH_MEMBER_DEFAULT_SET_INT("numTracks", 22)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbBlendingTransitionEffect", 1, "hkbBlendingTransitionEffect", 2)
	HK_PATCH_MEMBER_ADDED_INT("alignmentBone", -1)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbMoveBoneAttachmentModifier", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkbModifier")
	HK_PATCH_MEMBER_ADDED_INT("activateEventId", -1)
	HK_PATCH_MEMBER_ADDED("attachment", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("localFrame", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbModifier", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbScriptGenerator", 0)
    HK_PATCH_PARENT_SET(HK_NULL, "hkbGenerator")
    HK_PATCH_MEMBER_ADDED("child", TYPE_OBJECT, "hkbGenerator", 0)
    HK_PATCH_MEMBER_ADDED("onActivateScript", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("onPreUpdateScript", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("onGenerateScript", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("onHandleEventScript", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("onDeactivateScript", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_DEPENDS("hkbNode", 1)
    HK_PATCH_DEPENDS("hkBaseObject", 0)
    HK_PATCH_DEPENDS("hkbGenerator", 0)
    HK_PATCH_DEPENDS("hkbBindable", 0)
    HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterStringData", 6, "hkbCharacterStringData", 7)
	HK_PATCH_MEMBER_ADDED("luaFiles", TYPE_ARRAY_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbDockingGeneratorInternalState", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("localTime", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("previousLocalTime", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("intervalStartLocalTime", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("intervalEndLocalTime", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbDockingGenerator", 0)
        HK_PATCH_PARENT_SET(HK_NULL, "hkbGenerator")
        HK_PATCH_MEMBER_ADDED_INT("dockingBone", -1)
        HK_PATCH_MEMBER_ADDED("translationOffset", TYPE_VEC_4, HK_NULL, 0)
        HK_PATCH_MEMBER_ADDED("rotationOffset", TYPE_VEC_4, HK_NULL, 0)
        HK_PATCH_MEMBER_ADDED("blendType", TYPE_INT, HK_NULL, 0)
        HK_PATCH_MEMBER_ADDED_INT("flags", 0)
        HK_PATCH_MEMBER_ADDED("child", TYPE_OBJECT, "hkbGenerator", 0)
        HK_PATCH_MEMBER_ADDED_INT("intervalStart", -1)
        HK_PATCH_MEMBER_ADDED_INT("intervalEnd", -1)
        HK_PATCH_MEMBER_ADDED("previousLocalTime", TYPE_REAL, HK_NULL, 0)
        HK_PATCH_MEMBER_ADDED("intervalStartLocalTime", TYPE_REAL, HK_NULL, 0)
        HK_PATCH_MEMBER_ADDED("intervalEndLocalTime", TYPE_REAL, HK_NULL, 0)
        HK_PATCH_DEPENDS("hkbNode", 1)
        HK_PATCH_DEPENDS("hkBaseObject", 0)
        HK_PATCH_DEPENDS("hkbGenerator", 0)
        HK_PATCH_DEPENDS("hkbBindable", 0)
        HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbVariableBounds", 0)
	HK_PATCH_MEMBER_ADDED("min", TYPE_STRUCT, "hkbVariableValue", 0)
	HK_PATCH_MEMBER_ADDED("max", TYPE_STRUCT, "hkbVariableValue", 0)
	HK_PATCH_DEPENDS("hkbVariableValue", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbBehaviorGraphData", 2, "hkbBehaviorGraphData", 3)
	HK_PATCH_MEMBER_ADDED("variableBounds", TYPE_ARRAY_STRUCT, "hkbVariableBounds", 0)
	HK_PATCH_FUNCTION(hkbBehaviorGraphData_2_to_3)
	HK_PATCH_MEMBER_REMOVED("wordMinVariableValues", TYPE_ARRAY_STRUCT, "hkbVariableValue", 0)
	HK_PATCH_MEMBER_REMOVED("wordMaxVariableValues", TYPE_ARRAY_STRUCT, "hkbVariableValue", 0)
	HK_PATCH_DEPENDS("hkbVariableValue", 0)
	HK_PATCH_DEPENDS("hkbVariableBounds", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbBlendingTransitionEffectInternalState", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("fromPos", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("fromRot", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("toPos", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("toRot", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("lastPos", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("lastRot", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("alignmentFinished", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("characterPoseAtBeginningOfTransition", TYPE_ARRAY_VEC_12, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("timeRemaining", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("timeInTransition", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("applySelfTransition", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("initializeCharacterPose", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("alignThisFrame", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbManualSelectorGenerator", 0, "hkbManualSelectorGenerator", 1)
	HK_PATCH_MEMBER_ADDED_BYTE("selectedIndexCanChangeAfterActivate", 1)
	HK_PATCH_MEMBER_ADDED("generatorIndexAtActivate", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbCharacterControllerModifierControlData", 0)
	HK_PATCH_MEMBER_ADDED_REAL("verticalGain", 1.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("horizontalCatchUpGain", 1.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("maxVerticalSeparation", 0.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("maxHorizontalSeparation", 0.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterControllerModifier", 0, "hkbCharacterControllerModifier", 1)
	HK_PATCH_MEMBER_RENAMED("controlData", "old_controlData")	
	HK_PATCH_MEMBER_ADDED("controlData", TYPE_STRUCT, "hkbCharacterControllerModifierControlData", 0)
	HK_PATCH_FUNCTION(hkbCharacterControllerModifier_0_to_1)
	HK_PATCH_MEMBER_REMOVED("old_controlData", TYPE_STRUCT, "hkbCharacterControllerControlData", 0)	
	HK_PATCH_DEPENDS("hkbCharacterControllerModifierControlData", 0)	
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterControllerControlData", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("desiredVelocity", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("verticalGain", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("horizontalCatchUpGain", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxVerticalSeparation", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxHorizontalSeparation", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbSetSelectedCharacterCommand", 0)
    HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
    HK_PATCH_MEMBER_ADDED("characterId", TYPE_INT, HK_NULL, 0)
    HK_PATCH_DEPENDS("hkBaseObject", 0)
    HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbCharacterStringDataFileNameMeshNamePair", 0)
	HK_PATCH_MEMBER_ADDED("fileName", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("meshName", TYPE_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterStringData", 7, "hkbCharacterStringData", 8)	
	HK_PATCH_MEMBER_ADDED("skinNames", TYPE_ARRAY_STRUCT, "hkbCharacterStringDataFileNameMeshNamePair", 0)
	HK_PATCH_MEMBER_ADDED("boneAttachmentNames", TYPE_ARRAY_STRUCT, "hkbCharacterStringDataFileNameMeshNamePair", 0)
	HK_PATCH_FUNCTION(hkbCharacterStringData_7_to_8)
	HK_PATCH_MEMBER_REMOVED("deformableSkinNames", TYPE_ARRAY_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("rigidSkinNames", TYPE_ARRAY_CSTRING, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkbCharacterStringDataFileNameMeshNamePair", 0)	
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterData", 7, "hkbCharacterData", 8)
	HK_PATCH_MEMBER_ADDED("boneAttachmentBoneIndices", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("boneAttachmentTransforms", TYPE_ARRAY_VEC_16, HK_NULL, 0)	
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbCharacterSelectedInfo", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("characterId", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("scriptDebuggingPort", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("padding", TYPE_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterAddedInfo", 0, "hkbCharacterAddedInfo", 1)
	HK_PATCH_MEMBER_ADDED("localScriptsPath", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("remoteScriptsPath", TYPE_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbClientCharacterState", 1, "hkbClientCharacterState", 2)
	HK_PATCH_MEMBER_ADDED("localScriptsPath", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("remoteScriptsPath", TYPE_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbCharacterControllerModifierInternalState", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("gravity", TYPE_VEC_4, HK_NULL, 0)	
	HK_PATCH_MEMBER_ADDED("isInitialVelocityAdded", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("isTouchingGround", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbPositionRelativeSelectorGeneratorInternalState", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkReferencedObject", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("entryPosition", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("entryForward", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("lastTargetPos", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("lastTargetRot", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("targetLinearDisp", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("targetAngularDisp", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("clipTime", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("currentGeneratorIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("usingBlendToFixPositionGenerator", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("doLeadInFixup", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbProxyModifierProxyInfo", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("dynamicFriction", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("staticFriction", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("keepContactTolerance", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("up", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("keepDistance", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("contactAngleSensitivity", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("userPlanes", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxCharacterSpeedForSolver", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("characterStrength", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("characterMass", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxSlope", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("penetrationRecoverySpeed", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxCastIterations", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("refreshManifoldInCheckSupport", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbSplinePathGenerator", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkbGenerator", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("registeredGenerators", TYPE_ARRAY_OBJECT, "hkbRegisteredGenerator", 0)
	HK_PATCH_MEMBER_REMOVED("characterForward", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("targetPosition", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("targetDirection", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("leadInGain", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("leadOutGain", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("useProximityTrigger", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("endEventProximity", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("endEventTime", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("selectedGeneratorIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("useManualSelection", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("trackPosition", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("usePathEstimation", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("useCharacterForward", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("currentGeneratorIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("pathEndEvent", TYPE_STRUCT, "hkbEventProperty", 0)
	HK_PATCH_DEPENDS("hkbEventProperty", 1)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkbRegisteredGenerator", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbGenerator", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkbEventBase", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbSplinePathGeneratorInternalState", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkReferencedObject", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("entryPosition", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("entryForward", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("exitPosition", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("exitForward", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("averageSpeed", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("pathTime", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("curTime", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("pathParam", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("currentGeneratorIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("doLeadInFixup", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("eventTriggered", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbRegisteredGenerator", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkbBindable", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("generator", TYPE_OBJECT, "hkbGenerator", 0)
	HK_PATCH_MEMBER_REMOVED("relativePosition", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("relativeDirection", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbGenerator", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbProxyModifier", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkbModifier", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("proxyInfo", TYPE_STRUCT, "hkbProxyModifierProxyInfo", 0)
	HK_PATCH_MEMBER_REMOVED("linearVelocity", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("horizontalGain", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("verticalGain", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxHorizontalSeparation", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxVerticalSeparation", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("verticalDisplacementError", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("verticalDisplacementErrorGain", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxVerticalDisplacement", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("minVerticalDisplacement", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("capsuleHeight", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("capsuleRadius", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("maxSlopeForRotation", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("collisionFilterInfo", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("phantomType", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("linearVelocityMode", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("ignoreIncomingRotation", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("ignoreCollisionDuringRotation", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("ignoreIncomingTranslation", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("includeDownwardMomentum", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("followWorldFromModel", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("isTouchingGround", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbModifier", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkbProxyModifierProxyInfo", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbPositionRelativeSelectorGenerator", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkbGenerator", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("registeredGenerators", TYPE_ARRAY_OBJECT, "hkbRegisteredGenerator", 0)
	HK_PATCH_MEMBER_REMOVED("blendToFixPositionGenerator", TYPE_OBJECT, "hkbGenerator", 0)
	HK_PATCH_MEMBER_REMOVED("autoComputeEntryPoints", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("transitionTime", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("useCharacterForward", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("characterForward", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("targetPosition", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("targetRotation", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("positionTolerance", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("fixPositionTolerance", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("endFixPositionEventId", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("useManualSelection", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("selectedGeneratorIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("entryPosition", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("entryForward", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("fixPositionEvent", TYPE_STRUCT, "hkbEventProperty", 0)
	HK_PATCH_DEPENDS("hkbEventProperty", 1)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkbRegisteredGenerator", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbGenerator", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkbEventBase", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbGeneratorTransitionEffect", 2, "hkbGeneratorTransitionEffect", 3)
	HK_PATCH_MEMBER_REMOVED("childState", TYPE_TUPLE_INT, HK_NULL, 2)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbToolNodeType", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbAttachmentSetup", 1, "hkbAttachmentSetup", 2)
	HK_PATCH_MEMBER_DEFAULT_SET_REAL("maxLinearDistance", 1.000000f)
	HK_PATCH_MEMBER_DEFAULT_SET_REAL("maxAngularDistance", 180.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbRebuildScriptsCommand", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("characterId", TYPE_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbHandIkModifierHand", 3, "hkbHandIkModifierHand", 4)
	HK_PATCH_MEMBER_REMOVED("handOrienationOffsetLS", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED_VEC_4("handOrientationOffsetLS", 0.000000f,0.000000f,0.000000f,1.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbReferencedGeneratorSyncInfo", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("syncInfo", TYPE_STRUCT, "hkbGeneratorSyncInfo", 0 )
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkbGeneratorSyncInfo", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbRigidBodyRagdollControlsModifier", 3, "hkbRigidBodyRagdollControlsModifier", 4)
	HK_PATCH_MEMBER_ADDED_REAL("animationBlendFraction", 0.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbPoweredRagdollControlsModifier", 5, "hkbPoweredRagdollControlsModifier", 6)
	HK_PATCH_MEMBER_ADDED_REAL("animationBlendFraction", 0.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbDemoConfig", 4, "hkbDemoConfig", 5)
	HK_PATCH_MEMBER_DEFAULT_SET_INT("numTracks", 23)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbLuaModifier", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkbModifier", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("luaScriptOnPrecompute", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("luaScriptOnActivate", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("luaScriptOnDeactivate", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("luaScriptOnModify", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("luaScriptOnUpdate", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("luaScriptOnHandleEvent", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbModifier", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
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
