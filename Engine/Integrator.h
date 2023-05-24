#pragma once
#include "body.h"

namespace Integrator {
	
	
	void ExplicitEuler(Body& body, float dt) {
		glm::vec2 acceleration = (body.force * body.invMass);

		body.position += body.velocity * dt;
		body.velocity += acceleration * dt;
	}

	void SemiImplicitEuler(Body& body, float dt) {
		glm::vec2 acceleration = (body.force * body.invMass);

		body.velocity += acceleration * dt;
		body.position += body.velocity * dt;
	
	}

	
}