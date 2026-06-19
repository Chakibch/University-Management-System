#include "restaurantinfo.h"

RestaurantInfo::RestaurantInfo(int dormID)
{
    this->dormID = dormID;
    mealsServedToday = 0;

    // Monday
    breakfast[0] = dormID % 2 == 0 ? "Croissant, Coffee, Orange Juice" : "Bread, Butter, Milk, Honey";
    lunch[0]     = dormID % 2 == 0 ? "Couscous, Chicken, Vegetables" : "Rice, Grilled Fish, Salad";
    dinner[0]    = dormID % 2 == 0 ? "Lentil Soup, Bread, Fruit" : "Pasta, Meatballs, Juice";

    // Tuesday
    breakfast[1] = dormID % 2 == 0 ? "Eggs, Toast, Milk" : "Pancakes, Coffee, Juice";
    lunch[1]     = dormID % 2 == 0 ? "Grilled Chicken, Fries, Salad" : "Couscous, Lamb, Chickpeas";
    dinner[1]    = dormID % 2 == 0 ? "Vegetable Soup, Pasta, Yogurt" : "Grilled Vegetables, Rice, Fruit";

    // Wednesday
    breakfast[2] = dormID % 2 == 0 ? "Chocolate Croissant, Tea, Juice" : "Oatmeal, Milk, Banana";
    lunch[2]     = dormID % 2 == 0 ? "Beef Tajine, Bread, Salad" : "Stuffed Peppers, Rice, Juice";
    dinner[2]    = dormID % 2 == 0 ? "Chicken Soup, Bread, Fruit" : "Spaghetti Bolognese, Salad";

    // Thursday
    breakfast[3] = dormID % 2 == 0 ? "Msemen, Coffee, Honey" : "Eggs, Cheese, Bread, Tea";
    lunch[3]     = dormID % 2 == 0 ? "Grilled Fish, Potatoes, Salad" : "Chicken Tagine, Couscous";
    dinner[3]    = dormID % 2 == 0 ? "Bean Soup, Bread, Yogurt" : "Pizza, Salad, Juice";

    // Friday
    breakfast[4] = dormID % 2 == 0 ? "Baghrir, Butter, Tea" : "Crepes, Jam, Coffee";
    lunch[4]     = dormID % 2 == 0 ? "Lamb Couscous, Vegetables" : "Fried Chicken, Rice, Salad";
    dinner[4]    = dormID % 2 == 0 ? "Harira, Bread, Dates" : "Vegetable Soup, Pasta, Fruit";

    // Saturday
    breakfast[5] = dormID % 2 == 0 ? "Eggs, Bread, Cheese, Juice" : "Waffles, Coffee, Fruit";
    lunch[5]     = dormID % 2 == 0 ? "Grilled Steak, Fries, Salad" : "Seafood Pasta, Bread, Juice";
    dinner[5]    = dormID % 2 == 0 ? "Chicken Soup, Rice, Yogurt" : "Grilled Vegetables, Couscous";

    // Sunday
    breakfast[6] = dormID % 2 == 0 ? "Pancakes, Honey, Milk" : "Msemen, Olive Oil, Tea";
    lunch[6]     = dormID % 2 == 0 ? "Roast Chicken, Potatoes, Salad" : "Lamb Chops, Rice, Vegetables";
    dinner[6]    = dormID % 2 == 0 ? "Pasta, Tomato Sauce, Fruit" : "Harira, Bread, Dates, Fruit";
}
int RestaurantInfo::getDormID() const { return dormID; }

QString RestaurantInfo::getBreakfast(int day) const { return breakfast[day]; }
QString RestaurantInfo::getLunch(int day) const { return lunch[day]; }
QString RestaurantInfo::getDinner(int day) const { return dinner[day]; }

void RestaurantInfo::setBreakfast(int day, const QString &meal) { breakfast[day] = meal; }
void RestaurantInfo::setLunch(int day, const QString &meal) { lunch[day] = meal; }
void RestaurantInfo::setDinner(int day, const QString &meal) { dinner[day] = meal; }

void RestaurantInfo::addMeal() { mealsServedToday++; }
int RestaurantInfo::getMealsToday() const { return mealsServedToday; }
void RestaurantInfo::resetMeals() { mealsServedToday = 0; }