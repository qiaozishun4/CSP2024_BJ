#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100010];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i]>arr[ans]){
            ans++;
        }
    }
    cout<<n-ans;
}