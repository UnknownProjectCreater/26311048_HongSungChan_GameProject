#pragma once

#include <string>
#include <glc2d.h>
#include <stdio.h>

struct GameMain
{
    POINT winPos{ 200, 100 };
    SIZE winSize{ 1024, 700 };

    int Init();
    int Destroy();
    int Update();
    int Render();
};