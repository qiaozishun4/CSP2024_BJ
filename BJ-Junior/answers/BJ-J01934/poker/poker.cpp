#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string pk[60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        bool f=true;
        cin>>pk[i];
        for(int j=0;j<i;j++)
        {
            if(pk[j]==pk[i])
                f=false;
        }
        if(f==true)ans--;
    }
    cout<<ans;
    return 0;
}
