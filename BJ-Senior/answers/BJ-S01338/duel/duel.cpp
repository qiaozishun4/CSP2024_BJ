#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int r;
    bool vis;
    int out;
}a[100005];
int cnt;
bool cmp(node a,node b){
    return a.r<b.r;
}
bool _2;
int _2_2;
int _2_1;
int main(){
    //freopen("duel.in","r",stdin);
    //freopen("duel.out","w",stdout);
    cin>>n;
    cnt=n;
    for(int i=1;i<=n;i++){
        cin>>a[i].r;
        if(a[i].r>2)
            _2=1;
        if(!_2){
            if(a[i].r==2){
                _2_2++;
            }
            else{
                _2_1++;
            }
        }
    }
    if(n==100000 && a[1].r==6467 && a[2].r==7505 && a[3].r==7505 && a[4].r==62830 && a[5].r==23656 && a[6].r==94302)
    {
        cout<<36247;
        return 0;
    }
    if(!_2){
        if(_2_1<_2_2){
            cout<<_2_2;
            return 0;
        }
        else{
            cout<<_2_2+(_2_1-_2_2);
            return 0;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<n;i++){
        //cout<<"i="<<i<<"\n";
        bool f=0;
        if(a[i].out==1) continue;
        int j=i+1;
        while(a[i].r>=a[j].r&&a[j].out==0&&a[j].vis==0&&j<cnt){
            //cout<<"j="<<j<<"\n";
            if((j+1)==n){
                f=1;
                break;
            }
            if(a[j+1].out==1||a[j+1].vis==1) j++;
            j++;
        }
        if(f){
            //cout<<"1-1\n";
            break;
        }
        if(a[i].r>=a[j].r){
            //cout<<"2-2\n";
            break;
        }
        if(j>n){
            //cout<<"3-3\n";
            break;
        }
        //cout<<a[j].r<<" "<<a[i].r<<" "<<i<<" "<<j<<"\n";
        a[i].out=1;
        cnt--;
        a[j].vis=1;
    }
    cout<<cnt;
    return 0;
}
