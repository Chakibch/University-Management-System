#include "university.h"

University* University::instance = nullptr;

University* University::get()
{
    if (instance == nullptr)
        instance = new University();
    return instance;
}

void University::initRooms()
{
    rooms.clear();
    for (int dorm = 1; dorm <= 5; dorm++)
        for (int room = 1; room <= 230; room++)
            rooms.append(RoomInfo(room, dorm));
}

void University::addStudent(const StudentInfo &s)
{
    students.append(s);
}

void University::removeStudent(int studentID)
{
    for (int i = 0; i < students.size(); i++)
        if (students[i].getID() == studentID)
        {
            students.removeAt(i);
            return;
        }
}

QVector<StudentInfo>& University::getAllStudents()
{
    return students;
}

int University::getTotalStudents() const
{
    return students.size();
}

QVector<RoomInfo>& University::getAllRooms()
{
    return rooms;
}

int University::getTotalRooms() const
{
    return rooms.size();
}

int University::getOccupiedRooms() const
{
    int count = 0;
    for (const RoomInfo &r : rooms)
        if (r.isOccupied()) count++;
    return count;
}

bool University::assignStudentToRoom(int studentID, int roomNumber, int dormID)
{
    for (RoomInfo &r : rooms)
        if (r.GetNumber() == roomNumber && r.GetDorm() == dormID)
        {
            if (r.isOccupied()) return false;
            for (StudentInfo &s : students)
                if (s.getID() == studentID)
                {
                    r.assignStudent(s);
                    return true;
                }
        }
    return false;
}

bool University::removeStudentFromRoom(int roomNumber, int dormID)
{
    for (RoomInfo &r : rooms)
        if (r.GetNumber() == roomNumber && r.GetDorm() == dormID)
        {
            r.removeStudent();
            return true;
        }
    return false;
}

RestaurantInfo& University::getRestaurant(int dormIndex)
{
    return restaurants[dormIndex];
}

University::University()
{
    for (int i = 0; i < 5; i++)
        restaurants[i] = RestaurantInfo(i + 1);
}

int University::getTotalMealsToday() const
{
    int total = 0;
    for (int i = 0; i < 5; i++)
        total += restaurants[i].getMealsToday();
    return total;
}
int University::getOccupiedRoomsInDorm(int dormID) const
{
    int count = 0;
    for (const RoomInfo &r : rooms)
        if (r.GetDorm() == dormID && r.isOccupied()) count++;
    return count;
}

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

void University::saveData()
{
    QJsonArray studentsArray;
    for (const StudentInfo &s : students)
    {
        QJsonObject obj;
        obj["id"]   = s.getID();
        obj["name"] = s.getName();
        obj["year"] = s.getYear();
        obj["dorm"] = s.getDorm();
        obj["room"] = s.getRoom();
        studentsArray.append(obj);
    }

    QJsonObject root;
    root["students"] = studentsArray;

    QJsonDocument doc(root);
    QFile file("data.json");
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(doc.toJson());
        file.close();
    }
}
void University::loadData()
{
    QFile file("data.json");
    if (!file.open(QIODevice::ReadOnly))
        return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject root = doc.object();
    QJsonArray studentsArray = root["students"].toArray();

    students.clear();
    for (const QJsonValue &val : studentsArray)
    {
        QJsonObject obj = val.toObject();
        int id     = obj["id"].toInt();
        QString name = obj["name"].toString();
        int year   = obj["year"].toInt();
        int dorm   = obj["dorm"].toInt();
        int room   = obj["room"].toInt();

        StudentInfo s(id, room, dorm, year, name);
        students.append(s);

        if (room != 0 && dorm != 0)
            assignStudentToRoom(id, room, dorm);
    }
}
