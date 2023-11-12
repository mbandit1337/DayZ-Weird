//
// FindPattern.h
//

#include <Windows.h>
#include <psapi.h>
#include <cstdio>
#include <winscard.h>

#pragma once

typedef struct {
	float X, Y, Z;
} FVector;

typedef struct {
	float X, Y;
} FVector2D;

typedef struct {
	float Pitch;
	float Yaw;
	float Roll;
} FRotator;

typedef struct {
	FVector Location;
	FRotator Rotation;
	float FOV;
	float OrthoWidth;
	float OrthoNearClipPlane;
	float OrthoFarClipPlane;
	float AspectRatio;
} FMinimalViewInfo;


//
//namespace SDK
//{
//	namespace Utils {
//
//		namespace Memory {
//
//			void NopRegion( BYTE* dst, const size_t size )
//			{
//				DWORD oldprotect;
//				VirtualProtect( dst, size, PAGE_EXECUTE_READWRITE, &oldprotect );
//				memset( dst, 0x90, size );
//				VirtualProtect( dst, size, oldprotect, &oldprotect );
//			}
//			void Nop(BYTE* dst, unsigned int size)
//			{
//				DWORD oldprotect;
//				VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
//				memset(dst, 0x90, size);
//				VirtualProtect(dst, size, oldprotect, &oldprotect);
//			}
//			void Patch1(BYTE* dst, BYTE* src, unsigned int size)
//			{
//				DWORD oldprotect;
//				VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
//
//				memcpy(dst, src, size);
//				VirtualProtect(dst, size, oldprotect, &oldprotect);
//			}
//			void Patch( BYTE* dst, BYTE* src, unsigned int size )
//			{
//				DWORD oldprotect;
//				VirtualProtect( dst, size, PAGE_EXECUTE_READWRITE, &oldprotect );
//				memcpy( dst, src, size );
//				VirtualProtect( dst, size, oldprotect, &oldprotect );
//			}
//		}
//
//		namespace Pattern {
//
//
//			bool DataCompare1(PBYTE pData, PBYTE bSig,const char* szMask) {
//				for (; *szMask; ++szMask, ++pData, ++bSig) {
//					if (*szMask == 'x' && *pData != *bSig)
//						return false;
//				}
//				return (*szMask) == 0;
//			}
//
//			PBYTE FindPattern1(PBYTE dwAddress, DWORD dwSize, PBYTE pbSig, const char* szMask, long offset) {
//				size_t length = strlen(szMask);
//				for (size_t i = NULL; i < dwSize - length; i++) {
//					if (DataCompare1(dwAddress + i, pbSig, szMask))
//						return dwAddress + i + offset;
//				}
//				return 0;
//			}
//
//
//			bool DataCompare( PBYTE pData, PBYTE bSig, char* szMask ) {
//				for ( ; *szMask; ++szMask, ++pData, ++bSig ) {
//					if ( *szMask == 'x' && *pData != *bSig )
//						return false;
//				}
//				return ( *szMask ) == 0;
//			}
//
//
//
//			PBYTE FindPattern( PBYTE dwAddress, DWORD dwSize, PBYTE pbSig, char* szMask, long offset ) {
//				size_t length = strlen( szMask );
//				for ( size_t i = NULL; i < dwSize - length; i++ ) {
//					if ( DataCompare( dwAddress + i, pbSig, szMask ) )
//						return dwAddress + i + offset;
//				}
//				return 0;
//			}
//				BOOLEAN MaskCompare3(PVOID buffer, LPCSTR pattern, LPCSTR mask) {
//		for (auto b = reinterpret_cast<PBYTE>(buffer); *mask; ++pattern, ++mask, ++b) {
//			if (*mask == 'x' && *reinterpret_cast<LPCBYTE>(pattern) != *b) {
//				return FALSE;
//			}
//		}
//
//		return TRUE;
//	}
//
//	PBYTE FindPattern3(PVOID base, DWORD size, LPCSTR pattern, LPCSTR mask) {
//		size -= static_cast<DWORD>(strlen(mask));
//
//		for (auto i = 0UL; i < size; ++i) {
//			auto addr = reinterpret_cast<PBYTE>(base) + i;
//			if (MaskCompare3(addr, pattern, mask)) {
//				return addr;
//			}
//		}
//
//		return NULL;
//	}
//
//	PBYTE FindPattern3(LPCSTR pattern, LPCSTR mask) {
//		MODULEINFO info = { 0 };
//		GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, sizeof(info));
//
//		return FindPattern3(info.lpBaseOfDll, info.SizeOfImage, pattern, mask);
//	}
//		}
//
//		void allocate_console( )
//		{
//			AllocConsole( );
//			freopen( "CONOUT$", "w", stdout );
//		}
//	}
//
//}
