#include<iostream>
using namespace std;

#include<string>

int main() {
	int N = 0;
	int M = 0;
		cin >> N;
		cin >> M;
	int *array = new int[N];
	for (int i = 1; i <= N; i++){
		cin >> array[i];
	}
	char ch;
	int A;
	int B;
	while (M--){
		cin >> ch >> A >> B;
		if (ch == 'U'){
			array[A - 1] = B;
		}
		if (ch == 'Q'){
			int max = array[A - 1];
			for (int i = A; i<B; i++){
				if (array[i]>max){
					max = array[i];
				}
			}
			cout << max << endl;
		}
	}
	return 0;
}
