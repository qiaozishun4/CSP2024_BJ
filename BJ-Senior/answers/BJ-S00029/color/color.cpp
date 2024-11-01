#include<bits/stdc++.h>
using namespace std;
int a[200005];int n;
bool c[200005];//0:red 1:blue
int maxsum=-1;
void dfs(int bt)
{
    if(bt==n+1)
    {
        int res=0;
        for(int i=1;i<=n;++i)
        {
            int last=i-1;
            while(last and c[last]!=c[i])
                --last;
            if(last and a[i]==a[last])res+=a[i];
        }
        maxsum=max(maxsum,res);return;
    }
    c[bt]=0;dfs(bt+1);
    c[bt]=1;dfs(bt+1);
}
int main()
{
    //copied successfully
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;cin>>T;while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        maxsum=-1;dfs(1);
        cout<<maxsum<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
