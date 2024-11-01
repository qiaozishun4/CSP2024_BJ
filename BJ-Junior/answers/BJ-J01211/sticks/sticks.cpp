//性质A 30tps
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		n=n/7;
		for(int i=1;i<=n;i++)
			cout<<8;
		cout<<endl;
	}
}
