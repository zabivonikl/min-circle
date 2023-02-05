#include <QPoint>
#include <QList>
#include <QSize>
#include <QRect>

#ifndef COORDSCONVERTER_H
#define COORDSCONVERTER_H


class CoordsConverter
{
public:
    explicit CoordsConverter(QSize size = QSize());

    CoordsConverter(const CoordsConverter& other);
    QVector<QPoint> centerToLeftBottom(QVector<QPoint> coords) const;
    QPoint centerToLeftBottom(const QPoint& coords) const;
    QPoint leftTopToCenter(const QPoint& coords) const;
    QRect leftTopToCenter(const QRect& rect) const;

    void updatePaintSceneSize(QSize paintSceneSize);
    ~CoordsConverter() = default;

private:
    QSize size;
};

#endif // COORDSCONVERTER_H
