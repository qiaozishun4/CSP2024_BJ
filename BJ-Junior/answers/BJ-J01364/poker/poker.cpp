#include<bits/stdc++.h>
using namespace std;

int n, ans = 0;
int d[60], c[60], h[60], s[60]; // every 13 * 4

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin>>n;
    for (int i=0;i<n;i++){
        char ta, tb;
        cin>>ta>>tb;
        int idx;
        if (tb == 'A') idx = 1;
        else if (tb == 'T') idx = 10;
        else if (tb == 'J') idx = 11;
        else if (tb == 'Q') idx = 12;
        else if (tb == 'K') idx = 13;
        else idx = tb - '0';
        if (ta == 'D'){
            d[idx] = 1;
        } else if (ta == 'C'){
            c[idx] = 1;
        } else if (ta == 'H'){
            h[idx] = 1;
        } else if (ta == 'S'){
            s[idx] = 1;
        }
    }
    for (int i=1;i<=13;i++){
        if (d[i] == 0) ans++;
        if (c[i] == 0) ans++;
        if (h[i] == 0) ans++;
        if (s[i] == 0) ans++;
    }
    cout<<ans<<endl;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
