    #include<bits/stdc++.h>
    using namespace std;
    int ki[100005],k[100005];
    int main(){
        freopen("duel.in","r",stdin);
        freopen("duel.out","w",stdout);
        int n,xiao=10000000;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>ki[i];
        }
        int num=n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j>i){
                    if(k[j]==0){
                        num=num-1;
                        k[j]=1;
                        continue;
                    }
                }
            }
        }
        cout<<num;
        return 0;
    }

