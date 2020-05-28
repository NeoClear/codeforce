#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;
 
int m;
int n, t, a[2];
pair<int, int> p[200005];
 
int main(){
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d%d%d", &n, &t, &a[0], &a[1]);
		for(int i=1;i<=n;++i) scanf("%d", &p[i].second);
		for(int i=1;i<=n;++i) scanf("%d", &p[i].first);
		int b[2] = {};
		for(int i=1;i<=n;++i) b[p[i].second]++;
		int c[2] = {};
		sort(p+1, p+n+1);
		int s = 0;
		int ans = 0;
		for(int i=1;i<=n;++i) {
			int k = min(b[0]-c[0], (p[i].first - s - 1)/a[0]);
			int l = min(b[1]-c[1], (p[i].first - s - a[0]*k - 1)/a[1]);
			k = max(0, k);
			l = max(0, l);
			if(p[i].first > s) ans = max(ans, k+l+i-1);
			s += a[p[i].second];
			c[p[i].second]++;
			if(s > t) break;
			if(i==n) ans = n;
		}
		printf("%d\n", ans);
	}
}
