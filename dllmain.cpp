#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#pragma comment (lib, "RebirthGuard.lib")       //Lib pra deletar dll
#include "RebirthGuardSDK.h"
#include <Windows.h>
#include <cstdint>
#include "Globals.h"
#include "Hooker.h"
#include "Renderer.h"
#include "Utils.h"
#include "Squad.h"
#include "menu_config.h"
#include "xorstr.h"
#include "Vector.hpp"
#include "Vector2.h"
#include "Logo.h"
#include <string>
#include <chrono>
#include "stdafx.h"
#include <WinInet.h>
bool City_Esp;
bool City_Esp0e1 =1;
std::string getNameFromId(uintptr_t namePointer);
float CameraSpeed = 1.0f;
HMODULE module12;
#include <filesystem>   
#include <winerror.h>
#include "dayz.h"
#include <TlHelp32.h>
#include <map>;
#include "lazyimporter.h"
#include "winternl.h"
int isnpc = 0;
#include "hotkeys.h"
 void allocate_consowwle()
{
	AllocConsole();
	freopen(xorstr_("CONOUT$"), "w", stdout);
}

#include <iostream>
#include <string>
#include <functional>

 
float aimfov = 80;
int num1 = 18, num2 = 45, num3 = 45, num4 = 69, num5 = 45, num6 = 72, num7 = 45, num8 = 15, num9 = 69, num10 = 48, num11 = 72, num12 = 102, num13 = 15, num14 = 3, num15 = 15, num16 = 9;
bool enableSpeed;
bool anablefov;
int addr;
int speeedbeckup;
int speeedbeckup1;
bool speeonce = false;
bool speeonce1 = false;
int speedtest = 10000000;
uintptr_t* resultant_target_entity = nullptr;
std::vector<uintptr_t*> valid_players;
 std::vector<uintptr_t*> valid_players1;
std::vector<uintptr_t*> valid_players2;

bool Iemtelist;
bool Iemtelis2t;
bool Iemtelist1;
bool twaeawe;
bool twaeawe1;
bool awaysday;
bool Slowly;
bool cosmetic;
float  maxplayer = 10000, maxzombie = 10000, maxanimal = 10000, maxcar = 10000, maxloot = 10000;
bool cosmetic2;
bool cosmetic3;
bool cosmetic4;
bool FarEntity = true;
bool showplayer=1;
bool showplayer1;
bool Skelet1Player=1;
bool inventoryespcaixa;
bool Cargoesp ;
bool inventoryesp=0;
bool inventoryesp1;
bool inventoryesphand=1;
bool inventoryespfull =1;
 int Adds = 0x18;

bool Skelet1Zombie;
bool showzombie;
bool showzombie1;
bool showAnimal;
bool car;
bool debugged;
bool debugg;
bool debugg2, debugg3, debugg4, debugg5;
bool MEAVehicles;
bool BRTVehicles;
bool MILVehicles;
bool RUSVehicles;
bool INSVehicles;
bool USAVehicles;
float horas;
float posx, posy, posz;
float posx1, posy1, posz1 =100;
bool Skelet1;
int boneidlist;
bool SpeedHackk;
float INSVeh[] = { 255, 0, 255, 255.f };
float INSVeh1[] = { 255, 122, 31, 255.f };
float INSVeh2[] = { 255, 0, 0, 255.f };
float BRTVeh[] = { 233, 255, 0, 255.f };
float RUSVeh[] = { 255, 0, 255, 255.f };
float FOVRADIO[] = { 0, 255, 255, 255.f };
float HAB[] = { 0, 0, 255, 255.f };
float ammocratee[] = { 0, 0, 255, 255.f };
float RUSVeh1[] = { 255, 0, 255, 255.f };
float RUSVeh11[] = { 0, 0, 255, 255.f };
float SkeletCollor[] = { 0, 0, 0, 255.f };
float SkeletCollorvisible[] = { 0, 0, 0, 255.f };
float FOVCOLORR[] = { 0, 0, 0, 255.f };
float USAVeh[] = { 0, 0, 0, 255.f };
float MEAVeh[] = { 0, 0, 0, 255.f };
float TesTESP[] = { 255, 0, 0, 255.f };
bool aimHead;
bool AimChest;
bool AimPelvis;
float grass;
float PosCords[3] = { 0.f, 0.f , 0.f };

bool Xbutton2;
bool Xbutton1;
bool caital;
bool keyc;
bool TeamESpNew;
bool TeamESpNew2;
bool controll;
bool Lshidht;
bool keyf;
bool mbutton, RBUTTON, LBUTTON;
float TimeBetweenShots = -1;
float recoilslod;
float bBoltBetweenRounds;
bool bMuzzleVelocity, bMaxDamageToApply;
int bInfiniteAmmo, bShowAmmoInHUD, bInfiniteClip, InitialClips;
bool bInfiniteAmmo1, bTimeBetweenShots, bShowAmmoInHUD1, bInfiniteClip1, bBoltBetweenRounds1, TimeBetweenShots1, InitialClips1, bbCreateProjectileOnServer, bbbCreateProjectileOnServer;
bool bInfiniteAmmo2, bShowAmmoInHUD2, bInfiniteClip2, bBoltBetweenRounds2, TimeBetweenShots2, InitialClips2;
bool Ammo;
bool toggle_line;
bool aimbot_bullet_drop;
bool aimbot_smoothing;
bool weapon_projectile_speed;
bool crosshair;
bool colour_mgr;
bool show_fov = 0;
float fov_value = 1200.f;
float smooth_value = 2.6026f;
float projectile_speed_value;
float red = 255;
float green;
float blue;
float alpha = 255;
bool esp_tab;
bool esp;
bool esp_player_usa;
bool esp_player_ru;
bool esp_player_GB;
bool esp_player_INS;
bool esp_player_CAF;
bool esp_player_MIL;
bool toogle_2dboxMIL;
bool esp_player_skeleton = true;
bool esp_player_skeleton1 = true;
bool glowVisible;
bool glowHidden;
#define M_PI 3.14159265358979323846
bool esp_player_tag = true;
bool noclip;
bool esp_player_team;
float skeleton_colour[3] = { 0.f, 1.f, 0.0f };
float extraction_colour[3] = { 0.f, 1.f, 0.0f };
bool esp_extractions;
bool esp_corpses;
bool esp_item;
float sliderflov = 0.005f;
bool esp_bots;
bool esp_player_visible;
bool esp_player_sleeping;
bool esp_rock;
bool esp_chicken;
bool esp_bear;
bool toogle_2dboxCAF;
bool toggle_lineCAF;
bool toggle_lineMIL;
bool Delatation = true;
float Delation_Value = 2.0f;
bool BDelation_Value;
bool toogle_2dbousa;
bool toggle_distance;
bool toggle_lineusa;
bool toggle_distance_MIL;
bool toggle_distance_USA;
bool toggle_distance_RU;
bool toggle_distance_GB;
bool toggle_distance_INS;
bool toggle_distance_CAF;
bool RapidFire;
bool toogle_2dboxru;
bool test1;
bool Aimbot;
bool toogle_2dboxGB;
bool toggle_lineGB;
float skeleton_thickness_value = 1;
bool toogle_2dboxINS;
bool toggle_lineINS;
bool esp_wolf;
bool esp_deer;
bool esp_loot_container;
bool esp_loot_weapon;
bool esp_loot_clothes;
bool esp_loot_others;
bool esp_boar;
bool esp_horse;
bool esp_supply_drop;
bool esp_stash;
bool esp_vans;
bool esp_tanks;
bool esp_btr;
bool esp_atvs;
bool esp_fobs;
bool esp_helicopters;
bool esp_projectile;
bool esp_rally_points;
bool esp_radios;
bool esp_keycards;
bool esp_droppeditems;
bool esp_droppedweapons;
bool esp_inventory;
bool esp_max;
bool esp_storagecotainer;
bool esp_minicopters;
bool esp_lockedcrates;
bool toggle_lineru;
float esp_max_distance;
float esp_min_distance;
bool aim_tab;
bool weapon;
bool weaponToggle;
int weaponkey;
bool qualidade;
bool ProxyMagazines;
bool ProxyMagazines1;
bool Miras;
bool rodas;
bool inventoryItem12 =0;
bool inventoryItem132 =0;
bool inventoryItem2 = 0;
bool inventoryItem22 = 1;
bool inventoryItem222 = 0;
bool inventoryItem2222 =1;
bool inventoryItem22221=1;

bool comida;
bool Containers;
bool BackPack;
bool comida1;
bool medicine;
bool medicine1;
bool drinks;
bool drinks1;
bool clothing;
bool clothing1;
bool inventoryItem;
bool inventoryItemsss;
bool misc;
bool recoil_modify;
bool recoil_modify1;
bool sight_zoom;
bool field_of_view_modify;
bool rapid_fire;
bool unlimited_ammo;
bool speed_multiplier;
float speed_multipler_value = 1.f;
float recoil_value;
float zoom_value;
float fov_value_modify;
float spread_value;
bool sway_modify;
bool unlimitedammo;
bool Norecoil;
float sway_value;
bool debug_camera;
bool debug_mode;
bool othervehicles;
int bone_limiter;
bool climb_walls;
bool no_fall;
bool auto_weapons;
bool third_person;
bool fast_bullet;
bool thick_bullet;
bool no_range;
bool no_spread;
bool high_step;
bool no_gravity;
bool unlock_shoot_restriction;
int aim_Key;
int selected_item_key;
int selected_item_bone;
float font_size = 16.f;
int bone_choice;
bool norecoil;
bool norecoil2;
bool toogle_2dbox;
bool cornervis, cornernotvis;

#define STB_IMAGE_IMPLEMENTATION
Vector3 SAVEDPOS;
#include <iostream>
#include <thread>
#include "speedhack.h"
#include <mutex>
#include "font.h"
//#include "C:/Users/2/Desktop/Game-Radar-main/stb_image.h"
bool esp_trucks;

bool Cordednada;
bool SilentAim;
bool SleepBbutton;
using namespace SDK;
#define telep 0x2026610;
WNDPROC oriWndProc = NULL;
bool toggle_menu = false;
bool toggle_menu1 = false;
bool toggle_tab_1;
bool toggle_recoil;
bool toogle_fov;
bool toogle_sway;
bool toogle_spread;
float Sliderrx;
float Sliderry;

float esp_btrcolor[3]{ 1,0,0 };
float esp_atvsColor[3]{ 1,0,0 };
float esp_vansColor[3]{ 1,0,0 };
float GlowColor[3]{ 0,1,0 };
float DsitanceColor[3]{ 1,0,0 };
float esp_ifvsColor[3]{ 1,0,0 };

float esp_tanksColor[3]{ 1,0,0 };
float FovColor[3]{ 1,0,0 };
float GlowColorHide[3]{ 1,0,0 };


float esp_apcolor[3]{ 1,0,0 };
float esp_btrolor[3]{ 1,0,0 };
float esp_atvscolor[3]{ 1,0,0 };
float esp_helicopterscolor[3]{ 1,0,0 };
float esp_trucksolor[3]{ 1,0,0 };
float esp_fobColor[3]{ 1,0,0 };
float esp_fobscolor[3]{ 1,0,0 };
float esp_trucksColor[3]{ 1,0,0 };

float esp_radiosColor[3]{ 1,0,0 };
float esp_rally_pointsColor[3]{ 1,0,0 };



float  MuzzleVelocity = 999;

float   MaxDamageToApply = 999;
ImFont* SkeetFont;



int ok = 0;

//void* __fastcall hkCreateProjectile(void * ecx, bool forward) {
//
//	 
//	 
//	 
//
//	 
//	SDK::squad::APlayerController* projectile = *reinterpret_cast<SDK::squad::APlayerController**>(functions::original_FnK2_TeleportTo(ecx,forward));
//
// 
//	return projectile;
//}

size_t CurTabOpen = 0;
bool Aimboot;
bool pelsvis;
bool chest;
bool Aimboot1;
void AddTab(size_t Index, const char* Text)
{
	static const size_t TabWidth = 85;
	static const size_t TabHeight = 25;

	ImGui::PushID(Index);
	ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 4);

	if (Index == 1)
		ImGui::SameLine(Index * (TabWidth + 5));
	else if (Index > 1)
		ImGui::SameLine(Index * (TabWidth + 4 - Index));

	if (CurTabOpen == Index)
		ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(0.70f, 0.0f, 0.0f));			// Color on tab open
	else
		ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(30, 30, 30));			// Color on tab closed

	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(0.70f, 0.0f, 0.0f));			// Color on mouse hover in tab
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(35, 35, 35));			// Color on click tab

	if (ImGui::Button(Text, ImVec2(TabWidth, TabHeight)))	// If tab clicked
		CurTabOpen = Index;

	ImGui::PopStyleVar();
	ImGui::PopStyleColor(3);
	ImGui::PopID();
}



