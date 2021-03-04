// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prehistoric_Ball/BallPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBallPlayerController() {}
// Cross Module References
	PREHISTORIC_BALL_API UClass* Z_Construct_UClass_ABallPlayerController_NoRegister();
	PREHISTORIC_BALL_API UClass* Z_Construct_UClass_ABallPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_Prehistoric_Ball();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	void ABallPlayerController::StaticRegisterNativesABallPlayerController()
	{
	}
	UClass* Z_Construct_UClass_ABallPlayerController_NoRegister()
	{
		return ABallPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ABallPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HUD_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HUD;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HUDClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_HUDClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABallPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_Prehistoric_Ball,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallPlayerController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "BallPlayerController.h" },
		{ "ModuleRelativePath", "BallPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUD_MetaData[] = {
		{ "Category", "BallPlayerController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BallPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUD = { "HUD", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallPlayerController, HUD), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUD_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUD_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUDClass_MetaData[] = {
		{ "Category", "BallPlayerController" },
		{ "ModuleRelativePath", "BallPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUDClass = { "HUDClass", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallPlayerController, HUDClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUDClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUDClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABallPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUD,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallPlayerController_Statics::NewProp_HUDClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABallPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABallPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABallPlayerController_Statics::ClassParams = {
		&ABallPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABallPlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayerController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABallPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABallPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABallPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABallPlayerController, 4052266942);
	template<> PREHISTORIC_BALL_API UClass* StaticClass<ABallPlayerController>()
	{
		return ABallPlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABallPlayerController(Z_Construct_UClass_ABallPlayerController, &ABallPlayerController::StaticClass, TEXT("/Script/Prehistoric_Ball"), TEXT("ABallPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABallPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
