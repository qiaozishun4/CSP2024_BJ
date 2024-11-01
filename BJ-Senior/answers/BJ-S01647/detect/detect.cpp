#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int T;
int n, m, L, V;
struct node{
	int d, v, a;
	double est = -1;
	double eed = -1;
}c[MAXN];
int p[MAXN];
double iup(double x){
	int xx = x;
	if(x == xx){
		return x + 1;
	} else {
		return ceil(x);
	}
}
double idown(double x){
	int xx = x;
	if(x == xx){
		return x - 1;
	} else {
		return floor(x);
	}
}
int pcf[MAXN];
int sum;
int Ccf[MAXN];
int cnt;
bool ifall0 = true, ifall1 = true;
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		
		sum = 0;
		cnt = 0;
		memset(pcf, 0, sizeof(pcf));
		memset(Ccf, 0, sizeof(Ccf));
		
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
			if(c[i].a == 0){
				
				if(c[i].v > V){
					c[i].est = c[i].d;
					c[i].eed = L + 5;
				}
				
			} else if(c[i].a > 0){
				
				ifall0 = false;
				if(c[i].v > V){
					c[i].est = c[i].d;
					c[i].eed = L;
				} else if(c[i].v == V){
					c[i].est = c[i].d + 1;
					c[i].eed = L;
				} else if(c[i].v < V){
					c[i].est = iup((double)c[i].d + (double)(V*V-c[i].v*c[i].v) / (double)(2*c[i].a));
					c[i].eed = L;
				}
				
			} else if(c[i].a < 0){
				
				ifall0 = false;
				ifall1 = false;
				if(c[i].v > V){
					c[i].est = c[i].d;
					c[i].eed = idown((double)c[i].d + (double)(V*V-c[i].v*c[i].v) / (double)(2*c[i].a));
				}
				
			}
		}
		
		for(int i = 1; i <= m; i++){
			scanf("%d", &p[i]);
			pcf[p[i]]++;
		}
		sort(p + 1, p + 1 + m);
		if(ifall0 == true || ifall1 == true){
			for(int i = 1; i <= n; i++){
				if(c[i].est > p[m] || c[i].est == -1) sum++;
			}
			sum = n - sum;
		} else {
			for(int i = 1; i <= L; i++){
				pcf[i] += pcf[i-1];
			}
			for(int i = 1; i <= n; i++){
				if(c[i].est == -1) continue;
				if(pcf[(int)(c[i].est)] == pcf[(int)(c[i].eed)]) continue;
				sum++; 
			}
		}
		
		printf("%d ", sum);
		if(ifall0 == true || ifall1 == true){
			printf("%d\n", m-1);
		}
	}
	return 0;
}

