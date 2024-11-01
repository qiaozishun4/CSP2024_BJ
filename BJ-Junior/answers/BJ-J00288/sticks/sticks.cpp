#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string dp[N],now[7];
inline string minim(string a,string b)
{
	int lena=a.size(),lenb=b.size();
	if (lena!=lenb) return (lena<lenb?a:b);
	for (int i=0;i<lena;i++)
		if (a[i]!=b[i]) return (a[i]<b[i]?a:b);
	return a;
}
inline string work(int cnt)
{
	string res=now[cnt];
	for (register int i(1);i<cnt;i++) res=minim(res,now[i]);
	return res;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for (register int i(1);i<N;i++) dp[i]="-1";
	int cnt=0;
	dp[2]="1",dp[3]="7",dp[4]="4",dp[5]="2",dp[6]="6",dp[7]="8";
	string a,b,c,d,e,f;
	for (register int i=8;i<=100;i++)
	{
		cnt=0;
		if (dp[i-2]!="-1") now[++cnt]=dp[i-2]+'1';
		if (dp[i-3]!="-1") now[++cnt]=dp[i-3]+'7';
		if (dp[i-4]!="-1") now[++cnt]=dp[i-4]+'4';
		if (dp[i-5]!="-1") now[++cnt]=dp[i-5]+'2';
		if (dp[i-6]!="-1") now[++cnt]=dp[i-6]+'0';
		if (dp[i-7]!="-1") now[++cnt]=dp[i-7]+'8';
		dp[i]=work(cnt);
	}
	for (int i=101;i<N;i++) dp[i]=dp[i-7]+'8';
	int T,n;
	cin>>T;
	while (T--)
	{
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	return 0;
}