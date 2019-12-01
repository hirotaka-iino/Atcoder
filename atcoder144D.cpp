#include"bits/stdc++.h"
// #include "prettyprint.hpp"

using namespace std;

#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define all(x) x.begin(),x.end()

typedef long long ll;

int main(){

	long double a,b,x;
	cin >> a >> b >> x;

	long double pi = 4*atan(1); 

	// cout << pi << endl;

	long double inner = a/(2*b) + (x/(2*a*pow(b,2))) + (pow(x,2) /(2*pow(a,3) *pow(b,3))) ;

	long double sieta = atan(inner);

	long double ans = (180.0000/pi) * sieta; 

	// long double sieta = (180/pi)* atan( 2* (pow(a,2)*b - x) /pow(a,3)) ;

	// cout << pow(a,2)*b - x << endl;
	// cout << (pow(a,2)*b - x) /pow(a,3) << endl;

	

	cout << 90- ans << endl;

	return 0;
}	 