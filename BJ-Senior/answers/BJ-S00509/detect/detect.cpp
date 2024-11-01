#include <bits/stdc++.h>
using namespace std;
long long d[100050],v[100050],a[100050];
long long p[100050];
long long n,m,L,V;
inline double getspd(long long s,long long v,long long a){
	return sqrt(max(0.0,2.0 * a * s + v * v));
}
struct car {
	long long d,v,a;
	long long mi,mx;
}c[100050],c2[100050];
long long k = 0,k2;
bool cmp(car x,car y){
	return x.mx < y.mx;
}
inline long long read(){
	long long x = 0,f = 1;
	char ch = getchar();
	while (!isdigit(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
long long use[100050];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	long long T;
	T = read();
	while (T--){
		memset(use,0,sizeof(use));
		k = 0;
		k2 = 0;
		for (long long i = 0;i <= n;i++) c[i].d = c[i].v = c[i].a = c[i].mi = c[i].mx = 0;
		for (long long i = 0;i <= n;i++) c2[i].d = c2[i].v = c2[i].a = 0;
		n = read(),m = read(),L = read(),V = read();
		for (long long i = 1;i <= n;i++) d[i] = read(),v[i] = read(),a[i] = read();
		for (long long i = 1;i <= m;i++) p[i] = read();
		long long cnt = 0;
		for (long long i = 1;i <= n;i++){
			if (a[i] >= 0){
				if (p[m] < d[i]) continue;
				double rv = getspd(p[m] - d[i],v[i],a[i]);
				if (rv > V) cnt++,c2[++k2].d = d[i],c2[k2].v = v[i],c2[k2].a = a[i];
			} else if (a[i] < 0){
				long long x = lower_bound(p + 1,p + m + 1,d[i]) - p;
				double rv = getspd(p[x] - d[i],v[i],a[i]);
				if (rv > V) cnt++,c[++k].d = d[i],c[k].v = v[i],c[k].a = a[i],c[k].mi = x;
			}
		}
		cout << cnt << " ";
		for (long long i = 1;i <= k;i++){/*
			for (long long j = c[i].mi;j <= m;j++){
				double rv = getspd(p[j] - c[i].d,c[i].v,c[i].a);
				if (rv > V) c[i].mx = max(c[i].mx,j);
				else break;
			}*/
			long long l = c[i].mi,r = m;
			while (l <= r){
				long long mid = (l + r) >> 1;
				double rv = getspd(p[mid] - c[i].d,c[i].v,c[i].a);
				if (rv <= V) r = mid - 1;
				else l = mid + 1;
			}
			c[i].mx = l - 1;
		}
		sort(c + 1,c + k + 1,cmp);
		for (long long i = 1;i <= k;i++){
			long long p = c[i].mx;
			use[p]++;
			long long j = i;
			while (p >= c[j].mi && j <= k) j++;
			i = max(i,j - 1);
		}
		long long cnt2 = 0;
		long long last = 0;
		for (long long i = 1;i <= m;i++) if (use[i] != 0) cnt2++,last = max(last,i);
		long long flag = 0;
		for (long long i = 1;i <= k2;i++){
			if (p[last] < c2[i].d) flag = 1;
			double rv = getspd(p[last] - c2[i].d,c2[i].v,c2[i].a);
			if (rv <= V) flag = 1;
		}
		cout << m - cnt2 - flag << endl;
	}
	return 0;
}