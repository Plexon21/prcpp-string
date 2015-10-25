#pragma once
class Point {
	int m_x, m_y;
public: Point(int x = 0, int y = 0) { m_x = x; m_y = y; } int getX() const { return m_x; } int getY() const { return m_y; }
		void setX(const int x) { m_x = x; } void setY(const int y) { m_y = y; }
};
class PointArray { size_t m_size, m_capacity; Point *m_points; public: PointArray(); PointArray(const Point pts[], const size_t size); PointArray(const PointArray& pv); ~PointArray(); void clear(); int getSize() const { return m_size; } void print() const; void pushBack(const Point& p); void insert(const size_t pos, const Point& p); void remove(const size_t pos); bool get(const size_t pos, Point& p) const; Point* at(const size_t pos); const Point* at(const size_t pos) const; private: void resize(size_t capacity); }; #pragma once
