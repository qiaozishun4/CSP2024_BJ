#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,d;
long long sum;
char ditu[4000005];
int s[4000005];
long long g;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int z;
    cin>>z;
    for (int a=1;a<=z;a++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        g=2000*x+y;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>ditu[2000*i+j];
            }
        }
        for (int i=1;i<=k;i++){
            s[g]++;
            if (d==3){
                if (ditu[g-2000]=='x'||g-2000<2001){
                    d=(d+1)%4;
                    continue;
                }
                else {
                    g-=2000;
                    x-=1;
                    s[g]++;
                    continue;
                }
            }
            else if (d==0){
                if (ditu[g+1]=='x'||g+1>2000*x+m){
                    d=(d+1)%4;
                    continue;
                }
                else {
                    g+=1;
                    y+=1;
                    s[g]++;
                    continue;
                }
            }
            else if (d==1){
                if (ditu[g+2000]=='x'||g+2000>2000*n+m){
                    d=(d+1)%4;
                    continue;
                }
                else {
                    g+=2000;
                    x+=1;
                    s[g]++;
                    continue;
                }
            }
            else if (d==2){
                if (ditu[g-1]=='x'||g-1<2000*x+1){
                    d=(d+1)%4;
                    continue;
                }
                else {
                    g-=1;
                    y-=1;
                    s[g]++;
                    continue;
                }
            }
        }
        for (int i=1;i<=2000*n+m;i++){
            if (s[i]) sum++;
            s[i]=0;
        }
        cout<<sum<<endl;
        sum=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
