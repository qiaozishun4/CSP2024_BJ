#include<bits/stdc++.h>
using namespace std;

int n,a[110000],v[110000],last=1100000,lastv=1100000,cnt=0,maxx=-1,b[1100000];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int f=1,tmp,f1=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(i>1&&tmp!=x)
            f1=0;
        else
            tmp=x;
        a[x]++;
        v[x]++;
        if(x<last)last=x;
        if(x>maxx)maxx=x;
    }
    if(f1)
    {
        cout<<n;
        return 0;
    }
    for(int i=1;i<=100000;i++)
    {
        if(a[i]>=1&&i!=last)
        {
            lastv=i;
            break;
        }
    }
    for(int i=1,cur=last;i<=100000;i++)
    {
        if(a[i]>=1&&i!=cur)
        {
            b[cur]=i;
            cur=i;
        }
        if(a[i]>1)f=0;
    }
    if(f)
    {
        cout<<1;
        return 0;
    }
    b[maxx]=maxx;
    while(last<maxx&&lastv<maxx)
    {
        if(lastv>last)
        {
            int x=min(a[last],v[lastv]);
            a[last]-=x;
            v[lastv]-=x;
            if(a[last]<=0)
                last=b[last];
            if(v[lastv]<=0)
                lastv=b[lastv];
        }
        else
        {
            lastv=b[lastv];
        }
    }
    if(lastv==maxx&&last<maxx)
    {
        int x=min(a[last],v[lastv]);
        a[last]-=x;
        v[lastv]-=x;
        if(a[last]<=0)
            last=b[last];
        if(v[lastv]<=0)
            lastv=b[lastv];
    }
    for(int i=1;i<=100000;i++)
    {
        if(a[i]>=1)cnt+=a[i];
    }
    cout<<cnt;
    return 0;
}
