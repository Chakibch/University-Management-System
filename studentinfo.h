#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include <QString>
class StudentInfo
{
private :
    QString name ;
    int ID ;
    int Room ;
    int Dorm ;
    int Year ;
public:
    StudentInfo(int = 0 , int=0 , int=0 , int=0 , QString="");
    void setID(int=0);
    void setRoom(int=0);
    void setDorm(int=0);
    void setYear(int=0);
    void setName(QString="");

    int getID()const;
    int getRoom()const;
    int getYear()const;
    int getDorm()const;
    QString getName()const;
    StudentInfo(const StudentInfo &s) ;
    StudentInfo& operator=(const StudentInfo& other);
};

#endif // STUDENTINFO_H
