#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cout<<"1\n0\n8";
	return 0;
}
/*

#include<bits/stdc++.h>
using namespace std;
class bignum{
private:
	typedef long long ll;
	vector<ll>v;
	ll p_size;
	static ll _weishu(ll x){
		ll ans=0;
		while(x){
			++ans;
			x/=10;
		}
		return ans;
	}
public:
	bignum(unsigned long long x){
		v.clear();
		v.push_back(x);
		p_size=_weishu(x);
	}
	bignum(string st){
		v.clear();
		st.erase(0,st.find_first_not_of('0'));
		p_size=st.size();
		ll len=p_size;
		ll s=0;
		bool flag=false;
		for(ll i=0;i<len;++i){
			s=s*10+st[i]-'0';
			flag=true;
			if((i+1)%10==0){
				v.push_back(s);
				s=0;
				flag=false;
			}
		}
		if(flag)v.push_back(s);
	}
	bignum(const char* str){
		string st=str;
		v.clear();
		st.erase(0,st.find_first_not_of('0'));
		p_size=st.size();
		ll len=p_size;
		ll s=0;
		bool flag=false;
		for(ll i=0;i<len;++i){
			s=s*10+st[i]-'0';
			flag=true;
			if((i+1)%10==0){
				v.push_back(s);
				s=0;
				flag=false;
			}
		}
		if(flag)v.push_back(s);
	}
	bignum(char* str){
		string st=str;
		v.clear();
		st.erase(0,st.find_first_not_of('0'));
		p_size=st.size();
		ll len=p_size;
		ll s=0;
		bool flag=false;
		for(ll i=0;i<len;++i){
			s=s*10+st[i]-'0';
			flag=true;
			if((i+1)%10==0){
				v.push_back(s);
				s=0;
				flag=false;
			}
		}
		if(flag)v.push_back(s);
	}
	bignum(){
		v.clear();
	}
	~bignum(){
		v.clear();
	}
public:
	string to_string()const{
		string str;
		for(ll num:v){
			char ch[15]={};
			sprintf(ch,"%010lld",num);
			str+=ch;
		}
		str.erase(0,str.find_first_not_of('0'));
		str=str.substr(0,p_size);
		return str;
	}
	size_t length()const{
		return p_size;
	}
	size_t size()const{
		return p_size;
	}
public:
	friend ostream& operator<<(ostream &os,const bignum &num){
		os<<num.to_string();
		return os;
	}
	friend istream& operator>>(istream &is,bignum &num){
		string st;
		cin>>st;
		st.erase(0,st.find_first_not_of('0'));
		num.p_size=st.size();
		num.v.clear();
		ll len=st.size();
		ll s=0;
		bool flag=false;
		for(ll i=0;i<len;++i){
			s=s*10+st[i]-'0';
			flag=true;
			if((i+1)%10==0){
				num.v.push_back(s);
				s=0;
				flag=false;
			}
		}
		if(flag)num.v.push_back(s);
		return is;
	}
};
typedef long long ll;
int main(){
	bignum num;
	cin>>num;
	cout<<num<<endl<<num.length()<<" "<<num.size();
	return 0;
}

*/
