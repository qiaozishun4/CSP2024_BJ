#include<bits/stdc++.h>
using namespace std;
const int N=(int)1000+10;
int n,m,k,xx,yy,d,cnt=0;



inline int solve(){
    bool mapc[N][N];
    bool walked[N][N];
    //unordered_map <int,bool> mapc[N];
    //unordered_map <int,bool> walked[N];
    int ans=1;//initial point
    cin>>n>>m>>k>>xx>>yy>>d;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char tmp;
            cin>>tmp;
            mapc[i][j]=false;
            walked[i][j]=false;
            //cout<<i<<' '<<j<<endl;
            if(tmp=='.'){
                mapc[i][j]=true;
                cnt++;
            }

        }
    }
    walked[xx][yy]=1;
    for(int stepN=0;stepN<k;stepN++){
        int tx=xx,ty=yy;
        if(ans>=cnt){
            return cnt;
        }
        //cout<<tx<<' '<<ty<<' '<<d<<endl;

        switch(d){
        case 0:
            ty+=1;
            break;
        case 1:
            tx+=1;
            break;
        case 2:
            ty-=1;
            break;
        case 3:
            tx-=1;
            break;
        }
        //cout<<tx<<' '<<ty<<' '<<d<<endl;
        if(tx>=1 && tx<=n && ty>=1 && ty<=m && mapc[tx][ty]){
            xx=tx;
            yy=ty;
        }else{
            d=(d+1)%4;
        }
        if(walked[xx][yy]==1){
            continue;
        }else{
            walked[xx][yy]=1;
            ans++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}
