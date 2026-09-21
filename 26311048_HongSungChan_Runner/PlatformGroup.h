#pragma once
#include <vector>
#include "Platform.h"
#include "GameObject.h"

class PlatformGroup : public GameObject
{
private:
	std::vector<Platform> m_platforms;
	float m_moveSpeed;

public:
	PlatformGroup();
	~PlatformGroup() override;

	int Update(float deltaTime) override;
	int Render() override;
	int Destroy() override;

	void SetMoveSpeed(const float speed) { m_moveSpeed = speed; };
	float GetMoveSpeed() const { return m_moveSpeed; };

	void SetChildrenPos();

	const std::vector<Platform>& GetPlatforms() const { return m_platforms; };
};