#include <QMainWindow>
#include <QRandomGenerator>

#include "circle.h"
#include "coords_converter.h"

class MinDiscBuilder
{
    QVector<QPoint>* coords;
    QVector<QPoint> convertedCoords;
    CoordsConverter* converter;
    QRandomGenerator* rg;
    Circle circle;

public:
    MinDiscBuilder(CoordsConverter* converter);

    void addPoint(const QPoint& point);

    void buildCircle();

	QRect getCircumscribedRect() const;

	QString getCircleParams() const;

	void reset();

	~MinDiscBuilder();

private:

    static QVector<QPoint> getSplice(const QVector<QPoint>& list, int count);

    QVector<QPoint>& getRandomPermutation(const QVector<QPoint>& list);

    Circle getMinDiscWithPoint(const QVector<QPoint>& list, QPoint q1);

    static Circle getMinDiscWithTwoPoint(const QVector<QPoint>& list, QPoint q1, QPoint q2);
};
