#pragma once

namespace lab4
{
	void TestPoint();

	class Point
	{
	public:
		Point(float x, float y);
		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;

		inline void SetX(const float x) { _x = x; }
		inline void SetY(const float y) { _y = y; }

		inline float GetX() const { return _x; }
		inline float GetY() const { return _y; }

		void Print() const;

	private:
		float _x;
		float _y;
	};

	// Point p6 = operator*(2.f, p2);
	Point operator*(float operand, const Point& point);

} // namespace lab4