#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp1(const pair<long long int, long long int> &a, const pair<long long int, long long int> &b)
{
	if(a.first==b.first){//y가 작은 것 부터 
		return a.second<b.second;
	}
    return a.first > b.first;//x가 큰 거 부 터 
}

bool cmp2(const pair<long long int, long long int> &a, const pair<long long int, long long int> &b)
{
	if(a.first==b.first){//y가 작은 것 부터 
		return a.second<b.second;
	}
    return a.first < b.first;//x가 작은 거 부터 
}

int main(void){
	int n1,n2;
	int minx1=2147483647,minx2=2147483647;
	int miny1=2147483647,maxy1=-2147483647-1;
	int miny2=2147483647,maxy2=-2147483647-1;
	int count=0;
	long long ans=9223372036854775807;
	vector<pair<long long int,long long int> >v1;
	vector<pair<long long int,long long int> >v2;
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		minx1=min(minx1,x);
		miny1=min(miny1,y);
		maxy1=max(maxy1,y);
		v1.push_back(make_pair(x,y));
	}
	scanf("%d",&n2);
	for(int i=0;i<n2;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		minx2=min(minx2,x);
		miny2=min(miny2,y);
		maxy2=max(maxy2,y);
		v2.push_back(make_pair(x,y));
	}
	if(maxy1<miny2){
		printf("-1");
		return 0;
	}
	else if(miny1>maxy2){
		printf("-1");
		return 0;
	}
	if(minx1<minx2){
		sort(v1.begin(),v1.end(),cmp1); 
		sort(v2.begin(),v2.end(),cmp2);
	}
	else{
		sort(v1.begin(),v1.end(),cmp2);
		sort(v2.begin(),v2.end(),cmp1);
	}
	for(int i=0;i<n1;i++){
		int cnt=0;
		for(int j=0;j<n2;j+=2){
			if(v1[i].second>=v2[j].second&&v1[i].second<=v2[j+1].second){
				if(v1[i].first<=v2[j].first&&v1[i].second>v2[j].second)cnt++;
				ans=min(ans,abs(v1[i].first-v2[j].first));
			}
			else continue;
		}
		if(cnt==1)count++;
	}
	if(ans==9223372036854775807||count==0||count==n1){
		count=0;
		for(int i=0;i<n2;i++){
			int cnt=0;
			for(int j=0;j<n1;j+=2){
				if(v2[i].second>=v1[j].second&&v2[i].second<=v1[j+1].second){
					if(v2[i].first<=v1[j].first)cnt++;
					ans=min(ans,abs(v2[i].first-v1[j].first));
				}
				else continue;
			}
			if(cnt==1)count++;
		}		
	}
	else{
		printf("0");
		return 0;
	}
	if(count>0&&count<n2){
		printf("0");
		return 0;
	}
	printf("%lld",ans);
	return 0;
}
