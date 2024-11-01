#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 5;
const ld eps = 1e-10;

int d[N], a[N], u[N];
int p[N];

ld x[N], y[N];

struct node{
	int l, r;
	bool operator < (const node& cmp) const{
		return r < cmp.r;
	}
}edge[N];
int tot;

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while(T--){
		tot = 0;
		int n, m, L, V;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(int i = 1; i <= n; i++) scanf("%d%d%d", d + i, u + i, a + i);
		for(int i = 1; i <= m; i++) scanf("%d", p + i);
		
		for(int i = 1; i <= n; i++){
//			cout << "i : " << i << endl;
			//左端点
			if(a[i] > 0){
//				cout << "\ta[i] > 0\n" << endl;
				ld l = 0, r = L - d[i], best = -1;
//				cout << l << " " << r << endl;
				while(fabs(r) - fabs(l) > eps){
					ld mid = (l + r) / 2;
					ld now = sqrtl(u[i] * u[i] + 2 * a[i] * mid);
					if(now - V > eps){
						best = mid;
						r = mid;
					}
					else l = mid;
//					printf("\t\tl : %.15Lf r : %.15Lf mid : %.15Lf best : %.15Lf\n", l, r, mid, best);
//					printf("\t\tfabs(l) : %Lf fabs(r) : %Lf\n", fabs(l), fabs(r));
//					getchar();
				}
				x[i] = d[i] + best;
			}
			else if(a[i] < 0){
//				cout << "\ta[i] <= 0\n" << endl;
				ld l = 0, r = L - d[i], best = -1;
				while(fabs(r) - fabs(l) > eps){
					ld mid = (l + r) / 2;
					ld now = sqrtl(u[i] * u[i] + 2 * a[i] * mid);
					if(now - V > eps){
						best = mid;
						r = mid;
					}
					else r = mid;
//					printf("\t\tl : %.15Lf r : %.15Lf mid : %.15Lf best : %.15Lf\n", l, r, mid, best);
				}
				x[i] = d[i] + best;
			}
			else{
				if(u[i] <= V) x[i] = -1;
				else x[i] = d[i];
			}
//			cout << "left ok\n" << endl;
			
			//右端点
			if(a[i] > 0){
				ld l = 0, r = L - d[i], best = -1;
				while(fabs(r) - fabs(l) > eps){
					ld mid = (l + r) / 2;
					ld now = sqrtl(u[i] * u[i] + 2 * a[i] * mid);
					if(now - V > eps){
						best = mid;
						l = mid;
					}
					else l = mid;
//					printf("\t\tl : %.15Lf r : %.15Lf mid : %.15Lf best : %.15Lf\n", l, r, mid, best);
				}
				y[i] = d[i] + best;
			}
			else if(a[i] < 0){
				ld l = 0, r = L - d[i], best = -1;
				while(fabs(r) - fabs(l) > eps){
					ld mid = (l + r) / 2;
					ld now = sqrtl(u[i] * u[i] + 2 * a[i] * mid);
					if(now - V > eps){
						best = mid;
						l = mid;
					}
					else r = mid;
//					printf("\t\tl : %.15Lf r : %.15Lf mid : %.15Lf best : %.15Lf\n", l, r, mid, best);
				}
				y[i] = d[i] + best;
			}
			else{
				if(u[i] <= V) y[i] = -1;
				else y[i] = L;
			}
						
//			cout << "right ok\n" << endl;
//			printf("%.15Lf %.15Lf\n", x[i], y[i]);
		}
		
		int ans1 = 0, ans2 = 0;
		for(int i = 1; i <= n; i++){
			if(x[i] == -1 || y[i] == -1) continue;
			
			int a, b;
			
			int l = 1, r = n, best = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(p[mid] - x[i] >= -eps){
					best = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			a = best;
			
			l = 1, r = n, best = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(y[i] - p[mid] >= -eps){
					best = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			b = best;
			
//			cout << a << " " << b << endl;
			
			if(b >= a){
				edge[++tot] = {a, b};
				ans1++;
			}
		}
		
		sort(edge + 1, edge + 1 + tot);
		int R = 0;
		for(int i = 1; i <= tot; i++){
			if(edge[i].l > R){
				ans2++;
				R = edge[i].r;
			}
		}
		
		printf("%d %d\n", ans1, m - ans2);
	}
	
	return 0;
}