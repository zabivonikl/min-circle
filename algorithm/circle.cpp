#include "circle.h"
#include <cmath>

Circle::Circle() { }

Circle::Circle(const QPoint& p1, const QPoint& p2)
{
	this->center = (p1 + p2) / 2;
	this->radius = (int) sqrt(pow(p1.x() - center.x(), 2) + pow(p1.y() - center.y(), 2));
}

Circle::Circle(const QPoint& p1, const QPoint& p2, const QPoint& p3)
{
	int x1 = p1.x(), y1 = p1.y();
	int x2 = p2.x(), y2 = p2.y();
	int x3 = p3.x(), y3 = p3.y();

	int A = x2 - x1;
	int B = y2 - y1;
	int C = x3 - x1;
	int D = y3 - y1;
	int E = A * (x1 + x2) + B * (y1 + y2);
	int F = C * (x1 + x3) + D * (y1 + y3);
	int G = 2 * (A * (y3 - y2) - B * (x3 - x2));

	center = QPoint((D * E - B * F) / G, (A * F - C * E) / G);
	radius = (int) sqrt(pow(x1 - center.x(), 2) + pow(y1 - center.y(), 2));
}

bool Circle::isPointInCircle(const QPoint& point) const
{
	return pow(point.x() - center.x(), 2) + pow(point.y() - center.y(), 2) <= pow(radius, 2);
}

QRect Circle::getCircumscribedRect() const
{
    return { center - QPoint(radius, radius), QSize(2 * radius, 2 * radius) };
}

QString Circle::toString() const
{
    return QString("R: %1, x: %2, y: %3")
            .arg(radius)
            .arg(center.x() - 51)
            .arg(center.y() + 14);
}
