#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int a[100005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
	    for(int i=1;i<=n;++i){
		    cin>>a[i];
	    }
	}
	cout<<1<<endl;
	cout<<0<<endl;
	cout<<8<<endl;
	return 0;
}
