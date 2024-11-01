#include <bits/stdc++.h>
using namespace std;
bool a[10][20];
int huase(char x)
{
    if(x=='D') return 1;
    if(x=='C') return 2;
    if(x=='H') return 3;
    if(x=='S') return 4;
}
int shuzi(char x)
{
    if(x=='A') return 1;
    if(x=='2') return 2;
    if(x=='3') return 3;
    if(x=='4') return 4;
    if(x=='5') return 5;
    if(x=='6') return 6;
    if(x=='7') return 7;
    if(x=='8') return 8;
    if(x=='9') return 9;
    if(x=='T') return 10;
    if(x=='J') return 11;
    if(x=='Q') return 12;
    if(x=='K') return 13;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    while(n--)
    {
        cin>>s;
        a[huase(s[0])][shuzi(s[1])]=1;
    }

    int cnt=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(!a[i][j]) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
