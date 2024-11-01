#include <bits/stdc++.h>
using namespace std;
struct Car 
{
	int d,v,a,db;
	double l,r;
	//d入口，v初速度，a加速度，db(detected by)被哪个超速仪所检测到,l、r超速区间
}car[100010];
struct Detect 
{
	int l,r,x;
	bool flag;
}p[100010];
int n,m;
bool cmp(Car x,Car y)
{
	return x.l<y.l;
}
bool comp(Detect x,Detect y)
{
	if(x.l==y.l) return x.r>y.r;
	return x.l<y.l;
}
const int inf=1e9+7;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i,j,k,T;
	cin>>T;
	while(T--)
	{
		memset(car,0,sizeof(car));
		memset(p,0,sizeof(p));
		int L,V;
		cin>>n>>m>>L>>V;
		for(i=1;i<=n;i++) cin>>car[i].d>>car[i].v>>car[i].a;
		for(i=1;i<=m;i++) cin>>p[i].x;
		for(i=1;i<=n;i++)
		{
			if(car[i].a==0&&car[i].v>V)
			{
				car[i].l=car[i].d;
				car[i].r=inf;
			}
			else if(car[i].a!=0)
			{
				if(car[i].a<0&&car[i].v>V)
				{
					car[i].r=car[i].d+(V*V*1.00-car[i].v*car[i].v*1.00)/(2.00*car[i].a);
					car[i].l=car[i].d;
				}
				else if(car[i].a>0)
				{
					car[i].l=car[i].d+(V*V*1.00-car[i].v*car[i].v*1.00)/(2.00*car[i].a);
					car[i].r=inf;
				}
				else car[i].r=-1,car[i].l=inf;
			}
			else car[i].r=-1,car[i].l=inf;
		}
		sort(car+1,car+n+1,cmp);
		int j=1,sum=0,ans=0;
		for(i=1;i<=m;i++)
		{
			while(p[i].x>car[j].l&&j<=n)
			{
				if(p[i].x>=car[j].r)
				{
					j++;
					continue;
				}
				if(!p[i].flag)
				{
					p[i].flag=true;
					p[i].r=p[i].l=j;
				}
				else p[i].r++;
				car[j].db=1;
				sum++;
				j++;
			}
		}
		j=1;
		sort(p+1,p+n+1,comp);
		for(i=1;i<=n;i++)
		{
			if(!car[i].db) continue;
			if(p[j].r<=i)
			{
				while(p[j].r<=i&&j<=m) j++;
				ans++;
			}
		}
		cout<<sum<<" "<<m-ans<<endl;
	}
}
//清空数组
