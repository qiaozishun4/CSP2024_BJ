#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore4.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k,x,y,d,ans;
    int a[1005][1005]={0};
    int pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    string s;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=0;
        int l,sum=0;
        while(true){
            cin>>s;
            l=s.length()
            sum+=l;
            for(int i=0;i<l;i++){
                if(s[i]=='%') a[i/m][i%m]=1;
            }
            if(sum=m*n) break;
        }
        a[x][y]=2;
        for(int j=0;j<k;j++){
            if(x+pos[d][0]==0||y+pos[d][1]==0||x+pos[d][0]==n+1||y+pos[d][1]==m+1||a[x+pos[d][0]][y+pos[d][1]]==1) d=(d+1)%4;
            else{
                x+=pos[d][0];
                y+=pos[d][1];
                a[x][y]=2;
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                //out<<a[j][k]<<' ';
                if(a[j][k]==2){
                    ans++;
                }
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
