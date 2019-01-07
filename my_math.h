#ifndef MY_MATH_H
#define MY_MATH_H

#include "Multiple/Multiple.h"
Multiple Multiple_LCM(Multiple big_num,Multiple small_num);
Multiple Multiple_decryption(Multiple ans,Multiple n,int d,Multiple c);
Multiple Multiple_encryption(Multiple ans,Multiple e, Multiple n,Multiple m);
Multiple Multiple_calc_d(Multiple d,Multiple e,Multiple f);
int int_calc_d(Multiple e,Multiple f);
int Multiple_disjoint(Multiple p, Multiple q);
int LCM(int p,int q);
int disjoint(int p,int q);
void calc_nfd(int *n,int *f,int *d, int p, int q,int e);
int encryption(int e, int n, int m);
int decryption(int n, int d, int c);
void Factor(int *p,int *q,int n); //ポインタp,qに因数分解の結果を渡す.nが対象
int calc_d(int e,int f);
#endif
