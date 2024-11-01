#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int val,num,use;
    node(int v=0):val(v),num(0),use(0){}
}num[100005];
int n,cn;
int nn[100005];
bool cmp(node a,node b)
{
    return a.val>b.val;
}
int main(void)
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int t;
        scanf("%d",&t);
        if(nn[t]==0)
        {
            nn[t]=++cn,num[cn].val=t,
            num[cn].num=num[cn].use=1;
            continue;
        }
        num[nn[t]].num++,num[nn[t]].use++;
    }
    sort(num+1,num+cn+1,cmp);
    while(n)
    {
        int li=200000,minc=2147483647,hit=0,to=0;
        for(int t=1;t<=cn;t++)
        {
            int i=num[t].val,ii=(li==200000?200000:num[li].val);
            if(ii!=200000&&ii-i<minc&&ii-i>0)
                minc=ii-i,hit=li,to=t;
            if(num[t].use>0)li=t;
        }
        if(minc==2147483647)
        {
            printf("%d",n);
            return 0;
        }
        --num[to].num,--num[hit].use,--n;
        if(num[to].num==0)
        {
            for(int i=to;i<cn;i++)
                num[i]=num[i+1];
            --cn;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
