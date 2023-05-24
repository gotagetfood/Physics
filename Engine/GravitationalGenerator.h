#pragma once
#include "../Physics/ForceGenerator.h"
#include <list>

class GravitationalGenerator : public ForceGenerator
{
public:
	GravitationalGenerator(float strength) : m_strength{ strength } {}

	void Apply(std::vector<class Body*> bodies) override;

public:
	float m_strength{ 0 };

};