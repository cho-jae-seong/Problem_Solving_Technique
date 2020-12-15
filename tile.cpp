#include<stdio.h>
#include<vector>
using namespace std;

int n;
char pattern[31];

int generatePattern(int k,int type){
	int newType;
	if(k==n){
		printf("%s\n", pattern);
		return 0;
	}
	// k < n
	if ((type != 2) && (k <= n-2)) {
		pattern[k] = pattern[k+1] = '=';
		generatePattern(k+2, 2);
	}
	// k <= n-1
	if (type != 11) { 
		pattern[k] = '|'; 
		if (type == 21) newType = 11;
		else newType = 21;
		generatePattern(k+1, newType);
	}
	return 0;
}

int main(void){
	vector<int>v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	scanf("%d",&n);
	for(int i=6;i<=n;i++){
		v.push_back((v[i-4]%20201212)+(v[i-3]%20201212));
	}
	printf("%d\n",v[n]%20201212);
	if(n<31){ 
		pattern[n] = '\0';
		generatePattern(0, -1);
	}
	return 0;
}
