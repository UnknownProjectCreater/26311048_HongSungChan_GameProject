#pragma once
#include <string>
class Scene
{
public:
	virtual int Init();
	virtual int Update();
	virtual int Render();
	virtual int Destroy();

	std::string sceneName;
};