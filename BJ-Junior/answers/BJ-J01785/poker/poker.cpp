#include <bits/stdc++.h>
using namespace std;

bool box[60];

int main()
{
    freopen("poker.in" , "r" , stdin);
    freopen("poker.out" , "w" , stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        char a , b;
        cin >> a >> b;
        int temp = 0;
        if(a == 'D') temp = 0;
        else if(a == 'C') temp = 13;
        else if(a == 'H') temp = 26;
        else temp = 39;

        if ('2' <= b && b <= '9') temp = temp + (b - '0');
        else if (b == 'A') temp++;
        else if (b == 'T') temp += 10;
        else if (b == 'J') temp += 11;
        else if (b == 'Q') temp += 12;
        else temp += 13;
        box[temp] = true;
    }

    int ans = 0;
    for (int i = 1;i <= 52;i++)
        if(!box[i]) ans++;
//    for (int i = 1;i <= 52;i++) cout << box[i] << " ";
    cout << ans << endl;
    return 0;
}