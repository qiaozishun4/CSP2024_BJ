#include<bits/stdc++.h>
using namespace std;
const int N=50000+10;
int a[10]={6,2,5,5,4,5,6,3,7,6},biao[N];
int chai(int x)
{
    int sum=0;
    while(x)
    {
        sum+=a[x%10];
        x/=10;
    }
    return sum;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    biao[0]=-1;
    for(int i=1;i<=N;i++)
    {
        biao[i]=chai(i);
    }
    int T,n;
    cin>>T;
    while(T--)
    {
        bool flag=0;
        cin>>n;
        for(int i=1;i<=N;i++)
        {
            if(biao[i]==n)
            {
                cout<<i<<"\n";
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            cout<<-1<<"\n";
        }
    }
    return 0;
}
