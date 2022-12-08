#include "pheromone.h"

Pheromone::Pheromone()
{
}

Pheromone::Pheromone(double xPos, double yPos)
{
    pheromonePosition[xCor] = xPos;
    pheromonePosition[yCor] = yPos;
}

double Pheromone::get_x_position() const
{
    return pheromonePosition[xCor];
}

double Pheromone::get_y_position() const
{
    return pheromonePosition[yCor];
}

int Pheromone::get_strength()
{
    return pheromoneStrength;
}

void Pheromone::decay_strength()
{
    if (pheromoneStrength > 0)
    {
        pheromoneStrength = pheromoneStrength - 1;
    }
}

