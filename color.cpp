#include<stdio.h>

int main(void){
	int dp[10001];
	int n;
	scanf("%d",&n);
	dp[1]=2;dp[2]=2;
	for(int i=3;i<10001;i++){
		dp[i]=(dp[i-1]+dp[i-2])%10000;
	}
	printf("%d",dp[n]%10000);
	return 0;
}
