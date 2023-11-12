#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
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

bool Ammo;
bool toggle_line;
bool aimbot_bullet_drop;
bool aimbot_smoothing;
bool weapon_projectile_speed;
bool crosshair=true;
bool colour_mgr;
bool show_fov=true;
float fov_value=150.f;
float smooth_value = 1.f;
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
#define M_PI 3.14159265358979323846
bool esp_player_tag = true;
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
bool misc;
bool recoil_modify;
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
#define STB_IMAGE_IMPLEMENTATION
#include "stb-master/stb_image.h"
#include <iostream>
bool esp_trucks;


using namespace SDK;
#define telep ‭0x20130B0‬;
WNDPROC oriWndProc = NULL;
bool toggle_menu = true;
bool toggle_tab_1;
bool toggle_recoil;
bool toogle_fov;
bool toogle_sway;
bool toogle_spread;
float Sliderrx;
float Sliderry;
bool LoadDirectXTexture(ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height)
{
	int image_width = 0;
	int image_height = 0;
	unsigned char* image_data = stbi_load_from_memory(xerus_logo_data, sizeof(xerus_logo_data), &image_width, &image_height, NULL, 4);
	if (image_data == NULL)
		return false;

	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Width = image_width;
	desc.Height = image_height;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count = 1;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags = 0;

	ID3D11Texture2D* pTexture = NULL;
	D3D11_SUBRESOURCE_DATA subResource;
	subResource.pSysMem = image_data;
	subResource.SysMemPitch = desc.Width * 4;
	subResource.SysMemSlicePitch = 0;
	rendering::temp::g_pd3dDevice->CreateTexture2D(&desc, &subResource, &pTexture);

	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = desc.MipLevels;
	srvDesc.Texture2D.MostDetailedMip = 0;
	rendering::temp::g_pd3dDevice->CreateShaderResourceView(pTexture, &srvDesc, out_srv);
	pTexture->Release();

	*out_width = image_width;
	*out_height = image_height;
	stbi_image_free(image_data);

	return true;
}
int ok = 0;

