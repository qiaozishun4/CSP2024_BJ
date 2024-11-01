#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
char c[1000][1000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>c[i][j];
        c[x-1][y-1]='0';
        int sum=1;
        while (k--){
            if(d==0){
                if(c[x-1][y+1-1]=='x'||y+1>n) d=(d+1)%4;
                else if(c[x-1][y+1-1]!='0'){
                    c[x-1][y+1-1]='0';
                    y=y+1;
                    sum=sum+1;
                }
                else y=y+1;
            }
            else if(d==1){
                if(c[x+1-1][y-1]=='x'||x+1>m) d=(d+1)%4;
                else if(c[x+1-1][y-1]!='0'){
                    c[x+1-1][y-1]='0';
                    x=x+1;
                    sum=sum+1;
                }
                else x=x+1;
            }
            else if(d==2){
                if(c[x-1][y-1-1]=='x'||y-1<1) d=(d+1)%4;
                else if(c[x-1][y-1-1]!='0'){
                    c[x-1][y-1-1]='0';
                    y=y-1;
                    sum=sum+1;
                }
                else y=y-1;
            }
            else if(d==3){
                if(c[x-1-1][y-1]=='x'||x-1<1) d=(d+1)%4;
                else if(c[x-1-1][y-1]!='0'){
                    c[x-1-1][y-1]='0';
                    x=x-1;
                    sum=sum+1;
                }
                else x=x-1;
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}