static const char* keys_list[]{ "caps lock", "alt", "right mouse btn", "left mouse btn" };
static const char* bone_list[]{ "head", "neck", "torso" };

static int currentColumn = 0;
static bool choosing_key_bind = false;
static std::string chosen_key_name;
bool AimbotRbuttom;
bool aimbotC;
bool AimbotF;
int logo_width = 0;
int logo_height = 0;
ID3D11ShaderResourceView* texture_logo;
utils::maths::vectype2::FVector Temp = { 0,0,0 };

namespace ImGui
{
	void BuildColourPicker(std::string id_str, std::string id_str2, std::string text, float* colour_data)
	{
		bool open_pop_up_skeleton = ImGui::ColorButton(id_str.c_str(), ImColor{ colour_data[0], colour_data[1], colour_data[2], 1.f }, ImGuiColorEditFlags_NoTooltip);
		if (open_pop_up_skeleton)
			ImGui::OpenPopup(id_str2.c_str());

		if (ImGui::BeginPopup(id_str2.c_str()))
		{
			ImGui::ColorPicker4(text.c_str(), colour_data, ImGuiColorEditFlags_RGB);
			ImGui::EndPopup();
		}
	}
}
void Active() { ImGuiStyle* Style = &ImGui::GetStyle(); Style->Colors[ImGuiCol_Button] = ImColor(25, 30, 34); Style->Colors[ImGuiCol_ButtonActive] = ImColor(25, 30, 34); Style->Colors[ImGuiCol_ButtonHovered] = ImColor(25, 30, 34); }
void Hovered() { ImGuiStyle* Style = &ImGui::GetStyle(); Style->Colors[ImGuiCol_Button] = ImColor(19, 22, 27); Style->Colors[ImGuiCol_ButtonActive] = ImColor(19, 22, 27); Style->Colors[ImGuiCol_ButtonHovered] = ImColor(19, 22, 27); }
float mid;
float mid2;
float mid2ve2;
float mid2ve22;
ImFont* Mark;
bool esp_ifvs;
bool esp_apc;
bool esp_jeeps;
static int mAimbot = -1;
static int mAimbot2 = -1;
constexpr auto windowFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;


static bool ilks = true;
static bool applyp = false;
static bool Bosta = false;
std::string one;
std::string Serverid;
std::string Serverid2;
std::string protect;
std::string testing;
std::string kadi;

static bool open = true;
static int menu = 0;
MSG msg;
inline std::string senha;
bool show_sam_window = false;
bool show_entity_scanner = true;
bool show_radar = true;
bool show_radarOptions = true;
bool show_direction_lines = true;
float sqrtf1(float _X
) {
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(_X)));
}

uintptr_t* get_closest_Item(std::vector<uintptr_t*> list, float field_of_view)
{
	ImGuiIO& io = ImGui::GetIO();

	uintptr_t* resultant_target_entity_temp = nullptr;
	float closestTocenter = FLT_MAX;

	for (auto curr_entity : list)
	{


		Vector3 currentworld;

		Vector3 Pos = Game::GetObjectVisualState((uintptr_t)curr_entity);


		Game::WorldToScreen(Pos, currentworld);
		auto dx = currentworld.x - (variables::game_screen_X / 2);

		auto dy = currentworld.y - (variables::game_screen_Y / 2);
		auto dist = sqrtf1(dx * dx + dy * dy);

		if (dist < field_of_view && dist < closestTocenter) {
			closestTocenter = dist;
			resultant_target_entity_temp = curr_entity;
		}


	}

	return resultant_target_entity_temp;
}
uintptr_t* get_closest_Item1(std::vector<uintptr_t*> list, float field_of_view)
{
	ImGuiIO& io = ImGui::GetIO();

	uintptr_t* resultant_target_entity_temp = nullptr;
	float closestTocenter = FLT_MAX;

	for (auto curr_entity : list)
	{


		Vector3 currentworld;

		Vector3 Pos = Game::GetObjectVisualState((uintptr_t)curr_entity);

 		Game::WorldToScreen(Pos, currentworld);
		auto dx = currentworld.x - (variables::game_screen_X / 2);

		auto dy = currentworld.y - (variables::game_screen_Y / 2);
		auto dist = sqrtf1(dx * dx + dy * dy);

		if (dist < field_of_view && dist < closestTocenter) {
			closestTocenter = dist;
			resultant_target_entity_temp = curr_entity;
		}


	}

	return resultant_target_entity_temp;
}
uintptr_t* get_closest_Item2(std::vector<uintptr_t*> list, float field_of_view)
{
	ImGuiIO& io = ImGui::GetIO();

	uintptr_t* resultant_target_entity_temp = nullptr;

	for (auto curr_entity : list)
	{


		Vector3 currentworld;

		Vector3 Pos = Game::GetObjectVisualState((uintptr_t)curr_entity);

		Game::WorldToScreen(Pos, currentworld);


		float pythag_result = sqrtf(pow((((float)variables::game_screen_X / 2) - currentworld.x), 2) + pow((((float)variables::game_screen_Y / 2) - currentworld.y), 2));

		auto closest_fov = aimfov;


		if (pythag_result <  aimfov && closest_fov > pythag_result)
		{


			resultant_target_entity_temp = curr_entity;
			closest_fov = pythag_result;

		}


	}

	return resultant_target_entity_temp;
}




uintptr_t* get_closest_player(std::vector<uintptr_t*> list, float field_of_view, int s2)
{
	ImGuiIO& io = ImGui::GetIO();

	uintptr_t* resultant_target_entity_temp = nullptr;
	float closestTocenter = FLT_MAX;

	for (auto curr_entity : list)
	{
		uint64_t Skeleton;

		if (s2 == 1)
			Skeleton = ReadData<uint64_t>((uint64_t)curr_entity + 0x810);

		if (s2 == 2)
			Skeleton = ReadData<uint64_t>((uint64_t)curr_entity + 0x678);

		if (!IsValidPtr((void*)Skeleton))
			continue;

		Vector3 current;
		Vector3 currentworld;


		Game::GetBonePosition(Skeleton, Game::GeVisualState((uint64_t)curr_entity), 18, &current);


		Game::WorldToScreen(current, currentworld);
		auto dx = currentworld.x - (variables::game_screen_X / 2);

		auto dy = currentworld.y - (variables::game_screen_Y / 2);
		auto dist = sqrtf1(dx * dx + dy * dy);

		if (dist < field_of_view && dist < closestTocenter) {
			closestTocenter = dist;
			resultant_target_entity_temp = curr_entity;
		}
	}

	return resultant_target_entity_temp;
}


bool SilentAim1(uint64_t Entity, int ss)
{
	if (!Entity)
		return false;





	int index = 0;
	if (ss == 1)
		index = 24;

	if (ss == 2)
		index = 15;


	Vector3 worldPosition = Game::GetCoordinate((uintptr_t)resultant_target_entity);

	Vector3 outPos;


	Vector3 Pos = Game::GetObjectVisualState((uintptr_t)resultant_target_entity);


	int distance = Game::GetDistanceToMe(worldPosition);

	Game::WorldToScreen(Pos, outPos);

	uintptr_t Skeleton;

	if (ss == 1)
		Skeleton = ReadData<uint64_t>((uint64_t)resultant_target_entity + 0x810);

	if (ss == 2)
		Skeleton = ReadData<uint64_t>((uint64_t)resultant_target_entity + 0x678);

	Vector3 current;
	Vector3 currentworld;


	Game::GetBonePosition(Skeleton, Game::GeVisualState((uint64_t)resultant_target_entity), index, &current);


	Game::WorldToScreen(current, currentworld);


	rendering::Renderer::GetInstance()->DrawLine({ (float)variables::game_screen_X / 2, (float)variables::game_screen_Y / 2 }, { currentworld.x,currentworld.y }, { FovColor[0] * 255, FovColor[1] * 255, FovColor[2] * 255, 255.f }, 1.0f);

	uintptr_t entityTable = ReadData<uintptr_t>(globals::World + 0xD70);
	if (!IsValidPtr((void*)entityTable))
		return false;

	int objectTableSz = ReadData<int>(globals::World + 0xD70 + 0x8);
	if (objectTableSz < 1)
		return false;
	//TransData transData = world.GetTransData();
	for (uint64_t i = NULL; i < objectTableSz; i++)
	{
		if (!entityTable)
			continue;

		uint64_t entity = ReadData<uint64_t>(entityTable + (i * 0x8));
		if (!IsValidPtr((void*)entity))
			continue;

		Vector3 WorldPosition = Game::GetCoordinate(Entity);

		int distance = Game::GetDistanceToMe(WorldPosition);
		if(distance  )
		Vector3 outPos;

		Game::WorldToScreen(WorldPosition, outPos);
		 
	 

		if (SilentAim)
			Game::SetPosition(entity, current);




	}


 
	return true;
}
KeyBindToggle activate_bind11 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)

inline void __stdcall main_aimboo2(int ss)
{
	
	if (!LI_FN(GetAsyncKeyState)(activate_bind11.toInt()))
		resultant_target_entity = nullptr;

	if (LI_FN(GetAsyncKeyState)(activate_bind11.toInt()))
	{
		if (!resultant_target_entity)
			resultant_target_entity = get_closest_player(valid_players, aimfov, ss);
		if (!resultant_target_entity)
			return;

		Vector3 worldPosition = Game::GetCoordinate((uint64_t)resultant_target_entity);

		int dist = Game::GetDistanceToMe(worldPosition);

	
			if(dist  > 1200 ){

				resultant_target_entity = nullptr;
				return;
			}
		

		SilentAim1((uintptr_t)resultant_target_entity, ss);






	}


}

 
 
KeyBindToggle activate_bind = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind1 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind2 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind3 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind4 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind5 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind6 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind7 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind8 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind9 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind10 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)
KeyBindToggle activate_bind12 = KeyBindToggle(KeyBind::KeyCode::MAX); // key variable, selected default hotkey (insert)


float VisualTabx = 700;
float VisualTaby = 500;

