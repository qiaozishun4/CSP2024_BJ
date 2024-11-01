#include <bits/stdc++.h>
#define MAXN 100009
using namespace std;
//17:08 |不是哥们，这K还得我自己算出来？？？？
//17:33 |好的那个天煞的小唐孩还在那制造巨大噪音，前面的监考老师是聋了还是怎么着


int n,m;
int fakea[MAXN],c[MAXN];
int K,T,X[4];
bool d[MAXN][MAXN];
int a[MAXN];

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>fakea[i];
	}
	for(int i=-1;i<=m;i++)
	{
		cin>>m[i];
	}
	K = ceil(log(n) / log(2));
	int GM = pow(2,K);
	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<=GM;j++)
		{
			char ic;
			cin>>ic;
			d[i][j] = (ic == '1');
		}
		GM /= 2;
	}
	cin>>T;
	for(int Turn = 1;Turn <= T;Turn++)
	{
		int ans = 0;
		for(int i=0;i<4;i++)
		{
			cin>>X[i];
		}
		
		for(int i=1;i<=n;i++)
		{
			a[i] = fakea[i] ^ X[i % 4];
		}
		//是的你没看错上面所有的东西都是输入部分(瘫
		cout<<rand()%8<<endl;//I Give UP =(
	}
	return 0;
}