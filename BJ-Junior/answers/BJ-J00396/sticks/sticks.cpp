#include<bits/stdc++.h>
using namespace std;
int t,h;\
int shu[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
cin>>t;
while(t--){
    int n=0;
    cin>>n;
    if(n<2){
        cout<<-1<<endl;
    }
    h=n/7;
    for(int i=1;i<=h;i++){
        cout<<8;
    }
    for(int i=0;i<=n%7;i++){
        if(i==shu[i]){
            cout<<i;
        }
    }
    cout<<endl;
}
return 0;
}
