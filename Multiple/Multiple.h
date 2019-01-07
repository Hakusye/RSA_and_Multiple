#ifndef MULTIPLE_H
#define MULTIPLE_H
#define DIGIT 1000
#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	int num[DIGIT]; //配列がおおきい方が桁のおおきい方
	int len;
	char number[DIGIT]; //makeを通して構造体を使うときにだけ使う
}Multiple;

Multiple Multiple_surplus(Multiple num1);
void Multiple_output(Multiple num1);
int Multiple_big_true(Multiple big_num,Multiple small_num);
int my_ctoi(char c);
int max(int a,int b);
Multiple Multiple_copy(Multiple ans,Multiple num1);
Multiple Make_Multiple(Multiple num); 
Multiple Multiple_init(Multiple num);
Multiple Multiple_shift(Multiple num,int shift);
//四則演算
Multiple Multiple_add_Multiple(Multiple ans,Multiple num1,Multiple num2);
Multiple Multiple_add_int(Multiple ans, Multiple num1, int num2);
Multiple Multiple_sub_Multiple(Multiple ans, Multiple num1, Multiple num2);
Multiple Multiple_sub_int(Multiple ans,Multiple num1,int sub); //ansが引かれる.ansの方が小さいことは考慮していない
Multiple Multiple_times_Multiple(Multiple ans,Multiple num1,Multiple num2); 
Multiple Multiple_times_int(Multiple ans,Multiple num1,int times);
Multiple Multiple_devide_Multiple_remainder(Multiple ans, Multiple big_num, Multiple small_num );
Multiple Multiple_devide_Multiple_quotient(Multiple ans, Multiple big_num, Multiple small_num);


#endif
