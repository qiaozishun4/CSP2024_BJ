#include<bits/stdc++.h>
using namespace std;
int wow(int k){
    if(k==1){
        return 7;
    }
    return 7+wow(k-1)*10;
}
int wow2(int k){
    if(k==1){
        return 10;
    }
    return 7+wow2(k-1)*10;
}
int d,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d;
        int k=d/7;
        int f=d%7;
        if(f==0){
            cout<<wow(k)<<endl;
        }else{
            cout<<wow2(k)<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
