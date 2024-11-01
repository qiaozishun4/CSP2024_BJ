#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int a[60],n;
char c[2],c1,c2;
int color(char ch){
    int op=0;
    if(ch=='D'){
        op=0;
    }
    if(ch=='C'){
        op=1;
    }
    if(ch=='H'){
        op=2;
    }
    if(ch=='S'){
        op=3;
    }
    return op;
}
int number(char ch){
    int op=0;
    if(ch=='A'){
        op=0;
    }
    else if(ch=='T'){
        op=9;
    }
    else if(ch=='J'){
        op=10;
    }
    else if(ch=='Q'){
        op=11;
    }
    else if(ch=='K'){
        op=12;
    }
    else{
        op=(ch-'0')-1;
    }
    return op;
}
int ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c;
        c1=c[0],c2=c[1];
        //cout<<c1<<" "<<c2;
        int dd=color(c1),ee=number(c2);
        //cout<<dd<<" "<<ee<<endl;
        a[dd*13+ee]=1;
    }
    for(int i=0;i<52;i++){
        //cout<<a[i]<<" ";
        if(a[i]==0){
            ans++;
        }

    }
    cout<<ans<<endl;
    return 0;

}
