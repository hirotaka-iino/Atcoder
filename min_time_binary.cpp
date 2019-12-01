#include"bits/stdc++.h"
#include "prettyprint.hpp"

using namespace std;

#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define all(x) x.begin(),x.end()

typedef long long ll;

// i日目までに作れる商品数
long product_num(vector<long> v, long i){
	long size = v.size();
	long total_product = 0;
	rep(i,size){
		total_product += i / v[i];
	}

	return total_product;
}

long minTime(vector<long> machines, long goal) {
	long min = *min_element(all(machines));
	double right_day = (goal*min);
	double left_day = 1;
	double midle_day = floor((right_day + left_day) / 2 );
	long midle_pro = product_num(machines, midle_day); 
	long ans = 0;

	while(midle_pro != goal){
		cout << left_day << " " << right_day << endl;
		cout << midle_pro << endl;

		if(right_day -left_day == 1){
			if(product_num(machines,left_day) == goal)	ans = left_day;
			else if(product_num(machines,right_day) == goal)	ans = right_day;
			break;
		}


		else if(midle_pro > goal){
			right_day = midle_day;
			midle_day = floor((right_day + left_day) / 2 );
			midle_pro = product_num(machines, midle_day);
			cout << "Hi1" << endl;
			
		}

		else if(midle_pro < goal){
			left_day = midle_day;
			midle_day = floor((right_day + left_day) / 2 );
			midle_pro = product_num(machines, midle_day);
			cout << "Hi2" << endl;
			
		}

		

	}

	if(ans == 0 && right_day -left_day != 1){
		cout << "Hi" << endl;
		for(int i = midle_day; i > 0; i--){
			if(product_num(machines,i) != goal){
				ans = i;
				break;
			}
		}
	}


	return ans;

}

int main(){
	// vector<long> v = {1,3,4};
	// cout << minTime(v,10) << endl;

	vector<long> v = {4,5,6};
	cout << minTime(v,12) << endl;

	v = {2,3};
	cout << minTime(v,5) << endl;

}




