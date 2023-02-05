#include "not_enough_points_exception.h"


NotEnoughPointsException::NotEnoughPointsException(const char* message): QException()
{
    this->message = QString(message);
}

NotEnoughPointsException::NotEnoughPointsException(const NotEnoughPointsException& other): QException()
{
    this->message = other.getMessage();
}

QString NotEnoughPointsException::getMessage() const
{
	return message;
}
