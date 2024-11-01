#include<bits/stdc++.h>
using namespace std;
int a[] = {6,2,5,5,4,5,6,3,7,6};
int foo(int n){
    if(n == 2) return 1;
    if(n == 3) return 7;
    if(n == 4) return 4;
    if(n == 5) return 2;
    if(n == 6) return 6;
    if(n == 9) return 18;
    if(n == 10) return 23;
    if(n == 11) return 20;
    if(n == 12) return 28;
    if(n == 13) return 80;
    if(n == 16) return 188;
    if(n == 17) return 408;
    if(n == 18) return 488;
    if(n == 19) return 608;
    if(n == 20) return 688;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n == 1){
            cout<<-1;
        }else if(n % 7 == 0){
            for(int i = 1;i <= n / 7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n % 7 == 1){
            cout<<10;
            n -= 8;
            for(int i = 1;i <= n / 7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n <= 50){

        }else{
            cout<<-1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
