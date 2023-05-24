
#include "ForceGenerator.h"
#include "../Engine/body.h"

void ForceGenerator::Draw(Graphics* graphics)
{
	if (m_body) m_body->Draw(graphics);
}
