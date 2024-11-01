#include<iostream>
using namespace std;
int s[15]={6,2,5,5,4,5,6,3,7,6};
long long a[10010]={0};
long long w=0;
int how_many(long long x)
{
    int ans=0;
    while(x)
    {
        ans+=s[x%10];
        x/=10;
    }
    return ans;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            while(n)
            {
                cout<<8;
                n-=7;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1)
        {
            cout<<10;
            while(n>8)
            {
                cout<<8;
                n-=7;
            }
            cout<<endl;
            continue;
        }
        while(!a[n])
        {
            int tmp=how_many(w);
            if(!a[tmp])a[tmp]=w;
            w++;
        }
        cout<<a[n]<<endl;
    }
    return 0;
}
