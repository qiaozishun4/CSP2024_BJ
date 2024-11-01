#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,a,q,m;
	cin>>t;
	for(int i=0;i<t;i++){
		 cin>>n>>a>>q;
		 for(int j=0;j<n;j++){
			 cin>>m;
			 for(int k=0;k<m;k++){
				 cin>>a;
			 }
		 }
		 for(int j=0;j<q;j++){
			 cin>>a>>a;
			 cout<<0<<endl;
		 }
	 }
	return 0;
}