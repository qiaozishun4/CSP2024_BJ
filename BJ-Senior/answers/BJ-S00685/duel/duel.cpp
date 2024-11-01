#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N], n;
long long ans;
queue<int>  ali, atk;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i){
		ali.push(a[i]);
		atk.push(a[i]);
	}
	while(!atk.empty())
	{
		int x=ali.front(), y=atk.front();
		if(x<y){
			ali.pop();
			atk.pop();
		}else
			atk.pop();
	}
	cout << ali.size() << '\n';
	return 0;
}