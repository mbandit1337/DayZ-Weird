#pragma once
#include <Windows.h>
#include "vectoprr.h"


#include "winternl.h"
#define BASENETSHOW



__declspec(noinline) DWORD64 GetModBase(const wchar_t* Name) {
	PPEB_LDR_DATA Ldr = ((PTEB)__readgsqword(FIELD_OFFSET(NT_TIB, Self)))->ProcessEnvironmentBlock->Ldr;
	for (PLIST_ENTRY CurEnt = Ldr->InMemoryOrderModuleList.Flink; CurEnt != &Ldr->InMemoryOrderModuleList; CurEnt = CurEnt->Flink) {
		PLDR_DATA_TABLE_ENTRY pEntry = CONTAINING_RECORD(CurEnt, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
		if (((DWORD64)Name > 1 && !_wcsicmp(Name, pEntry->BaseDllName.Buffer)) ||
			((DWORD64)Name == 1 && pEntry->BaseDllName.Length == 18 && *(DWORD64*)pEntry->BaseDllName.Buffer == 0x6C00640074006E) || !Name)
			return (DWORD64)pEntry->DllBase;
	} return 0;
}

DWORD64 FindPattern(const PBYTE Pattern, const char* Mask, const wchar_t* Module = nullptr)
{
	PBYTE Start = (PBYTE)GetModBase(Module);
	PIMAGE_NT_HEADERS NTHead = (PIMAGE_NT_HEADERS)(Start + ((PIMAGE_DOS_HEADER)Start)->e_lfanew);
	DWORD Len = NTHead->OptionalHeader.SizeOfImage;

	for (PBYTE region_it = Start; region_it < (Start + Len); ++region_it)
	{
		if (*region_it == *Pattern)
		{
			bool found = true;
			const unsigned char* pattern_it = Pattern, * mask_it = (const PBYTE)Mask, * memory_it = region_it;
			for (; *mask_it && (memory_it < (Start + Len)); ++mask_it, ++pattern_it, ++memory_it) {
				if (*mask_it != 'x') continue;
				if (*memory_it != *pattern_it) {
					found = false;
					break;
				}
			}

			if (found)
				return (DWORD64)region_it;
		}
	}

	return 0;
}

void CreateThreadSafe(PVOID StartAddr)
{
	typedef HANDLE(__fastcall* CreateSimpleThreadFn)(void*, PVOID, PVOID, unsigned int);
	static CreateSimpleThreadFn CST = nullptr;
	CST = (CreateSimpleThreadFn)FindPattern((PBYTE)xorstr_("\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30"), xorstr_("xxxx?xxxx?xxxx?xxxxx"), xorstr_(L"tier0_s64.dll"));
	CST(StartAddr, 0, 0, 0);
}




int aimkey = VK_RBUTTON;


#define OFF_TEXT				0x10
#define OFF_LENGTH				0x8
#define OFF_WORLD				0x413B418 
std::uintptr_t nearTableList = 0xEB8;

std::uintptr_t slowTable = 0x1F80;

std::uintptr_t farTableList = 0x1000;

std::uintptr_t bulletTableList = 0xD70;
std::uintptr_t items_table_1 = 0x1FD0;
std::uintptr_t items_table_2 = 0x1FF0;
 
#define off_world_itemtable	 0x1FD0  
#define off_world_itemtable1	 0x1F80  
//0x7ff776460000
#include "Globals.h"
static int keystatus = 0;
static int realkey = 0;
bool GetKey(int key)
{
	realkey = key;
	return true;
}
void ChangeKey(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				aimkey = i;
				keystatus = 0;
				return;
			}
		}
	}
}
//static const char* KeyNames[] = {
//  _("Press Key"),
//  _("Left Mouse"),
//  _("Right Mouse"),
//  _("Cancel"),
//  _("Middle Mouse"),
//  _("X1 Mouse"),
//  _("X2 Mouse"),
//  _("Unknown"),
//  _("Backspace"),
//  _("Tab"),
//  _("unknown"),
//  _("unknown"),
//  _("Clear"),
//  _("Return"),
//  _("unknown"),
//  _("unknown"),
//  _("Shift"),
//  _("Control"),
//  _("Menu"),
//  _("Pause"),
//  _("Caps Lock"),
//  _("Kana"),
//  _("unknown"),
//  _("vk_junja"),
//  _("vk_final"),
//  _("vk_kanji"),
//  _("unknown"),
//  _("Escape"),
//  _("Convert"),
//  _("Nonconvert"),
//  _("Accept"),
//  _("Modechange"),
//  _("Space"),
//  _("Page Up"),
//  _("Page Down"),
//  _("End"),
//  _("Home"),
//  _("Left"),
//  _("Up"),
//  _("Right"),
//  _("Down"),
//  _("Select"),
//  _("Print"),
//  _("Execute"),
//  _("Snapshot"),
//  _("Insert"),
//  _("Delete"),
//  _("Help"),
//  _("0"),
//  _("1"),
//  _("2"),
//  _("3"),
//  _("4"),
//  _("5"),
//  _("6"),
//  _("7"),
//  _("8"),
//  _("9"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("a"),
//  _("b"),
//  _("c"),
//  _("d"),
//  _("e"),
//  _("f"),
//  _("g"),
//  _("h"),
//  _("i"),
//  _("j"),
//  _("k"),
//  _("l"),
//  _("m"),
//  _("n"),
//  _("o"),
//  _("p"),
//  _("q"),
//  _("r"),
//  _("s"),
//  _("t"),
//  _("u"),
//  _("v"),
//  _("w"),
//  _("x"),
//  _("y"),
//  _("z"),
//  _("Windows"),
//  _("Windows"),
//  _("Apps"),
//  _("unknown"),
//  _("Sleep"),
//  _("Numpad 0"),
//  _("Numpad 1"),
//  _("Numpad 2"),
//  _("Numpad 3"),
//  _("Numpad 4"),
//  _("Numpad 5"),
//  _("Numpad 6"),
//  _("Numpad 7"),
//  _("Numpad 8"),
//  _("Numpad 9"),
//  _("Multiply"),
//  _("Add"),
//  _("Separator"),
//  _("Subtract"),
//  _("Decimal"),
//  _("Divide"),
//  _("F1"),
//  _("F2"),
//  _("F3"),
//  _("F4"),
//  _("F5"),
//  _("F6"),
//  _("F7"),
//  _("F8"),
//  _("F9"),
//  _("F10"),
//  _("F11"),
//  _("F12"),
//  _("F13"),
//  _("F14"),
//  _("F15"),
//  _("F16"),
//  _("F17"),
//  _("F18"),
//  _("F19"),
//  _("F20"),
//  _("F21"),
//  _("F22"),
//  _("F23"),
//  _("F24"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("Numlock"),
//  _("Scroll"),
//  _("vk_oem_nec_equal"),
//  _("vk_oem_fj_masshou"),
//  _("vk_oem_fj_touroku"),
//  _("vk_oem_fj_loya"),
//  _("vk_oem_fj_roya"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("unknown"),
//  _("Shift"),
//  _("Shift"),
//  _("Control"),
//  _("Control"),
//  _("Menu"),
//  _("Menu")
//};
static const char* KeyNames[] = {
   "Press Key",
   "Left Mouse",
   "Right Mouse",
   "Cancel",
   "Middle Mouse",
   "X1 Mouse",
   "X2 Mouse",
   "Unknown",
   "Backspace",
   "Tab",
   "unknown",
   "unknown",
   "Clear",
   "Return",
   "unknown",
   "unknown",
   "Shift",
   "Control",
   "Menu",
   "Pause",
   "Caps Lock",
   "Kana",
   "unknown",
   "vk_junja",
   "vk_final",
   "vk_kanji",
   "unknown",
   "Escape",
   "Convert",
   "Nonconvert",
   "Accept",
   "Modechange",
   "Space",
   "Page Up",
   "Page Down",
   "End",
   "Home",
   "Left",
   "Up",
   "Right",
   "Down",
   "Select",
   "Print",
   "Execute",
   "Snapshot",
   "Insert",
   "Delete",
   "Help",
   "0",
   "1",
   "2",
   "3",
   "4",
   "5",
   "6",
   "7",
   "8",
   "9",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "a",
   "b",
   "c",
   "d",
   "e",
   "f",
   "g",
   "h",
   "i",
   "j",
   "k",
   "l",
   "m",
   "n",
   "o",
   "p",
   "q",
   "r",
   "s",
   "t",
   "u",
   "v",
   "w",
   "x",
   "y",
   "z",
   "Windows",
   "Windows",
   "Apps",
   "unknown",
   "Sleep",
   "Numpad 0",
   "Numpad 1",
   "Numpad 2",
   "Numpad 3",
   "Numpad 4",
   "Numpad 5",
   "Numpad 6",
   "Numpad 7",
   "Numpad 8",
   "Numpad 9",
   "Multiply",
   "Add",
   "Separator",
   "Subtract",
   "Decimal",
   "Divide",
   "F1",
   "F2",
   "F3",
   "F4",
   "F5",
   "F6",
   "F7",
   "F8",
   "F9",
   "F10",
   "F11",
   "F12",
   "F13",
   "F14",
   "F15",
   "F16",
   "F17",
   "F18",
   "F19",
   "F20",
   "F21",
   "F22",
   "F23",
   "F24",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "Numlock",
   "Scroll",
   "vk_oem_nec_equal",
   "vk_oem_fj_masshou",
   "vk_oem_fj_touroku",
   "vk_oem_fj_loya",
   "vk_oem_fj_roya",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "Shift",
   "Shift",
   "Control",
   "Control",
   "Menu",
   "Menu"
};

