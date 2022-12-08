#include "antsimutils.h"
#include <cmath>

double convert_to_radians(double angleInDegrees)
{
    double PI{3.14159};
    return (angleInDegrees*(PI/180.0));
}

double calculate_clockwise_alignment_angle_degrees(const Eigen::Vector2d from, Eigen::Vector2d to)
{
    double PI{3.14159};
    double det = from[0]*to[1] - from[1]*to[0];
    double d = from.dot(to);
    double clockwiseAngle = std::atan2(-det,-d)+PI;
    return clockwiseAngle * (180.0/PI);
}

void rotate_vector(Eigen::Vector2d &vector_to_be_rotated, double angleInDegrees)
{
    int x{0};
    int y{1};

    double angleInRadians{convert_to_radians(angleInDegrees)};

    double newX{vector_to_be_rotated[x] * cos(angleInRadians) - vector_to_be_rotated[y] * sin(angleInRadians)};
    double newY{vector_to_be_rotated[x] * sin(angleInRadians) + vector_to_be_rotated[y] * cos(angleInRadians)};

    vector_to_be_rotated[x] = newX;
    vector_to_be_rotated[y] = newY;
}

Eigen::Vector2d create_orientaion(double angleInDegrees)
{
    Eigen::Vector2d newOrientation{{0.0,0.0}};
    double angleInRadians{convert_to_radians(angleInDegrees)};
    newOrientation[0] = cos(angleInRadians);
    newOrientation[1] = sin(angleInRadians);
    return newOrientation;
}


bool check_two_points(double firstX, double firstY, double secondX, double secondY, int tolerance)
{
    if ( (abs(firstX - secondX) <= tolerance) && (abs(firstY-secondY) <= tolerance))
        return true;
    else
        return false;
}

bool are_these_points_near_eachother(Eigen::Vector2d firstCor, Eigen::Vector2d secondCor, int tolerance)
{
    if ( (abs(firstCor[0] - secondCor[0]) <= tolerance) && (abs(firstCor[1]-secondCor[1]) <= tolerance))
        return true;
    else
        return false;
}

bool are_these_points_near_eachother(Eigen::Vector2d firstCor, double secondCor, int tolerance)
{
    if ( (abs(firstCor[0] - secondCor) <= tolerance) && (abs(firstCor[1]-secondCor) <= tolerance))
        return true;
    else
        return false;
}

bool is_point_inside_box(Eigen::Vector2d firstVector, Eigen::Vector2d secondVector, Eigen::Vector2d thirdVector, Eigen::Vector2d fourthVector, double firstCor, double secondCor)
{
    double x_p{firstCor};
    double y_p{secondCor};
    double x1{firstVector[0]};
    double x2{secondVector[0]};
    double x3{thirdVector[0]};
    double x4{fourthVector[0]};
    double y1{firstVector[1]};
    double y2{secondVector[1]};
    double y3{thirdVector[1]};
    double y4{fourthVector[1]};

    if ( abs(x1) < x_p && abs(y1) < y_p &&
         abs(x2) > x_p && abs(y2) < y_p &&
         abs(x3) > x_p && abs(y3) > y_p &&
         abs(x4) < x_p && abs(y4) > y_p)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_point_inside_box(Eigen::Vector2d firstVector, Eigen::Vector2d secondVector, double firstCor, double secondCor)
{
    if ( (abs(firstVector[0]) <= firstCor) && (abs(firstVector[1]) >= secondCor) && (abs(secondVector[0]) >= firstCor) && (abs(secondVector[1]) <= secondCor) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_point_inside_box(Eigen::Vector2d firstVector, Eigen::Vector2d secondVector, Eigen::Vector2d thirdVector)
{
    if ( (abs(firstVector[0]) <= thirdVector[0]) && (abs(firstVector[1]) >= thirdVector[1]) && (abs(secondVector[0]) >= thirdVector[0]) && (abs(secondVector[1]) <= thirdVector[1]) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_ant_near_edge(Eigen::Vector2d &antLocation, int limit)
{
    int bounceFactor{2};
    int xCor{0};
    int yCor{1};

    if (antLocation[xCor] >= limit)
    {
        antLocation[xCor] = limit - bounceFactor;
        return true;
    }

    if (antLocation[yCor] >= limit)
    {
        antLocation[yCor] = limit - bounceFactor;
        return true;
    }

    if (antLocation[xCor] <= 0.0)
    {
        antLocation[xCor] = bounceFactor;
        return true;
    }

    if (antLocation[yCor] <= 0.0)
    {
        antLocation[yCor] = bounceFactor;
        return true;
    }

    else
    {
        return false;
    }
}
