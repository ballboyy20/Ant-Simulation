#include "gtest/gtest.h"
#include "pheromone.h"
#include "pheromonemap.h"
#include "world.h"
#include "ant.h"

class PheromoneSpy: public Pheromone
{
public:


protected:


};

class PheromoneMapSpy: public PheromoneMap
{
public:



protected:

};

class AntSpy: public Ant
{
public:

};

TEST(PheromoneTest, WhenGivenAPheromoneInitializedWithAnXAndYPosition_ExpectSetXAndYToMatchStoredXAndY)
{
    double xPos{5.0};
    double yPos{10.0};
    Pheromone testingPheromone{xPos,yPos};

    EXPECT_EQ(xPos, testingPheromone.get_x_position());

    EXPECT_EQ(yPos, testingPheromone.get_y_position());
}

TEST(PheromoneTest, GivenAPheromone_WhenReducingItsStrength_ExpectStrengthToDropOneInteger)
{
    Pheromone testingPheromone;
    int firstStrength{testingPheromone.get_strength()};
    testingPheromone.decay_strength();
    int secondStrength{testingPheromone.get_strength()};

    EXPECT_EQ( (firstStrength - secondStrength), 1);
}


TEST(PheromoneMapTest, GivenAPheromoneMap_WhenPuttingPheromonesOnTheMap_CheckToSeeIfVectorOnPheromoneMapClassHasPheromonesOnIt)
{
    PheromoneMapSpy testingPherMap;
    double pointlessValue{1.0};
    testingPherMap.add_pheromone(pointlessValue,pointlessValue);
    EXPECT_TRUE(testingPherMap.get_pheromones().size() == 1);
}

TEST(PheromoneDeleteTest, GivenAPheromoneMap_WhenDeletingOldPheromones_CheckToSeeVectorOfPheromonesChangesSize)
{
    EXPECT_TRUE(false);
}

