#include <iostream>
#include <vector>
using namespace std;

bool Countable = false;
bool isPrime(int n); //�Ҽ� �Ǻ�
void Combination(vector<int>, vector<int>, int, int, int); //�ߺ����� 'nH4'

int main(void) {
	int num;
	cin >> num;

	vector<int> v;
	for (int i = 1; i < num; i++) {
		if (isPrime(i) == true)
			v.push_back(i);
	}
	//�Ҽ��� �ּڰ��� 2�ε� 4���� ���� 8���� num�� ���� ���, ��� �Ұ�
	if (num < 8) {
		cout << "-1" << endl;
		return 0;
	}

	vector<int> comb(4);
	Combination(v, comb, num, 0, 0); //�Ҽ��� ��� �ִ� vector �߿��� �ߺ����� 'nH4'
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