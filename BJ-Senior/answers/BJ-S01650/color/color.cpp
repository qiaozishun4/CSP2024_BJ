#include<iostream>
using namespace std;
int a[105],b[105];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,bas;
		cin>>n;
		bas=1<<n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n>20) cout<<"0\n";
		else
		{
			int maxn=0,cnt,l[2],k;
			for(int i=0;i<bas;i++)
			{
				k=i;
				for(int j=1;j<=n;j++)
				{
					b[j]=k&1;
					k=k>>1;
				}
				cnt=0;
				l[0]=0;
				l[1]=0;
				for(int j=1;j<=n;j++)
				{
					if(a[j]==l[b[j]]) cnt+=a[j];
					l[b[j]]=a[j];
				}
				maxn=max(maxn,cnt);
			}
			cout<<maxn<<endl;
		}
	}
	return 0;
}