#include <bits/stdc++.h>
#define int long long
#define maxn 100010
using namespace std;

int n,m,l,v;
struct node{
	int st,v,a,ed=0;
}car[maxn];
int p[maxn],ans1=0,ans2=0;
vector<int> e[maxn];
int bag[maxn];
double get_s(int s,int v,int a) {return sqrt(v*v+2*a*s);}
double get_vv(int v,int a) {return (-1*((v*v*1.0)/(a+a))*1.0)*1.0;}

int upp(double x) {int down=x;return (x-down<0.00001?down:x+1);}



int tree[maxn<<2],tag[maxn<<2];

int ls(int x){return x<<1;}
int rs(int x){return x<<1|1;}
void push_up(int x) {tree[x]=tree[ls(x)]+tree[rs(x)];}

void addtag(int p,int pl,int pr,int x)
{
	tag[p]+=x;
	tree[p]+=(pr-pl+1)*x;
}
void pushdown(int p,int pl,int pr)
{
	if(tag[p])
	{
		int mid=(pl+pr)>>1;
		addtag(ls(p),pl,mid,tag[p]);
		addtag(rs(p),mid+1,pr,tag[p]);
		tag[p]=0;
	}
}

void update(int L,int R,int p,int pl,int pr,int k)
{
	if(L<=pl&&pr<=R) 
	{
		addtag(p,pl,pr,k);
		return ;
	}
	pushdown(p,pl,pr);
	int mid=(pl+pr)>>1;
	if(L<=mid) update(L,R,ls(p),pl,mid,k);
	if(R>mid)  update(L,R,rs(p),mid+1,pr,k);
	push_up(p);
}

int query(int L,int R,int p,int pl,int pr)
{
	if(L<=pl&&pr<=R) 
	{
		return tree[p];
	}
	pushdown(p,pl,pr);
	int res=0;
	int mid=(pl+pr)>>1;
	if(L<=mid) res+=query(L,R,ls(p),pl,mid);
	if(R>mid)  res+=query(L,R,rs(p),mid+1,pr);
	return res;
}

int search__(int x)
{
	int l=1,r=m,mid;
	while(l<=r)
	{
		int mid=upp((double)(l+m)/2);
		if(x<p[mid]) r=mid;
		if(x>p[mid]) l=mid;
		if(x==p[mid]) return mid;
		if(l==r) return r;
	}
	return r;
}

void todo()
{
	memset(tree,0,sizeof(tree));
	memset(tag,0,sizeof(tag));
	int flaga=0;
	cin>>n>>m>>l>>v;
	for(int i=1;i<=n;i++)
	{
		int di,vi,ai;
		cin>>di>>vi>>ai;
		car[i].st=di;
		car[i].v=vi;
		car[i].a=ai;
		if(ai>=0) car[i].ed=l;
		else car[i].ed=di+get_vv(vi,ai);
	}
	for(int i=1;i<=m;i++) 
	{
		cin>>p[i];
		bag[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int stp=search__(e[i].st);
		int endp=search__(e[i].get_vv);
		if(p[endp]>e[i].getvv) endp--;

		if(get_s(p[stp],car[j].v,car[j].a)-v>0.00001) 
		{
			ans1++;
			if(query(p[stp],p[endp],1,1,n)==0) ans2++;
			update(p[stp],p[endp],1,1,n,1);
		}
		else if(get_s(p[m],car[j].v,car[j].a)-v>0.00001) 
		{
			ans1++;
			if(query(p[stp],p[endp],1,1,n)==0) ans2++;
			update(p[stp],p[endp],1,1,n,1);
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
	return ;
}
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--) todo();
	return 0;
}