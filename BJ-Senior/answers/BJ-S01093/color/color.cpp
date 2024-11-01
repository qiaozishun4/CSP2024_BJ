#include<bits/stdc++.h>
using namespace std;
 int n,a[201000],c[200100],m,cnt=0;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
   
    cin>>m;
    while(m--)
    {
		cin>>n;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			c[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]==a[j])
				{
					c[j]=a[i];
				}
			}
		}
		for(int i=2;i<=n;i++)
		{
			cnt+=c[i];
		}
		cout<<cnt<<endl;
	}	
    
    return 0;
}
