#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
//               0  1  2  3  4  5  6  7  8  9
int stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string pi[7] = {"", "10", "1", "200", "20", "2", "6"};
int ps[7] = {0, 1, 0, 2, 1, 0, 0};
string best[maxn], bestn[maxn];
bool visited[100010];
bool bigger(string a, string b)
{
    if(a.size() > b.size()) return true;
    else if(a.size() < b.size()) return false;
    else return a > b;
}
string dfs(int i, int oi)
{
    if(visited[i])
    {
        return best[i];
    }
    else if(i >= 8)
    {
        string ans = "", ansn = "";
        for(int j = 0;j < 10;j++)
        {
            string a = "0"; a[0] = char(j + '0');
            a += dfs(i - stick[j], oi);
            if(ans == "" || bigger(ans, a))
            {
                ans = a;
            }
            if((ansn == "" || bigger(ansn, a)) && !(i == oi && a[0] == '0')) ansn = a;
        }
        best[i] = ans;
        bestn[i] = ansn;
        visited[i] = true;
        return ans;
    }
    else {return best[i];}
}
void init()
{
    for(int i = 0;i <= 70;i++)
    {
        dfs(i, i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("sticks.in", ios::in);
    ofstream fout("sticks.out", ios::out);
    fin.tie(0); fout.tie(0);
    int t;
    fin >> t;
    best[0] = "99999999999999999999999"; bestn[0] = "9999999999999999999999";
    best[1] = "99999999999999999999999"; bestn[1] = "9999999999999999999999";
    best[2] = "1"; bestn[2] = "1";
    best[3] = "7"; bestn[3] = "7";
    best[4] = "4"; bestn[4] = "4";
    best[5] = "2"; bestn[5] = "2";
    best[6] = "0"; bestn[6] = "6";
    best[7] = "8"; bestn[7] = "8";
    init();
    while(t--)
    {
        int n;
        fin >> n;
        if(n >= 2)
        {
            if(n >= 70)
            {
                string ans = pi[n % 7];
                for(int j = 0;j < (n / 7) - ps[n % 7];j++)
                {
                    ans += "8";
                }
                fout << ans << endl;
            }
            else fout << bestn[n] << endl;
        }
        else fout << "-1" << endl;
    }
    return 0;
}
