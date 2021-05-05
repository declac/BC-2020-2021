/* 
 * Author: Francis Selldorff - selldorf@bc.edu
*/ 
// necessary include statements for program 
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include "point.h" 

// symbolic constant to define bits necessary for char to_string function
#define POINT_STRING_LENGTH (64) 

// typedef struct PointData 
typedef struct PointData { 
	double x; 
	double y; 
	char to_string[POINT_STRING_LENGTH]; 
} PointData; 


/* this reference to Point x */ 
double Point_x(Point * this) { 
	return this->data->x; 
} 

/* this reference to Point y */ 
double Point_y(Point * this) { 
	return this->data->y; 
} 


/* magnitude function */ 
double Point_magnitude(Point * this) { 
	return sqrt((Point_x(this) * Point_x(this)) + (Point_y(this) * Point_y(this))); 
}

/* distance function */ 
double Point_distance(Point * this, Point * that) { 
	return sqrt(((Point_x(this) - Point_x(that)) * (Point_x(this) - Point_x(that))) 
		+ ((Point_y(this) - Point_y(that)) * (Point_y(this) - Point_y(that)))); 	

} 

/* to_string function */ 
char * Point_to_string(Point * this) { 
	return this->data->to_string; 
} 

/* delete function */ 
void Point_delete(Point * this) { 
	free(this->data); 
	free(this); 
} 

/* Point_init_data function */ 
void Point_init_data(Point * this, double x, double y) { 
	this->data->x = x; 
	this->data->y = y; 
	sprintf(this->data->to_string, "(%f, %f)", x, y); 
} 

/* Point_init_functions function */ 
void Point_init_functions(Point * this) { 
	this->x = &Point_x; 
	this->y = &Point_y; 
	this->to_string = &Point_to_string; 
	this->magnitude = &Point_magnitude; 
	this->distance = &Point_distance; 
	this->delete = &Point_delete; 
} 

/* Point * Point_new function */ 
Point * Point_new(double x, double y) { 
	Point * point = (Point *)malloc(sizeof(Point)); 
	point->data = (PointData *) malloc(sizeof(PointData)); 
	Point_init_data(point, x, y); 
	Point_init_functions(point); 
	return point; 
} 
