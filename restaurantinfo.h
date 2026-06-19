#ifndef RESTAURANTINFO_H
#define RESTAURANTINFO_H
#include <QString>

class RestaurantInfo
{
public:
    RestaurantInfo(int dormID = 0);

    int getDormID() const;

    QString getBreakfast(int day) const;
    QString getLunch(int day) const;
    QString getDinner(int day) const;

    void setBreakfast(int day, const QString &meal);
    void setLunch(int day, const QString &meal);
    void setDinner(int day, const QString &meal);
    void addMeal();
    int getMealsToday() const;
    void resetMeals();
private:
    int dormID;
    QString breakfast[7];
    QString lunch[7];
    QString dinner[7];
    int mealsServedToday;
};

#endif // RESTAURANTINFO_H
