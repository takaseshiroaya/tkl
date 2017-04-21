#include <iostream>
#include <vector>
#include <string>

#include "kagamin.hpp"

using namespace std;

int stod_vec(vector<string>& str_vec, vector<double>& dbl_vec){
	int i;
	for(i=0;i<str_vec.size();++i){
		dbl_vec[i] = stod(str_vec[i]);
	}
}

/*

tokyo002
/data/local/kana_crossplace_operations5

crossings_kanagawa2.csv@Œð·“_À•W

handles/  kousatens/  teishis/

‰^“]‘€ì‚ÌŽU•z}‚ð•`‚­


2	ƒqƒ…ƒxƒj
2	‘Î‰ž‚·‚éŒð·“_‚ðŒ©‚Â‚¯‚é
3	Œð·“_‚Ì‰^“]‘€ì‚ðŽæ‚é
2	ƒOƒ‰ƒt‚ðo—Í‚·‚é
*/
