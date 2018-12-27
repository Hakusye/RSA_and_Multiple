#include <stdio.h>
#include <stdlib.h>
#include "my_math.h"
#include "output.h"
//#include <unistd.h> わんちゃん送信中ですを出すためだけに使う

int main(void){
	int p,q; //素数
	int n,f,d,e,c,m; //f,eは互いに素
	int i,j;
	int decry;

	Input_pqem(&p,&q,&e,&m);
	calc_nfd(&n,&f,&d,p,q,e);
	c = encryption(e,n,m); //送信側はe,nを元々持ってて,m(平文)を入力した想定
	test_output(p,q,n,f,d,e,c,m);
	printf("元の平文mは必要なくなったので,-1で初期化します\n");
	m = -1;
	printf("送信中です\n");
	printf("送信しました\n");
	decry = decryption(n,d,c); //受信側はn,dを元々持っていて,送信者からc(暗号)を受け取る
	printf("送信者から送られてきた平文は%dです\n",decry);
}

