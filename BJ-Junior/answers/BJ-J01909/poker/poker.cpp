#include<iostream>
#include<cstdio>
using namespace std;
int vis[60]={};
int f(string s){
    char c;
    int a=0;
    c=s[0];
    if(c=='C'){
        a=13;
    }
    if(c=='H'){
        a=26;
    }
    if(c=='S'){
        a=39;
    }
    c=s[1];
    if(c=='A'){
        a+=1;
    }
    if(c=='T'){
        a+=10;
    }
    if(c=='J'){
        a+=11;
    }
    if(c=='Q'){
        a+=12;
    }
    if(c=='K'){
        a+=13;
    }
    else{
        a+=c-48;
    }
    return a;
}
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
    int n,c=52;
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        if(!vis[f(a)]){
            vis[f(a)]=1;
            c--;
        }
    }
    cout<<c;
    return 0;
}
