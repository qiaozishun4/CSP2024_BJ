# include<bits/stdc++.h>
using namespace std;
int x[100001],y[100001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T,n,m,k,x0,y0,d0;
    cin>>T;
    for(int i=1;i<=T;i++){
        int sum=0,xx=1,yy=1;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        char c[n+1][m+1];
        for(int xi=1;xi<=n;xi++){
            for(int yi=1;yi<=m;yi++){
                cin>>c[xi][yi];
            }
        }
        for(int j=1;j<=k;j++){
            if(d0==0){
                if(c[x0][y0+1]=='.'&&y0+1<=m){sum++;y0++;x[xx]=x0;y[yy]=y0;xx++;yy++;}
                else d0=(d0+1)%4;
            }
            else if(d0==1){
                if(c[x0+1][y0]=='.'&&x0+1<=n){sum++;x0++;x[xx]=x0;y[yy]=y0;xx++;yy++;}
                else d0=(d0+1)%4;
            }
            else if(d0==2){
                if(c[x0][y0-1]=='.'&&y0-1>=1){sum++;y0--;x[xx]=x0;y[yy]=y0;xx++;yy++;}
                else d0=(d0+1)%4;
            }
            else if(d0==3){
                if(c[x0-1][y0]=='.'&&x0-1>=1){sum++;x0--;x[xx]=x0;y[yy]=y0;xx++;yy++;}
                else d0=(d0+1)%4;
            }
        }int sumn=sum;
        for(int k=1;k<sumn;k++){
            for(int ki=k+1;ki<=sumn;ki++){
            if(x[k]==x[ki]&&y[k]==y[ki])sum--;
        }
        }

        cout<<sum+1<<endl;
    }

    fclose(stdin);
    fclose(stdout);


    return 0;


}
