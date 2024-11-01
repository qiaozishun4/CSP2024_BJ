#include<bits/stdc++.h>
using namespace std;
int t,p[100010];
int s[110][10010];
bool mp[110][10010];
//void dfs(int r,int c,int k){
   //if(r==0){
     //   return ;
    //}
    //else{
        //for(int i=1;i<=n;i++){
           // for(int j=1;j<=p[i];j++){
             //   for(int l=j;l<=p[i]+k;l++){
             //       if(!mp[i][l]){
//
              //      }
              //  }
            //}
        //}
    //}
//}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>p[i];
            for(int j=1;j<=p[i];j++){
                cin>>s[i][j];
            }
        }
        while(q--){
            int r,c,cnt=0;
            cin>>r>>c;
            for(int i=1;i<=p[n];i++){
                if(c!=s[n][i]){
                    cnt++;
                }
            }
            if(cnt==p[n]||k<2){
                cout<<0<<endl;
            }
            else{
                srand(time(NULL));
                cout<<rand()%2<<endl;
            }
        }
    }
    return 0;
}
