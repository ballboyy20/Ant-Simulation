#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
    Random();
    virtual double get_random_number(double minValue, double maxValue);
    int get_random_number(int minValue, int maxValue);

private:

};

#endif // RANDOM_H
