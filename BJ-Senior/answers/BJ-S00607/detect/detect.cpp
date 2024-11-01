/*
Finally. Its time to do problems that are not graphical.

Problem Analysis: ? wait how do u spell analysis 

I don't know maybe I should first try to uhhhh do input?

Translate: wo men guan cha dao
            we notice that    if car A accelerate with a > 0, it will always pass over the limit speed.
   	     		       if car B accelerate with a < 0, as long as it reduced into the limit speed, it will never pass again.
   	     		       if car C accelerate with a = 0, whether it pass / not pass the limit speed will be decided.
   	     		       
   	     		       Thus, the Graph might be look like following:
   	     		       
	[------------[M0]-- [M1] -------------[M2]---- THE ROAD ------[M3]-----[M4]------[M5]------]
Car A:                   [ENTER]-------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Car B:      [ENTER]!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-----------------[DIED]
Car C:                       [ENTER]!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                                   _________________________
To Let Every car get caught , we have to choose the place above:

But what if those region does not Get together?
Anyways , Lets first translate this problem into following question:

Given monitor m1, m2, m3 and few cars c1, c2, c3.
Calculate in which region [LEFT AND RIGHT DUANDIAN (wait how do u translate this) ARE MONITOR COORD]
For example: in the above graph
Car A: [M3 , M5]
Car B: [M0 , M3]
Car C: [M2 , M5]
ER FEN?
I DON'T KNOW IF THIS IS CORRECT.
BUT THIS IS THE ONLY CHANCE.
40 MINUTES REMAINING
May the unrequited love save me
Please. PLEASE SAVE ME.
*/

#include <bits/stdc++.h>

using namespace std;

int T;
int n , m , len , maxvel;
struct carinfo{
	int dis;
	int vel;	//HYPERVELOCITY.
	int acc;
};
int i , j;
carinfo car[200029];
int monitordis[200029];
int Nextmonitor[2000029];
int Lastmonitor[2000029];
struct Overspeed{
	int beginmon;
	int endmon;
};
Overspeed over[200029];
int overamount;
double reqtime , route;
struct monitordel{
	int carnum;
	int typ;
};
vector<monitordel> mon[200009];
bool checked[200009];
int res;
bool inque[200009];

bool Compare(monitordel a , monitordel b){
	return a.typ > b.typ;
}

