/*
 * Program to do object oriented programing with points
 * 
 * Author: Declan McGranahan - aviram@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h" //Bring in point.h which is defined in the file point.h
#define POINT_STRING_SIZE (64) //Define the point string size maximum of 64


/* Create the PointData structure
 * Declares the to_string function to the size set above
 */ 
typedef struct PointData {
    double x;
    double y;
    char to_string[POINT_STRING_SIZE];
} PointData;

/* Works with Point_x to define the point
 * 
 */ 
double Point_x(Point *this) {
    return this->data->x;
}

/* Works with Point_y to define the point
 * 
 */ 
double Point_y(Point *this) {
    return this->data->y;
}

/* Works with Point_string to define the point that brings back string
 * 
 */ 
char *Point_to_string(Point *this) {
    return this->data->to_string;
}

/* Works with Point_magnitude to define the point magnitude
 * Uses the square root function to do it
 */ 
double Point_magnitude(struct Point *this) {
    return sqrt((Point_x(this) * Point_x(this)) + (Point_y(this) * Point_y(this)));
}

/* Finds the distance between two points
 * Uses the square root function to do it
 */ 
double Point_distance(struct Point *this, struct Point *other) {
    return sqrt(((Point_x(this) - Point_x(other)) * (Point_x(this) - Point_x(other))) 
		+ ((Point_y(this) - Point_y(other)) * (Point_y(this) - Point_y(other))));
}

//Deletes a point to free memory space
void Point_delete(Point *this) { 
	free(this->data); 
	free(this); 
} 

//initiaties the point using two doubles defined in the function call
void Point_init_data(Point *this, double x, double y) {
    this->data->x = x;
    this->data->y = y;
    sprintf(this->data->to_string, "(%f, %f)", x, y);
}

//Initiaties the functions needed to do the math for the distance and to string
//Also initiates the function delete
void Point_init_functions(Point *this) {
    this->x = &Point_x;
    this->y = &Point_y;
    this->to_string = &Point_to_string;
    this->magnitude = &Point_magnitude;
    this->distance = &Point_distance;
    this->delete = &Point_delete; 
}

//Creates a new point and sets the data ands size to the aproperate measures
Point *Point_new(double x, double y) {
    Point *point = (Point *)malloc(sizeof(Point));
    point->data = (PointData *) malloc(sizeof(PointData));
    Point_init_data(point, x, y);
    Point_init_functions(point);
    return point;
}