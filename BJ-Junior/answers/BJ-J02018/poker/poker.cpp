#include<bits/stdc++.h>
using namespace std;
int b[14][5];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        string k;
        cin>>k;
        int g='k[0]';
        if(k[0]=='T'&&k[1]=='D')
        {
            b[10][1]++;

        }
        else if(k[0]=='T'&&k[1]=='C')
        {
            b[10][2]++;

        }
        else if(k[0]=='T'&&k[1]=='H')
        {
            b[10][3]++;

        }
        else if(k[0]=='T'&&k[1]=='S')
        {
            b[10][4]++;

        }
        else if(k[0]=='J'&&k[1]=='D')
        {
            b[11][1]++;

        }
        else if(k[0]=='J'&&k[1]=='C')
        {
            b[11][2]++;

        }
        else if(k[0]=='J'&&k[1]=='H')
        {
            b[11][3]++;

        }
        else if(k[0]=='J'&&k[1]=='S')
        {
            b[11][4]++;

        }

        else if(k[0]=='Q'&&k[1]=='D')
        {
            b[12][1]++;

        }
        else if(k[0]=='Q'&&k[1]=='C')
        {
            b[12][2]++;

        }
        else if(k[0]=='Q'&&k[1]=='H')
        {
            b[12][3]++;

        }
        else if(k[0]=='Q'&&k[1]=='S')
        {
            b[12][4]++;

        }
        else if(k[0]=='K'&&k[1]=='D')
        {
            b[13][1]++;

        }
        else if(k[0]=='K'&&k[1]=='C')
        {
            b[13][2]++;

        }
        else if(k[0]=='K'&&k[1]=='H')
        {
            b[13][3]++;

        }
        else if(k[0]=='K'&&k[1]=='S')
        {
            b[13][4]++;

        }
        else if(k[0]=='A'&&k[1]=='D')
        {
            b[1][1]++;

        }
        else if(k[0]=='A'&&k[1]=='C')
        {
            b[1][2]++;

        }
        else if(k[0]=='A'&&k[1]=='H')
        {
            b[1][3]++;

        }
        else if(k[0]=='A'&&k[1]=='S')
        {
            b[1][4]++;

        }
        else if(k[1]=='S')
        {
            b[g][1]++;


        }
        else if(k[1]=='D')
        {
            b[g][2]++;


        }
        else if(k[1]=='C')
        {
            b[g][3]++;


        }
        else if(k[1]=='H')
        {
            b[g][4]++;


        }


    }
    int ans=0;
    for(int i=1;i<14;i++)
    {
        for(int j=1;i<5;j++)
        {
            if(b[i][j]!=0)
                ans++;

        }
    }
    cout<<52-ans;
    return 0;
}
