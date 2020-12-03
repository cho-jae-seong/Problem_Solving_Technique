#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

bool check=false;
long long int ans[2];
typedef pair<long long int, long long int> p;
priority_queue<p, vector<p>, greater<p> > pq;
vector<long long int> s;
vector<long long int> t;

int main(void){
	int n;
	long long int x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&x,&y);
		pq.push(make_pair(x,y));
	}
	long long int x1=0,y1=0,x2=0,y2=0,px=0,py=0,px2=0,py2=0,h=0,low=0,up=0,sum=0;
	while(!pq.empty()){
		x1=pq.top().first;
		y1=pq.top().second;
		pq.pop();
		if(h!=0){
			s.push_back((h*(x1-px)));
			sum+=h*(x1-px);
		}
		x2=pq.top().first;
		y2=pq.top().second;
		pq.pop();
		h=y2-y1;
		if(check){
			if(py==y2){
				up=py2;
				low=y1;
			}
			if(py==y1){
				up=py2;
				low=y2;
			}
			if(py2==y2){
				up=y1;
				low=py;
			}
			if(py2==y1){
				up=y2;
				low=py;
			}
			h=up-low;
		}
		if(!check){
			up=y2;
			low=y1;
			check=true;
		}
		px=x1;
		py=low;
		px2=x2;
		py2=up;
	}
	long long int min = 9223372036854775807;
	t.resize(s.size());
	t[0]=s[0];
	for(int i=1;i<s.size();i++){
		t[i]=s[i]+t[i-1];
	}
	for(int i=0;i<t.size();i++){
		long long int r=sum-t[i];
		if(min>abs(r-t[i])){
			min=abs(r-t[i]);
			ans[0]=t[i];
			ans[1]=r;
		}
	}
	sort(ans,ans+2);
	printf("%lld %lld",ans[0],ans[1]);
	return 0;
}
