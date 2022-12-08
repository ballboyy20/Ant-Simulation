#include "world.h"
#include "ant.h"

World::World()
{
    //this->create_grid();
    this->populate_world();
}

World::~World()
{
    this->clear_ants();
}

void World::update()
{
    this->update_ants();
    this->update_pheromone_map();
    this->update_food_map();
}

void World::reset()
{
    this->populate_ants();
    this->populate_food();
    foodPheromoneMap.clear();
    homePheromoneMap.clear();
}

void World::update_ants()
{
    for (int i{0}; i < this->amountOfAnts; i++)
    {
        antsOnTheWorld[i]->update();
    }
}

void World::clear_ants()
{
    for (Ant* tempAnt : antsOnTheWorld)
    {
        delete tempAnt;
    }
    antsOnTheWorld.clear();
}

void World::update_pheromone_map()
{
    this->foodPheromoneMap.update();
    this->homePheromoneMap.update();
}

void World::update_food_map()
{
    this->foodMap.update();
}

void World::add_food(double x, double y)
{
    this->foodMap.add_user_food(x,y);
}

void World::add_sushi_roll(double x, double y)
{
    this->foodMap.create_sushi_roll(x,y);
}

int World::get_amount_ants()
{
    return amountOfAnts;
}

void World::populate_world()
{
    this->populate_ants();
    this->populate_food();
}

void World::populate_ants()
{    
    this->clear_ants();

    for (int i{0}; i < this->amountOfAnts; i++)
    {
        Ant* tempAnt = new Ant{foodPheromoneMap, homePheromoneMap, foodMap};
        antsOnTheWorld.push_back(tempAnt);
    }
}

void World::populate_food()
{
    foodMap.clear();
    foodMap.populate_food(amountOfFood);
}

void World::set_amount_ants(int amountOfAntsInTheWorld)
{
    this->amountOfAnts = amountOfAntsInTheWorld;
}

std::vector<Food> World::get_food()
{
    return foodMap.get_food();
}

std::vector<Ant *> World::get_ants()
{
    return antsOnTheWorld;
}

const std::vector<Pheromone>& World::get_home_pheromones() const
{
    return this->homePheromoneMap.get_pheromones();
}

const std::vector<Pheromone>& World::get_food_pheromones() const
{
    return this->foodPheromoneMap.get_pheromones();
}

int World::get_world_size()
{
    return sizeOfTheWorld;
}

void World::create_grid()
{
    worldGrid.resize(sizeOfTheWorld);
    for (std::vector<int>& row: worldGrid)
    {
        row.resize(sizeOfTheWorld);
    }

    for (int i{0}; i < worldGrid.size(); i++)
    {
        for (int j{0}; j < worldGrid.size(); j++)
        {
            worldGrid[i][j] = 0;
        }
    }
}
