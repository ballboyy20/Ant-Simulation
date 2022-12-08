#ifndef ANT_H
#define ANT_H

#include "pheromonemap.h"
#include "foodmap.h"
#include <Eigen/Dense>

#include "random.h"


class Random;
class PheromoneMap;
class FoodMap;

class Ant
{
public:

    Ant(PheromoneMap &foodPheromoneMapPassedIn, PheromoneMap &homePheromoneMapPassedIn, FoodMap &foodMapPassedIn);
    virtual ~Ant();
    double get_ant_x_coordinate() const;
    double get_ant_y_coordinate() const;
    double get_random_angle() const;

    void update();
    void rotate_orientation();
    void set_orientation(double angle);
    virtual void set_random_angle();
    virtual void move_ant_location();

    bool has_food();

    Eigen::Vector2d get_orientation();
    Eigen::Vector2d get_position();

protected:
    double PI{3.14159};
    double antMotionRangeInDegrees{15.0};
    double viewingAngle{20.0};
    double speed{3.0};
    double randomAngle{90.0};
    double initialPosition{500.0};
    double positionLimit{initialPosition * 2};

    int xCor{0};
    int yCor{1};
    int foodSearchTolerance{4};
    int colonySearchTolerance{50};

    bool foodIndicator{false};

    Random randomNumberMaker;

    void set_x_orientation(double x);
    void set_y_orientation(double y);
    void flip_direction();
    void look_for_edge();
    void look_for_food();
    void look_for_colony();
    void look_for_home_pheromones();
    void look_for_food_pheromones();
    void drop_food_pheromone();
    void drop_home_pheromone();
    void initialize_position();

    PheromoneMap& foodPheromoneMap;
    PheromoneMap& homePheromoneMap;
    FoodMap& foodMap;

    Eigen::Vector2d antPosition{{0.0,0.0}}; // 2 means two dimensions, d means double data type
    Eigen::Vector2d antOrientation{{0.0,0.0}};

private:

};

#endif // ANT_H
