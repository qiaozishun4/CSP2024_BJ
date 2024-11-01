#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int r[100001];
    for(int i = 0;i < n;i++){
        cin >> r[i];
    }
    sort(r, r + n);
    long long sum = 0;
    long long ssum[100001] = {0};
    long t = 0;
    long num = 0;
    for(int i = 0;i < n;i++){
        if(r[i] == r[t]){
            if(t != 0 && num > 0){
                ssum[t - 1]--;
                num--;
                continue;
            }
            ssum[t]++;
            num++;
        }
        else{
            t++;
        }
    }
    for(int i = 0;i < n;i++){
        sum += ssum[i];
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
