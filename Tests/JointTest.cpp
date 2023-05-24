#include "JointTest.h"
#include "../Engine/CircleShape.h"
#include "../Engine/world.h"
#include "../Engine/Body.h"
#include "../Physics/Joint.h"

#define SPRING_STIFFNESS	100
#define SPRING_LENGTH		2
#define BODY_DAMPING		10
#define CHAIN_SIZE			3

#define CHAIN
//#define NET

void JointTest::Initialize()
{
	Test::Initialize();

	m_anchor = new Body(new CircleShape(0.7f, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_anchor);


#if defined( NET )
	int current = 0;
	auto prevBody2 = m_anchor;
	auto prevBody = m_anchor;
	while (current < CHAIN_SIZE) {

		auto body = new Body(new CircleShape(20, { 0, 1, 0.3, 1 }), { 400, 200 }, { 0, 0 }, 9, Body::DYNAMIC);
		body->damping = BODY_DAMPING;
		m_world->AddBody(body);

		auto body2 = new Body(new CircleShape(17, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 9, Body::DYNAMIC);
		body2->gravityScale = 250;
		body2->damping = BODY_DAMPING;
		m_world->AddBody(body2);

		auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);
		 joint = new Joint(prevBody2, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		joint = new Joint(prevBody2, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);
		joint = new Joint(prevBody, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		 joint = new Joint(body, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody2 = body2;
		prevBody = body;
		current++;
	}
#elif defined ( CHAIN )
	int current = 0;
	auto prevBody = m_anchor;
	while (current < CHAIN_SIZE) {

		auto body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::DYNAMIC);
		body->damping = BODY_DAMPING;
		m_world->AddBody(body);

		auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;
		current++;
	}
#endif

	//body = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
	//body->gravityScale = 250;
	//body->damping = BODY_DAMPING;
	//m_world->AddBody(body);

	//joint = new Joint(body, prevBody, SPRING_STIFFNESS, SPRING_LENGTH);
	//m_world->AddJoint(joint);

}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Renderer()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}
