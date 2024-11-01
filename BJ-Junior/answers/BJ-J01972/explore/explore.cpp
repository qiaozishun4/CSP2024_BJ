#include<iostream>
using namespace std;
char forest[1000][1000];
char check[1000][1000];
int cposition(int direc){
    if(direc==0){
        return 1;
    }else if(direc==1){
        return 2;
    }else if(direc==2){
        return 3;
    }else{
        return 0;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t = 0;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n = 0;
        int m = 0;
        int s = 0;
        cin>>n>>m>>s;
        int rn = 0;
        int rm = 0;
        int rd = 0;
        cin>>rn>>rm>>rd;
        rn--;
        rm--;
        int ans = 1;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin>>forest[i][j];
                check[i][j]=false;
            }
        }
        for(int j = 0; j < s; j++){
            int tmpn = 0;
            int tmpm = 0;
            if(rd==0){
                tmpn=rn;
                tmpm=rm+1;
            }else if(rd==1){
                tmpn=rn+1;
                tmpm=rm;
            }else if(rd==2){
                tmpn=rn;
                tmpm=rm-1;
            }else{
                tmpn=rn-1;
                tmpm=rm;
            }

            if(tmpn<0||tmpm<0||tmpn>=n||tmpm>=m||forest[tmpn][tmpm]=='x'||check[tmpn][tmpm]==true){
                if(rd==0){
                    rd=1;
                }else if(rd==1){
                    rd=2;
                }else if(rd==2){
                    rd=3;
                }else{
                    rd=0;
                }

            }else{
                rn=tmpn;
                rm=tmpm;
                ans++;
                check[tmpn][tmpm]=true;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
