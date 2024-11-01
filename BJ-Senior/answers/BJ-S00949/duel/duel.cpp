#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n;
int a[N];

int cnt,cur=1;
int main(){
	ios::sync_with_stdio(0);
	#ifndef M_D
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	#endif
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;++i){
		if(a[cur]<a[i]){
			++cur;
		}
	}
	cout << n-cur+1;
	return 0;
}
