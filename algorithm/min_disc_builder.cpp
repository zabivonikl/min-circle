#include "min_disc_builder.h"
#include "../exceptions/not_enough_points_exception.h"
#include "coords_converter.h"

MinDiscBuilder::MinDiscBuilder(CoordsConverter* converter)
{
    coords = new QVector<QPoint>;
    convertedCoords = QVector<QPoint>();
    this->converter = converter;
    rg = QRandomGenerator::global();
}

MinDiscBuilder::~MinDiscBuilder()
{
    delete coords;
    delete rg;
}

void MinDiscBuilder::addPoint(const QPoint& point)
{
    coords->append(point);
}

void MinDiscBuilder::buildCircle()
{
    if (coords->size() < 2) throw NotEnoughPointsException("Not enough points.");
    convertedCoords.clear();
    convertedCoords = converter->centerToLeftBottom(*coords);

    QVector<QPoint> P = getRandomPermutation(convertedCoords);
    circle = Circle(P[0], P[1]);
	for (int i = 2; i < P.size(); i++)
        if (!circle.isPointInCircle(P[i]))
        {
            QVector<QPoint> newP = getSplice(P, i);
            circle = getMinDiscWithPoint(newP, P[i]);
        }
}

QVector<QPoint>& MinDiscBuilder::getRandomPermutation(const QVector<QPoint>& list)
{
    auto* new_list = new QVector<QPoint>(list);
    for (int i = 0; i < new_list->size(); i++)
        new_list->swapItemsAt(i, rg->bounded(0, new_list->size()));
    return *new_list;
}

Circle MinDiscBuilder::getMinDiscWithPoint(const QVector<QPoint>& list, QPoint q1)
{
    QVector<QPoint> P = getRandomPermutation(list);
	Circle D(P[0], q1);
	for (int i = 1; i < P.size(); i++)
		if (!D.isPointInCircle(P[i]))
		{
            QVector<QPoint> newP = getSplice(P, i);
			D = getMinDiscWithTwoPoint(newP, P[i], q1);
		}
	return D;
}

QVector<QPoint> MinDiscBuilder::getSplice(const QVector<QPoint>& list, int count)
{
    QVector<QPoint> newVector;
    for (int i = 0; i < count; i++)
        newVector.append(list[i]);
    return newVector;
}

Circle MinDiscBuilder::getMinDiscWithTwoPoint(const QVector<QPoint>& list, QPoint q1, QPoint q2)
{
    Circle D(q1, q2);
    foreach (auto& point, list)
        if (!D.isPointInCircle(point))
            D = Circle(point, q1, q2);
	return D;
}

QRect MinDiscBuilder::getCircumscribedRect() const
{
    return circle.getCircumscribedRect();
}

QString MinDiscBuilder::getCircleParams() const
{
    return circle.toString();
}

void MinDiscBuilder::reset()
{
    coords->clear();
}
