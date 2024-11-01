#include<bits/stdc++.h>
#define Debug
using namespace std;
const int M=1E6+1;
int d[M],v[M],a[M],p[M],f[M],sr[M],ygg[M];
void Init()
{
    memset(d,0,sizeof(d));
    memset(v,0,sizeof(v));
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    memset(sr,0,sizeof(sr));
    memset(f,0,sizeof(f));
    memset(ygg,0,sizeof(ygg));
}
int Speed(int now,int V)
{
    return (V*V-v[now]*v[now])/(2*a[now]*1.0)+d[now];
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        Init();
        bool f1,f2,f3;
        int n,m,l,V;
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            if(a[i]!=0)
                sr[i]=Speed(i,V);
            else
                sr[i]=d[i];
            if(a[i]>0)
                f2=f3=1;
            if(a[i]==0)
                f1=f3=1;
            if(a[i]<0)
                f1=f2=1;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
            f[p[i]]=1;
        }
        for(int i=1;i<=l;i++)
            f[i]+=f[i-1];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0 && v[i]>V && f[l]-f[d[i]-1]>0)
                ans++;
            else if(a[i]>0 && f[l]-f[sr[i]]>0)
                ans++;
            else if(a[i]<0 && f[sr[i]]-f[d[i]-1]>0)
                ans++;
        }
        printf("%d ",ans);
        int cnt=ans;
        if(!f1)
            printf("%d\n",m-1);
        else if(!f2)
            printf("%d\n",m-1);
        else if(!f3)
        {
            for(int i=1;i<=m;i++)
            {
                bool flag=1;
                for(int j=1;j<=n;j++)
                {
                    if(!ygg[i])
                    {
                        if(sr[j]<p[i] && p[i]<=d[j])
                            if(!flag)
                                cnt--,flag=1;
                    }
                }
            }
            printf("%d\n",m-cnt);
        }
        else
            printf("%d\n",m-ans);
    }
    return 0;
}
/*
与加速度有关的定义和公式如下:
• 匀加速运动 是指物体在运动过程中,加速度保持不变的运动,即每单位时间内
速度的变化量是恒定的。
• 当一辆车的初速度为 v 0 、加速度 a ̸ = 0,做匀加速运动,则 t 时刻后它的速度
v 1 = v 0 + a × t,它的位移(即行驶路程)s = v 0 × t + 0.5 × a × t 2 。
• 当一辆车的初速度为 v 0 、加速度 a ̸ = 0,做匀加速运动,则当它的位移(即行驶
√
路程)为 s 时,这辆车的瞬时速度为 v 0 2 + 2 × a × s。
• 当一辆车的初速度为 v 0 、加速度 a ̸ = 0,在它的位移(即行驶路程)为
这辆车的瞬时速度为 v 1 。
如果你使用浮点数进行计算,需要注意潜在的精度问题。
*/