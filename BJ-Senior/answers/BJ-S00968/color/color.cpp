#include <bits/stdc++.h>

using namespace std;
int t,a[200100][200100];
int alll[200100];
map<int,int> mp;
int ct(int x,int ajmd){
    int tmp = 0;
    for(int k = 1;k <= x;k++){
        if(a[ajmd][k] == x) tmp++;
    }
    return tmp;
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    for(int i = 1;i <= t;i++){
        cin >> alll[i];
        for(int j = 1;j <= alll[i];j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= t;i++){
        for(int j = 1;j <= alll[i];j++){
            int tmp = 0;
            mp[a[i][j]] = ct(a[i][j],i);
        }
    }
    for(auto it = mp.begin();it != mp.end();it++){
        cout << it->first * (it->second-1) << "\n;
    }
    return 0;
}
