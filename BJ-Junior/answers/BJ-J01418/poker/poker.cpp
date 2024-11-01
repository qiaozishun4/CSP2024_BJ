#include <bits/stdc++.h>
using namespace std;
int a[100][100],cnt;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        if(a[s[0]][s[1]]==0) cnt++;
        a[s[0]][s[1]]++;
    }
    cout << 52-cnt;
    return 0;
}
