#include<bits/stdc++.h>
using namespace std;
int calc(int n)
{
    int a=n%7, num8=n/7, ans=0;
    if(n<2) return -1;
    if(n==2) return 1;
    if(n==3) return 7;
    if(n==4) return 4;
    if(n==5) return 2;
    if(n==6) return 6;
    if(n==10) return 22;
    if(n==17) return 200;
    if(a==0) ans+=8;
    else if(a==1) ans+=10;
    else if(a==2) ans+=18;
    else if(a==3) ans+=22;
    else if(a==4) ans+=200;
    else if(a==5) ans+=28;
    else if(a==6) ans+=68;
    if(num8 == 1) return ans;
    for(int j=0; j<num8; ++)
    {
        ans*=10;
        ans+=8;
    }
    if(a==4)
    {
        ans-=8;
        ans/=10;
    }
    return ans;
}
int main()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    int n,t,ans;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n;
        ans = calc(n);
        cout << ans << endl;
    }
    return 0;
}
