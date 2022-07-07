#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"

// Handle to the window
HWND hwnd = NULL;

// Name of the window
LPCTSTR WindowName = L"DX12 tutorials";

// Title of the window
LPCTSTR WindowTitle = L"DX12 Window";

// width and height of the window
int Width = 800;
int Height = 600;

// Is window full screen?
bool FullScreen = false;

// Create a window
bool InitializeWindow(HINSTANCE hInstance, int ShowWnd, int width, int height, bool fullscreen);

// main application loop
void mainloop();

// callback function for windows messages;
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);