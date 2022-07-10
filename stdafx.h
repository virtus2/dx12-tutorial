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

// this will only call release if an object exists (prevents exceptions calling release on non existant objects)
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }

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

// we will exit the program when this becomes false
bool Running = true;

// Create a window
bool InitializeWindow(HINSTANCE hInstance, int ShowWnd, int width, int height, bool fullscreen);

// main application loop
void mainloop();

// callback function for windows messages;
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// direct3d stuff
const int frameBufferCount = 3; // number of buffers we want, 2 for double buffering, 3 for tripple buffering
ID3D12Device* device; // direct3d device;
IDXGISwapChain3* swapChain; // swapchain used to switch between render targets
ID3D12CommandQueue* commandQueue; // container for commands lists;
ID3D12DescriptorHeap* rtvDescriptorHeap; // a descriptor heap to hold resources like the render targets
ID3D12Resource* renderTargets[frameBufferCount]; // number of render targets equal to buffer count
ID3D12CommandAllocator* commandAllocator[frameBufferCount]; // we want enough allocators for each buffer * number of threads(we only have one thread)
ID3D12GraphicsCommandList* commandList; // a command list we can record commands into, then execute them to render the frame
ID3D12Fence* fence[frameBufferCount]; // an object that is locked while our command list is being executed by the gpu. We need as many
									  // as we have allocators(more if we want to know when the gpu is finished with an asset)
HANDLE fenceEvent; // a handle to an event when our fence is unlocked by gpu
UINT64 fenceValue[frameBufferCount]; // this value is incremented each frame. each fence will have its own value
int frameIndex; // current rtv we are on
int rtvDescriptorSize; // size of the rtv descriptor on the device (all front and back buffers will be the same size)

// function declarations
bool InitD3D(); // initializes direct3d 12

void Update(); // update the game logic

void UpdatePipeline(); // update the direct3d pipeline (update command lists)

void Render(); // execute the command list

void Cleanup(); // release com objects and clean up memory

void WaitForPreviousFrame(); // wait until gpu is finished with command list


