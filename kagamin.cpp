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

crossings_kanagawa2.csv�@�����_���W

handles/  kousatens/  teishis/

�^�]����̎U�z�}��`��


2	�q���x�j
2	�Ή���������_��������
3	�����_�̉^�]��������
2	�O���t���o�͂���
*/
