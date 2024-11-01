#include<bits/stdc++.h>
using namespace std;
set<char> C;
set<char> D;
set<char> H;
set<char> S;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        char ch=s[1];
        if(s[0]=='C')
            C.insert(ch);
        else if(s[0]=='D')
            D.insert(ch);
        else if(s[0]=='H')
            H.insert(ch);
        else
            S.insert(ch);
    }
    printf("%d",52-(C.size()+D.size()+H.size()+S.size()));
    return 0;
}