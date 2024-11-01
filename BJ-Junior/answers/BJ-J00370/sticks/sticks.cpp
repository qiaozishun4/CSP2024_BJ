#include <iostream>
#include <cmath>
using namespace std;
int f[100005]={0,-1,1,7,4,2,6,8,10},q[8]={0,0,1,7,4,2,0,8};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,x,i,j;
    for(i=9;i<=100000;i++)
    {
        f[i]=1e9;
        for(j=2;j<=7;j++)
        {
            x=f[i-j]*10+q[j];
            f[i]=min(f[i],x);
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
}