void testt() {



}
bool draw_abigsquare()
{
	static int MenuTab = 0;
	static int VisualTab = 0;
	float
		TextSpaceLine = 90.f,
		SpaceLineOne = 120.f,
		SpaceLineTwo = 280.f,
		SpaceLineThr = 420.f;
	ImGuiStyle* style = &ImGui::GetStyle();

	static auto flags = ImGuiWindowFlags_NoCollapse;



	//this is a pas te
	//ImGui::Begin(XorStr("Silence"), NULL, flags);
	//ImGui::Begin(_("Immune"), NULL, flags);
	ImGui::Begin(_("Cheesy Private"), NULL, flags);
	{
		ImGui::SetWindowSize(ImVec2(VisualTabx, VisualTaby));
		{
			ImGui::BeginChild(_("##Tabs"), ImVec2(-1, 30.0f));
			{
				style->ItemSpacing = ImVec2(1, 1);
				ImGui::PushFont(SkeetFont);
				{
					if (ImGui::Button(_("Player"), ImVec2(100, 20)))
					{
						MenuTab = 0;
					}ImGui::SameLine();
					if (ImGui::Button(_("Visuals"), ImVec2(100, 20)))
					{
						MenuTab = 1;
					}
					ImGui::SameLine();
					if (ImGui::Button(_("City"), ImVec2(100, 20)))
					{
						MenuTab = 2;
					}
					ImGui::SameLine();
					//if (ImGui::Button(_("Color"), ImVec2(100, 20)))
					//{
					//	MenuTab = 3;
					//}ImGui::SameLine();
				} ImGui::PopFont();

			} ImGui::EndChild();

			style->ItemSpacing = ImVec2(8, 8);

			if (MenuTab == 0)
			{

			ImGui::Checkbox(xorstr_("Sleep"), &SleepBbutton);
			ImGui::Checkbox(xorstr_("Bullet TP"), &SilentAim);
			ImGui::SameLine();
 			ImGuiCustom::hotkey(xorstr_("Key"), activate_bind11);

			ImGui::Checkbox(xorstr_("Show fov"), &anablefov);

					ImGui::SliderFloat(xorstr_("##Fosv"), &aimfov, 1, 80);
				ImGui::Checkbox(xorstr_("No Grass"), &twaeawe);
				ImGui::Checkbox(xorstr_("change time day"), &awaysday);
				if (awaysday)
					ImGui::SliderFloat(xorstr_("Hour"), &horas, 0.0005, 24.000);

		   ////
			ImGui::Checkbox(xorstr_("Inventory"), &inventoryesp);
		
			ImGui::Checkbox(xorstr_("GPS"), &Cordednada);
		
			if (Cordednada) {
				ImGui::SliderFloat(xorstr_("Pos X "), &posx, 1.0f, 1000);
				ImGui::SliderFloat(xorstr_("Pos Y"), &posy, 1.0f, 1000);
				ImGui::SliderFloat(xorstr_("Pos Z"), &posz, 1.0f, 1000);

				ImGui::SliderFloat(xorstr_("Pos1 X "), &posx1, 1.0f, 100.f);
				ImGui::SliderFloat(xorstr_("Pos1 Y"), &posy1, 1.0f, 100.f);
				ImGui::SliderFloat(xorstr_("Pos1 Z"), &posz1, 1.0f, 100.f);
		
			}
			ImGui::Checkbox(xorstr_("Inventory Boxs"), &inventoryespcaixa);
			ImGui::Checkbox(xorstr_("Cargo esp"), &Cargoesp);

			}
			if (MenuTab == 1)
			{
				ImGui::SetCursorPos(ImVec2(10, 1200));
				ImGui::Text(_("Player ESP:"));
				ImGui::SetCursorPos(ImVec2(10, 100));
				ImGui::BeginChild(_("##Players1"), ImVec2(240.f, 275), true);
				{
					ImGui::Checkbox(_(" Player"), &showplayer);
					if (showplayer)
						ImGui::SliderFloat(xorstr_("##MaxDistancep"), &maxplayer, 0, 1200);
					if (showplayer)
						ImGui::Checkbox(_("Player Skelets"), &Skelet1Player);
  
					if (showplayer) {

						ImGui::Checkbox(xorstr_("Player Name"), &esp_player_team);
 
					}
					ImGui::Checkbox(xorstr_("Zombie"), &showzombie);
					if (showzombie)
						ImGui::Checkbox(xorstr_("Zombie Skelets"), &Skelet1Zombie);
					if (showzombie)
						ImGui::SliderFloat(xorstr_("##MaxDistancez"), &maxzombie, 0, 1200);
					ImGui::Checkbox(xorstr_("Animal"), &showAnimal);
					if (showAnimal)
						ImGui::SliderFloat(xorstr_("##Animald"), &maxanimal, 0, 1200);
					ImGui::Checkbox(xorstr_("Vehicle"), &car);
					if (car)
						ImGui::SliderFloat(xorstr_("##Vehicled"), &maxcar, 0, 1200);

				}
				ImGui::EndChild();
				ImGui::SetCursorPos(ImVec2(260, 1200));
				ImGui::Text(_("Items:"));
				ImGui::SetCursorPos(ImVec2(260, 100));
				ImGui::BeginChild(_("##Players22"), ImVec2(-1, 290), true);
				{
					ImGui::PushItemWidth(170.f);
					ImGui::Checkbox(xorstr_("Show Items"), &Iemtelist);
					if(Iemtelist){
					ImGui::Checkbox(xorstr_("ESP Weapon"), &weapon);
					ImGui::Checkbox(xorstr_("ESP ProxyMagazines"), &ProxyMagazines);
					ImGui::Checkbox(xorstr_("ESP Scoop"), &Miras);
					ImGui::Checkbox(xorstr_("ESP Well"), &rodas);
					ImGui::Checkbox(xorstr_("ESP clothing"), &clothing);
					ImGui::Checkbox(xorstr_("ESP Others"), &inventoryItem);


					ImGui::Checkbox(xorstr_("ESP Food"), &comida);
					ImGui::Checkbox(xorstr_("ESP drinks"), &drinks);
					ImGui::Checkbox(xorstr_("ESP Medicine"), &medicine);
					ImGui::Checkbox(xorstr_("ESP Containers"), &Containers);
					ImGui::Checkbox(xorstr_("ESP BackPack"), &BackPack);
					ImGui::Checkbox(xorstr_("EPS All"), &inventoryItem12);

					ImGui::SliderFloat(xorstr_("##Msho2wzos2asmbie"), &maxloot, 0, 1200);

					}

					ImGui::PopItemWidth();

				}
				ImGui::EndChild();
			}
			if (MenuTab == 2)
			{
				ImGui::SetCursorPos(ImVec2(10, 1200));
				ImGui::SetCursorPos(ImVec2(10, 100));
				ImGui::BeginChild(_("##P2layewrs1"), ImVec2(240.f, 300), true);
				{
					ImGui::Checkbox(xorstr_("Show City"), &City_Esp);
					if (City_Esp) {
						ImGui::Checkbox(xorstr_("Berezino (Down)"), &City_Esp1);
						ImGui::Checkbox(xorstr_("Solnechniy"), &City_Esp2);
						ImGui::Checkbox(xorstr_("Kamyshovo"), &City_Esp3);
						ImGui::Checkbox(xorstr_("Electrozavodsk"), &City_Esp4);
						ImGui::Checkbox(xorstr_("Prigorodki"), &City_Esp5);
						ImGui::Checkbox(xorstr_("Chernogorsk"), &City_Esp6);
						ImGui::Checkbox(xorstr_("Svetloyarsk"), &City_Esp7);
						ImGui::Checkbox(xorstr_("Mogilevka"), &City_Esp8);
						ImGui::Checkbox(xorstr_("Guglovo"), &City_Esp9);
					}
				}
				ImGui::EndChild();
				ImGui::SetCursorPos(ImVec2(260, 1200));
				ImGui::SetCursorPos(ImVec2(260, 100));
				ImGui::BeginChild(_("##cwdsdw"), ImVec2(-1, 300), true);
				{
					ImGui::PushItemWidth(170.f);
					if (City_Esp) {
						ImGui::Checkbox(xorstr_("Kozlovka"), &City_Esp11);
						ImGui::Checkbox(xorstr_("Nadezhdino"), &City_Esp12);
						ImGui::Checkbox(xorstr_("Air-Field (Vybor)"), &City_Esp13);
						ImGui::Checkbox(xorstr_("Novodmitrovsk"), &City_Esp14);
						ImGui::Checkbox(xorstr_("Zelenogorsk"), &City_Esp15);
						ImGui::Checkbox(xorstr_("Krasnostav"), &City_Esp16);
						ImGui::Checkbox(xorstr_("Severograd"), &City_Esp17);
						ImGui::Checkbox(xorstr_("Stariy Sobor"), &City_Esp18);
						ImGui::Checkbox(xorstr_("Military base (Pavlovo)"), &City_Esp19);
						ImGui::Checkbox(xorstr_("Military base (Kabanino)"), &City_Esp20);
						ImGui::Checkbox(xorstr_("Kabanino"), &City_Esp10);
					}

					ImGui::PopItemWidth();

				}
				ImGui::EndChild();
			}


		}
		ImGui::End();
	}
	return true;
}

void BuildMenuMain()
{
	ImGui::GetIO().MouseDrawCursor = true;



	if (toggle_menu) {
		ImGui::SetNextWindowSize(ImVec2(450, 450));
		ImGui::Begin(xorstr_("DAYZ "), &toggle_menu/*, windowFlags*/);
		if (ImGui::BeginTabBar(xorstr_("TabBar"), ImGuiTabBarFlags_NoTooltip)) {


			if (ImGui::BeginTabItem(xorstr_("Wallhack"))) {

				ImGui::Checkbox(xorstr_("Active all"), &City_Esp0e1);





				ImGui::Checkbox(xorstr_("Quality"), &qualidade);
				ImGui::Checkbox(xorstr_("Player Skelet"), &Skelet1Player);
				ImGui::Checkbox(xorstr_("Player"), &showplayer);
				ImGui::SameLine();

				if (showplayer) {
					
						ImGui::Checkbox(xorstr_("Player Name"), &esp_player_team);
						ImGui::SliderFloat(xorstr_("##showp2layer"), &maxplayer, 0, 1200);

				}
				ImGui::Checkbox(xorstr_("##weaponss"), &showplayer1);
				if (showplayer1) {
					ImGui::SameLine();
					ImGuiCustom::hotkey(xorstr_("Key"), activate_bind2);

				}

				ImGui::Checkbox(xorstr_("zombie Skelet"), &Skelet1Zombie);
				ImGui::Checkbox(xorstr_("zombie"), &showzombie);
				ImGui::SameLine();

				if (showzombie)
					ImGui::SliderFloat(xorstr_("##Msh3owzombie"), &maxzombie, 0, 1200);
				ImGui::Checkbox(xorstr_("##swzombie"), &showzombie1);

				if (showzombie1) {
					ImGui::SameLine();
					ImGuiCustom::hotkey(xorstr_("Key"), activate_bind3);

				}



				ImGui::Checkbox(xorstr_("animal"), &showAnimal);
				if (showAnimal)
					ImGui::SliderFloat(xorstr_("##Mshowz3osmbie"), &maxanimal, 0, 1200);

				ImGui::Checkbox(xorstr_("car"), &car);
				if (car)
					ImGui::SliderFloat(xorstr_("##Msh2owz2osasmbie"), &maxcar, 0, 1200);
				ImGui::Checkbox(xorstr_("Show Items"), &Iemtelist);
				ImGui::SameLine();
				ImGui::Checkbox(xorstr_("##com1wisssdsa"), &Iemtelis2t);
				if (Iemtelis2t) {
					ImGui::SameLine();
					ImGuiCustom::hotkey(xorstr_("key al"), activate_bind9);
				}
				if (Iemtelist) {
					ImGui::Checkbox(xorstr_("ESP Weapon"), &weapon);
					ImGui::SameLine();
					ImGui::Checkbox(xorstr_("##weapons"), &weaponToggle);
					if (weaponToggle) {
						ImGui::SameLine();
						ImGuiCustom::hotkey(xorstr_("Key wp"), activate_bind);


					}




					ImGui::Checkbox(xorstr_("ESP ProxyMagazines"), &ProxyMagazines);
					ImGui::SameLine();
					ImGui::Checkbox(xorstr_("##ProxyMagaziness"), &ProxyMagazines1);
					if (ProxyMagazines1) {
						ImGui::SameLine();
						ImGuiCustom::hotkey(xorstr_("key mg"), activate_bind1);


					}
					ImGui::Checkbox(xorstr_("ESP Scoop"), &Miras);
					ImGui::Checkbox(xorstr_("ESP Well"), &rodas);
					ImGui::Checkbox(xorstr_("ESP clothing"), &clothing);
					ImGui::SameLine();
					ImGui::Checkbox(xorstr_("##com1isssdsa"), &clothing1);
					if (clothing1) {
						ImGui::SameLine();
						ImGuiCustom::hotkey(xorstr_("key fd"), activate_bind7);
					}
					ImGui::Checkbox(xorstr_("ESP Others"), &inventoryItem);
					ImGui::SameLine();

					ImGui::Checkbox(xorstr_("##wdsadaw2dwd"), &inventoryItemsss);
					if (inventoryItemsss) {
						ImGui::SameLine();
						ImGuiCustom::hotkey(xorstr_("key ot"), activate_bind4);



					}


					ImGui::Checkbox(xorstr_("ESP Food"), &comida);
					ImGui::SameLine();

					ImGui::Checkbox(xorstr_("##com1ida"), &comida1);

					if (comida1) {
						ImGui::SameLine();
						ImGuiCustom::hotkey(xorstr_("key cm"), activate_bind5);


					}


					ImGui::Checkbox(xorstr_("ESP drinks"), &drinks);
					ImGui::SameLine();
					ImGui::Checkbox(xorstr_("##com1isssssdsa"), &drinks1);
					if (drinks1) {
						ImGui::SameLine();
						ImGuiCustom::hotkey(xorstr_("key dr"), activate_bind8);



					}
					ImGui::Checkbox(xorstr_("ESP Medicine"), &medicine);
					ImGui::SameLine();
					ImGui::Checkbox(xorstr_("##com1isdsa"), &medicine1);
					if (medicine1) {
						ImGui::SameLine();
						ImGuiCustom::hotkey(xorstr_("key int"), activate_bind1);


					}
					ImGui::SliderFloat(xorstr_("##Msho2wzos2asmbie"), &maxloot, 0, 1200);

				}
				ImGui::Checkbox(xorstr_("  Remove Grass"), &twaeawe);
				ImGui::Checkbox(xorstr_("Restaure Grass"), &twaeawe1);
				ImGui::Checkbox(xorstr_("Aways day"), &awaysday);
				if (awaysday)
					ImGui::SliderFloat(xorstr_("Hour"), &horas, 0.0005, 24.000);

				ImGui::Checkbox(xorstr_("GPS"), &Cordednada);

				if (Cordednada) {
					ImGui::SliderFloat(xorstr_("Pos X "), &posx, 1.0f, 1200);
					ImGui::SliderFloat(xorstr_("Pos Y"), &posy, 1.0f, 1200);
					ImGui::SliderFloat(xorstr_("Pos Z"), &posz, 1.0f,1200);
				 
				}

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem(xorstr_("City"))) {

				ImGui::Checkbox(xorstr_("Show City"), &City_Esp);
				ImGui::Checkbox(xorstr_("Berezino (Down)"), &City_Esp1);
				ImGui::Checkbox(xorstr_("Solnechniy"), &City_Esp2);
				ImGui::Checkbox(xorstr_("Kamyshovo"), &City_Esp3);
				ImGui::Checkbox(xorstr_("Electrozavodsk"), &City_Esp4);
				ImGui::Checkbox(xorstr_("Prigorodki"), &City_Esp5);
				ImGui::Checkbox(xorstr_("Chernogorsk"), &City_Esp6);
				ImGui::Checkbox(xorstr_("Svetloyarsk"), &City_Esp7);
				ImGui::Checkbox(xorstr_("Mogilevka"), &City_Esp8);
				ImGui::Checkbox(xorstr_("Guglovo"), &City_Esp9);
				ImGui::Checkbox(xorstr_("Kabanino"), &City_Esp10);
				ImGui::Checkbox(xorstr_("Kozlovka"), &City_Esp11);
				ImGui::Checkbox(xorstr_("Nadezhdino"), &City_Esp12);
				ImGui::Checkbox(xorstr_("Air-Field (Vybor)"), &City_Esp13);
				ImGui::Checkbox(xorstr_("Novodmitrovsk"), &City_Esp14);
				ImGui::Checkbox(xorstr_("Zelenogorsk"), &City_Esp15);
				ImGui::Checkbox(xorstr_("Krasnostav"), &City_Esp16);
				ImGui::Checkbox(xorstr_("Severograd"), &City_Esp17);
				ImGui::Checkbox(xorstr_("Stariy Sobor"), &City_Esp18);
				ImGui::Checkbox(xorstr_("Military base (Pavlovo)"), &City_Esp19);
				ImGui::Checkbox(xorstr_("Military base (Kabanino)"), &City_Esp20);

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem(xorstr_("Silent Aim"))) {

				ImGui::Checkbox(xorstr_("SilentAim"), &SilentAim);
				ImGui::SliderFloat(xorstr_("##Fov"), &aimfov, 5, 500);
				ImGuiCustom::hotkey(xorstr_("Key Silent"), activate_bind11);


				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(xorstr_("Inventory Players"))) {
				 
				ImGui::Checkbox(xorstr_("Test Inv 1"), &inventoryItem22);
				ImGui::Checkbox(xorstr_("Test Inv 2"), &inventoryItem222);
				ImGui::Checkbox(xorstr_("Test Inv 3"), &inventoryItem2222);
				ImGui::SameLine();
				ImGui::Checkbox(xorstr_("##weaposds#wdns"), &inventoryItem22221);
				if (inventoryItem22221) {
					ImGui::SameLine();
					ImGuiCustom::hotkey(xorstr_("Key wsp"), activate_bind10);


				}
				ImGui::Checkbox(xorstr_("Inventory Esp"), &inventoryesp1);
				if (inventoryesp1) {
					ImGuiCustom::hotkey(xorstr_("key invt"), activate_bind12);


				}

				if (inventoryesp1) {
 
				//	ImGui::Checkbox(xorstr_("In Hand"), &inventoryesphand);

					ImGui::Checkbox(xorstr_("Inventory Equiped"), &inventoryespfull);

 				
				}
				 ImGui::Checkbox(xorstr_("Inventory Boxs"), &inventoryespcaixa);
				ImGui::Checkbox(xorstr_("Cargo esp"), &Cargoesp);

				//ImGui::Checkbox(xorstr_("Get Namess"), &inventoryItem2);
				//ImGui::Checkbox(xorstr_("Get Namess3"), &inventoryItem132);


				ImGui::EndTabItem();
			}


			ImGui::EndTabBar();
		}

		ImGui::EndChild();
		ImGui::End();
	}

}


