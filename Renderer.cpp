#pragma once
#include "Renderer.h"
#include "xorstr.h"

using namespace SDK::rendering;

Renderer* Renderer::m_pInstance;

Renderer::Renderer( )
{
}

Renderer::~Renderer( )
{
}

void Renderer::Initialize( )
{
	ImGuiIO& io = ImGui::GetIO( );
	ImFontConfig font_cfg;
	Mark = io.Fonts->AddFontFromFileTTF(_("C:\\Windows\\Fonts\\Tahoma.ttf"), 14);
	pRudaFont = io.Fonts->AddFontFromMemoryTTF( &ruda_bold_data, sizeof ruda_bold_data, 14.f );
}

void Renderer::BeginScene( )
{
	ImGuiIO& io = ImGui::GetIO( );

	ImGui::PushStyleVar( ImGuiStyleVar_WindowBorderSize, 0.0f );
	ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { 0.0f, 0.0f } );
	ImGui::PushStyleColor( ImGuiCol_WindowBg, ImVec4( 0.0f, 0.0f, 0.0f, 0.0f ) );
	ImGui::Begin( _("##Backbuffer"), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs );

	ImGui::SetWindowPos( ImVec2( 0, 0 ), ImGuiCond_Always );
	ImGui::SetWindowSize( ImVec2( io.DisplaySize.x, io.DisplaySize.y ), ImGuiCond_Always );

	//ImGuiWindow* window = ImGui::GetCurrentWindow( );
	//window->DrawList->AddRectFilled( ImVec2( 0, 0 ), ImVec2( ImGui::GetIO( ).DisplaySize.x, ImGui::GetIO( ).DisplaySize.y ), ImGui::GetColorU32( ImVec4( .1f, .1f, .1f, 0.1f ) ) );
}

void Renderer::DrawScene( )
{
	ImGuiIO& io = ImGui::GetIO( );
}

void Renderer::EndScene( )
{
	ImGuiWindow* window = ImGui::GetCurrentWindow( );
	window->DrawList->PushClipRectFullScreen( );

	ImGui::End( );
	ImGui::PopStyleColor( );
	ImGui::PopStyleVar( 2 );
}

