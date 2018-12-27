/************最後を一番大きい桁にかえる作業からはじめよう**********************/

#include <stdio.h>
#include <string.h>
#define DIGIT 1000
//classチックに書く
typedef struct{
	int num[DIGIT]; //配列がおおきい方が桁のおおきい方
	int len;
	char number[DIGIT]; //makeを通して構造体を使うときにだけ使う
}Multiple;

Multiple Multiple_init(Multiple num);
Multiple Multiple_times_Multiple(Multiple ans,Multiple num1,Multiple num2); //変数との掛け算を利用しまくる
Multiple Multiple_shift(Multiple num,int shift);
Multiple Multiple_sub_int(Multiple ans,Multiple num1,int sub); //ansが引かれる.ansの方が小さいことは考慮していない
int max(int a,int b);
Multiple Multiple_times_int(Multiple ans,Multiple num1,int times);
void Multiple_surplus(Multiple num1);
void Multiple_output(Multiple num1);
Multiple Multiple_add(Multiple ans,Multiple num1,Multiple num2);
Multiple Make_Multiple(Multiple num); //代入する値をここにいれないとポインタの関係上事故る
int my_ctoi(char c);
//end

int main(void){
	int i,times,sub;
	Multiple num1,num2,num3;
	num1 = Make_Multiple(num1);
	num2 = Make_Multiple(num2);
	num3 = Multiple_times_Multiple(num3,num1,num2);
	Multiple_output(num1);
	Multiple_output(num2);
	Multiple_output(num3);
	//Multiple_output(num3);

}

//四則演算

//割り算


//足し算はできてる
Multiple Multiple_add(Multiple ans,Multiple num1,Multiple num2){
	int i,tmp;
	int move_up=0;
	ans.len = max(num1.len,num2.len);
	for(i=0;i<ans.len;i++){
		tmp = num1.num[i] + num2.num[i] + move_up;
		if(tmp > 9){
			ans.num[i] = tmp - 10;
			move_up = 1; 
		}else{
			ans.num[i] = tmp;
			move_up = 0;
		}
	}
	if(move_up == 1){
		ans.len++;
		ans.num[ans.len-1] = 1;
	}
	
	Multiple_surplus(ans);
	return ans;
}

//変数とMultipleの掛け算
Multiple Multiple_times_int(Multiple ans,Multiple num1,int times){
	int i,tmp;
	int move_up=0;
	ans.len = num1.len;
	for(i=0;i<ans.len;i++){
		tmp = num1.num[i] * times + move_up;
		if(tmp/10 == 0){
			ans.num[i] = tmp;
			move_up = 0;
		}else{
			move_up = tmp / 10;
			ans.num[i] = tmp % 10;
		}
	}
	if(move_up != 0){
		ans.len++;
		ans.num[ans.len-1] = move_up;
	}
	return ans;

}

//Multiple同士の掛け算
Multiple Multiple_times_Multiple(Multiple ans,Multiple num1,Multiple num2){ //変数との掛け算を利用しまくる
	int i;
	Multiple tmp;
	ans = Multiple_init(ans);
	for(i=0;i<num2.len;i++){
		tmp = Multiple_init(tmp);
		tmp = Multiple_times_int(tmp,num1,num2.num[i]);
		//tmpをiの大きさ分右にシフトし,num[0]に0をいれる関数をここで実行
		tmp = Multiple_shift(tmp,i);
		ans = Multiple_add(ans,tmp,ans);
	}
	return ans;
}

Multiple Multiple_shift(Multiple num,int shift){
	int i,j;
	for(i=0;i<shift;i++){
		for(j=num.len-1;j>=0;j--){
			num.num[j+1] = num.num[j];
		}
		num.num[0] = 0;
		num.len++;
	}
	return num;
}

Multiple Multiple_init(Multiple num){
	int i;
	for(i=0;i<DIGIT;i++){
		num.num[i] = 0;
	}
	num.len = 0;
	return num;
}

//引き算(ans 側のほうが小さいことは考慮していない)
Multiple Multiple_sub_int(Multiple ans,Multiple num1,int sub){
	int i,j = 0;
	int move_up = 0;
	ans.len = num1.len;
	for(i=0;i<ans.len;i++){
		ans.num[i] = num1.num[i];
	}
	i = 0;
	do{
		if(num1.num[i] - move_up >= sub % 10){
			ans.num[i] = ans.num[i] - (sub % 10) - move_up;
			move_up = 0;
		}else{
			ans.num[i] = 10 + ans.num[i] - (sub % 10) - move_up;
			move_up = 1;
		}
		i++;
		sub = sub / 10;
		if(sub == 0){
		j++;
		}
	}while(j != 2);
	if(ans.num[i] == 0){
		ans.len--;
	}
	return ans;
}


/***************************************************************************                     ここから下は動く.あんまりさわらないこと
*************************************************************************/
int my_ctoi(char c){
	switch(c){
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
	}
}

Multiple Make_Multiple(Multiple num1){
	int i;
	printf("数字を入力してね\n");
	scanf("%s",num1.number);
	num1.len = strlen(num1.number);
	printf("len = %d\n",num1.len);
	for(i=num1.len-1;i>=0;i--){
		num1.num[i] = my_ctoi(num1.number[num1.len-1-i]);
	}
	Multiple_surplus(num1);
	return num1;
}

void Multiple_surplus(Multiple num1){
	int i;
	for(i=0;i<20;i++){
		num1.num[num1.len+i] = 0;
	}
}
void Multiple_output(Multiple num1){
	int i;
	printf("numは");
	for(i=num1.len-1;i>=0;i--){ //本来-1
		printf("%d",num1.num[i]);
	}
	printf("です\n");
}

int max(int a,int b){
	if(a>b){ return a; }
	else{return b; }
}











