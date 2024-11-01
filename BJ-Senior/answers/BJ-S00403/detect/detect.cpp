#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int n,m,l,vv,d[N],v[N],a[N],p[N],son[30],fa[30][30];

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&l,&vv);
        bool f1=true,f2=true;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            if(a[i]!=0)
                f1=false;
            if(a[i]<=0)
                f2=false;
        }
        for(int i=1;i<=m;i++)
            scanf("%d",&p[i]);
        sort(p+1,p+1+m);
        if(f1)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(v[i]>vv && p[m]>=d[i])
                    ans++;
            }
            printf("%d ",ans);
            if(ans==0)
                printf("%d\n",m);
            else
                printf("%d\n",m-1);
        }
        else if(f2)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                int fz=vv*vv-v[i]*v[i],fm=2*a[i];
                if(v[i]>vv)
                    ;
                else
                    d[i]+=fz/fm+1;
                if(p[m]>=d[i])
                    ans++;
            }
            printf("%d ",ans);
            if(ans==0)
                printf("%d\n",m);
            else
                printf("%d\n",m-1);
        }
        else
        {
            memset(son,0,sizeof(son));
            memset(fa,0,sizeof(fa));
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                {
                    if(v[i]>vv)
                    {
                        for(int j=1;j<=m;j++)
                        {
                            if(p[j]>=d[i])
                            {
                                son[j]++;
                                fa[i][0]++;
                                fa[i][fa[i][0]]=j;
                            }
                        }
                    }
                    if(fa[i][0]!=0)
                        ans++;
                }
                else if(a[i]>0)
                {
                    int fz=vv*vv-v[i]*v[i],fm=2*a[i];
                    if(v[i]>vv)
                        ;
                    else
                        d[i]+=fz/fm+1;
                    for(int j=1;j<=m;j++)
                    {
                        if(p[j]>=d[i])
                        {
                            son[j]++;
                            fa[i][0]++;
                            fa[i][fa[i][0]]=j;
                        }
                    }
                    if(fa[i][0]!=0)
                        ans++;
                }
                else
                {
                    if(v[i]>vv)
                    {
                        int fz=vv*vv-v[i]*v[i],fm=2*a[i];
                        int en;
                        if((fz%fm)==0)
                            en=d[i]+fz/fm-1;
                        else
                            en=d[i]+fz/fm;
                        for(int j=1;j<=m;j++)
                        {
                            if(p[j]>=d[i] && p[j]<=en)
                            {
                                son[j]++;
                                fa[i][0]++;
                                fa[i][fa[i][0]]=j;
                            }
                        }
                        if(fa[i][0]!=0)
                            ans++;
                    }
                }
            }
            printf("%d ",ans);
            ans=0;
            while(true)
            {
                int mm=0,id;
                for(int i=1;i<=m;i++)
                {
                    if(son[i]>mm)
                    {
                        mm=son[i];
                        id=i;
                    }
                }
                if(mm==0)
                    break;
                for(int i=1;i<=n;i++)
                {
                    bool ff=false;
                    for(int j=1;j<=fa[i][0];j++)
                    {
                        if(fa[i][j]==id)
                        {
                            ff=true;
                            break;
                        }
                    }
                    if(ff)
                    {
                        for(int j=1;j<=fa[i][0];j++)
                            son[fa[i][j]]--;
                        fa[i][0]=0;
                    }
                }
                son[id]=0;
                ans++;
            }
            printf("%d\n",m-ans);
        }
    }
    return 0;
}
