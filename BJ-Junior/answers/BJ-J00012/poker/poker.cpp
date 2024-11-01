#include<bits/stdc++.h>
using namespace std;

set<string> s;

int main(){
        freopen("poker.in", "w", stdin);
        freopen("poker.out", "r", stdout);
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
                string ss;
                cin >> ss;
                s.insert(ss);
        }
        int t = s.size();
        cout << 52 - t;
        fclose(stdin);
        fclose(stdout);
        return 0;
}

