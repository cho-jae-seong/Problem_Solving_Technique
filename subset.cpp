#include<stdio.h>

int p[10000],q[10000];

void check(int n,int k){
	int x,y;
	for(x=0;x<n-k;x++){
		int z=0;
		printf(" ");
		for(y=1;y<=n;y++){
			if(q[y]==1)printf("%02d",y);
			else if(q[y]==0&&z==0){
				printf("%02d",y);
				q[y]=2;
				z=1;
			}
		}
	}
}

void reset(int n){
	int x=0;
	for(x=1;x<=n;x++){
		q[x]=0;
	}
}

void subset(int n,int k,int i,int j){
	if(k==i){
		while(j<=n){
			p[i]=j;
			q[j]=1;
			int x=1;
			for(x=1;x<=k;x++){
				printf("%02d",p[x]);
				q[p[x]]=1;
			}
			check(n,k);
			reset(n);
			printf("\n");
			j++;
		}
	}else{
		while(j<=n-k+i){
			p[i]=j;
			subset(n,k,i+1,++j);
		}
	}
}

int main(void){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==0){
		int x=0;
		while(x<n)printf("%02d ",x++);
		printf("%02d",x);
	}else{
		subset(n,k,1,1);
	}
	return 0;
}
