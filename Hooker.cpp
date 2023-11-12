#include "Hooker.h"

namespace SDK2
{
	namespace utils
	{
		namespace hooks
		{
			Hooker::Hooker()
			{

			}

			Hooker::~Hooker()
			{

			}

			void __stdcall Hooker::HookFunction(PVOID* destination, PVOID source)
			{
				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourAttach(destination, source);
				DetourTransactionCommit();
			}

			void __stdcall Hooker::UnhookFunction(PVOID* destination, PVOID source)
			{
				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourDetach(destination, source);
				DetourTransactionCommit();
			}

			//template <typename T> T __stdcall Hooker::HookVirtual( void* func, T Hook )
			//{
			//	DWORD oldProtect = 0;
			//	VirtualProtectEx( GetCurrentProcess( ), func, sizeof( uintptr_t ) , PAGE_EXECUTE_READWRITE, &oldProtect );

			//	T original = *( T* )func;
			//	*( T* )func = Hook;

			//	VirtualProtectEx( GetCurrentProcess( ), func, sizeof( uintptr_t ), oldProtect, &oldProtect );

			//	return original;
			//}
		}
	}
}