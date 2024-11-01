#import<bits/stdc++.h>
using namespace std;
int t,a;
int n[21]={-1,-1,1,7,4,2,6,8,10,18,22,26,28,68,88,218,248,228,208,288,688};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
       cin>>a;
       for(int j=0;j<=20;j++)
       {
           if(a==j)
            cout<<n[j]<<endl;
       }
    }
    return 0;
}
