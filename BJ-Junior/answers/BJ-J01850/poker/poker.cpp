#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+10;
int n;
string s;
map<string,int>mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>s;
		mp[s]=1;
	}
	cout<<52-mp.size()<<endl;
	return 0;
}
