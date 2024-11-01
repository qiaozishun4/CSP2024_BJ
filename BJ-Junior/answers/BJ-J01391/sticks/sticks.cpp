#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        int cnt=(n+6)/7;
        for(int i=1;i<=cnt;i++){
            int id=0,low=n-(cnt-i)*7,high=n-(cnt-i)*2;
            if(i==1){
                id=1;
            }
            while(id<=9&&(a[id]<low||a[id]>high)){
                id++;
            }
            cout<<id;
            n-=a[id];
        }
        cout<<endl;
    }
    return 0;
}
