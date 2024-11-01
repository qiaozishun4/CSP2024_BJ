#include<bits/stdc++.h>
using namespace std;
int q(int o){
    if(o == 2)return 1;
    if(o == 3)return 7;
    if(o == 4)return 4;
    if(o == 5)return 2;
    if(o == 6)return 0;
    if(o == 7)return 8;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    if(n < 2){
        cout<<-1;
        return 0;
    }
    if(n==2||n==3||n==4){
        cout<<q(n);
        return 0;
    }
    if(n == 6){
        cout<<6;
        return 0;
    }
    for(int i = 2;i < n;i++){
        if(n == 0){
            return 0;
        }
        if(n-i!=0&&n-i<=7){
            n-=i;
            cout<<q(i);
        }
    }
    return 0;
}
