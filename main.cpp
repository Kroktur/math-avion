#include <iostream>
#include <cmath>
enum Direction
{
	Haut = 1
	, Bas
};

class Vec2
{
public:
	Vec2(float x_, float y_) : y(y_), x(x_) {}


	float x;
	float y;

};
std::ostream& operator<<(std::ostream& os, Vec2 v)
{
	return os << "(" << v.x << " ; " << v.y << ")";
}
float getYcoordonate(float x, float r)
{
	float y = r * r - x * x;

	return sqrt(y);
}
Vec2 getCoordonate(float x, float y, int sens)
{

	if (sens == Bas)
		return Vec2{ x,-y };
	else if (sens == Haut)
		return Vec2{ x,y };
	else
		std::cout << "Coordonate  error " << std::endl;

}
int getAngle(float x, float y , float r, int sens)
{

	if (sens == Bas)
	{
		if (x > 0)
			return -(180 - std::acos(y / r) * 180 / 3.1415926535);
		else
			return 180 - std::acos(y / r) * 180 / 3.1415926535;
	}
	else if (sens == Haut)
	{
		if (x > 0)
		return  -(std::acos(y / r) * 180 / 3.1415926535);
		else 
			return  std::acos(y / r) * 180 / 3.1415926535;
	}
		
}


int main()
{
	float y;
	float x;
	float r;
	int sens;
	std::cout << "enter radius : ";
	std::cin >> r;
	std::cout << "enter x position : ";
	std::cin >> x;
	std::cout << "direction : 1(up) 2(down) :";
	std::cin >> sens;
	y = getYcoordonate(x, r);
	std::cout << getCoordonate(x, y, sens) << std::endl;
	std::cout << "angle : " << getAngle(x, y, r, sens) << std::endl;


	return 0;
}
