#include <bits/stdc++.h>
using namespace std;

int c = 52;
int n,sum = 0;
int s[1005];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        if(n==1)
        {
            cout<<"51"<<"\n";
            break;
        }
    }
    if(n>1)
    {
        c -= n;
        cout<<c<<"\n";
    }
    return 0;
}
