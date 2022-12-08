#include "gtest/gtest.h"
#include "random.h"
#include "world.h"
#include "food.h"
#include "pheromone.h"



class WorldSpy: public World
{
public:


protected:

};


TEST(WorldTest, GivenAWorld_WhenCheckingToSeeIfItHasAnAnt_ExpectThereToBeAnAntOnTheAntVector)
{
    WorldSpy testingWorld;
    int amountOfAntsOnTestingWorld{testingWorld.get_amount_ants()};

    EXPECT_TRUE(amountOfAntsOnTestingWorld >= 1);

    int antVectorAmount{static_cast<int>(testingWorld.get_ants().size())};

    EXPECT_TRUE(antVectorAmount >= 1);
}

TEST(WorldTest, GivenAWorldWithAntsOnIt_WhenCheckingToSeeIfItMovesAntLocations_ExpectAntsToHaveMovedXLocations)
{
    WorldSpy testingWorld;
    for(int i{0}; i < testingWorld.get_amount_ants(); i++)
    {
        EXPECT_TRUE(testingWorld.get_ants()[i]->get_ant_x_coordinate() == 500.0);
    }

    testingWorld.update_ants();

    for(int i{0}; i < testingWorld.get_amount_ants(); i++)
    {
        EXPECT_TRUE(testingWorld.get_ants()[i]->get_ant_x_coordinate() != 0.0);
    }
}

TEST(WorldTest, GivenAWorldWithAntsOnIt_WhenCheckingToSeeIfItMovesAntLocations_ExpectAntsToHaveMovedYLocations)
{
    WorldSpy testingWorld;
    for(int i{0}; i < testingWorld.get_amount_ants(); i++)
    {
        EXPECT_TRUE(testingWorld.get_ants()[i]->get_position()[0] == 500.0);
    }

    testingWorld.update_ants();

    for(int i{0}; i < testingWorld.get_amount_ants(); i++)
    {
        EXPECT_TRUE(testingWorld.get_ants()[i]->get_position()[1] != 0.0);
    }
}







