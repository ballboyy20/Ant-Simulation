#include "random.h"
#include <random>

Random::Random()
{

}

double Random::get_random_number(double minValue, double maxValue)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(minValue, maxValue);
    return dis(gen);
}

int Random::get_random_number(int minValue, int maxValue)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(minValue, maxValue);
    return dis(gen);
}
