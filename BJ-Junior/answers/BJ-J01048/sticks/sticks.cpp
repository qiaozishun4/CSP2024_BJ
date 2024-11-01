#include <bits/stdc++.h>
using namespace std;
string str;
string minn="999999999999999";
pair<int,int> a[101]={{0,0},{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6},{0,6}};
bool compare(string a,string b){
    if (a.size()<b.size()){
        return 1;
    }
    else if (a.size()>b.size()){
        return 0;
    }
    return a<b;
}
void dfs(int t){
    for (int i=1;i<=10;i++){
        if (t>=a[i].second){
            t-=a[i].second;
 //               cout<<"c:"<<a[i].first+'0'<<endl;
            str.push_back(a[i].first+'0');
 //           cout<<"s:"<<str<<endl;
//            dfs(t);
            if (t==0){
                if (str.front()!='0'){
                    if (compare(str,minn)){
                        minn=str;
                    }
                }
            }
            else{
                dfs(t);
            }
            t+=a[i].second;
            str.pop_back();
        }
    }
}
int n,x;
bool cmp(pair<int,int> a,pair<int,int> b){
    if (a.second!=b.second){
        return a.second>b.second;
    }
    else{
        return a.first<b.first;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    sort(a+1,a+10+1,cmp);
    for (int i=1;i<=n;i++){
        minn="999999999999999";
        str.clear();
        cin>>x;
        if (x<2){
            cout<<"-1";
        }
        else if (x<=20){
            dfs(x);
            cout<<minn;
        }
        else if (x%7==0){
            string s=string(x/7,'8');
            cout<<s;
        }
        else if (x%7==1){
            string s="10"+string(x/7-1,'8');
            cout<<s;
        }
        else if (x%7==2){
            string s="1"+string(x/7,'8');
            cout<<s;
        }
        else if (x%7==5){
            string s="2"+string(x/7,'8');
            cout<<s;
        }
        else if (x%7==6){
            string s="6"+string(x/7,'8');
            cout<<s;
        }
        else if (x%7==3){
            string s="7"+string(x/7,'8');
            cout<<s;
        }
        else{
            dfs(x);
            if (minn=="999999999999999"){
                cout<<-1;
            }
            else{
                cout<<minn;
            }
        }
        if (i!=n){
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}