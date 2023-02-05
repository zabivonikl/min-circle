#include <QException>
#include <QString>

class NotEnoughPointsException : public QException
{
    QString message;

public:
    explicit NotEnoughPointsException(const char* message = "Not enough points");

    NotEnoughPointsException(const NotEnoughPointsException& other);

    QString getMessage() const;
};
