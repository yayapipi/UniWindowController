#pragma once

#ifdef LIBUNIWINC_EXPORTS
#define UNIWINC_API __stdcall
#define UNIWINC_EXPORT extern "C" __declspec(dllexport)
#else
#define UNIWINC_API __stdcall
#define UNIWINC_EXPORT extern "C" __declspec(dllimport)
#endif


// Maximum monitor number that this library could be handle
#define UNIWINC_MAX_MONITORCOUNT 32

// Size of a buffer to keep dropped file paths
#define UNIWINC_MAX_PATHBUFFER 2048


// Methods to transparent the window
enum TransparentType : int {
	None = 0,
	Alpha = 1,
	ColorKey = 2
};

using FileDropHandler = void(*)(LPWSTR);


UNIWINC_EXPORT BOOL UNIWINC_API IsActive();
UNIWINC_EXPORT BOOL UNIWINC_API IsTransparent();
UNIWINC_EXPORT BOOL UNIWINC_API IsBorderless();
UNIWINC_EXPORT BOOL UNIWINC_API IsTopmost();
UNIWINC_EXPORT BOOL UNIWINC_API IsMaximized();

UNIWINC_EXPORT BOOL UNIWINC_API AttachMyWindow();
UNIWINC_EXPORT BOOL UNIWINC_API AttachMyOwnerWindow();
UNIWINC_EXPORT BOOL UNIWINC_API AttachMyActiveWindow();
UNIWINC_EXPORT BOOL UNIWINC_API DetachWindow();

UNIWINC_EXPORT void UNIWINC_API SetTransparent(const BOOL isTransparent);
UNIWINC_EXPORT void UNIWINC_API SetBorderless(const BOOL isBorderless);
UNIWINC_EXPORT void UNIWINC_API SetTopmost(const BOOL isTopmost);
UNIWINC_EXPORT void UNIWINC_API SetClickThrough(const BOOL isTransparent);
UNIWINC_EXPORT void UNIWINC_API SetMaximized(const BOOL isZoomed);
UNIWINC_EXPORT BOOL UNIWINC_API SetPosition(const float x, const float y);
UNIWINC_EXPORT BOOL UNIWINC_API GetPosition(float* x, float* y);
UNIWINC_EXPORT BOOL UNIWINC_API SetSize(const float width, const float height);
UNIWINC_EXPORT BOOL UNIWINC_API GetSize(float* width, float* height);
UNIWINC_EXPORT INT32 UNIWINC_API GetCurrentMonitor();

// Monitor Info.
UNIWINC_EXPORT INT32 UNIWINC_API GetMonitorCount();
UNIWINC_EXPORT BOOL UNIWINC_API GetMonitorRectangle(const INT32 monitorIndex, float* x, float* y, float* width, float* height);

// Mouse pointer
UNIWINC_EXPORT BOOL UNIWINC_API SetCursorPosition(const float x, const float y);
UNIWINC_EXPORT BOOL UNIWINC_API GetCursorPosition(float* x, float* y);

// File drop
UNIWINC_EXPORT BOOL UNIWINC_API SetAllowDrop(const BOOL bEnabled);
UNIWINC_EXPORT void UNIWINC_API RegisterFileDropCallback(FileDropHandler callback);
UNIWINC_EXPORT void UNIWINC_API UnregisterFileDropCallback();

// Windows only
UNIWINC_EXPORT void UNIWINC_API SetTransparentType(const TransparentType type);
UNIWINC_EXPORT void UNIWINC_API SetKeyColor(const COLORREF color);
UNIWINC_EXPORT HWND UNIWINC_API GetWindowHandle();
UNIWINC_EXPORT DWORD UNIWINC_API GetMyProcessId();
