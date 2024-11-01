#include<bits/stdc++.h>
using namespace std;
int a[100007];
bool b[100007];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i]&&b[j]==0)
            {
                b[j]=1;
                break;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            cnt++;
            //cout<<i<<endl;
        }
    }
    cout<<cnt;
    return 0;
}
