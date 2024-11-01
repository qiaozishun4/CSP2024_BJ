#include<bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
bool flag;
int ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        flag=true;
        for(int j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cnt++;
        }
        if(cnt==52)
        {
            cout<<0<<endl;
            return 0;
        }
    }
    ans=52-cnt;
    cout<<ans<<endl;
    return 0;
}