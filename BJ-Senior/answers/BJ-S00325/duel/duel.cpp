#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int> > done,pending;
    for(int i = 1;i<=n;i++) {
        int a;
        cin>>a;
        pending.push(a);
    }
    done.push(pending.top());
    pending.pop();
    while(!pending.empty()) {
        if(done.top() < pending.top()) {
            done.pop();
            done.push(pending.top());
            pending.pop();
        }
        else {
            done.push(pending.top());
            pending.pop();
        }
    }
    cout << done.size()<<endl;
    return 0;
}
