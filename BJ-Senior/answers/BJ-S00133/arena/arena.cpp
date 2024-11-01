/*
    author: honglan0301
    Goodbye OI~~~~~
    2022.7~2024.7

    BJ jiayou!!!
    RDFZ jiayou!!!
    sexy_goodier,didi123,mc123456,xsap,HYX1124,wuyouka,flying,bunH2O,whdywjd,Max_s_xaM,wzc_IOI_czw,fast_photon,mysterious_cat... jiayou!!!

    accelerate.

    //freopen
    duel1.in duel1.out
    detect1.in detect1.out
    color1.in color1.out
    arena1.in arena1.out

    ？WA了
    ？不能输出几个具体的答案？每组数据只有个异或和调锤子？？
    两小时调不出来，开摆了，老年人是这样的

    送给大家一首《心愿》：
    [
        湖水是你的眼神，梦想满天星辰
        心情是一个传说，亘古不变的等候
        成长是一扇树叶的门，童年有一群亲爱的人～
        春天是一段路程，沧海桑田的拥有

        那些我爱的人，那些离逝的风
        那些永远的誓言一遍一遍
        那些爱我的人，那些沉淀的泪
        那些永远的誓言一遍一遍

        湖水是你的眼神，梦想满天星辰
        心情是一个传说，亘古不变的等候
        成长是一扇树叶的门，童年有一群亲爱的人～
        春天是一段路程，沧海桑田的拥有

        那些我爱的人，那些离逝的风
        那些永远的誓言一遍一遍
        那些爱我的人，那些沉淀的泪
        那些永远的誓言一遍一遍

        我们都曾有过一张天真而忧伤的脸
        手握阳光我们望着遥远～
        轻轻的一天天 一年又一年
        长大间我们是否还会在唱起心愿
        轻轻的一天天 一年又一年
        长大间我们是否还会在唱起心愿
        长大间我们是否还会在唱起心愿～
    ]

    再让自己唱一首《歌》
    [
        当我死去的时候，亲爱的，别为我唱悲伤的歌～
        我坟上不必安插蔷薇，也无需浓荫的柏树
        让盖着我的青青的草，淋着雨，也沾着露珠～
        假如你愿意请记着我，要是你甘心，忘了我～
    ]

    不好意思，忘词了，希望大家天天开心，前路一片坦途吧～

    ”雨过不知龙去处，一池草色万蛙鸣“

    2024.10.26 18:28
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
mt19937 rnd(time(0));
mt19937_64 rndl(time(0));

int n,m,la[300005],c[300005],d[19][300005],L,lim,a[300005],nans[300005],ans,T,X[5];
char sss;

int tot,totd,na,dep[300005],isd[300005],op[300005],nwa[300005];

void tkl(int x)
{
    //cout<<"P "<<x<<endl;
    if(isd[x]) return;
    isd[x]=1; if(x>=tot) return na-=(x-tot+1),void();
    tkl(x*2); tkl(x*2+1);
}
void upd(int x)
{
    if(isd[x]) return;
    if(x==1) return;
    int swz=x-(x/2)*2,sop=op[x/2],fa=x/2;
    if(sop==0&&swz==0)
    {
        if(nwa[x]>=dep[fa]) nwa[fa]=nwa[x],tkl(x+1),upd(fa);
        else tkl(x);
    }
    else if(sop==1&&swz==0)
    {
        return;
    }
    else if(sop==0&&swz==1)
    {
        nwa[fa]=nwa[x],upd(fa);
    }
    else if(sop==1&&swz==1)
    {
        if(nwa[x]>=dep[fa]) nwa[fa]=nwa[x],tkl(x-1),upd(fa);
        else nwa[fa]=nwa[x-1],tkl(x),upd(fa);
    }
    else exit(1);
}
void solve2(int nL)
{
    tot=(1<<nL); na=tot*(tot+1)/2; totd=tot*2-1;
    for(int i=1;i<=nL;i++) for(int j=1;j<=(1<<nL-i);j++) op[(1<<nL-i)+j-1]=d[i][j],dep[(1<<nL-i)+j-1]=i;
    for(int i=1;i<=totd;i++) isd[i]=nwa[i]=0;
    for(int i=1;i<=min(tot,n);i++)
    {
        nwa[tot+i-1]=a[i]; upd(tot+i-1);
        if(i>tot/2) nans[i]=na;
    }
    //cout<<endl;
}
void solve()
{
    memset(nans,0,sizeof(nans));
    for(int i=0;i<=L;i++) solve2(i);
    ans=0;
    for(int i=1;i<=m;i++) ans^=(i*nans[c[i]]);
    cout<<ans<<endl;
}

signed main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>la[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    lim=1; while(lim<n) lim<<=1,L++;
    for(int i=1;i<=L;i++) for(int j=1;j<=(1<<L-i);j++) cin>>sss,d[i][j]=sss-'0';
    cin>>T;
    while(T--)
    {
        for(int i=0;i<4;i++) cin>>X[i];
        for(int i=1;i<=n;i++) a[i]=la[i]^X[i%4];
        solve();
        //return 0;
    }
}
