#include "ant.h"
#include "random.h"
#include <cmath>
#include "antsimutils.h"


Ant::Ant(PheromoneMap &foodPheromoneMapPassedIn, PheromoneMap &homePheromoneMapPassedIn, FoodMap &foodMapPassedIn): foodPheromoneMap{foodPheromoneMapPassedIn}, homePheromoneMap{homePheromoneMapPassedIn}, foodMap{foodMapPassedIn}
{
    this->initialize_position();
}

Ant::~Ant()
{

}

void Ant::initialize_position()
{
    antPosition[xCor] = initialPosition;
    antPosition[yCor] = initialPosition;

    double initialOrientation{randomNumberMaker.get_random_number(0.0,360.0)};
    this->set_orientation(initialOrientation);
}

void Ant::update()
{
    this->move_ant_location();

    if (foodIndicator == false)
    {
        this->look_for_food();
        this->drop_home_pheromone();
        // this->look_for_food_pheromones();
    }

    else
    {
        this->look_for_colony();
        this->drop_food_pheromone();
        //this->look_for_home_pheromones();
    }
}

bool Ant::has_food()
{
    if (foodIndicator)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void Ant::drop_food_pheromone()
{
    this->foodPheromoneMap.add_pheromone(this->get_position()[xCor], this->get_position()[yCor]);
}

void Ant::drop_home_pheromone()
{
    this->homePheromoneMap.add_pheromone(this->get_position()[xCor], this->get_position()[yCor]);
}

void Ant::look_for_home_pheromones()
{
    for (int i{0}; i < homePheromoneMap.get_pheromones().size(); i++)
    {
        if (are_these_points_near_eachother(antPosition, homePheromoneMap.get_pheromones()[i].get_x_position(), homePheromoneMap.get_pheromones()[i].get_y_position()))
        {

        }
    }
}

void Ant::look_for_food_pheromones()
{

}

void Ant::move_ant_location()
{    

    this->look_for_edge();

    this->set_random_angle();

    this->rotate_orientation();

    antPosition = antPosition + antOrientation * speed;

}

void Ant::rotate_orientation()
{
    rotate_vector(antOrientation, this->randomAngle);
}

void Ant::look_for_food()
{
    for(int i{0}; i < foodMap.get_food().size(); i++)
    {
        if(are_these_points_near_eachother(this->get_position(), foodMap.get_food()[i].get_position(),foodSearchTolerance))
        {
            foodIndicator = true;
            this->flip_direction();
            foodMap.eat_food(i);
        }
    }
}

void Ant::look_for_colony()
{
    if (are_these_points_near_eachother(this->get_position(),initialPosition,colonySearchTolerance))
    {
        foodIndicator = false;
        this->flip_direction();
    }
}

double Ant::get_ant_x_coordinate() const
{
    return antPosition[xCor];
}

double Ant::get_ant_y_coordinate() const
{
    return antPosition[yCor];
}

double Ant::get_random_angle() const
{
    return this->randomAngle;
}

void Ant::set_x_orientation(double x)
{
    antOrientation[xCor] = x;
}

void Ant::set_y_orientation(double y)
{
    antOrientation[yCor] = y;
}

void Ant::set_orientation(double angle)
{
    double angleInRadians{convert_to_radians(angle)};
    this->set_x_orientation(cos(angleInRadians));
    this->set_y_orientation(sin(angleInRadians));
}

void Ant::look_for_edge()
{
    if (is_ant_near_edge(antPosition, positionLimit))
    {
        this->flip_direction();
    }
}

void Ant::flip_direction()
{    
    rotate_vector(this->antOrientation, (this->randomAngle + 180));
}

void Ant::set_random_angle()
{
    double randomAngleInDegrees{randomNumberMaker.get_random_number(-1 * antMotionRangeInDegrees, antMotionRangeInDegrees)};
    this->randomAngle = randomAngleInDegrees;
}

Eigen::Vector2d Ant::get_orientation()
{
    return antOrientation;
}

Eigen::Vector2d Ant::get_position()
{
    return antPosition;
}

