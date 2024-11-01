#include<bits/stdc++.h>
using namespace std;
int n,ma;
struct node
{
    int num,color=0;
}a[100010];
int calc()
{
    int c=0;
    for(int i=1;i<=n;i++)
        for(int j=i-1;j>=1;j--)
            if(a[i].color==a[j].color)
            {
                if(a[i].num==a[j].num) c+=a[i].num;
                break;
            }
    return c;
}
void dfs(int step)
{
    if(step>n)
    {
        ma=max(ma,calc());
        return;
    }
    a[step].color=1;
    dfs(step+1);
    a[step].color=0;
    dfs(step+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].num;
        ma=0;
        dfs(1);
        cout<<ma<<endl;
//        a[2].color=1;
//        cout<<calc()<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
