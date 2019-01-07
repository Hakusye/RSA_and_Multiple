//Multipleをつかう前の状態
#include <stdlib.h>
#include <stdio.h>
int LCM(int p,int q){
	int tmp;
	if(p < q){
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

int disjoint(int p, int q){
	int ans;
	ans = LCM(p,q);
	if(ans == 1){
		return 1; //True
	}else{
		return 0; // False
	}
}

int calc_d(int e,int f){
	int i=0,tmp,d;
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
	d = i;
	return d;
}

void calc_nfd(int *n,int *f,int *d, int p, int q,int e){
	int tmp;
	*n = p * q;
	*f = (p-1) * (q-1);
	*d = calc_d(e,*f);
}

int encryption(int e, int n, int m){
	int i;
	long int ans = 1;
	for(i=0; i<e; i++){
		ans *= m;
	}
	ans = ans % n;
	return ans;
}

int decryption(int n, int d,int c){
	int i;
	long int ans = 1;
	for(i = 0; i<d; i++){
		ans *= c;
	}
	ans = ans % n;
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




