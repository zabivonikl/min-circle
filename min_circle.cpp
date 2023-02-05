#include "min_circle.h"
#include "ui_min_circle.h"
#include "exceptions/not_enough_points_exception.h"

MinCircle::MinCircle(QWidget* parent): QMainWindow(parent), ui(new Ui::MinCircle)
{
	ui->setupUi(this);

    coordsConverter = new CoordsConverter();
    discBuilder = new MinDiscBuilder(coordsConverter);

	scene = new PaintScene();
	scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
	ui->graphicsView->setScene(scene);
	ui->graphicsView->setMouseTracking(true);
    scene->setBackgroundBrush(QColor("black"));

	currentCircle = nullptr;

	connect(scene, SIGNAL(newPoint(QPointF)), this, SLOT(onNewPoint(QPointF)));
    connect(scene, SIGNAL(mouseMove(QPointF)), this, SLOT(onMouseMove(QPointF)));
}

MinCircle::~MinCircle()
{
    delete ui;
}

void MinCircle::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    coordsConverter->updatePaintSceneSize(ui->graphicsView->size());
}

void MinCircle::showEvent(QShowEvent* event)
{
    QMainWindow::showEvent(event);
    coordsConverter->updatePaintSceneSize(ui->graphicsView->size());
}

void MinCircle::onNewPoint(QPointF cursorPos)
{
    discBuilder->addPoint(cursorPos.toPoint());
}

void MinCircle::onMouseMove(QPointF p)
{
    QPointF tmp = coordsConverter->centerToLeftBottom(p.toPoint());
	ui->cursorPositionLabel->setText(QString("Mouse position: %1, %2").arg(tmp.x() - 51).arg(tmp.y() + 14));
}

void MinCircle::on_clearButton_clicked()
{
	scene->clear();
    discBuilder->reset();
	currentCircle = nullptr;
}


void MinCircle::on_calculateButton_clicked()
{
	try
	{
        discBuilder->buildCircle();

        QString circleParams = discBuilder->getCircleParams();
        ui->responseLabel->setText(circleParams);

		if (currentCircle != nullptr)
            scene->removeItem((QGraphicsItem*)currentCircle);

        QRect circumscribedRect = discBuilder->getCircumscribedRect();
        QRect transformedCircumscribedRectangle = coordsConverter->leftTopToCenter(circumscribedRect);
        currentCircle = scene->addEllipse(
            transformedCircumscribedRectangle,
            QPen(Qt::blue),
            QBrush(Qt::transparent)
        );
	}
    catch (const NotEnoughPointsException& err)
	{
        ui->responseLabel->setText(err.getMessage());
	}
}

