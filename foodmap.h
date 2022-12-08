#ifndef FOODMAP_H
#define FOODMAP_H

#include <vector>
#include "food.h"


class FoodMap
{
public:

    FoodMap();
    ~FoodMap();

    void update();
    void clear();
    void eat_food(int i);
    void populate_food(int amountOfFood);
    void add_user_food(double x, double y);
    void create_sushi_roll(double xCor, double yCor);

    const std::vector<Food>& get_food() const;

protected:

    std::vector<std::vector<int>> foodGrid;
    std::vector<Food> foodList;

    int amountOfExtraFood{9};


    void create_9_by_9_food_square(double xCor, double yCor);
    void remove_empty_food();

};

#endif // FOODMAP_H
