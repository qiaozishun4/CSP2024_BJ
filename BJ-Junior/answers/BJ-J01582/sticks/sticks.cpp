#include<bits/stdc++.h>
using namespace std;
int hb(int n){
    if(n==0){
        return 6;
    }
    if(n==1){
        return 2;
    }
    if(n==2){
        return 5;
    }
    if(n==3){
        return 5;
    }
    if(n==4){
        return 4;
    }
    if(n==5){
        return 5;
    }
    if(n==6){
        return 6;
    }
    if(n==7){
        return 3;
    }
    if(n==8){
        return 7;
    }
    if(n==9){
        return 6;
    }
    return 0;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n%2!=0&&n%3!=0&&n%4!=0&&n%5!=0&&n%6!=0&&n%7!=0){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 1;;i++){
            int sb=i;
            int c=0;
            while(sb){
                c+=hb(sb%10);
                sb/=10;
            }
            if(c==n){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}