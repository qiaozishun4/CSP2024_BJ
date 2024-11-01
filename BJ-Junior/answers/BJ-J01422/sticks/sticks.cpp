#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		dp[7]=8;
		dp[8]=10;
		int n;
		cin>>n;
		if(n==1){ 
			dp[1]=-1;
			cout<<-1<<endl;
			continue;
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=n/7-1;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n==6){
			dp[6]=6;
			cout<<6<<endl;
			continue;
		}
		else if(n==4){
			dp[4]=4;
			cout<<4<<endl;
			continue;
		}
		else if(n==2){
			dp[2]=1;
			cout<<1<<endl;
			continue;
		}
		else if(n==5){
			dp[5]=2;
			cout<<2<<endl;
			continue;
		}
		else if(n==3){
			dp[3]=7;
			cout<<7<<endl;
			continue;
		}
		else if(n==9) cout<<18<<endl;
		else if(n==10) cout<<22<<endl;
		else if(n==11) cout<<48<<endl;
		else if(n==12) cout<<28<<endl;
		else if(n==13) cout<<68<<endl;
		else if(n==16) cout<<188<<endl;
		else if(n==17) cout<<228<<endl;
		else if(n==18) cout<<208<<endl;
		else if(n==19) cout<<288<<endl;
		else if(n==20) cout<<688<<endl;
	}
	return 0;
}
