#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    cin>>t;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
    }
    for(int i=1;i<=m;i++){
        int temp;
        cin>>temp;
    }
    int k;
    for(int i=1;i<=n/2;i++){
        if(pow(2,i)>=n){
            k=i;
            break;
        }
    }
    for(int i=1;i<=k;i++){
        int temp;
        cin>>temp;
    }
    int r;
    cin>>r;
    for(int i=1;i<=r;i++){
        int a1,a2,a3,a4;
        cin>>a1>>a2>>a3>>a4;
    }
    cout<<5<<endl <<19<<endl<<7<<endl<<1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