static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}
 void HotkeyButton(int aimkey, void* changekey, int status)
{
	const char* preview_value = NULL;
	if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(KeyNames))
		Items_ArrayGetter(KeyNames, aimkey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = _("Select Key");
	else
		aimkeys = preview_value;

	if (status == 1)
	{
		aimkeys = _("Press key to bind");
	}
	if (ImGui::Button(aimkeys.c_str(), ImVec2(125, 20)))
	{
		if (status == 0)
		{
			CreateThreadSafe(changekey);
		}
	}
}

bool City_Esp1,
City_Esp2,
City_Esp3,
City_Esp4,
City_Esp5,
City_Esp6,
City_Esp7,
City_Esp8,
City_Esp9,
City_Esp10,
City_Esp11,
City_Esp12,
City_Esp13,
City_Esp14,
City_Esp15,
City_Esp16,
City_Esp17,
City_Esp18,
City_Esp19,
City_Esp20,
City_Esp21,
City_Esp22,
City_Esp23,
City_Esp24,
City_Esp25,
City_Esp26,
City_Esp27,
City_Esp28;


bool IsValidPtr(void* pointer)
{
	if (!pointer)
		return false;

	if (pointer < (void*)0xFFF)
		return false;

	if (pointer > (void*)0x7FFFFFFFFFFF)
		return false;

	return true;
}

