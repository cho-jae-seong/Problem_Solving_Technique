#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
//201621427 조재성 컴퓨터정보공학부 
int main(void){
	vector<pair<int,int> >v;//(경과시간,방향)을 저장하기 위한 벡터 쌍 
	vector<pair<int,int> >v2;//(초기위치,가중치)을 저장하기 위한 벡터 쌍 
	deque<int>dq;//가중치를 저장하기 위한 deque 
	int n,b,w,x,d,check=0;
	int ans=0;//쉼터로 들어간 개미 로봇의 가중치와 전체 개미 로봇 가중치 합의 반과 비교하기 위한 변수 
	double sum=0;//전체 개미 로봇 가중치 합의 반을 나타낼 변수 
	scanf("%d%d",&n,&b);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&w,&x,&d);
		sum+=w;
		if(d<0)v.push_back(make_pair(x,d));//방향에 맞추어서 (경과시간,방향)으로 저장한다. 
		else v.push_back(make_pair(b-x,d)); 
		v2.push_back(make_pair(x,w));//(초기위치,가중치) 저장. 
	}
	sum/=2;
	sort(v.begin(),v.end());//경과시간에 맞게 오름차순 정렬
	sort(v2.begin(),v2.end());//초기위치에 맞게 오름차순 정렬
	for(int i=0;i<v2.size();i++){//deque에 가중치를 넣어준다. 
		dq.push_back(v2[i].second);
	} 
	for(int i=0;i<n;i++){//정렬된 경과시간에 의해 방향에 따라 가중치를 더해 나가면서 문제 조건을 만족할 시 답을 출력. 
		if(v[i].second<0){//방향이 왼쪽이라면 
			ans+=dq.front();//가중치의 왼쪽값을 더해준다. 
			if(ans>=sum){//조건에 만족하면 정답을 출력하고 종료. 
				printf("%d\n",v[i].first);
				break;
			}
			else dq.pop_front();
		}
		else{//방향이 오른쪽이라면 
			ans+=dq.back();//가중치의 오른쪽값을 더해준다. 
			if(ans>=sum){//조건에 만족하면 정답을 출력하고 종료. 
				printf("%d\n",v[i].first);
				break;
			}
			else dq.pop_back();
		}
	}
	return 0;
}
