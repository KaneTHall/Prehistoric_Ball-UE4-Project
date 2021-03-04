// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
struct FVector;
#ifdef PREHISTORIC_BALL_PlayerBall_generated_h
#error "PlayerBall.generated.h already included, missing '#pragma once' in PlayerBall.h"
#endif
#define PREHISTORIC_BALL_PlayerBall_generated_h

#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_SPARSE_DATA
#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOverlap); \
	DECLARE_FUNCTION(execCollision);


#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOverlap); \
	DECLARE_FUNCTION(execCollision);


#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerBall(); \
	friend struct Z_Construct_UClass_APlayerBall_Statics; \
public: \
	DECLARE_CLASS(APlayerBall, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prehistoric_Ball"), NO_API) \
	DECLARE_SERIALIZER(APlayerBall)


#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerBall(); \
	friend struct Z_Construct_UClass_APlayerBall_Statics; \
public: \
	DECLARE_CLASS(APlayerBall, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prehistoric_Ball"), NO_API) \
	DECLARE_SERIALIZER(APlayerBall)


#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerBall(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerBall) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerBall); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerBall); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerBall(APlayerBall&&); \
	NO_API APlayerBall(const APlayerBall&); \
public:


#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerBall(APlayerBall&&); \
	NO_API APlayerBall(const APlayerBall&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerBall); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerBall); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerBall)


#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArmComp() { return STRUCT_OFFSET(APlayerBall, SpringArmComp); } \
	FORCEINLINE static uint32 __PPO__PlayerCam() { return STRUCT_OFFSET(APlayerBall, PlayerCam); } \
	FORCEINLINE static uint32 __PPO__SphereComp() { return STRUCT_OFFSET(APlayerBall, SphereComp); } \
	FORCEINLINE static uint32 __PPO__Ball() { return STRUCT_OFFSET(APlayerBall, Ball); } \
	FORCEINLINE static uint32 __PPO__MovementForce() { return STRUCT_OFFSET(APlayerBall, MovementForce); }


#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_15_PROLOG
#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_PRIVATE_PROPERTY_OFFSET \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_SPARSE_DATA \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_RPC_WRAPPERS \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_INCLASS \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_PRIVATE_PROPERTY_OFFSET \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_SPARSE_DATA \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_INCLASS_NO_PURE_DECLS \
	Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PREHISTORIC_BALL_API UClass* StaticClass<class APlayerBall>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prehistoric_Ball_Source_Prehistoric_Ball_PlayerBall_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