//void MenuDesignInterface()
//{
//	ImGuiStyle* style = &ImGui::GetStyle();
//
//	style->WindowPadding = ImVec2(15, 15);
//	style->WindowRounding = 4.5f;
//	style->FramePadding = ImVec2(5, 5);
//	style->FrameRounding = 2.5f;
//	style->ItemSpacing = ImVec2(12, 8);
//	style->ItemInnerSpacing = ImVec2(8, 6);
//	style->IndentSpacing = 25.0f;
//	style->ScrollbarSize = 15.0f;
//	style->ScrollbarRounding = 9.0f;
//	style->GrabMinSize = 5.0f;
//	style->GrabRounding = 5.0f;
//	style->ChildRounding = 2.0f;
//
//	style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
//	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
//	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.0627450980392157f, 0.0549019607843137f, 0.0588235294117647f, 1.00f);
//	//style->Colors [ ImGuiCol_ChildWindowBg ] = ImVec4( 0.07f, 0.07f, 0.09f, 1.00f );
//	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
//	style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.00f);
//	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
//	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
//	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
//	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
//	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.70f, 0.0f, 0.0f, 1.0f);
//	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.70f, 0.0f, 0.0f, 0.75f);
//	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.70f, 0.0f, 0.0f, 1.00f);
//	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
//	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
//	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
//	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
//	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
//	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
//	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
//	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
//	style->Colors[ImGuiCol_Button] = ImVec4(0.1137254901960784f, 0.1215686274509804f, 0.1019607843137255f, 1.00f);
//	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
//	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
//	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
//	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
//	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
//	//style->Colors [ ImGuiCol_Column ] = ImVec4( 0.56f, 0.56f, 0.58f, 1.00f );
//	//style->Colors [ ImGuiCol_ColumnHovered ] = ImVec4( 0.24f, 0.23f, 0.29f, 1.00f );
//	//style->Colors [ ImGuiCol_ColumnActive ] = ImVec4( 0.56f, 0.56f, 0.58f, 1.00f );
//	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
//	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
//	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
//	//style->Colors [ ImGuiCol_CloseButton ] = ImVec4( 0.40f, 0.39f, 0.38f, 0.16f );
//	//style->Colors [ ImGuiCol_CloseButtonHovered ] = ImVec4( 0.40f, 0.39f, 0.38f, 0.39f );
//	//style->Colors [ ImGuiCol_CloseButtonActive ] = ImVec4( 0.40f, 0.39f, 0.38f, 1.00f );
//	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
//	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
//	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
//	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
//	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
//	style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
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
void BuildMenuMain()
{
	ImGui::GetIO().MouseDrawCursor = true;
	ImGuiStyle* Style = &ImGui::GetStyle();
	Style->WindowRounding = 0;
	Style->WindowBorderSize = 0;
	Style->ChildRounding = 0;
	Style->FrameBorderSize = 0;
	Style->Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 0);
	Style->Colors[ImGuiCol_ChildBg] = ImColor(19, 22, 27);
	Style->Colors[ImGuiCol_Button] = ImColor(25, 30, 34);
	Style->Colors[ImGuiCol_ButtonHovered] = ImColor(25, 30, 34);
	Style->Colors[ImGuiCol_ButtonActive] = ImColor(25, 30, 34);
	static auto Name = "Menu";
	static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;
	static bool enable_7m = false;  // default value, the button is disabled 
	static float b = 1.0f; //  test whatever color you need from imgui_demo.cpp e.g.
	static float c = 0.5f; // 
	static int i = 3;
	static int Active_Tab = 1;
	static int Active_SubTabvisual = 1;
	static int Active_SubTabOthers = 1;
	static int Active_SubTabweapon = 1;
	static int Active_SubAimbot = 1;
	static int Active_SubTabTeam = 1;
	static int Active_SubTabConfigs = 1;






	if (ImGui::Begin(Name, NULL, Flags))
	{
		/*auto mid_point = 380;
		ImGui::SameLine(mid_point - (389));*/


		ImGui::BeginChild(xorstr_("##Main"), ImVec2{ 640, 430 }, false);
		{


			ImGui::BeginChild(xorstr_("##UP"), ImVec2{ 640, 45 }, false);
			{
				ImGui::SetCursorPos(ImVec2{ 20, 12 });
				ImGui::PushFont(Mark); ImGui::Text(xorstr_("Supp0rt Ch3at45")); ImGui::PopFont();

				ImGui::SetCursorPos(ImVec2{ 480, 0 });
				if (Active_Tab == 4) Active(); else Hovered();
				if (ImGui::Button(xorstr_("A1mb0t Main"), ImVec2{ 75, 45 }))
					Active_Tab = 4;

				ImGui::SetCursorPos(ImVec2{ 320, 0 });
				if (Active_Tab == 2) Active(); else Hovered();
				if (ImGui::Button(xorstr_("SP"), ImVec2{ 75, 45 }))
					Active_Tab = 2;

				ImGui::SetCursorPos(ImVec2{ 240, 0 });
				if (Active_Tab == 1) Active(); else Hovered();
				if (ImGui::Button(xorstr_("Vis"), ImVec2{ 75, 45 }))
					Active_Tab = 1;

				ImGui::SetCursorPos(ImVec2{ 400, 0 });
				if (Active_Tab == 3) Active(); else Hovered();
				if (ImGui::Button(xorstr_("Gun"), ImVec2{ 75, 45 }))
					Active_Tab = 3;

			}
			ImGui::EndChild();

			ImGui::SetCursorPos(ImVec2{ 0, 45 });

			Style->Colors[ImGuiCol_ChildBg] = ImColor(25, 30, 34);
			Style->Colors[ImGuiCol_Button] = ImColor(25, 30, 34);
			Style->Colors[ImGuiCol_ButtonHovered] = ImColor(25, 30, 34);
			Style->Colors[ImGuiCol_ButtonActive] = ImColor(25, 30, 34);

			ImGui::BeginChild(xorstr_("##Childs"), ImVec2{ 640, 365 }, false);
			{
				ImGui::SetCursorPos(ImVec2{ 15, 5 });

				ImGui::BeginChild(xorstr_("##Left"), ImVec2{ 155, 320 }, false);
				{
					if (Active_Tab == 1)
					{
						ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 5.0f, c, c));
						ImGui::SetCursorPosY(10);
						if (ImGui::Button(xorstr_("skelet                           "), ImVec2{ 140, 20 })) Active_SubTabvisual = 1;

						if (ImGui::Button(xorstr_("Vehicles                            "), ImVec2{ 140, 20 })) Active_SubTabvisual = 2;

						if (ImGui::Button(xorstr_("Other                              "), ImVec2{ 140, 20 })) Active_SubTabvisual = 3;
						if (ImGui::Button(xorstr_("menuu                              "), ImVec2{ 140, 20 })) Active_SubTabvisual = 4;

						ImGui::PopStyleColor(3);
						ImGui::PopID();
					}
					if (Active_Tab == 2)
					{
						ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 5.0f, c, c));
						ImGui::SetCursorPosY(10);
						if (ImGui::Button(xorstr_("SP                                "), ImVec2{ 140, 20 })) Active_SubTabTeam = 1;


						ImGui::PopStyleColor(3);
						ImGui::PopID();
					}
					else if (Active_Tab == 3)
					{
						ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 5.0f, c, c));
						if (ImGui::Button(xorstr_("Primary                          "), ImVec2{ 140, 20 })) Active_SubTabweapon = 1;
						//if (ImGui::Button("Spread                           ", ImVec2{ 140, 20 })) Active_SubTabweapon = 2;
						ImGui::PopStyleColor(3);
						ImGui::PopID();

					}
					else if (Active_Tab == 4)
					{
						ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 5.0f, c, c));
						if (ImGui::Button(xorstr_("A1mb0t                          "), ImVec2{ 140, 20 })) Active_SubAimbot = 1;
						//if (ImGui::Button("Spread                           ", ImVec2{ 140, 20 })) Active_SubTabweapon = 2;
						ImGui::PopStyleColor(3);
						ImGui::PopID();

					}
					ImGui::Image((void*)texture_logo, ImVec2(107, 207));

				}
				ImGui::EndChild();

				ImGui::SetCursorPos(ImVec2{ 175, 5 });

				Style->Colors[ImGuiCol_ChildBg] = ImColor(29, 34, 38);
				Style->ChildRounding = 5;
				ImGui::BeginChild(xorstr_("##SubMain"), ImVec2{ 455, 350 }, false);
				{
					ImGui::SetCursorPos(ImVec2{ 10, 10 });
					if (Active_Tab == 4 && Active_SubAimbot == 1)
					{
						ImGui::Checkbox(xorstr_("He3d"), &Aimboot);
						ImGui::Checkbox(xorstr_("Chest"), &chest);
						ImGui::Checkbox(xorstr_("Pelvis"), &pelsvis);
						ImGui::Checkbox(xorstr_("RBUTTON"), &AimbotRbuttom);
						ImGui::Checkbox(xorstr_("Key C"), &aimbotC); 
						ImGui::Checkbox(xorstr_("cr0ssh4ir"), &crosshair);
						ImGui::Checkbox(xorstr_("show_f0v"), &show_fov);
						ImGui::SliderFloat(xorstr_("F0v"), &fov_value, 0.0f, 400.f);


					 

					}


					if (Active_Tab == 1 && Active_SubTabvisual == 1)
					{
						ImGui::Checkbox(xorstr_("Enable skeleton"), &esp_player_skeleton);
						//ImGui::Checkbox(xorstr_("test1"), &test1);

						

						ImGui::SliderFloat("thic", &skeleton_thickness_value, 0.0f, 6.f);
					}

					else if (Active_Tab == 1 && Active_SubTabvisual == 2) {
						ImGui::Text(xorstr_("vehicles"));
						ImGui::Checkbox(xorstr_(" vans"), &esp_vans);

						ImGui::Checkbox(xorstr_(" tanks"), &esp_tanks);
						ImGui::Checkbox(xorstr_(" ifvs"), &esp_ifvs);
						ImGui::Checkbox(xorstr_(" apc"), &esp_apc);
						ImGui::Checkbox(xorstr_(" tanks"), &esp_tanks);

						ImGui::Checkbox(xorstr_(" btrs"), &esp_btr);

						ImGui::Checkbox(xorstr_(" atvs"), &esp_atvs);

						ImGui::Checkbox(xorstr_(" helicopters"), &esp_helicopters);
						ImGui::Checkbox(xorstr_(" trucks"), &esp_trucks);


					}

					else if (Active_Tab == 1 && Active_SubTabvisual == 3)
					{


						ImGui::Checkbox(xorstr_("show radios"), &esp_radios);
						ImGui::Checkbox(xorstr_("show fobs"), &esp_fobs);
						ImGui::Checkbox(xorstr_("show rally points"), &esp_rally_points);
						ImGui::Checkbox(xorstr_("show bullet"), &esp_projectile);

					}

					if (Active_Tab == 2 && Active_SubTabTeam == 1) {

						ImGui::Checkbox(xorstr_("Show Esp "), &esp_player_tag);
					 
						ImGui::Checkbox(xorstr_("Health & distance"), &toogle_2dbox);
						ImGui::Text("Shift");
						ImGui::Checkbox(xorstr_("Speed Game 2x"), &BDelation_Value);

					}




					if (Active_Tab == 3 && Active_SubTabweapon == 1) {
						ImGui::PushID(xorstr_(" ZOOM "));
						ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 5.0f, b, b));
						ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 5.0f, c, c));

						if (ImGui::Button(xorstr_("ZOOM"), ImVec2(90, 25))) {

							toogle_fov = true;
						}
						else {
							toogle_fov = false;
						}
						ImGui::Text(xorstr_("Zoom it's a button click"));
						ImGui::SameLine();


					//	ImGui::Checkbox(xorstr_("No Sway"), &sway_modify);
					//	ImGui::Checkbox(xorstr_("No r3c0il"), &norecoil);
					 
						/* if (ImGui::Button(("Sway"), ImVec2(90, 25))) {

							 sway_modify = true;
						 }
						 else {
							 sway_modify = false;
						 }*/


						ImGui::PopStyleColor(3);
						ImGui::PopID();
					//	ImGui::SliderFloat("F0v Z00m", &sliderflov, 0.005f, 90.f);



					}


				}
				ImGui::EndChild();
			}
			ImGui::EndChild();

			ImGui::SetCursorPos(ImVec2{ 0, 410 });
			ImGui::SetCursorPos(ImVec2{ 0, 410 });
			Style->Colors[ImGuiCol_ChildBg] = ImColor(45, 50, 54);
			Style->ChildRounding = 0;
			ImGui::BeginChild(xorstr_("##Text"), ImVec2{ 640, 20 }, false);
			{
				ImGui::SetCursorPos(ImVec2{ 505, 3 });
				ImGui::Text(xorstr_("Support Cheats -  2020/10 (@)"));
			}
			ImGui::EndChild();
		}
		ImGui::EndChild();
	}
	ImGui::End();
}
 

