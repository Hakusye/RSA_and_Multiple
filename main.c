#include <stdio.h>
#include <stdlib.h>
#include "my_math.h"
#include "output.h"
//#include <unistd.h> わんちゃん送信中ですを出すためだけに使う

int main(void){
	Multiple p,q;
	int d;
	Multiple n,f,c,m,e;
	Multiple_Input_pqem(&p,&q,&e,&m,&f,&n); //引数の5つはひいてこれてる.
	printf("f = "); Multiple_output(f);
	printf("n = "); Multiple_output(n);
	printf("m = "); Multiple_output(m);
	d = int_calc_d(e,f);
	printf("d = %d\n",d);
	printf("暗号化します\n");
	c = Multiple_encryption(c,e,n,m);
	printf("送信者にはmは不必要なので初期化します\n");
	m = Multiple_init(m);
	printf("送信中です\n");
	printf("送信しました\n");
	printf("復号します\n");
	m = Multiple_decryption(m,n,d,c);
	printf("送信者から送られてきた平文は"); Multiple_output(m);
}

//こっちがint型で行えるRSA暗号の暗号化と復号
/*
	int p,q; //素数
	int n,f,d,e,c,m; //f,eは互いに素
	int decry;

	Input_pqem(&p,&q,&e,&m,&f);
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
*/
