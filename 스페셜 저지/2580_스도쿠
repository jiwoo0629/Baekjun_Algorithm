#include <iostream>
using namespace std;

int main(void)
{
	int sdocu[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> sdocu[i][j];
	}
	cout << endl;

	for (int i = 0; i < 9; i++)
	{
		int count = 0; //빈칸 개수
		int line[9] = { 0, };
		int blank[9] = { 0, };
		for (int j = 0; j < 9; j++)
		{
			if (sdocu[i][j] == 0)
			{
				blank[count] = j;
				count++;
			}
			else
				line[sdocu[i][j] - 1] = sdocu[i][j];
		}
		if (count == 1)
		{
			for (int a = 0; a < 9; a++)
			{
				if (line[a] == 0)
					sdocu[i][blank[0]] = a + 1;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		int count = 0; //빈칸 개수
		int line[9] = { 0, };
		int blank[9] = { 0, };
		for (int j = 0; j < 9; j++)
		{
			if (sdocu[j][i] == 0)
			{
				blank[count] = j;
				count++;
			}
			else
				line[sdocu[j][i] - 1] = sdocu[j][i];
		}
		if (count == 1)
		{
			for (int a = 0; a < 9; a++)
			{
				if (line[a] == 0)
					sdocu[blank[0]][i] = a + 1;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int count = 0; //빈칸 개수
			int line[9] = { 0, };
			int b[9] = { 0, };
			int c[9] = { 0, };
			for (int k = 3 * i; k < 3 * i + 3; k++)
			{
				for (int l = 3 * j; l < 3 * j + 3; l++)
				{
					if (sdocu[k][l] == 0)
					{
						b[count] = k;
						c[count] = l;
						count++;
					}
					else
						line[sdocu[k][l] - 1] = sdocu[k][l];
				}
			}
			if (count == 1)
			{
				for (int a = 0; a < 9; a++)
				{
					if (line[a] == 0)
					{
						sdocu[b[0]][c[0]] = a + 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << sdocu[i][j] << " ";
		cout << endl;
	}

	return 0;
}
