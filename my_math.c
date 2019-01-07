#include <stdlib.h>
#include <stdio.h>
#include "Multiple/Multiple.h"

Multiple Multiple_LCM(Multiple p,Multiple q){
	int i = 0;
	Multiple tmp,tmp_p,tmp_q;
	tmp = Multiple_init(tmp);
	//変な値にならないようにダミーを使う
	tmp_p = Multiple_copy(tmp_p,p);
	tmp_q = Multiple_copy(tmp_q,q);

	if(Multiple_big_true(tmp_q,tmp_p) == TRUE){
		tmp = Multiple_copy(tmp,tmp_p);
		tmp_p = Multiple_copy(tmp_p,tmp_q);
		tmp_q = Multiple_copy(tmp_q,tmp);
	}
	tmp = Multiple_devide_Multiple_remainder(tmp, tmp_p, tmp_q);
	while(tmp.num[0] != 0 || tmp.len != 1 ){
		tmp_p = Multiple_copy(tmp_p,tmp_q);
		tmp_q = Multiple_copy(tmp_q,tmp);
		tmp = Multiple_devide_Multiple_remainder(tmp,tmp_p,tmp_q);
	}
	// Multiple_output(tmp_q);
	return tmp_q;
}

int LCM(int p,int q){
	int tmp;
	if(q > p){
	tmp = p;
	p = q;
	q = tmp;
	}
	/*ユークリッド互除法*/
	tmp = p % q;
	while(tmp != 0){
		p = q;
		q = tmp;
		tmp = p % q;
	}
	printf("最大公約数は%d\n",q);
	return q;
}

int Multiple_disjoint(Multiple p, Multiple q){
	Multiple ans,tmp_p,tmp_q;
	ans = Multiple_init(ans);
	//ポインタ処理の関係上ダミーで計算を行う
	tmp_p = Multiple_copy(tmp_p,p);
	tmp_q = Multiple_copy(tmp_q,q);
	ans = Multiple_LCM(tmp_p,tmp_q);
	if(ans.len == 1 && ans.num[0] == 1 ){
		return TRUE;
	}else{
		return FALSE;
	}
}
int disjoint(int p, int q){
	int ans;
	ans = LCM(p,q);
	if(ans == 1){
		return TRUE;
	}else{
		return FALSE;
	}
}

Multiple Multiple_calc_d(Multiple d,Multiple e,Multiple f){
	int i=0;
	Multiple tmp = Multiple_init(tmp);
	Multiple ans_check = Multiple_init(ans_check);
	d = Multiple_init(d);
	while(1){
		i++;
		tmp = Multiple_add_Multiple(tmp,tmp,e);
		ans_check = Multiple_devide_Multiple_remainder(ans_check,tmp,f);
		if(i == 100000){
			d = Multiple_add_int(d,d,i);
			i = 0;
		}
		if(ans_check.len == 1 && ans_check.num[0] == 1){
			d = Multiple_add_int(d,d,i);
			printf("dの値は"); Multiple_output(d);
			break;
		}
	}
	return d;
}
int int_calc_d(Multiple e,Multiple f){
	int i=0;
	Multiple tmp = Multiple_init(tmp);
	Multiple ans_check = Multiple_init(ans_check);
	while(1){
		i++;
		tmp = Multiple_add_Multiple(tmp,tmp,e);
		//tmp = Multiple_times_int(tmp,e,i);
		ans_check = Multiple_devide_Multiple_remainder(ans_check,tmp,f);
		if(ans_check.len == 1 && ans_check.num[0] == 1){
			break;
		}
	}
		return i;
	}


int calc_d(int e,int f){
	int i=0,tmp;
	while(1){
		i++;
		tmp = e * i;
		if(tmp % f == 1){
			printf("dの値は%dで決まりです\n",i);
			break;
		}else if(i == 100000){
			printf("%d回チェックした結果dが求まりません.終了します\n",i);
			exit(0);
		}
	}
	return i;
}

//Multiple においてこれはインプットですませているのでいらない
void calc_nfd(int *n,int *f,int *d, int p, int q,int *e){
	int tmp;
	*n = p * q;
	*f = (p-1) * (q-1);
	*d = calc_d(*e,*f);
}

Multiple Multiple_encryption(Multiple ans,Multiple e, Multiple n,Multiple m){
	Multiple i = Multiple_copy(i,e);

	ans = Multiple_init(ans);
	ans = Multiple_add_int(ans,ans,1);
	while(i.len != 1 || i.num[0] != 0){
		i = Multiple_sub_int(i,i,1);
		ans = Multiple_times_Multiple(ans,ans,m);
		ans = Multiple_devide_Multiple_remainder(ans,ans,n);
	}
	return ans;
}

int encryption(int e, int n, int m){
	int i;
	long int ans = 1;
	for(i=0; i<e; i++){
		ans *= m;
		ans = ans % n;
	}
	return ans;
}

Multiple Multiple_decryption(Multiple ans,Multiple n,int d,Multiple c){
	int i;
	ans = Multiple_init(ans);
	ans = Multiple_add_int(ans,ans,1);
	for(i=d;i>0;i--){
		ans = Multiple_times_Multiple(ans,ans,c);
		ans = Multiple_devide_Multiple_remainder(ans,ans,n);
	}
	return ans;
}

int decryption(int n, int d,int c){
	int i;
	long int ans = 1;
	for(i = 0; i<d; i++){
		ans *= c;
		ans = ans % n;
	}
	return ans;
}

void Factor(int *p,int *q,int n){ //ポインタp,qに因数分解の結果を渡す.nが対象
	int i;
	//ここでは3桁までとする
	for(i=2;i<1000;i++){
		if(n % i == 0){
			*p = i;
			*q = n / i;
			break;
		}
	}
}




