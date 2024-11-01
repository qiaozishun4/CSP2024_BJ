#include<bits/stdc++.h>
using namespace std;
int n;
struct stu{
    int num;
    bool se;
}a[100005];
long long ji(int x){
    long long s=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(a[j].se==a[i].se)
            {
                if(a[j].num==a[i].num)
                    s+=a[i].num;
                break;
            }
        }
    }
    return s;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int w=1;w<=t;w++)
    {
        int s=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].num;
        for(long long i=0;i<(1<<n);i++)
        {
            long long x=i,r;
            for(int j=1;j<=n;j++)
            {
                a[j].se=(x&1);
                x>>=1;
            }
            r=ji(i);
            if(r>s||s==0)
                s=r;
        }
        printf("%lld\n",s);
    }
    return 0;
}
