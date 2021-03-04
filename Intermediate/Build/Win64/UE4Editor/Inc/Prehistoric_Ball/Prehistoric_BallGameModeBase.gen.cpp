// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prehistoric_Ball/Prehistoric_BallGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrehistoric_BallGameModeBase() {}
// Cross Module References
	PREHISTORIC_BALL_API UClass* Z_Construct_UClass_APrehistoric_BallGameModeBase_NoRegister();
	PREHISTORIC_BALL_API UClass* Z_Construct_UClass_APrehistoric_BallGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Prehistoric_Ball();
// End Cross Module References
	void APrehistoric_BallGameModeBase::StaticRegisterNativesAPrehistoric_BallGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_APrehistoric_BallGameModeBase_NoRegister()
	{
		return APrehistoric_BallGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_APrehistoric_BallGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrehistoric_BallGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Prehistoric_Ball,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrehistoric_BallGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Prehistoric_BallGameModeBase.h" },
		{ "ModuleRelativePath", "Prehistoric_BallGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrehistoric_BallGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrehistoric_BallGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrehistoric_BallGameModeBase_Statics::ClassParams = {
		&APrehistoric_BallGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_APrehistoric_BallGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APrehistoric_BallGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrehistoric_BallGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrehistoric_BallGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrehistoric_BallGameModeBase, 2402645021);
	template<> PREHISTORIC_BALL_API UClass* StaticClass<APrehistoric_BallGameModeBase>()
	{
		return APrehistoric_BallGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrehistoric_BallGameModeBase(Z_Construct_UClass_APrehistoric_BallGameModeBase, &APrehistoric_BallGameModeBase::StaticClass, TEXT("/Script/Prehistoric_Ball"), TEXT("APrehistoric_BallGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrehistoric_BallGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
