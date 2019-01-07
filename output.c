#include <stdio.h>
#include "Multiple/Multiple.h"
#include "my_math.h"

void Input_pqem(int *p,int *q,int *e,int *m,int *f){
	do{
		printf("p,q,eの値を入力してください\n");
		printf("p:"); scanf("%d",p);
		printf("q:"); scanf("%d",q);
	}while(*p < 100 || *q < 100);
	do{
		printf("e:"); scanf("%d",e);
		printf("送信する人はmの値も入力してください:"); scanf("%d",m); 
		*f = (*p-1) * (*q-1);

	}while(*e < 2 || *m < 1 || disjoint(*p,*q) == FALSE || disjoint(*f,*e) == FALSE);
}

void test_output(int p,int q,int n,int f,int d,int e,int c,int m){
	printf("p:%d, q:%d, n:%d,f:%d, d:%d, e:%d, c:%d, m:%d\n",p,q,n,f,d,e,c,m);
}

void Multiple_Input_pqem(Multiple *p,Multiple *q,Multiple *e,Multiple *m,Multiple *f,Multiple *n){
	Multiple tmp_p = Multiple_init(tmp_p);
	Multiple tmp_q = Multiple_init(tmp_q);
	do{
		printf("p,q,eの値を入力してください\n");
		printf("pの値の");
		*p = Make_Multiple(*p);
		printf("qの値の");
		*q = Make_Multiple(*q);
	}while(p->len <= 2 || q->len <= 2 ||  Multiple_disjoint(*p,*q) == FALSE);
	*n = Multiple_times_Multiple(*n,*p,*q);
	tmp_p = Multiple_copy(tmp_p,*p);
	tmp_q = Multiple_copy(tmp_q,*q);
	tmp_p = Multiple_sub_int(tmp_p,tmp_p,1);
	tmp_q = Multiple_sub_int(tmp_q,tmp_q,1);
	*f = Multiple_init(*f);
	*f = Multiple_times_Multiple(*f,tmp_p,tmp_q);
	do{
		printf("eの値の"); *e = Make_Multiple(*e);
	}while( Multiple_disjoint(*f,*e) == FALSE );
	printf("送信する人はmの値も");
	*m = Make_Multiple(*m);
}
