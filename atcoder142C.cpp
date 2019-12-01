#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> rev(N);

	for(int i =0; i < N; i++){
		cin >> A[i];
	}


	for (int i = 0; i < N; i++){
		rev[A[i] -1] = i + 1;
	}

	for(int i = 0; i < N; i++){
		cout << rev[i] << " ";
	}

	cout << endl;
	

}