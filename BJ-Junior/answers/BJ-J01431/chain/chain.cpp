#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);	
	cin>>t;
	for(ll i=1;i<=t;i++){
		if(i%2==0)
			printf("0\n");
		else
			printf("1\n");
	}
	
	return 0;
}
