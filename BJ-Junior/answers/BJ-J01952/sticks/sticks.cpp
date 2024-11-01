#include<bits/stdc++.h>
using namespace std;
long long zhuan (int a){
    if (a==0 || a==6 || a==9){
        return 6;
    }
    if (a==1){
        return 2;
    }
    if (a==2 || a==3 || a==5){
        return 5;
    }
    if (a==4){
        return 4;
    }
    if (a==7){
        return 3;
    }
    if (a==8){
        return 7;
    }
}
long long chai (int a){
    int sum=0;
    while (a){
        sum+=zhuan(a%10);
        a/=10;
    }
    return sum;
}
int main(){
    freopen ("sticks.in","r",stdin);
    freopen ("sticks.out","w",stdout);
    int a,b;
    cin>>a;
    for (int i=1;i<=a;i++){
        cin>>b;
        if (b==1) {
            cout<<-1;
            continue;
        }
        else if (b<=50){
            if (b==50) cout<<10888888;
            for (int i=1;i<=8888888;i++){
                if (chai(i)==b) {
                    cout<<i;
                    break;
                }
            }
            cout<<endl;
        }
        else {
            b/=7;
            for (int i=1;i<=b;i++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
