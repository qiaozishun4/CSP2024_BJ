#include <bits/stdc++.h>

using namespace std;
const int N=1e6+5;
struct node
{
    long long a;
    int c;
}r[N];
bool bmp(node A,node B)
{
    return A.a<B.a;
}
int main()
{

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&r[i].a);
    }
    sort(r+1,r+n+1,bmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            //cout<<r[i].a<<" "<<r[j].a<<endl;
            if(r[i].a==r[j].a||r[j].c==1)continue;
            r[i].a=-1;
            r[i].c=1,r[j].c=1;
            //cout<<r[i].a<<" "<<r[j].a<<endl;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(r[i].a!=-1)ans++;
    }
    printf("%d",ans);
    return 0;
}
