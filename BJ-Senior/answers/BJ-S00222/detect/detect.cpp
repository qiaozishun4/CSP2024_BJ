#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


const int MAXN=100010,MAXM=100010,MAXL=1000010;
int n,m,L,V;
//respectively: amount of cars; amount of devices; length of the track; speed limit
int d[MAXN],v[MAXN],a[MAXN];
//respectively: distance to the entrance; initial velocity; acceleration
int p[MAXM];
//position of the devices, their distance to the entrance

int c[MAXL];

pair<int,int> t[MAXN];

int makeint_h(int x,int y)
{
//	if(x%y==0) return x/y+1;
//	else return x/y+1;
	return x/y+1;
}

int makeint_l(int x,int y)
{
	if(x%y==0) return x/y;
	else return x/y+1;
}

pair<int,int> cal(int dis,int vel,int acc)
{
	if(acc==0)
	{
		if(vel<=V) return make_pair(0,0);
		else return make_pair(dis,L+1);
	}
	if(acc>0)
	{
		if(vel>V) return make_pair(dis,L+1);
		else
		{
		//	int d0=makeint_h(V*V-vel*vel,acc+acc);
		//	return make_pair(min(L+1,dis+d0),L+1);
			return make_pair(min(L+1,dis+makeint_h(V*V-vel*vel,acc+acc)),L+1);
		}
	}
	if(acc<0)
	{
		if(vel<=V) return make_pair(0,0);
		else
		{
		//	int d0=makeint_l(vel*vel-V*V,-acc-acc);
		//	return make_pair(dis,min(L+1,dis+d0));
			return make_pair(dis,min(L+1,dis+makeint_l(vel*vel-V*V,-acc-acc)));
		}
	}
}

bool cmp(pair<int,int> x,pair<int,int> y)
{
	if(x.second!=y.second) return x.second<y.second;
	else return x.first<y.first;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	//cin>>T;
	//ios::sync_with_stdio(false);
	scanf("%d",&T);
	while(T--)
	{
	//	cin>>n>>m>>L>>V;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
		{
	//		cin>>d[i]>>v[i]>>a[i];
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
	//		t[i]=cal(d[i],v[i],a[i]);
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(p+1,p+m+1);
		int pp=1;
/*		if(p[1]==0)
		{
			pp=2;
			c[0]=1;
		}*/
		for(int i=0;i<=L;i++)
		{
			if(p[pp]==i)
			{
				c[i+1]=c[i]+1;
				pp++;
			}
			else c[i+1]=c[i];
			//how many devices in [0,i)
		}
		int cnt=0;
		pair<int,int> tmp;
		for(int i=1;i<=n;i++)
		{
			tmp=cal(d[i],v[i],a[i]);
			if(c[tmp.second]-c[tmp.first])
			{
				cnt++;
				t[cnt]=tmp;
			}
		}
		
//for the second problem, our strategy is quite direct:
//starting from the left and in turn closing the nearest one to the end till it ends
		sort(t+1,t+cnt+1,cmp);
		int pb=-1,ans=0;;
		for(int i=1;i<=cnt;i++)
		{
			if(pb<t[i].first)
			{
				ans++;
				pb=p[c[t[i].second]];
		//		printf("%d %d %d\n",pb,t[i].second,c[t[i].second]);
			}
		}
		printf("%d %d\n",cnt,m-ans);
	}
	return 0;
}
