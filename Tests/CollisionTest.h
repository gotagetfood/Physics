#pragma once
#include "test.h"
#include "../Engine/world.h"

class CollisionTest : public Test
{
public:
	void Initialize() override;

	void Update() override;
	virtual void FixedUpdate() override;
	virtual void Renderer() override;

protected:
	class Body* m_user{ nullptr };

};