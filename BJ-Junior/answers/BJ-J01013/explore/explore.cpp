#include<bits/stdc++.h>
using namespace std;
const int N=1050;
int f,m,n,t,dog[5];
bool flag[N][N];
char q[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
            int e=1;
        cin>>n>>m>>f;
        cin>>dog[1]>>dog[2]>>dog[3];
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>q[j][k];
                flag[j][k]=false;
            }
        }
        flag[dog[1]][dog[2]]=true;
        for(int j=1;j<=f;j++){
            if(dog[3]==0){
                if(dog[2]+1<=m&&q[dog[1]][dog[2]+1]=='.'){
                        dog[2]++;
                    if(flag[dog[1]][dog[2]]==false){
                        e++;
                        flag[dog[1]][dog[2]]=true;
                    }
                }else{
                    dog[3]=1;
                }
            }else if(dog[3]==1){
                if(dog[1]+1<=n&&q[dog[1]+1][dog[2]]=='.'){
                        dog[1]++;
                    if(flag[dog[1]][dog[2]]==false){
                        e++;
                        flag[dog[1]][dog[2]]=true;
                    }
                }else{
                    dog[3]=2;
                }
            }else if(dog[3]==2){
                 if(dog[2]-1>=1&&q[dog[1]][dog[2]-1]=='.'){
                        dog[2]--;
                    if(flag[dog[1]][dog[2]]==false){
                        e++;
                        flag[dog[1]][dog[2]]=true;
                    }
                }else{
                    dog[3]=3;
                }
            }else{
                if(dog[1]-1>=1&&q[dog[1]-1][dog[2]]=='.'){
                        dog[1]--;
                    if(flag[dog[1]][dog[2]]==false){
                        e++;
                        flag[dog[1]][dog[2]]=true;
                    }
                }else{
                    dog[3]=0;
                }
            }
        }
        cout<<e<<endl;
    }
    return 0;
}