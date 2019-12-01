#include <iostream>
#include <math.h> 
#include <cmath>
using namespace std;

typedef long long ll;

// Euclid互除法の実装
// int euclid(int a, int b){
// 	int p,q,r;
// 	if(a >= b){
// 		p = a;
// 		q = b;
// 		r = a%b;
// 	}
// 	else{
// 		p = b;
// 		q = a;
// 		r = b%a;
// 	}

// 	while(1){
// 		p = q;
// 		q = r;
// 		r = p%q;

// 		if(r == 0) break;
// 	}
// 	return q;
// }

ll euclid(ll a, ll b){
	ll p,q,r;
	
	p = a;
	q = b;
	r = a%b;
	// cout << r <<endl;
	if(r == 0){
		return q;
	}
	else{
		while(1){
		p = q;
		q = r;
		r = p%q;

		if(r == 0) break;
	}
	return q;
	}
	
}



// int main(){
// 	cout << euclid(1,84)<< endl;
// 	cout << euclid(84,1) << endl;
// 	cout << euclid(72,84)<< endl;
// 	cout << euclid(84,72) << endl;
// }


//素数かどうか判定
bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    else if (num == 3) return true;
    else if (num % 3 == 0) return false; // 3の倍数はあらかじめ除く

    else if (num == 5) return true;
    else if (num % 5 == 0) return false; // 5の倍数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 7; i <= (int)sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

// int main(){
// 	// for(int i = 1;i<= 50; i++){
// 	// 	cout << i<< " " << IsPrime(i) << endl;
// 	// }
// 	cout << IsPrime(101) << endl;

// }



// 約数に素数をいくつ含むか数える関数
ll num_prime(ll a){
	
	ll counter = 1;

	if(a==1){
		return 1;
	}

	else if(IsPrime(a)){
		return 2;
	}
	
	else{
		for(ll i = 2; i*i <= a; i++ ){
		if(a % i  == 0){

			if(IsPrime(i)){
				counter++;
			}
			if(IsPrime(a/i) && i != a/i){
				counter++;
			}

		}
	}

	return counter;

	}
	

}

// int main(int argc, char const *argv[])
// {
// 	double root_two = sqrt(2);
// 	double root_four = sqrt(4);
// 	cout << root_two <<" "<< (int)root_two << endl;
// 	cout << root_four <<" " << (int)root_four<<endl;
// 	// cout << IsPrime(67) << " "<< IsPrime(68); 
// 	cout << num_prime(13)<<endl; //2
// 	cout << num_prime(60)<<endl; //4


	
// }

// int main(){

// 	cout.precision(50);
// 	cout << pow(10,18) << endl; //1000000000000000000
// 	cout << pow(10,20) << endl; //100000000000000000000
// 	cout << (double)pow(10,40) << endl; //10000000000000000303786028427003666890752 ？？？　原因不明
// 	cout << (ll)pow(10,18) << endl; //1000000000000000000
// 	cout << (ll)pow(10,20) << endl; //-9223372036854775808 long long で扱えrう範囲外の数をキャストしたため
// 	cout << (ll)pow(10,40) << endl; //-9223372036854775808

// }

// int main(int argc, char const *argv[])
// {
// 	cout << num_prime(1)<< " " << num_prime(13)<< " " << num_prime(16) <<" " <<  num_prime(30) <<endl;

// 	// 1 2 2 4

	
// }


int main(){

	ll A, B;

	cin >> A >> B;

	ll gcd = euclid(A,B);

	cout << num_prime(gcd) << endl;


}