//void Renderer::DrawNameTag( std::string name, DirectX::XMFLOAT2 screen_position, DirectX::XMFLOAT4 tag_color, float distance, bool healthbar, float health )
//{
//	float end_spacing = 0.f;
//	name = name + " " + std::to_string( ( int )distance ) + "m";
//	unsigned int text_size = name.size( );
//
//	if ( text_size > 13 )
//		end_spacing = 3.f;
//
//	/*ImVec2 textSize = rendering::pDefaultFont->CalcTextSizeA( 13.f, FLT_MAX, 1.0f, name.c_str( ) );*/
//	int tag_width = /*textSize.x;*/  text_size * 6.5f;
//	int tag_width_midpoint = tag_width / 2;
//
//	if ( !healthbar )
//	{
//		/* Gray Frame Background */
//		this->DrawBoxFilled( { screen_position.x - 45.f, screen_position.y - 2.f }, { screen_position.x + tag_width, screen_position.y + 28.f }, { 0.f, 0.f, 0.f, 120.f }, 2.8f );
//
//		/* Color Tag */
//		this->DrawBoxFilled( { screen_position.x - 45.f, screen_position.y - 2.f }, { screen_position.x - 45.f + 4.5f, screen_position.y + 28.f }, tag_color, 2.8f );
//
//		/* Name */
//		ImGuiWindow* window = ImGui::GetCurrentWindow( );
//		window->DrawList->AddText( { screen_position.x - 22.f, screen_position.y + 6.f }, ImGui::GetColorU32( { 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w } ), name.c_str( ) );
//	}
//	else
//	{
//		/* Gray Frame Background */
//		this->DrawBoxFilled( { screen_position.x - tag_width_midpoint - 12.5f, screen_position.y + 3.f }, { screen_position.x + tag_width_midpoint + 12.5f + end_spacing, screen_position.y + 41.f }, { 0.f, 0.f, 0.f, 120.f }, 2.8f );
//
//		/* Healthbar Background */
//		this->DrawBoxFilled( { ( screen_position.x - tag_width_midpoint - 12.5f + 9.5f ) , screen_position.y + 30.f }, { ( screen_position.x + tag_width_midpoint + 12.5f + end_spacing - 9.5f ), screen_position.y + 36.f }, { 226.f, 39.f, 55.f, 255.f }, 1.8f );
//
//		/* Healthbar Filler */
//		auto sections = ( ( screen_position.x - tag_width_midpoint  - 12.5f + 9.5f ) - ( screen_position.x + tag_width_midpoint + 12.5f + end_spacing - 9.5f ) ) / 100.f;
//		auto health_length = sections * health;
//		this->DrawBoxFilled( { ( screen_position.x - tag_width_midpoint - 12.5f + 9.5f ), screen_position.y + 30.f }, { ( screen_position.x + tag_width_midpoint + 12.5f + end_spacing - 9.5f ) - health_length, screen_position.y + 36.f }, { 55.f, 226.f, 39.f, 255.f }, 1.8f );
//
//		/* Color Tag */
//		this->DrawBoxFilled( { screen_position.x - tag_width_midpoint - 12.5f, screen_position.y + 3.f }, { ( screen_position.x - tag_width_midpoint - 12.5f ) + 4.5f, screen_position.y + 41.f }, tag_color, 2.8f );
//
//		/* Name */
//		ImGuiWindow* window = ImGui::GetCurrentWindow( );
//		window->DrawList->AddText( 
//			{ ( screen_position.x - tag_width_midpoint ), screen_position.y + 11.f }, 
//			ImGui::GetColorU32( { 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w } ), 
//			name.c_str( )/*, 0, rendering::pRudaFont, 12.f*/ );
//	}
//}
void Renderer::DrawLine4(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddLine(from, to, ImGui::GetColorU32(ImVec4(r / 255, g / 255, b / 255, a / 255)), thickness);
}
void Renderer::DrawNameTag(std::string name, DirectX::XMFLOAT2 screen_position, DirectX::XMFLOAT4 tag_color, float distance, bool healthbar, float health)
{
	name = name + " " + std::to_string((int)distance) + "m";
	unsigned int text_size = name.size();

	if (!healthbar)
	{
		auto width_full_tag = ImGui::CalcTextSize(name.c_str());
		auto width_half = width_full_tag.x / 2;

		/* Gray Frame Background */
	//	this->DrawBoxFilled({ screen_position.x - width_half - 10.f, screen_position.y + 3.f }, { screen_position.x + width_half + 10.f, screen_position.y + 28.f }, { 0.f, 0.f, 0.f, 120.f }, 2.8f);

		/* Color Tag */
		//this->DrawBoxFilled({ screen_position.x - width_half - 10.f, screen_position.y + 3.f }, { screen_position.x - width_half - 10.f + 4.5f, screen_position.y + 28.f }, tag_color, 2.8f);

		/* Name */
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		window->DrawList->AddText({ screen_position.x - width_half + 5.f, screen_position.y + 10.f }, ImGui::GetColorU32({ tag_color.x / 255.f,tag_color.y / 255.f,tag_color.z / 255.f,tag_color.w / 255.f }), name.c_str());
	}
	else
	{
		auto width_full_tag = ImGui::CalcTextSize(name.c_str());
		auto width_half = width_full_tag.x / 2;

		/* Gray Frame Background */
//		this->DrawBoxFilled({ screen_position.x - width_half - 10.f, screen_position.y + 3.f }, { screen_position.x + width_half + 10.f, screen_position.y + 41.f }, { 0.f, 0.f, 0.f, 120.f }, 2.8f);

		/* Healthbar */
		this->DrawBoxFilled({ screen_position.x - width_half + 5.f, screen_position.y + 30.f }, { screen_position.x + width_half, screen_position.y + 36.f }, { 226.f, 39.f, 55.f, 255.f }, 1.8f);

		auto sections = (((screen_position.x - width_half + 5.f)) - ((screen_position.x + width_half))) / 100.f;

		auto health_length = sections * health;

		this->DrawBoxFilled({ screen_position.x - width_half + 5.f, screen_position.y + 30.f }, { (screen_position.x - width_half + 5.f) - health_length, screen_position.y + 36.f }, { 55.f, 226.f, 39.f, 255.f }, 1.8f);

		/* Color Tag */
		//	this->DrawBoxFilled({ screen_position.x - width_half - 10.f, screen_position.y + 3.f }, { screen_position.x - width_half - 10.f + 4.5f, screen_position.y + 41.f }, tag_color, 2.8f);

		/* Name */
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		window->DrawList->AddText({ screen_position.x - width_half + 5.f, screen_position.y + 10.f }, ImGui::GetColorU32({ tag_color.x / 255.f,tag_color.y / 255.f,tag_color.z / 255.f,tag_color.w / 255.f }), name.c_str());
	}
}



