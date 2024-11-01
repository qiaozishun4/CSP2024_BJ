#include<bits/stdc++.h>
using namespace std;
int a[20]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x<=7){
            cout<<a[x];
        }else{
            cout<<a[x%7+7];
            x/=7;
            x--;
            for(int i=1;i<=x;i++) cout<<8;
        }cout<<endl;
    }
    return 0;
}
