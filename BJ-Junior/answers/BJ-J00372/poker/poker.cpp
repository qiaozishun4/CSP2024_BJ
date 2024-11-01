#include<bits/stdc++.h>
using namespace std;
bool d[505];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        string s;
        cin>>s;
        char a=s[0],b=s[1];
        int q=0;
        if(a=='D') q++;
        if(a=='C') q+=2;
        if(a=='H') q+=3;
        if(a=='S') q+=4;
        q*=100;
        if(isdigit(b)) q+=int(b-'0');
        if(b=='T') q+=10;
        if(b=='J') q+=11;
        if(b=='Q') q+=12;
        if(b=='K') q+=13;
        if(b=='A') q+=1;
        d[q]=true;

    }
    int cnt=0;
    for(int i = 101; i<=413; i++)
    {
        if(i/100<=4&&i/100>=1&&i%100<=13&&i%100>=1)
        {
            if(!d[i]) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
