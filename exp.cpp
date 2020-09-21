#include<stdio.h>
#include<algorithm>
using namespace std;
//201621427 조재성 컴퓨터정보공학부 
int main(void){
	int n;//입력받을 n 
	int sum1=0,sum2=0;//n=3일 때 최대값 구하기 위한 변수들 
	int maximum=-987654321;//결과값을 출력하기 위한 변수,최대값을 출력하기위해 초기값을 왼쪽과 같이 잡음 
	int num[1001];//숫자들을 입력받기 위한 배열 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	sum1=(num[1]-num[2])-num[3];
	sum2=num[1]-(num[2]-num[3]);
	maximum=max(sum1,sum2);//초기 3개의 숫자들만으로 최대값을 구한다. 
	if(n==3)printf("%d\n",maximum);//n=3이면 그대로 답을 출력 
	else{//n이 3 초과라면 그 이후의 숫자들을 더한다. 양수라면 그대로 더하고 음수라면 양수로 바꾸고 더한다. 
		for(int i=4;i<=n;i++){
			if(num[i]>=0)maximum+=num[i];
			else maximum+=(-1*num[i]);
		}
		printf("%d\n",maximum);//결과 출력 
	}
	return 0;
}