namespace globals
{
	uintptr_t process_id;
	HANDLE handle;

	HWND OverlayWnd;
	HWND TargetWnd;
	int Width, Height;
	bool console;
	 

	uint64_t Base;
	uint64_t World;
};
typedef struct _player_t
{
	std::uint64_t EntityPtr;
	std::uint64_t TableEntry;
	int NetworkID;
} player_t;

typedef struct _item_t
{
	std::uint64_t ItemPtr;
	std::uint64_t ItemTable;
} item_t;

#pragma once
 
#include "memory.h"
#include <string>
#include <TlHelp32.h>
#include "lazyimporter.h"
uintptr_t GetModule(const std::string& ModuleName)
{
	HANDLE hSnap = LI_FN(CreateToolhelp32Snapshot)(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, globals::process_id);
	if (hSnap == INVALID_HANDLE_VALUE) return 0;

	MODULEENTRY32 me32{ 0 };
	me32.dwSize = sizeof(me32);

	if (LI_FN(Module32First)(hSnap, &me32))
	{
		do
		{
			if (strcmp(ModuleName.c_str(), me32.szModule) == 0)
			{
				LI_FN(CloseHandle)(hSnap);
				return (uintptr_t)me32.modBaseAddr;
			}
		} while (LI_FN(Module32Next)(hSnap, &me32));
	}
	LI_FN(CloseHandle)(hSnap);
	return 0;
}
static __forceinline bool ZwCopyMemory(uint64_t address, PVOID buffer, uint64_t size, BOOL write = false)
{
	if (SDK::variables::handle == NULL)
		return false;

	SIZE_T bytes = 0;

	if (!write)
	{
		if (!ReadProcessMemory(SDK::variables::handle, (LPVOID)address, buffer, size, (SIZE_T*)&bytes))
			return false;

		if (bytes != size)
			return false;
	}
	else
	{
		if (!WriteProcessMemory(SDK::variables::handle, (LPVOID)address, buffer, size, (SIZE_T*)&bytes))
			return false;

		if (bytes != size)
			return false;
	}

	return true;
};
 
