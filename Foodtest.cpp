#include "gtest/gtest.h"
#include "food.h"
#include "foodmap.h"
#include "antsimutils.h"

class FoodMapSpy: public FoodMap
{
public:

    int get_amount_of_extra_food()
    {
        return amountOfExtraFood;
    }

protected:

};

class FoodSpy: public Food
{
public:

    FoodSpy()
    {
        initialFoodStrength = foodStrength;
    }

    int get_initial_food_strength()
    {
        return initialFoodStrength;
    }

    void set_strength(int strength)
    {
        foodStrength = strength;
    }



protected:
    int initialFoodStrength{0};

};

TEST(FoodMapTest, GivenAFoodMap_WhenCheckingToSeeIfItHasFoodOnIt_ExpectListSizeToEqualAmountOfFoodTimesExtraFood)
{
    FoodMapSpy testingFoodMap;
    int amountOfFood{10};

    testingFoodMap.populate_food(amountOfFood);
    int foodMapSize{static_cast<int>(testingFoodMap.get_food().size())};

    EXPECT_EQ(amountOfFood * testingFoodMap.get_amount_of_extra_food() , foodMapSize);
}

TEST(FoodTest, GivenAFood_WhenCheckingToSeeIfItDecrementsStrength_ExpectItsStrengthToDecreaseByOne)
{
    FoodSpy testingFood;
    EXPECT_TRUE(testingFood.get_strength() == testingFood.get_initial_food_strength());
    testingFood.decrement_food();
    EXPECT_TRUE(testingFood.get_strength() == testingFood.get_initial_food_strength() - 1);

}

TEST(FoodTest, GivenAFood_WhenCheckingToSeeIfTheFoodPositionIsRandom_ExpectFoodPositionToBeRandom)
{
    FoodSpy testingFoodOne;
    EXPECT_TRUE(testingFoodOne.get_x_coordinate() != testingFoodOne.get_y_coordinate());
    FoodSpy testingFoodTwo;
    EXPECT_TRUE(testingFoodTwo.get_x_coordinate() != testingFoodTwo.get_y_coordinate());

    EXPECT_TRUE(testingFoodOne.get_x_coordinate() != testingFoodTwo.get_x_coordinate());
    EXPECT_TRUE(testingFoodOne.get_y_coordinate() != testingFoodTwo.get_y_coordinate());

}

TEST(FoodMapTest, GivenAFoodMap_WhenDeletingEmpltyFoods_CheckToSeeIfEmptyFoodDeletesFromFoodMapVector)
{
    EXPECT_TRUE(false);//ILL NEED POINTERS FOR THIS
}

TEST(SearchTest, WhenGivenTwoPointsNearOneAnother_WhenCheckingToSeeIfCheckingFunctionReturnsTrue_ExpectFunctionToReturnTrue)
{
    EXPECT_TRUE(check_two_points(2.0,5.0,1.0,6.0,4.0));
}

TEST(SearchTest, WhenGivenTwoPointNearOneAnotherInVectors_WhenCheckingToSeeIfCheckingFunctionReturnsTrue_ExpectFunctionToReturnTrue)
{
    Eigen::Vector2d firstVector{{1.0,1.0}};
    Eigen::Vector2d secondVector{{2.0,2.0}};
    int tolerance{4};
    EXPECT_TRUE(are_these_points_near_eachother(firstVector,secondVector,tolerance));
}

TEST(SearchTest, WhenGivenTwoPointNearOneAnotherOneInVectorAndTheOtherPointAsASingleValue_WhenCheckingToSeeIfCheckingFunctionReturnsTrue_ExpectFunctionToReturnTrue)
{
    Eigen::Vector2d firstVector{{1.0,1.0}};
    double singleValue{1.0};
    int tolerance{4};
    EXPECT_TRUE(are_these_points_near_eachother(firstVector,singleValue,tolerance));
}
