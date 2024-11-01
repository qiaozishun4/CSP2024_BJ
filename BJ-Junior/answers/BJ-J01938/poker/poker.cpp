#include <bits/stdc++.h>
using namespace std;

int n,cnt;
int D[15],C[15],H[15],S[15];

int char_num(char x)
{
    if(x == 'A') return 1;
    else if(x == '2') return 2;
    else if(x == '3') return 3;
    else if(x == '4') return 4;
    else if(x == '5') return 5;
    else if(x == '6') return 6;
    else if(x == '7') return 7;
    else if(x == '8') return 8;
    else if(x == '9') return 9;
    else if(x == 'T') return 10;
    else if(x == 'J') return 11;
    else if(x == 'Q') return 12;
    else if(x == 'K') return 13;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        string s;
        cin >> s;
        int pos = char_num(s[1]);
        if(s[0] == 'D') D[pos]++;
        else if(s[0] == 'C') C[pos]++;
        else if(s[0] == 'H') H[pos]++;
        else if(s[0] == 'S') S[pos]++;
    }
    for(int i = 1 ; i <= 13 ; i++)
    {
        if(D[i] == 0) cnt++;
        if(C[i] == 0) cnt++;
        if(H[i] == 0) cnt++;
        if(S[i] == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}