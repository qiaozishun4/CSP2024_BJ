#include <iostream>
#include <cstdio>

using namespace std;//0:6 1:2 2:5 3:5 4:4 5:5 6:6 7:3 8:7 9:6

int dfs(int n,int m)
{
    if(n == 0)
        return m;
    int l[15] = {0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff};
    if(n >= 6 && m != 0)
        l[0] = dfs(n - 6,m * 10 + 0);
    if(n >= 2)
        l[1] = dfs(n - 2,m * 10 + 1);
    if(n >= 5)
        l[2] = dfs(n - 5,m * 10 + 2);
    if(n >= 4)
        l[3] = dfs(n - 4,m * 10 + 4);
    if(n >= 3)
        l[4] = dfs(n - 3,m * 10 + 7);
    if(n >= 7)
        l[5] = dfs(n - 7,m * 10 + 8);
    int mv = 0x7fffffff;
    for(int mi = 0;mi < 6;mi ++)
    {
        if(l[mi] < mv)
            mv = l[mi];
    }
    return mv;

}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int Ti = 0;Ti < T;Ti ++)
    {
        int n;
        scanf("%d",&n);
        //printf("%d",0x7fffffff);
        int l = dfs(n,0);
        printf("%d\n",(l == 0x7fffffff) ? -1 : l);
    }
    return 0;
}
