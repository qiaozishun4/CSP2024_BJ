#include<bits/stdc++.h>
using namespace std;
map<pair<char,char>,int>m;
int n,ans;
char t1,t2,p_l[4]={'D','C','H','S'},p_s[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>t1>>t2;
		m[{t1,t2}]++;
	}
	for(int i=0;i<4;i++) {
		for(int j=0;j<13;j++) {
			if(m[{p_l[i],p_s[j]}]==0) {
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}