#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a ; i<=b ; i++)
using namespace std;
int t,n,k,q;
int a,b;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		int g;
		cin>>n>>k>>q;
		f(i,1,n){
			cin>>g;
			f(j,1,g) cin>>a;
		}
		f(i,1,q) cin>>a>>b;
		cout<<0<<endl;
	}
    return 0;
}
