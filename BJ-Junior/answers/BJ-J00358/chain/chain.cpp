#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct fs
{
    int f = -1,s = -1;
};
short int s[10000][20000];
int n;
int sh(int n,int m)
{
    int i = 0;
    while(true)
    {
        if(s[m][i] == -1)
            return -1;
        if(s[m][i] == n)
            return i;
        i ++;
    }
}


bool dfs(int n,int m)
{
    if(n == 0)
    {
        if(sh(s[m][1],m) != -1)
            return true;
        return false;
    }
    for(int i = 0;i < n;i ++)
    {
        if(i == m)
            continue;
        if(sh(s[m][0],i) >= 2 && dfs(n - 1,i))
            return true;
    }
    return false;
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int Ti = 0;Ti < T;Ti ++)
    {
        int k,q;
        scanf("%d %d %d",&n,&k,&q);\

        for(int i_i = 0;i_i < n;i_i ++)
        {
            int l;
            scanf("%d",&l);
            //fill(&s[i_i][0],&s[i_i][j],-1)
            for(int i_j = 0;i_j < l;i_j ++)
                scanf("%d",&s[i_i][i_j]);
            s[i_i][l] = -1;
        }
        fs st[100000];
        for(int i_i = 0;i_i < q;i_i ++)
        {
            int f,s;
            scanf("%d %d",&f,&s);
            st[i_i].f = f;
            st[i_i].s = s;
        }


        for(int ri = 0;ri < q;ri ++)
        {
            bool ret = false;
            for(int i = 0;i < n;i ++)
            {
                int l = sh(st[i].s,i);
                if(l >= 2 && dfs(st[i].f,i))
                {
                    ret = true;
                    break;
                }
            }
            printf("%d\n",(ret) ? 1 : 0);
        }
    }
    return 0;
}
