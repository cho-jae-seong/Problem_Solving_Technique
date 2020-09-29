#include<stdio.h>
#include<vector>
using namespace std;
unsigned long long f[3001];
//201621427 조재성 컴퓨터정보공학부 
int main(void){
	int n;
	unsigned long long ans=1;//정답을 출력하기 위한 변수 
	unsigned long long cnt;//현재 값보다 작은 수들을 카운트하기 위한 변수 
	unsigned long long k=0;//팩토리얼을 위한 변수 
	scanf("%d",&n);
	vector<int> v(n);
	f[0]=1;//팩토리얼 초기화 
	for(int i=1;i<3001;i++){//미리 팩토리얼을 배열에 넣어준다 문제와 계산 범위에 의거하여 12377의 나머지 연산을 해준다 
		f[i]=(f[i-1]*i)%12377;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	if(n==1)printf("1\n");//1개라면 반드시 1이 답 
	else if(n==2){//2개라면 앞 뒤 숫자크기 비교 후 1 or 2 를 출력 
		if(v[0]<v[1])printf("1\n");
		else printf("2\n");
	}
	else{//3개 이상부터 
		for(int i=n-2;i>=0;i--){//수들을 일렬로 나열했을 때 맨 오른쪽을 기준으로 
			cnt=0;//두 번째 수부터 차례로 자신의 값보다 오른쪽 수들 중 작은 값이 있으면 카운트 한다 
			k++;//카운트 한 값만큼 기존에 구한 팩토리얼 값을 입력된 수의 크기에 알맞게 맞추어 곱해서 더해준다 
			for(int j=i+1;j<n;j++){
				if(v[i]>v[j])cnt++;
			}
			ans=ans+(cnt*f[k]);
		}
		printf("%llu\n",ans%12377);//정답 출력  
	}
	return 0;
}
