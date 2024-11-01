#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
bool bmp[1005][1005];
long long u,l,r;
int bot(int n,int m,int d,int s){//hang lie fangxiang shengyubushu
    if(m==0||n==0||m>l||n>r){
        return s;
    }
    if(bmp[n][m]==0&&mp[n][m]=='.'){
        u++;
    }
    //cout<<s<<" "<<u<<" "<<m<<" "<<n<<" "<<d<<endl;
    bmp[n][m]=1;
    int dd=d;
    for(int i=0;s>0&&i<4;i++){
        d=(dd+i)%4;
        if(d!=dd)
        s--;
        if(s<=0){
            return 0;
        }
        //cout<<"d="<<d<<endl;
        if(d==0){
            if(mp[n][m+1]=='.'){
                //cout<<"mp="<<mp[n][m+1]<<endl;
                s=bot(n,m+1,d,s-1);
            }
        }else if(d==1){
            if(mp[n+1][m]=='.'){
                s=bot(n+1,m,d,s-1);
            }
        }else if(d==2){
            if(mp[n][m-1]=='.'){
                s=bot(n,m-1,d,s-1);
            }
        }else if(d==3){
            if(mp[n-1][m]=='.'){
                s=bot(n-1,m,d,s-1);
            }
        }
    }
    return s;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int tt;
    cin>>tt;
    for(int jj=0;jj<tt;jj++){
        l=0;
        r=0;
        u=0;
        for(int i=1;i<=1001;i++){
            for(int j=1;j<=1001;j++){
                mp[i][j]=0;
                bmp[i][j]=0;
            }
        }
        int m=0,n=0,k=0,sm=0,sn=0,d=0;
        cin>>n>>m>>k>>sn>>sm>>d;
        l=m;
        r=n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                if(mp[i][j]!='.'){
                    bmp[i][j]=1;
                }
            }
        }
        bot(sn,sm,d,k);
        cout<<u<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
