#include "../include/IFunction.h"

float IFunction::GetDerivativeY(float x, float deltaX)
{
    this->deltaX = deltaX;
    
    dy = (GetY(x) - GetY(x - deltaX)) / deltaX;
    return dy;
}

float IFunction::GetAntiderivativeY(float a, float b, float h)
{
    int n = ((b - a) / h);
    float sumYi = 0;
    
    for (int k = 1; (k * fabsf(h)) < fabsf(b); k++)
        sumYi += GetY(a + k * h);
    
    float F = (h / 2) * (GetY(a) + GetY(b) + 2 * sumYi);
    
    return F;
}

