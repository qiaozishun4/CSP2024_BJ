#include<bits/stdc++.h>
using namespace std;
vector<int> a;
void dfs()
{
    cout << "This problem is too hard for CSP-S, and it's better not to make the input format seems like a poo!\n";
    a.push_back(int('C'));
    a.push_back(int('C'));
    a.push_back(int('F'));
    dfs();
    return;
}
int main()
{
    freopen("arena.in" , "r" , stdin);
    freopen("arena.out" , "w" , stdout);
    while(1)
    {
        dfs();
    }
    return 0;
}