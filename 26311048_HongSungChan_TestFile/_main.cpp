
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <glc2d.h>

// link the 2d game library
#if defined(_DEBUG)
#if defined(_M_X64) // 64-bit 아키텍처
#pragma comment(lib, "glc2d_x64_debug.lib")
#elif defined(_M_IX86) // 32-bit 아키텍처
#pragma comment(lib, "glc2d_win32_debug.lib")
#endif
#else
#if defined(_M_X64)
#pragma comment(lib, "glc2d_x64_release.lib")
#elif defined(_M_IX86)
#pragma comment(lib, "glc2d_win32_release.lib")
#endif
#endif

int main()
{
    // SDK 초기화
    g2_InitSdk();

    printf("Starting ...\n\n");

    // 윈도우 생성
    g2_CreateWin(100, 100, 1024, 600, "Hello World");

    // 실행
    g2_Run();

    // 윈도우 해제
    g2_DestroyWin();
}