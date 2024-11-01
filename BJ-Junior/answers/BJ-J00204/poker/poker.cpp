#include <algorithm>
#include <iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    vector<string> s;
    for (int i = 1; i <= n; i++){
        string a;
        cin >> a;
        s.push_back(a);
    }
    sort(s.begin(),s.end());
    int x = 0;
    for (int i = 1; i < n; i++){
       if(s[i]!=s[x]){
            x++;
       }
        s[x] = s[i];
    }
    cout << 52-x-1;
    return 0;
}
