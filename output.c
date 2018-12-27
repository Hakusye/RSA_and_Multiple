#include <stdio.h>
void Input_pqem(int *p,int *q,int *e,int *m){
	//do{
		printf("p,q,eの値を入力してください\n");
		printf("p:"); scanf("%d",p);
		printf("q:"); scanf("%d",q);
		printf("e:"); scanf("%d",e);
		printf("送信する人はmの値も入力してください:"); scanf("%d",m); 
//後にp,qの互いに素,fとeも互いに素もここに入れたい
	//}while( *p < 100 || *q < 100 || *e < 2 || *m < 1 || disjoint(p,q) == 0 || disjoint(f,e) == 0);
}

void test_output(int p,int q,int n,int f,int d,int e,int c,int m){
	printf("p:%d, q:%d, n:%d,f:%d, d:%d, e:%d, c:%d, m:%d\n",p,q,n,f,d,e,c,m);
}

