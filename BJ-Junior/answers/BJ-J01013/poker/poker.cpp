#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
    int a,s=52,d=0;
    string q[100];
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>q[i];
        d=0;
        for(int j=1;j<i;j++){
            if(q[j]==q[i]){
                d=1;
            }
        }
        if(d==0){
            s--;
        }
    }
    cout<<s;
    return 0;
}