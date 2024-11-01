#include<bits/stdc++.h>
using namespace std;
int a[200][200];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int h = 52;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if(a[s[0]][s[1]] == true)
        {
            continue;
        }
        a[s[0]][s[1]] = true;
        h--;
    }
    cout << h;
    return 0;
}