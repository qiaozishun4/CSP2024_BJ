#include<bits/stdc++.h>
using namespace std;
int T,n,cnt=1,ans=0;
bool a[10240][16];
int b[20],d[9]={0,0,0,1,0,0,1,0,0};
void ejz(int i){
    int j=i,z=n;
    while(j){
        a[i][z--]=j%2;
        j/=2;
    }
    return ;
}
int main(){
   
    cin>>T;
    while(T--){
        
        cnt=1,ans=0;
        memset(a,0,sizeof(a));
        int c=0;
        cin>>n;
        for(int i=1;i<(1<<n);i++){
            ejz(i);
    
        }
      
        for(int i=1;i<=n;i++){
            cin>>b[i];
    
        }
        
        for(int i=1;i<(1<<n);i++){
            for(int j=1;j<=n;j++){
                for(int k=j-1;k>=1;k--){
                    if(a[i][j]==a[i][k]){
                        if(b[j]==b[k]){
                            c+=b[k];
                        }
                        break;
                    }
                }
            }
            ans=max(ans,c);
            c=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}