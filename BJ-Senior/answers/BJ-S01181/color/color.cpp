#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
using namespace std;
#define cin fin
#define cout fout
long long dp[1000005],delta,mx;
ofstream cout("color.out");
ifstream cin("color.in");
long long n,a[200005];
long long update(int i,int j,long long k)
{
	long long val=(j==-1)?0:dp[j];
	if(dp[i]<val+k)	dp[i]=val+k;
	return dp[i];
}
void mian()
{
	cin>>n;
	memset(dp,0xc0,sizeof dp);
	for(int i=1;i<=n;i++)	cin>>a[i];
	mx=delta=0;
	dp[0]=0;
//	for(int i=0;i<=13;i++)	cout<<i<<"\t\n"[i==13];
	for(int i=1;i<=n;i++)
	{
		long long mark=0;
		if(a[i]==a[i-1])	delta+=a[i],mark=a[i];
		else				mx=max(mx,update(a[i-1],a[i],a[i]));
		mx=max(mx,update(a[i-1],-1,mx-mark));
//		for(int i=0;i<=13;i++)	cout<<max(dp[i]+delta,-1ll)<<","<<from[i]<<"\t\n"[i==13];
	}
	cout<<mx+delta<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)	mian();
}
