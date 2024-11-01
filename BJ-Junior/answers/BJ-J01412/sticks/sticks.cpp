#include<bits/stdc++.h>
using namespace std;
int n,t,ans;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		if(n<2||n==4){
			ans=-1;
		}else if(n==2){
			ans=1;
		}else if(n==3){
			ans=7;
		}else if(n==5){
			ans=2;
		}else if(n==6){
			ans=6;
		}else if(n%7==0){
			for(int i=0;i<n/7;i++){
				ans+=pow(10,i)*8;
			}
		}else if(n%7==1){
			int i;
			for(i=0;i<n/7-1;i++){
				ans+=pow(10,i)*8;
			}
			ans+=pow(10,i)*16;
		}else if(n%7==2){
			int i;
			for(i=0;i<n/7;i++){
				ans+=pow(10,i)*8;
			}
			ans+=pow(10,i);
		}else if(n%7==3){
			int i;
			for(i=0;i<n/7-1;i++){
				ans+=pow(10,i)*8;
			}
			ans+=pow(10,i)*22;
		}else if(n%7==4){
			int i;
			for(i=0;i<n/7-1;i++){
				ans+=pow(10,i)*8;
			}
			ans+=pow(10,i)*20;
		}else if(n%7==5){
			int i;
			for(i=0;i<n/7;i++){
				ans+=pow(10,i)*8;
			}
			ans+=pow(10,i)*2;
		}else if(n%7==6){
			int i;
			for(i=0;i<n/7;i++){
				ans+=pow(10,i)*8;
			}
			ans+=pow(10,i)*6;
		}
		cout<<ans<<endl;
	}
	return 0;
}
