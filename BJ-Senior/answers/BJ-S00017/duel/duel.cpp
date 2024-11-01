#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int r[N];

int main(){
        freopen("duel.in", "r", stdin);
        freopen("duel.out", "w", stdout);
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> r[i];
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
                if(r[i] >= r[i + 1]) cnt++;
        }
        cout << cnt;
        fclose(stdin);
        fclose(stdout);
        return 0;
}
