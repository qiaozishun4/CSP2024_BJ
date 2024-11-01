#include<bits/stdc++.h>
using namespace std;
int r[100005];
int c1[100005];
int c2[100005];
void cz(int n,int i)//n表示总共要减去的值 i表示起始位
{
    while(n!=0)
    {
        if(c2[i]>=n)
        {
            c2[i]-=n;
            n=0;
        }
        else
        {
            n-=c2[i];
            c2[i]=0;
            i++;
        }
    }
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&r[i]);
    }
    sort(r+1,r+n+1);
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        c1[cnt]++;
        c2[cnt]++;
        if(r[i]!=r[i+1])
        {
            cnt++;
        }
    }
    cnt--;
    for(int i=1;i<=cnt;i++)
    {
        int sum=0;
        for(int j=i+1;j<=cnt;j++)
        {
            sum+=c2[j];
        }
        if(sum>=c1[i])
        {
            cz(c1[i],i+1);
            c1[i]=0;
        }
        else
        {
            cz(sum,i+1);
            c1[i]-=sum;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=c1[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
