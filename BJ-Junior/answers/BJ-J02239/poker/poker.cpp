#include <bits/stdc++.h>
using namespace std;
#define int long long
map<string,int> mp;
string dis[52];
signed main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for(int i = 0;i<13;i++)	dis[i]+='D';
	for(int i = 13;i<26;i++) dis[i]+='C';
	for(int i = 26;i<39;i++) dis[i]+='H';
	for(int i = 39;i<52;i++) dis[i]+='S';
	dis[0] += 'A';
	dis[13] += 'A';
	dis[26] += 'A';
	dis[39] += 'A';
	for(int i = 0;i<52;i+=13)
		dis[i+9] += 'T',dis[i+10] += 'J',dis[i+11] += 'Q',dis[i+12] += 'K';
	for(int i = 0;i<52;i+=13) {
		int k = '2';
		for(int j = i+1;j<i+9;j++)
			dis[j] += k,k++;
	}
	//for(int i = 0;i<52;i += 13) {
	//	for(int j = i;j<i+13;j++)
	//		cout<<dis[j]<<' ';
	//	cout<<endl;
	//}
	int n;cin>>n;
	for(int i = 1;i<=n;i++) {
		string s;cin>>s;
		mp[s]++;
	}
	int ans = 0;
	for(int i = 0;i<52;i++)
		if(mp[dis[i]]==0)
			ans++;
	cout<<ans<<endl;
	return 0;
}