#include<bits/stdc++.h>
using namespace std;
namespace solve
{
	constexpr int N=100000+5;
	int n,m,L,V;
	struct pd
	{
		pd()
		{
			l=0;r=0;
		}
		pd(int pl,int pr)
		{
			l=pl;
			r=pr;
		}
		int l,r;
	};
	pd pds[N];
	int pos[N];
	vector<pd> upd;
	bool cmp(pd a,pd b)
	{
		if(a.r==b.r) return a.l<b.l;
		return a.r<b.r;
	}
	void sol()
	{
		upd.clear();
		 cin>>n>>m>>L>>V;
		 for(int i=1;i<=n;++i)
		 {
			 int d,v,a;
			 cin>>d>>v>>a;
			 if(a<0)
			 {
				 if(v<=V)
				 {
					 pds[i].l=L+1;
					 pds[i].r=L+1;
				 }
				 else
				 {
					 pds[i].l=d;
					 pds[i].r=(V*V-v*v)/a/2+d;
					 if((V*V-v*v)%(a*2)==0)
					 {
						 pds[i].r--;
					 }
				 }
			 }
			 else if(a>0)
			 {
				 if(v<=V)
				 {
					 pds[i].l=(V*V-v*v)/a/2+d+1;
					 pds[i].r=L+1;
				 }
				 else
				 {
					 pds[i].l=d;
					 pds[i].r=L;
				 }
			 }
			 else
			 {
				 if(v<=V)
				 {
					 pds[i].l=L+1;
					 pds[i].r=L+1;
				 }
				 else
				 {
					 pds[i].l=d;
					 pds[i].r=L;
				 }
			 }
		 }
		 for(int i=1;i<=m;++i)
		 {
			 cin>>pos[i];
		 }
		 for(int i=1;i<=n;++i)
		 {
			 //cout<<pds[i].l<<" "<<pds[i].r<<endl;
			 int pl=lower_bound(pos+1,pos+m+1,pds[i].l)-pos;
			 int pr=upper_bound(pos+1,pos+m+1,pds[i].r)-pos-1;
			 if(pl<=pr)
			 {
				 upd.push_back(pd(pl,pr));
			 }
		 }
		 cout<<upd.size()<<" ";
		 sort(upd.begin(),upd.end(),cmp);
		 int r=-1,cnt=0;
		 for(int i=0;i<upd.size();++i)
		 {
			 //cout<<upd[i].l<<" "<<upd[i].r<<endl;
			 if(r<upd[i].l)
			 {
				 r=upd[i].r;
				 cnt++;
			 }
		 }
		 cout<<m-cnt<<endl;
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve::sol();
	}
	return 0;
}
