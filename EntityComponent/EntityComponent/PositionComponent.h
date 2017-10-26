#pragma once
#include "Component.h"
#include "BasicTypes.h"

class PositionComponent : public Component
{
public:
	PositionComponent() : pos(0,0) {}
	void setPosition(Point2D p) { this->pos = p; }
private:
	Point2D pos;
};