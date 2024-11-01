#include<bits/stdc++.h>
using namespace std;
int pw[100000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int a=0;
    int max = 0;
    int min = 0;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>pw[i];
    }

    for(int k = 0;k<n;k++){
        if(max<pw[k]){
            max=pw[k];
        }
        }
        min = max;
    for(int k = 0;k<n;k++){
        if(min>pw[k]){
            min=pw[k];
        }
        }
    if(max==min){
            cout<<n;
        }
    if(max!=min){
            cout<<1;
        }
    return 0;
    }
