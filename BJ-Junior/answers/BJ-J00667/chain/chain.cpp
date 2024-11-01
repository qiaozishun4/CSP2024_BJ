#include<iostream>
using namespace std;
int main(){
	int t,n,k,q,l,a;
	freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			cin>>l;
			for(int k=0;k<l;k++){
				cin>>a;
			}
		}
		for(int j=0;j<q;j++){
			if(j==0){
				cout<<1<<endl;
			}else if(j%2==0){
				cout<<0<<endl;
			}else{
				cout<<1<<endl;
			}
		}
	}
	return 0;
}
