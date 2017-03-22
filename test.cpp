#include <iostream>
#include <iomanip>
#include <cmath>
#include "dist_from_ll.hpp"

using namespace std;

int test_hubenys_formula(double dlat1, double dlon1, double dlat2, double dlon2){
	
	cout << "dlat1 dlon1 dlat2 dlon2" << endl;
	cout << dlat1 << dlon1 << dlat2 << dlon2 << endl;
	
	double rlat1 = deg2rad(dlat1);
	double rlat2 = deg2rad(dlat2);
	double rlon1 = deg2rad(dlon1);
	double rlon2 = deg2rad(dlon2);
	
	double dn = hubenys_formula(rlat1,rlon1,rlat2,rlon2);
	
	
	double rLAT = rlat1;//
	double rLON = rlon1;//
	//cout << sin(LAT) - sin((lat1+lat2)/2) << endl;
	
	double W = sqrt(1 - f * (2 - f) * pow(sin(rLAT), 2));
	double M2 = pow(a * (1 - f * (2 - f)) / pow(W, 3), 2);
	double N2 = pow(cos(rLAT) * a / W, 2);
	
	double dy = rLAT-rlat2;
	double dx = rLON-rlon2;
	
	double df = hubenys_formula_fast(dx,dy,M2,N2);
	
	cout << "normal hubeny " << setprecision(10) << dn << endl;
	cout << "fast hubeny " << setprecision(10) << df << endl;
	
	return 0;
}
