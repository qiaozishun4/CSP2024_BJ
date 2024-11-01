#include<iostream>
#include<cstring>
using namespace std;
int t,n,x,e[55],a[]={6,2,5,5,4,5,6,3,7,6};
string dp[100020],zh[]={"0","1","2","3","3","5","6","7","8","9"};
bool xy(string x,string y){
	if (x.size()==y.size())
		return x<y;
	return x.size()<y.size();
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.ans","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>e[i];
		n=max(n,e[i]);
	}
	if (n>1000){
		if (n%7==0){
			for (int i=1;i<=t;i++){
				for (int j=1;j<=n/7;j++){
					cout<<8;
				}
				cout<<'\n';
			}
			return 0;
		}
		else if (n%7==1){
			for (int i=1;i<=t;i++){
				cout<<10;
				for (int j=1;j<=(n-8)/7;j++)
					cout<<8;
				cout<<'\n';
			}
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
		dp[i]="x";
	dp[2]="1",dp[3]="7",dp[4]="4",dp[5]="2",dp[6]="6",dp[7]="8";
	for (int i=2;i<=n;i++){
		if (dp[i]=="x")
			continue;
		for (int j=0;j<=9;j++){
			if (dp[i+a[j]]=="x"){
				dp[i+a[j]]=dp[i]+(zh[j]);
				continue;
			}
			string x=dp[i]+zh[j];
			if (xy(x,dp[i+a[j]]))
				dp[i+a[j]]=x;
		}
	}
	for (int i=1;i<=t;i++)
		if (dp[e[i]]=="x")
			cout<<-1<<'\n';
		else
			cout<<dp[e[i]]<<'\n';
	return 0;
}
