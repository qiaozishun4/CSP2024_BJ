#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>a[i];
    }
    for(int i=1 ; i<=n ; i++)
    {
        if(a[i]<=1) cout<<-1<<endl;
        else if(a[i]==2) cout<<1<<endl;
        else if(a[i]>2 && a[i]<=7)
        {
            if(a[i]==5) cout<<2<<endl;
            else if(a[i]==3) cout<<7<<endl;
            else if(a[i]==4) cout<<4<<endl;
            else if(a[i]==6) cout<<6<<endl;
            else if(a[i]==2) cout<<5<<endl;
            else if(a[i]==7) cout<<8<<endl;
            else cout<<'-1'<<endl;
        }
    }
    return 0;
}
