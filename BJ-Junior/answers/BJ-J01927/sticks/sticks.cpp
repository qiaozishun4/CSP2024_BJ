#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n,t;

void Main(){

    cin>>n;
    if(n%7==0){
        for(int i=1;i<=n%7;++i){
            cout<<8;
        }
        cout<<endl;
    }

    if(n==2){
        cout<<1<<endl;
    }
    if(n=3){
        cout<<7<<endl;
    }

    else{
        cout<<-1<<endl;
    }

}

int main(){

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin>>t;
    while(t--){
        Main();
    }

    return 0;
}
