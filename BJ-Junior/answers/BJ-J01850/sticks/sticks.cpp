//白哥保佑T3，暴力出奇迹，打表出省一！
#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
/*
//白哥nb，这个记忆化DaFaShi就给你了
const string str[]={"0","1","2","3","4","5","6","7","8","9"};
const int need[]={6,2,5,5,4,5,6,3,7,6};
int n,T;
bool vis[N][2];
string ans,dp[N][2];
void dfs(int x,int d){
	if(x<0)return;
	if(vis[x][d])return;
	vis[x][d]=1;
	int k;
	if(d)k=0;
	else k=1;
	for(int i=k;i<=9;i++){
		dfs(x-need[i],1);
		if(dp[x-need[i]][1]==""&&x-need[i]!=0)continue;//用不了
		string tmp=str[i]+dp[x-need[i]][1];
		if(dp[x][d]==""){
			dp[x][d]=tmp;
			continue;
		}
		if(tmp.size()<dp[x][d].size()){
			dp[x][d]=tmp;
			continue;
		}
		if(dp[x][d].size()==tmp.size()&&tmp<dp[x][d]){
			dp[x][d]=tmp;
			continue;
		}
	}
	return;
}

//白哥啊，让我拿J1吧！！！
dfs(n,0);
if(dp[n][0]=="")cout<<"-1"<<endl;
else cout<<dp[n][0]<<endl;
*/
const string ans[]={
	"Man! What Can I say? Baige NB!",
	"-1",
	"1",
	"7",
	"4",
	"2",
	"6",
	"8",
	"10",
	"18",
	"22",
	"20",
	"28",
	"68",
	"88"
	};
const string pre[]={"","10","1","200","20","2","6"};
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=14){
			cout<<ans[n]<<endl;
			continue;
		}
		int weishu=(n+7)/7;
		int yushu=n%7;
		cout<<pre[yushu];
		weishu-=pre[yushu].size();
		while(weishu--)cout<<"8";
		cout<<endl;
	}
	return 0;
}
