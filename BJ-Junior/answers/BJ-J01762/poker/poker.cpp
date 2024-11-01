#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[124];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> s[i];
    int res = unique(s,s + n) - s;
    cout << 52 - res;
    return 0;
}
