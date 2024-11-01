#include<bits/stdc++.h>
using namespace std;
bool b[20][20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    string s;
    char fir,sco;
    while(n--)
    {
        cin >> s;
        fir=s[0],sco=s[1];
        if(fir=='D')
        {
            if(sco=='A') b[0][0]=1;
            else if(sco=='2') b[0][1]=1;
            else if(sco=='3') b[0][2]=1;
            else if(sco=='4') b[0][3]=1;
            else if(sco=='5') b[0][4]=1;
            else if(sco=='6') b[0][5]=1;
            else if(sco=='7') b[0][6]=1;
            else if(sco=='8') b[0][7]=1;
            else if(sco=='9') b[0][8]=1;
            else if(sco=='T') b[0][9]=1;
            else if(sco=='J') b[0][10]=1;
            else if(sco=='Q') b[0][11]=1;
            else if(sco=='K') b[0][12]=1;
        }
        else if(fir=='C')
        {
            if(sco=='A') b[1][0]=1;
            else if(sco=='2') b[1][1]=1;
            else if(sco=='3') b[1][2]=1;
            else if(sco=='4') b[1][3]=1;
            else if(sco=='5') b[1][4]=1;
            else if(sco=='6') b[1][5]=1;
            else if(sco=='7') b[1][6]=1;
            else if(sco=='8') b[1][7]=1;
            else if(sco=='9') b[1][8]=1;
            else if(sco=='T') b[1][9]=1;
            else if(sco=='J') b[1][10]=1;
            else if(sco=='Q') b[1][11]=1;
            else if(sco=='K') b[1][12]=1;
        }
        else if(fir=='H')
        {
            if(sco=='A') b[2][0]=1;
            else if(sco=='2') b[2][1]=1;
            else if(sco=='3') b[2][2]=1;
            else if(sco=='4') b[2][3]=1;
            else if(sco=='5') b[2][4]=1;
            else if(sco=='6') b[2][5]=1;
            else if(sco=='7') b[2][6]=1;
            else if(sco=='8') b[2][7]=1;
            else if(sco=='9') b[2][8]=1;
            else if(sco=='T') b[2][9]=1;
            else if(sco=='J') b[2][10]=1;
            else if(sco=='Q') b[2][11]=1;
            else if(sco=='K') b[2][12]=1;
        }
        else if(fir=='S')
        {
            if(sco=='A') b[3][0]=1;
            else if(sco=='2') b[3][1]=1;
            else if(sco=='3') b[3][2]=1;
            else if(sco=='4') b[3][3]=1;
            else if(sco=='5') b[3][4]=1;
            else if(sco=='6') b[3][5]=1;
            else if(sco=='7') b[3][6]=1;
            else if(sco=='8') b[3][7]=1;
            else if(sco=='9') b[3][8]=1;
            else if(sco=='T') b[3][9]=1;
            else if(sco=='J') b[3][10]=1;
            else if(sco=='Q') b[3][11]=1;
            else if(sco=='K') b[3][12]=1;
        }
    }
    int ans=52;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(b[i][j]) ans--;
        }
    }
    cout <<ans <<endl;
    return 0;
}
