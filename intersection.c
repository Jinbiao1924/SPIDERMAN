#include "intersection.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

double *circle_intersect(double x1,double y1,double r1,double x2,double y2,double r2){
    double d,K,x_first,y_first,x_second,y_second,theta_first,theta_second;
    
    d = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    
    K = 0.25*sqrt((pow(r1+r2,2)-pow(d,2))*(pow(d,2)-pow(r1-r2,2)));
    
    x_first = 0.5*(x1+x2) + 0.5*(x2-x1)*(pow(r1,2)-pow(r2,2))/pow(d,2) + 2*(y2-y1)*K/pow(d,2);
    y_first = 0.5*(y2+y1) + 0.5*(y2-y1)*(pow(r1,2)-pow(r2,2))/pow(d,2) + -2*(x2-x1)*K/pow(d,2);
    
    x_second = 0.5*(x1+x2) + 0.5*(x2-x1)*(pow(r1,2)-pow(r2,2))/pow(d,2) - 2*(y2-y1)*K/pow(d,2);
    y_second = 0.5*(y2+y1) + 0.5*(y2-y1)*(pow(r1,2)-pow(r2,2))/pow(d,2) - -2*(x2-x1)*K/pow(d,2);

    double *coords = malloc(sizeof(double) * 6);

    theta_first = atan(y_first/x_first);

    if(theta_first < 0){
        theta_first = 2*M_PI + theta_first;
    }

    theta_second = atan(y_second/x_second);

    if(theta_second < 0){
        theta_second = 2*M_PI + theta_second;
    }

    coords[0] = x_first;
    coords[1] = y_first;
    coords[2] = x_second;
    coords[3] = y_second;
    coords[4] = theta_first;
    coords[5] = theta_second;

    return coords;
}

double *line_intersect(double m,double theta,double x2,double y2,double r2){
    double x_first,y_first,x_second,y_second;
    
    x_first = ((2*x2 + 2*y2*m) + sqrt(pow((2*x2 + 2*y2*m),2) - 4*(1 + pow(m,2))*(pow(x2,2) + pow(y2,2) - pow(r2,2))))/(2*(1 + pow(m,2)));
    x_second = ((2*x2 + 2*y2*m) - sqrt(pow((2*x2 + 2*y2*m),2) - 4*(1 + pow(m,2))*(pow(x2,2) + pow(y2,2) - pow(r2,2))))/(2*(1 + pow(m,2)));
    
    y_first = x_first*m;
    y_second = x_second*m;

    double* coords = malloc(sizeof(double) * 6);

    double r_first = sqrt(pow(x_first,2) + pow(y_first,2));
    double r_second =sqrt(pow(x_second,2) + pow(y_second,2));

    coords[0] = x_first;
    coords[1] = y_first;
    coords[2] = x_second;
    coords[3] = y_second;
    coords[4] = r_first;
    coords[5] = r_second;

    return coords;
}