#include<bits/stdc++.h>
using namespace std;
int n,t;
string ans;
int bf[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
string f[7]={"888","108","188","200","208","288","688"};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=14) cout<<bf[n]<<endl;
        else
        {
            ans=f[n%7];
            for(int i=1;i<=n/7-2;i++)
                ans=ans+"8";
            cout<<ans<<endl;
        }
    }
    return 0;
}