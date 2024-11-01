#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int st[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, ans;
void dfs(int step, int num, int n) {
    if(n==0) {
        ans=min(ans, num);
        return;
    }
    if(num>=ans) {
        return;
    }
    int start=0;
    if(step==1) {
        start=1;
    }
    for(int i = start;i<10;i++) {
        if(n>=st[i]) {
            dfs(step+1, num*10+i, n-st[i]);
        }
    }
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin>>t;
    while(t--) {
        ans=numeric_limits<int>::max();
        int n;
        cin>>n;
        /*
        if(n<2) {
            cout<<-1<<endl;
        }
        if(n%7==0) {
            while(n) {
                cout<<8;
                n-=7;
            }
        } else if(n%7==1) {
            cout<<1;
            n--;
            while(n) {
                cout<<6;
                n-=6;
            }
        }
        cout<<endl;
        */
        dfs(1, 0, n);
        if(n<2) {
            ans=-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}