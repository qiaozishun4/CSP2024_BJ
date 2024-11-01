#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;

#define MAX 100010
#define MAXL 1000010
#define ROOT 1
int t,n,m,l,v,d,v0,a,cnt,cntexc,tot=-1;
double tmp;
int diff[MAXL],final[MAXL],detect[MAX];
bitset<MAXL>pd;
struct segment
{
	int l,r;
}data[MAX];

struct node
{
	int l,r;
	bool det;
}segtree[MAXL*4];

void build(int l,int r,int p=ROOT)
{
	segtree[p].l=l;
	segtree[p].r=r;
	if(l==r)
	{
		segtree[p].det=pd[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	segtree[p].det=segtree[p*2].det||segtree[p*2+1].det;
}
void trim(int p=ROOT)
{
	segtree[p].det=false;
	if(segtree[p].l==segtree[p].r)
	{
		segtree[p].l=segtree[p].r=0;
		return;
	}
	segtree[p].l=segtree[p].r=0;
	trim(p*2);
	trim(p*2+1);
}
bool query(int l,int r,int p=ROOT)
{
	if(l<=segtree[p].l&&r>=segtree[p].r)
		return segtree[p].det;

	int mid=(segtree[p].l+segtree[p].r)/2;
	if(r<=mid)
		return query(l,r,p*2);

	else if(l>mid)
		return query(l,r,p*2+1);

	return query(l,r,p*2)||query(l,r,p*2+1);
}

inline double square(double x)
{
	return x*x;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> l >> v;
		for(int i = 0;i<n;i++)
		{
			cin >> d >> v0 >> a;
			if(v0>v)
			{
				data[++tot].l=d;
				if(a>=0)
					data[tot].r=l;
				else
				{
					data[tot].r=ceil((square(v)-square(v0))/(2*a))-1+d;
					data[tot].r=min(data[tot].r,l);
				}
			}
			else
			{
				if(a<=0)
					continue;

				tmp=(square(v)-square(v0))/(2*a);
				if(tmp>=l)
					continue;

				data[++tot].l=floor(tmp)+1+d;
				data[tot].r=l;
			}
/*			if(tot>-1)
				cout << i << ':' << data[tot].l << ',' << data[tot].r << endl;*/
		}
		for(int i = 0;i<=tot;i++)
		{
			diff[data[i].l]++;
			diff[data[i].r+1]--;
		}
		for(int i = 0;i<m;i++)
		{
			cin >> detect[i];
			pd[detect[i]]=true;
		}
		build(0,l);
		for(int i = 0;i<=tot;i++)
			cntexc+=query(data[i].l,data[i].r);

		final[0]=diff[0];
		for(int i = 1;i<=l;i++)
			final[i]=final[i-1]+diff[i];

		for(int i = 0;i<m;i++)
			cnt+=final[detect[i]]==0;

		cout << cntexc << ' ' << cnt << endl;
		trim();
		for(int i = 0;i<=tot;i++)
			data[i].l=data[i].r=0;
		tot=0;
		for(int i = 0;i<=l;i++)
			final[i]=diff[i]=0;
		for(int i = 0;i<m;i++)
			detect[i]=0;
		pd=0;
		cntexc=0;
		cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
}