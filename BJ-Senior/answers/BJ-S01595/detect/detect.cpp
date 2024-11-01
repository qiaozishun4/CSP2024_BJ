#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("detect.in","w",stdin);
    freopen("detect.out","r",stdout);
    int t;
    cin>>t;
    int n,m,l,x;
    cin>>n>>m>>l>>x;
    int num=0,sum=x;
    int d[n],v[n],a[n];
    int p[m],p1[m];
    int q;
    int c[n];
    for(int i=1;i<=n;i++)
    {
        cin>>d[i]>>v[i]>>a[i];
        c[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>p[i];
    }
    for(int i=1;i<=m;i++)
    {
        p1[i]=p[i];
    }
    for(int i=1;i<=n;i++)//遍历每一辆车
    {
        for(int j=d[i];j<=l;j++)//读取车初始位置，并循环增加
        {
            int q=1;
            if(a[j]==0)//如果加速度为零
            {
                for(int k=1;k<=m;k++) //遍历测速仪位置
                {
                    if(p[k]==d[i])//测速仪位置等于当前位置
                    {
                        if(v[i]>x)//当前速度大于限速
                        {
                            if(c[i]==1)
                            {
                                num++;//超速车数量加一
                                c[i]=0;
                            }
                            if(p1[k]!=l+1)//当前测速仪没有测过超速
                            {
                                sum--;//关闭数量减一
                                p1[k]=l+1;//设定为保留；
                            }
                        }
                    }
                }
            }
            else//如果不为零
            {
                for(int k=1;k<=m;k++)//遍历测速仪位置
                {
                    double speed=v[i]*v[i]-2*a[i]*q;
                    sqrt(speed);
                    if(speed>0)//如果当前速度大于零
                    {
                        if(p[k]==d[i])//测速仪位置等于当前位置
                        {
                            if(speed>x)//当前速度大于限速
                            {
                                if(c[i]==1)
                                {
                                    num++;//超速车数量加一
                                    c[i]=0;
                                }
                                if(p1[k]!=l+1)//当前测速仪没有测过超速
                                {
                                    sum--;//关闭数量减一
                                    p1[k]=l+1;//设定为保留；
                                }
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            q++;
        }
    }
    cout<<num<<" "<<sum;
    return 0;
}