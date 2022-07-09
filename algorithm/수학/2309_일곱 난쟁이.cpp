#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int height[9];
	int sumfor9 = 0; //9 난쟁이의 키의 합
	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		sumfor9 += height[i];
	}
	int sub = sumfor9 - 100;
	vector<int> height7;
	//임의의 2명의 난쟁이의 키의 합이 sub이 되는 경우를 찾는다.
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (height[i] + height[j] == sub)
			{
				for (int k = 0; k < 9; k++)
				{
					if(k != i && k != j)
						height7.push_back(height[k]);
				}
				continue;
			}
		}
	}
	sort(height7.begin(), height7.end());
	for (int i = 0; i < height7.size(); i++)
		cout << height7[i] << endl;

	return 0;
}
