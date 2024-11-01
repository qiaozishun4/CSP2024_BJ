#include<iostream>
#include<cstdio>
#include<cstring>
#include<utility>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=100005;
int pre[N],ask[N];
long long res[N];
string str[25];
pii a[N];
pii maxnode(pii a,pii b)
{
    if (a.first>b.first) return a; else return b;
}
pii minnode(pii a,pii b)
{
    if (a.first<b.first) return a; else return b;
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>pre[i];
    for (int i=1;i<=m;i++) cin>>ask[i];
    int power=0,temp=1;
    while ((temp<<1)<n) temp<<=1,power++;
    for (int i=1;i<=power;i++) cin>>str[i];
    int T,x[4];
    cin>>T;
    int remT=T;
    while (T--)
    {
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for (int i=1;i<=n;i++) a[i]=make_pair(i,pre[i]^x[i%4]);
        int p=power,t=temp,r=0;
        while (p--)
        {
            r++,t>>=1;
            int ins=0;
            for (int i=1;i<=t;i++)
            {
                ins++;
                if (str[r][i-1]=='1')
                {
                    pii jud=maxnode(a[i<<1],a[(i<<1)-1]);
                    if (jud.second>=r) a[ins]=jud; else a[ins]=minnode(a[i<<1],a[(i<<1)-1]);
                }
                else
                {
                    pii jud=minnode(a[i<<1],a[(i<<1)-1]);
                    if (jud.second>=r) a[ins]=jud; else a[ins]=minnode(a[i<<1],a[(i<<1)-1]);
                }
            }
        }
        res[remT-T]=1ll*a[1].first*(remT-T);
    }
    ll final_res=res[1];
    for (int i=2;i<=remT;i++) final_res^=res[i];
    cout<<final_res<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
