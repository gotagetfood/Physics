#include "ForceTest.h"
#include "../Engine/body.h"
#include "../Engine/CircleShape.h"
#include "../Engine/GravitationalGenerator.h"
#include "../Physics/GravitationalForce.h"
#include "../Physics/PointForce.h"
#include "../Physics/DragForce.h"
#include "../Physics/AreaForce.h"

//#define POINT_FORCE
//#define AREA_FORCE
#define DRAG_FORCE
//#define GRAV_FORCE

void ForceTest::Initialize()
{
	Test::Initialize();
	auto forceGeneratorG = new GravitationalGenerator(-200);
	m_world->AddForceGenerator(forceGeneratorG);

#if defined(POINT_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC);
	auto forceGenerator = new PointForce(body, 2000);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(AREA_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC);
	auto forceGenerator = new AreaForce(body, 2000, -90);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(DRAG_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC);
	auto forceGenerator = new DragForce(body, 0.5f);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(GRAV_FORCE) 
	auto forceGenerator = new GravitationalForce(200);
	m_world->AddForceGenerator(forceGenerator);
#endif

	//World::gravity = { 0, 9.8f };
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(50, 200);

		float size = randomf(1, 8);
		auto shape = new CircleShape(size * 3, { randomf(), randomf(), randomf(), 1 });
		auto body = new Body(shape, m_input->GetMousePosition(), velocity);
		body->damping = 1;
		body->gravityScale = 0;
		m_world->AddBody(body);
	}

}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Renderer()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
}
