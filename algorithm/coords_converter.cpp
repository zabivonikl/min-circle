#include "coords_converter.h"

CoordsConverter::CoordsConverter(QSize size)
{
    updatePaintSceneSize(size);
}

CoordsConverter::CoordsConverter(const CoordsConverter& other)
{
    this->size = other.size;
}

QPoint CoordsConverter::centerToLeftBottom(const QPoint& coords) const
{
    return
    {
        +coords.x() + size.width()  / 2,
        -coords.y() + size.height() / 2
    };
}

QVector<QPoint> CoordsConverter::centerToLeftBottom(QVector<QPoint> coords) const
{
    for (auto& coord : coords)
        coord = centerToLeftBottom(coord);
    return coords;
}

QPoint CoordsConverter::leftTopToCenter(const QPoint& coords) const
{
    return
    {
        +coords.x() - size.width()  / 2,
        -coords.y() + size.height() / 2
    };
}

QRect CoordsConverter::leftTopToCenter(const QRect& rect) const
{
    QPoint topLeft = rect.topLeft(), bottomRight = rect.bottomRight();
    QPoint convertedTopLeft = leftTopToCenter(topLeft), convertedBottomRight = leftTopToCenter(bottomRight);
    return QRect { convertedTopLeft, convertedBottomRight };
}

void CoordsConverter::updatePaintSceneSize(QSize paintSceneSize)
{
    this->size = paintSceneSize;
}
