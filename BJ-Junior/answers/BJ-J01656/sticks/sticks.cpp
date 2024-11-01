#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int s[15]={0,0,1,7,4,2,6,0,10,18,22,20};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int cnt=0;
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }else if(n%7==0){
            for(int i=0;i<n/7;i++)cout<<8;
            continue;
        }else if((n-1)%7==0){
            cout<<16;
            for(int i=0;i<(n-8)/7;i++)cout<<8;
            continue;
        }
        while(n>11){
            n-=7;
            cnt++;
        }
        cout<<s[n];
        for(int i=0;i<cnt;i++)cout<<8;
        cout<<endl;
    }
    return 0;
}
