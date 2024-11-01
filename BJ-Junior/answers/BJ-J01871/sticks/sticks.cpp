#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        if(a<2){
            cout << "-1\n";
            continue;
        }
        if(a%7==1){
            a-=8;
            cout << 10;
        }
        if(a%7==2){
            a-=2;
            cout << 1;
        }
        if(a%7==3 && a>=17){
            a-=17;
            cout << 200;
        }
        if(a%7==4 && a>=11){
            a-=11;
            cout << 20;
        }
        if(a%7==5){
            a-=5;
            cout << 2;
        }
        if(a%7==6){
            a-=6;
            cout << 6;
        }
        if(a%7==0){
            for(i=0;i<a/7;i++){
                cout << 8;
            }
            cout << endl;
            continue;
        }
        switch(a){
        case 3:
            cout << 7;
            break;
        case 4:
            cout << 4;
            break;
        case 10:
            cout << 22;
            break;
        }
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}