#include <iostream>
#include <vector>
#include <string>

#include "kagamin.hpp"

using namespace std;

int stof_vec(vector<string>& str_vec, vector<double>& dbl_vec){
	int i;
	for(i=0;i<str_vec.size();++i){
		dbl_vec[i] = stof(str_vec[i]);
	}
}
