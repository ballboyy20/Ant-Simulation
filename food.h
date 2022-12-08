#ifndef FOOD_H
#define FOOD_H

#include "random.h"
#include <Eigen/Dense>

class Food
{
public:

    Food();
    Food(double xCoordinate, double yCoordinate);

    double get_y_coordinate() const;
    double get_x_coordinate() const;

    int get_strength();

    void decrement_food();

    Eigen::Vector2d get_position() const;

protected:

    Eigen::Vector2d foodPosition{{0.0,0.0}};

    Random randomNumberGetter;

    int randomNumberRange{980};
    int foodGridSpacer{20};
    int xCor{0};
    int yCor{1};
    int foodStrength{1};

};

#endif // FOOD_H
