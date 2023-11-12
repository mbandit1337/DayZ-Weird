#pragma once
#include "Globals.h"
#include "Singletons.h"
#include "Offsets.h"
#include "Vector.hpp"
#include "Vector2.h"
#include <d3dx10math.h>

#define UENGINE __stdcall
#define PI 3.14159265358979323846f
#define RAD2DEG (180.f / PI)
#define DEG2RAD (PI / 180.F)
namespace SDK
{
	namespace functions
	{	
		typedef void*(__fastcall* FnK2_TeleportTo)(void*, SDK::utils::maths::vectype2::FVector& LookatPos, float AngularSpeed, float DeltaTime);

		static FnK2_TeleportTo original_FnK2_TeleportTo = nullptr;
 


	}
}
 
inline uintptr_t GetBone = 0;





 
constexpr auto r2d = 57.2957795131f; /* 180 / pi, used for conversion from radians to degrees */
constexpr auto d2r = 0.01745329251f; /* pi / 180, used for conversion from degrees to radians */
constexpr auto pi = 3.14159265358979323846f;  /* pi */
namespace SDK
{
	namespace squad
	{
		template<class T>
		struct TArray
		{
		private:
			T* Data;
			int32_t Count;
			int32_t Max;

			friend struct FString;

		public:
			TArray()
			{
				Data = nullptr;
				Count = Max = 0;
			};

			int Num() const
			{
				return Count;
			};

			T& operator[](int i)
			{
				return Data[i];
			};

			const T& operator[](int i) const
			{
				return Data[i];
			};

			bool IsValidIndex(int i) const
			{
				return i < Num();
			}
		};

	 
		struct FString : public TArray<wchar_t>
		{
			FString() = default;

			explicit FString(const wchar_t* other)
			{
				Max = Count = *other ? std::wcslen(other) + 1 : 0;

				if (Count)
				{
					Data = const_cast<wchar_t*>(other);
				}
			};

			inline bool IsValid() const
			{
				return Data != nullptr;
			}

			inline const wchar_t* cw_str() const
			{
				return Data;
			}

			inline const char* c_str() const
			{
				return (const char*)Data;
			}

			std::string ToString() const
			{
				size_t length = std::wcslen(Data);
				std::string str(length, '\0');
				std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

				return str;
			}

			std::wstring ToWString() const
			{
				std::wstring str(Data);
				return str;
			}
		};

		class FNameEntry
		{
		public:
			static const auto NAME_WIDE_MASK = 0x1;
			static const auto NAME_INDEX_SHIFT = 1;

			int32_t Index;
			char UnknownData00 [ 0x04 ];
			FNameEntry* HashNext;
			union
			{
				char AnsiName [ 1024 ];
				wchar_t WideName [ 1024 ];
			};

			inline const int32_t GetIndex( ) const
			{
				return Index >> NAME_INDEX_SHIFT;
			}

			inline bool IsWide( ) const
			{
				return Index & NAME_WIDE_MASK;
			}

			inline const char* GetAnsiName( ) const
			{
				return AnsiName;
			}

			inline const wchar_t* GetWideName( ) const
			{
				return WideName;
			}
		};

		
		enum bones
		{
			HEAD = 6,
			UPPER_NECK = 7,
			NECK = 6,
			RIGHT_SHOULDER = 66,
			RIGHT_ELBOW = 89,
			RIGHT_HAND = 124,
			LEFT_SHOULDER = 93,
			LEFT_ELBOW = 94,
			LEFT_HAND = 123,
			PELVIS = 2,
			STOMACH = 4,
			CHEST = 5,
			RIGHT_THIGH = 130,
			RIGHT_KNEE = 131,
			RIGHT_FOOT = 140,
			LEFT_THIGH = 125,
			LEFT_KNEE = 126,
			LEFT_FOOT = 139,
			ROOT = 199,
		};
	
		template<typename ElementType, int32_t MaxTotalElements, int32_t ElementsPerChunk>
		class TStaticIndirectArrayThreadSafeRead
		{
		public:
			inline size_t Num( ) const
			{
				return NumElements;
			}

			inline bool IsValidIndex( int32_t index ) const
			{
				return index < Num( ) && index >= 0;
			}