bool IsValidPtr2(void* pointer)
{
	if (!pointer)
		return false;

	if (pointer < (void*)0xFFF)
		return false;

	if (pointer > (void*)0x7FFFFFFFFFFF)
		return false;

	return true;
}


template <typename T>
static T ReadData1(uint64_t address)
{
	if (!address)
		return T();

	if (!IsValidPtr2((void*)address))
		return T();

	T buffer;
	return ZwCopyMemory(address, &buffer, sizeof(T), false) ? buffer : T();
};
template<typename t>
t ReadData(uintptr_t addr) {
	if (addr < 0xfffff)
		return t();
	if (addr > 0x7FFFFFFFFFFF)
		return t();

	return *reinterpret_cast<t*>(addr);
}
 

static std::string ReadString(uint64_t address, size_t size)
{
	if (!address || size > 1024)
		return _("");

	char string[1024] = "";
	return ZwCopyMemory(address, string, size, false) ? std::string(string) : _("");
};

std::string ReadArmaString(uint64_t address)
{
	int length = ReadData<int>(address + OFF_LENGTH);

	std::string text = ReadString(address + OFF_TEXT, length);

	return text.c_str();
}

#pragma once
 
#include "memory.h"
#include <string>

namespace Game
{
	uint64_t GetInventory(uint64_t Entity)
	{
		if (!IsValidPtr2((void*)Entity))
			return 0;

		return ReadData<uint64_t>(Entity + 0x658);
	}

	std::string FetchHands(uint64_t Entity)
	{
		auto Getch1 = Game::GetInventory(Entity);
		if (!Getch1)
			return ""; 

		return ReadArmaString(ReadData<uint64_t>(ReadData<uint64_t>(ReadData<uint64_t>(Game::GetInventory(Entity) + 0x1B0) + 0x168) + 0x4E8)).c_str();
	}

	uint64_t NearEntityTable()
	{
		return ReadData<uint64_t>(globals::World + 0xEB8);
	}

	uint32_t NearEntityTableSize()
	{
		return ReadData<uint32_t>(globals::World + 0xEB8 + 0x08);
	}

	uint64_t GetEntity(uint64_t PlayerList, uint64_t SelectedPlayer)
	{


		// Sorted Object
		return ReadData<uint64_t>(PlayerList + SelectedPlayer * 0x8);
	}

	std::string GetEntityTypeName(uint64_t Entity)
	{
		// Render Entity Type + Config Name
		return ReadArmaString(ReadData<uint64_t>(ReadData<uint64_t>(Entity + 0x168) + 0x4E8)).c_str();
	}
	std::string GetEntityTypeName2(uint64_t Entity)
	{
		// Render Entity Type + Config Name
		return ReadArmaString(ReadData<uint64_t>(ReadData<uint64_t>(Entity + 0x168) + 0Xa8)).c_str();
	}

	uint64_t FarEntityTable()
	{
		return ReadData<uint64_t>(globals::World + 0x1010);
	}

	uint32_t FarEntityTableSize()
	{
		return ReadData<uint32_t>(globals::World + 0x1010 + 0x08);
	}

	 

	uint64_t GetLocalPlayer()
	{ 


		return ReadData<uint64_t>(ReadData<uint64_t>(globals::World + 0x28d8) + 0x8) - 0xA8;
	}
 
	uint64_t GetLocalPlayerVisualState()
	{
		// Future Visual State
		return ReadData<uint64_t>(GetLocalPlayer() + 0x1C0);
	}
	struct matrix4x4
	{
		float m[12];
	};

	uint64_t BulletTable() {
		auto bullet = ReadData<uint64_t>(globals::World + 0xD70);
		if (!bullet)
			return 0;



		return bullet;
	}

	uint64_t BulletTableSize() {
		return sizeof(BulletTable());
	}
 

