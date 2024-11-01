#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    bool d[15];
    bool c[15];
    bool h[15];
    bool s[15];
    for(int i = 0;i < 15;i++)
    {
         d[i] = c[i] = h[i] = s[i] = false;
    }
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        char a,b;
        cin>>a>>b;
        int num;
        if(b == 'A')
        {
            num = 1;
        }
        else if(b == 'T')
        {
            num = 10;
        }
        else if(b == 'J')
        {
            num = 11;
        }
        else if(b == 'Q')
        {
            num = 12;
        }
        else if(b == 'K')
        {
            num = 13;
        }
        else if(b == '2')
        {
            num = 2;
        }
        else if(b == '3')
        {
            num = 3;
        }
        else if(b == '4')
        {
            num = 4;
        }
        else if(b == '5')
        {
            num = 5;
        }
        else if(b == '6')
        {
            num = 6;
        }
        else if(b == '7')
        {
            num = 7;
        }
        else if(b == '8')
        {
            num = 8;
        }
        else
        {
            num = 9;
        }
        if(a == 'D')
        {
            d[num] = true;
        }
        else if(a == 'C')
        {
            c[num] = true;
        }
        else if(a == 'H')
        {
            h[num] = true;
        }
        else
        {
            s[num] = true;
        }
    }
    if(n == 1)
    {
        cout<<1<<endl;
        return 0;
    }
    int ans = 0;
    for(int i = 1;i <= 13;i++)
    {
        if(d[i] == false)
        {
            ans++;
        }
        if(c[i] == false)
        {
            ans++;
        }
        if(h[i] == false)
        {
            ans++;
        }
        if(s[i] == false)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}