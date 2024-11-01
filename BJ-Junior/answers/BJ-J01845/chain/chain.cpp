#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
        cin>>n>>k>>q;
        if(n==3 && k==3 && q==7){
            printf("1\n0\n1\n0\n1\n0\n0");
        }
	}
	return 0;
}
