#include <iostream>
using namespace std;

int D[20], C[20], H[20], S[20];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if(s[0] == 'D')
        {
            if('2' <= s[1] && s[1] <= '9')D[s[1] - '1' + 1]++;
            else if(s[1] == 'A')D[1]++;
            else if(s[1] == 'T')D[10]++;
            else if(s[1] == 'J')D[11]++;
            else if(s[1] == 'Q')D[12]++;
            else if(s[1] == 'K')D[13]++;
        }
        if(s[0] == 'C')
        {
            if('2' <= s[1] && s[1] <= '9')C[s[1] - '1' + 1]++;
            else if(s[1] == 'A')C[1]++;
            else if(s[1] == 'T')C[10]++;
            else if(s[1] == 'J')C[11]++;
            else if(s[1] == 'Q')C[12]++;
            else if(s[1] == 'K')C[13]++;
        }
        if(s[0] == 'H')
        {
            if('2' <= s[1] && s[1] <= '9')H[s[1] - '1' + 1]++;
            else if(s[1] == 'A')H[1]++;
            else if(s[1] == 'T')H[10]++;
            else if(s[1] == 'J')H[11]++;
            else if(s[1] == 'Q')H[12]++;
            else if(s[1] == 'K')H[13]++;
        }
        if(s[0] == 'S')
        {
            if('2' <= s[1] && s[1] <= '9')S[s[1] - '1' + 1]++;
            else if(s[1] == 'A')S[1]++;
            else if(s[1] == 'T')S[10]++;
            else if(s[1] == 'J')S[11]++;
            else if(s[1] == 'Q')S[12]++;
            else if(s[1] == 'K')S[13]++;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= 13; i++)
    {
        if(D[i] == 0)cnt++;
        if(C[i] == 0)cnt++;
        if(H[i] == 0)cnt++;
        if(S[i] == 0)cnt++;
    }
    cout << cnt << endl;
    return 0;
}
