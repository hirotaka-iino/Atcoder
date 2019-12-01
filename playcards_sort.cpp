//playcards_sort

// 何が間違っているのかわからず。。。
#include"bits/stdc++.h"

typedef long long ll;


using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> c(N);

	for(int i = 0; i < N; i++){
		cin >> c[i];
	}

	
	int len_max_sequence = 0;
	vector<int> dp(N);

	for(int i = 0; i < N;i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(c[j] < c[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
		cout << dp[i] << endl;
		len_max_sequence = max(len_max_sequence, dp[i]);
	}

	cout << N - len_max_sequence << endl;
}