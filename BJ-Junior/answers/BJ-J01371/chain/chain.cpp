#include<iostream>
using namespace std;
int a[1005][2005],x[1005],ch[1005],ch1[1005],ch2[1005];
int r,c,n,k,ans;

void dfs(int y,int cur,int flag){
    if(y>r){
        if(flag==c){
            ans=1;
            
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(i==cur) continue;
        for(int j=2;j<=min(x[i],k);j++){
            for(int l=1;l<=x[i]-j+1;l++){
                if(a[i][l]!=flag) continue;
                ch[y]=i;
                ch1[y]=l;
                ch2[y]=l+j-1;
                dfs(y+1,i,a[i][l+j-1]);
            }
        }
    }
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            for(int j=1;j<=x[i];j++){
                cin>>a[i][j];
            }
        }
        while(q--){
            cin>>r>>c;
            if(r==1){
                bool flag=0;
                for(int i=1;i<=n;i++){
                    for(int j=2;j<=min(k,x[i]);j++){
                        for(int l=1;l<=x[i]-j+1;l++){
                            if(a[i][l]==1 && a[i][l+j-1]==c){
                                flag=1;
                                break;
                            }
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
                if(flag) cout<<"1\n";
                else cout<<"0\n";
            }
            else{
                dfs(1,0,1);//I love 101
                if(ans==1) cout<<"1\n";
                else cout<<"0\n";
                ans=0;
            }
        }
    }
    return 0;
}

//15pts finish time: 11:59
//luogu uid 453759
//BJ-J01371
//:(
//IcantAKCSPJ
