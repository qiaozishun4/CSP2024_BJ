#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
				int k=n/7;
				for(int i=1;i<=k;i++){
						cout<<8;
				}
				cout<<endl;
		}
		if(n%7==1){
			int k=n/7;
			k--;
			cout<<10;
			for(int i=1;i<=k;i++){
					cout<<8;
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
