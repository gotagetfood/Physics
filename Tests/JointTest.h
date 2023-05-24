#pragma once
#include "test.h"

class JointTest : public Test
{
public:
	void Initialize() override;

	void Update() override;
	virtual void FixedUpdate() override;
	virtual void Renderer() override;

protected:
	class Body* m_anchor{ nullptr };


};