void Renderer::DrawText_( std::string text, DirectX::XMFLOAT2 screen_position, DirectX::XMFLOAT4 tag_color, float font_size )
{
	ImGuiWindow* window = ImGui::GetCurrentWindow( );
	window->DrawList->AddText( { screen_position.x, screen_position.y }, ImGui::GetColorU32( { tag_color.x /255.f  ,  tag_color.y / 255.f  , tag_color.z / 255.f  , tag_color.w / 255.f  , } ), text.c_str( ), 0, rendering::pRudaFont, font_size );
}

void Renderer::DrawInventoryList( std::vector<std::string> item, std::string name_str, DirectX::XMFLOAT2 screen_resolution, DirectX::XMFLOAT4 tag_color, float font_size )
{
	/* Gray Frame Background */

		auto y_ = screen_resolution.y / 4.f;
		auto x_ = screen_resolution.x / 6.f;
		auto x__ = screen_resolution.x - x_;
		auto x__x = x__ + 200.f;
		auto mid_point = (x__x - x__) / 2;
		auto list_size = item.size() * 25.f;
		ImVec2 textSize = ImGui::CalcTextSize(name_str.c_str(), 0, false, -1.0f, font_size);
		auto x_text_ = textSize.x / 2;

		float totat_y_text_size = textSize.y + textSize.y + textSize.y + textSize.y;
		for (const auto& name_size : item)
		{
			ImVec2 textSizeitem = ImGui::CalcTextSize(name_size.c_str(), 0, false, -1.0f, font_size);
			totat_y_text_size += textSizeitem.y + 10;
		}

		this->DrawBoxFilled({ x__, y_ }, { x__x, y_ + totat_y_text_size }, { 0.f, 0.f, 0.f, 120.f }, 2.8f);

		/* Color Tag */
		this->DrawBoxFilled({ x__, y_ }, { x__x, y_ + 5.f }, tag_color, 2.8f);

		/* Name */
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		window->DrawList->AddText({ x__x - mid_point - x_text_, y_ + textSize.y + textSize.y }, ImGui::GetColorU32({ 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w }), name_str.c_str(), 0, rendering::pRudaFont, font_size);

		float decrement = textSize.y + textSize.y + textSize.y + textSize.y + textSize.y;

		for (const auto& name : item)
		{
			ImVec2 textSizeitem = ImGui::CalcTextSize(name.c_str(), 0, false, -1.0f, font_size);
			auto x_text_item = textSizeitem.x / 2;
			window->DrawList->AddText({ x__x - mid_point - x_text_item, y_ + decrement }, ImGui::GetColorU32({ 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w }), name.c_str(), 0, rendering::pRudaFont, font_size);
			decrement += textSizeitem.y;
		
	}
}
void Renderer::DrawInventoryList1( std::vector<std::string> item, std::string name_str, DirectX::XMFLOAT2 screen_resolution, DirectX::XMFLOAT4 tag_color, float font_size )
{
	/* Gray Frame Background */

		auto y_ = screen_resolution.y / 4.f;
		auto x_ = screen_resolution.x / -6.f;
		auto x__ = screen_resolution.x - x_;
		auto x__x = x__ + 200.f;
		auto mid_point = (x__x - x__) / 2;
		auto list_size = item.size() * 25.f;
		ImVec2 textSize = ImGui::CalcTextSize(name_str.c_str(), 0, false, -1.0f, font_size);
		auto x_text_ = textSize.x / 2;

		float totat_y_text_size = textSize.y + textSize.y + textSize.y + textSize.y;
		for (const auto& name_size : item)
		{
			ImVec2 textSizeitem = ImGui::CalcTextSize(name_size.c_str(), 0, false, -1.0f, font_size);
			totat_y_text_size += textSizeitem.y + 10;
		}

	//	this->DrawBoxFilled({ x__, y_ }, { x__x, y_ + totat_y_text_size }, { 0.f, 0.f, 0.f, 120.f }, 2.8f);

		/* Color Tag */
	//	this->DrawBoxFilled({ x__, y_ }, { x__x, y_ + 5.f }, tag_color, 2.8f);

		/* Name */
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		//window->DrawList->AddText({ x__x - mid_point - x_text_, y_ + textSize.y + textSize.y }, ImGui::GetColorU32({ 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w }), name_str.c_str(), 0, rendering::pRudaFont, font_size);

		float decrement = textSize.y + textSize.y + textSize.y + textSize.y + textSize.y;

		for (const auto& name : item)
		{
			ImVec2 textSizeitem = ImGui::CalcTextSize(name.c_str(), 0, false, -1.0f, font_size);
			auto x_text_item = textSizeitem.x / 2;
			window->DrawList->AddText({ x__x - mid_point - x_text_item, y_ + decrement }, ImGui::GetColorU32({ 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w }), name.c_str(), 0, rendering::pRudaFont, font_size);
			decrement += textSizeitem.y;
		
	}
}
void Renderer::DrawInventoryList2( std::vector<std::string> item, std::string name_str, DirectX::XMFLOAT2 screen_resolution, DirectX::XMFLOAT4 tag_color, float font_size )
{
	/* Gray Frame Background */

		auto y_ = screen_resolution.y / 4.f;
		auto x_ = screen_resolution.x / 6.f;
		auto x__ = screen_resolution.x - x_;
		auto x__x = x__ + 200.f;
		auto mid_point = (x__x - x__) / 2;
		auto list_size = item.size() * 25.f;
		ImVec2 textSize = ImGui::CalcTextSize(name_str.c_str(), 0, false, -1.0f, font_size);
		auto x_text_ = textSize.x / 2;

		float totat_y_text_size = textSize.y + textSize.y + textSize.y + textSize.y;
		for (const auto& name_size : item)
		{
			ImVec2 textSizeitem = ImGui::CalcTextSize(name_size.c_str(), 0, false, -1.0f, font_size);
			totat_y_text_size += textSizeitem.y + 10;
		}

		this->DrawBoxFilled({ x__, y_ }, { x__x, y_ + totat_y_text_size }, { 0.f, 0.f, 0.f, 120.f }, 2.8f);

		/* Color Tag */
		this->DrawBoxFilled({ x__, y_ }, { x__x, y_ + 5.f }, tag_color, 2.8f);

		/* Name */
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		window->DrawList->AddText({ x__x - mid_point - x_text_, y_ + textSize.y + textSize.y }, ImGui::GetColorU32({ 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w }), name_str.c_str(), 0, rendering::pRudaFont, font_size);

		float decrement = textSize.y + textSize.y + textSize.y + textSize.y + textSize.y;

		for (const auto& name : item)
		{
			ImVec2 textSizeitem = ImGui::CalcTextSize(name.c_str(), 0, false, -1.0f, font_size);
			auto x_text_item = textSizeitem.x / 2;
			window->DrawList->AddText({ x__x - mid_point - x_text_item, y_ + decrement }, ImGui::GetColorU32({ 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w }), name.c_str(), 0, rendering::pRudaFont, font_size);
			decrement += textSizeitem.y;
		
	}
}

