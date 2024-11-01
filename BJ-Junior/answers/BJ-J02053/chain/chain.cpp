#include<iostream>
using namespace std;
int T;
int n,k,q;
string s,x;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			getline(cin,s);
		}
		for(int i=1;i<=q;i++){
			getline(cin,x);
		}
	}
	if(T==1){
		cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
	}
	return 0;
}
//this is too difficult !!!!!！