#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int first[2]={0,0};
int second[2]={-1,-1};
int a[N];
int cnt,last=-1e9;

int main()
{
  freopen("duel.in","r",stdin);
  freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool flag=1;
	int z=1;
	while(a[z++]==a[1])
	{
		first[1]=a[1];
		first[0]++;
	}
	while(flag)
	{
		flag=0;
		for(int i=z;i<=n;i++)
		{
			if(a[i]!=last&&(second[0]==-1||a[i]==second[1]))
			{
				if(second[0]==-1) second[0]++;
				second[0]++;
				second[1]=a[i];
				z=i;
				flag=1;
			}
		}
		last=second[1];
		if(second[0]==first[0]&&second[0]!=-1)
		{
			first[0]=second[0];
			second[0]=-1;
			second[1]=-1;
			int zold=z;
			while(a[z++]==a[zold])
			{
				first[0]++;
				first[1]=a[z];
			}
		}
		else if(second[0]<first[0]&&second[0]!=-1)
		{
			second[0]=-1;
			second[1]=-1;
		}
		else if(second[0]!=-1)
		{
			first[0]=second[0];
			first[1]=second[1];
			second[0]=-1;
			second[1]=-1;
		}
	}
	cout<<first[0];
	return 0;
}
