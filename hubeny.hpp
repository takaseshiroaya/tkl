#ifndef HUBENY_HPP
#define HUBENY_HPP

#include <iostream>
#include <cmath>

using namespace std;

const double a = 6378137.0; //Ô“¹”¼Œa,equatorial_radius
const double f = 1.0/298.257222101; //G•½—¦,flattening
const double pi = 3.141592653589793238462;

double deg2rad(double deg){
	return deg*pi/180;
}

class Hubeny{
	double rlat0, rlon0;
	double M2, N2;
	
public:
	double dist(double lat1, double lon1, double lat2, double lon2){
		double dy = (deg2rad(lat1) - deg2rad(lat2));
		double dx = (deg2rad(lon1) - deg2rad(lon2));
		double avgy = deg2rad((lat1+lat2)/2);//ƒÊy
		double W = sqrt(1 - f * (2 - f) * pow(sin(avgy), 2));
		double M = a * (1 - f * (2 - f)) / pow(W, 3);
		double N = a / W;
		double d = sqrt(pow(dy * M, 2) + pow(dx * N * cos(avgy), 2));
		return d;
	}
	/*
	double dist_fast(double lat1, double lon1, double lat2, double lon2){
		double dy = (deg2rad(lat1) - deg2rad(lat2));
		double dx = (deg2rad(lon1) - deg2rad(lon2));
		double avgy = deg2rad(lat2);//ƒÊy
		double W = sqrt(1 - f * (2 - f) * pow(sin(avgy), 2));
		double M = a * (1 - f * (2 - f)) / pow(W, 3);
		double N = a / W;
		double d = sqrt(pow(dy * M, 2) + pow(dx * N * cos(avgy), 2));
		return d;
	}
	*/
	
	void set_ref_point(double lat0, double lon0){
		this->rlat0 = deg2rad(lat0);
		this->rlon0 = deg2rad(lon0);
		double W = sqrt(1 - f * (2 - f) * pow(sin(rlat0), 2));
		this->M2 = pow(a * (1 - f * (2 - f)) / pow(W, 3), 2);
		this->N2 = pow(cos(rlat0) * a / W, 2);
	}
	
	
	double dist_from_ref_point(double lat1, double lon1){
		double dy = deg2rad(lat1) - rlat0;
		double dx = deg2rad(lon1) - rlon0;
		return sqrt(dy*dy*M2+dx*dx*N2);
	}
	
};


#endif