#include<bits/stdc++.h>

using namespace std;

int T;
int n,m,len,V;
int d[100005],v[100005],a[100005];
struct node
{
	int l,r;
}b[100005];//i:[b[i].l,b[i].r]中必须有检测器
int p[100005];
int ans1,ans2;

int find1(int x) //在p中第一个大于等于x的数
{
	int l=1,r=m,res=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (p[mid]>=x)
		{
			res=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return res;
}
int find2(double x) //在p中最后一个小于x的数
{
	int l=1,r=m,res=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (p[mid]<x)
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return res;	
}
int find3(double x) //在p中第一个大于x的数
{
	int l=1,r=m,res=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (p[mid]>x)
		{
			res=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return res;
}
bool cmp(node x,node y)
{
	if (x.r!=y.r)
	{
		return x.r<y.r;
	}
	return x.l<y.l;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		ans1=ans2=0;
		scanf("%d%d%d%d",&n,&m,&len,&V);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&p[i]);
		}
		for (int i=1;i<=n;i++)
		{
			b[i].l=1,b[i].r=m;
		}
		for (int i=1;i<=n;i++)
		{
			if (a[i]==0)
			{
				if (v[i]>V) 
				{
					int tmp=find1(d[i]);
					if (tmp)
					{
						ans1++;
						b[i].l=tmp,b[i].r=m;
					}
				}
			}
			else if (a[i]>0)
			{
				if (v[i]>V)
				{
					int tmp=find1(d[i]);
					if (tmp)
					{
						ans1++;
						b[i].l=tmp,b[i].r=m;
					}
				}
				else
				{
					double t=(V-v[i])*1.0/a[i];
					double s=v[i]*t+a[i]*t*t*0.5;
					double d2=d[i]+s;
					int tmp=find3(d2);
					if (tmp)
					{
						ans1++;
						b[i].l=tmp,b[i].r=m;
					}
				}
			}
			else if (a[i]<0)
			{
				if (v[i]>V)
				{
					double t=(V-v[i])*1.0/a[i];
					double s=v[i]*t+a[i]*t*t*0.5;
					double d2=d[i]+s;
					// printf("%d:%f,%f,%f\n",i,t,s,d2);
					int tmp1=find1(d[i]);
					int tmp2=find2(d2);
					if (tmp1<=tmp2)
					{
						ans1++;
						b[i].l=tmp1,b[i].r=tmp2;
					}
				}
			}
			// printf("%d:[%d,%d]\n",i,b[i].l,b[i].r);
		}
		printf("%d ",ans1);
		if (!ans1)
		{
			printf("%d\n",m);
			continue;
		}
		sort(b+1,b+n+1,cmp);
		int last=0;
		for (int i=1;i<=n;i++)
		{
			if (b[i].l<=last)
			{
				continue;
			}
			last=b[i].r;
			ans2++;
		}
		ans2=m-ans2;
		printf("%d\n",ans2);
	}
	return 0;
}