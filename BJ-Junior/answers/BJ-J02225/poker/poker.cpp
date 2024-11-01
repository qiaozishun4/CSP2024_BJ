#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,ll>m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ll n,sum=0;
	cin>>n;
	string str;
	while(n--){
		cin>>str;
		m[str]=1;
	}
	for(auto num:m){
		++sum;
	}
	cout<<52-sum<<endl;
	return 0;
}
