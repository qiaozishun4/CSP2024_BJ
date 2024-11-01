#include <iostream>
using namespace std;
int a[200003];
long long mx;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
	mx=0;
		int n;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int sum=(1<<n);
		for (int i=0;i<sum;i++)
		{
			long long ans; ans=0;
			int l0=-1,l1=-1;
			for (int j=0;j<n;j++)
			{
				int x=(1<<j)&i;
				if (x==0)
				{
					if (a[j+1]==l0) ans+=l0;
					l0=a[j+1];
				}
				else {
					if (a[j+1]==l1) ans+=l1;
					l1=a[j+1];
				}
			}
			mx=max(mx,ans);
		}
		cout<<mx<<endl;
	}
	return 0;
}