long long CALLBACK hWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//if (toggle_menu)
	///SetWindowDisplayAffinity(hwnd, WDA_EXCLUDEFROMCAPTURE);

	if (ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam) && toggle_menu == true)
	{
		return 1l;
	}

	return CallWindowProc(oriWndProc, hwnd, uMsg, wParam, lParam);
}






#define RELATIVE_ADDR(addr, size) ((PBYTE)((UINT_PTR)(addr) + *(PINT)((UINT_PTR)(addr) + ((size) - sizeof(INT))) + (size)))

inline BOOLEAN MaskCompare(PVOID buffer, LPCSTR pattern, LPCSTR mask) {
	for (auto b = reinterpret_cast<PBYTE>(buffer); *mask; ++pattern, ++mask, ++b) {
		if (*mask == 'x' && *reinterpret_cast<LPCBYTE>(pattern) != *b) {
			return FALSE;
		}
	}

	return TRUE;
}
inline PBYTE FindPattern(PVOID base, DWORD size, LPCSTR pattern, LPCSTR mask) {
	size -= static_cast<DWORD>(strlen(mask));

	for (auto i = 0UL; i < size; ++i) {
		auto addr = reinterpret_cast<PBYTE>(base) + i;
		if (MaskCompare(addr, pattern, mask)) {
			return addr;
		}
	}

	return NULL;
}

inline PBYTE FindPattern(LPCSTR pattern, LPCSTR mask) {
	MODULEINFO info = { 0 };
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, sizeof(info));

	return FindPattern(info.lpBaseOfDll, info.SizeOfImage, pattern, mask);
}

inline PVOID* uWorld = 0;

inline BOOLEAN Initialize() {

	auto addr = FindPattern(xorstr_("\x48\x89\x05\x00\x00\x00\x00\x49\x8B\xBF\x00\x00\x00\x00"), xorstr_("xxx????xxx????"));
	if (!addr) {
		MessageBox(0, xorstr_("Please contact an administrator and give the error code:\n0x08"), xorstr_("Error"), 0);
		return FALSE;
	}

	uWorld = reinterpret_cast<decltype(uWorld)>(RELATIVE_ADDR(addr, 7));
	if (!uWorld)
		return false;



	return TRUE;


}
int cstrlen(const char* string)
{
	int cnt = 0;
	if (string)
	{
		for (; *string != 0; ++string) ++cnt;
	}
	return cnt;
};
static uintptr_t PatternScanEx(uintptr_t pModuleBaseAddress, const char* sSignature, size_t nSelectResultIndex = 0)
{
	static auto patternToByte = [](const char* pattern)
	{
		auto       bytes = std::vector<int>{};
		const auto start = const_cast<char*>(pattern);
		const auto end = const_cast<char*>(pattern) + cstrlen(pattern);

		for (auto current = start; current < end; ++current)
		{
			if (*current == '?')
			{
				++current;
				if (*current == '?')
					++current;
				bytes.push_back(-1);
			}
			else
				bytes.push_back(strtoul(current, &current, 16));
		}
		return bytes;
	};

	const auto dosHeader = (PIMAGE_DOS_HEADER)pModuleBaseAddress;
	const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)pModuleBaseAddress + dosHeader->e_lfanew);

	const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
	auto       patternBytes = patternToByte(sSignature);
	const auto scanBytes = reinterpret_cast<std::uint8_t*>(pModuleBaseAddress);

	const auto s = patternBytes.size();
	const auto d = patternBytes.data();

	size_t nFoundResults = 0;

	for (auto i = 0ul; i < sizeOfImage - s; ++i)
	{
		bool found = true;

		for (auto j = 0ul; j < s; ++j)
		{
			if (scanBytes[i + j] != d[j] && d[j] != -1)
			{
				found = false;
				break;
			}
		}

		if (found)
		{
			if (nSelectResultIndex != 0)
			{
				if (nFoundResults < nSelectResultIndex)
				{
					nFoundResults++;
					found = false;
				}
				else
					return reinterpret_cast<uintptr_t>(&scanBytes[i]);
			}
			else
				return reinterpret_cast<uintptr_t>(&scanBytes[i]);
		}
	}

	return NULL;
}

static uintptr_t PatternScan(const char* sSignature, size_t nSelectResultIndex = 0)
{
	static bool bIsSetted = false;

	static MODULEINFO info = { 0 };

	if (!bIsSetted)
	{
		GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, sizeof(info));
		bIsSetted = true;
	}
	return PatternScanEx((uintptr_t)info.lpBaseOfDll, sSignature, nSelectResultIndex);
}
#define RVA(addr, size) ((uintptr_t)((UINT_PTR)(addr) + *(PINT)((UINT_PTR)(addr) + ((size) - sizeof(INT))) + (size)))


bool Foiepasso = false;
bool Foiepasso1 = false;

std::vector<player_t> entities = {};
std::vector<item_t> items = {};
uintptr_t FindProcessID(const std::string& ProcessName);
void update_list();
HANDLE MyCreateThread(LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, LPDWORD lpThreadId);
DWORD ThreadID2;

void init()
{
	globals::process_id = FindProcessID(xorstr_("DayZ_x64.exe"));
	globals::handle = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION, FALSE, globals::process_id);

	globals::Base = GetModule(xorstr_("DayZ_x64.exe"));
	globals::World = ReadData<uint64_t>(globals::Base + OFF_WORLD);

}

class USQAnimInstanceSoldier1P1
{
public:
	void UENGINE RecoilCameraOffsetFactor(int zoom)
	{
		*(int*)(this) = zoom;

	}

};
class USQAnimInstanceSoldier1P
{
public:


	void UENGINE RecoilCameraOffsetFactor(float zoom)
	{
		*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0xB80) = zoom;
	}
	void UENGINE RecoilCameraOffsetFactor1(float zoom)
	{
		*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + 0x28E8) = zoom;
	}

};


Vector3 GetDirection(uintptr_t entity)
{
	if (entity)
	{
		uintptr_t renderVisualState = ReadData<uintptr_t>(entity + 0x1C0);

		if (renderVisualState)
		{
			Vector3 pos = ReadData<Vector3>(renderVisualState + 0x8);
			return pos;
		}
	}

	return Vector3(-1, -1, -1);
}

