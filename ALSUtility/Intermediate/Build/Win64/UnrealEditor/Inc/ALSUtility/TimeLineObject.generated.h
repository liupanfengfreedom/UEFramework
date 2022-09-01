// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCurveFloat;
class UCurveVector;
class UTimeLineObject;
#ifdef ALSUTILITY_TimeLineObject_generated_h
#error "TimeLineObject.generated.h already included, missing '#pragma once' in TimeLineObject.h"
#endif
#define ALSUTILITY_TimeLineObject_generated_h

#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_38_DELEGATE \
struct TimeLineObject_eventTimeLineDelegate_Parms \
{ \
	float F1; \
	FVector F3; \
}; \
static inline void FTimeLineDelegate_DelegateWrapper(const FMulticastScriptDelegate& TimeLineDelegate, float F1, FVector F3) \
{ \
	TimeLineObject_eventTimeLineDelegate_Parms Parms; \
	Parms.F1=F1; \
	Parms.F3=F3; \
	TimeLineDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_SPARSE_DATA
#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReverseFromEnd); \
	DECLARE_FUNCTION(execReverse); \
	DECLARE_FUNCTION(execSetNewTime); \
	DECLARE_FUNCTION(execPlayFromStart); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execPlay); \
	DECLARE_FUNCTION(execTimeLineObject);


#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReverseFromEnd); \
	DECLARE_FUNCTION(execReverse); \
	DECLARE_FUNCTION(execSetNewTime); \
	DECLARE_FUNCTION(execPlayFromStart); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execPlay); \
	DECLARE_FUNCTION(execTimeLineObject);


#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTimeLineObject(); \
	friend struct Z_Construct_UClass_UTimeLineObject_Statics; \
public: \
	DECLARE_CLASS(UTimeLineObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ALSUtility"), NO_API) \
	DECLARE_SERIALIZER(UTimeLineObject)


#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUTimeLineObject(); \
	friend struct Z_Construct_UClass_UTimeLineObject_Statics; \
public: \
	DECLARE_CLASS(UTimeLineObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ALSUtility"), NO_API) \
	DECLARE_SERIALIZER(UTimeLineObject)


#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTimeLineObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTimeLineObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTimeLineObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTimeLineObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTimeLineObject(UTimeLineObject&&); \
	NO_API UTimeLineObject(const UTimeLineObject&); \
public:


#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTimeLineObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTimeLineObject(UTimeLineObject&&); \
	NO_API UTimeLineObject(const UTimeLineObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTimeLineObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTimeLineObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTimeLineObject)


#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_15_PROLOG
#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_SPARSE_DATA \
	FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_RPC_WRAPPERS \
	FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_INCLASS \
	FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_SPARSE_DATA \
	FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_INCLASS_NO_PURE_DECLS \
	FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ALSUTILITY_API UClass* StaticClass<class UTimeLineObject>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
