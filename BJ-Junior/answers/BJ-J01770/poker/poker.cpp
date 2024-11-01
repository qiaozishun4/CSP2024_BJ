#include<bits/stdc++.h>
using namespace std;
const int MAXN=55;
int n;
map<string, bool> mp;
string ch(int num)
{

    if(num==1) return "A";
    if(num==2) return "2";
    if(num==3) return "3";
    if(num==4) return "4";
    if(num==5) return "5";
    if(num==6) return "6";
    if(num==7) return "7";
    if(num==8) return "8";
    if(num==9) return "9";
    if(num==10) return "T";
    if(num==11) return "J";
    if(num==12) return "Q";
    if(num==13) return "K";
}
string check(int num)
{
    if(num==1) return "D";
    if(num==2) return "C";
    if(num==3) return "H";
    if(num==4) return "S";
}
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        mp[s]=1;
    }
    long long ans=0;
    for(int i=1; i<=13; i++)
    {
        string num=ch(i);
        for(int j=1; j<=4; j++)
        {
            string hs=check(j);
            hs+=num;
            if(mp[hs]==0) ans++;
        }
    }
    printf("%lld", ans);
    return 0;
}
