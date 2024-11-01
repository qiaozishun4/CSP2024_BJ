#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n;
    cin>>n;
    int m[100005];
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    sort(m,m+n);
    queue<int> alive;
    alive.push(m[0]);
    for(int i=1;i<n;i++){
        if(m[i]>alive.front()){
            alive.pop();
        }
        alive.push(m[i]);

    }
    cout<<alive.size();
    return 0;
}
