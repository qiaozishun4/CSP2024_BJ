#include<bits/stdc++.h>
using namespace std;
string iput[10005],oput[10005];
int atn[20];
int fgr(int x)
{
    return int(ceil((x*1.0)/7.0));
}
string f(int x)
{
    for(int i=9;i<=x;i++)
    {
        int group=fgr(i);
        int use=2;
        while(i-use>(7*(group-1)))
        {
            use=use+atn[(oput[use][0]-'0')];
        }
        oput[i]=oput[use]+iput[i-use];
        iput[i]=oput[i];
        if(oput[i][0]=='6') iput[i][0]='0';
    }
    return oput[x];
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T ;
    cin>>T;
    iput[1]="-1";
    iput[2]="1";
    iput[3]="7";
    iput[4]="4";
    iput[5]="2";
    iput[6]="0";
    iput[7]="8";
    oput[1]="-1";
    oput[2]="1";
    oput[3]="7";
    oput[4]="4";
    oput[5]="2";
    oput[6]="6";
    oput[7]="8";
    atn[1]=3;
    atn[2]=-1;
    atn[4]=2;
    atn[6]=-3;
    atn[7]=4;
    int s=9;//last time
    while(T--)
    {
        int n;
        cin>>n;
        if(n<=7)
        {
            cout<<oput[n]<<endl;
            continue;
        }
        else{
            cout<<f(n)<<endl;
        }
    }
    return 0;
}