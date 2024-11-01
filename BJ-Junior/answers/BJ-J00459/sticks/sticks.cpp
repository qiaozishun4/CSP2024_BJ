#include<iostream>
using namespace std;
int a[10]={0,-1,1,7,4,2,6};
int b[10]={8,10,18,22,20,28,68,88};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<7) cout<<a[n]<<endl;
        else
        {
            cout<<b[n%7];
            for(int i=1;i<n/7;i++) cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
