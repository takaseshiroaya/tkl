#include <iostream>
#include <iomanip>
#include "dist_from_ll.hpp"

using namespace std;

int main(int argc, char** argv){
	if(argc != 5){
		cout << "lat1 lon1 lat2 lon2" <<endl;
		exit(1);
	}
	double lat1 = atof(argv[1]);
	double lon1 = atof(argv[2]);
	double lat2 = atof(argv[3]);
	double lon2 = atof(argv[4]);
	
	//cout << lat1 << endl;
	
	double d = hubenys_formula(lat1,lon1,lat2,lon2);
	
	cout << setprecision(10) << d << endl;
	
	
}
