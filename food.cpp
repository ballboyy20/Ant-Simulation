#include "food.h"

Food::Food()
{
    foodPosition[xCor] = randomNumberGetter.get_random_number(foodGridSpacer,randomNumberRange);
    foodPosition[yCor] = randomNumberGetter.get_random_number(foodGridSpacer,randomNumberRange);
}

Food::Food(double xCoordinate, double yCoordinate)
{
    foodPosition[xCor] = xCoordinate;
    foodPosition[yCor] = yCoordinate;
}

double Food::get_y_coordinate() const
{
    return foodPosition[yCor];
}

double Food::get_x_coordinate() const
{
    return foodPosition[xCor];
}

Eigen::Vector2d Food::get_position() const
{
    return foodPosition;
}

int Food::get_strength()
{
    return foodStrength;
}

void Food::decrement_food()
{
    if (foodStrength > 0)
    {
        foodStrength = foodStrength - 1;
    }
}

