#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll oo=3e18;
const int M=2;
int n;
string s;
map<string,int> mp;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		mp[s]++;
	}
	cout<<52ll-(ll)mp.size()<<"\n";
	return 0;
}
//LXT5201314