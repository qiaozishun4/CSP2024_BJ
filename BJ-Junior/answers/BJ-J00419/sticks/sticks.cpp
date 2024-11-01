#include <bits/stdc++.h>
using namespace std;
const int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int minn = 1e9;
int Find(int n)
{
    for(int i=0; i<10; i++)
        if(num[i] == n)
            return i;
    return -1;
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int x;
        cin >> x;
        if(x%7 == 1)
        {
            cout << -1 << endl;
            for(int i=1; i<=x/7; i++) cout << 8;
            continue;
        } else if(x%7 == 0) {
            for(int i=1; i<=x/7; i++) cout << 8;
            continue;
        }
        int MinLen = ceil(x / 7.0);
        if(MinLen == 1)
        {
            if(!Find(x))
            {
                cout << 6 << endl;
                continue;
            } else {
                cout << Find(x) << endl;
                continue;
            }
        }
        int FirstNum = x - (MinLen-1)*7;
        int SecondNum = 7;
        while(FirstNum <= SecondNum && Find(FirstNum) == -1 && Find(SecondNum) == -1)
            FirstNum++, SecondNum--;
        cout << Find(FirstNum+1) << Find(SecondNum);
        for(int i=2; i<MinLen; i++) cout << 8;
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}