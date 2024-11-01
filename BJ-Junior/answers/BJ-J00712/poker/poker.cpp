#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n=0,ans=0;
    string a[10000];
    cin>>n;
    map<string,int> cont;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(cont[a[i]]>=1){
            continue;
        }
        else{
            ans++;
            cont[a[i]]=1;
        }
    }
    int b=52-ans;
    cout<<b;
    fclose(stdin);
    fclose(stdout);
}