			inline ElementType* operator[]( int32_t index ) const
			{
				ElementType* ItemPtr = GetItemPtr( index );
				return ItemPtr;
			}

		private:
			inline ElementType* GetItemPtr( int32_t Index ) const
			{
				int32_t ChunkIndex = Index / ElementsPerChunk;
				int32_t WithinChunkIndex = Index % ElementsPerChunk;
				ElementType* Chunk = ( *Chunks ) [ ChunkIndex ];
				int offset = WithinChunkIndex * 8;
				uintptr_t ptrAddress = *reinterpret_cast< uintptr_t* >( reinterpret_cast< unsigned char* >( Chunk ) + offset );
				ElementType* ItemPtr = reinterpret_cast< ElementType* >( ptrAddress );
				return ItemPtr;
			}

			enum
			{
				ChunkTableSize = ( MaxTotalElements + ElementsPerChunk - 1 ) / ElementsPerChunk
			};

			ElementType** Chunks [ ChunkTableSize ];
			int32_t NumElements;
			int32_t NumChunks;
		};

		struct FTransform
		{
			D3DXQUATERNION rot;
			SDK::utils::maths::vec3_t translation;
			char pad [ 4 ];
			SDK::utils::maths::vec3_t scale;
			char pad1 [ 4 ];
			D3DMATRIX ToMatrixWithScale( )
			{
				D3DMATRIX m;
				m._41 = translation.x;
				m._42 = translation.y;
				m._43 = translation.z;

				float x2 = rot.x + rot.x;
				float y2 = rot.y + rot.y;
				float z2 = rot.z + rot.z;

				float xx2 = rot.x * x2;
				float yy2 = rot.y * y2;
				float zz2 = rot.z * z2;
				m._11 = ( 1.0f - ( yy2 + zz2 ) ) * scale.x;
				m._22 = ( 1.0f - ( xx2 + zz2 ) ) * scale.y;
				m._33 = ( 1.0f - ( xx2 + yy2 ) ) * scale.z;

				float yz2 = rot.y * z2;
				float wx2 = rot.w * x2;
				m._32 = ( yz2 - wx2 ) * scale.z;
				m._23 = ( yz2 + wx2 ) * scale.y;

				float xy2 = rot.x * y2;
				float wz2 = rot.w * z2;
				m._21 = ( xy2 - wz2 ) * scale.y;
				m._12 = ( xy2 + wz2 ) * scale.x;

				float xz2 = rot.x * z2;
				float wy2 = rot.w * y2;
				m._31 = ( xz2 + wy2 ) * scale.z;
				m._13 = ( xz2 - wy2 ) * scale.x;

				m._14 = 0.0f;
				m._24 = 0.0f;
				m._34 = 0.0f;
				m._44 = 1.0f;

				return m;
			}
		};

		D3DMATRIX MatrixMultiplicationx( D3DMATRIX pM1, D3DMATRIX pM2 )
		{
			D3DMATRIX pOut;
			pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
			pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
			pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
			pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
			pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
			pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
			pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
			pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
			pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
			pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
			pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
			pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
			pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
			pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
			pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
			pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

			return pOut;
		}
		class USQItemStaticInfo
		{
		public:

			void UENGINE RecoilCameraOffsetFactor(float zoom)
			{
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x0668) = zoom;
			}
			 
			int UENGINE g_ControlRotation()
			{
				return *reinterpret_cast<int*>(reinterpret_cast<std::uintptr_t>(this) + 0x0670);
			}

			int UENGINE g_ControlRotation2()
			{
				return *reinterpret_cast<int*>(reinterpret_cast<std::uintptr_t>(this) + 0x068C);
			}
			void UENGINE bHasBipod(bool zoom)
			{
				*reinterpret_cast<bool*>(reinterpret_cast<std::uintptr_t>(this) + 0x0798) = zoom;
			}

			


		};

		//class UProjectileMovementComponent : public UMovementComponent
		//class UMovementComponent : public UActorComponent
		//
		//
		class USceneComponent
		{
		public:

			utils::maths::vectype2::FVector UENGINE g_RelativeLocation( )
			{
				return *reinterpret_cast< utils::maths::vectype2::FVector* >( reinterpret_cast< std::uintptr_t >( this ) + 0x0144);
			}

