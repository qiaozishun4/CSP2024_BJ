#include<iostream>
using namespace std;
int T;
int n,k,q,r,c;
int l[100001]={},s[100001][2001]={};
bool flag;
void dfs(int ed,int rd,int lpp)
{
    if(rd==r)
    {
        if(ed==c)flag=true;
        return;
    }
    for(int i=1;i<=n&&!flag;i++)
        if(i!=lpp)
            for(int j=1;j<=l[i]&&!flag;j++)
                if(s[i][j]==ed)
                    for(int lt=2;lt<=k&&j+lt<=l[i]&&!flag;lt++)
                        dfs(s[i][j+lt],rd+1,i);
}
int main(void)
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&l[i]);
            for(int j=1;j<=l[i];j++)
                scanf("%d",&s[i][j]);
        }
;        while(--q>=0)
        {
            scanf("%d%d",&r,&c);
            flag=false;
            dfs(1,0,0);
            printf("%d\n",(int)flag);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
