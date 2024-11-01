#include<bits/stdc++.h>
using namespace std;

string has_got[105];
long long n;


int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    long long j=0;
    for(long long i=1; i<=n; i++){
        string now;
        cin >> now;
        bool flag=true;
        for(int k=1; k<=j; k++){
            if(has_got[k] == now) flag = false;
        }
        if(flag)
            has_got[++j] = now;
    }
    long long ans = 52 - j;
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
