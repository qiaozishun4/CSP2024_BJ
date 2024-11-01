#include <iostream>
using namespace std;
const int N=100002;
int d[N],v[N],a[N],p[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		int n,m,l,V,flag=1,f2=1;
		cin>>n>>m>>l>>V;
//		cout<<n<<' '<<m<<' '<<l<<' '<<V<<endl;
		for (int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
//			cout<<d[i]<<' '<<v[i]<<' '<<a[i]<<endl;
			if (a[i]!=0) flag=0;
			if (a[i]<=0) f2=0;
		}
		for (int i=1;i<=m;i++)
		{
			cin>>p[i];
//			cout<<p[i]<<' ';
//			h[p[i]]++;
		}/*
		for (int i=1;i<=L;i++)
		{
			h[i]=h[i-1]+h[i];
		}*/
		if (flag)
		{
			int ans=0;
			for (int i=1;i<=n;i++)
			{
				if (v[i]>V && d[i]<=p[m]) ans++;
			}
			cout<<ans<<' ';
			if (ans!=0)
			{
				cout<<m-1<<endl;
			}
			else cout<<m<<endl;/*
			break;*/
			continue;
		}
		if (f2)
		{
			
			int ans=0;
			for (int i=1;i<=n;i++)
			{
				if (double(V*V-v[i]*v[i])/(2*a[i])+d[i]<double(p[m]))
					ans=ans+1;
			}
			cout<<ans<<' ';
			if (ans!=0)
			{
				cout<<m-1<<endl;
			}
			else cout<<m<<endl;/*
			break;*/
			continue;
		}
		int flb=0,fls=0,fle=0,ans=0;
		for (int i=1;i<=n;i++)
		{
			if (a==0)
			{
				if (v[i]>V && d[i]<p[m]) fle=1,ans=ans+1;
			}
			else if (a>0)
			{
				if (double(V*V-v[i]*v[i])/(2*a[i])+d[i]<p[m])
					flb=1,ans=ans+1;
			}
			else if (a<0)
			{
				if (double(V*V-v[i]*v[i])/(2*a[i])>p[1])
				{
					fls=1,ans=ans+1;
				}
			}
//			cout<<ans<<' ';
		}
		cout<<ans<<' ';
		if (flb==0 && fls==0)
		{
			cout<<m-fle<<endl;
		}
		else
		{
			cout<<m-flb-fls<<endl;
		}
	}
	return 0;
}