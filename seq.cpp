#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
//201621427 조재성 컴퓨터정보공학부 
int main(void){
	int n,num;//입력 받을 n과 벡터에 넣어줄 숫자num 
	vector<int> v;//초기에 입력받은 원소들을 저장할 vector v 
	vector<int> v2;//등차수열 확인 후 나머지 원소들을 저장할 vector v2 
	vector<int> v3;//등차수열인지 확인 후 원소들을 저장할 vector v3  
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		v.push_back(num);
	}
	sort(v.begin(),v.end());//오름차순으로 정렬 
	if(n==2){//n이 2,3,4 인 경우는 무조건적으로 등차수열이 생성되므로 아래와 같이 출력한다. 
		printf("1\n");
		printf("%d\n",v[0]);
		printf("1\n");
		printf("%d\n",v[1]);
	}
	else if(n==3){
		printf("1\n");
		printf("%d\n",v[0]);
		printf("2\n");
		printf("%d %d\n",v[1],v[2]);
	}
	else if(n==4){
		printf("2\n");
		printf("%d %d\n",v[0],v[1]);
		printf("2\n");
		printf("%d %d\n",v[2],v[3]);
	}
	else{//그 외에 n이 5이상은 아래와 같다. 
		int idx;//등차수열의 인덱스 확인용 변수 
		int cnt;//개수 확인용 변수 
		int check[100001];//등차수열을 두 부분으로 나누기 위한 체크 배열 
		int diff;//공차를 나타내기 위한 변수 
		int ccnt=1;//첫 원소를 제외한 나머지 원소들이 등차수열을 이룰 때 개수 체크용 변수 
		int ddiff=v[2]-v[1];//위와 같은 경우의 공차를 나타내기 위한 변수 
		for(int i=3;i<n;i++){//공차를 구하다가 하나라도 다르면 바로 break 
			if(ddiff!=v[i]-v[i-1])break;
			else ccnt++;
		}//위와 같은 가정이 만족될 때 출력하고 바로 종료 
		if(ccnt==n-2){
			printf("1\n");
			printf("%d\n",v[0]);
			printf("%d\n",n-1);
			for(int i=1;i<n;i++){
				printf("%d ",v[i]);
			}
			exit(0);
		}//첫 번째 원소는 두 등차수열 부분 중 어느 한 부분에라도 속하므로 첫 원소를 기준으로 등차수열을 판별 
		for(int i=1;i<n;i++){//
			memset(check,0,sizeof(check));//체크 배열은 매번 초기화 
			diff=v[i]-v[0];//공차 
			check[i]=check[0]=1;//체크 
			idx=i;//인덱스 
			cnt=2;//개수 
			v2.clear();//초기화 
			v3.clear();//초기화 
			v3.push_back(v[0]);v3.push_back(v[i]);//확정적인 두 원소는 미리 저장 
			for(int k=0;k<n;k++){//나머지 체크 안된 원소들을 저장 
				if(check[k]==0)v2.push_back(v[k]);
			}
			if(v2.size()==1||v2.size()==2){//크기가 1 or 2 라면 반드시 성립하므로 아래와 같이 출력 후 바로 종료 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
			}
			else{//크기가 3 이상이라면 
				int count=1;
				int dif=v2[1]-v2[0];
				for(int l=2;l<v2.size();l++){//등차수열인지 판별한다. 
					if(dif!=v2[l]-v2[l-1])break;//아니면 바로 break 
					else count++;
				}
				if(count==v2.size()-1){//등차수열이라면 아래와 같이 출력 후 바로 종료 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
				}
			}
			memset(check,0,sizeof(check));//체크 배열은 매번 초기화
			check[i]=check[0]=1;//체크
			v2.clear();//초기화
			for(int j=i+1;j<n;j++){
				if(diff<v[j]-v[idx])break;//원하는 공차보다 크면 바로 break 
				else if(diff==(v[j]-v[idx])){//공차와 동일하다면 원소 저장 후 체크,인덱스 저장,개수 추가 
					v3.push_back(v[j]);
					check[j]=1;
					idx=j;
					cnt++;
					for(int k=0;k<n;k++){//나머지 체크 안된 원소들을 저장 
				if(check[k]==0)v2.push_back(v[k]);
			}
			if(v2.size()==1||v2.size()==2){//크기가 1 or 2 라면 반드시 성립하므로 아래와 같이 출력 후 바로 종료 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
			}
			else{//크기가 3 이상이라면 
				int count=1;
				int dif=v2[1]-v2[0];
				for(int l=2;l<v2.size();l++){//등차수열인지 판별한다. 
					if(dif!=v2[l]-v2[l-1])break;//아니면 바로 break 
					else count++;
				}
				if(count==v2.size()-1){//등차수열이라면 아래와 같이 출력 후 바로 종료 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
				}
			}
			v2.clear();//초기화
				}
				else continue;//공차보다 작다면 무시하고 다음 원소 진행 
			}
			for(int k=0;k<n;k++){//나머지 체크 안된 원소들을 저장 
				if(check[k]==0)v2.push_back(v[k]);
			}
			if(v2.size()==1||v2.size()==2){//크기가 1 or 2 라면 반드시 성립하므로 아래와 같이 출력 후 바로 종료 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
			}
			else{//크기가 3 이상이라면 
				int count=1;
				int dif=v2[1]-v2[0];
				for(int l=2;l<v2.size();l++){//등차수열인지 판별한다. 
					if(dif!=v2[l]-v2[l-1])break;//아니면 바로 break 
					else count++;
				}
				if(count==v2.size()-1){//등차수열이라면 아래와 같이 출력 후 바로 종료 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
				}
			}
		}
		printf("-1\n");
	}
	return 0;
}
