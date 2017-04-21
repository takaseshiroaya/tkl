#ifndef NEAREST_CROSSING_HPP
#define NEAREST_CROSSING_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "hubeny.hpp" 

using namespace std;

const int n_partitions = 100;

class Crossings{
	int i,j,k,l,m;
public:
	vector<vector<double>> crossings;
	array<array<vector<int>,n_partitions>,n_partitions> grid_crossings; //番号を抱えている
	double min_lat, max_lat, min_lon, max_lon;
	double lat_interval, lon_interval;
	int n_crossings = 0;

	void load_crossings(string path){
		ifstream ifs(path);
		if(!ifs){
			cout << "file cannot open" << endl;
			exit(1);
		}
		string str;
		while(getline(ifs,str)){
			if(str=="") break;
			vector<double> vec;
			stringstream ss(str);
			string str_buf;
			while(getline(ss,str_buf,',')){
				vec.push_back(stod(str_buf));
			}
			crossings.push_back(vec);
			++n_crossings;
		}
		cout << "load " << n_crossings << " crossings" << endl;
		min_lat = max_lat = crossings[0][1];
		min_lon = max_lon = crossings[0][2];
		for(i=0; i<n_crossings; ++i){
			if(crossings[i][1] < min_lat) min_lat = crossings[i][1];
			if(crossings[i][1] > max_lat) max_lat = crossings[i][1];
			if(crossings[i][2] < min_lon) min_lon = crossings[i][2];
			if(crossings[i][2] > max_lon) max_lon = crossings[i][2];
		}
		//cout << "min_lat = " << min_lat << ", max_lat = " << max_lat  << endl;
		//cout << "min_lon = " << min_lon << ", max_lon = " << max_lon  << endl;
		lat_interval = (max_lat-min_lat) / n_partitions;
		lon_interval = (max_lon-min_lon) / n_partitions;
		//cout << "lat_interval = " << lat_interval << endl;
		//cout << "lon_interval = " << lon_interval << endl;
		
		//double d;
		for(i=0; i<n_crossings;++i){
			j = (crossings[i][1] - min_lat) / lat_interval;
			if(j==n_partitions) --j;
			k = (crossings[i][2] - min_lon) / lon_interval;
			if(k==n_partitions) --k;
			grid_crossings[j][k].push_back(i);
		}
		/*
		for(i=0;i<n_partitions;++i){
			for(j=0;j<n_partitions;++j){
				cout << grid_crossings[i][j].size() << " ";
			}
			cout << endl;
		}*/
		cout << "complete" << endl;
	}
	
	
	//十分に密だと仮定し、同じブロックと周囲8ブロックの中だけから探す
	int get_crossing_num(double lat, double lon){
		Hubeny hubeny;
		double nearest_dist = 100000000;
		double nearest_num = -1;
		hubeny.set_ref_point(lat,lon);
		j = (lat - min_lat) / lat_interval;
		if(j>=n_partitions) j = n_partitions;
		k = (lon - min_lon) / lon_interval;
		if(k>=n_partitions) k = n_partitions;
		//cout << j << " " << k << endl;
		for(l=-1;l<=1;++l){
			//cout << "j+l= " << j+l << endl;
			if(j+l >= n_partitions || j+l < 0) continue;
			for(m=-1;m<=1;++m){
				//cout << "k+m= " << k+m << endl;
				if(k+m >= n_partitions || k+m < 0) continue;
				for(i=0;i<grid_crossings[j+l][k+m].size();++i){
					double dist = hubeny.dist_from_ref_point(crossings[grid_crossings[j+l][k+m][i]][1],crossings[grid_crossings[j+l][k+m][i]][2]);
					if(dist < nearest_dist){
						nearest_dist = dist;
						nearest_num = grid_crossings[j+l][k+m][i];
					}
				}
			}
		}
		if(nearest_num == -1){
			cout << "error: cannot get crossing num" << endl;
			exit(1);
		}
		return nearest_num;
	}
	
	
	
};


#endif

