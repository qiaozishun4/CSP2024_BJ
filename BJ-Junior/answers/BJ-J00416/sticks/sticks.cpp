#include<bits/stdc++.h>
using namespace std;
int st[20]={6,2,5,5,4,5,6,3,7,6};
int cnt(int n)
{
    int sum=0;
    while(n)
    {
        sum+=st[n%10];
        n/=10;
    }
    return sum;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        bool flag=0;
        cin>>x;
        for(int j=0;j<=(1e3) && !flag;j++)
        {
            if(cnt(j)==x)
            {
                cout<<j<<"\n";
                flag=1;
            }
        }
        if(!flag) cout<<-1;
    }
    return 0;
}
