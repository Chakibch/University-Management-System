#include "studentinfo.h"

StudentInfo::StudentInfo(int id, int room, int dorm, int year, QString name)
{
    this->ID = id;
    this->Room = room;
    this->Dorm = dorm;
    this->Year = year;
    this->name = name;
}
StudentInfo::StudentInfo(const StudentInfo &s)
{
    ID = s.getID() ;
    Room = s.getRoom() ;
    Dorm = s.getDorm();
    Year = s.getYear();
    name = s.getName();
}
void StudentInfo::setID(int id)
{
    ID = id;
}

void StudentInfo::setRoom(int room)
{
    Room = room;
}

void StudentInfo::setDorm(int dorm)
{
    Dorm = dorm;
}

void StudentInfo::setYear(int year)
{
    Year = year;
}

void StudentInfo::setName(QString name)
{
    this->name = name;
}

int StudentInfo::getID() const
{
    return ID;
}

int StudentInfo::getRoom() const
{
    return Room;
}

int StudentInfo::getDorm() const
{
    return Dorm;
}

int StudentInfo::getYear() const
{
    return Year;
}

QString StudentInfo::getName() const
{
    return name;
}
StudentInfo& StudentInfo::operator=(const StudentInfo& other)
{
    this->ID = other.getID();
    this->Room = other.getRoom();
    this->Dorm = other.getDorm();
    this->Year = other.getYear();
    this->name = other.getName();
    return *this;
}