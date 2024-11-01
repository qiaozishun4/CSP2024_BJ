#include <bits/stdc++.h>
#define MAXN 100009
using namespace std;

int T;
int n,m,L,V;
int d[MAXN],v[MAXN],a[MAXN],p[MAXN];
int mc;

/*
 * d[i] : The distance between car and Start
 * v[i] : The speed
 * a[i] : The addspeed
 * p[i] : The distance between e-eye and Start
 * l[i] : The lastest e-eye can catch it
 */


//14:45| 太好了是运动学公式，我们没救了
//15:07| 这数据...默认摄像头距离递增？坑啊
//15:38| 测才发现0<p1<p2..pn 已经给了
//15:53| 喵的想不出来第二个，开骗！(局部性质好东西啊)

bool Check(int CNum,int Enum)
{
	int dis = p[Enum] - d[CNum];
	//cout<<"Debug:"<<CNum<<"="<<sqrt(pow(v[CNum],2)+2*a[CNum]*dis)<<endl;
	if(v[CNum]*v[CNum] + 2*a[CNum]*dis > V*V)
	{
		return 1;
	}
	return 0;
}

struct Line
{
	int l,r;
}D[MAXN];
int D_top = 0;;

bool cmp(Line a,Line b)
{
	if(a.r == b.r)
		return a.l < b.l;
	return a.r < b.r;
}

void DebugD()
{
	for(int i=0;i<D_top;i++)
	{
		cout<<"("<<D[i].l<<","<<D[i].r<<") ";
	}
}

int GetMC()
{
	if(D_top == 0)
		return 0;
	sort(D,D+D_top,cmp);
	int now = 0,re = 0;
	while(now < D_top)
	{
		re++;
		int RR = D[now].r;

		while(D[now].l <= RR&&now < D_top)
		{
			now++;
		}
	}
	return re;
}

bool A,B,C;

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int Turns = 1;Turns <= T;Turns++)
	{
		D_top = 0;
		bool up = 0;
		cin>>n>>m>>L>>V;
		mc = 0;
		A = 1;
		B = 1;
		C = 1;
		int ans = 0;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			if(a[i] != 0)
				A = 0;
			if(a[i] <= 0)
			{
				B = 0;
				up = 1;
			}
			if(a[i] >= 0)
			{
				C = 0;
				up = 1;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		for(int i=1;i<=n;i++)
		{
			int add;
			if(d[i] > p[m])
			       continue;	
			if(a[i] >= 0)
			{
				add = Check(i,m);
				ans += add;
			}
			else
			{
				int j=lower_bound(p+1,p+m+1,d[i])-p;
				add = Check(i,j);
				ans += add;
				if(add && !(Check(i,n)))
				{
					double X = (double(V) * double(V) - double(v[i]) * double(v[i])) /(2.0*double(a[i]));
					int nest = lower_bound(p+1,p+m+1,X+d[i])-p - 1;
					D[D_top].l = j;
					D[D_top].r = nest;
					D_top++;
				}
			}
		}
		mc = m - GetMC();
		if(up)
		{
			mc--;
		}
		if(A||B)
		{
			mc = m-1;
		}

		if(ans == 0)
		{
			mc = m;
		}
		cout<<ans<<" "<<mc<<endl;
	}

	return 0;
}