#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int t,n,a[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int ma[7]={108,188,200,208,288,688,888};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=14) cout<<a[n]<<endl;
        else
        {
            n-=15;
            int k=n%7,m=n/7;
            cout<<ma[k];
            for(int i=1;i<=m;i++)
                cout<<"8";
            cout<<endl;
        }
    }
    return 0;
}