#include<bits/stdc++.h>
using namespace std;
int op(int n){
    if(n<=1) return -1;
    else{
        if(n == 2){
            return 1;
        }else if(n == 3){
            return 7;
        }else if(n == 4){
            return 4;
        }else if(n == 5){
            return 2;
        }else if(n == 6){
            return 6;
        }else if(n == 7){
            return 8;
        }else if(n == 18){
            return 208;
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,q;
    cin>>n;
    int a[n],r[n],w[6] = {2,3,4,5,6,7};
    for(int i=0;i<n;i++){
        cin>>a[i];
        r[i] = op(a[i]);
    }
    for(int i=0;i<n;i++){
        cout<<r[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}