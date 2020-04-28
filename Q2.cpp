// s: 1 2 3 4 5 6 7 8 9 10 10^12
// -= ?

// 9 -> 6

// 1: 3 6 9 12
// 2: 7 14
// 3: 2 4 6 8 10 12

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	unsigned long long T, N, D, x, S, S_old;
	vector<unsigned long long> X;

	// Number of test cases
	cin >> T;


	for (int t = 1; t <= T; t++) {
		// N, D
		cin >> N >> D;

		// X
		X.clear();
		for (int n = 0; n < N; n++) {
			cin >> x;
			X.push_back(x);
		}

		// result
		bool fail;

		for (
			unsigned long long s = floor(D / X[0]) * X[0];
			s > 0;
			) {
			S = s;
			// Check if  `S` is true for all buses
			fail = false;
			for (int i = 0; i < N; i++) {
				S_old = S; // 9
				S = ceil((double)S / X[i]) * X[i]; // 14
				if (S > D) {
					fail = true;

					/*
					s = min
					(
						s - X[0],
						(unsigned long long)(floor((double)S_old / X[i]) * X[i])
					);
					break;
					*/


					// update `s`, backware from failure
					S = S_old;
					for (int j = i; j >= 0; j--) {
						S = floor((double)S / X[j]) * X[j];
					}
					s = S;
					break;
				}
			}
			if (fail == false) {
				cout << "Case #" << t << ": " << s << endl;
				break;
			}
		}

	}
}


