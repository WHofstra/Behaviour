#include "Vector.h"

Vector::Vector(int x, int y, int z)
	:thisX(&x), thisY(&y), thisZ(&z)
{

}

Vector::~Vector()
{

}

int Vector::X()
{
	return *thisX;
}

int Vector::Y()
{
	return *thisY;
}

int Vector::Z()
{
	return *thisZ;
}

void Vector::SetVector(int x, int y, int z)
{
	thisX = &x;
	thisY = &y;
	thisZ = &z;
}
