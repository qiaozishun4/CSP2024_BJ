#include<bits/stdc++.h>
using namespace std;
int n, k, a[10005][20005];
bool DFS(int m, int r, int c,int s){
    //cout << m << " " << r << " "<< c << " " << s << "\n";
    if(r==1){
        //cout << n;
        for(int i=1;i<=n;i++){
            if(i==s)continue;
            //cout << a[i][0] << " ";
            for(int j=1;j<a[i][0];j++){
                //cout << a[i][j] << " "<<a[i][j+1] << " "<<a[i][j+2]<<'\n';
                if(a[i][j]==m){
                    for(int q =1;q<k&&j+q<=a[i][0];q++){
                        if(a[i][j+q]==c)return true;
                    }
                }
            }
        }
        return false;
    }
    for(int i=1;i<=n;i++){
        if(i==s)continue;
        for(int j=1;j<a[i][0];j++){
            if(a[i][j]==m){
                for(int q =1;q<k&&j+q<=a[i][0];q++){
                    if(DFS(a[i][j+q], r-1, c, i))return true;
                }
            }
        }
    }
    return false;
}
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        int q;
        scanf("%d %d %d", &n, &k, &q);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i][0]);
            for(int j=1;j<=a[i][0];j++){
                scanf("%d", &a[i][j]);
            }
            a[n][a[n][0]+1]=-1;
        }
        while(q--){
            int r, c;
            scanf("%d %d", &r, &c);
            printf("%d\n", DFS(1,r,c,0));
        }
    }
}
