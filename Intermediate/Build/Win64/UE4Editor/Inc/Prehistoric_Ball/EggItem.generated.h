// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PREHISTORIC_BALL_EggItem_generated_h
#error "EggItem.generated.h already included, missing '#pragma once' in EggItem.h"
#endif
#define PREHISTORIC_BALL_EggItem_generated_h

#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_SPARSE_DATA
#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_RPC_WRAPPERS
#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEggItem(); \
	friend struct Z_Construct_UClass_AEggItem_Statics; \
public: \
	DECLARE_CLASS(AEggItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prehistoric_Ball"), NO_API) \
	DECLARE_SERIALIZER(AEggItem)


#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAEggItem(); \
	friend struct Z_Construct_UClass_AEggItem_Statics; \
public: \
	DECLARE_CLASS(AEggItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prehistoric_Ball"), NO_API) \
	DECLARE_SERIALIZER(AEggItem)


#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEggItem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEggItem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEggItem); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEggItem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEggItem(AEggItem&&); \
	NO_API AEggItem(const AEggItem&); \
public:


#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEggItem(AEggItem&&); \
	NO_API AEggItem(const AEggItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEggItem); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEggItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEggItem)


#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CapsuleComp() { return STRUCT_OFFSET(AEggItem, CapsuleComp); } \
	FORCEINLINE static uint32 __PPO__Egg() { return STRUCT_OFFSET(AEggItem, Egg); } \
	FORCEINLINE static uint32 __PPO__Score() { return STRUCT_OFFSET(AEggItem, Score); } \
	FORCEINLINE static uint32 __PPO__RotationSpeed() { return STRUCT_OFFSET(AEggItem, RotationSpeed); }


#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_12_PROLOG
#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_PRIVATE_PROPERTY_OFFSET \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_SPARSE_DATA \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_RPC_WRAPPERS \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_INCLASS \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_PRIVATE_PROPERTY_OFFSET \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_SPARSE_DATA \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_INCLASS_NO_PURE_DECLS \
	Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PREHISTORIC_BALL_API UClass* StaticClass<class AEggItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prehistoric_Ball_Source_Prehistoric_Ball_EggItem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
