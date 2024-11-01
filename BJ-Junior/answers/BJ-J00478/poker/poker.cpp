#include<bits/stdc++.h>
using namespace std;
long long n,sum,r = 0;
string s,a[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> s;
        bool f = true;
        for(long long j = 1;j <= r;j++){
            if(a[j] == s){
                f = false;
                break;
            }
        }
        if(f){
            a[++r] = s;
            sum++;
        }
    }
    cout << 52-sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}