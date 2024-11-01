#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int i,n,t;
    int ans[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<15)
        {
            cout<<ans[n]<<endl;
            continue;
        }
        cout<<ans[n%7+7];
        t=n/7-2;
        for(i=0;i<=t;i++)
            cout<<8;
        cout<<endl;
    }
    return 0;
}