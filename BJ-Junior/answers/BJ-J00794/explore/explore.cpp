#include<bits/stdc++.h>
using namespace std;

char a[1050][1050];
bool b[1050][1050];
int t,n,m,k,x,y,d,sum=1;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int k=1;k<=n;k++){
            for(int j=1;j<=m;j++){
                cin>>a[k][j];
                b[k][j]=false;
            }
        }
        sum=1;
        b[x][y]=true;
        while(k!=0){
            if(d==0&&a[x][y+1]=='.'&&1<=x&&x<=n&&1<=y+1&&y+1<=m){
                if(!b[x][y+1]){
                    sum++;
                    b[x][y+1]=true;
                }

                y=y+1;
            }
            else if(d==1&&a[x+1][y]=='.'&&1<=x+1&&x+1<=n&&1<=y&&y<=m){
                if(!b[x+1][y]){
                    sum++;
                    b[x+1][y]=true;
                }
                x=x+1;
            }
            else if(d==2&&a[x][y-1]=='.'&&1<=x&&x<=n&&1<=y-1&&y-1<=m){
                if(!b[x][y-1]){
                    sum++;
                    b[x][y-1]=true;
                }
                y=y-1;
            }
            else  if(d==3&&a[x-1][y]=='.'&&1<=x-1&&x-1<=n&&1<=y&&y<=m){
                if(!b[x-1][y]){
                    sum++;
                    b[x-1][y]=true;
                }
                x=x-1;
            }
             else{
                d=(d+1)%4;
             }
           //  cout<<x<<" "<<y<<endl;
            k--;
        }
        cout<<sum<<endl;
	}

	return 0;
}
