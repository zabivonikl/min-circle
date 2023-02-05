#include <QPoint>
#include <QRect>
#include <QObject>

struct Circle
{
    QPoint center;
    int radius;

    Circle();

    Circle(const QPoint& p1, const QPoint& p2);

	Circle(const QPoint& p1, const QPoint& p2, const QPoint& p3);

    bool isPointInCircle(const QPoint& point) const;

    QRect getCircumscribedRect() const;

    QString toString() const;
};