float Renderer::DrawMyText( ImFont* pFont, const std::string& text, const DirectX::XMFLOAT2& position, float size, DirectX::XMFLOAT4 color, bool center )
{
	ImGuiWindow* window = ImGui::GetCurrentWindow( );

	float a = color.w;
	float r = color.x;
	float g = color.y;
	float b = color.z;

	std::stringstream stream( text );
	std::string line;

	float y = 0.0f;
	int i = 0;

	while ( std::getline( stream, line ) )
	{
		ImVec2 textSize = m_pFont->CalcTextSizeA( size, FLT_MAX, 1.0f, line.c_str( ) );

		if ( center )
		{ 
			window->DrawList->AddText( pFont, size, { ( position.x - textSize.x / 2.0f ) /*+ 1.0f*/, ( position.y + textSize.y * i ) /*+ 1.0f*/ }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );
			window->DrawList->AddText( pFont, size, { ( position.x - textSize.x / 2.0f ) /*- 1.0f*/, ( position.y + textSize.y * i ) /*- 1.0f*/ }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );
			window->DrawList->AddText( pFont, size, { ( position.x - textSize.x / 2.0f ) /*+ 1.0f*/, ( position.y + textSize.y * i ) /*- 1.0f*/ }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );
			window->DrawList->AddText( pFont, size, { ( position.x - textSize.x / 2.0f ) /*- 1.0f*/, ( position.y + textSize.y * i ) /*+ 1.0f*/ }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );

			window->DrawList->AddText( pFont, size, { position.x - textSize.x / 2.0f, position.y + textSize.y * i }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );
		}
		else
		{
			window->DrawList->AddText( pFont, size, { ( position.x ) /*+ 1*/, ( position.y + textSize.y * i ) /*+ 1*/ }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );
			window->DrawList->AddText( pFont, size, { ( position.x ) /*- 1*/, ( position.y + textSize.y * i ) /*- 1*/ }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );
			window->DrawList->AddText( pFont, size, { ( position.x ) /*+ 1*/, ( position.y + textSize.y * i ) /*- 1*/ }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );
			window->DrawList->AddText( pFont, size, { ( position.x ) /*- 1*/, ( position.y + textSize.y * i ) /*+ 1*/ }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );

			window->DrawList->AddText( pFont, size, { position.x, position.y + textSize.y * i }, ImGui::GetColorU32( { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f } ), line.c_str( ) );
		}

		y = position.y + textSize.y * ( i + 1 );
		i++;
	}

	return y;
}


 
 


