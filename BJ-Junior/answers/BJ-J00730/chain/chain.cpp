#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,l,tc,r,c;
vector <vector <int> > a[100005];
bool flag;
void dfs (int u,int d,int tot)
{
    if (flag)
    {
        return;
    }
    if (!tot)
    {
        if (d==c)
        {
            flag=1;
        }
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (u==i)
        {
            continue;
        }
        for (int j=0;j<a[i].size ();j++)
        {
            if (a[i][j][0]==d)
            {
                dfs (i,a[i][j][a[i][j].size ()-1],tot-1);
            }
        }
    }
}
int main()
{
	freopen ("chain.in","r",stdin);
	freopen ("chain.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>k>>q;
        for (int i=1;i<=n;i++)
        {
            cin>>l;
            int tmp[100005]={},cnt=0;
            for (int j=1;j<=l;j++)
            {
                cin>>tmp[j];
            }
            for (int j=0;j<k;j++)
            {
                for (int k=1;k+j<=l;k++)
                {
                    vector <int> ttmp;
                    a[i].push_back (ttmp);
                    for (int ii=k;ii<=k+j;ii++)
                    {
                        a[i][cnt].push_back (tmp[ii]);
                    }
                    cnt++;
                }
            }
        }
        while (q--)
        {
            cin>>r>>c;
            for (int i=1;i<=n;i++)
            {
                for (int j=0;j<a[i].size ();j++)
                {
                    if (a[i][j][0]==1)
                    {
                        int up=i,down=a[i][j][a[i][j].size ()-1];
                        dfs (up,down,r-1);
                    }
                }
            }
            if (!flag)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<1<<endl;
            }
            flag=0;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<a[i].size ();j++)
            {
                a[i][j].clear ();
            }
        }
    }
	return 0;
}
