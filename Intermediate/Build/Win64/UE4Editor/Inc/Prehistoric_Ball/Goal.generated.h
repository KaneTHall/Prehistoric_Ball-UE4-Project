// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PREHISTORIC_BALL_Goal_generated_h
#error "Goal.generated.h already included, missing '#pragma once' in Goal.h"
#endif
#define PREHISTORIC_BALL_Goal_generated_h

#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_SPARSE_DATA
#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_RPC_WRAPPERS
#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGoal(); \
	friend struct Z_Construct_UClass_AGoal_Statics; \
public: \
	DECLARE_CLASS(AGoal, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prehistoric_Ball"), NO_API) \
	DECLARE_SERIALIZER(AGoal)


#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAGoal(); \
	friend struct Z_Construct_UClass_AGoal_Statics; \
public: \
	DECLARE_CLASS(AGoal, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prehistoric_Ball"), NO_API) \
	DECLARE_SERIALIZER(AGoal)


#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGoal(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGoal) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGoal); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGoal); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGoal(AGoal&&); \
	NO_API AGoal(const AGoal&); \
public:


#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGoal(AGoal&&); \
	NO_API AGoal(const AGoal&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGoal); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGoal); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGoal)


#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArmComp() { return STRUCT_OFFSET(AGoal, SpringArmComp); } \
	FORCEINLINE static uint32 __PPO__GoalCam() { return STRUCT_OFFSET(AGoal, GoalCam); } \
	FORCEINLINE static uint32 __PPO__BoxComp() { return STRUCT_OFFSET(AGoal, BoxComp); } \
	FORCEINLINE static uint32 __PPO__GoalFrame() { return STRUCT_OFFSET(AGoal, GoalFrame); } \
	FORCEINLINE static uint32 __PPO__Goal() { return STRUCT_OFFSET(AGoal, Goal); }


#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_13_PROLOG
#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_PRIVATE_PROPERTY_OFFSET \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_SPARSE_DATA \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_RPC_WRAPPERS \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_INCLASS \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_PRIVATE_PROPERTY_OFFSET \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_SPARSE_DATA \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_INCLASS_NO_PURE_DECLS \
	Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PREHISTORIC_BALL_API UClass* StaticClass<class AGoal>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prehistoric_Ball_Source_Prehistoric_Ball_Goal_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
