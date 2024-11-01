
#include<bits/stdc++.h>
using namespace std;
int n;
string tmp;
map<string, char> vis;
string poker_letter[5] =  {"D", "C", "H", "S"};
string poker_number[15] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(vis[tmp] == false) cnt++;
        vis[tmp] = true;
    }
    cout << 52 - cnt;
}
