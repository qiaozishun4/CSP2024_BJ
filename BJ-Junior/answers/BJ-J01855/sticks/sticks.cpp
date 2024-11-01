#include<bits/stdc++.h>
using namespace std;
long long t, n, s[110] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, o;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>n;
        if(n == 1){
            cout<<"-1"<<endl;
        }else if(n == 2){
            cout<<"1"<<endl;
        }else if(n == 3){
            cout<<"7"<<endl;
        }else if(n == 4){
            cout<<"4"<<endl;
        }else if(n == 5){
            cout<<"2"<<endl;
        }else if(n == 6){
            cout<<"6"<<endl;
        }else if(n == 7){
            cout<<"8"<<endl;
        }else if(n == 8){
            cout<<"10"<<endl;
        }else if(n == 9){
            cout<<"18"<<endl;
        }else if(n == 10){
            cout<<"22"<<endl;
        }else if(n == 11){
            cout<<"20"<<endl;
        }else if(n == 12){
            cout<<"28"<<endl;
        }else if(n == 13){
            cout<<"68"<<endl;
        }else if(n == 14){
            cout<<"88"<<endl;
        }else{
            if(n % 7 == 1){
                cout<<"10";
                n -= 8;
            }else if(n % 7 == 2){
                cout<<"1";
                n -= 2;
            }else if(n % 7 == 3){
                cout<<"200";
                n -= 17;
            }else if(n % 7 == 4){
                cout<<"20";
                n -= 11;
            }else if(n % 7 == 5){
                cout<<"2";
                n -= 5;
            }else if(n % 7 == 6){
                cout<<"6";
                n -= 6;
            }
            for(int j = 1; j <= n / 7; j++){
                cout<<"8";
            }
            cout<<endl;
        }
    }
    return 0;
}
