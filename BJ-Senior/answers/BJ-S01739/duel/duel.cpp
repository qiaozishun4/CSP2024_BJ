#include <bits/stdc++.h>
using namespace std;

priority_queue <int,vector<int>,greater<int>> qat, qde;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int p;
        cin >> p;
        qat.push(p);
        qde.push(p);
    }
    while(!qat.empty()){
        int p = qat.top();
        qat.pop();
        int q = qde.top();
        if(p>q){
            qde.pop();
        }
        else{
            continue;
        }
    }
    cout << qde.size();
    return 0;
}