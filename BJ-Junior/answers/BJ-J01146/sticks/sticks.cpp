#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define maxn (int)1e5
const int d[]={6,2,5,5,4,5,6,3,7,6};
long long t,n;
long long f[maxn+10],p[maxn+10];
vector<long long>v;
int main()
{
    //freopen("sticks.in","r",stdin);
    //freopen("sticks.out","w",stdout);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%lld",&t);
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for(int i=1;i<=maxn;i++)
    {
        p[i]=-1;
        for(int k=0;k<10;k++)
            if(i>=d[k]&&f[i-d[k]]+1<f[i])
            {
                f[i]=f[i-d[k]]+1;
                p[i]=k;
            }
    }
    while(t--)
    {
        scanf("%lld",&n);
        if(n<2)
        {
            printf("-1\n");
            continue;
        }
        int cur=1;
        for(int i=2;i<10;i++)
            if(n>=d[i]&&f[n-d[i]]<f[n-d[cur]])cur=i;
        v.clear();
        v.push_back(cur);
        cur=n-d[cur];
        while(cur)
        {
            v.push_back(p[cur]);
            if(p[cur]<0)break;
            cur-=d[p[cur]];
        }
        if(v.back()>=0)
            for(int i=0;i<v.size();i++)printf("%lld",v[i]);
        else printf("-1");
        printf("\n");
    }
    return 0;
}
//CSP rp++
//为什么我这么弱啊
