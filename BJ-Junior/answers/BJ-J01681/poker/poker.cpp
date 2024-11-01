#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		mp[a]++;
	}
	cout<<52-mp.size();
	return 0;
}
