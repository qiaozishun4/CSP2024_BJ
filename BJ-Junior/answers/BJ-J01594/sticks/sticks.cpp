#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n[100];
string dp[100010];//运用i根木棍所拼的最小数
string min_num[10];
ll maxn;
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++)
	cin>>n[i],maxn=max(maxn,n[i]);
	for(ll i=0;i<=maxn;i++)
	dp[i]="inf";
	dp[2]="1";
	dp[3]="7";
	dp[4]="4";
	dp[5]="2";
	dp[6]="6";
	dp[7]="8";
	min_num[2]="1";
	min_num[3]="7";
	min_num[4]="4";
	min_num[5]="2";
	min_num[6]="0";
	min_num[7]="8";
	for(ll i=8;i<=maxn;i++){
		for(ll j=2;j<=7;j++){
			if(dp[i-j]=="inf")continue;
			if(dp[i]=="inf")
			dp[i]=dp[i-j]+min_num[j];
			else{
				string str=dp[i-j]+min_num[j];
				if(str.size()!=dp[i].size()){
					if(str.size()<dp[i].size())
					dp[i]=str;
				}else{
					dp[i]=min(dp[i],str);
				}
			}
		}
	}
	for(ll i=1;i<=t;i++){
		if(dp[n[i]]!="inf")
		cout<<dp[n[i]]<<endl;
		else
		cout<<-1<<endl;
	}
	return 0;
}
