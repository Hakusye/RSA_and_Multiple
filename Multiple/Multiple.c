//クラスチックに書く
#include "Multiple.h"
//代入する値を仮引数にしないとポインタの関係上事故る
//四則演算
Multiple Multiple_devide_Multiple_quotient(Multiple ans, Multiple big_num, Multiple small_num){
	Multiple tmp;
	ans = Multiple_init(ans);
	tmp = Multiple_init(tmp);
	tmp = Multiple_add_Multiple(tmp,tmp,small_num);
	while( Multiple_big_true(big_num,tmp) == TRUE ){
		ans = Multiple_add_int(ans,ans,1);
		tmp = Multiple_add_Multiple(tmp,tmp,small_num);
	}
	return ans;
}

Multiple Multiple_devide_Multiple_remainder(Multiple ans, Multiple big_num, Multiple small_num ){
	Multiple tmp,big_tmp,small_tmp;
	tmp = Multiple_init(tmp);
	//ans = Multiple_init(ans);
	big_tmp = Multiple_copy(big_tmp,big_num);
	small_tmp = Multiple_copy(small_tmp,small_num);

	tmp = Multiple_add_Multiple(tmp,tmp,small_tmp);
	while( Multiple_big_true(big_tmp,tmp) == TRUE ){  
		tmp = Multiple_add_Multiple(tmp,tmp,small_tmp);
	}
	tmp = Multiple_sub_Multiple(tmp,tmp,small_tmp);
	ans = Multiple_sub_Multiple(ans,big_tmp,tmp);
	return ans;
}

int Multiple_big_true(Multiple big_num,Multiple small_num){
	int i = big_num.len;
	if(big_num.len > small_num.len){
		return TRUE;
	}else if(big_num.len < small_num.len){
		return FALSE;
	}else{
		while(big_num.num[i] == small_num.num[i] && i >= 0){ i--; }
		if( big_num.num[i] >= small_num.num[i] ){ return TRUE; }
		else if(big_num.num[i] < small_num.num[i]){ return FALSE; }
	}
	printf("この処理はありえないので一旦離脱\n");
	exit(1);
}


//足し算はできてる
Multiple Multiple_add_int(Multiple ans, Multiple num1, int num2){
	int i=0,j=0;
	int move_up=0;
	ans = Multiple_copy(ans,num1);
	do{
		if(num1.num[i] + (num2 % 10) + move_up < 10){
			ans.num[i] = ans.num[i] + (num2 % 10) + move_up;
			move_up = 0;
		}else{
			ans.num[i] = ans.num[i] + (num2 % 10) - 10 + move_up;
			move_up = 1;
		}
		num2 = num2 / 10;
		if(num2 == 0){
			j++;
		}
		i++;
	}while(j != 2);
	if(move_up == 1){
		ans.len++;
	}
	ans = Multiple_surplus(ans);
	return ans;
}

Multiple Multiple_copy(Multiple ans,Multiple num1){
	int i = 0;
	ans.len = num1.len;
	for(i=0;i<ans.len;i++){
		ans.num[i] = num1.num[i];
	}
	ans = Multiple_surplus(ans);
	return ans;
}

Multiple Multiple_add_Multiple(Multiple ans,Multiple num1,Multiple num2){
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
	
	ans = Multiple_surplus(ans);
	return ans;
}

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

Multiple Multiple_times_Multiple(Multiple ans,Multiple num1,Multiple num2){ //変数との掛け算を利用しまくる
	int i;
	Multiple tmp;
	ans = Multiple_init(ans);
	for(i=0;i<num2.len;i++){
		tmp = Multiple_init(tmp);
		tmp = Multiple_times_int(tmp,num1,num2.num[i]);
		//tmpをiの大きさ分右にシフトし,num[0]に0をいれる関数をここで実行
		tmp = Multiple_shift(tmp,i);
		ans = Multiple_add_Multiple(ans,tmp,ans);
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
	num.len = 1;
	return num;
}

//引き算(num1 側のほうが小さいことは考慮していない)
Multiple Multiple_sub_int(Multiple ans,Multiple num1,int sub){
	int i,j = 0;
	int move_up = 0;
	ans = Multiple_copy(ans,num1);
	i = 0;
	do{
		if(ans.num[i] - move_up >= sub % 10){
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

	if(ans.num[ans.len-1] == 0 && ans.len != 1){
		ans.len--;
	}
	return ans;
}

//num1が小さいことは考慮してない
Multiple Multiple_sub_Multiple(Multiple ans, Multiple num1, Multiple num2){
	int i,tmp;
	int move_up=0;
	ans = Multiple_copy(ans,num1);
	for(i=0;i<ans.len;i++){
		if(ans.num[i] - move_up >= num2.num[i]){
			ans.num[i] = ans.num[i] - num2.num[i] - move_up;
			move_up = 0;
		}else{
			ans.num[i] = 10 + ans.num[i] - num2.num[i] -move_up;
			move_up = 1;
		}
	}
	while(ans.num[ans.len-1] == 0){
		if(ans.len != 1){
			ans.len--;
		}else{
			break;
		}
	}
	ans = Multiple_surplus(ans);
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
//	printf("len = %d\n",num1.len);
	for(i=num1.len-1;i>=0;i--){
		num1.num[i] = my_ctoi(num1.number[num1.len-1-i]);
	}
	num1 = Multiple_surplus(num1);
	return num1;
}

Multiple Multiple_surplus(Multiple num1){
	int i;
	for(i=0;i<20;i++){
		num1.num[num1.len+i] = 0;
	}
	return num1;
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




