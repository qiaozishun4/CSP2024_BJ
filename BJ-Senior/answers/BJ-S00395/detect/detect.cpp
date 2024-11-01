#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;
int T;

int n,m,L,V;//n,m,L,V,分别表示车辆数量、测速仪数量、主干道长度和道路限速。
int p[N];

struct car{
    int d,v,a;//第 i 辆车从主干道上距离最南端 d_i 的位置驶入,以 v_i 的初速度和 a_i 的加速度做匀加速运动向北行驶
    double l,r;//其超速区间为l-r;
    bool flagl,flagr;//区间两端是否可取
    bool flag;//会超速
}c[N];
int cnt;//超速车辆数
int ans;//要用多少摄像头
bool spa,spb,spc;

void work1()
{
    int pm = 0;
    for(int i = 1;i <= m;i++)
    {
        cin >> p[i];
        pm = max(pm,p[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        if(pm >= c[i].d && c[i].v > V)
            cnt++;
    }
    cout << cnt << ' ' << ((cnt == 0) ? m : (m - 1)) << endl;
}

void work2()
{
    int pm = 0;
    for(int i = 1;i <= m;i++)
    {
        cin >> p[i];
        pm = max(pm,p[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        if(c[i].flag)
        {
            if((double)c[i].l <= pm)
            {
                if(c[i].l == pm && c[i].flagl == false)
                    continue;
                cnt++;
            }
            // cout << c[i].l << ' ' << c[i].r << endl;
        }
    }
    cout << cnt << ' ' << ((cnt == 0) ? m : (m - 1)) << endl;
    return ;
}

void work3()
{
    return ;
}

void work4()
{
    // for(int i = 1;i <= n;i++)
    // {
    //     if(!c[i].flag)
    //         continue;
    //     for(int j = 1;j <= m;j++)
    //     {
    //         if(p[j] == c[i].l)
    //         {
    //             if(a[i])
    //         }

    // }
    return ;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--)
    {
        ans = 0,cnt = 0;
        memset(c,0,sizeof(c));
        spa = true,spb = true,spc = true;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++)
        {
            cin >> c[i].d >> c[i].v >> c[i].a;
            if(c[i].a == 0)
            {
                spb = false;
                spc = false;
                if(c[i].v > V)
                {
                    c[i].l = c[i].d;
                    c[i].r = L;
                    c[i].flagl = true;
                    c[i].flagr = true;
                    c[i].flag = true;
                }
            }
            else if(c[i].a > 0)
            {
                spa = false;
                spc = false;
                if(c[i].v > V)
                {
                    c[i].l = c[i].d;
                    c[i].r = L;
                    c[i].flagl = true;
                    c[i].flagr = true;
                    c[i].flag = true;
                }
                else if(c[i].v == V)
                {
                    c[i].l = c[i].d;
                    c[i].r = L;
                    c[i].flagl = false;
                    c[i].flagr = true;
                    c[i].flag = true;
                }
                else if(c[i].v <= V)
                {
                    double x = (double)(V * V - c[i].v * c[i].v) / (double)(2.0 * c[i].a);
                    if(x + c[i].d <= L)
                    {
                        c[i].l = c[i].d + x;
                        c[i].r = L;
                        c[i].flagl = false;
                        c[i].flagr = true;
                        c[i].flag = true;
                    }
                }
            }
            else if(c[i].a < 0)
            {
                spb = false;
                spa = false;
                if(c[i].v > V)
                {
                    double x = (double)(V * V - c[i].v * c[i].v) / (double)(2.0 * c[i].a);
                    if(x <= L)
                    {
                        c[i].l = c[i].d;
                        c[i].r = c[i].d + x;
                        c[i].flagl = true;
                        c[i].flagr = false;
                        c[i].flag = true;
                    }
                    else
                    {
                        c[i].l = c[i].d + x;
                        c[i].r = L;
                        c[i].flagl = true;
                        c[i].flagr = true;
                        c[i].flag = true;
                    }
                }
                else if(c[i].v == V)
                {
                    c[i].l = c[i].d;
                    c[i].r = c[i].d;
                    c[i].flagl = true;
                    c[i].flagr = true;
                    c[i].flag = true;
                }
            }

        }
        if(spa)
            work1();
        else if(spb)
            work2();
        else if(spc)
            work3();
        else
            work4();
    }

    return 0;
}