struct nameid
{
	UINT64 pt1;
	UINT64 pt2;
};
std::map<UINT64, std::string> nameCache;
std::string GetPlayerNameByID(uint32_t ID)
{

	uint64_t networkClient = ReadData<uint64_t>(globals::Base + 0xEE7A88 + 0x48);
	if (networkClient)
	{
		uint64_t pScoreboard = ReadData<uint64_t>(networkClient + 0x10);

		uint64_t lScoreboardSize = ReadData<uint64_t>(networkClient + 0x1c);

		if (pScoreboard)
		{
			for (int i = 0; i < lScoreboardSize; i++)
			{
				//uint64_t pCurrentIdentity = pScoreboard + (i * 0x8);
			//	auto pCurrentIdentity = *reinterpret_cast<uint64_t*>(pScoreboard + i * 0x8);


				auto pCurrentIdentity = ReadData<uint64_t>(pScoreboard + (i * 0x8));
				if (!pCurrentIdentity)
					continue;
				uint32_t lCurrentID = ReadData<uint32_t>(pCurrentIdentity + 0x30);
				if (lCurrentID == ID)
				{
					uint64_t pPlayerName = ReadData<uint64_t>(pCurrentIdentity + 0xF0);
					if (!pPlayerName)
						continue;
					//if (pPlayerName)
						return ReadArmaString(pPlayerName);
				}
			}
		}
	}
	return _("AI");
}

 
void inventory() {

	ImGuiIO& io = ImGui::GetIO();

	if (isnpc == 2)
		return;


	if (inventoryesp) {
		uint64_t ff = (uint64_t)get_closest_player(valid_players1, aimfov, 1);
		if (!ff)
			return;


		uint64_t Skeleton = ReadData<uint64_t>((uint64_t)ff + 0x810);
		if (!IsValidPtr((void*)Skeleton))
			return;

		Vector3 current;
		Vector3 currentworld;


		Game::GetBonePosition(Skeleton, Game::GeVisualState((uint64_t)ff), 18, &current);


		Game::WorldToScreen(current, currentworld);





	//	std::vector<std::string> item_names;
		//auto Get = Game::FetchHands(ff);

	//	if (inventoryesphand) {
		//	if (item_names.size() <= 1)
		//		rendering::Renderer::GetInstance()->DrawInventoryList1(item_names, Get, { (float)variables::game_screen_X+15, (float)variables::game_screen_Y }, { 0.f, 255.f, 0.f, 255.f }, 12);
	//		item_names.push_back(Get);
	//	}
		if (inventoryespfull) {
			auto Inventory = Game::GetInventory(ff);
			if (!Inventory)
				return;




			auto equiped = ReadData<uint64_t>(Inventory + 0x150);
			if (!equiped)
				return; 

			auto size = ReadData<uint32_t>(Inventory + 0x15c);
			if (!size)
				return;

			std::vector<std::string> item_names1;
			std::string  objectBase;
			//std::string text2;
			for (size_t i = 0; i < size; i++)
			{
				//	auto item = ReadData<uint64_t>(equiped + (uint64_t)(i * 0x10) + 0x08);
				auto item = ReadData<uintptr_t>(equiped + i * 0x10 + 0x8);
				if (!item)
					continue;

				objectBase = Game::GetEntityTypeName(item);
				if (objectBase.empty())
					continue;

				item_names1.push_back(objectBase);
				uintptr_t objectBase1 = ReadData<uintptr_t>(item + 0x168);

				uintptr_t cleanNamePtr2 = ReadData<uintptr_t>(objectBase1 + 0Xa8);

				if (!IsValidPtr((void*)cleanNamePtr2))
					return;

				//text2 = getNameFromId(cleanNamePtr2);

			}

			if (item_names1.empty())
				return;

			if (objectBase.empty()) 
				return;
			
		 

		

			rendering::Renderer::GetInstance()->DrawInventoryList(item_names1, _("  "), {(float)variables::game_screen_X, (float)variables::game_screen_Y}, {0.f, 255.f, 0.f, 255.f}, 12);

		}

	}

	return;
}
void caixas() {



	if (inventoryespcaixa) {
		ImGuiIO& io = ImGui::GetIO();
		auto* window = ImGui::GetOverlayDrawList();

		uint64_t ff = (uint64_t)get_closest_Item1(valid_players2, aimfov);
		if (!ff)
			return;

		Vector3 currentworld;

		Vector3 Pos = Game::GetObjectVisualState(ff);

		Game::WorldToScreen(Pos, currentworld);


		std::vector<std::string> item_names;





		uint64_t inventory = ReadData<uint64_t>(ff + 0x658);// std::printf("Inventory %llx \n", inventory);
		if (!inventory)
			return;
		uint64_t equippedItems = ReadData<uint64_t>(inventory + 0x150);// std::printf("equippedItems %llx \n", equippedItems);
		if (!equippedItems)
			return;

		int equippedItemsCount = ReadData<int>(inventory + 0x15C);// std::printf("equippedItemsCount %i \n", equippedItemsCount);
		std::vector<std::string> item_names1;
		//std::string  objectBase;
		std::string  objectBase2;
		for (int k = 0; k < equippedItemsCount; k++)

		{
			uint64_t item = ReadData<uint64_t>(equippedItems + (uint64_t)(k * 0x10) + 0x8); //std::printf("item %llx \n", item);
			if (!item)
				continue;
		//	objectBase = Game::GetEntityTypeName(item);
			//if (objectBase.empty())
			//	continue;
			objectBase2 = Game::GetEntityTypeName2(item);
			//item_names1.push_back(objectBase);

		}
		//if (objectBase.empty())
		//	return;

		if (item_names1.empty())
			return;

	//	window->AddText(ImVec2{ currentworld.x, currentworld.y }, ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255)), objectBase2.c_str());

		window->AddLine(ImVec2{ (float)variables::game_screen_X / 2, (float)variables::game_screen_Y }, ImVec2{ currentworld.x, currentworld.y }, ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255)), 1.5f);

		rendering::Renderer::GetInstance()->DrawInventoryList(item_names1, objectBase2, { (float)variables::game_screen_X, (float)variables::game_screen_Y }, { 0.f, 255.f, 0.f, 255.f }, 12);


		/*	auto equiped = ReadData<uint64_t>(Inventory + Adds); std::printf("equiped %llx \n", equiped);
			if (!equiped)
				return;


			auto size = ReadData<uint32_t>(Inventory + addssize); std::printf("size %llx \n", size);
			if (!size)
				return;

			for (size_t i = 0; i < size; i++)
			{
				auto item = ReadData<uintptr_t>(equiped + ((i * 0x10) + 0x8)); std::printf("item %llx \n", item);
				if (!item)
					continue;

				auto objectBase = Game::GetEntityTypeName(item);
				std::printf("objectBase %s \n", objectBase.c_str());

				item_names1.push_back(objectBase);

			}*/




	}

}
void GetCargo() {




	if (Cargoesp) {
		ImGuiIO& io = ImGui::GetIO();
		auto* window = ImGui::GetOverlayDrawList();
		uint64_t ff = (uint64_t)get_closest_Item2(valid_players2, aimfov);
		if (!ff)
			return;

		Vector3 currentworld;

		Vector3 Pos = Game::GetObjectVisualState(ff);

		Game::WorldToScreen(Pos, currentworld);




		std::vector<std::string> item_names;

		uint64_t IGrid = ReadData<uint64_t>(ff + 0x658); //std::printf("IGrid %llx \n", IGrid);
		if (!IGrid)
			return;

		uint64_t inventoryGrid = ReadData<uint64_t>(IGrid + 0x148); //std::printf("inventoryGrid %llx \n", inventoryGrid);
		if (!inventoryGrid)
			return;

		int size = ReadData<int>(inventoryGrid + 0x44); //std::printf("size %i \n", size);
		std::vector<std::string> item_names1;
		std::string  objectBase;
		std::string  objectBase2;
		for (int k = 0; k < size; k++)
		{
			uint64_t tmp = ReadData<uint64_t>(inventoryGrid + 0x38); //std::printf("tmp %llx \n", tmp);
			if (!tmp)
				continue;

			uint64_t item = ReadData<uint64_t>(tmp + k * 0x10 + 0x8); //std::printf("item %llx \n", item);
			if (!item)
				continue;
			objectBase = Game::GetEntityTypeName(item);
			objectBase2 = Game::GetEntityTypeName2(item);
			if (objectBase.empty())
				continue;

			item_names1.push_back(objectBase);

		}

		if (objectBase.empty())
			return;

		if (item_names1.empty())
			return;

		window->AddLine(ImVec2{ (float)variables::game_screen_X / 2, (float)variables::game_screen_Y }, ImVec2{ currentworld.x, currentworld.y }, ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255)), 1.5f);
	//	window->AddText(ImVec2{ currentworld.x, currentworld.y - 15 }, ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255)), objectBase2.c_str());
		rendering::Renderer::GetInstance()->DrawInventoryList(item_names1, objectBase2, { (float)variables::game_screen_X, (float)variables::game_screen_Y }, { 0.f, 255.f, 0.f, 255.f }, 12);


		/*	auto equiped = ReadData<uint64_t>(Inventory + Adds); std::printf("equiped %llx \n", equiped);
			if (!equiped)
				return;


			auto size = ReadData<uint32_t>(Inventory + addssize); std::printf("size %llx \n", size);
			if (!size)
				return;

			for (size_t i = 0; i < size; i++)
			{
				auto item = ReadData<uintptr_t>(equiped + ((i * 0x10) + 0x8)); std::printf("item %llx \n", item);
				if (!item)
					continue;

				auto objectBase = Game::GetEntityTypeName(item);
				std::printf("objectBase %s \n", objectBase.c_str());

				item_names1.push_back(objectBase);

			}*/




	}

}

std::string getNameFromId(uintptr_t namePointer)
{
	nameid ID = ReadData<nameid>(namePointer + 0x10);

	std::map<UINT64, std::string>::iterator it = nameCache.find(ID.pt1 + ID.pt2);

	if (it == nameCache.end())
	{

		int size = ReadData<int>(namePointer + 0x8);
		if (size < 1)
			return "";
		char* name = new char[size];
		ZwCopyMemory(namePointer + 0x10, name, size, false);

		if (strstr(name, xorstr_("Animal")) != NULL || strstr(name, xorstr_("Zmb")) != NULL || strstr(name, xorstr_("Firewood")) != NULL || strstr(name, xorstr_("Barrel")) || strstr(name, xorstr_("Watchtower")) || strstr(name, xorstr_("Wood Pillar")) || strstr(name, xorstr_("Roof")) || strstr(name, xorstr_("Wall")) != NULL || strstr(name, xorstr_("Floor")) || strstr(name, xorstr_("Fireplace")) != NULL || strstr(name, xorstr_("Wire Mesh Barrier")) != NULL || strstr(name, xorstr_("Fence")) != NULL)
		{
			std::string text = "";
			nameCache.insert(std::pair<UINT64, std::string>(ID.pt1 + ID.pt2, text));
			delete name;
			return text;
		}

		std::string text = std::string(name);
		delete name;
		nameCache.insert(std::pair<UINT64, std::string>(ID.pt1 + ID.pt2, text));
		return text;
	}
	else
	{
		return it->second;
	}
}
bool bulletsToHead;
std::mutex bulletToHeadMutex;

void DrawSkeleton(uintptr_t Entity, ImVec4 color, int merda);


std::string get_quality(uint64_t Entity)
{
	auto quality = ReadData<int>(Entity + 0x180);

	if (quality == 1) return xorstr_("Worn");
	else if (quality == 2) return xorstr_("Damaged");
	else if (quality == 3) return xorstr_("Badly Damaged");
	else if (quality == 4) return xorstr_("Ruined");

	else return xorstr_("Pristine");
}

ImU32 ColoroU32(uint64_t Entity)
{



	auto quality = ReadData<int>(Entity + 0x180);
	//if (!quality) {
	//	ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255));
	//	return colorweapon;
	//}

	if (quality == 1) {

		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(196, 201, 34, 255));
		return colorweapon;

	}
	if (quality == 2) {

		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(247, 95, 0, 255));
		return colorweapon;
	}
	if (quality == 3) {
		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(252, 185, 0, 255));
		return colorweapon;
	}
	if (quality == 4) {
		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(255, 0, 0, 255));
		return colorweapon;
	}
	else {
		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255));
		return colorweapon;

	}
	return	ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255));
}



