#include<bits/stdc++.h>
using namespace std;
bool flag[6][17];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(flag,false,sizeof(flag));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int nee=52;
    while(t--)
    {
        string s;
        cin>>s;
        int x,y;
        if(s[0]=='D') x=0;
        else if(s[0]=='C') x=1;
        else if(s[0]=='H') x=2;
        else x=3;
        if(s[1]=='A') y=0;
        else if(s[1]=='2') y=1;
        else if(s[1]=='3') y=2;
        else if(s[1]=='4') y=3;
        else if(s[1]=='5') y=4;
        else if(s[1]=='6') y=5;
        else if(s[1]=='7') y=6;
        else if(s[1]=='8') y=7;
        else if(s[1]=='9') y=8;
        else if(s[1]=='T') y=9;
        else if(s[1]=='J') y=10;
        else if(s[1]=='Q') y=11;
        else y=12;
        if(flag[x][y]==false)
        {
            flag[x][y]=true;
            nee--;
        }
    }
    cout<<nee<<endl;
    return 0;
}