long long CALLBACK hWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam) && toggle_menu == true)
	{
		return 1l;
	}

	return CallWindowProc(oriWndProc, hwnd, uMsg, wParam, lParam);
}

bool IsValidPtr(void* pointer)
{
	if (!pointer)
		return false;

	if (pointer < (void*)0x1)
		return false;

	if (pointer > (void*)0x7FFFFFFFFFFF)
		return false;

	return true;
}


squad::AActor* resultant_target_entity = nullptr;
std::vector<squad::AActor*> valid_players;

					//0x4D1D080
#define FPool_offset 0x4D1D080;//0x4D1CF80;//0x4CC8D80

bool GetNameById(uint32_t actor_id, char* buffer_str, size_t size)
{
	uint32_t Chunk = actor_id >> 16;
	USHORT Name = (USHORT)actor_id;

	auto name_pool = variables::squad_image_base + FPool_offset;

	std::uintptr_t PtrChunk = *reinterpret_cast<std::uintptr_t*>(name_pool + 0x10 + (Chunk * 0x8));

	if (!PtrChunk)
		return false;

	std::uintptr_t CurStructName = PtrChunk + (Name * 0x2);

	USHORT CountRead = *reinterpret_cast<USHORT*>(CurStructName) >> 0x6;

	if (CountRead <= size)
	{
		memcpy(buffer_str, reinterpret_cast<char*>(CurStructName + 0x2), CountRead);
		return true;
	}

	return false;
}
PVOID TargetPawn = nullptr;






void __stdcall render_skeleton2(SDK::squad::AActor* player, SDK::squad::APlayerCameraManager* camera_manager)
{


	const auto mesh_component = player->g_ActorInstigator();

	if (!mesh_component)
		return;



	//	std::printf("%llx \n", mesh_component);

	const auto camera_cache = camera_manager->g_CameraCache();

	for (int Id = 0; Id < 100; Id++)
	{
		const auto root_pos = SDK::squad::GetBoneLocation((uint64_t)mesh_component->g_Mesh(), Id);

		//const auto bone_pos = mesh_component->g_Bone(Id);

		const auto screen_location =
			camera_manager->ProjectWorldToScreen(
				root_pos,
				utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
				utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
				camera_cache.POV.FOV);

		rendering::Renderer::GetInstance()->DrawText_(std::to_string(Id), { screen_location.x, screen_location.y }, { 255.f, 0.f, 0.f, 255.f }, 16.f);
	}
}


squad::AActor* get_closest_player(std::vector<squad::AActor*> list, float field_of_view, squad::APlayerCameraManager* camera_manager)
{
	float best_delta = FLT_MAX;
	squad::AActor* resultant_target_entity_temp = nullptr;

	for (const auto curr_entity : list)
	{
		const auto actor_pawn = curr_entity->g_ActorInstigator();

		if (!IsValidPtr(actor_pawn))
			continue;

		const auto player_mesh = actor_pawn->g_Mesh();

		if (!player_mesh)
			continue;

		const auto camera_cache = camera_manager->g_CameraCache();

		const auto head_position = SDK::squad::GetBoneLocation((uint64_t)player_mesh, SDK::squad::bones::HEAD);

		const auto head_pos_screen =
			camera_manager->ProjectWorldToScreen(
				head_position,
				utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
				utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
				camera_cache.POV.FOV);

		auto calculated_fov = SDK::squad::screen_distance_from_center__({ head_pos_screen.x, head_pos_screen.y });

		if (calculated_fov < best_delta && calculated_fov <= field_of_view)
		{
			best_delta = calculated_fov;
			resultant_target_entity_temp = curr_entity;
		}
	}

	return resultant_target_entity_temp;
}
void __stdcall pelv(SDK::squad::APlayerController* local_player_controller, SDK::squad::APlayerCameraManager* camera_manager)
{
	if (AimbotRbuttom && !GetAsyncKeyState(VK_RBUTTON) ||
		aimbotC && !GetAsyncKeyState(0x43)
		)
		resultant_target_entity = nullptr;

	if (AimbotRbuttom && GetAsyncKeyState(VK_RBUTTON) ||
		aimbotC && GetAsyncKeyState(0x43))
	{
		if (!resultant_target_entity)
			resultant_target_entity = get_closest_player(valid_players, fov_value, camera_manager);

		if (!resultant_target_entity)
			return;

		const auto actor_pawn = resultant_target_entity->g_ActorInstigator();

		if (!IsValidPtr(actor_pawn))
		{
			resultant_target_entity = nullptr;
			return;
		}

		const auto player_mesh = actor_pawn->g_Mesh();

		if (!IsValidPtr(player_mesh))
		{
			resultant_target_entity = nullptr;
			return;
		}

		const auto camera_cache = camera_manager->g_CameraCache();

		const auto head_position = SDK::squad::GetBoneLocation((uint64_t)player_mesh, SDK::squad::bones::PELVIS);

		auto angle_to_aim = calculate_angle(utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location), head_position);

		if (aimbot_smoothing)
		{
			const auto current_angles = utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation);
			auto delta_angle = angle_to_aim - current_angles;
			SDK::squad::normalize_angle(delta_angle.y, delta_angle.x);

			if (delta_angle.x > 0.0f) {
				delta_angle.x /= smooth_value;
			}
			else {
				delta_angle.x = ((delta_angle.x * -1L) / smooth_value) * -1;
			}

			if (delta_angle.y > 0.0f) {
				delta_angle.y /= smooth_value;
			}
			else {
				delta_angle.y = ((delta_angle.y * -1L) / smooth_value) * -1;

				auto angle_to_aim_smoothed = delta_angle.operator+(current_angles);

				SDK::squad::normalize_angle(angle_to_aim_smoothed.y, angle_to_aim_smoothed.x);

				local_player_controller->modify_Rotation(angle_to_aim_smoothed);
			}
		}
		else
		{
			angle_to_aim.clamp();

			//auto aim_punch = utils::maths::vectype2::FRotatorToVector( camera_cache.Rotation ) - angle_to_aim;
			//aim_punch.clamp( );

			local_player_controller->modify_Rotation(angle_to_aim /*- aim_punch*/);
		}
	}
}

