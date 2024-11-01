#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int t, n;
int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

//如果加了这个数， minlen成功-1了， 说明这个数可以加

void solve7(){
    for(int i=1; i<=n/7; i++) printf("8");
    printf("\n");
}

void solve7_1(){
    printf("10");
    for(int i=2; i<=n/7; i++) printf("8");
    printf("\n");
}

int minlen(int x){
    if(x%7 == 0) return x/7;
    else return x/7+1;
}

void solvea(){
    bool firsttime = true;
    while(n>7){
        for(int i=0; i<=9; i++){
            if(firsttime && i==0) continue;
            if(minlen(n-arr[i]) < minlen(n)){
                cout<<i;
                n-=arr[i];
                break;
            }
        }
        firsttime = false;
    }
    if(n==7) cout<<8<<endl;
    if(n==6) cout<<0<<endl;
    if(n==5) cout<<2<<endl;
    if(n==4) cout<<4<<endl;
    if(n==3) cout<<7<<endl;
    if(n==2) cout<<1<<endl;
}

int main(){

    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1) cout<<-1<<endl;
        else if(n==6) cout<<6<<endl;
        else if(n%7 == 0){
            solve7();
        }
        else if(n%7 == 1){;
            solve7_1();
        }
        else{
            solvea();
        }

    }

    return 0;
}
