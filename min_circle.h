#include <QTimer>
#include <QMainWindow>
#include "paint_scene.h"
#include "algorithm/min_disc_builder.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
	class MinCircle;
}
QT_END_NAMESPACE

class MinCircle : public QMainWindow
{
Q_OBJECT

public:
	explicit MinCircle(QWidget* parent = nullptr);
	~MinCircle() override;

protected:
    void resizeEvent(QResizeEvent* event) override;
    void showEvent(QShowEvent* event) override;

private slots:

	void on_clearButton_clicked();

	void onNewPoint(QPointF cursorPos);

	void onMouseMove(QPointF p);

	void on_calculateButton_clicked();

private:
	Ui::MinCircle* ui;
	PaintScene* scene;
    QGraphicsEllipseItem* currentCircle;

    MinDiscBuilder* discBuilder;
    CoordsConverter* coordsConverter;
};