			utils::maths::vectype2::FRotator UENGINE g_RelativeRotation()
			{
				return *reinterpret_cast<utils::maths::vectype2::FRotator*>(reinterpret_cast<std::uintptr_t>(this) + 0x0150);
			}

		};
	 

		class USkeletalMeshComponent
		{
		public:
			FTransform GetBoneIndexTransform( signed __int32 index )
			{
				const auto transform_array = *reinterpret_cast< std::uintptr_t* >( reinterpret_cast< std::uintptr_t >( this ) + 0x0680);

				if ( !transform_array )
					return {};

				return *reinterpret_cast< FTransform* >( transform_array + ( index * 0x30 ) );
			}

			FTransform GetComponentToWorld( )
			{
				/*const auto comp_to_world_array = *reinterpret_cast< std::uintptr_t* >( reinterpret_cast< std::uintptr_t >( this ) + 0X1e0 );

				if ( !comp_to_world_array )
					return {};*/

				return *reinterpret_cast< FTransform* >( reinterpret_cast< std::uintptr_t >( this ) + 0x128 );
			}
			utils::maths::vectype2::vec3_t UENGINE g_Bone( signed __int32 index )
			{
				auto _transform = this->GetBoneIndexTransform( index );
				auto _comp_to_world = this->GetComponentToWorld( );

				D3DMATRIX matrix;
				matrix = MatrixMultiplicationx( _transform.ToMatrixWithScale( ), _comp_to_world.ToMatrixWithScale( ) );
				return utils::maths::vectype2::vec3_t( matrix._41, matrix._42, matrix._43 );
			}
		};

		class APlayerState
		{
		public:
			FString UENGINE PlayerName()
			{
				return *reinterpret_cast<FString*>(reinterpret_cast<std::uintptr_t>(this) + 0x0350);
			}

			signed __int32 UENGINE g_TeamId( )
			{
				return *reinterpret_cast< signed __int32* >( reinterpret_cast< std::uintptr_t >( this ) + 0x420);
			}

			void UENGINE s_TeamId(int zoom)
			{
				*reinterpret_cast<int*>(reinterpret_cast<std::uintptr_t>(this) + 0x420) = zoom;
			}
		};

		class APawn
		{
		public:

			USkeletalMeshComponent* UENGINE g_Mesh()
			{
				return *reinterpret_cast<USkeletalMeshComponent**>(reinterpret_cast<std::uintptr_t>(this) + 0x02A8);
			} 
			
			APlayerState* UENGINE g_PlayerState()
			{
				return *reinterpret_cast<APlayerState**>(reinterpret_cast<std::uintptr_t>(this) + 0x0268);
			}

			USceneComponent* UENGINE g_ActorRootComponent1()
			{
				return *reinterpret_cast<USceneComponent**>(reinterpret_cast<std::uintptr_t>(this) + 0x0160);
			}

		};
	

		enum class ESQVehicleType : uint8_t
		{
			ESQVehicleType__None = 0,
			ESQVehicleType__Motorcycle = 1,
			ESQVehicleType__Jeep = 2,
			ESQVehicleType__JeepTransport = 3,
			ESQVehicleType__JeepLogistics = 4,
			ESQVehicleType__JeepAntiTank = 5,
			ESQVehicleType__JeepArtillery = 6,
			ESQVehicleType__TruckTransport = 7,
			ESQVehicleType__TruckLogistics = 8,
			ESQVehicleType__TruckAntiAir = 9,
			ESQVehicleType__APC = 10,
			ESQVehicleType__APCTracked = 11,
			ESQVehicleType__AntiAirTracked = 12,
			ESQVehicleType__IFV = 13,
			ESQVehicleType__IFVTracked = 14,
			ESQVehicleType__Tank = 15,
			ESQVehicleType__HelicopterTransport = 16,
			ESQVehicleType__HelicopterAttack = 17,
			ESQVehicleType__Boat = 18,
			ESQVehicleType__MAX = 19,

		};

		class ASQVehicle  
		{
		public:
			ESQVehicleType g_VehicleType()
			{
				return *reinterpret_cast<ESQVehicleType*>(reinterpret_cast<uintptr_t>(this) + 0x0628);
			}

