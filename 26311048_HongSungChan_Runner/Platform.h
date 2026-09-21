#pragma once
#include <vector>
#include "GameObject.h"

class Platform : public GameObject
{
private:
	VEC2 m_localPos;

public:
	Platform();
	~Platform() override;

	int Update(float deltaTime) override;
	int Render() override;

	void OnCollision(const GameObject* obj) override;

	VEC2 GetLocalPosition() const { return m_pos; };
	void SetLocalPosition(const VEC2& pos) { m_pos = pos; };
};

