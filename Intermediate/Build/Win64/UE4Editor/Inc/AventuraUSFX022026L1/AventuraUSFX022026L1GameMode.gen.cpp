// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AventuraUSFX022026L1/AventuraUSFX022026L1GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAventuraUSFX022026L1GameMode() {}
// Cross Module References
	AVENTURAUSFX022026L1_API UClass* Z_Construct_UClass_AAventuraUSFX022026L1GameMode_NoRegister();
	AVENTURAUSFX022026L1_API UClass* Z_Construct_UClass_AAventuraUSFX022026L1GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_AventuraUSFX022026L1();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	AVENTURAUSFX022026L1_API UClass* Z_Construct_UClass_APlataforma_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(AAventuraUSFX022026L1GameMode::execSpawnearPlataformaAleatoria)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnearPlataformaAleatoria();
		P_NATIVE_END;
	}
	void AAventuraUSFX022026L1GameMode::StaticRegisterNativesAAventuraUSFX022026L1GameMode()
	{
		UClass* Class = AAventuraUSFX022026L1GameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SpawnearPlataformaAleatoria", &AAventuraUSFX022026L1GameMode::execSpawnearPlataformaAleatoria },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AAventuraUSFX022026L1GameMode_SpawnearPlataformaAleatoria_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAventuraUSFX022026L1GameMode_SpawnearPlataformaAleatoria_Statics::Function_MetaDataParams[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "AventuraUSFX022026L1GameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AAventuraUSFX022026L1GameMode_SpawnearPlataformaAleatoria_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAventuraUSFX022026L1GameMode, nullptr, "SpawnearPlataformaAleatoria", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AAventuraUSFX022026L1GameMode_SpawnearPlataformaAleatoria_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AAventuraUSFX022026L1GameMode_SpawnearPlataformaAleatoria_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AAventuraUSFX022026L1GameMode_SpawnearPlataformaAleatoria()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AAventuraUSFX022026L1GameMode_SpawnearPlataformaAleatoria_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AAventuraUSFX022026L1GameMode_NoRegister()
	{
		return AAventuraUSFX022026L1GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClasePlataformaIndestructible_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ClasePlataformaIndestructible;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClasePlataformaDestructible_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ClasePlataformaDestructible;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RangoSpawnMin_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RangoSpawnMin;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RangoSpawnMax_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RangoSpawnMax;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IntervaloSpawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_IntervaloSpawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AventuraUSFX022026L1,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AAventuraUSFX022026L1GameMode_SpawnearPlataformaAleatoria, "SpawnearPlataformaAleatoria" }, // 860299976
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AventuraUSFX022026L1GameMode.h" },
		{ "ModuleRelativePath", "AventuraUSFX022026L1GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaIndestructible_MetaData[] = {
		{ "Category", "Spawner" },
		{ "Comment", "// Clases de plataformas a spawnear (asignables desde el editor o por c?digo)\n" },
		{ "ModuleRelativePath", "AventuraUSFX022026L1GameMode.h" },
		{ "ToolTip", "Clases de plataformas a spawnear (asignables desde el editor o por c?digo)" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaIndestructible = { "ClasePlataformaIndestructible", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAventuraUSFX022026L1GameMode, ClasePlataformaIndestructible), Z_Construct_UClass_APlataforma_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaIndestructible_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaIndestructible_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaDestructible_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "AventuraUSFX022026L1GameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaDestructible = { "ClasePlataformaDestructible", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAventuraUSFX022026L1GameMode, ClasePlataformaDestructible), Z_Construct_UClass_APlataforma_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaDestructible_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaDestructible_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMin_MetaData[] = {
		{ "Category", "Spawner" },
		{ "Comment", "// Rango de spawn aleatorio\n" },
		{ "ModuleRelativePath", "AventuraUSFX022026L1GameMode.h" },
		{ "ToolTip", "Rango de spawn aleatorio" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMin = { "RangoSpawnMin", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAventuraUSFX022026L1GameMode, RangoSpawnMin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMin_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMax_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "AventuraUSFX022026L1GameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMax = { "RangoSpawnMax", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAventuraUSFX022026L1GameMode, RangoSpawnMax), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMax_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_IntervaloSpawn_MetaData[] = {
		{ "Category", "Spawner" },
		{ "Comment", "// Intervalo de spawn (segundos)\n" },
		{ "ModuleRelativePath", "AventuraUSFX022026L1GameMode.h" },
		{ "ToolTip", "Intervalo de spawn (segundos)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_IntervaloSpawn = { "IntervaloSpawn", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAventuraUSFX022026L1GameMode, IntervaloSpawn), METADATA_PARAMS(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_IntervaloSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_IntervaloSpawn_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaIndestructible,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_ClasePlataformaDestructible,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_RangoSpawnMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::NewProp_IntervaloSpawn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAventuraUSFX022026L1GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::ClassParams = {
		&AAventuraUSFX022026L1GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAventuraUSFX022026L1GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAventuraUSFX022026L1GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAventuraUSFX022026L1GameMode, 2263049241);
	template<> AVENTURAUSFX022026L1_API UClass* StaticClass<AAventuraUSFX022026L1GameMode>()
	{
		return AAventuraUSFX022026L1GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAventuraUSFX022026L1GameMode(Z_Construct_UClass_AAventuraUSFX022026L1GameMode, &AAventuraUSFX022026L1GameMode::StaticClass, TEXT("/Script/AventuraUSFX022026L1"), TEXT("AAventuraUSFX022026L1GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAventuraUSFX022026L1GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
