#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n,m,l,v;
struct Node
{
	int di,vi,ai;
}c[100005];
int p[100005];
int h[1000005];
bool h0[1000005];
int ans1,ans2;
struct Node2
{
	int li,ri,id;
} qj[100005],qj2[100005];
int cnt;
vector<int> q;
int lenq;
bool cmp2(Node2 x,Node2 y)
{
	return x.li<=y.li;
}
bool check(int maxx)
{
	int k=0;
	int last=1;
	for (int i=1;i<=m;i++)
	{
		while (qj[last].li<=p[i] && last<=cnt)
		{
			q.push_back(qj[last].id);
			last++;
			
			
		}
		bool flag=0;
		
		for (int j=0;j<q.size();j++)
		{
			
			if (qj[q[j]].ri<p[i+1])
			{
				flag=1;
				
				break;
			}
		}
		if (flag)
		{
			k++;
			q.clear();
		}
	}
	return k<=maxx;		
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		
		ans1=ans2=0;
		memset(h0,0,sizeof(h0));
		memset(h,0,sizeof(h));
		cin>>n>>m>>l>>v;
		for (int i=1;i<=n;i++)
		{
			cin>>c[i].di>>c[i].vi>>c[i].ai;
		}
		for (int i=1;i<=m;i++)
		{
			cin>>p[i];
			h0[p[i]]=1;
		}
		p[m+1]=0x3f3f3f3f;
		for (int i=1;i<=l;i++)
		{
			if (h0[i])
			{
				h[i]=h[i-1]+1;
			}
			else
			{
				h[i]=h[i-1];
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (c[i].ai==0)
			{
				if (c[i].vi>v)
				{
					if (c[i].di==0)
					{
						if (h[l]>0)
						{
							ans1++;
						
							qj[++cnt]={c[i].di,l,cnt};
						}
					}
					else
					{
						if (h[l]-h[c[i].di-1]>0)
						{
							ans1++;
						
							qj[++cnt]={c[i].di,l,cnt};
						}
					}
				}
			}
			else if (c[i].ai>0)
			{
				if (c[i].vi>v)
				{
					if (c[i].vi>v)
					{
						if (c[i].di==0)
						{
							if (h[l]>0)
							{
								ans1++;
						
								qj[++cnt]={c[i].di,l,cnt};
							}
						}
						else
						{
							if (h[l]-h[c[i].di-1]>0)
							{
								ans1++;
					
								qj[++cnt]={c[i].di,l,cnt};
							}
						}
					}
				}
				else
				{
					double j=(v*v-c[i].vi*c[i].vi)/(2*c[i].ai);
					if ((int)floor(j)+c[i].di<=l && h[l]-h[(int)floor(j)+c[i].di]>0)
					{
						ans1++;
			
						qj[++cnt]={c[i].di+(int)floor(j)+1,l,cnt};
					}
				}
			}
			else
			{
				
				if (c[i].vi>v)
				{
					double j=(v*v-c[i].vi*c[i].vi)/(2*c[i].ai);
					if (c[i].di>0)
					{
						if ((int)floor(j)+c[i].di>l || h[c[i].di+(int)floor(j)]-h[c[i].di-1]>0)
						{
							ans1++;
							
							qj[++cnt]={c[i].di,c[i].di+(int)ceil(j)-1,cnt};
						}
					}
					else
					{
						if ((int)floor(j)+c[i].di>l || h[c[i].di+(int)floor(j)]-h[c[i].di]>0)
						{
							ans1++;
							
							qj[++cnt]={c[i].di,c[i].di+(int)ceil(j)-1,cnt};
						}
					}
				}
			}
		}

		sort(qj+1,qj+cnt+1,cmp2);
		/*
		cout<<"//////////"<<endl;
		for (int i=1;i<=cnt;i++)
		{
			cout<<qj2[i].li<<" "<<qj2[i].id<<endl;
		}
		cout<<"//////////"<<endl;
		*/
		int l=0,r=m;
		while (l<=r)
		{
			int mid=(l+r)/2;
			
			if (check(mid))
			{
				r=mid-1;
				ans2=mid;
			}
			else
			{
				l=mid+1;
			}
			
		}
		cout<<ans1<<" "<<m-ans2<<endl;
	}
	return 0;
}