	BOOL GetBonePosition(DWORD64 skeleton, DWORD64 visual, DWORD index, Vector3* out)
	{
		uint64_t animClass = ReadData<uint64_t>( skeleton + 0x98);
		if (!IsValidPtr2((void*)animClass))
			return 0;


		uint64_t matrixClass = ReadData<uint64_t>(animClass + 0xBF0);
		if (!IsValidPtr2((void*)matrixClass))
			return 0;
 
		 matrix4x4 matrix_a= ReadData< matrix4x4>( visual + 0x8);

		
		Vector3 matrix_b = ReadData<Vector3>( matrixClass + 0x54 + index * sizeof(SDK::utils::maths::mat4x4_t));

		out->x = (matrix_a.m[0] * matrix_b.x) + (matrix_a.m[3] * matrix_b.y) + (matrix_a.m[6] * matrix_b.z) + matrix_a.m[9];
		out->y = (matrix_a.m[1] * matrix_b.x) + (matrix_a.m[4] * matrix_b.y) + (matrix_a.m[7] * matrix_b.z) + matrix_a.m[10];
		out->z = (matrix_a.m[2] * matrix_b.x) + (matrix_a.m[5] * matrix_b.y) + (matrix_a.m[8] * matrix_b.z) + matrix_a.m[11];
		return TRUE;
	}

	uint64_t GeVisualState(uint64_t Enity)
	{
		if (!IsValidPtr2((void*)Enity))
			return 0;

		return ReadData<uint64_t>(Enity + 0x1C0);
	}
	uint64_t GetSkeleton(uint64_t Entity,int s2) {

		uint64_t Skeleton;
		 
		if(s2==1)
		Skeleton = ReadData<uint64_t>(Entity + 0x810);

		if (s2== 2)
		 Skeleton = ReadData<uint64_t>(Entity + 0x678);

		return Skeleton;
	}

	Vector3 GetCoordinate(uint64_t Entity)
	{
		while (true)
		{
			if (Entity == GetLocalPlayer())
			{
				return Vector3(ReadData<Vector3>(GetLocalPlayerVisualState() + 0x2C));
			}
			else
			{
				return  Vector3(ReadData<Vector3>(ReadData<uint64_t>(Entity + 0x1C0) + 0x2C));
			}
		}
	}
	void SetCoordinate(uint64_t myplayer ,float x,float y ,float z)
	{
		
		
		Vector3 Vissual = Game::GetCoordinate(myplayer);

		//auto Vissual = ReadData<Vector3>(GetLocalPlayerVisualState() + 0x2C);
		 
		
		*reinterpret_cast<Vector3*>(GetLocalPlayerVisualState() + 0x2C)= { Vissual.x + x,Vissual.y+ y,Vissual.z+ z };
			 
		
	}

	uint64_t GetCamera()
	{
	//	while (true)
	//	{
		uint64_t cam = ReadData<uint64_t>(globals::World + 0x1B8);

		return cam;
		//}
	}

	Vector3 GetInvertedViewTranslation()
	{
		return Vector3(ReadData<Vector3>(GetCamera() + 0x2C));
	}
	Vector3 GetInvertedViewRight()
	{
		return Vector3(ReadData<Vector3>(GetCamera() + 0x8));
	}
	Vector3 GetInvertedViewUp()
	{
		return Vector3(ReadData<Vector3>(GetCamera() + 0x14));
	}
	Vector3 GetInvertedViewForward()
	{
		return Vector3(ReadData<Vector3>(GetCamera() + 0x20));
	}

	Vector3 GetViewportSize()
	{
		return Vector3(ReadData<Vector3>(GetCamera() + 0x58));
	}

	Vector3 GetProjectionD1()
	{
		return Vector3(ReadData<Vector3>(GetCamera() + 0xD0));
	}

	Vector3 GetProjectionD2()
	{
		return Vector3(ReadData<Vector3>(GetCamera() + 0xDC));
	}

 

	float GetDistanceToMe(Vector3 Entity)
	{
		return Entity.Distance(GetCoordinate(GetLocalPlayer()));
	}


	bool WorldToScreen1(Vector3 Position, Vector3& output)
	{
		if (!GetCamera()) return false;

		Vector3 temp = Position - GetInvertedViewTranslation();

		float x = temp.Dot(GetInvertedViewRight());
		float y = temp.Dot(GetInvertedViewUp());
		float z = temp.Dot(GetInvertedViewForward());
		if (z < 0.1f)
			return false;
		if (z < 0.1f)
			return false;

		Vector3 res(
			GetViewportSize().x * (1 + (x / GetProjectionD1().x / z)),
			GetViewportSize().y * (1 - (y / GetProjectionD2().y / z)),
			z);

		if (res.z < 1.1f)
			return false;

		output.x = res.x;
		output.y = res.y;
		output.z = res.z;
		return true;
	}
 
