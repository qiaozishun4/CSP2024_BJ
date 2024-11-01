#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,a[N],maxx;
string dp[N];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> a[i];
		maxx=max(a[i],maxx);
	}
	dp[1]="-1";
	dp[2]="1";
	dp[3]="7";
	dp[4]="4";
	dp[5]="2";
	dp[6]="0";
	dp[7]="8";
	for(int i=8;i<=maxx;i++){
		string ans="";
		int cc=i/7;
		if(i%7!=0) cc++;
		for(int j=1;j<=cc;j++) ans+="9";
		for(int j=2;j<=7;j++){
			if(dp[i-j]!="-1"){
				string tp=dp[i-j];
				if(i-j==6) tp="6";
				bool flag=false;
				string res="";
				for(int k=0;k<int(tp.length());k++){
					if(!flag && k>0 && dp[j][0]<tp[k]) res+=dp[j],flag=true;
					res+=tp[k];
				}
				if(!flag) res+=dp[j][0];
				if(res.length()<ans.length()) ans=res;
				if(res<ans) ans=res;
			}
		}
		dp[i]=ans;
	}
	for(int i=1;i<=t;i++){
		if(a[i]==6) cout << 6 << endl;
		else cout << dp[a[i]] << endl;
	}
	return 0;
}