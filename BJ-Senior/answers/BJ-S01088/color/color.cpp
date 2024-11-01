#include<bits/stdc++.h>
# define eps 1e-6
#define maxn 2000
using namespace std;
long long n,color[200100],a[200100],cnt[200100],ls[200100],ans,res;
long long calu()
{

    long long result=0;
    long long str=-1,stb=-1;
    for(int i=1;i<=n;i++)
    {

        if(color[i]&&str==a[i])
            result+=a[i];
        if(!color[i]&&stb==a[i])
            result+=a[i];
        if(color[i])
            str=a[i];
        else stb=a[i];
    }
    return result;
}
void k(long long i)
{
    if(i==n+1)
    {
        ans=max(ans,calu());
        return;
    }
    color[i]=1;
    k(i+1);
    color[i]=0;
    k(i+1);
}
long long p(){
    for(int i=1;i<=n;i++)
    {

        cnt[a[i]]++;
    }
    for(int i=maxn;i>=1;i++)
    {

        res=max(res,(cnt[i]-1)*i);
    }
    return res;
}
long long p2()
{

    long long l=1,r=1;
    ls[a[1]]=1;
    bool flag=0;
    while(l<=r&&r<=n)
    {
        if(ls[a[r]]&&(color[ls[a[r]]]!=flag&&ls[a[r]]<l)||(color[ls[a[r]]]==flag&&ls[a[r]]>=l))
        {
            color[ls[a[r]]]=1;
            color[r]=(!flag);
            l=r+1;
            flag=!flag;
        }
        ls[a[r]]=r;
        r++;
    }
    return calu();
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int ai=1;i<=n;i++)   
            cin>>a[i];
        if(n<=15)
        {
            k(1);
            cout<<ans<<endl;
        }
        else
            cout<<max(p(),p2())<<endl;
    }
    return 0;
}
