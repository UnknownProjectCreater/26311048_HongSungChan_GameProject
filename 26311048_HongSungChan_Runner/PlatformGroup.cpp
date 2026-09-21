#include "PlatformGroup.h"

PlatformGroup::PlatformGroup()
{
    m_moveSpeed = 0;
}

PlatformGroup::~PlatformGroup()
{
}

int PlatformGroup::Update(float deltaTime)
{
    m_pos.x = m_pos.x + m_moveSpeed * deltaTime;

    return 0;
}

int PlatformGroup::Render()
{
    for (Platform& platform : m_platforms)
    {
        platform.Render();
    }

    return 0;
}

int PlatformGroup::Destroy()
{
    for (Platform& platfom : m_platforms)
    {
        platfom.Destroy();
    }

    m_platforms.clear();

    return 0;
}

void PlatformGroup::SetChildrenPos()
{
    for (Platform& platform : m_platforms)
    {
        VEC2 pos(m_pos.x + platform.GetLocalPosition().x, m_pos.y + platform.GetLocalPosition().y);
        platform.SetPosition(pos);
    }
}