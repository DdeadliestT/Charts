#pragma once

#include <cmath>

class IFunction
{
protected:    
    // for derivative
    float dy;
    float deltaX;
public:
    IFunction() {};
    
	virtual float GetY(float x) = 0;
    
    float GetDerivativeY(float x, float deltaX);
    float GetAntiderivativeY(float a, float b, float h);
};
