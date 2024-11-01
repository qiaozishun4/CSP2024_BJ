#include<bits/stdc++.h>
using namespace std;
int nnn[] = {0,1,2,3,4,5,6,7,8,9};
int sss[] = {6,2,5,5,4,5,6,3,7,6};
int f(int x){
    int c = 0;
    while(x){
        int t = x % 10;
        for(int i = 0;i < 7;i += 1){
            if(nnn[i] == t){
                c += sss[i];
                break;
            }
        }
        x /= 10;
    }
    return c;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n == 1){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 1;i < n;i += 1){
            int t = f(i);
            if(t == n){
                cout<<t<<endl;
                break;
            }
        }
    }
    return 0;
}
