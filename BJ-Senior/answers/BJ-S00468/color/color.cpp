#include <iostream>

using namespace std;
struct node{
    long long v;
    long long color;//1表示蓝色，2表示红色
};
long long get_score(node x[],long long len){
    long long c[len+1]={};
    bool flag=false;
    long long k;
    for(long long i=1;i<=len;i++){
        for(long long j=i-1;j>=1;j--){
            if(x[i].color==x[j].color){
                flag=true;
                k=j;
                break;
            }
        }
        if(!flag){
            c[i]=0;
        }else{
            if(x[i].v==x[k].v){
                c[i]=x[i].v;
            }else{
                c[i]=0;
            }
        }
    }
    long long res=0;
    for(long long i=1;i<=len;i++){
        res+=c[i];
    }
    return res;
}
bool check(node x[],long long len){
    bool flag=true;
    for(long long i=1;i<=len;i++){
        if(x[i].color==0){
            flag=false;
        }
    }
    return flag;
}
long long max_val(node x[],long long step,long long len){
    if(step==len+1){
        return get_score(x,len);

    }else{
        long long max_=0;
        //尝试染成蓝色
        x[step].color=1;
        max_=max(max_,max_val(x,step+1,len));
        x[step].color=2;
        max_=max(max_,max_val(x,step+1,len));
        x[step].color=0;
        return max_;
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long T;
    cin>>T;
    while(T--){
        long long n;
        cin>>n;
        node arr[n+1];
        for(long long i=1;i<=n;i++){
            cin>>arr[i].v;
            arr[i].color=0;
        }
        cout<<max_val(arr,1,n)<<endl;
    }
    return 0;
}
