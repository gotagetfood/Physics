#include "ParticleTest.h"
#include "../Engine/body.h"
#include "../Engine/CircleShape.h"

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(50, 200);
		auto body = new Body( new CircleShape(randomf(5, 50), { randomf(), randomf(), randomf(), 1 }),  m_input->GetMousePosition(), velocity);
		body->damping = 1;
		m_world->AddBody(body);
	}

}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Renderer()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
}
