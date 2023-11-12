#pragma once
#include <cstdint>
#include <Windows.h>
#include <Psapi.h>
#include <cstdint>
#include "xorstr.h"
typedef std::intptr_t game_base;
typedef std::uint32_t game_offset;

namespace SDK
{
	namespace variables
	{
		uintptr_t process_id;
		uintptr_t World;
		HANDLE handle;
		unsigned __int64 squad_image_base;
		MODULEINFO squad_module_info;
		MODULEINFO info;
		unsigned int game_screen_X;
		unsigned int game_screen_Y;

		HWND window_handle;

	 
		LPCSTR window_wnd_name = "";

		HMODULE current_module_handle;

		bool renderer_executed;
		bool renderer_intialized;
		bool renderer_exit;

		namespace offsets
		{
			static constexpr game_base base_networkable = 0x24B2AA0;
			static constexpr game_base game_objmgr = 0x163D080;
		}
	}
}

WCHAR ptrBuf[1000];
WCHAR ptrData[] = L"m_UWorld: 0x%016X\n";
WCHAR ptrBuf2[1000];
WCHAR ptrData2[] = L"m_OwningGameInstance: 0x%016X\n";
WCHAR ptrBuf3[1000];
WCHAR ptrData3[] = L"m_LocalPlayers: 0x%016X\n";
WCHAR ptrBuf4[1000];
WCHAR ptrData4[] = L"[View Angles] | Pitch: %d | Yaw: %d | Roll: %d |\n";
//WCHAR ptrData4[] = L"m_LocalPlayer: 0x%016X\n";
WCHAR ptrData4_[] = L"[View Angles] | Loading";