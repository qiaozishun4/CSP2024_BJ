#include<bits/stdc++.h>
using namespace std;
int a[7]={-1,-1,1,7,4,2,6};
int b[7]={8,10,18,22,20,28,68};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;cin>>T;
    while(T)
    {
        cin>>n;
        if(n<7)
        {
            cout<<a[n]<<endl;
            T--;continue;
        }
        int r=n/7-1;
        cout<<b[n%7];
        for(int i=0;i<r;i++)
            cout<<8;
        cout<<endl;
        T--;
    }
    return 0;
}