#include<iostream>
#include<cstring>
using namespace std;
int a[200001];
int n,ans=0;
void dfs(int x,string q)
{
    if(x==n+1)
    {
        int s=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(q[i]==q[j])
                {
                    if(a[i+1]==a[j+1]) s+=a[i+1];
                    break;
                }
            }
        }
        ans=max(ans,s);
        return;
    }
    string p=q;
    q+='r';
    dfs(x+1,q);
    q=p;
    q+='b';
    dfs(x+1,q);
    q=p;
}
void main2()
{
    ans=0;
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,"");
    cout<<ans<<endl;
    return;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--) main2();
    return 0;
}
