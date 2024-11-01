#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n, t;
    cin >> t;
    bool flag = false;
    for(int j = 1;j <= t;j++)
    {
        cin >> n;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        for(int i = 1;i <= 1e9;i++)
        {
            int temp = i, sum = 0, idx = 0;
            string s;
            while(temp != 0)
            {
                s[idx++] += (temp % 10 + 48);
                temp /= 10;
            }
            for(int j = 0;j <= idx;j++)
            {
                if(s[j] == '0') sum += 6;
                if(s[j] == '1') sum += 2;
                if(s[j] == '2') sum += 5;
                if(s[j] == '3') sum += 5;
                if(s[j] == '4') sum += 4;
                if(s[j] == '5') sum += 5;
                if(s[j] == '6') sum += 6;
                if(s[j] == '7') sum += 3;
                if(s[j] == '8') sum += 7;
                if(s[j] == '9') sum += 6;
            }
            if(sum == n)
            {
                cout << i <<endl;
                flag = true;
                break;
            }

        }
        if(!flag) cout << -1 << endl;
        flag = false;
    }
    return 0;
}

