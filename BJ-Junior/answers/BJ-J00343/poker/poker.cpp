#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ll n,m,i;
	char s1,s2;
	set<char> s;
	set<char> x;
	cin>>n;
	m=n;
	for(i=1;i<=n;i++){
		cin>>s1>>s2;
		if(s.count(s1)&&x.count(s2)) m--;
		s.insert(s1);
		x.insert(s2);
	}
	cout<<52-m;
	return 0;
}