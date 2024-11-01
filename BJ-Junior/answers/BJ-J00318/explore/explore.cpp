#include<iostream>
using namespace std;
char arr[1005][1000005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x,y,d;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=0;j<n;j++){
            for(int q=0;q<m;q++){
                cin>>arr[j][q];
            }
        }
    }
    int cnt=0;
    char c='.';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==c){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
