#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[1000001];
int chk(int c,int nn,int A[])
{
    int fcnt=0;
    for (int i=1;i<=nn;i++)
        if (A[i]==c) fcnt++;
    return fcnt;
}
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        int cnta[1000001];
        memset(cnta,0,sizeof(cnta));
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++)
        {
            if (i==1) cnta[i]=a[i];
            else
            {
                int ltcnt=0;
                for (int j=1;j<i;j++)
                    if (a[i]==cnta[j]) ltcnt++;
                if (ltcnt==0) cnta[i]=a[i];
            }
        }
        sort(cnta+1,cnta+n+1);
        int ls=chk(cnta[1],n,a);
        for (int i=1;i<=n;i++)
            if (chk(cnta[i],n,a)>ls) ls=chk(cnta[i],n,a);
        int num=0;
        for (int i=1;i<=n;i++)
            if (chk(cnta[i],n,a)==ls) num=cnta[i];
        int cmin=(ls-1)*num,cmax=(chk(cnta[n],n,a)-1)*cnta[n];
        cout<<max(cmin,cmax)<<"\n";
    }
    return 0;
}
//I have not solve this problem perfectly, even though I have got a few ideas about it. I will be look forward to the right solution.
//This might not be a successful result, but it is all what I have and what should I get. AFOed. Good luck for every OIer.
