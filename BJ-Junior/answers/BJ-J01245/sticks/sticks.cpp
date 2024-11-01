#include<bits/stdc++.h>
using namespace std;

int nfs[10] = {6,2,5,5,4,5,6,3,7,6};
int t,n;

bool check(int h){
    int u = h;
    int ans = 0;
    while(u){
        ans+=nfs[u%10];
        u/=10;
    }
    return (ans == n);
}

void finds(int x){ // "er fen" has been wrong
    long long int i = 1,end_ = pow(10,x/2); //6 second for 100000*50
    for(;i<=end_;i++){
        if(check(i)){
            cout<<i<<endl;
            return ;
        }
    }
    cout<<-1<<endl;
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        finds(n);
    }

    return 0;
}