void IterateItems(uintptr_t worldptr)
{
	auto* window = ImGui::GetOverlayDrawList();
	auto color = ImGui::ColorConvertFloat4ToU32(ImVec4(255, 0, 255, 255));


 
	
	int objectTableSz = ReadData<int>(worldptr + off_world_itemtable + 0x8);


	std::stringstream all;
	uintptr_t entityTable = ReadData<uintptr_t>(worldptr + off_world_itemtable);

	if (!IsValidPtr((void*)entityTable))
		return;

	for (size_t i = 0; i < objectTableSz; i++)
	{

		if (!IsValidPtr((void*)entityTable))
			continue;



		uintptr_t entity = ReadData<uintptr_t>(entityTable + i * 0x18 + 0x8);
		if (!IsValidPtr((void*)entity))
			continue;
		const auto flag = ReadData<uint32_t>(entityTable + i * 0x18);
		if (flag != 1)
			continue;
	

		if (entity)
		{

		//	bool isdead = ReadData<bool>(entity + 0x15D);
		//	if (isdead == true)
			//	continue;

			Vector3 worldPosition = Game::GetCoordinate(entity);

			Vector3 outPos;

			Vector3 Pos = Game::GetObjectVisualState(entity);

			Game::WorldToScreen(Pos, outPos);

			 
			if (outPos.z < 1.0f)
				continue;

			
				
			
 

					int dist = Game::GetDistanceToMe(worldPosition);

					if (dist <= maxloot && dist > 0)
					{
						uintptr_t objectBase = ReadData<uintptr_t>(entity + 0x168);

						if (!IsValidPtr((void*)objectBase))
							continue;
						uintptr_t cleanNamePtr = ReadData<uintptr_t>(objectBase + 0x4E8);

						if (!IsValidPtr((void*)cleanNamePtr))
							continue;

						uintptr_t cleanNamePtr5 = ReadData<uintptr_t>(objectBase + 0x88);

						if (!IsValidPtr((void*)cleanNamePtr5))
							continue;

						uintptr_t cleanNamePtr2 = ReadData<uintptr_t>(objectBase + 0Xa8);

						if (!IsValidPtr((void*)cleanNamePtr2))
							continue;


						std::string text = getNameFromId(cleanNamePtr);  
						std::string text2 = getNameFromId(cleanNamePtr2);
						 
						std::string text3 = getNameFromId(cleanNamePtr5);
						 


						std::stringstream all;
						all << text;
						all << " " << dist;
						auto get = (xorstr_("[ ") + std::to_string(dist) + xorstr_(" ]"));
						auto get1 = text;
						auto get2 = get1 + get;
						auto color2 = ImGui::ColorConvertFloat4ToU32(ImVec4(INSVeh2[0], INSVeh2[1], INSVeh2[2], INSVeh2[3]));
						auto colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(255, 0, 0, 255));
						auto corcomida = ImGui::ColorConvertFloat4ToU32(ImVec4(153, 0, 153, 255));
						auto colorcloting = ImGui::ColorConvertFloat4ToU32(ImVec4(232, 41, 145, 180));
						auto colorinventor = ImGui::ColorConvertFloat4ToU32(ImVec4(110, 141, 145, 200));
						auto coloriMagazines = ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 255, 200));
						auto corrodas = ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 255, 200));
						auto coloriMagazines2 = ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255));
						auto colorcomida = ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 0, 255));

						if (text2.empty())
							continue;
						if (text3.empty())
							continue;

						if (weapon) {
							//if (text2 == xorstr_("Weapon")) {

								if (std::string(text2).find(xorstr_("Weapon")) != std::string::npos) {
								window->AddText(ImVec2(outPos.x, outPos.y), colorweapon, get2.c_str());

								if (qualidade)
									window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());

							}

						}
						if (BackPack) {
							//if (text2 == xorstr_("Weapon")) {
						
								if (std::string(text3).find(xorstr_("backpacks")) != std::string::npos) {
								window->AddText(ImVec2(outPos.x, outPos.y), colorweapon, get2.c_str());
						
							 
							}
						
						}
						if (Containers) {
							if (std::string(text3).find(xorstr_("containers")) != std::string::npos) {
 						
								window->AddText(ImVec2(outPos.x, outPos.y), corcomida, get2.c_str());
						
							 
							}
							if (std::string(text3).find(xorstr_("cooking")) != std::string::npos) {
 						
								window->AddText(ImVec2(outPos.x, outPos.y), corcomida, get2.c_str());
						
							 
							}
						}
						if (comida) {
							if (std::string(text3).find(xorstr_("food")) != std::string::npos) {
							//if (text3 == xorstr_("food")) {

								window->AddText(ImVec2(outPos.x, outPos.y), corcomida, get2.c_str());

								if (qualidade)
									window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());

							}
						}
						if (medicine) {
							if (std::string(text3).find(xorstr_("medical")) != std::string::npos) {
							//if (text3 == xorstr_("medical")) {

								window->AddText(ImVec2(outPos.x, outPos.y), corcomida, get2.c_str());
								if (qualidade)
									window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
							}
						}

						if (drinks) {
							if (std::string(text3).find(xorstr_("drinks")) != std::string::npos) {
						//	if (text3 == xorstr_("drinks")) {

								window->AddText(ImVec2(outPos.x, outPos.y), corcomida, get2.c_str());
								if (qualidade)
									window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
							}
						}
						if (clothing) {
								if (std::string(text2).find(xorstr_("clothing")) != std::string::npos) {
							//if (text2 == xorstr_("clothing")) {

								window->AddText(ImVec2(outPos.x, outPos.y), colorcloting, get2.c_str());
								if (qualidade)
									window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
							}
						}
						if (inventoryItem) {
							if (std::string(text).find(xorstr_("Cerca")) != std::string::npos)
							//if (text2 == xorstr_("Cerca"))
								continue;
							if (std::string(text3).find(xorstr_("food")) != std::string::npos)
							//if (text3 == xorstr_("food"))
								continue;
							if (std::string(text3).find(xorstr_("medical")) != std::string::npos)
						//	if (text3 == xorstr_("medical"))
								continue;
							if (std::string(text3).find(xorstr_("drinks")) != std::string::npos)
 								continue;
							if (std::string(text3).find(xorstr_("Fogueira")) != std::string::npos)
								continue;
							//if (text2 == xorstr_("inventoryItem")) {

								if (std::string(text2).find(xorstr_("inventoryItem")) != std::string::npos) {



								window->AddText(ImVec2(outPos.x, outPos.y), colorinventor, get2.c_str());
								if (qualidade)
									window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
							}
						





						}
						if (ProxyMagazines) {
							//if (text2 == xorstr_("ProxyMagazines")) {

								if (std::string(text2).find(xorstr_("ProxyMagazines")) != std::string::npos) {
								window->AddText(ImVec2(outPos.x, outPos.y), coloriMagazines, get2.c_str());
 							}
								if (std::string(text3).find(xorstr_("ammunition")) != std::string::npos) {
								window->AddText(ImVec2(outPos.x, outPos.y), coloriMagazines, get2.c_str());
 							}
						}
						if (Miras) {
								if (std::string(text2).find(xorstr_("itemoptics")) != std::string::npos) {
							//if (text2 == xorstr_("itemoptics")) {

								window->AddText(ImVec2(outPos.x, outPos.y), coloriMagazines, get2.c_str());
								if (qualidade)
									window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
							}
						}
						if (rodas) {
							if (std::string(text2).find(xorstr_("carwheel")) != std::string::npos) {
						//	if (text2 == xorstr_("carwheel")) {
//
								window->AddText(ImVec2(outPos.x, outPos.y), corrodas, get2.c_str());
								if (qualidade)
									window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
							}
						}
					if (inventoryItem2) {

						window->AddText(ImVec2(outPos.x, outPos.y), coloriMagazines, get2.c_str());
						window->AddText(ImVec2(outPos.x, outPos.y - 15), coloriMagazines, text.c_str());
						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
					}
					if (inventoryItem12) {

						window->AddText(ImVec2(outPos.x, outPos.y), coloriMagazines, get2.c_str());
					//	window->AddText(ImVec2(outPos.x, outPos.y - 15), coloriMagazines, text2.c_str());
					//	if (qualidade)
						//	window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity ).c_str());
					}
					if (inventoryItem132) {

						window->AddText(ImVec2(outPos.x, outPos.y), coloriMagazines, get2.c_str());
						window->AddText(ImVec2(outPos.x, outPos.y - 15), coloriMagazines, text3.c_str());
						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
					}


					valid_players2.push_back((uintptr_t*)entity);



					
				
			
		}}
	}
	return;
 	 
}
uint32_t GetNetworkId(uint64_t Entity);

float get_health(uint64_t Entity) {
	uintptr_t the_class = *reinterpret_cast<uintptr_t*>(Entity + 0x150);
	if (!the_class)
		return 100.0f;

	return *reinterpret_cast<float*>(the_class + 0x10);
}
template <class T>
void filled_box(T x1, T y1, T x2, T y2, ImColor color, float thickness = 1.f, float rounding = 0.f, bool outline = false) {

	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImColor(color), rounding);
}


uint64_t  GetEntity(uint64_t PlayerList, uint64_t SelectedPlayer) {
	return  ReadData<uint64_t>(PlayerList + SelectedPlayer * 0x8);
}

void IterateAll(uintptr_t worldptr, uintptr_t offset)
{
	auto* window = ImGui::GetOverlayDrawList();

	auto color = ImGui::ColorConvertFloat4ToU32(ImVec4(RUSVeh11[0], RUSVeh11[1], RUSVeh11[2], RUSVeh11[3]));
	auto color1 = ImGui::ColorConvertFloat4ToU32(ImVec4(BRTVeh[0], BRTVeh[1], BRTVeh[2], BRTVeh[3]));
	auto color2 = ImGui::ColorConvertFloat4ToU32(ImVec4(RUSVeh[0], RUSVeh[1], RUSVeh[2], RUSVeh[3]));
	auto color3 = ImGui::ColorConvertFloat4ToU32(ImVec4(FOVRADIO[0], FOVRADIO[1], FOVRADIO[2], FOVRADIO[3]));
	auto color4 = ImGui::ColorConvertFloat4ToU32(ImVec4(HAB[0], HAB[1], HAB[2], HAB[3]));

	int objectTableSz = ReadData<int>(worldptr + offset + 0x8);

	if (objectTableSz < 1)
		return;

	std::stringstream all;
	uintptr_t entityTable = ReadData<uintptr_t>(worldptr + offset);
	if (!IsValidPtr((void*)entityTable))
		return;
	Vector3 outPos;


	for (size_t i = 0; i < objectTableSz; i++)
	{
		if (!entityTable)
			continue;
		uint64_t entity = ReadData<uint64_t>(entityTable + i * 0x8);

		if (!IsValidPtr((void*)entity))
			continue;
 
		if (entity)
		{
		

			Vector3 worldPosition = Game::GetCoordinate(entity);



			Vector3 Pos = Game::GetObjectVisualState(entity);


			int distance = Game::GetDistanceToMe(worldPosition);

			Game::WorldToScreen(Pos, outPos);


			int dist = Game::GetDistanceToMe(worldPosition);


			
			
			uintptr_t objectBase = ReadData<uintptr_t>(entity + 0x168);

			if (!IsValidPtr((void*)objectBase))
				continue;

			uintptr_t cleanNamePtr = ReadData<uintptr_t>(objectBase + 0x4E8);

			if (!IsValidPtr((void*)cleanNamePtr))
				continue;



			std::string text = getNameFromId(cleanNamePtr);
			if (text.empty()) continue;

			std::stringstream all;
			all << text;
			all << " " << dist;
			auto get = (xorstr_("[ ") + std::to_string(dist) + xorstr_("]"));
			auto get1 = text;
			auto get2 = get1 + get;
			auto color2 = ImGui::ColorConvertFloat4ToU32(ImVec4(INSVeh2[0], INSVeh2[1], INSVeh2[2], INSVeh2[3]));


			if (showzombie) {
				if (Game::GetEntityTypeName2(entity) == xorstr_("dayzinfected")) {


					if (distance > maxzombie)
						continue;

					isnpc = 2;
					valid_players.push_back((uintptr_t*)entity);

					if (Skelet1Zombie)
						DrawSkeleton(entity, { 255,0,0,255 }, 2);

					window->AddText(ImVec2(outPos.x, outPos.y), color2, (std::to_string(distance)).c_str());

				}
			}
			if (showplayer) {

				if (Game::GetEntityTypeName2(entity) == xorstr_("dayzplayer")) {
					if (distance > maxplayer)
						continue;

					if (distance < 2)
						continue;

					auto entityt = GetNetworkId(entity);


					//if(esp_player_team)
				//	window->AddText(ImVec2(outPos.x, outPos.y), color1, ("" + GetPlayerNameByID(entityt) + " [ " + std::to_string(distance) + "  ]").c_str());
				///	else
					window->AddText(ImVec2(outPos.x, outPos.y), color1, ("Player " +  std::to_string(distance) + "  ").c_str());

				//	window->AddText(ImVec2(outPos.x, outPos.y+15), color, ("" + GetPlayerNameByID(entity) + "[  " + std::to_string(distance) + "  ]").c_str());


					isnpc = 1;
					valid_players.push_back((uintptr_t*)entity);
					valid_players1.push_back((uintptr_t*)entity);
					//valid_players2.push_back((uintptr_t*)entity);


					if (Skelet1Player)
						DrawSkeleton(entity, { 255,0,0,255 }, 1);




				}
			}

			if (showAnimal) {

				if (Game::GetEntityTypeName2(entity) == xorstr_("dayzanimal")) {

					if (distance > maxanimal)
						continue;


					valid_players.push_back((uintptr_t*)entity);

					window->AddText(ImVec2(outPos.x, outPos.y), color3, get2.c_str());
				}

			}
			if (car) {
				if (Game::GetEntityTypeName2(entity) == xorstr_("car")) {



					if (distance > maxzombie)
						continue;

					window->AddText(ImVec2(outPos.x, outPos.y), color3, get2.c_str());

					window->AddText(ImVec2(outPos.x, outPos.y), color4, get2.c_str());
				}
			}




		}
	}
}

#define off_networkmanager_networkclient 0x50
#define off_networkclient_scoreboard 0x10
#define off_networkclient_playeridentity_size 0x168
#define off_networkclient_servername 0x330
#define off_sortedobject_entity 0x8

uint32_t GetNetworkId(uint64_t Entity)
{
	return ReadData<uint32_t>(Entity + 0x6DC);
}


void DrawSkeleton(uintptr_t Entity, ImVec4 color, int s2)
{


	int vBone[][4] =
	{
		{ num1 ,num2 },{ num3 , num4 },{num5 , num6 },{num7 , num8}, /*п авая нога*/
		{ num9 , num10 },{ num11 ,num12 },{ num13 , num14 },{num15 , num16 }
	};


	auto* window = ImGui::GetOverlayDrawList();

	for (auto part : vBone)
	{
		Vector3 previous = Vector3(0, 0, 0);
		for (int i = 0; i < 4; i++)
		{
			if (!part[i]) break;

			Vector3 current;//= ValSDK::valorant::GetBoneWithRotation(Mesh, part[i]);
			int s3 = s2;
			Game::GetBonePosition(Game::GetSkeleton(Entity, s3), Game::GeVisualState(Entity), part[i], &current);
			if (previous.x == 0.f)
			{
				previous = current;
				continue;
			}
			Vector3 p1, c1 = Vector3(0, 0, 0);

			Game::WorldToScreen(previous, p1);
			Game::WorldToScreen(current, c1);

			window->AddLine({ p1.x, p1.y }, { c1.x, c1.y }, ImGui::GetColorU32(color), 1.5f);

			previous = current;
		}
	}
}




