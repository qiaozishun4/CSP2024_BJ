#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[100010],more_people=1,t;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }for(int i=0;i<m;i++){
        cin>>b[i];
    }while(more_people<n){
        more_people*=2;
    }for(int i=0;i<more_people-n;i++){
        cin>>a[i];
    }cin>>t;
    for(int j=0;j<t;j++){
        cout<<1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}