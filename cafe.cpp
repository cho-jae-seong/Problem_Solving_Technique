#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;

int n,k,ans;
vector<pair<int,int> > v[100000];
int apt[100000],visit[100000];

int dfs(int x){
	int result=0,cnt=0;
	vector<pair<int,int> >::iterator it;
	visit[x]=1;
	for(it=v[x].begin();it!=v[x].end();it++){	
		int y=it->first;
		int w=it->second;
		if(visit[y])continue;
		int c_result=dfs(y);
		if(c_result<0)continue;
		cnt++;
		result+=c_result;
	}
	if(apt[x]){
		ans+=result+1;
		return 0;
	}
	result++;
	if(cnt>1){
		ans+=result;
		return 0;
	}
	else if(cnt==1){
		return result;
	}
	return -1;
}

int main(void){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n-1;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		x--;
		y--;
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	for(int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		x--;
		apt[x]=1;
	}
	dfs(0);
	printf("%d",ans);
	return 0;
}
