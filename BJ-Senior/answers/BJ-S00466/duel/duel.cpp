#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long int n,a;
    cin>>n;
    long long int anser = n;
    vector <long long int> v(n+1,0);
    vector <long long int> dx(n+1,0);
    vector <long long int> px(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i]>v[j]){
                dx[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        a=dx[i];
        for(int j=0;j<n;j++){
            if(px[a]!=0){
                a++;
            }
            else{
                px[a]=v[i];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(px[i]>px[j]){
                anser--;
                break;
            }
        }
    }
    cout<<anser;
    return 0;
}