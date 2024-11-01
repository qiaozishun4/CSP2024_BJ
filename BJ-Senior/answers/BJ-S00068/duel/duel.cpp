#include<bits/stdc++.h>
using namespace std;
int n;
int x[100005];
int main(){
freopen("dule.in","r",stdin);
freopen("dule.out","w",stdout);
    cin>>n;
    int y=n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(x[j]<x[i]){
                x[j]=x[j]+x[i];
                x[i]=x[j]-x[i];
                x[j]=x[j]-x[i];
            }
        }
    }
for(int i=n;i>0;i--){
            if(x[i-1]>x[i]){
                y--;
            }
}
cout<<y;
return 0;
}
