#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i*7<=n;i++)cout<<8;
		cout<<endl;
	}
    return 0;
}