#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt;
long long sum;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    cout << sum << endl;
    for(int i = 0;i < n;i++){
        if(a[i] > sum){
            cnt += 1;
        }
    }
    cout << n - cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
