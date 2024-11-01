#include <bits/stdc++.h>
using namespace std;

long long box[100005];
long long r[100005];
struct node
{
	long long d,x,isuse;
};
bool operator<(const node &x,const node &y)
{
	return x.d<y.d;
}
bool operator>(const node &x,const node &y)
{
	return x.d>y.d;
}
priority_queue<node,vector<node>,greater<node>>q;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n;
	cin>>n;
	long long maxn=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>r[i];
		maxn=max(maxn,r[i]);
		box[r[i]]++;

	}
	if(maxn==2)
	{
		if(box[1]<box[2])
		{
			cout<<box[2]<<endl;
		}
		else
		{
			cout<<box[1]-box[2]+box[2]<<endl;
		}
		return 0;
	}
	for(long long i=1;i<=100000;i++)
	{
		if(box[i])
		{
			q.push((node){i,box[i],0});
		}
	}
	long long ans=0;
	while(q.size()>1)
	{
		ans++;
		// cout<<ans<<endl;
		node x=q.top();
		q.pop();
		//找到最近的有攻击力的
		vector<node>rp;
		node y;
		while(!q.empty())
		{
			y=q.top();
			q.pop();
			if(y.x==y.isuse)
			{
				rp.push_back(y);
				if(q.empty())
				{
					cout<<n-ans+1<<endl;
					return 0;
				}
			}
			else break;
		}
		y.isuse++;
		x.x--;
		if(x.isuse)x.isuse--;
		if(x.x)q.push(x);
		q.push(y);
		for(long long j=0;j<rp.size();j++)
		{
			q.push(rp[j]);
		}
		// cout<<x.d<<" "<<y.d<<endl;
	}
	cout<<n-ans<<endl;
	return 0;
}