#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int r[N];
int n;
int tot = 0;
int a[N];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> r[i];
	}
	sort(r+1, r+n+1);
	int pre = 0;
	for(int i=1;i<=n;i++){
		if(r[i]!=pre){
			tot++;
		}
		a[tot]++;
		pre = r[i];
	}
	if(tot==1){
		cout << a[1] << endl;
		return 0;
	}
	pre = a[1];
	for(int i=2;i<=n;i++){
		pre = max(pre, a[i]);
	}
	cout << pre << endl;
	
	return 0;
}
