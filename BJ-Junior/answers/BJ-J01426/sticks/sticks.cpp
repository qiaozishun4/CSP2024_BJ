#include<bits/stdc++.h>
using namespace std;
int num(int a)
{
    if(a==0) return 6;
    if(a==1) return 2;
    if(a==2) return 5;
    if(a==3) return 5;
    if(a==4) return 4;
    if(a==5) return 5;
    if(a==6) return 6;
    if(a==7) return 3;
    if(a==8) return 7;
    if(a==9) return 6;
}
int cnt(int a)
{
    int ans=0;
    while(a)
    {
        int c=a%10;
        ans+=num(c);
        a/=10;
    }
    return ans;
}
const int N=1e5+10;
int t,n;
int a[N];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    for(int i=1;i<=N;i++)
    {
        a[i]=cnt(i);
    }
    while(t--)
    {
        cin>>n;
        bool f=false;
        for(int i=1;i<=N;i++)
            if(a[i]==n)
            {
                cout<<i<<"\n";
                f=true;
                break;
            }
        if(!f) cout<<-1<<"\n";
    }
    return 0;
}
