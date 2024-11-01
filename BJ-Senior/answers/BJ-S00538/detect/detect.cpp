#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

// double!
// double!
// fast read




/*

qu
jian
kai
bi

!
!
!
!

*/



int n, m, l, V;int d[100010], v[100010], a[100010];
int p[100010];
int pre[1000010]; //pre[i]: the cur of first cam after position i
int now;
struct In
{
    double l, r;
}pos[100010];

bool cmp(In x, In y)
{
    if(x.l != y.l) return x.r < y.r;
    else return x.l > y.l;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int t;
    scanf("%d",&t);
    for(int times = 1; times <= t; times++)
    {
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i = 1; i <= n; i++)
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i = 1; i <= m; i++)
            scanf("%d",&p[i]);
        sort(p+1, p+m+1);


        //solve 1


        memset(pre, 0x3f, sizeof(pre));
        pre[p[1]] = 1;
        for(int i = 1; i <= m; i++)
        {
            for(int j = p[i-1]+1; j <= p[i]; j++)
            {
                pre[j] = i;
            }
        }

        int cnt = 0;
        now = 0;

        for(int i = 1; i <= n; i++) //every car
        {
            if(a[i] >= 0)
            {
                if(p[m] >= d[i]) //detected
                {
                    int lst = 2 * a[i] * (p[m] - d[i]) + v[i] * v[i];
                    if(lst > V * V) //fast
                    {
                        cnt++;
                        if(a[i] == 0)
                        {
                            pos[++now].l = d[i];
                        }
                        else
                        {
                            pos[++now].l = d[i] + (V*V - v[i]*v[i]) * 1.00000000 / (2*a[i]);
                            if(pos[now].l == int(pos[now].l)) pos[now].l += 0.00000001;
                        }
                        pos[now].r = l;
                        // printf("car %d : l = %.2lf, r = %.2lf\n",now,pos[now].l, pos[now].r);
                    }
                }
            }
            else
            {
                int goal = p[pre[d[i]]];
                if(goal < 0x3f3f3f3f) //detected
                {
                    int lst = 2 * a[i] * (goal - d[i]) + v[i] * v[i];
                    if(lst > V * V) //fast
                    {
                        cnt++;
                        pos[++now].l = d[i];
                        pos[now].r = d[i] + (V*V - v[i]*v[i]) * 1.00000000 / (2*a[i]);
                        if(pos[now].r == int(pos[now].r)) pos[now].r -= 0.00000001;
                        // printf("car %d : l = %.2lf, r = %.2lf\n",now,pos[now].l, pos[now].r);
                    }
                }
            }
            

        }

        printf("%d ",cnt);


        //solve 2
        
        
        cnt = 0;
        sort(pos+1, pos+now+1, cmp);
        p[0] = -1;
        int nowfind = 0;
        for(int i = 1; i <= now; i++)
        {
            if(p[nowfind] < double(pos[i].l))
            {
                cnt++;
                while(p[nowfind+1] <= pos[i].r && nowfind + 1 <= m) 
                {
                    nowfind++;
                }
            }
        }
        printf("%d\n",m-cnt);
    }
}