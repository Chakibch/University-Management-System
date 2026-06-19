#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "restaurantinfo.h"
#include "roominfo.h"
#include "studentinfo.h"
#include <QVector>

class University
{
public:
    static University* get();

    void addStudent(const StudentInfo &s);
    void removeStudent(int studentID);
    QVector<StudentInfo>& getAllStudents();
    int getTotalStudents() const;

    void initRooms();
    QVector<RoomInfo>& getAllRooms();
    int getTotalRooms() const;
    int getOccupiedRooms() const;

    bool assignStudentToRoom(int studentID, int roomNumber, int dormID);
    bool removeStudentFromRoom(int roomNumber, int dormID);
    University();
    RestaurantInfo& getRestaurant(int dormIndex);
    int getTotalMealsToday() const ;
    int getOccupiedRoomsInDorm(int dormID) const;
    void saveData() ;
    void loadData() ;
private:
    QVector<StudentInfo> students ;
    QVector<RoomInfo> rooms ;
    static University* instance;

    RestaurantInfo restaurants[5];
};

#endif // UNIVERSITY_H
