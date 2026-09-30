#pragma once
#include <string>
#include "glc2d.h"
#include "GameManager.h"
#include "TextureManager.h"
#include "Entity.h"

extern GameManager g_gameManager;

struct Texture
{
	VEC2 scaling;
	int texture;
	int alphaOption;
};

struct Collider
{
	float width;
	float height;
};

enum class Tag
{
	NONE,
	PLAYER,
	ENEMY,
	PLATFORM,
	ITEM
};

class GameObject
{
protected:
	VEC2 m_pos;
	Collider m_collider;
	Tag m_tag;
	bool m_isActive;
	bool m_isTrigger;

	int m_id;

public:
	std::string m_name;
	Texture m_image;

	GameObject();
	virtual ~GameObject();

	virtual int Init(TextureType textureId);
	virtual int Update(float deltaTime) = 0;
	virtual int Render() = 0;
	virtual int Destroy();

	void SetColliderSize();

	float GetLeft() const { return m_pos.x; };
	float GetRight() const { return m_pos.x + m_collider.width; };
	float GetTop() const { return m_pos.y; };
	float GetBottom() const{ return m_pos.y + m_collider.height; };

	VEC2 GetPosition() const { return m_pos; };
	void SetPosition(const VEC2& pos) { m_pos = pos; };

	Collider GetCollider() const { return m_collider;; };
	void SetCollider(const Collider& col) { m_collider = col; };

	bool IsTrigger() const { return m_isTrigger;; };
	void SetTrigger(const bool& isTrigger) { m_isTrigger = isTrigger; };

	Tag GetTag() const { return m_tag;; };
	void SetTag(const Tag& tag) { m_tag = tag; };

	bool IsActive() const { return m_isActive; };

	int GetTexture() const { return m_image.texture; };
	void SetTexture(const TextureType textureId);

	VEC2 GetScaling() const { return m_image.scaling; };
	void SetScaling(const VEC2& scale) { m_image.scaling = scale; };

	int GetId() const { return m_id; };
	void SetId(int num) { m_id = num; };
};