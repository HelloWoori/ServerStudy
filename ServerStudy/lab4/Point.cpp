#include "Point.h"

#include <iostream>
#include <iomanip>

#include "WooriAssert.h"

namespace lab4
{
	void TestPoint()
	{
		// µ¡¼À
		Point p1(2.f, 3.f);
		Point p2(-1.f, 4.f);

		Point p3 = p1 + p2;
		
		WOORI_ASSERT(p3.GetX() == 1.f, "");
		WOORI_ASSERT(p3.GetY() == 7.f, "");

		// »¬¼À
		Point p4 = p2 - p1;
		
		WOORI_ASSERT(p4.GetX() == -3.f, "");
		WOORI_ASSERT(p4.GetY() == 1.f, "");

		// ³»Àû
		float dotProduct = p1.Dot(p2);

		WOORI_ASSERT(dotProduct == 10.f, "");

		// ½ºÄ®¶ó °ö¼À
		Point p6 = 2.f * p2;
		//Point p6 = p2 * 2.f;

		WOORI_ASSERT(p6.GetX() == -2.f, "");
		WOORI_ASSERT(p6.GetY() == 8.f, "");
	}
	
	Point::Point(float x, float y)
		: _x(x), _y(y)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		return Point(_x + other._x, _y + other._y);
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(_x - other._x, _y - other._y);
	}

	float Point::Dot(const Point& other) const
	{
		return (_x * other._x + _y * other._y);
	}

	Point Point::operator*(float operand) const
	{
		return Point(_x * operand, _y * operand);
	}

	void Point::Print() const
	{
		std::cout << "[" << std::setprecision(2) << std::fixed << _x;
		std::cout << ", " << std::setprecision(2) << std::fixed << _y << "]" << "\n";
	}

	Point operator*(float operand, const Point& point)
	{
		return point * operand;
	}
} // namespace lab4