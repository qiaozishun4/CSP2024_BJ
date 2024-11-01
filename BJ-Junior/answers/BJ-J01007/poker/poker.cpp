#include<bits/stdc++.h>
using namespace std;
int a[10][25];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        int pt, c;
        switch(s[0])
        {
            case 'S':
            {
                c = 1;
                break;
            }
            case 'H':
            {
                c = 2;
                break;
            }
            case 'C':
            {
                c = 3;
                break;
            }
            default:
            {
                c = 4;
                break;
            }
        }
        if(s[1] == 'T')
        {
            pt = 10;
        }
        else if(s[1] == 'J')
        {
            pt = 11;
        }
        else if(s[1] == 'Q')
        {
            pt = 12;
        }
        else if(s[1] == 'K')
        {
            pt = 13;
        }
        else if(s[1] == 'A')
        {
            pt = 1;
        }
        else pt = (s[1] - '0');
        if(a[c][pt] == 0)
        {
            cnt++;
            a[c][pt] = 1;
        }
    }
    printf("%d\n", 52 - cnt);
    return 0;
}
