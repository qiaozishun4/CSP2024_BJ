#include<bits/stdc++.h>
using namespace std;
int n;
int a[100015],b[100015];
int ans=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int h=-1;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        b[t]++;
        h=max(h,t);
    }
    int s=0;
    for(int i=1;i<=h;i++)
    {
        if(b[i])
        {
            s++;
            a[s]=b[i];
        }
    }
    int m=a[1];
    for(int i=1;i<s;i++)
    {
        ans+=min(m,a[i+1]);
        m=max(m,a[i+1]);
    }
    cout<<n-ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