	bool WorldToScreen(Vector3 Position, Vector3& output) {
 
		uint64_t camera = ReadData<uint64_t>(globals::World + 0x1b8);
		if (!camera)
			return false;
	auto InvertedViewRight = ReadData<Vector3>(camera + 0x8);
	auto InvertedViewUp = ReadData<Vector3>(camera + 0x14);
	auto InvertedViewForward = ReadData<Vector3>(camera + 0x20);
	auto InvertedViewTranslation = ReadData<Vector3>(camera + 0x2C);
	auto ProjectionD1 = ReadData<Vector3>(camera + 0xD0);
	auto ProjectionD2 = ReadData<Vector3>(camera + 0xDC);

		Vector3 temp = Position - InvertedViewTranslation;
		float x = temp.Dot(InvertedViewRight);
		float y = temp.Dot(InvertedViewUp);
		float z = temp.Dot(InvertedViewForward);
		if (z < 0.1f) return false;
		Vector3 res(
			GetViewportSize().x * (1 + (x / GetProjectionD1().x / z)),
			GetViewportSize().y * (1 - (y / GetProjectionD2().y / z)),
			z);
		if (res.z < 1.1f)
			return false;
		output.x = res.x;
		output.y = res.y;
		output.z = res.z;
		return true;
	}
	bool SetPosition(uint64_t Entity, Vector3 TargetPosition)
	{
		if (Entity == Game::GetLocalPlayer()) {

			*reinterpret_cast<Vector3*>(ReadData<uint64_t>(Entity + 0xF0) + 0x2C) = TargetPosition;
		}
		else {
			*reinterpret_cast<Vector3*>(ReadData<uint64_t>(Entity + 0x1C0) + 0x2C)= TargetPosition;
		}
		return true;
	}
	

	Vector3 GetObjectVisualState(uintptr_t entity)
	{
		if (entity)
		{
			uintptr_t renderVisualState = ReadData<uintptr_t>(entity + 0x1C0);

			if (!IsValidPtr((void*)renderVisualState))
				return Vector3(-1, -1, -1);

			if (renderVisualState)
			{
				Vector3 pos = ReadData<Vector3>(renderVisualState + 0x2C);
				return pos;
			}
		}

		return Vector3(-1, -1, -1);
	}

}

float GetFov(Vector3 pos) {

	Vector3 currentworld;

	Game::WorldToScreen(pos, currentworld);



	if (currentworld.empty())
		return 1000;
	ImGuiIO& io = ImGui::GetIO();

	return Vector2(io.DisplaySize.x / 2, io.DisplaySize.y / 2).Distance(currentworld.xy());
}

/**
 * Copyright (c) 2019 exsightcore (by emey)
 * last up - 04.19.2019
 */


#include <cstdint>
#include <string>
#include "vectoprr.h"
using namespace std;

#define off_cameraentry_movupdown 0xcc
#define off_cameraentry_movforwardbackward 0xc8
#define off_cameraentry_movleftright 0xd4
#define off_cameraentry_movrotate 0xd4
 
