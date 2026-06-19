#ifndef ROOMINFO_H
#define ROOMINFO_H
#include "studentinfo.h"
class RoomInfo
{
public:
    RoomInfo(int = 0 , int = 0 , const StudentInfo & = StudentInfo());
    void SetNumber(int);
    void SetDorm(int);
    int GetNumber() const ;
    int GetDorm() const ;
    StudentInfo GetStudent() const ;
    bool isOccupied() const;
    void assignStudent(const StudentInfo &student);
    void removeStudent();
private :
    int number ;
    int Dorm ;
    StudentInfo CurrentStudent ;
};

#endif // ROOMINFO_H
