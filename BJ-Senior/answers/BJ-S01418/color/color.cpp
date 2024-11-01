#include<bits/stdc++.h>
using namespace std;
int q,n=8,a[200005]={0,3,5,1,5,2,1,2,4},ans;
int s[200005]={0,1,1,2,1,1,2,1,2};
int suan()
{
    int c[200005];
    for(int i=1;i<=n;i++)
    {
        bool flag=true;
        for(int j=i-1;j>=1;j--)
        {
            if(s[i]==s[j])
            {
                if(a[i]==a[j])
                {
                    c[i]=a[i];
                    flag=false;
                }
            }
        }
        if(flag)
        {
            c[i]=0;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)sum+=c[i];
    return sum;
}
void dfs(int idx)
{

    if(idx==n)
    {

        ans=max(suan(),ans);
        return;
    }
    s[idx+1]=1;
    dfs(idx+1);
    s[idx+1]=2;
    dfs(idx+1);
}
int main()
{
     freopen("color.in","r",stdin);
     freopen("color.out","w",stdout);
     cin>>q;
     while(q--)
     {
         ans=0;
         cin>>n;
         for(int i=1;i<=n;i++)
         {
             cin>>a[i];
             s[i]=0x3f3f3f3f;
         }
         dfs(0);
         cout<<ans<<endl;
     }
     fclose(stdin);
     fclose(stdout);
    return 0;
}

