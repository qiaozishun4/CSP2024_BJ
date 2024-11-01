#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
stack<int> red, blue, rest, ts;
ll ans;
int T, n, x;
void Init(){
	while(!rest.empty())
		rest.pop();
	while(!red.empty())
		red.pop();
	while(!blue.empty())
		blue.pop();
	while(!ts.empty())
		ts.pop();
}
void clr(int t){
	while(!rest.empty()){
		ts.push(rest.top());
		rest.pop();
	}
	if(t==1){
		while(!ts.empty()){
			blue.push(ts.top());
			ts.pop();
		}
	}
	else{
		while(!ts.empty()){
			red.push(ts.top());
			ts.pop();
		}
	}
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> T;
	while(T--){
		Init();
		cin >> n;
		cin >> x;
		red.push(x);
		for(int i=1; i<n; ++i){
			cin >> x;
			if(red.top()==x){
				red.push(x);
				clr(1);
				ans+=x;
			}else if(blue.empty())
				blue.push(x);
			else if(blue.top()==x){
				blue.push(x);
				clr(2);
				ans+=x;
			}else{
				rest.push(x);
			}
		}
		cout << ans << '\n';
		ans=0;
	}
	return 0;
}