#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    vector<int> v;
    int n,a[100005]={0},p[100005]={0},b[100005]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(find(v.begin(),v.end(),a[i])==v.end()){
            v.push_back(a[i]);
        }
        p[a[i]]++;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++){
        if(p[v[i]]<=p[v[i+1]]){
            n-=p[v[i]];
            p[v[i]]=0;
        }
        else{
            n-=p[v[i+1]];
            p[v[i+1]]=p[v[i]];
        }
    }
    cout<<n;
}