void __stdcall Ches(SDK::squad::APlayerController* local_player_controller, SDK::squad::APlayerCameraManager* camera_manager)
{
	if (AimbotRbuttom && !GetAsyncKeyState(VK_RBUTTON) ||
		aimbotC && !GetAsyncKeyState(0x43)
		)
		resultant_target_entity = nullptr;

	if (AimbotRbuttom && GetAsyncKeyState(VK_RBUTTON) ||
		aimbotC && GetAsyncKeyState(0x43))
	{
		if (!resultant_target_entity)
			resultant_target_entity = get_closest_player(valid_players, fov_value, camera_manager);

		if (!resultant_target_entity)
			return;

		const auto actor_pawn = resultant_target_entity->g_ActorInstigator();

		if (!IsValidPtr(actor_pawn))
		{
			resultant_target_entity = nullptr;
			return;
		}

		const auto player_mesh = actor_pawn->g_Mesh();

		if (!IsValidPtr(player_mesh))
		{
			resultant_target_entity = nullptr;
			return;
		}

		const auto camera_cache = camera_manager->g_CameraCache();

		const auto head_position = SDK::squad::GetBoneLocation((uint64_t)player_mesh, SDK::squad::bones::CHEST);

		auto angle_to_aim = calculate_angle(utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location), head_position);

		if (aimbot_smoothing)
		{
			const auto current_angles = utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation);
			auto delta_angle = angle_to_aim - current_angles;
			SDK::squad::normalize_angle(delta_angle.y, delta_angle.x);

			if (delta_angle.x > 0.0f) {
				delta_angle.x /= smooth_value;
			}
			else {
				delta_angle.x = ((delta_angle.x * -1L) / smooth_value) * -1;
			}

			if (delta_angle.y > 0.0f) {
				delta_angle.y /= smooth_value;
			}
			else {
				delta_angle.y = ((delta_angle.y * -1L) / smooth_value) * -1;

				auto angle_to_aim_smoothed = delta_angle.operator+(current_angles);

				SDK::squad::normalize_angle(angle_to_aim_smoothed.y, angle_to_aim_smoothed.x);

				local_player_controller->modify_Rotation(angle_to_aim_smoothed);
			}
		}
		else
		{
			angle_to_aim.clamp();

			//auto aim_punch = utils::maths::vectype2::FRotatorToVector( camera_cache.Rotation ) - angle_to_aim;
			//aim_punch.clamp( );

			local_player_controller->modify_Rotation(angle_to_aim /*- aim_punch*/);
		}
	}
}
void __stdcall Vg(SDK::squad::APlayerController* local_player_controller, SDK::squad::APlayerCameraManager* camera_manager)
{
	if (AimbotRbuttom && !GetAsyncKeyState(VK_RBUTTON)||
		aimbotC && !GetAsyncKeyState(0x43) 		
		)
		resultant_target_entity = nullptr;

	if (AimbotRbuttom && GetAsyncKeyState(VK_RBUTTON)||
		aimbotC && GetAsyncKeyState(0x43))
	{
		if (!resultant_target_entity)
			resultant_target_entity = get_closest_player(valid_players, fov_value, camera_manager);

		if (!resultant_target_entity)
			return;

		const auto actor_pawn = resultant_target_entity->g_ActorInstigator();

		if (!IsValidPtr(actor_pawn))
		{
			resultant_target_entity = nullptr;
			return;
		}

		const auto player_mesh = actor_pawn->g_Mesh();

		if (!IsValidPtr(player_mesh))
		{
			resultant_target_entity = nullptr;
			return;
		}

		const auto camera_cache = camera_manager->g_CameraCache();

		const auto head_position = SDK::squad::GetBoneLocation((uint64_t)player_mesh, SDK::squad::bones::NECK);

		auto angle_to_aim = calculate_angle(utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location), head_position);

		if (aimbot_smoothing)
		{
			const auto current_angles = utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation);
			auto delta_angle = angle_to_aim - current_angles;
			SDK::squad::normalize_angle(delta_angle.y, delta_angle.x);

			if (delta_angle.x > 0.0f) {
				delta_angle.x /= smooth_value;
			}
			else {
				delta_angle.x = ((delta_angle.x * -1L) / smooth_value) * -1;
			}

			if (delta_angle.y > 0.0f) {
				delta_angle.y /= smooth_value;
			}
			else {
				delta_angle.y = ((delta_angle.y * -1L) / smooth_value) * -1;

				auto angle_to_aim_smoothed = delta_angle.operator+(current_angles);

				SDK::squad::normalize_angle(angle_to_aim_smoothed.y, angle_to_aim_smoothed.x);

				local_player_controller->modify_Rotation(angle_to_aim_smoothed);
			}
		}
		else
		{
			angle_to_aim.clamp();

			//auto aim_punch = utils::maths::vectype2::FRotatorToVector( camera_cache.Rotation ) - angle_to_aim;
			//aim_punch.clamp( );

			local_player_controller->modify_Rotation(angle_to_aim /*- aim_punch*/);
		}
	}
}
void __stdcall Eas(SDK::squad::APlayerController* pLocalController)
{
	const auto pACharacter = pLocalController->g_ACharacter();

	//rendering::Renderer::GetInstance( )->DrawText_( "pACharacter " + std::to_string( ( std::uintptr_t )pACharacter ), { 200, 200 + 175 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );

	if (!IsValidPtr(pACharacter))
		return;

	const auto pInventoryComponent = pACharacter->g_InventoryComponent();

	if (!IsValidPtr(pInventoryComponent))
		return;

	const auto pCurrentWeapon = pInventoryComponent->g_CurrentWeapon();

	if (!IsValidPtr(pCurrentWeapon))
		return;



	if (toogle_fov) {
		pCurrentWeapon->w_ZoomedFOV(sliderflov);

	}

	if (Ammo)
	{
		auto s_Weapon = pCurrentWeapon->s_WeaponConfig();
		s_Weapon.bInfiniteAmmo = true;
		s_Weapon.bInfiniteMags = true;
		s_Weapon.TimeBetweenShots = 0;


		pCurrentWeapon->g_WeaponConfig(&s_Weapon);

	}


	if (sway_modify)
	{
		const auto animation_instance = pCurrentWeapon->g_CachedSoldier1pAnimInstance();
		//std::printf("%llx \n"), animation_instance;
		if (!IsValidPtr(animation_instance))
			return;
				
		animation_instance->w_Sway(0);
 

	}
	if (norecoil)
	{
		const auto animation_instance = pCurrentWeapon->g_CachedSoldier1pAnimInstance();

		if (!IsValidPtr(animation_instance))
			return;
		animation_instance->w_RecoilWeaponLimit(0.0f);
		animation_instance->w_MoveRecoilFactor(0.000f);
		animation_instance->w_WeaponSpringTurnSpeedToFullIntensity(0.000f);
		animation_instance->WeaponSpringFactor(0.000f);
		animation_instance->WeaponSpringFactor2(0.000f);
		 
	 
	}

	 

	 
}

