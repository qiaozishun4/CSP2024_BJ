#include <bits/stdc++.h>
using namespace std;
int T, n;
string s;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        s = "";
        scanf("%d", &n);
        switch (n % 7)
        {
            case 0:
                for (int i = 1; i <= n / 7; i++) s += '8';
                break;
            case 1:
                s += "10";
                for (int i = 1; i <= n / 7 - 1; i++) s += '8';
                break;
            case 2:
                s += '1';
                for (int i = 1; i <= n / 7; i++) s += '8';
                break;
            case 3:
                if (n == 3) s = "7";
                else if (n == 10) s = "22";
                else
                {
                    s += "200";
                    for (int i = 1; i <= n / 7 - 2; i++) s += '8';
                }
                break;
            case 4:
                if (n == 4) s = "4";
                else
                {
                    s += "20";
                    for (int i = 1; i <= n / 7 - 1; i++) s += '8';
                }
                break;
            case 5:
                s += '2';
                for (int i = 1; i <= n / 7; i++) s += '8';
                break;
            case 6:
                s += '6';
                for (int i = 1; i <= n / 7; i++) s += '8';
                break;
        }
        if (n <= 1) s = "-1";
        cout << s << endl;
    }
    return 0;
}
/*
2 3 4 5 6    7
1 7 4 2 6(0) 8

n = 7k    ? (n > 0) 8888888888888
n % 7 = 1 ? (n > 1) 1088888888888
got 8 = 3 + 5 = 4 + 4 = 2 + 6
        7 , 2   4 , 4   1, 6(0)
        27 72   44      10 16 61
        min = 10
n % 7 = 2 ? (n = 2) 1
            (n > 2) 1888888888888
got 9 = 4 + 5 = 3 + 6 = 2 + 7
        4 , 2   7 , 6(0) 1 , 8
        24 42   70 07 76 67 18 81
        min = 18
n % 7 = 3 ? (n = 3) 7
            (n = 10) 22
            (n > 10) 2008888888888
got 10 = 5 + 5 = 4 + 6 = 3 + 7
         2 , 2   4 , 6(0) 7 , 8
         22     40 04 64 46 78 87
         min = 22
         PAI found PROBLEMATHERE
    10 = 2 + 6 + 6
        2, 6(0), 6(0)
        200 smaller than 228
        min = 200
n % 7 = 4 ? (n = 4) 4
            (n > 4) 2088888888888
got 11 = 5 + 6 = 4 + 7
         2 , 6(0) 4 , 8
         20 26 02 06 48 84
         min = 20
n % 7 = 5 ? (n = 5) 2
            (n > 5) 2888888888888
got 12 = 6 + 6 = 5 + 7
        6(0) , 6(0) 2 , 8
        00 06 60 66 28 82
        min = 28
n % 7 = 6 ? (n = 6) 6
            (n > 6) 6888888888888
got 13 = 6 + 7
        6(0) , 8
        68 86 08 80
        min = 68


n % 7 = 0 ? (n > 0) 8888888888888
n % 7 = 1 ? (n > 1) 1088888888888
n % 7 = 2 ? (n = 2) 1
            (n > 2) 1888888888888
n % 7 = 3 ? (n = 3) 7
            (n > 3) 2008888888888
n % 7 = 4 ? (n = 4) 4
            (n > 4) 2088888888888
n % 7 = 5 ? (n = 5) 2
            (n > 5) 2888888888888
n % 7 = 6 ? (n = 6) 6
            (n > 6) 6888888888888
*/
