#include "min_circle.h"

#include <QApplication>

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  MinCircle w;
  w.show();
  return QApplication::exec();
}
