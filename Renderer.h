#pragma once

#include <dxgi.h>
#pragma comment(lib, "dxguid.lib")
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

#include <DirectXMath.h>

#include <cstdint>
#include <string>
#include <sstream>
#include <vector>

#include "Singletons.h"
#include "imgui-master/imgui.h"
#include "imgui-master/imgui_internal.h"
#include "imgui-master/imgui_impl_dx11.h"
#include "Vector.hpp"
#include "RUDA-BOLD.h"

namespace SDK
{
	namespace rendering
	{
		static ImFont* Mark;
		
		static ImFont* pDefaultFont;
		static ImFont* pRudaFont;

		class Renderer
		{
		public:
			void Initialize( );
			void BeginScene( );
			void DrawScene( );
			void EndScene( );

			static Renderer* GetInstance( );

			ImFont* m_pFont;

			Renderer( );
			~Renderer( );
		//	void DrawNameTag(std::string name, DirectX::XMFLOAT2 screen_position, DirectX::XMFLOAT4 tag_color, float distance, bool healthbar = false, float health = 0.f);
			void DrawLine4(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness = 1.0f);
			void DrawNameTag(std::string name, DirectX::XMFLOAT2 screen_position, DirectX::XMFLOAT4 tag_color, float distance, bool healthbar, float health);	
			void DrawInventoryList( std::vector<std::string> item, std::string name, DirectX::XMFLOAT2 screen_resolution, DirectX::XMFLOAT4 tag_color, float font_size );
			void DrawInventoryList1( std::vector<std::string> item, std::string name, DirectX::XMFLOAT2 screen_resolution, DirectX::XMFLOAT4 tag_color, float font_size );
			void DrawInventoryList2( std::vector<std::string> item, std::string name, DirectX::XMFLOAT2 screen_resolution, DirectX::XMFLOAT4 tag_color, float font_size );
			void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness);

			float DrawMyText( ImFont* pFont, const std::string& text, const DirectX::XMFLOAT2& pos, float size, DirectX::XMFLOAT4 color, bool center );
			void DrawText_( std::string text, DirectX::XMFLOAT2 screen_position, DirectX::XMFLOAT4 tag_color, float font_size );
			void DrawLine( const DirectX::XMFLOAT2& from, const DirectX::XMFLOAT2& to, DirectX::XMFLOAT4 color, float thickness );
			void DrawBox( const DirectX::XMFLOAT2& from, const DirectX::XMFLOAT2& size, DirectX::XMFLOAT4 color, float rounding, float thickness );
			void DrawLine1(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness = 1.0f);

			void DrawBox1(const ImVec2& position, const ImVec2& HeadPosition, uint32_t color);			void DrawBoxFilled(const DirectX::XMFLOAT2& from, const DirectX::XMFLOAT2& size, DirectX::XMFLOAT4 color, float rounding);
			void DrawCircle( const DirectX::XMFLOAT2& from, float radius, DirectX::XMFLOAT4 color, float thickness = 1.f );
			void DrawCircleFilled( const DirectX::XMFLOAT2& from, float radius, DirectX::XMFLOAT4 color );
		private:
			static Renderer* m_pInstance;
		};

		typedef HRESULT(__stdcall* tD3D11Present)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
		typedef HRESULT(__stdcall* ResizeBuffers)(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);
 		static ResizeBuffers resize_buffers_original = nullptr;

		static tD3D11Present o_pPresent = nullptr;

		static ID3D11Device* g_pd3dDevice = NULL;
		static ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
		static IDXGISwapChain* g_pSwapChain = NULL;
		static ID3D11RenderTargetView* g_mainRenderTargetView = NULL;

		namespace temp
		{
			static ID3D11Device* g_pd3dDevice = NULL;
			static ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
			static IDXGISwapChain* g_pSwapChain = NULL;
			static ID3D11RenderTargetView* g_mainRenderTargetView = NULL;
		}

		static void Initialize()
		{
			DXGI_SWAP_CHAIN_DESC sd;
			g_pSwapChain->GetDesc(&sd);

			ID3D11Texture2D* pBackBuffer;
			D3D11_RENDER_TARGET_VIEW_DESC render_target_view_desc;
			ZeroMemory(&render_target_view_desc, sizeof(render_target_view_desc));
			render_target_view_desc.Format = sd.BufferDesc.Format;
			render_target_view_desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
			g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			g_pd3dDevice->CreateRenderTargetView(pBackBuffer, &render_target_view_desc, &g_mainRenderTargetView);
			pBackBuffer->Release();
		}

		static HRESULT CreateDeviceD3D(HWND hWnd)
		{
			DXGI_SWAP_CHAIN_DESC sd;
			{
				ZeroMemory(&sd, sizeof(sd));
				sd.BufferCount = 2;
				sd.BufferDesc.Width = 0;
				sd.BufferDesc.Height = 0;
				sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				sd.BufferDesc.RefreshRate.Numerator = 0;
				sd.BufferDesc.RefreshRate.Denominator = 1;
				sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
				sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				sd.OutputWindow = hWnd;
				//SetWindowDisplayAffinity(sd.OutputWindow, WDA_EXCLUDEFROMCAPTURE);

				sd.SampleDesc.Count = 1;
				sd.SampleDesc.Quality = 0;
				sd.Windowed = TRUE;
				sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
			}

			D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

			//std::printf( "[#] bout to create swapchain \n" );

			if (FAILED(D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, &featureLevel, 1, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, NULL, &g_pd3dDeviceContext)))
			{
				//std::printf( "[#] Failed To Create Device\n" );
				return E_FAIL;
			}

			return S_OK;
		}

		static void CleanupRenderTarget()
		{
			if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
		}

		static void CleanupDeviceD3D()
		{
			CleanupRenderTarget();
			if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
			if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
			if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
		}
	}
}