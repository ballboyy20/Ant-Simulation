#include "foodmap.h"

FoodMap::FoodMap()
{

}

FoodMap::~FoodMap()
{
    this->clear();
}

void FoodMap::update()
{
    this->remove_empty_food();
}

void FoodMap::clear()
{

    foodList.clear();
}

void FoodMap::eat_food(int i)
{
    foodList[i].decrement_food();
}

void FoodMap::remove_empty_food()
{
    for (int i{0}; i < foodList.size(); i++)
    {
        if (foodList[i].get_strength() <= 0)
        {
            foodList.erase(foodList.begin()+i);
        }
    }
}

void FoodMap::populate_food(int amountOfFood)
{
    for (int i{0}; i < amountOfFood; i++)
    {
        Food tempFood;
        foodList.push_back(tempFood);
        create_9_by_9_food_square(tempFood.get_x_coordinate(), tempFood.get_y_coordinate());
    }
    foodList.resize(amountOfFood * amountOfExtraFood);
}

void FoodMap::add_user_food(double x, double y)
{
    Food tempFood(x,y);
    foodList.push_back(tempFood);

    this->create_9_by_9_food_square(x,y);
}
void FoodMap::create_9_by_9_food_square(double xCor, double yCor)
{    
    int foodSpacer{8};

    Food tempFood1(xCor + foodSpacer, yCor);
    Food tempFood2(xCor + foodSpacer, yCor + foodSpacer);
    Food tempFood3(xCor - foodSpacer, yCor);
    Food tempFood4(xCor - foodSpacer, yCor - foodSpacer);
    Food tempFood5(xCor, yCor + foodSpacer);
    Food tempFood6(xCor + foodSpacer, yCor - foodSpacer);
    Food tempFood7(xCor - foodSpacer, yCor + foodSpacer);
    Food tempFood8(xCor, yCor - foodSpacer);

    foodList.push_back(tempFood1);
    foodList.push_back(tempFood2);
    foodList.push_back(tempFood3);
    foodList.push_back(tempFood4);
    foodList.push_back(tempFood5);
    foodList.push_back(tempFood6);
    foodList.push_back(tempFood7);
    foodList.push_back(tempFood8);
}

void FoodMap::create_sushi_roll(double xCor, double yCor)
{
    int foodSpacer{6};

    Food tempFood(xCor, yCor);
    Food tempFood1(xCor, yCor + foodSpacer);
    Food tempFood2(xCor, yCor + foodSpacer * 2);
    Food tempFood3(xCor, yCor + foodSpacer * 3);
    Food tempFood4(xCor, yCor + foodSpacer * 4);
    Food tempFood5(xCor, yCor + foodSpacer * 5);
    Food tempFood6(xCor, yCor + foodSpacer * 6);
    Food tempFood7(xCor, yCor + foodSpacer * 7);

    foodList.push_back(tempFood);
    foodList.push_back(tempFood1);
    foodList.push_back(tempFood2);
    foodList.push_back(tempFood3);
    foodList.push_back(tempFood4);
    foodList.push_back(tempFood5);
    foodList.push_back(tempFood6);
    foodList.push_back(tempFood7);
}

const std::vector<Food>& FoodMap::get_food() const
{
    return foodList;
}



