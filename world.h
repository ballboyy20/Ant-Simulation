#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "ant.h"
#include "food.h"
#include "pheromone.h"
#include "pheromonemap.h"
#include "foodmap.h"

class Ant;
class PheromoneMap;
class World
{
public:

    World();
    ~World();

    void add_food_to_grid(int xCoordinateFood, int yCoordinateFood);
    void set_amount_ants(int amountOfAntsInTheWorld);
    void update();
    void reset();
    void populate_world();
    void update_ants();
    void clear_ants();
    void update_pheromone_map();
    void update_food_map();
    void add_food(double x, double y);
    void add_sushi_roll(double x, double y);

    int get_amount_ants();
    int get_world_size();

    std::vector<Ant*> get_ants();
    const std::vector<Pheromone>& get_home_pheromones() const;
    const std::vector<Pheromone>& get_food_pheromones() const;
    std::vector<Food> get_food();


protected:

    int amountOfAnts{500};
    int amountOfFood{1};
    int foodIndicator{1};
    int sizeOfTheWorld{1000};

    void create_grid();
    void populate_food();
    void populate_ants();

    PheromoneMap foodPheromoneMap;
    PheromoneMap homePheromoneMap;
    FoodMap foodMap;

    std::vector<std::vector<int>> worldGrid;

    std::vector<Ant*> antsOnTheWorld;

};

#endif // ANT_H
