#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#define reg register
#define fin freopen("chain.in","r",stdin);
#define fout freopen("chain.out","w",stdout);
using namespace std;
int tests,n,m,k,q,maxx,maxr;
int st[200005],en[200005];
int a[200005];
int pl[200005];
vector<int> t[200005];
int f[105][200005];//f[i][j]: at the end of the i-st round, whether it is possible to land on j
int diff[200005];
int num_painted[200005];//0: haven't done; -1: done; i>=1: done except i
int qr[200005],qe[200005];
bool g[105][200005];
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tests;
    while(tests--)
    {
        cin >> m >> k >> q;
        for(reg int i=0;i<=m+1;i++)
            st[i]=en[i]=0;
        maxx=maxr=0;
        for(reg int i=1;i<=m;i++)
        {
            st[i]=en[i-1]+1;
            int l;
            cin >> l;
            en[i]=st[i]+l-1;
            for(reg int j=st[i];j<=en[i];j++)
            {
                pl[j]=i;
                cin >> a[j];
                maxx=max(maxx,a[j]);
            }
        }
        n=en[m];
        for(reg int i=1;i<=q;i++)
        {
            cin >> qr[i] >> qe[i];
            maxr=max(maxr,qr[i]);
        }
        /*
        cout << "a: \n";
        for(int i=1;i<=n;i++)
            cout << a[i] << ' ';
        cout << endl;
        //*/
        for(reg int i=1;i<=maxx;i++)
            t[i].clear();
        for(reg int i=1;i<=n;i++)
            t[a[i]].push_back(i);
        a[0]=a[n+1]=0;
        for(reg int r=1;r<=maxr;r++)
            for(reg int i=0;i<=n;i++)
                f[r][i]=0;
        for(reg int i:t[1])
            f[1][i]=1;
        for(reg int r=1;r<=maxr;r++)
        {
            if(r>1)
            {
                for(reg int i=1;i<=maxx;i++)
                    num_painted[i]=0;
                for(reg int i=1;i<=n;i++)
                {
                    if(!f[r-1][i])
                        continue;
                    int x=num_painted[a[i]];
                    if(x==-1)
                        continue;
                    if(x)
                    {
                        if(x!=pl[i])
                        {
                            for(reg int j:t[a[i]])
                                f[r][j]=1;
                            num_painted[a[i]]=-1;
                        }
                    }
                    else
                    {
                        for(reg int j:t[a[i]])
                            if(pl[j]!=pl[i])
                                f[r][j]=1;
                        num_painted[a[i]]=pl[i];
                    }
                }
            }
            for(reg int i=1;i<=n;i++)
                diff[i]=0;
            for(reg int i=1;i<=n;i++)
            {
                if(!f[r][i])
                    continue;
                diff[i+1]++;
                diff[min(en[pl[i]],i+k-1)+1]--;
            }
            for(reg int i=1;i<=n;i++)
                f[r][i]=f[r][i-1]+diff[i];
            for(reg int i=1;i<=n;i++)
                if(f[r][i]>1)
                    f[r][i]=1;
        }
        /*
        for(int r=1;r<=4;r++)
        {
            for(int i=1;i<=n;i++)
                cout << f[r][i] << ' ';
            cout << endl;
        }
        //*/
        for(reg int r=1;r<=maxr;r++)
            for(reg int i=1;i<=maxx;i++)
                g[r][i]=0;
        for(reg int r=1;r<=maxr;r++)
            for(reg int i=1;i<=n;i++)
                g[r][a[i]]|=bool(f[r][i]);
        for(reg int i=1;i<=q;i++)
            cout << g[qr[i]][qe[i]] << endl;
    }
	return 0;
}
