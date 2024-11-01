#include<bits/stdc++.h>
using namespace std;
int n,ans = 52;
bool pokerD[14];
bool pokerC[14];
bool pokerH[14];
bool pokerS[14];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        string poker;
        cin >> poker;
        if(poker[0] == 'D')
        {
            if(poker[1] == 'A') pokerD[1] = 1;
            if(poker[1] == '2') pokerD[2] = 1;
            if(poker[1] == '3') pokerD[3] = 1;
            if(poker[1] == '4') pokerD[4] = 1;
            if(poker[1] == '5') pokerD[5] = 1;
            if(poker[1] == '6') pokerD[6] = 1;
            if(poker[1] == '7') pokerD[7] = 1;
            if(poker[1] == '8') pokerD[8] = 1;
            if(poker[1] == '9') pokerD[9] = 1;
            if(poker[1] == 'T') pokerD[10] = 1;
            if(poker[1] == 'J') pokerD[11] = 1;
            if(poker[1] == 'Q') pokerD[12] = 1;
            if(poker[1] == 'K') pokerD[13] = 1;
        }
        if(poker[0] == 'C')
        {
            if(poker[1] == 'A') pokerC[1] = 1;
            if(poker[1] == '2') pokerC[2] = 1;
            if(poker[1] == '3') pokerC[3] = 1;
            if(poker[1] == '4') pokerC[4] = 1;
            if(poker[1] == '5') pokerC[5] = 1;
            if(poker[1] == '6') pokerC[6] = 1;
            if(poker[1] == '7') pokerC[7] = 1;
            if(poker[1] == '8') pokerC[8] = 1;
            if(poker[1] == '9') pokerC[9] = 1;
            if(poker[1] == 'T') pokerC[10] = 1;
            if(poker[1] == 'J') pokerC[11] = 1;
            if(poker[1] == 'Q') pokerC[12] = 1;
            if(poker[1] == 'K') pokerC[13] = 1;
        }
        if(poker[0] == 'H')
        {
            if(poker[1] == 'A') pokerH[1] = 1;
            if(poker[1] == '2') pokerH[2] = 1;
            if(poker[1] == '3') pokerH[3] = 1;
            if(poker[1] == '4') pokerH[4] = 1;
            if(poker[1] == '5') pokerH[5] = 1;
            if(poker[1] == '6') pokerH[6] = 1;
            if(poker[1] == '7') pokerH[7] = 1;
            if(poker[1] == '8') pokerH[8] = 1;
            if(poker[1] == '9') pokerH[9] = 1;
            if(poker[1] == 'T') pokerH[10] = 1;
            if(poker[1] == 'J') pokerH[11] = 1;
            if(poker[1] == 'Q') pokerH[12] = 1;
            if(poker[1] == 'K') pokerH[13] = 1;
        }
        if(poker[0] == 'S')
        {
            if(poker[1] == 'A') pokerS[1] = 1;
            if(poker[1] == '2') pokerS[2] = 1;
            if(poker[1] == '3') pokerS[3] = 1;
            if(poker[1] == '4') pokerS[4] = 1;
            if(poker[1] == '5') pokerS[5] = 1;
            if(poker[1] == '6') pokerS[6] = 1;
            if(poker[1] == '7') pokerS[7] = 1;
            if(poker[1] == '8') pokerS[8] = 1;
            if(poker[1] == '9') pokerS[9] = 1;
            if(poker[1] == 'T') pokerS[10] = 1;
            if(poker[1] == 'J') pokerS[11] = 1;
            if(poker[1] == 'Q') pokerS[12] = 1;
            if(poker[1] == 'K') pokerS[13] = 1;
        }
    }

    for (i = 1; i <= 13; i++)
        if(pokerD[i]) ans--;
    for (i = 1; i <= 13; i++)
        if(pokerC[i]) ans--;
    for (i = 1; i <= 13; i++)
        if(pokerH[i]) ans--;
    for (i = 1; i <= 13; i++)
        if(pokerS[i]) ans--;

    cout << ans;
    return 0;
}
