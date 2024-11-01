#include<bits/stdc++.h>
using namespace std;
int n,r[100005];
int ans;
int d[100005],bd[100005];
long long sheng;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++){
        if(r[i]!=r[i-1]){
            d[++ans]=r[i];
            bd[ans]++;
        }
        else{
            bd[ans]++;
        }

    }

    for(int i=1;i<ans;i++){
      for(int j=i+1;j<=ans;j++){

            if(bd[j]>bd[i]){
                bd[i]=0;
                break;
            }
            else if(bd[j]==bd[i]){

                bd[i]=0;
                break;
            }
            else{
                bd[i]-=bd[j];
                break;
            }

        }
    }

   for(int i=1;i<=ans;i++){
       sheng+=bd[i];
   }
    cout<<sheng;
    return 0;
}