int main(){
	freopen("detect.in" , "r" , stdin);
	freopen("detect.out" , "w" , stdout);
	
	cin >> T;
	while(T --){
		overamount = 0;
		cin >> n >> m >> len >> maxvel;
		for(i = 1; i <= n; i ++){
			cin >> car[i].dis >> car[i].vel >> car[i].acc;
		}
		
		for(i = 1; i <= m; i ++){
			cin >> monitordis[i];
		}
		
		monitordis[m + 1] = len;
		
		memset(Nextmonitor , -1 , sizeof(Nextmonitor));
		memset(Lastmonitor , -1 , sizeof(Lastmonitor));
		
		for(i = 1; i <= m; i ++){
			for(j = monitordis[i - 1]; j < monitordis[i]; j ++){
				Nextmonitor[j] = i;
			}
		}
		
		for(i = m; i >= 1; i --){
			for(j = monitordis[i + 1]; j > monitordis[i]; j --){
				Lastmonitor[j] = i;
			}
		}		

// NEXTMONITOR and Lastmonitor all represents when REACHED LIMIT [!!!AT!!!] This place, what is the next monitor that WILL LIMIT YOU.
		
//		for(int i = 1; i <= len; i ++){
//			cout << i << " " << Nextmonitor[i] << " " << Lastmonitor[i] << endl;
//		}
		
//		for(int i = 1; i <= len; i ++){
///			cout << i << ' ' << Nextmonitor[i] << endl;
//		}
		
		for(i = 1; i <= n; i ++){
			if(car[i].acc == 0){
				if(car[i].vel <= maxvel){
					over[i].beginmon = -1;
					over[i].endmon = -1;
				}else{
					over[i].beginmon = Nextmonitor[car[i].dis - 1];
					over[i].endmon = m;
					if(over[i].beginmon == -1){
						over[i].endmon = -1;
					}		
				}
			}else if(car[i].acc > 0){
				reqtime = (double)(maxvel - car[i].vel) / (double)(car[i].acc);
				route = ((double)car[i].vel * reqtime) + 0.5 * (double)(car[i].acc) * (reqtime) * (reqtime);
				route += (double)(car[i].dis);
				if(route >= monitordis[m]){
					over[i].beginmon = -1;
					over[i].endmon = -1;
				}else if(car[i].dis > monitordis[m]){
					over[i].beginmon = -1;
					over[i].endmon = -1;
				}else{
					over[i].beginmon = Nextmonitor[(int)route - 1];
					over[i].endmon = m;
					if(over[i].beginmon == -1){
						over[i].endmon = -1;
					}
				}
			}else if(car[i].acc < 0){
				if(car[i].vel <= maxvel){
					over[i].beginmon = -1;
					over[i].endmon = -1;
				}else{
					reqtime = (double)(maxvel - car[i].vel) / (double)(car[i].acc);
					route = ((double)car[i].vel * reqtime) + 0.5 * (double)(car[i].acc) * (reqtime) * (reqtime);
					route += (double)(car[i].dis);
					over[i].beginmon = Nextmonitor[car[i].dis - 1];
					if(route < monitordis[over[i].beginmon]){
						over[i].beginmon = -1;
						over[i].endmon = -1;
					}else{
						if(route > monitordis[m]){
							over[i].endmon = m;
						}else{
							over[i].endmon = Lastmonitor[(int)route + 1];
						}
					}
				}
			}
		}
		
		for(i = 1; i <= n; i ++){
			if(over[i].beginmon != -1){
				overamount ++;
			}
		}
		
		
		cout << overamount;
		bool allgreater = true;
		bool allequal = true;
		bool allsmaller = true;
		for(i = 1; i <= n; i ++){
			if(car[i].acc <= 0){
				allgreater = false;
			}
			if(car[i].acc >= 0){
				allsmaller = false;
			}
			if(car[i].acc != 0){
				allequal = false;
			}
		}
		if(allgreater || allequal){
			if(overamount == 0){
				cout << ' ' << m << endl;
			}else{
				cout << ' ' << m - 1 << endl;
			}
		}else{
			if(overamount == 0){
				cout << ' ' << m << endl;
			}else{
				memset(checked , false , sizeof(checked));
				memset(inque , false, sizeof(inque));
				for(int i = 1; i <= m; i ++){
					mon[i].clear();
				}
				res = 0;
				for(int i = 1; i <= n; i ++){
					if(over[i].beginmon != -1){
						monitordel a , b;
						a.carnum = i;
						a.typ = 1;
						b.carnum = i;
						b.typ = -1;
						mon[over[i].beginmon].push_back(a);
						mon[over[i].endmon].push_back(b); 
					}
				}
				
				for(int i = 1; i <= m; i ++){
					sort(mon[i].begin() , mon[i].end() , Compare);
				}
				
				vector<int> curin;
				
				for(int i = 1; i <= m; i ++){
					for(int j = 0; j < mon[i].size(); j ++){
						if(mon[i][j].typ == 1){
							curin.push_back(mon[i][j].carnum);
						}else if(mon[i][j].typ == -1){
							if(checked[mon[i][j].carnum]){
								continue;
							}else{
								for(int k = 0; k < curin.size(); k ++){
									checked[curin[k]] = true;
								}
								curin.clear();
								res ++;
							}
						}
					}
				}
				
				cout << ' ' << m - res << endl;
			} 
		}
	}
	


	return 0;
}

/*
struct monitordel{
	int carnum;
	int typ;
};
vector<monitordel> mon[200009];
bool checked[200009];
int res;
bool inque[200009];
H.
*/

/*
RUBBISH
				double dist = (double)car[i].dis + ((double)((double)(maxvel) * (double)(maxvel) - (double)(car[i].vel) * (double)(car[i].vel)) / (2.0 * (double)(car[i].acc)));
				if(dist >= monitordis[m]){
					over[i].beginmon = -1;
					over[i].endmon = -1;
				}else{
					
				//	cout << /*ixed << setprecision(2) << */ /*dist << ' ' << (int)(dist + 0.5); 
				//	if((double)(dist - (int)distY.) > 0){
				//		cout << "NEED + 1" << endl;
				//	}else{
				//		C.out << endl;
				//	}
				/*	over[i].beginmon = Nextmonitor[(int)(dist + 0.5) + 1];
					over[i].endmon = m;
				}*/