#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include "dist_from_ll.hpp"

using namespace std;

const double a = 6378137.0; //Ô“¹”¼Œa,equatorial_radius
const double f = 1.0/298.257222101; //G•½—¦,flattening
//const double e = sqrt(f*(2-f))//—£S—¦Aeccentricity
//const double 

double deg2rad(double deg){
	return deg*M_PI/180;
}


//ƒqƒ…ƒxƒj‚ÌŒö®@http://yamadarake.jp/trdi/report000001.html
double hubenys_formula(double rlat1, double rlon1, double rlat2, double rlon2){

	double dy = (rlat1 - rlat2);
	double dx = (rlon1 - rlon2);
	double avgy = (rlat1+rlat2)/2;//ƒÊy
	
	double W = sqrt(1 - f * (2 - f) * pow(sin(avgy), 2));
	double M = a * (1 - f * (2 - f)) / pow(W, 3);
	double N = a / W;
	double d = sqrt(pow(dy * M, 2) + pow(dx * N * cos(avgy), 2));
	
	return d;
}


double hubenys_formula_fast(double dx, double dy, double M2, double N2){
	return sqrt(dy*dy*M2+dx*dx*N2);
}