void Renderer::DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness) {

	float lineW = (W / 3);
	float lineH = (H / 3);

	//black outlines
	/*ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	*/
	//corners

	//outline of esp
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 5);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 5);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 5);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 5);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 5);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 5);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 5);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 5);
	//main line esp
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(255.0, 0, 0, 255)), 3);//RGBA
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(255.0, 0, 0, 255)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(255.0, 0, 0, 255)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(255.0, 0, 0, 255)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(255.0, 0, 0, 255)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(255.0, 0, 0, 255)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(255.0, 0, 0, 255)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(255.0, 0, 0, 255)), 3);
}
void Renderer::DrawLine1(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddLine(from, to, ImGui::GetColorU32(ImVec4(r / 255, g / 255, b / 255, a / 255)), thickness);
}


void Renderer::DrawLine( const DirectX::XMFLOAT2& from, const DirectX::XMFLOAT2& to, DirectX::XMFLOAT4 color, float thickness )
{
	ImGuiWindow* window = ImGui::GetCurrentWindow( );

	window->DrawList->AddLine( ImVec2( to.x, to.y ), ImVec2( from.x, from.y ), ImGui::GetColorU32( ImVec4( color.x / 255, color.y / 255, color.z / 255, color.w / 255 ) ), thickness );
}

void Renderer::DrawBox( const DirectX::XMFLOAT2& from, const DirectX::XMFLOAT2& size, DirectX::XMFLOAT4 color, float rounding, float thickness )
{
	ImGuiWindow* window = ImGui::GetCurrentWindow( );

	window->DrawList->AddRect( ImVec2( from.x, from.y ), ImVec2( size.x, size.y ), ImGui::GetColorU32( ImVec4( color.x / 255, color.y / 255, color.z / 255, color.w / 255 ) ), rounding, 15, thickness );
}
void Renderer::DrawBox1(const ImVec2& pos, const ImVec2& headPosition, uint32_t color)
{
	float width = (headPosition.y + 15 - pos.y) / 4.5f;

	DrawLine1(ImVec2(pos.x - width, pos.y), ImVec2(pos.x + width, pos.y), color, 1.5f);
	DrawLine1(ImVec2(pos.x - width, headPosition.y), ImVec2(pos.x - width, pos.y), color, 1.5f);

	DrawLine1(ImVec2(pos.x + width, headPosition.y), ImVec2(pos.x + width, pos.y), color, 1.5f);
	DrawLine1(ImVec2(pos.x - width, headPosition.y), ImVec2(pos.x + width, headPosition.y), color, 1.5f);
}

void Renderer::DrawBoxFilled( const DirectX::XMFLOAT2& from, const DirectX::XMFLOAT2& size, DirectX::XMFLOAT4 color, float rounding )
{
	ImGuiWindow* window = ImGui::GetCurrentWindow( );

	window->DrawList->AddRectFilled( ImVec2( from.x, from.y ), ImVec2( size.x, size.y ), ImGui::GetColorU32( ImVec4( color.x / 255, color.y / 255, color.z / 255, color.w / 255 ) ), rounding, ImDrawCornerFlags_All );
}

void Renderer::DrawCircle( const DirectX::XMFLOAT2& from, float radius, DirectX::XMFLOAT4 color, float thickness )
{
	ImGuiWindow* window = ImGui::GetCurrentWindow( );

	window->DrawList->AddCircle( ImVec2( from.x, from.y ), radius, ImGui::GetColorU32( ImVec4( color.x / 255, color.y / 255, color.z / 255, color.w / 255 ) ), 180, thickness );
}

void Renderer::DrawCircleFilled( const DirectX::XMFLOAT2& from, float radius, DirectX::XMFLOAT4 color )
{
	ImGuiWindow* window = ImGui::GetCurrentWindow( );

	window->DrawList->AddCircleFilled( ImVec2( from.x, from.y ), radius, ImGui::GetColorU32( ImVec4( color.x / 255, color.y / 255, color.z / 255, color.w / 255 ) ), 180 );
}

Renderer* Renderer::GetInstance( )
{
	if ( !m_pInstance )
		m_pInstance = new Renderer( );

	return m_pInstance;
}