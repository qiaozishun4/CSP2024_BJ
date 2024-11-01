#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int na=52-n;
    string shuru[60];
    for(int i=0;i<n;i++){
        cin>>shuru[i];
        for(int j=0;j<i;j++){
            if(shuru[i]==shuru[j]){
                na++;
            }
        }
    }
    if(na<0){
        na=0;
    }
    cout<<na;
    return 0;
}
