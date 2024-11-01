#include <bits/stdc++.h>


using namespace std;
long long n,mx=0,ans=0;
struct qwerty{
    int a,b,c;//b=abstent c=short
}a[100005]={};
long long ss[100005]={};
int sss[100005]={};


int s(){
    int y=n;
    int x=1;

    for(int i=1;i<=1e5&&y>=0;i++){
        int cont=0;
        for(int j=0;j<ss[i];j++){
               // cout<<"("<<i<<","<<j<<")"<<x<<endl;
            cont++;
            a[x].a=i;
            x++;
            y--;

        }

    }
    return 0;
}

int main(){

    freopen("duel1.in","r",stdin);
    freopen("duel.out","w",stdout);
    //cout<<1;
    cin>>n;
    //cout<<n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ss[x]++;
        a[i].b=1;
        a[i].c=1;
        //cout<<x<<" "<<i<<endl;
    }
    s();
    //cout<<endl;

    for(int i=1;i<=n;i++){//j eat i


        for(int j=1;j<=n;j++){


            if(a[i].a>=a[j].a||a[j].b==0||a[i].b==0||a[j].c==0||i==j){
                continue;

            }

            ans++;
            a[i].b=0;
            a[j].c=0;
            break;
        }
    }
    cout<<n-ans;

    return 0;
}
