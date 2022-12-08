#ifndef ANTSIMUTILS_H
#define ANTSIMUTILS_H

#include <Eigen/Dense>

void rotate_vector(Eigen::Vector2d &vector_to_be_rotated, double angleInDegrees);
bool is_point_inside_box(Eigen::Vector2d firstVector, Eigen::Vector2d secondVector, double firstCor, double secondCor);
bool is_point_inside_box(Eigen::Vector2d firstVector, Eigen::Vector2d secondVector, Eigen::Vector2d thirdVector);
bool is_point_inside_box(Eigen::Vector2d firstVector, Eigen::Vector2d secondVector, Eigen::Vector2d thirdVector, Eigen::Vector2d fourthVector, double firstCor, double secondCor);

double convert_to_radians(double angleInDegrees);
double calculate_clockwise_alignment_angle_degrees(const Eigen::Vector2d from, Eigen::Vector2d to);

Eigen::Vector2d create_orientaion(double angleInDegrees); //maybe move this to the testing file if not used elsewhere

bool check_two_points(double firstX, double firstY, double secondX, double secondY, int tolerance);
bool are_these_points_near_eachother(Eigen::Vector2d firstCor, Eigen::Vector2d secondCor, int tolerance);
bool are_these_points_near_eachother(Eigen::Vector2d firstCor, double secondCor, int tolerance);
bool is_ant_near_edge(Eigen::Vector2d &antLocation, int limit);


#endif // ANTSIMUTILS_H
