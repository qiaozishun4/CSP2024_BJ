#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int n,m,k,T;
int a1[100010],a[100010];
int c[100010];
string d[110];
int x[10][300];
vector<int> v[100010];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);

    scanf("%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a1[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&c[i]);
    }
    for(int i=0;i<=n;i++){
        if(pow(2,i)>=n){
            k=i;
            break;
        }
    }
    for(int i=1;i<=k;i++){
        cin>>d[i];
    }

    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d%d%d%d",&x[0][i],&x[1][i],&x[0][i],&x[3][i]);
    }

    for(int p=1;p<=T;p++){

        //init
        for(int i=1;i<=m;i++){
            while(v[i].size()>0){
                v[i].pop_back();
            }
        }


        for(int i=1;i<=n;i++){
            a[i]=a1[i]^(x[p][i%4]);
        }
        for(int i=1;i<=m;i++){
            //diyilun
            int cnt=0;
            for(int j=2;j<=c[i];j*=2){
                cnt++;
                if(d[1][cnt-1]=='0'){
                    if(a[j-1]>=cnt){
                        v[i].push_back(j-1);
                    }else{
                        v[i].push_back(j);
                    }

                }else{
                    if(a[j]>=cnt){
                        v[i].push_back(j);
                    }else{
                        v[i].push_back(j-1);
                    }

                }

            }
            while(v[i].size()>1){
                int tmp[100010],cnt=0,lunshu=2;
                for(int j=0;j<v[i].size()-1;j+=2){
                    cnt++;
                    if(d[lunshu][j/2]=='0'){
                        if(a[j]>=cnt){
                            tmp[cnt]=j;
                        }else{
                            tmp[cnt]=j+1;
                        }

                    }else{
                        if(a[j+1]>=cnt){
                            tmp[cnt]=j+1;
                        }else{
                            tmp[cnt]=j;
                        }

                    }
                }
                lunshu++;
                while(v[i].size()>0){
                    v[i].pop_back();
                }
                for(int i=1;i<=cnt;i++){
                    v[i].push_back(tmp[i]);
                }
            }


        }
        long long ans=0;
        ans=v[1][0];
        for(int i=2;i<=m;i++){
            ans=ans^(2*v[2][0]);
        }
        printf("%lld\n",ans);

    }
    return 0;
}
