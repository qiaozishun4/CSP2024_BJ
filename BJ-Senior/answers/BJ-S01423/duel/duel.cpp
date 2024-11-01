#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int r[N],box0[N],box[N],sumj,sum,maxr = -1;
queue<int> q;
vector<int> v;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cur = 0;
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> r[i];
        box[r[i]]++;
     }
    sort(box + 1,box + 100006);
    int ans = 0;
    for (int i = 1;i <= 100005;i++){
        if (box[i] > 0){
            q.push(box[i]);
        }
    }
    while (!q.empty()){
        int x = q.front() - sumj;
        if (x <= 0) q.pop();
        else{
            sumj += x;
            ans += x;
            q.pop();
        }
    }
    cout << ans;
    return 0;
}