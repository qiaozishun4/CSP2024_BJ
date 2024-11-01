#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
void cha(int s,int w)
{
	int po=1<<w,tt=0;
	while(w--)
	{
		tt++;
		po/=2;
		a[tt]=s/po;
		if(s>=po) s-=po;
	}
}
int c(int n)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--){
			if(a[j]==a[i])
			{
				if(b[j]==b[i]) ans+=b[j];
				break;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T; cin>>T;
	while(T--)
	{
		int ans=0;
		int n; cin>>n;
		for (int i=1;i<=n;i++) cin>>b[i];
		int tm=1<<n;
		for (int i=0;i<tm;i++)
		{
			cha(i,n);
			ans=max(ans,c(n));
		}
		cout<<ans<<endl;
	}
	return 0;
}
