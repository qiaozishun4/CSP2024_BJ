#include<bits/stdc++.h>
using namespace std;
int T,len;
int n,k,q,maxx,minn;
struct nod1{int last,next,id;}link[300001];
struct nod2{int st,en,l;}id[300001];
int ans[101][200001];
struct nod4{int id,c,num;}f[1000001];
int a[300001]; //cunchu
int p[300001];//lian biao
int r[200001],c[200001];
void bfs()
{
    int tou=0,wei;
    for(int i=p[1];i!=0;i=link[i].last)
    {
        f[++tou].id=link[i].id;
        f[tou].c=1;
        f[tou].num=i;
    }
    wei=tou+1;tou=1;
    //printf("num: id c num\n");
    for(int i=1,to;i<=maxx;i++)
    {
        if(tou==wei)return;
        to=wei;
        while(tou!=to)
        {
            queue<int> dl;
            for(int i=f[tou].num;i>=id[f[tou].id].st;i=link[i].last)
            {
                dl.push(i);
            }
            for(int i=link[f[tou].num].next;i<=id[f[tou].id].en;i=link[i].next)
            {
                dl.push(i);
            }
            while(!dl.empty())
            {
                int u=dl.front();
                dl.pop();
                minn=min(id[f[tou].id].en,u+k-1);
                for(int j=u+1;j<=minn;j++)
                {
                    if(ans[i][a[j]]==10)continue;
                    ans[i][a[j]]++;
                    for(int k=p[a[j]];k!=0;k=link[k].last)
                    {
                        if(link[k].id!=f[tou].id)
                        {
                            f[wei].id=link[k].id;
                            f[wei].c=a[j];
                            f[wei].num=k;
                            wei++;
                            if(wei>1000000)wei=1;
                        }
                    }
                }
            }
            //printf("%.3d:%.3d %.1d %.3d\n",tou,f[tou].id,f[tou].c,f[tou].num);
            tou++;
            if(tou>1000000)tou=1;
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        len=0;maxx=0;
        memset(p,0,sizeof(p));
        memset(ans,0,sizeof(ans));
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&id[i].l);
            id[i].st=len+1;
            id[i].en=len+id[i].l;
            len=id[i].en;
            for(int j=id[i].st;j<=id[i].en;j++)
            {
                scanf("%d",&a[j]);
                link[p[a[j]]].next=j;
                link[j].last=p[a[j]];
                link[j].id=i;
                link[j].next=500000;
                p[a[j]]=j;
            }
        }
//        printf("num id last next\n");
//        for(int i=1;i<=len;i++)
//        {
//            printf("%.3d %.2d %.4d %.4d\n",i,link[i].id,link[i].last,link[i].next);
//        }
        p[0]=0;link[0].last=0;link[0].next=0;
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&r[i],&c[i]);
            maxx=max(maxx,r[i]);
        }
        bfs();
        for(int i=1;i<=q;i++)
        {
            if(ans[r[i]][c[i]]!=0)
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}
