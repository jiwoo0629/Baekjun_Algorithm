#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int n, east, west, south, north;
double per = 0;

void repeatPermutation(vector<char>, vector<char>, int);
bool simple(vector<char>);
int main(void)
{
	cin >> n >> east >> west >> south >> north;

	vector<char> vec = {'e', 'w', 's', 'n'};
	vector<char> perm(n);

	repeatPermutation(vec, perm, 0);
	cout << per << endl;

	return 0;
}

//중복순열
void repeatPermutation(vector<char> vec, vector<char> perm, int depth)
{
	if (depth == perm.size()) {
		if (simple(perm) == true) {
			double sum = 1;
			for (int i = 0; i < perm.size(); i++) {
				if (perm[i] == 'e')
					sum *= ((double)east / 100);
				else if (perm[i] == 'w')
					sum *= ((double)west / 100);
				else if (perm[i] == 's')
					sum *= ((double)south / 100);
				else if (perm[i] == 'n')
					sum *= ((double)north / 100);
			}
			per += sum;
		}
		
		return;
	}
	
	for (int i = 0; i < vec.size(); i++) {
		perm[depth] = vec[i];
		repeatPermutation(vec, perm, depth + 1);
	}
}

bool simple(vector<char> perm)
{
	int east_count = 0, west_count = 0, south_count = 0, north_count = 0;
	for (int i = 0; i < perm.size(); i++) {
		if (perm[i] == 'e' && east != 0)
			east_count++;
		else if (perm[i] == 'w' && west != 0)
			west_count++;
		else if (perm[i] == 's' && south != 0)
			south_count++;
		else if (perm[i] == 'n' && north != 0)
			north_count++;
	}
	if (east_count == west_count == south_count == north_count)
		return false;

	for (int i = 0; i < perm.size() - 1; i++) {
		if ((perm[i] == 'e' && perm[i + 1] == 'w') || (perm[i] == 'w' && perm[i + 1] == 'e') || (perm[i] == 's' && perm[i + 1] == 'n') || (perm[i] == 'n' && perm[i + 1] == 's'))
			return false;
	}

	return true;
}
