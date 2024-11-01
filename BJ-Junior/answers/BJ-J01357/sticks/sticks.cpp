#include <bits/stdc++.h>

using namespace std;
const string mp[22] = {"","-1","1","7","4","2","6","8","10","18","22","20","28","68","88","108","188","200","208","288","688"};

int t,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n <= 20)
        {
            cout << mp[n] << '\n';
            continue;
        }

        int cnt = 0;
        while(n > 20)
        {
            n -= 7;
            cnt++;
        }

        cout << mp[n];
        for(int i = 1;i <= cnt;i++)
            cout << 8;
        cout << '\n';
    }

    return 0;
}

/*
35
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
Output:
-1
1
7
4
2
6
8
10
18
22
20
28
68
88
108
188
200
208
288
688
888
1088
1888
2008
2088
2888
6888
8888
10888
18888
20088
20888
28888
68888
88888
*/