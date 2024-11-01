#include <bits/stdc++.h>
using namespace std;
string b[100];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,flag,ans=0;
    string a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        flag=0;
        cin>>a;
        b[i]=a;
        for(int j=0;j<i;j++)
        {
            if(b[j]==a)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            ans+=1;
        }
    }
    cout<<52-ans;
    return 0;
}
