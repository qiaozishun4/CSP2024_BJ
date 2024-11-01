#include<bits/stdc++.h>
using namespace std;
int col[200005]={};
int C[200005]={};
bool se[200005]={};
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        memset(col,0,sizeof(col));
        memset(se,0,sizeof(se));
        int n;
        cin >> n;
        for(int j=1;j<=n;j++){
            cin >> col[j];
        }
        int cnt=0;
        int fr=1,ba=2;
        int check=0;
        while(ba<=n){
            if((col[fr]==col[ba])&&((ba-fr)>1)&&!se[fr]){
                cnt+=col[fr];
                se[ba]=1;
                fr++;
                ba=fr+1;
                //check++;
                //cout<<check<<endl;
            }
            else ba++;
            if(ba>n&&fr<n){
                fr++;
                ba=fr+1;
            }
            //cout << fr << " " << ba  << endl;
        }
        cout << cnt << endl;
    }
    return 0;
}
