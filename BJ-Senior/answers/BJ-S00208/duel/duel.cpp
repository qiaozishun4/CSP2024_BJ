#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int r[1000005];
queue<int> wt;
stack<int> atk;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> r[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(r[i]>r[j]) swap(r[i],r[j]);
        }
    }
    wt.push(r[0]);
    for(int i=1;i<n;i++){
        int now=wt.front();
        if(r[i]>now){
            wt.pop();
        }
        wt.push(r[i]);
    }
    cout << wt.size();
    return 0;
}
