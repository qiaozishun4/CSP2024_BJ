#include<bits/stdc++.h>
using namespace std;
long long n, k, q;
long long l[100010];
vector<long long> s[100010];
long long r[100010];
long long c[100010];
long long x=0;
long long main2()
{
    cin>>n>>k>>q;
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (long long i=1;i<=n;i++)
    {
        cin>>l[i];
        s[i].clear();
        for (long long j=1;j<=l[i];j++)
        {
            long long x;
            cin>>x;
            s[i].push_back(x);
        }
    }
    for (long long i=1;i<=q;i++)
    {
        cin>>r[i]>>c[i];
        if (r[i]==1)
        {
            long long yes=0;
            for (long long j=1;j<=n;j++)
            {
                for (long long kk=1;kk<=l[j];kk++)
                {
                    if (s[j][kk-1]==1)
                    {
                        for (long long ll=kk+1;ll<=min(kk+k-1, l[j]);ll++)
                        {
                            if (s[j][ll-1]==c[i])
                            {
                                yes=1;
                            }
                        }
                    }
                }
            }
            cout<<yes<<endl;
        }
    }
    //cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    return 0;
}
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    long long t;
    cin>>t;
    for (long long i=1;i<=t;i++)
    {
        main2();
    }
    return 0;
}
