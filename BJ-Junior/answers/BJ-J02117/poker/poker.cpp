#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[114];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int t = s[0] == 'D' ? 0 : s[0] == 'C' ? 13 : s[0] == 'H' ? 26 : 39;//D1C2H3S4
        if(isdigit(s[1]))
        {
            vis[(int)(t + (s[1] - '0'))] = 1;
        }
        else if(s[1] == 'A') vis[t + 1] = 1;
        else if(s[1] == 'T') vis[t + 10] = 1;
        else if(s[1] == 'J') vis[t + 11] = 1;
        else if(s[1] == 'Q') vis[t + 12] = 1;
        else if(s[1] == 'K') vis[t + 13] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= 52; i++) cnt += vis[i];
    cout << 52 - cnt << endl;
    return 0;
}

/*
9必定在中间

有：
    a_5
a_1 9   a_4
a_3 a_2

此时 已证明 外圈大小交错排列时取最大
    且 外圈性旋转时不影响总和 （称此条为外圈可旋转性）
故不妨令 a_3 > a_1, a_2
则 对于a_3: |a_3 - a_1| + |a_3 - a_2| 为a_3对总和的贡献
   而对于9： |9 - a_1| + |9 - a_2| + |9 - a_5| + |9 - a_4|
因为9 > a_3
故9的贡献的前两项必大于a_3的贡献
而9的后两项必大于零
故9在中间时贡献比在外圈时大
此时令与9差的绝对值最大的数排布在9四周；由于外圈可旋转性，这种做法不会改变外圈的和
有：
5 4 6
1 9 2
8 3 7
此为最大排列的一种。
*/