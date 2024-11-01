#include<bits/stdc++.h>
using namespace std;
string pok;
char pans[60][10];
int ansch[10][20];
int n,ans=52;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int shu,huase;
        cin>>pok;
        pans[i][1]=pok[0];
        pans[i][2]=pok[1];
        if(pans[i][2]=='A') shu=1;
        else if(pans[i][2]=='T') shu=10;
        else if(pans[i][2]=='J') shu=11;
        else if(pans[i][2]=='Q') shu=12;
        else if(pans[i][2]=='K') shu=13;
        else shu=pans[i][2]-'0';
        if(pans[i][1]=='D') huase=1;
        else if(pans[i][1]=='C') huase=2;
        else if(pans[i][1]=='H') huase=3;
        else if(pans[i][1]=='S') huase=4;
        if(ansch[huase][shu]==0)
        {
            ans--;
            ansch[huase][shu]=1;
        }
    }
    cout<<ans;
    return 0;
}
