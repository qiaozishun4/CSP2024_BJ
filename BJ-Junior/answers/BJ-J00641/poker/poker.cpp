#include <iostream>

using namespace std;

bool cnt[4][13];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n,card,ans = 0;
    char a,b;

    cin >> n;

    while(n --)
    {
        cin >> a >> b;

        if(b == 'A') card = 0;
        else if(b == 'T') card = 9;
        else if(b == 'J') card = 10;
        else if(b == 'Q') card = 11;
        else if(b == 'K') card = 12;
        else card = b - '0' - 1;

        if(a == 'D') cnt[0][card] = true;
        else if(a == 'C') cnt[1][card] = true;
        else if(a == 'H') cnt[2][card] = true;
        else if(a == 'S') cnt[3][card] = true;
    }

    for(int i = 0;i < 4;i ++)
        for(int j = 0;j < 13;j ++)
            if(!cnt[i][j])
                ans ++;

    cout << ans;

    return 0;
}
