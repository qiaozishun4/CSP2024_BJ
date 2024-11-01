#ifndef DETECT_CPP_INCLUDED
#define DETECT_CPP_INCLUDED

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n, a[maxn];
//int na[maxn], num = 1;
deque<int> dq;
int ans = 0;
bool att[maxn];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    memset(att, true, sizeof(att));
    dq.push_front(a[1]);
    for(int i=2;i<=n;i++){
        if(att[i] == true && dq.back()<a[i]){
            dq.pop_back();
            ans++;
            att[i] = false;
        }
        dq.push_front(a[i]);
    }
    cout<<dq.size()<<endl;
    /*while(!dq.empty()){
        cout<<dq.back()<<" ";
        dq.pop_back();
    }*/
    return 0;
}

#endif // DETECT_CPP_INCLUDED
