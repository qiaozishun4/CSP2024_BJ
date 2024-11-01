#include <bits/stdc++.h>
#define int long long
#define maxn 100010
using namespace std;
// cd ytr2010/duel
//g++ A.cpp -std=c++14 -o A
struct node
{
	int r,num=0;
}a[maxn];

bool cmp(node a,node b){return a.r<b.r;}

int n,cnt=0;
int down[maxn];
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		if(down[x]>0) a[down[x]].num++;
		else
		{
			cnt++,down[x]=cnt;
			a[down[x]].num=1;
			a[down[x]].r=x;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int op=0;
	for(int i=1;i<=cnt;i++)
	{
		op=(op-a[i].num);
		if(op<0) op=0;
		op+=a[i].num;
	}
	cout<<op;
	return 0;
}
