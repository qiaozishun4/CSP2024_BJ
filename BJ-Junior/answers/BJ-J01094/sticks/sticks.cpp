#include<bits/stdc++.h>
using namespace std;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int t = n / 7;
        int t2 = n % 7;
        if(t == 0 && t2 <= 1)
        {
            cout << -1 << endl;
            continue;
        }
        if(t2 >= 2){
            switch(t2)
            {
                case 2:
                    cout << 1;
                    break;
                case 3:
                    cout << 7;
                    break;
                case 4:
                    cout << 4;
                    break;
                case 5:
                    cout << 2;
                    break;
                case 6:
                    cout << 6;
                    break;
            }
        }
        for(int i = 1; i <= t; i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}
