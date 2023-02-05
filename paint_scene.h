#ifndef PAINT_SCENE_H
#define PAINT_SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class PaintScene : public QGraphicsScene
{
Q_OBJECT
public:
    explicit PaintScene(QObject* parent = nullptr);

private:
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

signals:
	void newPoint(QPointF cursorPos);

	void mouseMove(QPointF cursorPos);
};

#endif // PAINT_SCENE_H
