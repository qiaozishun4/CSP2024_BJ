#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int sum=0;
        int n,m,k;
        cin>>n>>m>>k;
        char s[1005][1005];
        bool s1[1005][1005];
        int a,b,d;
        cin>>a>>b>>d;
        int h=a,l=b;
        for(int j=1;j<=n;j++){
            for(int f=1;f<=m;f++){
                cin>>s[j][f];
                s1[j][f]=0;
            }
        }
        for(int j=0;j<k;j++){
            if(d==3&&s[a+1][b]=='.'&&a+1<=n&&a>0&&b<=m&&b>0){
                a++;
                if(s1[a][b]==0){
                    sum++;
                    s1[a][b]=1;
                }
                continue;
            }else if(d==1&&s[a-1][b]=='.'&&a<=n&&a-1>0&&b<=m&&b>0){
                a--;
                if(s1[a][b]==0){
                    sum++;
                    s1[a][b]=1;
                }
                continue;
            }else if(d==0&&s[a][b+1]=='.'&&a<=n&&a>0&&b+1<=m&&b>0){
                b++;
                if(s1[a][b]==0){
                    sum++;
                    s1[a][b]=1;
                }
                continue;
            }else if(d==2&&s[a][b-1]=='.'&&a<=n&&a>0&&b<=m&&b-1>0){
                b--;
                if(s1[a][b]==0){
                    sum++;
                    s1[a][b]=1;
                }

                continue;
            }
            else{
                d=(d+1)%4;
                if(j==0){
                    sum++;
                    s1[a][b]=1;
                }
            }
        }
        cout<<sum;
    }
    return 0;
}