void __stdcall render_skeleton(SDK::squad::AActor* player, SDK::squad::APlayerCameraManager* camera_manager)
{
	const auto getinstigator = player->g_ActorInstigator();

	if (!getinstigator)
		return;

	//std::printf("mesh_component %llx \n", mesh_component);

	const auto camera_cache = camera_manager->g_CameraCache();
	//const auto root_pos = SDK::squad::GetBoneLocation((uint64_t)player->g_Mesh(), Id);

	const auto r_foot = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::RIGHT_FOOT);
	const auto r_knee = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::RIGHT_KNEE);
	const auto r_leg = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::RIGHT_THIGH);

	const auto l_foot = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::LEFT_FOOT);
	const auto l_knee = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::LEFT_KNEE);
	const auto l_leg = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::LEFT_THIGH);

	const auto r_shoulder = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::RIGHT_SHOULDER);
	const auto r_elbow = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::RIGHT_ELBOW);
	const auto r_hand = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::RIGHT_HAND);

	const auto l_shoulder = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::LEFT_SHOULDER);
	const auto l_elbow = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::LEFT_ELBOW);
	const auto l_hand = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::LEFT_HAND);

	const auto pelvis = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::PELVIS);

	const auto stomach = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::STOMACH);

	const auto chest = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::CHEST);

	const auto neck = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::NECK);

	const auto HEAD = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::HEAD);

	const auto Root = SDK::squad::GetBoneLocation((uint64_t)getinstigator->g_Mesh(), SDK::squad::bones::ROOT);


	const auto pelvis1 =
		camera_manager->ProjectWorldToScreen(
			pelvis,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto HEAD1 =
		camera_manager->ProjectWorldToScreen(
			HEAD,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto r_leg_screen =
		camera_manager->ProjectWorldToScreen(
			r_leg,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto l_foot_screen =
		camera_manager->ProjectWorldToScreen(
			l_foot,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto l_knee_screen =
		camera_manager->ProjectWorldToScreen(
			l_knee,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto l_leg_screen =
		camera_manager->ProjectWorldToScreen(
			l_leg,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto r_shoulder_screen =
		camera_manager->ProjectWorldToScreen(
			r_shoulder,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto r_elbow_screen =
		camera_manager->ProjectWorldToScreen(
			r_elbow,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto r_hand_screen =
		camera_manager->ProjectWorldToScreen(
			r_hand,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto l_shoulder_screen =
		camera_manager->ProjectWorldToScreen(
			l_shoulder,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto l_elbow_screen =
		camera_manager->ProjectWorldToScreen(
			l_elbow,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto l_hand_screen =
		camera_manager->ProjectWorldToScreen(
			l_hand,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto pelvis_screen =
		camera_manager->ProjectWorldToScreen(
			pelvis,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto stomach_screen =
		camera_manager->ProjectWorldToScreen(
			stomach,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto chest_screen =
		camera_manager->ProjectWorldToScreen(
			chest,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto neck_screen =
		camera_manager->ProjectWorldToScreen(
			neck,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);



	const auto r_foot_screen =
		camera_manager->ProjectWorldToScreen(
			r_foot,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);

	const auto r_knee_screen =
		camera_manager->ProjectWorldToScreen(
			r_knee,
			utils::maths::vectype2::FRotatorToVector(camera_cache.POV.Rotation),
			utils::maths::vectype2::FVectorToVector(camera_cache.POV.Location),
			camera_cache.POV.FOV);


	rendering::Renderer::GetInstance()->DrawLine(
		{ r_foot_screen.x, r_foot_screen.y }, { r_knee_screen.x, r_knee_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ r_knee_screen.x, r_knee_screen.y }, { r_leg_screen.x, r_leg_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ r_leg_screen.x, r_leg_screen.y }, { pelvis_screen.x, pelvis_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ l_foot_screen.x, l_foot_screen.y }, { l_knee_screen.x, l_knee_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ l_knee_screen.x, l_knee_screen.y }, { l_leg_screen.x, l_leg_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ l_leg_screen.x, l_leg_screen.y }, { pelvis_screen.x, pelvis_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ pelvis_screen.x, pelvis_screen.y }, { stomach_screen.x, stomach_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ stomach_screen.x, stomach_screen.y }, { chest_screen.x, chest_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ chest_screen.x, chest_screen.y }, { neck_screen.x, neck_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ neck_screen.x, neck_screen.y }, { HEAD1.x, HEAD1.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ neck_screen.x, neck_screen.y }, { r_shoulder_screen.x, r_shoulder_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ r_shoulder_screen.x, r_shoulder_screen.y }, { r_elbow_screen.x, r_elbow_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ r_elbow_screen.x, r_elbow_screen.y }, { r_hand_screen.x, r_hand_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine({ neck_screen.x, neck_screen.y }, { l_shoulder_screen.x, l_shoulder_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ l_shoulder_screen.x, l_shoulder_screen.y }, { l_elbow_screen.x, l_elbow_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

	rendering::Renderer::GetInstance()->DrawLine(
		{ l_elbow_screen.x, l_elbow_screen.y }, { l_hand_screen.x, l_hand_screen.y }, { red,green,blue,alpha }, skeleton_thickness_value);

}
SDK::squad::AActor* currentPlayer;

void __stdcall main_cheat_handler()
{
	/* Main Rendering Area */

	if (crosshair)
	{
		rendering::Renderer::GetInstance()->DrawLine({ (float)variables::game_screen_X / 2 - 15, (float)variables::game_screen_Y / 2 }, { (float)variables::game_screen_X / 2 - 5, (float)variables::game_screen_Y / 2 }, { 255.0f, 0.f, 0.f, 255.0f }, 1.5f);
		rendering::Renderer::GetInstance()->DrawLine({ (float)variables::game_screen_X / 2 + 16, (float)variables::game_screen_Y / 2 }, { (float)variables::game_screen_X / 2 + 6, (float)variables::game_screen_Y / 2 }, { 255.0f, 0.f, 0.f, 255.0f }, 1.5f);
		rendering::Renderer::GetInstance()->DrawLine({ (float)variables::game_screen_X / 2, (float)variables::game_screen_Y / 2 - 15 }, { (float)variables::game_screen_X / 2, (float)variables::game_screen_Y / 2 - 5 }, { 255.0f, 0.f, 0.f, 255.0f }, 1.5f);
		rendering::Renderer::GetInstance()->DrawLine({ (float)variables::game_screen_X / 2, (float)variables::game_screen_Y / 2 + 16 }, { (float)variables::game_screen_X / 2, (float)variables::game_screen_Y / 2 + 6 }, { 255.0f, 0.f, 0.f, 255.0f }, 1.5f);
	}

	if (show_fov)
	{
		rendering::Renderer::GetInstance()->DrawCircle({ (float)variables::game_screen_X / 2, (float)variables::game_screen_Y / 2 }, fov_value, { 255.f, 0.f, 0.f, 255.f }, 1.0f);
	}





																						 
	const auto pUWorld = *reinterpret_cast<squad::UWorld**>(variables::squad_image_base + 0x4E36AB8);// 0x4E369B8);

	//rendering::Renderer::GetInstance( )->DrawText_( "pUWorld " + std::to_string( ( std::uintptr_t )pUWorld ), { 200, 200 + 85 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );

	if (!IsValidPtr(pUWorld))
		return;

	const auto pPersistentLevel = pUWorld->g_PersistentLevel();

	//rendering::Renderer::GetInstance( )->DrawText_( "pPersistentLevel " + std::to_string( ( std::uintptr_t )pPersistentLevel ), { 200, 200 + 100 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );

	if (!IsValidPtr(pPersistentLevel))
		return;
	const auto pActorContainer = pPersistentLevel->g_ActorList();

//	rendering::Renderer::GetInstance( )->DrawText_( "pActorContainer " + std::to_string( ( std::uintptr_t )pActorContainer ), { 200, 200 + 115 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );

	if (!IsValidPtr(pActorContainer))
		return;

	const auto pGameInstance = pUWorld->g_GameInstance();

	//	rendering::Renderer::GetInstance( )->DrawText_( "pGameInstance " + std::to_string( ( std::uintptr_t )pGameInstance ), { 200, 200 + 130 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );
	if (!IsValidPtr(pGameInstance))
		return;

	const auto pLocalPlayerContainer = pGameInstance->g_LocalPlayerContainer();

	if (!IsValidPtr(pLocalPlayerContainer))
		return;


	const auto pLocalPlayer = pLocalPlayerContainer[0];

		//rendering::Renderer::GetInstance( )->DrawText_( "pLocalPlayer " + std::to_string( ( std::uintptr_t )pLocalPlayer ), { 200, 200 + 145 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );

	if (!IsValidPtr(pLocalPlayer))
		return;

	const auto pLocalController = pLocalPlayer->g_PlayerController();

//	rendering::Renderer::GetInstance( )->DrawText_( "pLocalController " + std::to_string( ( std::uintptr_t )pLocalController ), { 200, 200 + 160 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );
	if (!IsValidPtr(pLocalController))
		return;


	//const auto p_acharacher = pLocalController->g_ACharacter();
	//rendering::Renderer::GetInstance( )->DrawText_( "p_acharacher " + std::to_string( ( std::uintptr_t )p_acharacher), { 200, 200 + 80 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );
	//if (!p_acharacher)
	//	return;


	const auto localplayer = pLocalController->g_LocalAPawn();

	if (!IsValidPtr(localplayer))
		return;



	//const auto p_inventario = p_acharacher->g_InventoryComponent();
	//rendering::Renderer::GetInstance()->DrawText_("p_inventario " + std::to_string((std::uintptr_t)p_inventario), { 200, 200 + 120 }, { 255.f, 0.f, 0.f, 255.f }, 16.f);

	//if (!p_inventario)
	//	return;
	/*
	const auto p_current = p_inventario->g_CurrentWeapon();
	rendering::Renderer::GetInstance()->DrawText_("p_current " + std::to_string((std::uintptr_t)p_current), { 200, 200 + 140 }, { 255.f, 0.f, 0.f, 255.f }, 16.f);

	if (!p_current)
		return;*/

	const auto pCameraManager = pLocalController->g_CameraManager();

	//rendering::Renderer::GetInstance( )->DrawText_( "pCameraManager " + std::to_string( ( std::uintptr_t )pCameraManager ), { 200, 200 + 190 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );
	if (!IsValidPtr(pCameraManager))
		return;


	//rendering::Renderer::GetInstance( )->DrawText_( "pLocalAPawn " + std::to_string( ( std::uintptr_t )pLocalAPawn ), { 200, 200 + 205 }, { 255.f, 0.f, 0.f, 255.f }, 16.f );

	/*if ( !pLocalAPawn )
		return;*/

	const auto CameraInformation = pCameraManager->g_CameraCache();

	const auto pLocalAPawn = pLocalController->g_LocalAPawn();


	if (!IsValidPtr(pLocalAPawn))
		return;

	const auto pLocalAPlayerState = pLocalAPawn->g_PlayerState();

	if (!IsValidPtr(pLocalAPlayerState))
		return;

	const auto LocalTeamId = pLocalAPlayerState->g_TeamId();

 


	//if (BDelation_Value)
	//{
	//	if (GetAsyncKeyState(VK_SHIFT))
	//	{
	//		pPersistentLevel->SetTimeDilation(Delation_Value);

	//		/*
	//			 auto prisoner = pLocalController->g_ACharacter();

	//			prisoner->(SDK::FPrisonerTeleportRequest*)& request(tpRequest);*/

	//			//std::printf("%f \n", Delation_Value);
	//	}
	//	else {

	//		pPersistentLevel->SetTimeDilation(1.f);

	//	}
	//
	//}
	////static auto fnK2_TeleportTo = (void(*)(SDK::squad::AActor * actor, utils::maths::vectype2::FVector * OriginZeroBased, utils::maths::vectype2::FVector * ShootDir))(variables::squad_image_base + 0x1B9D80);
	////
	////	if (!fnK2_TeleportTo)
	////		return;

	for (int Id = 0; Id < pPersistentLevel->g_ActorCount(); Id++)
	{
		const auto curr_actor = pActorContainer[Id];


		if (!IsValidPtr(curr_actor))
			continue;




		const auto root_comp = curr_actor->g_ActorRootComponent();


		if (!IsValidPtr(root_comp))
			continue;
	

		 auto EnemyPos = root_comp->g_RelativeLocation();

		const auto screen_location =
			pCameraManager->ProjectWorldToScreen(
				utils::maths::vectype2::FVectorToVector(EnemyPos),
				utils::maths::vectype2::FRotatorToVector(CameraInformation.POV.Rotation),
				utils::maths::vectype2::FVectorToVector(CameraInformation.POV.Location),
				CameraInformation.POV.FOV);

	///	if (GetAsyncKeyState(VK_F1))
	//		rendering::Renderer::GetInstance()->DrawNameTag("merda", { screen_location.x, screen_location.y }, { 255.f, 0.f, 0.f, 255.f }, 100, false, 100);
		 

		const auto actor_id = curr_actor->g_ActorId();
		if (!actor_id)
			continue;
		

		//	std::printf("# %f #%f #%f\n", EnemyPos.x, EnemyPos.y, EnemyPos.z);


	/*	const auto actor_pawn = curr_actor->g_ActorInstigator();
	
		if (!actor_pawn)
			continue;*/




		const auto actor_distance = utils::maths::vectype2::FVectorToVector(EnemyPos).distance(utils::maths::vectype2::FVectorToVector(CameraInformation.POV.Location)) / 100;

		char g_name[256];
		if (!GetNameById(actor_id, g_name, sizeof(g_name)))
			return;


		if (esp_max && actor_distance <= esp_min_distance && actor_distance >= esp_max_distance)
			continue;



		bool is_visible_player = SDK::squad::LineOfSightTo(pLocalController, curr_actor); 

		if (esp_projectile)
		{
			if (std::string(g_name).find(xorstr_("BP_Projectile")) != std::string::npos || std::string(g_name).find(xorstr_("Proj2")) != std::string::npos)
			{
				rendering::Renderer::GetInstance()->DrawNameTag(xorstr_("°"), { screen_location.x, screen_location.y }, { 255.f, 0.f, 0.f, 255.f }, actor_distance, false, 0);


				continue;
			}
		}

		if (esp_vans && std::string(g_name).find(xorstr_("Logi")) != std::string::npos)
		{
			rendering::Renderer::GetInstance()->DrawNameTag((xorstr_(" Vehicle Van  ")), { screen_location.x, screen_location.y }, { 255.f, 255.f, 0.f, 255.f }, actor_distance, false, 0);

			continue;
		}

		if (esp_helicopters)
		{
			if (std::string(g_name).find(xorstr_("BP_MI8")) != std::string::npos || std::string(g_name).find(xorstr_("BP_UH60")) != std::string::npos)
			{
				rendering::Renderer::GetInstance()->DrawNameTag(xorstr_(" Vehicle Helicopter  "), { screen_location.x, screen_location.y }, { 0.f, 0.f, 255.f, 255.f }, actor_distance, false, 0);


				continue;
			}
		}

		if (esp_tanks && std::string(g_name).find(xorstr_("BP_T72B3")) != std::string::npos)
		{
			rendering::Renderer::GetInstance()->DrawNameTag(xorstr_("Vehicle Tank"), { screen_location.x, screen_location.y }, { 255.f, 0.f, 255.f, 255.f }, actor_distance, false, 0);


			continue;
		}

		if (esp_btr)
		{
			if (std::string(g_name).find(xorstr_("BP_BTR")) != std::string::npos
				|| std::string(g_name).find(xorstr_("BP_LAV6")) != std::string::npos
				|| std::string(g_name).find(xorstr_("BP_TAPV")) != std::string::npos
				|| std::string(g_name).find(xorstr_("BP_M1126")) != std::string::npos)
			{
				rendering::Renderer::GetInstance()->DrawNameTag(xorstr_("Vehicle BTR"), { screen_location.x, screen_location.y }, { 255.f, 50.f, 50.f, 255.f }, actor_distance, false, 0);

				continue;
			}
		}

		if (esp_atvs)
		{
			if (std::string(g_name).find(xorstr_("BP_MATV")) != std::string::npos)
			{
				rendering::Renderer::GetInstance()->DrawNameTag(xorstr_("Vehicle ATV"), { screen_location.x, screen_location.y }, { 50.f, 255.f, 0.f, 255.f }, actor_distance, false, 0);

				continue;
			}
		}

		if (esp_radios && std::string(g_name).find(xorstr_("BP_FOBRadio")) != std::string::npos)
		{
			rendering::Renderer::GetInstance()->DrawNameTag(xorstr_("FOB Radio"), { screen_location.x, screen_location.y }, { 25.f, 45.f, 4255.f, 255.f }, actor_distance, false, 0);


			continue;
		}

		if (esp_fobs && std::string(g_name).find(xorstr_("_Hab_")) != std::string::npos)
		{
			rendering::Renderer::GetInstance()->DrawNameTag(xorstr_(" Team FOB  "), { screen_location.x, screen_location.y }, { 192.f, 49.f, 12.f, 255.f }, actor_distance, false, 0);


			continue;
		}



		const auto actor_pawn = curr_actor->g_ActorInstigator();

		if (!actor_pawn)
			continue;

		const auto actor_player_state = actor_pawn->g_PlayerState();

		if (!actor_player_state)
			continue;

		const auto actor_team_id = actor_player_state->g_TeamId();
		if (!actor_team_id)
			continue;

		//	utils::maths::vectype2::FVector shot = { 0,0,0 };


	
			/*if (test1)
				fnK2_TeleportTo(curr_actor, &shot, &shot);
*/




		/*if ((uintptr_t)curr_actor == (uintptr_t)(localplayer))
			continue;
	*/
	 
		 


		if (esp_player_tag && std::string(g_name).find(xorstr_("BP_Soldier")) != std::string::npos)
		{
			const auto actor_health = curr_actor->g_ActorHealth();

			// std::printf("%llx", actor_health);

		
				if (actor_health >= 0.1f && actor_health < 200.f)
				{
					 
					 
					if (actor_team_id != LocalTeamId)
					{

					if (is_visible_player) {

						if (esp_player_skeleton) {

							red = 0;
							green = 255;
							blue = 0;
							render_skeleton(curr_actor, pCameraManager);
						}

						if (toogle_2dbox)
						{
							//rendering::Renderer::GetInstance()->DrawNameTag("      ", { screen_location.x, screen_location.y  }, { 0, 255, 0.f, 255.f }, actor_distance, true, actor_health);

							rendering::Renderer::GetInstance()->DrawNameTag(xorstr_(""), { screen_location.x, screen_location.y }, { 255, 255, 0.f, 255.f }, actor_distance, true, actor_health);
							//rendering::Renderer::GetInstance()->DrawNameTag(" ", { screen_location.x+5, screen_location.y+5 }, { 255, 255, 0.f, 255.f }, Health, true, actor_distance);

						}
						valid_players.push_back(curr_actor);

					}

					if (!is_visible_player) {

						if (toogle_2dbox)
						{
							rendering::Renderer::GetInstance()->DrawNameTag(xorstr_(""), { screen_location.x, screen_location.y }, { 255, 255, 0.f, 255.f }, actor_distance, true, actor_health);

							//rendering::Renderer::GetInstance()->DrawNameTag("    ", { screen_location.x, screen_location.y + 5 }, { 255, 0, 0.f, 255.f }, actor_distance, true, actor_health);


						}
						if (esp_player_skeleton) {

							red = 255;
							green = 0;
							blue = 0;


							render_skeleton(curr_actor, pCameraManager);
						}

					}
				}
			}


		}

	}


	if (Aimboot) {
		Vg(pLocalController, pCameraManager);

	}
	if (pelsvis) {
		pelv(pLocalController, pCameraManager);

	}
	if (chest) {
		Ches(pLocalController, pCameraManager);

	}
	end:
	valid_players.clear();

//	Eas(pLocalController);

	return;
}

HRESULT __stdcall my_present(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT flags)
{
	if (!variables::renderer_intialized)
	{
		rendering::temp::g_pSwapChain = pSwapChain;

		if (SUCCEEDED(rendering::temp::g_pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)(&rendering::temp::g_pd3dDevice))))
		{
			//std::printf( "[#] Success 1\n" );
			rendering::temp::g_pd3dDevice->GetImmediateContext(&rendering::temp::g_pd3dDeviceContext);
		}

		ID3D11Texture2D* renderTargetTexture = nullptr;
		if (SUCCEEDED(rendering::temp::g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<PVOID*>(&renderTargetTexture))))
		{
			//std::printf( "[#] Success 2\n" );

			if (SUCCEEDED(rendering::temp::g_pd3dDevice->CreateRenderTargetView(renderTargetTexture, NULL, &rendering::temp::g_mainRenderTargetView)))
			{
				//std::printf( "[#] Success 3\n" );
			}

			renderTargetTexture->Release();
		}

		UINT viewport_count = 1;
		D3D11_VIEWPORT viewport;
		rendering::temp::g_pd3dDeviceContext->RSGetViewports(&viewport_count, &viewport);
		variables::game_screen_X = viewport.Width;
		variables::game_screen_Y = viewport.Height;

		ImGui::CreateContext();
		ImGui_ImplDX11_Init(variables::window_handle, rendering::temp::g_pd3dDevice, rendering::temp::g_pd3dDeviceContext);
		rendering::Renderer::GetInstance()->Initialize();
		ImGui_ImplDX11_CreateDeviceObjects();
		//MenuDesignInterface();

		LoadDirectXTexture(&texture_logo, &logo_width, &logo_height);

		variables::renderer_intialized = true;
	}

	rendering::temp::g_pd3dDeviceContext->OMSetRenderTargets(1, &rendering::temp::g_mainRenderTargetView, NULL);

	ImGui_ImplDX11_NewFrame();

	rendering::Renderer::GetInstance()->BeginScene();

	main_cheat_handler();

	rendering::Renderer::GetInstance()->EndScene();

	if (GetAsyncKeyState(VK_INSERT) & 1) {
		toggle_menu = !toggle_menu;
	}

	if (toggle_menu)
		BuildMenuMain();
	else
		ImGui::GetIO().MouseDrawCursor = false;

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return rendering::o_pPresent(pSwapChain, SyncInterval, flags);
}
void allocate_consowwle()
{
	AllocConsole();
	freopen(xorstr_("CONOUT$"), "w", stdout);
}

void __stdcall init_cheat()
{
	//allocate_consowwle();

	variables::squad_image_base = (unsigned __int64)GetModuleHandle(nullptr);
	GetModuleInformation(GetCurrentProcess(), (HMODULE)variables::squad_image_base, &variables::squad_module_info, sizeof(variables::squad_module_info));

	variables::window_handle =
		FindWindowA(variables::window_class_name, NULL);



	if (rendering::CreateDeviceD3D(variables::window_handle) == E_FAIL)
	{
		rendering::CleanupDeviceD3D();
		return;
	}

	const auto pSwapchain =
		reinterpret_cast<std::uintptr_t*>(rendering::g_pSwapChain);

	const auto pSwapChainVT =
		reinterpret_cast<std::uintptr_t*>(pSwapchain[0]);

	//std::printf( "[#] pSwapchain %p\n", pSwapchain );

	rendering::o_pPresent
		= reinterpret_cast<rendering::tD3D11Present>(pSwapChainVT[8]);

	oriWndProc = (WNDPROC)SetWindowLongPtr(variables::window_handle, GWLP_WNDPROC, (DWORD_PTR)hWndProc);

	utils::hooks::Hooker::GetInstance().HookFunction(reinterpret_cast<PVOID*>(&rendering::o_pPresent), my_present);

 
	//while ( !variables::renderer_exit )
		//Sleep( 100 );

	//utils::hooks::Hooker::GetInstance( ).UnhookFunction( reinterpret_cast< PVOID* >( &rendering::o_pPresent ), my_present );
	//fclose( reinterpret_cast< FILE* >( stdout ) );
	//FreeConsole( );
	//FreeLibraryAndExitThread( variables::current_module_handle, EXIT_SUCCESS );
	return;
}

HANDLE m_HTimeQueue;
HANDLE m_hTimerQueueTimer;

void __stdcall CallbackRoutine(PVOID param, BOOLEAN TimeOrWaitFired)
{
	while (!GetModuleHandleA(xorstr_("d3d11.dll")))
	{
		Sleep(10);
	}

	init_cheat();
}

bool __stdcall DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == 1)
	{
		variables::current_module_handle = hModule;

		if (!CreateTimerQueueTimer(&m_hTimerQueueTimer, m_HTimeQueue, CallbackRoutine, 0, 1000, 0, WT_EXECUTEDEFAULT))
		{
			m_HTimeQueue = NULL;
			m_hTimerQueueTimer = NULL;
			MessageBoxA(nullptr, xorstr_("Client"), xorstr_("Failed Timer"), MB_OK);
			return false;
		}
	}

	return TRUE;
}




