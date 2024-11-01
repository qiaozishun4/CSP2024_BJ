#ifndef STICKS_CPP_INCLUDED
#define STICKS_CPP_INCLUDED

#include<bits/stdc++.h>
using namespace std;
int n, T;
int sticks[10] = {6,2,5,5,4,5,6,3,7,6};
int trans(int m){
    int x = 7;
    int cnt = 0;
    while(m > 0){
        if(m >= x){
            cnt++;
            m -= x;
        }
        else x--;
    }
    return cnt;
}
int ans[15001];
bool f = 0;
void s(int n){
    int cnt = trans(n);
    int m = n;
    for(int i=1;i<=cnt;i++){
        bool flag = 0;
        for(int j=9;j>=0;j--){
            if(m < sticks[j]) continue;
            if(j == 0){
                if(i != 1){
                    int tmp = (m-sticks[j])/7;
                    if((m-sticks[j])%7 != 0) tmp++;
                    if(tmp <= cnt-i){
                        flag = 1;
                        ans[i] = j;
                    }
                }
            }
            else{
                int tmp = (m-sticks[j])/7;
                if((m-sticks[j])%7 != 0) tmp++;
                if(tmp <= cnt-i){
                    flag = 1;
                    ans[i] = j;
                }
            }
        }
        if(flag == 0){
            f = 1;
            return;
        }
        else m -= sticks[ans[i]];
    }
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>T;
    while(T--){
        f = 0;
        memset(ans, 0, sizeof(ans));
        cin>>n;
        //cout<<trans(n)<<endl;
        s(n);
        if(f == 1) cout<<-1<<endl;
        else{
            for(int i=1;i<=trans(n);i++) cout<<ans[i];
            cout<<endl;
        }
    }
    return 0;
}

#endif // STICKS_CPP_INCLUDED
