#pragma once
#include "GameObject.h"

class Platform : public GameObject
{
public:
	Platform();
	~Platform() override;

	int Update(float deltaTime) override;
	int Render() override;
};

