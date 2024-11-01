#include<bits/stdc++.h>
using namespace std;
int basic[10]={6,2,5,5,4,5,6,3,7,6};
int ans,n,m,l,t;
int wait[1010],al,h=1,w,u,o,r=1e9;
void g(int ll,int xx){
    if(al==xx){
        sort(wait+1,wait+1+u);
        r=min(r,wait[h]);
        h++;
        return ;
    }
    u=ll;
    for(int i=2;i<=7;i++){
        for(int j=0;j<=9;j++){
            if(basic[j]==i){
                w=j;
                break;
            }
        }
        if(al==0) wait[h]=w;
        else wait[h]=wait[h]*10+w;
        al+=i;
        g(ll-1,al);
        al-=i;
    }

    return ;
}
void find(int x){
    if(x<=1){
        cout<<"-1"<<endl;
        return ;
    }
    else if(x<=7){
        for(int i=1;i<=9;i++){
            if(x==basic[i]){
                cout<<i<<endl;
                return ;
            }
        }
    }
    else if(x%7==0){
        l=x/7;
        for(int i=1;i<=l;i++) cout<<"8";
        cout<<endl;
    }
    else if(x%7==1){
        l=x/7;
        cout<<"10";
        for(int i=1;i<l;i++) cout<<"8";
        cout<<endl;
    }
    else{
        l=x/7+1;
        g(l,x);
        cout<<r;
    }
    return ;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        for(int i=1;i<=1010;i++) wait[i]=1;
        cin>>n;
        find(n);
    }
    return 0;
}