bool test32 = false;
float SnapColor[] = { 0, 140, 255, 255.f };
bool tt2;
void __stdcall main_cheat_handler()
{
	auto* window = ImGui::GetOverlayDrawList();
	ImGuiIO& io = ImGui::GetIO();
	 
	//1919663074
		//aimfov

	if(anablefov)
	window->AddCircle({ io.DisplaySize.x / 2, io.DisplaySize.y / 2 }, aimfov, ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), 50);

	const auto pUWorld = *reinterpret_cast<USQAnimInstanceSoldier1P**>(globals::Base + OFF_WORLD);
	if (!IsValidPtr((void*)pUWorld))
		return;

	if (City_Esp)
	{
		Vector3 berezino_down_world_position = { 12972, 6, 10058 };
		Vector3 berezino_screen_position;

		Vector3 solnechniy_world_position = { 13453, 7, 6239 };
		Vector3 solnechniy_screen_position;

		Vector3 kamyshovo_world_position = { 12010, 7, 3486 };
		Vector3 kamyshovo_screen_position;

		Vector3 electrozavodsk_world_position = { 10430, 7, 2277 };
		Vector3 electrozavodsk_screen_position;

		Vector3 prigorodki_world_position = { 7762, 5, 3171 };
		Vector3 prigorodki_screen_position;

		Vector3 chernogorsk_world_position = { 6400, 10, 2679 };
		Vector3 chernogorsk_screen_position;

		Vector3 svetloyarsk_world_position = { 13929, 20, 13234 };
		Vector3 svetloyarsk_screen_position;

		Vector3 mogilevka_world_position = { 7500, 220, 5238 };
		Vector3 mogilevka_screen_position;

		Vector3 guglovo_world_position = { 8412, 360, 6688 };
		Vector3 guglovo_screen_position;

		Vector3 kabanino_world_position = { 5297, 336, 8564 };
		Vector3 kabanino_screen_position;

		Vector3 kozlovka_world_position = { 4452, 230, 4578 };
		Vector3 kozlovka_screen_position;

		Vector3 nadezhdino_world_position = { 5865, 133, 4827 };
		Vector3 nadezhdino_screen_position;

		Vector3 airfield_vybor_world_position = { 4617, 340, 10438 };
		Vector3 airfield_vybor_screen_position;

		Vector3 novodmitrovsk_world_position = { 11619, 43, 14392 };
		Vector3 novodmitrovsk_screen_position;

		Vector3 zelenogorsk_world_position = { 2739, 200, 5223 };
		Vector3 zelenogorsk_screen_position;

		Vector3 krasnostav_world_position = { 11252, 194, 12231 };
		Vector3 krasnostav_screen_position;

		Vector3 severograd_world_position = { 7951, 115, 13688 };
		Vector3 severograd_screen_position;

		Vector3 stariy_sobor_world_position = { 6075, 300, 7757 };
		Vector3 stariy_sobor_screen_position;

		Vector3 military_base_pavlovo_world_position = { 2144, 91, 3369 };
		Vector3 military_base_pavlovo_screen_position;

		Vector3 military_base_kabanino_world_position = { 4570, 318, 8266 };
		Vector3 military_base_kabanino_screen_position;

		Game::WorldToScreen(berezino_down_world_position, berezino_screen_position);
		Game::WorldToScreen(solnechniy_world_position, solnechniy_screen_position);
		Game::WorldToScreen(kamyshovo_world_position, kamyshovo_screen_position);
		Game::WorldToScreen(electrozavodsk_world_position, electrozavodsk_screen_position);
		Game::WorldToScreen(prigorodki_world_position, prigorodki_screen_position);
		Game::WorldToScreen(chernogorsk_world_position, chernogorsk_screen_position);
		Game::WorldToScreen(svetloyarsk_world_position, svetloyarsk_screen_position);
		Game::WorldToScreen(mogilevka_world_position, mogilevka_screen_position);
		Game::WorldToScreen(guglovo_world_position, guglovo_screen_position);
		Game::WorldToScreen(kabanino_world_position, kabanino_screen_position);
		Game::WorldToScreen(kozlovka_world_position, kozlovka_screen_position);
		Game::WorldToScreen(nadezhdino_world_position, nadezhdino_screen_position);
		Game::WorldToScreen(airfield_vybor_world_position, airfield_vybor_screen_position);
		Game::WorldToScreen(novodmitrovsk_world_position, novodmitrovsk_screen_position);
		Game::WorldToScreen(zelenogorsk_world_position, zelenogorsk_screen_position);
		Game::WorldToScreen(krasnostav_world_position, krasnostav_screen_position);
		Game::WorldToScreen(severograd_world_position, severograd_screen_position);
		Game::WorldToScreen(stariy_sobor_world_position, stariy_sobor_screen_position);
		Game::WorldToScreen(military_base_pavlovo_world_position, military_base_pavlovo_screen_position);
		Game::WorldToScreen(military_base_kabanino_world_position, military_base_kabanino_screen_position);

		int distance_berezino = Game::GetDistanceToMe(berezino_down_world_position);
		int distance_solnechniy = Game::GetDistanceToMe(solnechniy_world_position);
		int distance_kamyshovo = Game::GetDistanceToMe(kamyshovo_world_position);
		int distance_electrozavodsk = Game::GetDistanceToMe(electrozavodsk_world_position);
		int distance_prigorodki = Game::GetDistanceToMe(prigorodki_world_position);
		int distance_chernogorsk = Game::GetDistanceToMe(chernogorsk_world_position);
		int distance_svetloyarsk = Game::GetDistanceToMe(svetloyarsk_world_position);
		int distance_mogilevka = Game::GetDistanceToMe(mogilevka_world_position);
		int distance_guglovo = Game::GetDistanceToMe(guglovo_world_position);
		int distance_kabanino = Game::GetDistanceToMe(kabanino_world_position);
		int distance_kozlovka = Game::GetDistanceToMe(kozlovka_world_position);
		int distance_nadezhdino = Game::GetDistanceToMe(nadezhdino_world_position);
		int distance_airfield_vybor = Game::GetDistanceToMe(airfield_vybor_world_position);
		int distance_novodmitrovsk = Game::GetDistanceToMe(novodmitrovsk_world_position);
		int distance_zelenogorsk = Game::GetDistanceToMe(zelenogorsk_world_position);
		int distance_krasnostav = Game::GetDistanceToMe(krasnostav_world_position);
		int distance_severograd = Game::GetDistanceToMe(severograd_world_position);
		int distance_stariy_sobor = Game::GetDistanceToMe(stariy_sobor_world_position);
		int distance_military_base_pavlovo = Game::GetDistanceToMe(military_base_pavlovo_world_position);
		int distance_military_base_kabanino = Game::GetDistanceToMe(military_base_kabanino_world_position);


		if (City_Esp1)
			window->AddText(ImVec2(berezino_screen_position.x, berezino_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Berezino (Down)   ") + std::to_string((int)distance_berezino)).c_str());
		if (City_Esp2)
			window->AddText(ImVec2(solnechniy_screen_position.x, solnechniy_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Solnechniy    ") + std::to_string((int)distance_solnechniy)).c_str());
		if (City_Esp3)
			window->AddText(ImVec2(kamyshovo_screen_position.x, kamyshovo_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Kamyshovo   ") + std::to_string((int)distance_kamyshovo)).c_str());
		if (City_Esp4)
			window->AddText(ImVec2(electrozavodsk_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Electrozavodsk    ") + std::to_string((int)distance_electrozavodsk)).c_str());
		if (City_Esp5)
			window->AddText(ImVec2(electrozavodsk_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Prigorodki   ") + std::to_string((int)distance_prigorodki)).c_str());
		if (City_Esp6)
			window->AddText(ImVec2(chernogorsk_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Chernogorsk  ") + std::to_string((int)distance_chernogorsk)).c_str());
		if (City_Esp7)
			window->AddText(ImVec2(svetloyarsk_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Svetloyarsk  ") + std::to_string((int)distance_svetloyarsk)).c_str());
		if (City_Esp8)
			window->AddText(ImVec2(mogilevka_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Mogilevka  ") + std::to_string((int)distance_mogilevka)).c_str());
		if (City_Esp9)
			window->AddText(ImVec2(guglovo_screen_position.x, guglovo_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Guglovo  ") + std::to_string((int)distance_guglovo)).c_str());
		if (City_Esp10)
			window->AddText(ImVec2(kabanino_screen_position.x, kabanino_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Kabanino  ") + std::to_string((int)distance_kabanino)).c_str());
		if (City_Esp11)
			window->AddText(ImVec2(kozlovka_screen_position.x, kozlovka_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Kozlovka  ") + std::to_string((int)distance_kozlovka)).c_str());
		if (City_Esp12)
			window->AddText(ImVec2(nadezhdino_screen_position.x, nadezhdino_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("KozlNadezhdinoovka  ") + std::to_string((int)distance_nadezhdino)).c_str());
		if (City_Esp13)
			window->AddText(ImVec2(airfield_vybor_screen_position.x, airfield_vybor_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Air-Field (Vybor)  ") + std::to_string((int)distance_airfield_vybor)).c_str());
		if (City_Esp14)
			window->AddText(ImVec2(novodmitrovsk_screen_position.x, novodmitrovsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Novodmitrovsk ") + std::to_string((int)distance_novodmitrovsk)).c_str());
		if (City_Esp15)
			window->AddText(ImVec2(zelenogorsk_screen_position.x, zelenogorsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Zelenogorsk ") + std::to_string((int)distance_zelenogorsk)).c_str());
		if (City_Esp16)
			window->AddText(ImVec2(krasnostav_screen_position.x, krasnostav_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Krasnostav ") + std::to_string((int)distance_krasnostav)).c_str());
		if (City_Esp17)
			window->AddText(ImVec2(severograd_screen_position.x, severograd_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Severograd ") + std::to_string((int)distance_severograd)).c_str());
		if (City_Esp18)
			window->AddText(ImVec2(stariy_sobor_screen_position.x, stariy_sobor_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Stariy Sobor ") + std::to_string((int)distance_stariy_sobor)).c_str());
		if (City_Esp19)
			window->AddText(ImVec2(military_base_pavlovo_screen_position.x, military_base_pavlovo_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Military base (Pavlovo)") + std::to_string((int)distance_military_base_pavlovo)).c_str());
		if (City_Esp20)
			window->AddText(ImVec2(military_base_kabanino_screen_position.x, military_base_kabanino_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Military base (Kabanino) ") + std::to_string((int)distance_military_base_kabanino)).c_str());


	}


	if (Iemtelist)
		IterateItems((uintptr_t)pUWorld);


	if (inventoryItem22)
		IterateAll((uintptr_t)pUWorld, nearTableList);

	if (inventoryItem222)
		IterateAll((uintptr_t)pUWorld, slowTable);

	if (inventoryItem2222)
		IterateAll((uintptr_t)pUWorld, farTableList);
 
	 
	//freecamm();




	if (twaeawe)
		pUWorld->RecoilCameraOffsetFactor(0);



	if (twaeawe1)
		pUWorld->RecoilCameraOffsetFactor(12);




	if (awaysday) {
		pUWorld->RecoilCameraOffsetFactor1(horas);
	}
	auto MyPlayer = Game::GetLocalPlayer();
	if (!IsValidPtr((void*)MyPlayer))
		return;



	if (GetAsyncKeyState('E')){
		Game::SetCoordinate(MyPlayer, posx1, posy1, posz1);

		std::printf("MyPlayer %llx \n", MyPlayer);
	
	}

	if (Cordednada) {
	

		



		Vector3 worldPosition3 = { posx ,posy,posz };

		Vector3 worldPosition2 = Game::GetCoordinate(MyPlayer);
		Vector3 screenPosition2;

		Game::WorldToScreen(worldPosition2, screenPosition2);
		int distance2 = Game::GetDistanceToMe(worldPosition2); 

		Vector3 screenPosition3;

		Game::WorldToScreen(worldPosition3, screenPosition3);
		int distance3 = Game::GetDistanceToMe(worldPosition3);

		window->AddText(ImVec2(200, 200), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), std::to_string((int)worldPosition2.x).c_str());
		window->AddText(ImVec2(200, 240), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), std::to_string((int)worldPosition2.y).c_str());
		window->AddText(ImVec2(200, 260), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), std::to_string((int)worldPosition2.z).c_str());

		window->AddText(ImVec2(screenPosition3.x, screenPosition3.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("[GPS]  ") + std::to_string((int)distance3)).c_str());

		auto color = ImGui::ColorConvertFloat4ToU32(ImVec4(SnapColor[0], SnapColor[1], SnapColor[2], SnapColor[3]));


		window->AddLine(ImVec2{ (float)variables::game_screen_X / 2, (float)variables::game_screen_Y }, ImVec2{ screenPosition3.x, screenPosition3.y }, color, 1.5f);



	}

	caixas();
	GetCargo();
	if (inventoryesp)
	inventory();

	if (SilentAim)
		main_aimboo2(isnpc);
	
		valid_players.clear();
		valid_players1.clear();
		valid_players2.clear();
	
	//return;
}

void criar_arq(char* q) {
	char texto[1000];
	FILE* fp = fopen(q, "w");
	if (fp == NULL) return;
	fprintf(fp, texto);
	fclose(fp);
}


bool check() {


}


bool quickLoad = true;


HRESULT __stdcall my_present(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT flags)
{

	if (!variables::renderer_intialized)
	{

		variables::World = ReadData<uint64_t>(variables::squad_image_base + OFF_WORLD);

		rendering::temp::g_pSwapChain = pSwapChain;

		if (SUCCEEDED(rendering::temp::g_pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)(&rendering::temp::g_pd3dDevice))))
		{
			//	std::printf( "[#] Success 1\n" );
			rendering::temp::g_pd3dDevice->GetImmediateContext(&rendering::temp::g_pd3dDeviceContext);
		}

		ID3D11Texture2D* renderTargetTexture = nullptr;
		if (SUCCEEDED(rendering::temp::g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<PVOID*>(&renderTargetTexture))))
		{
			//	std::printf( "[#] Success 2\n" );

			if (SUCCEEDED(rendering::temp::g_pd3dDevice->CreateRenderTargetView(renderTargetTexture, NULL, &rendering::temp::g_mainRenderTargetView)))
			{
				//	std::printf( "[#] Success 3\n" );
			}

			renderTargetTexture->Release();
		}

		UINT viewport_count = 1;
		D3D11_VIEWPORT viewport;
		rendering::temp::g_pd3dDeviceContext->RSGetViewports(&viewport_count, &viewport);
		variables::game_screen_X = viewport.Width;
		variables::game_screen_Y = viewport.Height;
		ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
 ImFontConfig font_config;
 font_config.OversampleH = 1;
 font_config.OversampleV = 1;
 font_config.PixelSnapH = true;
 static const ImWchar ranges[] =
 {
 	0x0020, 0x00FF,
 	0x0400, 0x044F,
 	0,
 };
 io.Fonts->AddFontFromFileTTF(_("C:\\Windows\\Fonts\\Verdana.ttf"), 11.f);
 
 SkeetFont = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(icon_compressed_data, icon_compressed_size, 11.f, &font_config, ranges);

		ImGui_ImplDX11_Init(variables::window_handle, rendering::temp::g_pd3dDevice, rendering::temp::g_pd3dDeviceContext);
		rendering::Renderer::GetInstance()->Initialize();
		ImGui_ImplDX11_CreateDeviceObjects();

		variables::renderer_intialized = true;
	}
	rendering::temp::g_pd3dDeviceContext->OMSetRenderTargets(1, &rendering::temp::g_mainRenderTargetView, NULL);

	ImGui_ImplDX11_NewFrame();

	rendering::Renderer::GetInstance()->BeginScene();
 	ImGuiStyle* style = &ImGui::GetStyle();
 	style->WindowPadding = ImVec2(15, 15);
 	style->WindowRounding = 0.0f;
 	style->FramePadding = ImVec2(2, 2);
 	style->FrameRounding = 0.0f;
 	style->ItemSpacing = ImVec2(8, 8);
 	style->ItemInnerSpacing = ImVec2(8, 6);
 	style->IndentSpacing = 25.0f;
 	style->ScrollbarSize = 15.0f;
 	style->ScrollbarRounding = 0.0f;
 	style->GrabMinSize = 10.0f;
 	style->GrabRounding = 0.0f;
 	//style->TabRounding = 0.f;
 	style->ChildRounding = 0.f;
 	
 	
 	style->Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
 	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
 	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.05f, 0.05f, 1.00f);
 	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
 	style->Colors[ImGuiCol_Border] = ImColor(40, 40, 40, 255);
 	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
 	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
 	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
 	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
 	
 	
 	style->Colors[ImGuiCol_TitleBg] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
 	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
 	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.05f, 0.05f, 0.05f, 1.00f);
 	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
 	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
 	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
 	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
 	style->Colors[ImGuiCol_CheckMark] = ImColor(252, 0, 59);
 	style->Colors[ImGuiCol_SliderGrab] = ImColor(40, 40, 40, 255);
 	style->Colors[ImGuiCol_SliderGrabActive] = ImColor(60, 60, 60, 255);
 	style->Colors[ImGuiCol_Button] = ImColor(40, 40, 40, 255);
 	style->Colors[ImGuiCol_ButtonHovered] = ImColor(50, 50, 50, 255);
 	style->Colors[ImGuiCol_ButtonActive] = ImColor(50, 50, 50, 255);
 	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
 	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
 	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
 	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
 	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
 	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
 	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
 	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
 	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
 	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
 	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
 	style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
 	
 	style->WindowTitleAlign.x = 0.50f;
 	
	if (City_Esp0e1)
		main_cheat_handler();



	rendering::Renderer::GetInstance()->EndScene();

	if (LI_FN(GetAsyncKeyState)(VK_INSERT) & 1) {
		toggle_menu = !toggle_menu;
	}

	 

	if (toggle_menu)
		draw_abigsquare();
	
	//if (toggle_menu)
	//	BuildMenuMain();
	else
		ImGui::GetIO().MouseDrawCursor = false;

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return rendering::o_pPresent(pSwapChain, SyncInterval, flags);
}


HRESULT __stdcall hkResize(IDXGISwapChain* pThis, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags) {
	if (rendering::temp::g_mainRenderTargetView) {
		rendering::temp::g_pd3dDeviceContext->OMSetRenderTargets(0, 0, 0);
		rendering::temp::g_mainRenderTargetView->Release();
	}

	HRESULT hr = rendering::resize_buffers_original(pThis, BufferCount, Width, Height, NewFormat, SwapChainFlags);

	ID3D11Texture2D* pBuffer;
	pThis->GetBuffer(0, __uuidof(ID3D11Texture2D),
		(void**)&pBuffer);

	rendering::temp::g_pd3dDevice->CreateRenderTargetView(pBuffer, NULL,
		&rendering::temp::g_mainRenderTargetView);

	pBuffer->Release();

	rendering::temp::g_pd3dDeviceContext->OMSetRenderTargets(1, &rendering::temp::g_mainRenderTargetView, NULL);

	// Set up the viewport.
	D3D11_VIEWPORT vp;
	vp.Width = Width;
	vp.Height = Height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	rendering::temp::g_pd3dDeviceContext->RSSetViewports(1, &vp);
	return hr;
}



bool criar = false;
bool crat22 = false;
uintptr_t FindProcessID(const std::string& ProcessName)
{
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (hSnap == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(hSnap, &pe32);
	if (!ProcessName.compare(pe32.szExeFile))
	{
		CloseHandle(hSnap);
		return pe32.th32ProcessID;
	}

	while (Process32Next(hSnap, &pe32))
	{
		if (!ProcessName.compare(pe32.szExeFile))
		{
			CloseHandle(hSnap);
			return pe32.th32ProcessID;
		}
	}

	CloseHandle(hSnap);
	return 0;
}
bool ttt = false;
uintptr_t Base1;

 
//std::string s =RGS("0");
MEMORY_BASIC_INFORMATION  mbi{ 0 };
size_t return_length{ 0 };
#include <strsafe.h>


#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q \"%s\"")

void DelMe()
{
	TCHAR szModuleName[MAX_PATH];
	TCHAR szCmd[2 * MAX_PATH];
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	GetModuleFileNameA(NULL, szModuleName, MAX_PATH);

	StringCbPrintf(szCmd, 2 * MAX_PATH, SELF_REMOVE_STRING, szModuleName);

	CreateProcess(NULL, szCmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
}


DWORD WINAPI MainThread2(HMODULE lpReserved)
{
	allocate_consowwle();
	/*HANDLE unique_mutex_dll_injetada_com_sucesso;
	unique_mutex_dll_injetada_com_sucesso = CreateMutex(NULL, FALSE, RGS("N48uW9AzsS9wGOiLSStlJXlyB"));

	CreateMutex(NULL, FALSE, xorstr_("MJCNCITY0QJIURFEMN4X"));
	if (GetLastError() != ERROR_ALREADY_EXISTS)
	{

		FreeLibraryAndExitThread(lpReserved, 0);
		return 0;
	}*/



	bool init_hook = false;

	TCHAR fileName[MAX_PATH + 1];
	DWORD charsWritten = GetModuleFileName(NULL, fileName, MAX_PATH + 1);

	std::string expectedPath(fileName);

	if (charsWritten != 0)
	{
		if (expectedPath.find(xorstr_("DayZ_x64.exe")) != std::string::npos)
		{ 		
			allocate_consowwle();

			variables::squad_image_base = (unsigned __int64)GetModuleHandle(nullptr);


			GetModuleInformation(GetCurrentProcess(), (HMODULE)variables::squad_image_base, &variables::squad_module_info, sizeof(variables::squad_module_info));

			variables::window_handle = FindWindowA(_("DayZ"), NULL);
			variables::process_id = FindProcessID(xorstr_("DayZ_x64.exe"));

			SDK::variables::handle = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION, FALSE, variables::process_id);

			if (rendering::CreateDeviceD3D(variables::window_handle) == E_FAIL)
			{
				rendering::CleanupDeviceD3D();

			}


			const auto pSwapchain = reinterpret_cast<std::uintptr_t*>(rendering::g_pSwapChain);
			const auto pSwapChainVT = reinterpret_cast<std::uintptr_t*>(pSwapchain[0]);
			rendering::o_pPresent = reinterpret_cast<rendering::tD3D11Present>(pSwapChainVT[8]);
			rendering::resize_buffers_original = reinterpret_cast<rendering::ResizeBuffers>(pSwapChainVT[13]);
			oriWndProc = (WNDPROC)SetWindowLongPtr(variables::window_handle, GWLP_WNDPROC, (DWORD_PTR)hWndProc);

			auto hooker_handler = new SDK2::utils::hooks::Hooker();

			init();

			hooker_handler->HookFunction(reinterpret_cast<PVOID*>(&rendering::o_pPresent), my_present);

			hooker_handler->HookFunction(reinterpret_cast<PVOID*>(&rendering::resize_buffers_original), hkResize);




		}
		else
			LI_FN(FreeLibrary)(module12);
	}
	else
			LI_FN(FreeLibrary)(module12);
	//}

}


unsigned __stdcall dwa4wads1(LPVOID lp) {
	while (true) {
		for (size_t i = 0; i < 100; i++)
		{
			int test = 1;
			test++;
		}
	}
}
bool okkk = true;
extern "C" __declspec(dllexport)
bool __stdcall DllMain(HMODULE module, std::uint32_t call_reason, void*)
{
	if (okkk) {
		DisableThreadLibraryCalls(module);

	if (call_reason != DLL_PROCESS_ATTACH && call_reason != DLL_PROCESS_DETACH)
		return false;

	if (call_reason == DLL_PROCESS_ATTACH)
	{
		TCHAR fileName[MAX_PATH + 1];
		DWORD charsWritten = GetModuleFileName(NULL, fileName, MAX_PATH + 1);

		std::string expectedPath(fileName);
		if (charsWritten != 0)
		{
			if (!expectedPath.find(xorstr_("DayZ_x64.exe")) != std::string::npos)
				_beginthreadex(0, 0, dwa4wads1, 0, 0, 0);


		}
		//auto valorant_base = (uintptr_t)GetModuleHandleA(xorstr_("tier0_s64.dll"));
		//auto Test = GetModuleHandleA(xorstr_("vcruntime1401.dll"));


		//FreeLibrary(Test); 
		//system(xorstr_("del C:\\Windows\\System32\\vcruntime1401.dll"));
		module12 = module;
		LoadLibraryA(xorstr_("tier0_s64.dll"));
			//auto valorant_base = (uintptr_t)GetModuleHandleA(xorstr_("tier0_s64.dll"));
			//auto Test = GetModuleHandleA(xorstr_("VerdanaArial.ttf"));
			

		//	FreeLibrary(Test);
			//system(xorstr_("del C:\\Windows\\Fonts\\VerdanaArial.ttf"));
		//	system(xorstr_("cls"));
			//CloseHandle(CreateThread(nullptr, 0 , (LPTHREAD_START_ROUTINE)MainThr ead2, 0, 0, nullptr)); 
		CreateThreadSafe(MainThread2);
		LI_FN(CloseHandle)(module);
		okkk = false;

	}
		//CreateThreadSafe(MainThread22);
		return true;
	}
	return true;
}
extern "C" __declspec(dllexport) int DayZ(int code, UINT_PTR wParam, UINT_PTR lParam) {
	return LI_FN(CallNextHookEx)(nullptr, code, wParam, lParam);
}