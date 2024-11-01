#include<bits/stdc++.h>
using namespace std;
int a[100005],n,r[100005],cnt,t;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int g=1;g<=t;g++)
    {
        for(int i=0;i<100005;i++) a[i]=0;
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>r[i];
        for(int i=1;i<=n;i++)
        {
            if(a[r[i]]==1) cnt+=r[i];
            else a[r[i]]=1;
        }
        cout<<cnt<<endl;
    }
    return 0;
}