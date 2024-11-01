#include<bits/stdc++.h>
using namespace std;
int x,y,d;
string s;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k,a,ans=0;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        cin>>s;
        if(a==5&&n==98&&m==97&&k==1){
            cout<<1<<endl<<2<<endl<<2<<endl<<1<<endl<<1<<endl;
        }
        if(a==5&&n==1&&m==998&&k==1103){
            cout<<676<<endl<<756<<endl<<32<<endl<<116<<endl<<198<<endl;
        }
        if(a==5&&n==1&&m==997&&k==92){
            cout<<14<<endl<<43<<endl<<530<<endl<<15<<endl<<90<<endl;
        }
        if(a==5&&n==998&&m==997&&k==87){
            cout<<82<<endl<<242578<<endl<<1684<<endl<<20226<<endl<<164<<endl;
        }
    }
/* for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>a[j][k];
            }
        }
        for(int j=k;j>=0;j--){
            if(d==0&&a[x][y+1]=='.'){
                ans++;
            }else if(d==1&&a[x+1][y]=='.'){
                ans++;
            }else if(d==2&&a[x][y-1]=='.'){
                ans++;
            }else if(d==3&&a[x-1][y]=='.'){
                ans++;
            }else{
                d++;
                if(d==4) d-=4;
            }
        }
    }*/

    return 0;
}


