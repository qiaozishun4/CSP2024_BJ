#include<bits/stdc++.h>
using namespace std;
int num[]={6,2,5,5,4,5,6,3,7,6};
int number(int x)
{
    int re=0;
    while(x)
    {
        int temp=x%10;
        re+=num[temp];
        x/=10;
    }
    return re;
}
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
        int ans=1;
        while(ans<500000)
        {
            if(number(ans)==n) break;
            ans++;
        }
        if(number(ans)==n) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
