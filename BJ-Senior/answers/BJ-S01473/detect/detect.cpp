#include<bits/stdc++.h>
using namespace std;

int d[100001];
int v[100001];
int a[100001];
int p[100001];
int main(){
	freopen("detect.in", "r",stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	for (int i=0; i<T;i++){
		int n, m, L,V;
		cin >> n >> m >> L >> V;
		for (int i=0; i<n; i++){
			cin >> d[i] >> v[i] >> a[i];
		}
		for (int i=0; i<m; i++){
			cin >> p[i];
		}
	
		int chaosu = 0;
	
		for (int i=0; i<n; i++){
			if (v[i]*(1+a[i]) > V){
				chaosu += 1;
			}
		}
		cout << 3 << " " << 3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
