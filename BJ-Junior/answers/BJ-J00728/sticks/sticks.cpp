#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const int N=1e5+233;
const int s[10]={6,2,5,5,4,5,6,3,7,6};
//               0 1 2 3 4 5 6 7 8 9
// {2,3,4,5,6,7} {1,7,4,2,0,6,8}
//                2 3 4 5 6 6 7
inline void _main()
{
    int n;
    cin>>n;
    int cnt=0;
    for (;n>14;n-=7) cnt++;
    if (n==1) cout<<-1;
    if (n==2) cout<<1;
    if (n==3) cout<<7;
    if (n==4) cout<<4;
    if (n==5) cout<<2;
    if (n==6) cout<<6;
    if (n==7) cout<<8;
    if (n==8) cout<<10;
    if (n==9) cout<<18;
    if (n==10) cout<<22;
    if (n==11) cout<<20;
    if (n==12) cout<<28;
    if (n==13) cout<<80;
    if (n==14) cout<<88;
    //human brain > computer & AI
    for (int i=1;i<=cnt;i++) putchar('8');
    cout<<endl;
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    for (cin>>t;t;t--) _main();

    return 0;
}
//orz to nzhtl1477
//rp<<=114514
