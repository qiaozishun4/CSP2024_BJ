#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    int smallans[8]={-1,-1,1,7,4,2,6,8};
    int ans[8]={88,68,28,20,22,18,10};
    while(T--)
    {
        cin>>n;
        if(n<=7)
            cout<<smallans[n]<<endl;
        else
        {
            int len=(n+6)/7;
            int r=len*7-n;
            cout<<ans[r];
            for(int i=0;i<len-2;i++) cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
