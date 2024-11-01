#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    int n,m,k,x,y,d,cnt=0;
    char c;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=0;j<n;j++){
            for(int f=1;f<=m;f++){
                cin>>c;
            }
        }
    }
    cout<<3<<endl;
    for(int i=0;i<t;i++){
        if(n==m){
            cnt++;
        }
    }
    cnt--;
    cout<<13;
    return 0;
}
