#include "geometry.h"
#include <iostream>

using namespace std;

PointArray::PointArray()
	: m_size(0)
	, m_capacity(0)
	, m_points(nullptr)
{
}

//const size bringt nichts
PointArray::PointArray(const Point ptsToCopy[], size_t size)
	: m_size(size)
	, m_capacity(size)
	, m_points(nullptr)
{
	m_points = new Point[size];
	for (size_t i = 0; i < size; i++)
	{
		m_points[i] = ptsToCopy[i];
	}
}

PointArray::PointArray(const PointArray& otherPointArray)
	:m_size(otherPointArray.m_size)
	, m_capacity(otherPointArray.m_size)
	, m_points(nullptr)
{
	m_points = new Point[otherPointArray.m_size];
	for (size_t i = 0; i < otherPointArray.m_size; i++)
	{
		m_points[otherPointArray.m_size] = otherPointArray.m_points[otherPointArray.m_size];
	}
}
PointArray::~PointArray()
{
	//so wird das ganze array gelöscht, nicht nur der Pointer.
	//size und capacity müssen nicht geleert werden
	delete[] m_points;
}
void PointArray::clear() {
	resize(0);
}

void PointArray::pushBack(const Point& p) {
	if (m_size == m_capacity)resize(3 * m_size / 2 + 1);
	m_points[m_size++];
}

void PointArray::insert(const size_t pos, const Point& p) {
	if (m_size == m_capacity)resize(3 * m_size / 2 + 1);
	for (size_t i = m_size; i > pos;i--)
	{
		m_points[i] = m_points[i - 1];
	}
	m_points[pos] = p;
	m_size++;
}
void PointArray::resize(size_t newCapacity) {
	m_capacity = newCapacity;
	if (newCapacity < m_size)m_size = newCapacity;
	Point *pts = new Point[m_capacity];
	for (size_t i = 0; i < m_size; i++)
	{
		delete[] m_points; m_points = pts;
	}
}
