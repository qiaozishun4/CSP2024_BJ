#include<iostream>
#include<map>
using namespace std;
struct bint{
    string n;
    bint operator +=(int a){
        n.push_back(a+48);
        return {n};
    }
    bool operator >(bint a){
        if(n.length()>a.n.length()){
            return 1;
        }
        else if(n.length()<a.n.length()){
            return 0;
        }
        else{
            for(int i=0;i<n.length();i++){
                if(n[i]>a.n[i]){
                    return 1;
                }
            }
            return 0;
        }
    }
};
bint smax(){
    string a;
    for(int i=0;i<99999;i++){
        a.push_back('9');
    }
    return {a};
}
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int u=a/7;
        int minu=999999,minv=999999;
        if(a==1){
            cout<<-1<<endl;
            continue;
        }
        for(int j=0;j<=u;j++){
            int v=a-7*j;
            v/=6;
            if(v+j<minv+minu){
                minv=v;
                minu=j;
            }
        }
        int y=a-minv*6-minu*7;
        if(y==1||y==0){
            minv--;
            y+=6;
        }
        if(y==2){
            cout<<1;
        }
        if(y==3){
            cout<<7;
        }
        if(y==4){
            cout<<4;
        }
        if(y==5){
            cout<<2;
        }
        if(y==6){
            cout<<6;
        }
        if(y==7){
            cout<<8;
        }
        for(int j=0;j<minv;j++){
            cout<<0;
        }
        for(int j=0;j<minu;j++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}

