#include <bits/stdc++.h>
using namespace std;
set <string> sa;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    while(n--){
        string a;
        cin >> a;
        sa.insert(a);
    }
    int ans = 0;
    for(int i = 0;i < sa.size();i++)
        ans++;
    cout << 52-ans;


    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
