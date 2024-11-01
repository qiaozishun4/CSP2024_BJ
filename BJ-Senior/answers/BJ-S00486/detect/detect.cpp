#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1e5+10;
ld v[N],d[N],p[N],a[N],L,V,oo=1e9;
priority_queue<int,vector<int>,greater<int> > q;
int n,m,ans1,ans2,cov[N],ton[N],pl[N],flag,maxn;
struct nod{int d,v,a;}ls[N];
bool cmp(nod x,nod y){return x.d<y.d;}
ld cal_vt(ld v0,ld a,ld x)
{
	if(2*a*x+v0*v0<=0)  return 0;
	else  return sqrt(2*a*x+v0*v0);
}
int Bin1(ld k)
{
	int l=1,r=m+1,pos=oo;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(k<=p[mid])  r=mid,pos=min(pos,mid);
		else  l=mid+1;
	}
	if(pos!=oo)  return pos;
	else  return 0;
}
void Bin2(int i)
{
	int l=1,r=m,pos=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		//cout<<" i "<<i<<" mid "<<mid<<endl;
		if(p[mid]<ls[i].d)  l=mid+1;
		else if(p[mid]>=ls[i].d&&cal_vt(ls[i].v,ls[i].a,p[mid]-ls[i].d)>V)  
		{
		    l=mid+1,pos=max(pos,mid);
		}
		else  r=mid-1;
		pl[i]=pos;
	}
}
int Calc1()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0)
		{
			if(p[m]>=d[i]&&cal_vt(v[i],a[i],p[m]-d[i])>V)  ans1++,ton[i]=1;
		}
		else if(a[i]<0)
		{
			if(p[m]>=d[i]&&cal_vt(v[i],a[i],p[Bin1(d[i])]-d[i])>V)  ans1++;
		}
		else if(a[i]==0)
		{
			if(p[m]>=d[i]&&v[i]>V)  ans1++,ton[i]=1;
		}
	}
	return ans1;
}
int Calc2()
{
	for(int i=1;i<=n;i++)  ls[i].d=d[i],ls[i].a=a[i],ls[i].v=v[i];
	sort(ls+1,ls+n+1,cmp);
	for(int i=1;i<=n;i++)  if(ls[i].a<0)  Bin2(i);
	//for(int i=1;i<=n;i++)  cout<<ls[i].d<<" "<<pl[i]<<endl;
	//cout<<endl;
	for(int i=1;i<=n;i++)
	{
		if(ls[i].a>=0)  continue; 	
		
		//cout<<i<<" "<<" d ql "<<ls[i].d<<" "<<pl[i]<<endl;
		if(!q.empty()&&p[q.top()]<ls[i].d)
		{
			cov[q.top()]=1;//cout<<"pop "<<i<<" "<<q.top()<<endl;
			maxn=max(maxn,q.top());q.pop();
			while(!q.empty())  q.pop();
		}
		if(pl[i]!=-1)  q.push(pl[i]);
	}
	if(!q.empty())
	{
		//cout<<" af "<<q.top()<<endl;
		cov[q.top()]=1;
		maxn=max(maxn,q.top());q.pop();
		while(!q.empty())  q.pop();
	}
	//cout<<" maxn "<<maxn<<endl;
	for(int i=1;i<=n;i++)
	{
		if(ton[i]&&!(p[maxn]>=d[i]&&cal_vt(v[i],a[i],p[maxn]-d[i])>V))  cov[m]=1;
	}
	for(int i=1;i<=m;i++)  if(cov[i])  ans2++;
	return m-ans2;
}
void Init()
{
	maxn=ans1=ans2=flag=0;
	memset(cov,0,sizeof(cov));
	memset(pl,0,sizeof(pl));
	memset(ton,0,sizeof(ton));
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		Init();
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)  cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)  cin>>p[i];
		cout<<Calc1()<<' '<<Calc2()<<'\n';
	}
	return 0;
}