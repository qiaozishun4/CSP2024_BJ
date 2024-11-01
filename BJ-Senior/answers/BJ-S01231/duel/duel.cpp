#include <bits/stdc++.h>
using namespace std;
long long n;
int monster[100005];
queue <int> m;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 0;i<n;i++){
        scanf("%d",&monster[i]);
    }
    sort(monster,monster+n);
    m.push(monster[0]);
    for(int i = 1;i<n;i++){
        m.push(monster[i]);
        if(monster[i] > m.front()){
            m.pop();
        }
    }
    cout<<m.size();
    return 0;
}
