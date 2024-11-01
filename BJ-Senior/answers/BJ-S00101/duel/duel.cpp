#include<iostream>
#include<algorithm>
using namespace std;
int hashing[100010];

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);


    int n;
    int temp;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> temp;
        hashing[temp]++;
    }
    int maxval = 0;
    for(int i=1; i<=100000;i++){
        maxval = max(maxval, hashing[i]);
    }

    cout << maxval;
    return 0;
}
