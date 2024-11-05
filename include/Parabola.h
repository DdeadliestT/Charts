#pragma once

#include "IFunction.h"

class Parabola : public IFunction
{
public:
    Parabola() {};
	virtual float GetY(float x) override;
};
