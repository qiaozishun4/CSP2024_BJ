#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,y=0,i;
    string x[55];
    cin>>n;
    for(i=0;i<n;i++) cin>>x[i];
    sort(x,x+n);
    for(i=0;i<n-1;i++)
    {
        if(x[i]!=x[i+1]) y++;
    }
    y++;
    cout<<52-y;
}
