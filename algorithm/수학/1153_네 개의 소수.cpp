#include <iostream>
#include <vector>
using namespace std;

bool Countable = false;
bool isPrime(int n); //소수 판별
void Combination(vector<int>, vector<int>, int, int, int); //중복조합 'nH4'

int main(void) {
	int num;
	cin >> num;

	vector<int> v;
	for (int i = 1; i < num; i++) {
		if (isPrime(i) == true)
			v.push_back(i);
	}
	//소수의 최솟값이 2인데 4개의 합인 8보다 num이 작을 경우, 계산 불가
	if (num < 8) {
		cout << "-1" << endl;
		return 0;
	}

	vector<int> comb(4);
	Combination(v, comb, num, 0, 0); //소수를 담고 있는 vector 중에서 중복조합 'nH4'
	if (Countable == false)
		cout << "-1" << endl;
	
	return 0;
}

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void Combination(vector<int> v, vector<int> comb, int num, int index, int depth)
{
	if (depth == comb.size()) {
		int sum = 0;
		for (int i = 0; i < comb.size(); i++) {
			sum += comb[i];
		}
		if (sum == num) {
			for (int i = 0; i < comb.size(); i++)
				cout << comb[i] << " ";
			cout << endl;
			Countable = true;
		}
	}
	else if (Countable == true)
		return;
	else {
		for (int i = index; i < v.size(); i++) {
			comb[depth] = v[i];
			Combination(v, comb, num, i, depth + 1);
		}		
	}
}