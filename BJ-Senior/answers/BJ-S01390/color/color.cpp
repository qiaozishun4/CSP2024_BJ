#include<bits/stdc++.h>
using namespace std;
int s[105];
int n;
int check(int now,int flag,int last0,int last1){
    if(now > n) return 0;
    long long ans = 0;
    if(flag){
        if(s[now] == s[last1]) ans += s[now];
    }
    else{
        if(s[now] == s[last0]) ans += s[now];
    }
    if(flag)return ans + max(check(now + 1,flag,last0,now),check(now + 1,!flag,last0,now));
    else return ans + max(check(now + 1,flag,now,last1),check(now + 1,!flag,now,last1));
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> s[i];
        }
        cout << check(1,0,0,0) << endl;
    }
    return 0;
}
