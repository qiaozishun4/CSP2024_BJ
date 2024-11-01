#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,l,x,y,d;
string s[10000];
int a[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int l=0;l<n;l++) cin>>s[l];
        int i=x-1,j=y-1;
        for(int p=0;p<n;p++){
            for(int o=0;o<m;o++) a[p][o]=0;
        }
        while(k--){
            a[i][j]=1;
            if(d==0){
                if(j+1>=m||s[i][j+1]=='x'){
                    d=(d+1)%4;
                }
                else{
                    j+=1;
                    if(!a[i][j])
                    ans++;
                }
            }
            else if(d==1){
                if(i+1>=n||s[i+1][j]=='x'){
                    d=(d+1)%4;
                }
                else{
                    i+=1;
                    if(!a[i][j])
                    ans++;
                }
            }
            else if(d==2){
                if(j-1<0||s[i][j-1]=='x'){
                    d=(d+1)%4;
                }
                else{
                    j-=1;
                    if(!a[i][j])
                    ans++;
                }
            }
            else if(d==3){
                if(i-1<0||s[i-1][j]=='x'){
                    d=(d+1)%4;
                }
                else{
                    i-=1;
                    if(!a[i][j])
                    ans++;
                }
            }

        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


