#include<bits/stdc++.h>
using namespace std;
constexpr int N=100000+5;
typedef long long ll;
int n,m;
struct quer
{
	int id,c;
	ll ans;
};
int aslash[N],a[N],ori[N],ida[N];
quer q[N];
bool d[20][N];
int X[5];
int K;
bool cmp1(quer a,quer b)
{
	return a.c<b.c;
}
bool cmp2(quer a,quer b)
{
	return a.id<b.id;
}
namespace solve
{
	void sol()
	{
		cin>>X[0]>>X[1]>>X[2]>>X[3];
		for(int i=1;i<=n;++i)
		{
			a[i]=aslash[i]^X[i%4];
			ida[i]=i;
			ori[i]=a[i];
			//cout<<a[i]<<" ";
		}
		//cout<<endl;
		sort(q+1,q+m+1,cmp1);
		int p=1;
		int bgK=1;
		int flr=0;
		for(int i=1;i<=n;++i)
		{
			int cur=i;
			int mul=1;
			int ly=1;
			while(cur%2==0)
			{
				if(!d[ly][cur/2])
				{
					if(a[i-mul]>=ly)
					{
						a[i]=a[i-mul];
						ida[i]=ida[i-mul];
					}
				}
				else
				{
					if(a[i]<ly)
					{
						a[i]=a[i-mul];
						ida[i]=ida[i-mul];
					}
				}
				cur/=2;
				mul*=2;
				ly+=1;
			}
			if(i>bgK)
			{
				bgK*=2;
				flr++;
			}
			//cerr<<q[p].c<<" "<<i<<" "<<p<<endl;
			if(i==q[p].c)
			{
				if(i==bgK)
				{
					q[p].ans=ida[i];
				}
				else
				{
					set<int> possr;
					ll possl=i;
					int curr=i;
					int mull=1;
					int minster=i+1;
					//cout<<"FLR"<<flr<<endl;
					for(int j=1;j<=flr;++j)
					{
						//cout<<"? "<<curr<<" "<<mull<<" "<<possl<<" "<<minster<<endl;
						if(curr%2==0)
						{
							if(d[j][(curr)/2]==0)
							{
								if(a[(curr-1)*mull]>=j)
								{
									possr.clear();
									possl=ida[(curr-1)*mull];
									minster=max(minster,curr*mull+1);
								}
							}
							else
							{
									//printf("jh=%d\n",j);
								if(possl==0)
								{
									//printf("j=%d\n",j);
									vector<set<int>::iterator> del;
									for(auto fff=possr.begin();fff!=possr.end();fff++)
									{
										if(ori[*fff]<j) del.emplace_back(fff);
									}
									for(auto ppp:del)
									{
										//cerr<<"p"<<endl;
										possr.erase(ppp);
									}
									//cerr<<"??? "<<ida[(curr-1)*mull]<<endl;
									possr.insert(ida[(curr-1)*mull]);
								}
								else
								{
									if(ori[possl]<j)
									{
										possl=ida[(curr-1)*mull];
									}
								}
							}
						}
						else
						{
							if(d[j][(curr+1)/2]==0)
							{
								if(possl==0)
								{
									vector<set<int>::iterator> del;
									for(auto fff=possr.begin();fff!=possr.end();fff++)
									{
										if(ori[*fff]<j) del.emplace_back(fff);
									}
									for(auto ppp:del)
									{
										//cerr<<"p"<<endl;
										possr.erase(ppp);
									}
								}
								else
								{
									if(ori[possl]<j)
									{
										possl=0;
									}
									else
									{
										minster=max(minster,(curr*mull+mull)+1);
									}
								}
							}
							else
							{
								if(possl!=0)
								{
									possr.insert(possl);
									possl=0;
								}
							}
						}
						mull*=2;
						if(curr%2==1) curr++;
						curr/=2;
					}
					for(auto op=possr.begin();op!=possr.end();op++)
					{
						possl+=*op;
					}
					if(minster<=bgK) possl+=((ll)(minster+bgK))*((ll)bgK-minster+1)/2;
					q[p].ans=possl;
				}
				while(q[p+1].c==q[p].c)
				{
					q[p+1].ans=q[p].ans;
					p++;
				}
				p++;
			}
		}
		//sort(q+1,q+m+1,cmp2);
		ll ress=0;
		for(int i=1;i<=m;++i)
		{
			//cerr<<q[i].ans<<" ";
			ress^=(q[i].id*q[i].ans);
		}
		//cerr<<endl;
		cout<<ress<<endl;
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>aslash[i];
	}
	int mul=1;
	for(int i=1;i<=m;++i)
	{
		cin>>q[i].c;
		q[i].id=i;
	}
	while(mul<n)
	{
		K++;
		mul*=2;
	}
	for(int i=1;i<=K;++i)
	{
		string s;
		cin>>s;
		for(int j=0;j<s.length();++j)
		{
			d[i][j+1]=s[j]-'0';
		}
	}
	int T;
	cin>>T;
	while(T--)
	{
		solve::sol();
	}
	return 0;
}

