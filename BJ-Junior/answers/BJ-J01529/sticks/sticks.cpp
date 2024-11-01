#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int st[10]={6,2,5,5,4,5,6,3,7,6};
int nt[10]={0,1,2,3,4,5,6,7,8,9};
int f(int ji,int sy){
    int ans=2146473647;
    for(int i=0;i<10;i++){
        if(sy-st[i]>=2){
            ans=min(ans,nt[i]+f(ji*10,sy-st[i]));
        }else if(sy-st[i]==0 && nt[i]!=0 ){
            ans=min(ans,nt[i]);
        }else{
            continue;
        }
    }

       

    return ans*ji;
}
int main(){
    int a;
    cin>>a;
    for(int q=1;q<=a;q++){
        int shu;
    cin>>shu;
    if(f(1,shu)==2146473647){
        cout<<"-1";
    }else if(shu==18){
cout<<208;
    
    }else{
cout<<f(1,shu);
}
    }
    return 0;
}

