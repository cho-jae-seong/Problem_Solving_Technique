#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector <pair<int,int> > v;
 
int n;
long long ans;

bool check(long long dist) { 
	int knots[100001] = { 0, };
	knots[0] = v[0].first; 
	for (int i = 0; i < n-1 ; i++) {
		if (dist <= v[i + 1].first - knots[i]) knots[i + 1] = v[i + 1].first; 		 
		else {
			if (knots[i] + dist > v[i + 1].first + v[i + 1].second) return false;
			else knots[i + 1] = knots[i] + dist;
		}
	}
	return true;
}
int main(void) {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		int x,l;
		scanf("%d%d",&x,&l);
		v.push_back(make_pair(x,l));
	} 
	sort(v.begin(), v.end());
	long long l = 0;
	long long r = 10000000000;
	while (l<= r) { 
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%lld",ans);
	return 0;
}
