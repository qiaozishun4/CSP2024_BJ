#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int c=0;
    char ch=getchar();

    while(ch<'0'||ch>'9'){
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    int T=read();

    while(T--){
        int n=read(),a[200005];
        long long ans=0;

        for(int i=1;i<=n;i++){
            a[i]=read();
        }

        for(long long i=0;i<=(1<<n)-1;i++){
            long long i1=i,t=1;

            vector<int>blue;
            vector<int>red;

            while(i1!=0){
                if(i1%2==0){
                    blue.push_back(a[t]);
                }else{
                    red.push_back(a[t]);
                }

                t++;
                i1/=2;
            }

            long long score=0;

            for(int i=1;i<blue.size();i++){
                if(blue[i]==blue[i-1]){
                    score+=blue[i];
                }
            }

            for(int i=1;i<red.size();i++){
                if(red[i]==red[i-1]){
                    score+=red[i];
                }
            }

            ans=max(ans,score);
        }

        cout<<ans<<"\n";
    }
    return 0;
}
