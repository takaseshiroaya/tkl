#include <iostream>
#include <iomanip>
#include <cmath>
#include "dist_from_ll.hpp"

using namespace std;

int main(int argc, char** argv){
	if(argc != 5){
		cout << "lat1 lon1 lat2 lon2" <<endl;
		exit(1);
	}
	double lat1 = deg2rad(atof(argv[1]));
	double lon1 = deg2rad(atof(argv[2]));
	double lat2 = deg2rad(atof(argv[3]));
	double lon2 = deg2rad(atof(argv[4]));

	double dn = hubenys_formula(lat1,lon1,lat2,lon2);
	
	
	double LAT = lat1;//
	double LON = lon1;//
	//cout << sin(LAT) - sin((lat1+lat2)/2) << endl;
	
	double W = sqrt(1 - f * (2 - f) * pow(sin(LAT), 2));
	double M2 = pow(a * (1 - f * (2 - f)) / pow(W, 3), 2);
	double N2 = pow(cos(LAT) * a / W, 2);
	
	double dy = LAT-lat2;
	double dx = LON-lon2;
	
	double df = hubenys_formula_fast(dx,dy,M2,N2);
	
	cout << setprecision(10) << dn << endl;
	cout << setprecision(10) << df << endl;
	
	
}
