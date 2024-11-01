#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[100005];
queue<int> que;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ans = n;
    for(int i=1;i<=n;i++){
        que.push(a[i]);
    }
    int i = 1;
    while(!que.empty() && i<=n){
        if(que.front()<a[i]){
            //cout << i << " " << que.front() << endl;
            que.pop();
            ans--;
        }
        i++;
    }
    cout << ans;
    return 0;
}
