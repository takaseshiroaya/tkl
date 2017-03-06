#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include "dist_from_ll.hpp"

using namespace std;

const double a = 6378137.0; //赤道半径,equatorial_radius
const double f = 1.0/298.257222101; //扁平率,flattening
//const double e = sqrt(f*(2-f))//離心率、eccentricity
//const double 

double deg2rad(double deg){
	return deg*M_PI/180;
}


//ヒュベニの公式　http://yamadarake.jp/trdi/report000001.html
double hubenys_formula(double lat1, double lon1, double lat2, double lon2){

	double dy = (lat1 - lat2);
	double dx = (lon1 - lon2);
	double avgy = (lat1+lat2)/2;//μy
	double W = sqrt(1 - f * (2 - f) * pow(sin(avgy), 2));
	double M = a * (1 - f * (2 - f)) / pow(W, 3);
	double N = a / W;
	double d = sqrt(pow(dy * M, 2) + pow(dx * N * cos(avgy), 2));
	
	return d;
}


double hubenys_formula_fast(double dx, double dy, double M2, double N2){
	return sqrt(dy*dy*M2+dx*dx*N2);
}




