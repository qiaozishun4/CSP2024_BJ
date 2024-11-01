#include<bits/stdc++.h>
using namespace std;
struct s{
    int num;
    bool a;
    bool b;
};
bool abc(s a,s b){
    if(a.num>b.num){
        return true;
    }
    else{
    return false;
    }
}

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int a,ans=0;
    cin>>a;
    s n[a];
    for(int i=0;i<a;i++){
        cin>>n[i].num;

        n[i].a=true;
        n[i].b=true;
    }

    bool bo=true;
    int abc=0;
    while(bo==true){
            //cout<<"start"<<endl;
        for(int i=1;i<a;i++){
                //cout<<"round"<<endl;
            int b=i;
            while(1){
                //cout<<i<<n[i].num<<endl;
                //cout<<"check target"<<i-b<<"("<<n[i-b].num<<")"<<endl;
                if(i-b>=a){
                    //cout<<"not find"<<endl;
                    break;

                }
                if(n[i-b].num<n[i].num&&n[i-b].a==true&&n[i].b==true){
                    n[i-b].a=false;
                    n[i].b=false;
                    //cout<<i-b<<" dead"<<endl;
                    break;
                }
                b--;
            }


    }
        for(int j=0;j<a;j++){
            if(n[j].a==true){
                ans++;

            }
            if(n[j].b==true&&n[j].a==true){
                ans=0;
                abc=j;
                //cout<<"re"<<endl;
                break;
            }
    }
            if (ans!=0){
            bo=false;
        }
    }
    //cout<<"complete"<<endl;
    cout<<ans;
    return 0;
}


