// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ALSUtility/Public/TimeLine/TimeLineObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTimeLineObject() {}
// Cross Module References
	ALSUTILITY_API UFunction* Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature();
	ALSUTILITY_API UClass* Z_Construct_UClass_UTimeLineObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ALSUTILITY_API UClass* Z_Construct_UClass_UTimeLineObject_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_ALSUtility();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveVector_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics
	{
		struct TimeLineObject_eventTimeLineDelegate_Parms
		{
			float F1;
			FVector F3;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_F1;
		static const UECodeGen_Private::FStructPropertyParams NewProp_F3;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::NewProp_F1 = { "F1", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TimeLineObject_eventTimeLineDelegate_Parms, F1), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::NewProp_F3 = { "F3", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TimeLineObject_eventTimeLineDelegate_Parms, F3), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::NewProp_F1,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::NewProp_F3,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTimeLineObject, nullptr, "TimeLineDelegate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::TimeLineObject_eventTimeLineDelegate_Parms), Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00930000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UTimeLineObject::execReverseFromEnd)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReverseFromEnd();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTimeLineObject::execReverse)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Reverse();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTimeLineObject::execSetNewTime)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetNewTime(Z_Param_Time);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTimeLineObject::execPlayFromStart)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlayFromStart();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTimeLineObject::execStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTimeLineObject::execPlay)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Play();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTimeLineObject::execTimeLineObject)
	{
		P_GET_OBJECT(UCurveFloat,Z_Param_CurveFloat);
		P_GET_OBJECT(UCurveVector,Z_Param_CurveVector);
		P_GET_PROPERTY(FFloatProperty,Z_Param_TimeStart);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTimeLineObject**)Z_Param__Result=UTimeLineObject::TimeLineObject(Z_Param_CurveFloat,Z_Param_CurveVector,Z_Param_TimeStart);
		P_NATIVE_END;
	}
	void UTimeLineObject::StaticRegisterNativesUTimeLineObject()
	{
		UClass* Class = UTimeLineObject::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Play", &UTimeLineObject::execPlay },
			{ "PlayFromStart", &UTimeLineObject::execPlayFromStart },
			{ "Reverse", &UTimeLineObject::execReverse },
			{ "ReverseFromEnd", &UTimeLineObject::execReverseFromEnd },
			{ "SetNewTime", &UTimeLineObject::execSetNewTime },
			{ "Stop", &UTimeLineObject::execStop },
			{ "TimeLineObject", &UTimeLineObject::execTimeLineObject },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UTimeLineObject_Play_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTimeLineObject_Play_Statics::Function_MetaDataParams[] = {
		{ "Category", "TimeLineObject" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTimeLineObject_Play_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTimeLineObject, nullptr, "Play", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTimeLineObject_Play_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTimeLineObject_Play_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTimeLineObject_Play()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTimeLineObject_Play_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTimeLineObject_PlayFromStart_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTimeLineObject_PlayFromStart_Statics::Function_MetaDataParams[] = {
		{ "Category", "TimeLineObject" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTimeLineObject_PlayFromStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTimeLineObject, nullptr, "PlayFromStart", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTimeLineObject_PlayFromStart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTimeLineObject_PlayFromStart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTimeLineObject_PlayFromStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTimeLineObject_PlayFromStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTimeLineObject_Reverse_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTimeLineObject_Reverse_Statics::Function_MetaDataParams[] = {
		{ "Category", "TimeLineObject" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTimeLineObject_Reverse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTimeLineObject, nullptr, "Reverse", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTimeLineObject_Reverse_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTimeLineObject_Reverse_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTimeLineObject_Reverse()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTimeLineObject_Reverse_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTimeLineObject_ReverseFromEnd_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTimeLineObject_ReverseFromEnd_Statics::Function_MetaDataParams[] = {
		{ "Category", "TimeLineObject" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTimeLineObject_ReverseFromEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTimeLineObject, nullptr, "ReverseFromEnd", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTimeLineObject_ReverseFromEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTimeLineObject_ReverseFromEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTimeLineObject_ReverseFromEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTimeLineObject_ReverseFromEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics
	{
		struct TimeLineObject_eventSetNewTime_Parms
		{
			float Time;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Time;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TimeLineObject_eventSetNewTime_Parms, Time), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::NewProp_Time,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "TimeLineObject" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTimeLineObject, nullptr, "SetNewTime", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::TimeLineObject_eventSetNewTime_Parms), Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTimeLineObject_SetNewTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTimeLineObject_SetNewTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTimeLineObject_Stop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTimeLineObject_Stop_Statics::Function_MetaDataParams[] = {
		{ "Category", "TimeLineObject" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTimeLineObject_Stop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTimeLineObject, nullptr, "Stop", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTimeLineObject_Stop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTimeLineObject_Stop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTimeLineObject_Stop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTimeLineObject_Stop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics
	{
		struct TimeLineObject_eventTimeLineObject_Parms
		{
			UCurveFloat* CurveFloat;
			UCurveVector* CurveVector;
			float TimeStart;
			UTimeLineObject* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurveFloat;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurveVector;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeStart;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::NewProp_CurveFloat = { "CurveFloat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TimeLineObject_eventTimeLineObject_Parms, CurveFloat), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::NewProp_CurveVector = { "CurveVector", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TimeLineObject_eventTimeLineObject_Parms, CurveVector), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::NewProp_TimeStart = { "TimeStart", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TimeLineObject_eventTimeLineObject_Parms, TimeStart), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TimeLineObject_eventTimeLineObject_Parms, ReturnValue), Z_Construct_UClass_UTimeLineObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::NewProp_CurveFloat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::NewProp_CurveVector,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::NewProp_TimeStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "TimeLine" },
		{ "CPP_Default_CurveVector", "None" },
		{ "CPP_Default_TimeStart", "0.000000" },
		{ "DisplayName", "TimeLineObject" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTimeLineObject, nullptr, "TimeLineObject", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::TimeLineObject_eventTimeLineObject_Parms), Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTimeLineObject_TimeLineObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTimeLineObject_TimeLineObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTimeLineObject);
	UClass* Z_Construct_UClass_UTimeLineObject_NoRegister()
	{
		return UTimeLineObject::StaticClass();
	}
	struct Z_Construct_UClass_UTimeLineObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnChangeValueDelegate_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnChangeValueDelegate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnFinishedDelegate_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFinishedDelegate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mTimeLength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_mTimeLength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mCurveFloat_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_mCurveFloat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mCurveVector_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_mCurveVector;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTimeLineObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ALSUtility,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UTimeLineObject_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UTimeLineObject_Play, "Play" }, // 539191029
		{ &Z_Construct_UFunction_UTimeLineObject_PlayFromStart, "PlayFromStart" }, // 2645081828
		{ &Z_Construct_UFunction_UTimeLineObject_Reverse, "Reverse" }, // 2186217819
		{ &Z_Construct_UFunction_UTimeLineObject_ReverseFromEnd, "ReverseFromEnd" }, // 4139199782
		{ &Z_Construct_UFunction_UTimeLineObject_SetNewTime, "SetNewTime" }, // 3274093266
		{ &Z_Construct_UFunction_UTimeLineObject_Stop, "Stop" }, // 3069011434
		{ &Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature, "TimeLineDelegate__DelegateSignature" }, // 1728554921
		{ &Z_Construct_UFunction_UTimeLineObject_TimeLineObject, "TimeLineObject" }, // 1184059803
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTimeLineObject_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "TimeLine/TimeLineObject.h" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnChangeValueDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnChangeValueDelegate = { "OnChangeValueDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTimeLineObject, OnChangeValueDelegate), Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnChangeValueDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnChangeValueDelegate_MetaData)) }; // 1728554921
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnFinishedDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnFinishedDelegate = { "OnFinishedDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTimeLineObject, OnFinishedDelegate), Z_Construct_UDelegateFunction_UTimeLineObject_TimeLineDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnFinishedDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnFinishedDelegate_MetaData)) }; // 1728554921
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mTimeLength_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mTimeLength = { "mTimeLength", nullptr, (EPropertyFlags)0x0041000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTimeLineObject, mTimeLength), METADATA_PARAMS(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mTimeLength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mTimeLength_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveFloat_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveFloat = { "mCurveFloat", nullptr, (EPropertyFlags)0x0041000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTimeLineObject, mCurveFloat), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveFloat_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveFloat_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveVector_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/TimeLine/TimeLineObject.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveVector = { "mCurveVector", nullptr, (EPropertyFlags)0x0041000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTimeLineObject, mCurveVector), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveVector_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTimeLineObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnChangeValueDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTimeLineObject_Statics::NewProp_OnFinishedDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mTimeLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveFloat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTimeLineObject_Statics::NewProp_mCurveVector,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTimeLineObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTimeLineObject>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTimeLineObject_Statics::ClassParams = {
		&UTimeLineObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UTimeLineObject_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UTimeLineObject_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTimeLineObject_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UTimeLineObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTimeLineObject()
	{
		if (!Z_Registration_Info_UClass_UTimeLineObject.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTimeLineObject.OuterSingleton, Z_Construct_UClass_UTimeLineObject_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTimeLineObject.OuterSingleton;
	}
	template<> ALSUTILITY_API UClass* StaticClass<UTimeLineObject>()
	{
		return UTimeLineObject::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTimeLineObject);
	struct Z_CompiledInDeferFile_FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTimeLineObject, UTimeLineObject::StaticClass, TEXT("UTimeLineObject"), &Z_Registration_Info_UClass_UTimeLineObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTimeLineObject), 2022791650U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_1010969718(TEXT("/Script/ALSUtility"),
		Z_CompiledInDeferFile_FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PhyiscalHit_Plugins_ALSUtility_Source_ALSUtility_Public_TimeLine_TimeLineObject_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
