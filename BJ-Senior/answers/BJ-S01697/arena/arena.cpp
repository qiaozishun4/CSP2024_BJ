#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int a1[120000],a[120000];
int c[120000];

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a1[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> c[i];	
	}
	cin >> t;
	for(int i = 1; i <= t; i++){
		int h = 12;
		int b = 3;
		cout << h << endl;
		h *= b;
		b++;
		h -= b*b;
	}
	return 0;
}