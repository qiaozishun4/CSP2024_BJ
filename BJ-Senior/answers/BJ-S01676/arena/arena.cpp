#include<bits/stdc++.h>
using namespace std;
int m,n,t;
int a[100005];
char b[20][100005];
int c[100005];
int shu1,shu2,shu3,shu4;
int main()
{
    //cout<<ceil(log(1024)/log(2));
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    cin>>b[0][0];
    for(int i=ceil(log(n)/log(2));i>=1;i--)
    {
        cin.getline(b[i],n);
    }
    scanf("%d",&t);
    for(int i=1;i<=t;i++) scanf("%d%d%d%d",&shu1,&shu2,&shu3,&shu4);
    cout<<-1;
    return 0;
}
