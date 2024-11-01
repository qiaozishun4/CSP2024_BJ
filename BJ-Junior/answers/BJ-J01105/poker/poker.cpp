#include <iostream>
#include <cstdio>
using namespace std;
int n,s[14],h[14],d[14],c[14];
void so()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    return;
}
void sc()
{
    fclose(stdin);
    fclose(stdout);
    return;
}
void init()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        string poker;
        cin >> poker;
        char f = poker[0],k = poker[1];
        if(f == 'S')
        {
            if(k >= '0' && k <= '9')
                s[k-'0']++;
            if(k == 'T')
                s[10]++;
            if(k == 'J')
                s[11]++;
            if(k == 'Q')
                s[12]++;
            if(k == 'K')
                s[13]++;
            if(k == 'A')
                s[14]++;
        }
        else if(f == 'H')
        {
            if(k >= '0' && k <= '9')
                h[k-'0']++;
            if(k == 'T')
                h[10]++;
            if(k == 'J')
                h[11]++;
            if(k == 'Q')
                h[12]++;
            if(k == 'K')
                h[13]++;
            if(k == 'A')
                h[14]++;
        }
        else if(f == 'D')
        {
            if(k >= '0' && k <= '9')
                d[k-'0']++;
            if(k == 'T')
                d[10]++;
            if(k == 'J')
                d[11]++;
            if(k == 'Q')
                d[12]++;
            if(k == 'K')
                d[13]++;
            if(k == 'A')
                d[14]++;
        }
        else if(f == 'C')
        {
            if(k >= '0' && k <= '9')
                c[k-'0']++;
            if(k == 'T')
                c[10]++;
            if(k == 'J')
                c[11]++;
            if(k == 'Q')
                c[12]++;
            if(k == 'K')
                c[13]++;
            if(k == 'A')
                c[14]++;
        }
    }
    return;
}
void calc_out()
{
    int cs = 0,ch = 0,cd = 0,cc = 0;
    for(int i = 1; i <= 14; i++)
    {
        if(s[i])
        {
            cs++;
        }
    }
    for(int i = 1; i <= 14; i++)
    {
        if(h[i])
        {
            ch++;
        }
    }
    for(int i = 1; i <= 14; i++)
    {
        if(d[i])
        {
            cd++;
        }
    }
    for(int i = 1; i <= 14; i++)
    {
        if(c[i])
        {
            cc++;
        }
    }
    int sum = cs+ch+cd+cc;
    cout << 52 - sum;
    return;
}


int main()
{
    so();
    init();
    calc_out();
    sc();
    return 0;
}
