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

/*

crossings_kanagawa2.csv�@�����_���W

handles/  kousatens/  teishis/

�^�]����̎U�z�}��`��


2	�q���x�j
2	�Ή���������_��������
3	�����_�̉^�]��������
2	�O���t���o�͂���
*/
