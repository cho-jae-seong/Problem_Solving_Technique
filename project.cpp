#include<stdio.h>
#include<algorithm>
#include<deque>
using namespace std;

int main(void){
	int n,skill,min=0;
	int ans=2147000000;
	deque<int> d;
	scanf("%d",&n);
	for(int i=0;i<n*2;i++){
		scanf("%d",&skill);
		d.push_back(skill);
	}
	sort(d.begin(),d.end());
	for(int i=0;i<n;i++){
		min=0;
		min+=d.front();
		d.pop_front();
		min+=d.back();
		d.pop_back();
		if(ans>min)ans=min;
	}
	printf("%d",ans);
	return 0;
}
