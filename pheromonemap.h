#ifndef PHEROMONEMAP_H
#define PHEROMONEMAP_H


#include <vector>
#include "pheromone.h"

class PheromoneMap
{
public:
    PheromoneMap();
    ~PheromoneMap();

    void update();
    void clear();
    void decay_pheromones();
    void add_pheromone(double xLoc, double yLoc);
    void delete_faded_pheromones();

    const std::vector<Pheromone>& get_pheromones() const;


protected:

    std::vector<Pheromone> pheromoneList;

};

#endif // PHEROMONEMAP_H
