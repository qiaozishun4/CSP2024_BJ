#include <iostream>
using namespace std;

bool d[14],c[14],s[14],h[14];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt = 0;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        string st;
        cin >> st;
        if(st[0] == 'D')
        {
            if(st[1] == 'A')
                d[1] = 1;
            if(st[1] == '2')
                d[2] = 1;
            if(st[1] == '3')
                d[3] = 1;
            if(st[1] == '4')
                d[4] = 1;
            if(st[1] == '5')
                d[5] = 1;
            if(st[1] == '6')
                d[6] = 1;
            if(st[1] == '7')
                d[7] = 1;
            if(st[1] == '8')
                d[8] = 1;
            if(st[1] == '9')
                d[9] = 1;
            if(st[1] == 'T')
                d[10] = 1;
            if(st[1] == 'J')
                d[11] = 1;
            if(st[1] == 'Q')
                d[12] = 1;
            if(st[1] == 'K')
                d[13] = 1;
        }
        if(st[0] == 'C')
        {
            if(st[1] == 'A')
                c[1] = 1;
            if(st[1] == '2')
                c[2] = 1;
            if(st[1] == '3')
                c[3] = 1;
            if(st[1] == '4')
                c[4] = 1;
            if(st[1] == '5')
                c[5] = 1;
            if(st[1] == '6')
                c[6] = 1;
            if(st[1] == '7')
                c[7] = 1;
            if(st[1] == '8')
                c[8] = 1;
            if(st[1] == '9')
                c[9] = 1;
            if(st[1] == 'T')
                c[10] = 1;
            if(st[1] == 'J')
                c[11] = 1;
            if(st[1] == 'Q')
                c[12] = 1;
            if(st[1] == 'K')
                c[13] = 1;
        }
        if(st[0] == 'H')
        {
            if(st[1] == 'A')
                h[1] = 1;
            if(st[1] == '2')
                h[2] = 1;
            if(st[1] == '3')
                h[3] = 1;
            if(st[1] == '4')
                h[4] = 1;
            if(st[1] == '5')
                h[5] = 1;
            if(st[1] == '6')
                h[6] = 1;
            if(st[1] == '7')
                h[7] = 1;
            if(st[1] == '8')
                h[8] = 1;
            if(st[1] == '9')
                h[9] = 1;
            if(st[1] == 'T')
                h[10] = 1;
            if(st[1] == 'J')
                h[11] = 1;
            if(st[1] == 'Q')
                h[12] = 1;
            if(st[1] == 'K')
                h[13] = 1;
        }
        if(st[0] == 'S')
        {
            if(st[1] == 'A')
                s[1] = 1;
            if(st[1] == '2')
                s[2] = 1;
            if(st[1] == '3')
                s[3] = 1;
            if(st[1] == '4')
                s[4] = 1;
            if(st[1] == '5')
                s[5] = 1;
            if(st[1] == '6')
                s[6] = 1;
            if(st[1] == '7')
                s[7] = 1;
            if(st[1] == '8')
                s[8] = 1;
            if(st[1] == '9')
                s[9] = 1;
            if(st[1] == 'T')
                s[10] = 1;
            if(st[1] == 'J')
                s[11] = 1;
            if(st[1] == 'Q')
                s[12] = 1;
            if(st[1] == 'K')
                s[13] = 1;
        }
    }
    for(int i = 1;i<=13;i++)
    {
        if(!d[i])
            cnt++;
        if(!c[i])
            cnt++;
        if(!h[i])
            cnt++;
        if(!s[i])
            cnt++;
    }
    cout << cnt;
    return 0;
}
