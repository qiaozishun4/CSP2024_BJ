#include<bits/stdc++.h>
using namespace std;
int gs;
int ans=0;
string a[1032];
bool byd[1032][1032];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&gs);
    for(int i=1;i<=gs;i++){
        ans=0;

        int n,m,k;
        int csxz,csyz,cx;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&csxz,&csyz,&cx);
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                a[j][l]=0;
                byd[j][l]=0;
            }

        }
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++)
            cin>>a[j][l];
        }
        int x=csxz,y=csyz;
        byd[x][y]=1;
        cx%=4;
        bool te=1;
        while(k!=0){
            cx%=4;

            byd[x][y]=1;

            if(cx==0){
                if(a[x][y+1]=='.'){
                    y+=1;
                    k--;
                    continue;
                }
                if(a[x][y+1]!='.'){
                    cx+=1;
                    k--;
                    continue;
                }
            }
            if(cx==1){
                if(a[x+1][y]=='.'){
                    x+=1;
                    k--;
                    continue;
                }
                if(a[x+1][y]!='.'){
                    cx+=1;
                    k--;
                    continue;
                }
            }
            if(cx==2){
                if(a[x][y-1]=='.'){
                    y-=1;
                    k--;
                    continue;
                }
                if(a[x][y-1]!='.'){
                    cx+=1;
                    k--;
                    continue;
                }
            }
            if(cx==3){
                if(a[x-1][y]=='.'){
                    x-=1;
                    k--;
                    continue;
                }
                if(a[x-1][y]!='.'){
                    cx+=1;
                    k--;
                    continue;
                }
            }
        }
        byd[x][y]=1;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++)
                if(byd[j][l]==1){
                    ans++;
                }
        }
       printf("%d\n",ans);
    }
    return 0;
}
