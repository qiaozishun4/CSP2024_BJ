#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=100010,MAXM=100010;
int n,m;
int c[MAXM];
int a0[MAXN],a[MAXN];
bool d[30][MAXN];
int k;
int X[5];

void getk()
{
	k=0;
	int x=1;
	while(x<n)
	{
		k++;
		x+=x;
	}
}

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a0[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	getk();
	for(int i=1;i<=k;i++)
		for(int j=1;j<=pow(2,k-i);j++)
			cin>>d[i][j];
	int T;
	cin>>T;
	while(T--)
	{
		for(int i=0;i<5;i++) cin>>X[i];
		for(int i=1;i<=n;i++) a[i]=a0[i] xor X[i%4];
		
	}
}
/*
 * ok it's 18.25 now. I don't want to work on this problem now.
 * many things happened to me since this summer.
 * I did great in some mo exams back then due to luck, so OI is so far away from me since then.
 * I feel estranged and sad for leaving this vigourous work.
 * but after all, there are so many precious memories to cherish. * 
 * so, thank you.
 * and everyone.
 * wish everybody good luck.
*/