#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
		cin>>n;
		if(n<2){
			cout<<-1;
		}
		int num=n/2;
		if(num%2==0){
			for(int i=1;i<=num;i++){
				cout<<1;
			}
		}else{
			num=n/2-4;
			for(int i=1;i<=num;i++){
				cout<<1;
			}
			cout<<2;
		}
		cout<<endl;
	}
    return 0;
}
