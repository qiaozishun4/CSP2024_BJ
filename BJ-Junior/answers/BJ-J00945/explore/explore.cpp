#include<bits/stdc++.h>
#define int long long
using namespace std;

char a[1005][1005];
bool place[1005][1005];
int ans=0;
int x00,y00,d00;
int n,m;

void change(int x,int y,int d){
    int nx,ny; nx=x,ny=y;

    if(d==0){
        ny++;
    }
    else if(d==1){
        nx++;
    }
    else if(d==2){
        ny--;
    }
    else{
        nx--;
    }

    //cout<<nx<<" "<<ny<<" "<<a[nx][ny]<<endl;
    if(1<=nx && nx<=n && 1<=ny && ny<=m && a[nx][ny]=='.'){
        x00=nx,y00=ny;
        //cout<<x00<<" "<<y00<<" "<<d<<endl;
    }
    else{
        d00=(d+1)%4;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t; cin>>t;

    while(t--){
        ans=0;
        memset(place,0,sizeof place);

        int k; cin>>n>>m>>k;
        cin>>x00>>y00>>d00;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }

        if(!place[x00][y00]){
            ans++;
        }
        place[x00][y00]=1;

        for(int i=1;i<=k;i++){
            change(x00,y00,d00);
            //cout<<x00<<" "<<y00<<" "<<d00<<endl;

            if(!place[x00][y00]){
                ans++;
            }

            place[x00][y00]=1;
        }

        cout<<ans<<"\n";
    }
    return 0;
}

