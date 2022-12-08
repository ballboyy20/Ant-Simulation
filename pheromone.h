#ifndef PHEROMONE_H
#define PHEROMONE_H

#include <Eigen/Dense>

class Pheromone
{
public:
    Pheromone();
    Pheromone(double xPos, double yPos);

    double get_x_position() const;
    double get_y_position() const;

    int get_strength();

    void decay_strength();

protected:

    Eigen::Vector2d pheromonePosition{{0.0,0.0}}; //ASK PROF. IF IT MAKES A DIFFERENT TO USE INT OR DOUBLE

    int pheromoneStrength{50};

    int xCor{0};
    int yCor{1};
};

#endif // PHEROMONE_H
