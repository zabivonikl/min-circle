#include "paint_scene.h"

PaintScene::PaintScene(QObject* parent): QGraphicsScene(parent)
{

}

void PaintScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	addEllipse(event->scenePos().x(), event->scenePos().y(), 7, 7, QPen(Qt::NoPen), QBrush(Qt::red));
	emit newPoint(event->scenePos());
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	emit mouseMove(event->scenePos());
}
