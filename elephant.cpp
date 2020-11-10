#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int dx[8] = {3, 3, -3, -3, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 3, -3, 3, -3};
queue<pair<int,pair<int,int> > >q;

int main(void){
	int cur_x,cur_y,tar_x,tar_y;
	int distx,disty;
	int visited[100][100]={0};
	scanf("%d%d",&cur_x,&cur_y);
	scanf("%d%d",&tar_x,&tar_y);
	distx=abs(tar_x-cur_x);
	disty=abs(tar_y-cur_y);
	if(cur_x==tar_x&&cur_y==tar_y){
		printf("2");
		return 0;
	}
	if(cur_x>tar_x){
		int temp=cur_x;
		cur_x=tar_x;
		tar_x=temp;
	}
	if(cur_y>tar_y){
		int temp=cur_y;
		cur_y=tar_y;
		tar_y=temp;
	}
	if(distx<=3&&disty<=3){
		q.push(make_pair(0,make_pair(cur_x,cur_y)));
		while(!q.empty()){
		int x=q.front().second.first;
		int y=q.front().second.second;
		int cnt=q.front().first;
		q.pop();
		if(x==tar_x&&y==tar_y){
			printf("%d",cnt);
			return 0;
		}
		for(int i=0;i<8;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			q.push(make_pair(cnt+1,make_pair(nx,ny)));
			}
		}
	}
	else{
	q.push(make_pair(0,make_pair(cur_x,cur_y)));
	visited[cur_x][cur_y]++;
		while(!q.empty()){
		int x=q.front().second.first;
		int y=q.front().second.second;
		int cnt=q.front().first;
		q.pop();
		if(x==tar_x&&y==tar_y){
			printf("%d",cnt);
			return 0;
		}
		for(int i=0;i<8;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||ny<0||nx>100||ny>100)continue;
			if(visited[nx][ny])continue;
			visited[nx][ny]++;
			q.push(make_pair(cnt+1,make_pair(nx,ny)));
			}
		}
	}
	return 0;
}
