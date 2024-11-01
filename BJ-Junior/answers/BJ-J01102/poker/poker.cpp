#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in" , "r" , stdin);
    freopen("poker.out" , "w" , stdout);
    int pokers[4][13];
    string a;
    int b[2], n, ans=0;
    for(int i=0; i<4; ++i)
        for(int j=0; j<13; ++j)
            pokers[i][j] = 0;
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> a;
        //D C H S
        if(a[0] == 'D') b[0] = 0;
        else if(a[0] == 'C') b[0] = 1;
        else if(a[0] == 'H') b[0] = 2;
        else if(a[0] == 'S') b[0] = 3;
        //A 2 3 4 5 6 7 8 9 T J Q K
        if(a[1] == 'A') b[1] = 0;
        else if(a[1] == '2') b[1] = 1;
        else if(a[1] == '3') b[1] = 2;
        else if(a[1] == '4') b[1] = 3;
        else if(a[1] == '5') b[1] = 4;
        else if(a[1] == '6') b[1] = 5;
        else if(a[1] == '7') b[1] = 6;
        else if(a[1] == '8') b[1] = 7;
        else if(a[1] == '9') b[1] = 8;
        else if(a[1] == 'T') b[1] = 9;
        else if(a[1] == 'J') b[1] = 10;
        else if(a[1] == 'Q') b[1] = 11;
        else if(a[1] == 'K') b[1] = 12;
        //count pokers
        pokers[b[0]][b[1]] = 1;
    }
    for(int i=0; i<4; ++i)
        for(int j=0; j<13; ++j)
            if(pokers[i][j] == 0)
                ans++;
    cout << ans;
    return 0;
}
