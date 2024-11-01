#include <iostream>
using namespace std;
int ans[30],t,n,tn,ttn;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    ans[1]=-1;
    ans[2]=1;
    ans[3]=7;
    ans[4]=4;
    ans[5]=2;
    ans[6]=6;
    ans[7]=8;
    ans[8]=10;
    ans[9]=18;
    ans[10]=22;
    ans[11]=20;
    ans[12]=28;
    ans[13]=68;
    ans[14]=88;
    ans[15]=108;
    ans[16]=188;
    ans[17]=200;
    ans[18]=208;
    ans[19]=288;
    ans[20]=688;
    ans[21]=888;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n<=21)
        {
            cout<<ans[n]<<endl;
            continue;
        }
        tn=n%7+14;
        ttn=(n-tn)/7;
        cout<<ans[tn];
        for(int i=1;i<=ttn;i++)
            cout<<8;
        cout<<endl;
    }
    return 0;
}
