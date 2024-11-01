#include<bits/stdc++.h>
using namespace std;
int n,c;
cin>>n;
int a[n],b[n];
void head(){
    for(int i=c;i<n;i++){
        if(b[i]==max(b[])){
            for(int j=0;i<n;i++){
                b[j]=0;
            }
            for(int y=0;y<n;i++){
                kill(c+1,a[y]);
            }
        }
    }
    c+1;
}
void kill(int i,int j){
    if(i<=j){
        return 0;
    }else{
        a[j]=0;
        return 1;
    }
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b[i]=kill(a[0],a[i]);
    }
    c+1;
    for(int i=1;i<n;i++){
        head();
    }
    cout>>max(b[]);
    return 0;
}
