#include <bits/stdc++.h>
#define int int64_t
using namespace std;
pair<int,int> check(int n){
    if(n>=6){
        if((n>=7&&n-7<=7&&n-6<=7)||n<7){
            return {n-6,0};
        }
        else if((n>=7&&n-7>7&&n-6>7)||(n>=7&&n-7<=7&&n-6>7)){
            return {n-7,8};
        }
    }
    if(n>=5){
        return {n-5,2};
    }
    if(n>=4){
        return {n-4,4};
    }
    if(n>=2){
        if((n>=3&&n-3<=7&&n-2<=7)||n<3){
            return {n-2,1};
        }
        else if((n>=3&&n-3>7&&n-2>7)||(n>=3&&n-3<=7&&n-2>7)){
            return {n-3,7};
        }
    }
    return {-1,-1};
}
int32_t main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    vector<pair<int,int>> num(11);
    num={{1,2},{7,3},{4,4},{2,5},{3,5},{5,5},{0,6},{6,6},{9,6},{8,7}};
    while(T--){
        int n;
        cin >> n;
        int ans1=0,ans2=0,ans3=0,n1=n,n2=n,n3=n;
        if(n/10==0){
            bool get=false;
            for(int i=0;i<11;i++){
                if(n==num[i].second&&num[i].first!=0){
                    get=true;
                    cout << num[i].first << endl;
                    break;
                }
            }
            if(!get){
                cout << -1 << endl;
            }
        }
        else{
            if(n1-2>=2){
                n1-=2;
                ans1=1;
            }
            if(n2-5>=2){
                n2-=5;
                ans2=2;
            }
            else if(n2-3>=2){
                n2-=3;
                ans2=7;
            }
            while(n1>0){
                //cout << n1 << endl;
                pair<int,int> res=check(n1);
                n1=res.first;
                ans1=ans1*10+res.second;
                if(n1>=2&&n1<=7){
                    bool get=false;
                    for(int i=0;i<11;i++){
                        if(n1==num[i].second){
                            get=true;
                            ans1=ans1*10+num[i].first;
                            break;
                        }
                    }
                    if(get){
                        break;
                    }
                }
                if(n1==-1){
                    ans1=-1;
                    break;
                }
                ans1=ans1*10+res.second;
            }
            while(n2>0){

                pair<int,int> res=check(n2);

                n2=res.first;
                ans2=ans2*10+res.second;
                //cout << n2 << endl;
                bool get=false;
                if(n2>=2&&n2<=7){
                    for(int i=0;i<11;i++){
                        if(n2==num[i].second){
                            get=true;
                            ans2=ans2*10+num[i].first;
                            break;
                        }
                    }
                    if(get){
                        break;
                    }
                }
                if(n2==-1){
                    ans2=-1;
                    break;
                }
                ans2=ans2*10+res.second;
            }
            while(n3>0){
                pair<int,int> res=check(n3);
                n3=res.first;
                ans3=ans3*10+res.second;
                if(n3>=2&&n3<=7){
                    bool get=false;
                    for(int i=0;i<11;i++){
                        if(n3==num[i].second){
                            get=true;
                            ans3=ans3*10+num[i].first;
                            break;
                        }
                    }
                    if(get){
                        break;
                    }
                }
                if(n3==-1){
                    ans3=-1;
                    break;
                }
                ans3=ans3*10+res.second;
            }
            if(ans1==-1&&ans2==-1&&ans3==-1){
                cout << -1 << endl;
            }
            else{
                cout << min(ans1,min(ans2,ans3));
            }
        }
    }
    return 0;
}