			float g_VehicleHealth()
			{
				return *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(this) + 0x0760);
			}

			float g_VehicleHealthMax()
			{
				return *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(this) + 0x0764);
			}
		};

		class UProjectileMovementComponent
		{
		public:
			
			float g_VehicleHealthMax()
			{
				return *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(this) + 0x0764);
			}
		};

		class AActor
		{
		public:
			 
			float UENGINE g_ActorHealth()
			{
				return *reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x1C18);
			}
		
			// Class Squad.SQProjectile
			// 0x0248 (FullSize[0x0490] - InheritedSize[0x0248])

			UProjectileMovementComponent* UENGINE SQProjectile()
			{
				return *reinterpret_cast<UProjectileMovementComponent**>(reinterpret_cast<std::uintptr_t>(this) + 0x0148);
			}


			APawn* UENGINE g_ActorInstigator( )
			{
				return *reinterpret_cast< APawn** >( reinterpret_cast< std::uintptr_t >( this ) + 0x0148);
			}
			
			 
			USceneComponent* UENGINE g_ActorRootComponent( )
			{
				return *reinterpret_cast< USceneComponent** >( reinterpret_cast< std::uintptr_t >( this ) + 0x0160 );
			}

 		
		};
	 
		struct FSQWeaponData
		{
			bool                                               bInfiniteAmmo;                                             // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bInfiniteMags;                                             // 0x0001(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownData9CTL[0x2];                                      // 0x0002(0x0002) MISSED OFFSET
			int                                                MaxMags;                                                   // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			int                                                RoundsPerMag;                                              // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bAllowRoundInChamber;                                      // 0x000C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownDataFGHR[0x3];                                      // 0x000D(0x0003) MISSED OFFSET
			TArray<int>                                        Firemodes;                                                 // 0x0010(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NativeAccessSpecifierPublic)
			float                                              TimeBetweenShots;                                          // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              TimeBetweenSingleShots;                                    // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bCanReloadWhenEquipping;                                   // 0x0028(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bCreateProjectileOnServer;                                 // 0x0029(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownData72Y9[0x2];                                      // 0x002A(0x0002) MISSED OFFSET
			float                                              TacticalReloadDuration;                                    // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              DryReloadDuration;                                         // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              TacticalReloadBipodDuration;                               // 0x0034(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              ReloadDryBipodDuration;                                    // 0x0038(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              ZoomDuration;                                              // 0x003C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              ADSPostTransitionRatio;                                    // 0x0040(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bAllowZoom;                                                // 0x0044(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bAverageFireRate;                                          // 0x0045(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bResetBurstOnTriggerRelease;                               // 0x0046(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownDataCUDW[0x1];                                      // 0x0047(0x0001) MISSED OFFSET
			class UClass* ProjectileClass;                                           // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			int                                                RoundsBetweenTracer;                                       // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownDataWR48[0x4];                                      // 0x0054(0x0004) MISSED OFFSET
			class UClass* TracerProjectileClass;                                     // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              MuzzleVelocity;                                            // 0x0060(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              MaxDamageToApply;                                          // 0x0064(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              TimeToStartDamageFallOff;                                  // 0x0068(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              DistanceToStartDamageFallOff;                              // 0x006C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              DamageFallOffRate;                                         // 0x0070(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              MinDamageToApply;                                          // 0x0074(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			class UCurveFloat* DamageFalloffCurve;                                        // 0x0078(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bIsBarrelSocketOnSoldier;                                  // 0x0080(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownDataBWDX[0x3];                                      // 0x0081(0x0003) MISSED OFFSET
			struct FNameEntry                                      BarrelSocketName;                                          // 0x0084(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              MOA;                                                       // 0x008C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              MaximumTraceDistance;                                      // 0x0090(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              WallHackCheckTraceDistance;                                // 0x0094(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              ProjectileCameraRelativeOffsetMultiplier;                  // 0x0098(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bMagMustBeEmptyForVehicleRearm;                            // 0x009C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bRearmOnlyIfCurrentMagazineIsEmpty;                        // 0x009D(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bRearmCanFillCurrentMagazine;                              // 0x009E(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownDataXHRU[0x1];                                      // 0x009F(0x0001) MISSED OFFSET
			float                                              MinimumTimeBetweenRearms;                                  // 0x00A0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bRearmOnlyOneMagazine;                                     // 0x00A4(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                                               bRearmOnlyXRoundsOfAmmo;                                   // 0x00A5(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownData2R0W[0x2];                                      // 0x00A6(0x0002) MISSED OFFSET
			int                                                RearmRoundsOfAmmoPerRearm;                                 // 0x00A8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			int                                                ArmorPenetrationDepthMillimeters;                          // 0x00AC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			class UCurveFloat* ArmorPenetrationDepthCurve;                                // 0x00B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			float                                              TraceDistanceAfterPenetrationMeters;                       // 0x00B8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownDataSZOZ[0x4];                                      // 0x00BC(0x0004) MISSED OFFSET

		};

		class USQAnimInstanceSoldier1P
		{
		public:

 
			void UENGINE RecoilCameraOffsetFactor(float zoom)
			{
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x09C4) = zoom;
			}
			 
		
		};

		class ASQEquipableItem
		{
		public:
			USQItemStaticInfo* UENGINE g_USQItemStaticInfo()
			{
				return *reinterpret_cast<USQItemStaticInfo**>(reinterpret_cast<std::uintptr_t>(this) + 0x0248);
			}

			USQAnimInstanceSoldier1P* UENGINE g_CachedSoldier1pAnimInstance()
			{
				return *reinterpret_cast<USQAnimInstanceSoldier1P**>(reinterpret_cast<std::uintptr_t>(this) + 0x0440);
			}
			ASQVehicle* UENGINE GetVeicle()
			{
				return *reinterpret_cast<ASQVehicle**>(reinterpret_cast<std::uintptr_t>(this) + 0x0488);
			}
			
			void UENGINE SetWeaponConfig(FSQWeaponData zoom)
			{
				*reinterpret_cast<FSQWeaponData*>(reinterpret_cast<std::uintptr_t>(this) + 0x0570) = zoom;
			}


			FSQWeaponData GetWeaponConfig()
			{
				return *reinterpret_cast<FSQWeaponData*>(reinterpret_cast<std::uintptr_t>(this) + 0x0570);
			}


			FSQWeaponData UENGINE s_WeaponConfig()
			{
				return *reinterpret_cast<FSQWeaponData*>(reinterpret_cast<std::uintptr_t>(this) + 0x0570);
			}

			void UENGINE g_WeaponConfig(bool zoom)
			{
				*reinterpret_cast<float*>(reinterpret_cast<FSQWeaponData*>(this) + 0x4e0) = zoom;
			 
			}

			void UENGINE w_CurrentFOV( float zoom )
			{
				*reinterpret_cast< float* >( reinterpret_cast< std::uintptr_t >( this ) + 0x0648 ) = zoom;
			}

			void UENGINE w_ZoomedFOV( float zoom )
			{
				*reinterpret_cast< float* >( reinterpret_cast< std::uintptr_t >( this ) + 0x064C) = zoom;
			}

			void UENGINE w_Sway(float sway)
			{
				utils::maths::vectype2::FRotator sway_all = { sway, sway, sway };

				/* MaxMoveSwayFactor */
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x0ACC) = sway;

				/* MinMoveSwayFactor */
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x0AD0) = sway;

				/* AddMoveSway */
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x0AC8) = sway;

				/* MoveSwayFactor */
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x08BC) = sway;

				/* MoveSwayFactor */
				*reinterpret_cast<utils::maths::vectype2::FRotator*>(reinterpret_cast<std::uintptr_t>(this) + 0x0678) = sway_all;
			}
		

		};

	/*	__forceinline float screen_distance_from_center__(utils::maths::vec2_t Position)
		{
			return sqrt(pow(abs(Position.x - (variables::game_screen_X / 2)), 2) + pow(abs(Position.y - (variables::game_screen_Y / 2)), 2));
		}*/

		void normalize_angle(float& Yaw, float& Pitch) {

			while (Pitch > 89.0f)
				Pitch -= 180.0f;

			while (Pitch < -89.0f)
				Pitch += 180.0f;

			while (Yaw > 180.0f)
				Yaw -= 360.0f;

			while (Yaw < -180.0f)
				Yaw += 360.0f;

			return;
		}

		class USQPawnInventoryComponent
		{
		public:
			
			ASQEquipableItem* UENGINE g_CurrentWeapon( )
			{
				return *reinterpret_cast< ASQEquipableItem** >( reinterpret_cast< std::uintptr_t >( this ) + 0x0168);
			}

		};

	

		class ACharacter
		{
		public:

			void UENGINE bIsCameraRecoilActive(bool zoom)
			{
				*reinterpret_cast<float*>(reinterpret_cast<FSQWeaponData*>(this) + 0x18C2) = zoom;

			}
			//class ASQWeapon_Effects : public ASQWeapon
			
		
			 
			USQPawnInventoryComponent* UENGINE g_InventoryComponent( )
			{
				return *reinterpret_cast< USQPawnInventoryComponent** >( reinterpret_cast< std::uintptr_t >( this ) + 0x1DA8);
			}
		};

		struct FMinimalViewInfo
		{
			struct utils::maths::vectype2::FVector                       Location;                                                 // 0x0000(0x000C) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_IsPlainOldData)
			struct utils::maths::vectype2::FRotator                      Rotation;                                                 // 0x000C(0x000C) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_IsPlainOldData)
			float                                              FOV;                                                      // 0x0018(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_IsPlainOldData)
			float                                              OrthoWidth;                                               // 0x001C(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_IsPlainOldData)
			float                                              OrthoNearClipPlane;                                       // 0x0020(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_IsPlainOldData)
			float                                              OrthoFarClipPlane;                                        // 0x0024(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_IsPlainOldData)
			float                                              AspectRatio;                                              // 0x0028(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_IsPlainOldData)
		};

		struct FCameraCacheEntry
		{
			float                                              Timestamp;                                                // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
			unsigned char                                      UnknownData00 [ 0xC ];                                    // 0x0004(0x000C) MISSED OFFSET
			struct FMinimalViewInfo                            POV;                                                      // 0x0010(0x0530)
		};

		class APlayerCameraManager
		{
		public:

		 

			inline D3DXMATRIX UENGINE Matrix( utils::maths::vectype2::vec3_t rot, utils::maths::vectype2::vec3_t origin = utils::maths::vectype2::vec3_t( 0, 0, 0 ) )
			{
				float radPitch = ( rot.x * float( PI ) / 180.f );
				float radYaw = ( rot.y * float( PI ) / 180.f );
				float radRoll = ( rot.z * float( PI ) / 180.f );

				float SP = sinf( radPitch );
				float CP = cosf( radPitch );
				float SY = sinf( radYaw );
				float CY = cosf( radYaw );
				float SR = sinf( radRoll );
				float CR = cosf( radRoll );

				D3DMATRIX matrix;
				matrix.m [ 0 ][ 0 ] = CP * CY;
				matrix.m [ 0 ][ 1 ] = CP * SY;
				matrix.m [ 0 ][ 2 ] = SP;
				matrix.m [ 0 ][ 3 ] = 0.f;

				matrix.m [ 1 ][ 0 ] = SR * SP * CY - CR * SY;
				matrix.m [ 1 ][ 1 ] = SR * SP * SY + CR * CY;
				matrix.m [ 1 ][ 2 ] = -SR * CP;
				matrix.m [ 1 ][ 3 ] = 0.f;

				matrix.m [ 2 ][ 0 ] = -( CR * SP * CY + SR * SY );
				matrix.m [ 2 ][ 1 ] = CY * SR - CR * SP * SY;
				matrix.m [ 2 ][ 2 ] = CR * CP;
				matrix.m [ 2 ][ 3 ] = 0.f;

				matrix.m [ 3 ][ 0 ] = origin.x;
				matrix.m [ 3 ][ 1 ] = origin.y;
				matrix.m [ 3 ][ 2 ] = origin.z;
				matrix.m [ 3 ][ 3 ] = 1.f;

				return matrix;
			}

 			inline utils::maths::vectype2::vec3_t UENGINE ProjectWorldToScreen( utils::maths::vectype2::vec3_t WorldLocation, utils::maths::vectype2::vec3_t CameraRotation, utils::maths::vectype2::vec3_t CameraLocation, float FOV )
			{
				utils::maths::vectype2::vec3_t Screenlocation = utils::maths::vectype2::vec3_t( 0, 0, 0 );

				utils::maths::vectype2::vec3_t Rotation = CameraRotation;

				D3DMATRIX tempMatrix = Matrix( Rotation );

				utils::maths::vectype2::vec3_t vAxisX, vAxisY, vAxisZ;

				vAxisX = utils::maths::vectype2::vec3_t(
					tempMatrix.m [ 0 ][ 0 ],
					tempMatrix.m [ 0 ][ 1 ],
					tempMatrix.m [ 0 ][ 2 ] );

				vAxisY = utils::maths::vectype2::vec3_t(
					tempMatrix.m [ 1 ][ 0 ],
					tempMatrix.m [ 1 ][ 1 ],
					tempMatrix.m [ 1 ][ 2 ] );

				vAxisZ = utils::maths::vectype2::vec3_t(
					tempMatrix.m [ 2 ][ 0 ],
					tempMatrix.m [ 2 ][ 1 ],
					tempMatrix.m [ 2 ][ 2 ] );

				utils::maths::vectype2::vec3_t vDelta = WorldLocation - CameraLocation;

				utils::maths::vectype2::vec3_t vTransformed =
					utils::maths::vectype2::vec3_t(
						vDelta.dot_product( vAxisY ),
						vDelta.dot_product( vAxisZ ),
						vDelta.dot_product( vAxisX ) );

				if ( vTransformed.z < 1.f )
					vTransformed.z = 1.f;

				float FovAngle = FOV;
				float ScreenCenterX = variables::game_screen_X / 2.0f;
				float ScreenCenterY = variables::game_screen_Y / 2.0f;

				Screenlocation.x = ScreenCenterX + vTransformed.x * ( ScreenCenterX / tan( FovAngle * ( float )PI / 360.f ) ) / vTransformed.z;
				Screenlocation.y = ScreenCenterY - vTransformed.y * ( ScreenCenterX / tan( FovAngle * ( float )PI / 360.f ) ) / vTransformed.z;

				return Screenlocation;
			}
		};
		//: public AController ASQPlayerController : public APlayerController class AController : public AActor
		class APlayerController
		{
		public:
			APlayerCameraManager* UENGINE g_CameraManager( )
			{
				return *reinterpret_cast< APlayerCameraManager** >( reinterpret_cast< std::uintptr_t >( this ) + 0x02E0);
			}

			ACharacter* UENGINE g_ACharacter( )
			{
				return *reinterpret_cast< ACharacter** >( reinterpret_cast< std::uintptr_t >( this ) + 0x0288);
			}

		 

			APawn* UENGINE g_LocalAPawn( )
			{
				return *reinterpret_cast< APawn** >( reinterpret_cast< std::uintptr_t >( this ) + 0x02C8);
			}

			utils::maths::vectype2::FRotator UENGINE g_ControlRotation()
			{
				return *reinterpret_cast<utils::maths::vectype2::FRotator*>(reinterpret_cast<std::uintptr_t>(this) + 0x02B0);
			}

			void UENGINE s_ControlRotation(float sway)
			{
				utils::maths::vectype2::FRotator sway_all = { sway};
				*reinterpret_cast<utils::maths::vectype2::FRotator*>(reinterpret_cast<std::uintptr_t>(this) + 0x02B0) = sway_all;
				
			}
			void UENGINE modify_Rotation(utils::maths::vectype2::vec3_t  rotation)
			{
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x02B0) = rotation.x;
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x02B0 + 0x4) = rotation.y;
			}

			void UENGINE StartFire(int rotation)
			{
				*reinterpret_cast<int*>(reinterpret_cast<std::uintptr_t>(this) + 0xAC0) = rotation;
			
			}


			void UENGINE ClientSetRotation(utils::maths::vectype2::FRotator  rotation)
			{
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x620) = rotation.Pitch;
				*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x620 + 0x4) = rotation.Yaw;
			//	*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x620 + 0x8) = rotation.Roll;
			}

			bool IsVisible(AActor* Target, SDK::utils::maths::vectype2::vec3_t ViewPoint) 
			{  
				auto LineOfSightTo = *reinterpret_cast<bool(__fastcall**)(APlayerController*, AActor*, SDK::utils::maths::vectype2::vec3_t&, bool)>(*(DWORD64*)this + 0x670);
				return LineOfSightTo(this, Target, ViewPoint, false);
			};
		 
		};
 

	 

		float GetDistance(utils::maths::vectype2::FVector point1, utils::maths::vectype2::FVector point2)
		{
			utils::maths::vectype2::FVector heading = Subtract(point2, point1);
			float distanceSquared;
			float distance;

			distanceSquared = heading.x * heading.x + heading.y * heading.y + heading.z * heading.z;
			distance = sqrt(distanceSquared);

			return distance;
		}

		class ULocalPlayer
		{
		public:
			APlayerController* UENGINE g_PlayerController( )
			{
				return *reinterpret_cast< APlayerController** >( reinterpret_cast< std::uintptr_t >( this ) + 0x30);
			}
		};

		class OwningGameInstance
		{
		public:
			ULocalPlayer** UENGINE g_LocalPlayerContainer( )
			{
				return *reinterpret_cast< ULocalPlayer*** >(
					reinterpret_cast< std::uintptr_t >( this ) 
						+ 0x38);
			}
		};

		class ULevel
		{
			signed __int64 GetWorldSettingsPtr()
			{
				return *reinterpret_cast<signed __int64*>(reinterpret_cast<std::uintptr_t>(this) + 0x240);
			}

		public:
			AActor** UENGINE g_ActorList( )
			{
				return *reinterpret_cast< AActor*** >( reinterpret_cast< std::uintptr_t >( this ) + 0x98 );
			}

			signed __int32 UENGINE g_ActorCount( )
			{
				return *reinterpret_cast< signed __int32* >( reinterpret_cast< std::uintptr_t >( this ) + 0x98+8);
			}

			void SetTimeDilation(float value)
			{
				auto pAWorldSettings = GetWorldSettingsPtr();
				*reinterpret_cast<float*>(pAWorldSettings + 0x310) = value;
			}


		};
 

		D3DMATRIX* GetBoneMatrixInternal(uint64_t pObj, D3DMATRIX* result, int BoneIdx)
		{
			static uintptr_t funcAddress = 0; 

			if (!funcAddress) funcAddress = GetBone;
			if (funcAddress != 0)
			{
				auto GetBoneMatrix = reinterpret_cast<D3DMATRIX * (__fastcall*)(uintptr_t, D3DMATRIX*, int)>(funcAddress);
				return GetBoneMatrix(pObj, result, BoneIdx);
			}
		}

		utils::maths::vectype2::vec3_t GetBoneLocation(uint64_t pMesh, int boneidx)
		{
			D3DMATRIX vMatrix;
			D3DMATRIX* vTempvMatrix = GetBoneMatrixInternal(pMesh, &vMatrix, boneidx);
			return utils::maths::vectype2::vec3_t(vMatrix._41, vMatrix._42, vMatrix._43);
		}
		//const struct FVector& DestLocation, const struct FRotator& DestRotation

	  
 
		
		bool LineOfSightTo(APlayerController* thiz, AActor* Other, FVector ViewPoint)
		{
			static DWORD_PTR funcAddress = 0;
			if (!funcAddress)				funcAddress = variables::squad_image_base + 0x2912D90;

			if (funcAddress) { return reinterpret_cast<int(__fastcall*)(APlayerController * thiz, AActor * Other, FVector ViewPoint)>(funcAddress)(thiz, Other, ViewPoint); }
		}
	 

		 
 
	 
		class UWorld
		{
		public:
			ULevel* UENGINE g_PersistentLevel( )
			{
				return *reinterpret_cast< ULevel** >( reinterpret_cast< std::uintptr_t >( this ) + 0x0030);
			}

			OwningGameInstance* UENGINE g_GameInstance( )
			{
				return *reinterpret_cast< OwningGameInstance** >( reinterpret_cast< std::uintptr_t >( this ) + 0x0170 );
			}
		};

	 
	}
}