//class EnfusionEngine
//{
//public:
//
//	static void MovCameraUp();
//	static void MovCameraDown();
//	static void MovCameraRight();
//	static void MovCameraLeft();
//	static void MovCameraForward();
//	static void MovCameraBackward();
//	static void SetTerrainGrid(float value);
//	static float CameraSpeed;
//	//static bool SetPosition(uint64_t Entity, Vector3 to);
//	static bool KillBySilentAim(uint64_t Entity);
//	static bool SetCameraMovSpeed(float Speed);
//	static Vector3 GetInvertedViewRight();
//	static Vector3 GetInvertedViewUp();
//	static Vector3 GetInvertedViewForward();
//	static Vector3 GetViewportSize();
//	static Vector3 GetInvertedViewTranslation();
//	static Vector3 GetProjectionD1();
//	static Vector3 GetProjectionD2();
//	static string GetDirection();
//	static uint64_t GetCamera();
//	static uint64_t GetCameraEntry();
//	static uint64_t GetCameraOn();
//	static uint64_t GetLocalPlayer();
//
//	static float RadiansToDegrees(float value);
//private:
//	static string ReadArmaString(uint64_t address);
//};
// 
//
//
//uint64_t EnfusionEngine::GetCamera() {
//	return  ReadData<uint64_t>(
//		globals::World + 0x28d0);
//}
////
//
//uint64_t EnfusionEngine::GetCameraOn() {
//
//		
//		
//		auto get = ReadData<uint64_t>(globals::World + 0x28D8);
//	//	std::printf("GetCameraOn %llx \n", get);
//
//		return get;
//}
//uint64_t EnfusionEngine::GetLocalPlayer() {
//
//auto get =ReadData<uint64_t>(EnfusionEngine::GetCameraOn() + 0x8);
//
////std::printf("GetLocalPlayer %llx \n", get);
//return get;
//}
//
//uint64_t EnfusionEngine::GetCameraEntry() {
//	
////	std::printf("Game::GetLocalPlayer() %llx \n", Game::GetLocalPlayer());
//
//	auto get =	ReadData<uint64_t>(Game::GetLocalPlayer() + 0x23d8);
//	std::printf("GetCameraEntry %llx \n", get);
//
//	return get;
//}
//
//bool EnfusionEngine::SetCameraMovSpeed(float Speed) {
//	EnfusionEngine::CameraSpeed = Speed;
//	return true;
//}
//
//float EnfusionEngine::CameraSpeed = 1.0f;
//
//void EnfusionEngine::MovCameraUp() {
//	if (EnfusionEngine::CameraSpeed <= 0) { EnfusionEngine::CameraSpeed = 1.0f; }
//
//	float updown = ReadData<float>(
//		EnfusionEngine::GetCameraEntry() + off_cameraentry_movupdown);
//
//	WriteData<float>(
//		EnfusionEngine::GetCameraEntry() + off_cameraentry_movupdown, updown + EnfusionEngine::CameraSpeed);
//}
//
//void EnfusionEngine::MovCameraDown() {
//	if (EnfusionEngine::CameraSpeed <= 0) { EnfusionEngine::CameraSpeed = 1.0f; }
//
//	float updown = ReadData<float>(
//		EnfusionEngine::GetCameraEntry() + off_cameraentry_movupdown);
//
//	WriteData<float>(
//		EnfusionEngine::GetCameraEntry() + off_cameraentry_movupdown, updown - EnfusionEngine::CameraSpeed);
//}
//
//void EnfusionEngine::MovCameraRight() {
//	if (EnfusionEngine::CameraSpeed <= 0) { EnfusionEngine::CameraSpeed = 1.0f; }
//
//	float updown = ReadData<float>(
//		EnfusionEngine::GetCameraEntry() + off_cameraentry_movleftright);
//
//	WriteData<float>(
//		EnfusionEngine::GetCameraEntry() + off_cameraentry_movleftright, updown + EnfusionEngine::CameraSpeed);
//}
//
//void EnfusionEngine::MovCameraLeft() {
//	if (EnfusionEngine::CameraSpeed <= 0) { EnfusionEngine::CameraSpeed = 1.0f; }
//
//	float updown = ReadData<float>(	EnfusionEngine::GetCameraEntry() + off_cameraentry_movleftright);
//
//	WriteData<float>(
//		EnfusionEngine::GetCameraEntry() + off_cameraentry_movleftright, updown - EnfusionEngine::CameraSpeed);
//}
//
//void EnfusionEngine::MovCameraForward() {
//	if (EnfusionEngine::CameraSpeed <= 0) 
//	{
//		EnfusionEngine::CameraSpeed = 1.0f;
//	}
//
//	float updown = ReadData<float>(EnfusionEngine::GetCameraEntry() + off_cameraentry_movforwardbackward);
//	//std::printf("updown %f \n", updown);
//
//	WriteData<float>( EnfusionEngine::GetCameraEntry() + off_cameraentry_movforwardbackward, updown + EnfusionEngine::CameraSpeed);
//}
//
//void EnfusionEngine::MovCameraBackward() {
//	if (EnfusionEngine::CameraSpeed <= 0) { EnfusionEngine::CameraSpeed = 1.0f; }
//
//	float updown = ReadData<float>(
//		EnfusionEngine::GetCameraEntry() + off_cameraentry_movforwardbackward);
//
//	WriteData<float>(
//		EnfusionEngine::GetCameraEntry() + off_cameraentry_movforwardbackward, updown - EnfusionEngine::CameraSpeed);
//}
