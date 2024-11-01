#include <bits/stdc++.h>>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m,a[100010],c[100010],t;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
    }
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<a[i]*c[i]-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
return 0;}
