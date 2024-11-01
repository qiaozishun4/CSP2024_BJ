#include<bits/stdc++.h>
using namespace std;
 int n,a[101000],cnt=0;
 bool o[100100];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
   
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
    {
		for(int j=i;j<=n;j++)
		{
			if(a[j]>a[i]&&a[i]!=-1&&a[j]!=-1&&o[j]!=1)
			{
				a[i]=-1;
				o[j]=1;
				break;
			}
		}
	}
	 for(int i=1;i<=n;i++)
    {
		if(a[i]!=-1)
		{
			cnt++;
		}
		
	}
	cout<<cnt;
    return 0;
}
