#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

//#include "dist_from_ll.hpp"
//#include "test.hpp"
#include "kagamin.hpp"
#include "hubeny.hpp"

using namespace std;

//latとlonをもらってパラメータを返す関数
//ライブラリなので使いやすいように書く

int main(int argc, char** argv){
	if(argc != 5){
		cout << "lat1 lon1 lat2 lon2" <<endl;
		exit(1);
	}
	double lat1 = atof(argv[1]);
	double lon1 = atof(argv[2]);
	double lat2 = atof(argv[3]);
	double lon2 = atof(argv[4]);
	
	Hubeny hubeny;
	double d = hubeny.dist(lat1, lon1, lat2, lon2);
	cout << d << endl;
	
	/*
	double rlat1 = deg2rad(dlat1);
	double rlon1 = deg2rad(dlon1);
	double rlat2 = deg2rad(dlat2);
	double rlon2 = deg2rad(dlon2);

	test_hubenys_formula(dlat1,dlon1,dlat2,dlon2);
	
	double rLAT = deg2rad(35.339172);
	double rLON = deg2rad(139.490060);
	
	ifstream ifs("./data/fujisawa_tsuugakuro_20170201.txt");
	if(!ifs){cout << "cannot open" << endl; exit(1);}
	
	vector<string>tsuugakuro;
	string buf;
	while(getline(ifs,buf)){
		
		tsuugakuro.push_back(buf);
	}
	*/
		/*
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
	*/
	return 0;
}
