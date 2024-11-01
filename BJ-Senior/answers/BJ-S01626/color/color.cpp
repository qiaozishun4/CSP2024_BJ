#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+5,M=1e6+5;
int a[N],n;
bool c[N];
long long ans,sum,maxn=-1;
void dfs(int step)
{
    if(step>n)
    {
        sum=0;
        for(int i=1;i<=n;++i)
        {
//            cout<<(c[i]?'R':'B');
            for(int j=i-1;j>=1;--j)
            {
                if(c[i]==c[j])
                {
                    if(a[i]==a[j])sum+=a[i];
                    break;
                }
            }
        }
//        cout<<" score:"<<sum;
//        cout<<endl;
        maxn=max(maxn,sum);
        return;
    }
    for(int i=0;i<=1;++i)
    {
        c[step]=i;
        dfs(step+1);
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        maxn=-1;
        memset(c,0,sizeof c);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        dfs(1);
        cout<<maxn<<endl;
    }
    return 0;
}
