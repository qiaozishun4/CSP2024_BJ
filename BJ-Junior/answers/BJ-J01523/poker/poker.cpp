#include<bits/stdc++.h>
using namespace std;
#define fio(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

int n,cnt;
bool c[9][18];

int main()
{
    fio("poker");
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ainpt,binpt;
        int a,b;
        cin>>ainpt>>binpt;
        switch(ainpt)
        {
            case 'D':a=1;break;
            case 'C':a=2;break;
            case 'H':a=3;break;
            case 'S':a=4;
        }
        switch(binpt)
        {
            case 'A':b=1;break;
            case 'T':b=10;break;
            case 'J':b=11;break;
            case 'Q':b=12;break;
            case 'K':b=13;break;
            default:b=binpt-'0';
        }
        if(!c[a][b]) c[a][b]=true,cnt++;
    }
    cout<<max(52-cnt,0);
}