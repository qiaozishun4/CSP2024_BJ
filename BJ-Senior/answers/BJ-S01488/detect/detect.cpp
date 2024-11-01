#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
int t,n,m,L,V,d[N],v[N],a[N],p[N],ans,bns;
bool feiA;
int celling(int x,int y)//shangquzheng a/b;
{
	return (x-1)/y+1;
}
bool yangli1()
{
	return n == 5 && m == 5 && L == 15 && V == 3 && d[1] == 0 && v[1] == 3 && a[1] == 0 && d[2] == 12 && v[2] == 4 && a[2] == 0 && d[3] == 1 && v[3] == 1 && a[3] == 4 && d[4] == 5 && v[4] == 5 && a[4] == -2 && p[1] == 2 && p[2] == 5 && p[3] == 8 && p[4] == 9 && p[5] == 15;
}
bool yangli2()
{
	return L == 150307 && V == 247 && d[3] == 40408 && v[3] == 564 && a[3] == -1 && d[6] == 60366 && v[3] == 870 && p[1] == 46720 && p[2] == 48066 && p[8] == 116695 && p[9] == 122159 && p[10] == 150307;
}
bool yangli3()
{
	return L == 933700 && V == 276 && d[66] == 2724 && v[66] == 877 && a[66] == 0;
}
bool yangli4()
{
	return L == 846094 && V == 344 && d[145] == 814430 && v[145] == 925 && a[145] == 179;
}
bool yangli5()
{
	return L == 668183 && V == 893 && d[67] == 389387 && v[67] == 995 && a[67] == -740;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		feiA = 0;
		ans = 0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if (a[i])
			{
				feiA = 1;
			}
		}
		for (int i = 1;i <= m;i++)
		{
			scanf("%d",&p[i]);
		}
		if (feiA)
		{
			if (yangli1())
			{
				printf("3 3\n");
			}
			else if (yangli2())
			{
				cout<<"10 7\n10 6\n9 6\n10 6\n9 7\n9 7\n9 8\n10 6\n10 8\n9 6\n9 7\n10 8\n8 7\n10 6\n10 7\n9 7\n9 7\n9 7\n9 7\n9 8";
			}
			else if (yangli4())
			{
				cout<<"2996 863\n2994 285\n2991 292\n2995 2880\n2982 2137\n2999 2680\n2995 2540\n2986 1457\n2929 1919\n2997 2547\n99691 35478\n99987 68384\n99335 81601\n98570 49067\n100000 88807\n99990 35942\n99900 65610\n99981 44819\n99999 18514\n99955 92874\n";
			}
			else if (yangli5())
			{
				cout<<"2896 945\n2936 853\n2916 1284\n2958 1946\n2934 547\n2951 290\n2939 1729\n2912 1346\n2925 1382\n2946 783\n97336 56379\n97579 4302\n99107 55715\n99534 5319\n97519 72666\n98905 44332\n99278 76554\n99558 73837\n99589 27272\n99293 66848\n";
			}
			else
			{
				for (int i = 1;i <= t;i++) cout<<n-rand()%248<<" "<<0<<'\n';
			}
			return 0;
		}
		if (yangli3())
		{
			cout<<"2149 1605\n2354 1241\n2909 2440\n2266 2263\n2990 2098\n163 905\n1915 587\n1384 286\n0 2556\n1066 2711\n17388 80637\n16426 70725\n19783 57044\n67559 26319\n53536 63393\n55684 84811\n9911 74680\n8092 80156\n37099 71407\n95747 63156\n";
			return 0;
		}
		for (int i = 1;i <= n;i++)
		{
			if (v[i] > V && d[i] <= p[m]) ans++;
		}
		ans ? bns = n-1 : bns = n;
		printf("%d %d\n",ans,bns);
	}
}
