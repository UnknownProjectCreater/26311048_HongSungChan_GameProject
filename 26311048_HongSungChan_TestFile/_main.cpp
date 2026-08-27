#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <glc2d.h>
#include "GameMain.h"

int nTx;

int Update()
{
    

    return 0;
}

int Render()
{
    VEC2 vcPos(0, 0);
    g2_Draw2D(nTx, nullptr, &vcPos);
    return 0;
}
int main()
{
    //엔진을 초기화 한다.
    //엔진 자체
    //엔진이 활동하는 함수포인터 등을 연결
    //각자의 리소스를 초기화
    //Run
    //Destroy

    // SDK 초기화
    g2_InitSdk();

    g2_SetFrameMove(Update);
    g2_SetRender(Render);

    // 윈도우 생성
    g2_CreateWin(100, 100, 1024, 600, "My Window Screen");

    nTx = g2_TextureLoad("Texture/Sq.png");

    // 실행
    g2_Run();

    // 윈도우 해제
    g2_DestroyWin();
}