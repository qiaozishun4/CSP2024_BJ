#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],v[N],d[N],last,cnt_car,cnt_other;

int main()
{
  freopen("detect.in","r",stdin);
  freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>last;
		}
		for(int i=1;i<=n;i++)
		{
			long long z=sqrt(v[i]*v[i]+2*a[i]*last);
			if(z>=V&&z-V>2) cnt_car++;
		}
		if(cnt_car!=0) cnt_other=m-1;
		else cnt_other=m;
		cout<<cnt_car<<" "<<cnt_other<<endl;
		cnt_car=cnt_other=0;
	}
	return 0;
}
