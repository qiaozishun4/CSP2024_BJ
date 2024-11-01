#include<bits/stdc++.h>
using namespace std;
int a[60] = {0};
int toNum(string s)
{
    int ans = 0;
    if(s[0] == 'D') ans += 0;
    if(s[0] == 'C') ans += 13;
    if(s[0] == 'S') ans += 26;
    if(s[0] == 'H') ans += 39;
    if(s[1] >= '1' && s[1] <= '9') ans += (s[1] - '0') - 1;
    if(s[1] == 'T') ans += 9;
    if(s[1] == 'J') ans += 10;
    if(s[1] == 'Q') ans += 11;
    if(s[1] == 'K') ans += 12;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("poker.in", ios::in);
    ofstream fout("poker.out", ios::out);
    fin.tie(0); fout.tie(0);
    int n;
    fin >> n;
    for(int i = 0;i < n;i++)
    {
        string s;
        fin >> s;
        a[toNum(s)]++;
    }
    int sum = 0;
    for(int i = 0;i < 52;i++)
    {
        if(a[i] == 0) sum++;
    }
    fout << sum << endl;
    return 0;
}
