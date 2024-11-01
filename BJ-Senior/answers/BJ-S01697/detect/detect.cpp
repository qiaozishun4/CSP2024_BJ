#include<bits/stdc++.h>
using namespace std;

int n,m,L,V,t;
int d[120000],v[120000],a[120000],p[120000];
int vp[120000][120000];
bool vis[120000];

void func(){
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(p[i]-d[j] < 0){
				break;
			}
			vp[i][j] = sqrt((v[j]*v[j]+2*a[j]*(p[i]-d[j])));
		}
	}
}

int solve1(){
	for(int i = 0; i <= n; i++){
		vis[i] = 0;
	}
	int ans1 = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if((vp[i][j] > V) && (vis[j] == 0)){
				ans1++;
				vis[j] = 1;
			}
		}
	}
	return ans1;
}

int solve2(){
	int ans2 = 0;
	int f = 0;
	for(int i = 1; i <= m; i++){
		f = 0;
		for(int j = 1; j <= n; j++){
			if(vp[i][j] < V){
				f++;
			}
		}
		if(f == n){
			ans2++;
		}
	}
	return ans2;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    for(int i = 1; i <= t; i++){
		cin >> n >> m >> L >> V;
		for(int j = 1; j <= n; j++){
			cin >> d[j] >> v[j] >> a[j];
		}
		for(int j = 1; j <= m; j++){
			cin >> p[j];
		}
		func();
		cout << solve1() << ' ' << solve2() << endl;
	}
    return 0;
}
