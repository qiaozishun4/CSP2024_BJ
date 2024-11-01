#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
const int N=60;
int n;
struct poker
{
    int hs,v;
}a[N];
string ans[N];
bool vis[N][N];
int to_int(char hs)
{
    if(hs=='D')return 0;//0=fangpian
    if(hs=='C')return 1;//1=caohua
    if(hs=='H')return 2;//2=hongtao
    return 3;//3=heitao
}
int vc_to_int(char v)
{
    if(v=='A')return 1;
    if(v=='T')return 10;
    if(v=='J')return 11;
    if(v=='Q')return 12;
    if(v=='K')return 13;
    return v-'0';
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        char hs,v;
        cin>>hs>>v;
        hs=to_int(hs);
        v=vc_to_int(v);
        a[i].hs=hs;
        a[i].v=v;
        vis[hs][v]=1;
    }
    int cnt=0;
    for(int i=0;i<=3;++i)
    {
        for(int j=1;j<=13;++j)
        {

            if(!vis[i][j])cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
