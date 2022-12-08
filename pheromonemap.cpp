#include "pheromonemap.h"

PheromoneMap::PheromoneMap()
{

}

PheromoneMap::~PheromoneMap()
{
    this->clear();
}

void PheromoneMap::update()
{
    this->decay_pheromones();
    this->delete_faded_pheromones();
}

void PheromoneMap::clear()
{

    pheromoneList.clear();
}

void PheromoneMap::decay_pheromones()
{
    for (int i{0}; i < pheromoneList.size(); i++)
    {
        pheromoneList[i].decay_strength();
    }
}

void PheromoneMap::add_pheromone(double xLoc, double yLoc)
{

    Pheromone tempPheromone{xLoc,yLoc};
    pheromoneList.push_back(tempPheromone);

}

void PheromoneMap::delete_faded_pheromones()
{
    for (int i{0}; i < pheromoneList.size(); i++)
    {
        if (pheromoneList[i].get_strength() <= 0)
        {
            pheromoneList.erase(pheromoneList.begin()+i);
        }
    }
}

const std::vector<Pheromone>& PheromoneMap::get_pheromones() const
{
    return pheromoneList;
}

