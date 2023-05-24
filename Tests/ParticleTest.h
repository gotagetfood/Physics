#pragma once
#include "test.h"

class ParticleTest : public Test
{
public:
	void Initialize() override;

	void Update() override;
	virtual void FixedUpdate() override;
	virtual void Renderer() override;

protected:
	


};
