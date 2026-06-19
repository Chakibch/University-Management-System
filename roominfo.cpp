#include "roominfo.h"
#include "studentinfo.h"
RoomInfo::RoomInfo(int number, int dorm, const StudentInfo &student ) : CurrentStudent(student)
{
    this->SetDorm(dorm);
    this->SetNumber(number);
}
void RoomInfo::SetNumber(int num)
{
    num > 0 && num < 230 ? this->number = num : this->number = 0 ;
}
void RoomInfo::SetDorm(int dorm)
{
    dorm > 0 && dorm < 6 ? this->Dorm = dorm : this->Dorm = 0 ;
}
int RoomInfo::GetDorm() const
{
    return Dorm ;
}
int RoomInfo::GetNumber() const
{
    return number ;
}
StudentInfo RoomInfo::GetStudent() const
{
    return CurrentStudent ;
}
bool RoomInfo::isOccupied() const
{
    return CurrentStudent.getID() != 0;
}

void RoomInfo::assignStudent(const StudentInfo &student)
{
    CurrentStudent = student;
}

void RoomInfo::removeStudent()
{
    CurrentStudent = StudentInfo(); // resets to default (ID=0)
}
