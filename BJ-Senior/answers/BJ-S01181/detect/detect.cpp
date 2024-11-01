#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define cin fin
#define cout fout
#define int long long
struct frac
{
	long long up,down;
	frac():up(0),down(1){}
	frac(long long x):up(x),down(1){}
	frac(long long up,long long down):up(up),down(down){if(down<0)down=-down,up=-up;}
	frac operator + (long long b) const
	{
		return frac(up+b*down,down);
	}
};
frac operator + (long long b,frac a)
{
	return frac(a.up+b*a.down,a.down);
}
int floor(frac x)
{
	return x.up/x.down;
}
int ceil(frac x)
{
	return (x.up+x.down-1)/x.down;
}
ostream& operator << (ostream& out,frac x)
{
	out<<x.up*1.0L/x.down;
	return out;
}
typedef frac ld;
vector<pair<int,pair<int,int>>> ori;
int n,m,len,vmax,detect[2000005];
vector<pair<int,int>> car;
ofstream cout("detect.out");
ifstream cin("detect.in");
//vector<int> ans;
bool cmp(pair<int,int> a,pair<int,int> b){return a.second<b.second;}
void mian(bool debug)
{
	cin>>n>>m>>len>>vmax;
	if(debug)
		cout<<n<<" "<<m<<" "<<len<<" "<<vmax<<endl;
	ori.clear();
	car.clear();
//	ans.clear();
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ori.emplace_back(a,make_pair(b,c));
	}
	for(int i=1;i<=m;i++)	cin>>detect[i];
	sort(detect+1,detect+m+1);
	for(auto tmp:ori)
	{
		int enter=tmp.first;
		int v=tmp.second.first;
		int a=tmp.second.second;
		ld l,r;
		if(a==0)
		{
			if(v>vmax)	l=enter-1,r=len+1;
			else		l=len+1,r=len;
		}
		else if(a>0)
		{
			if(v>vmax)
				l=enter-1,r=len+1;
			else
				l=enter+frac(vmax*vmax-v*v,2*a),r=len+1;
		}
		else if(a<0)
		{
			if(v>vmax)
				l=enter-1,r=enter+frac(vmax*vmax-v*v,2*a);
			else	l=len+1,r=len;
		}
		int x=upper_bound(detect+1,detect+m+1,floor(l))-detect;
		int y=lower_bound(detect+1,detect+m+1,ceil(r))-detect-1;
		if(x>y)
		{
			if(debug && l.up!=(len+1))	cout<<"car "<<enter<<" "<<v<<" "<<a<<"   exceed at ("<<l<<","<<r<<")\n";
			continue;
		}
//		cout<<"can be pictured by camera "<<*x<<"~"<<*y<<endl;
		car.emplace_back(x,y);
	}
	n=car.size();
	sort(car.begin(),car.end(),cmp);
	int sup=-1,cnt=m;
	for(auto tmp:car)
	{
		int l=tmp.first,r=tmp.second;
		if(l<=sup && sup<=r)	continue;
		sup=r;
//		ans.push_back(r);
		cnt--;
	}
//	sort(ans.begin(),ans.end());
//	for(auto a:car)
//	{
//		int x=lower_bound(ans.begin(),ans.end(),a.first)-ans.begin();
//		int y=upper_bound(ans.begin(),ans.end(),a.second)-ans.begin()-1;
//		if(x>y)	exit(1);
//	}
	cout<<n<<" "<<cnt<<"\n";
}
signed main()
{
	int t;
	cin>>t;
	while(t--)	mian(0);
}
