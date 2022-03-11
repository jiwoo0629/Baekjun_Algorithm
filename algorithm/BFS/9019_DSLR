#include <iostream>
using namespace std;

string check(int, int); //초기 값을 회전시켜 최종 값으로 만들 수 있는지 확인하는 함수
string divide(int, int); //계속 2배를 했을 때 값이 나오는지 확인
string sub(int, int); //1씩 뺐을 때 값이 나오는지 확인
string divide_sub(int, int); //계속 2배를 하다가 1씩 뺐을 때 값이 나올 때의 명령어 얻기

int main(void)
{
	int test;
	cin >> test;
	cin.ignore();
	string* cmd = new string[test];

	for (int i = 0; i < test; i++)
	{
		int first, second;
		cin >> first >> second;
		string str;

		if (check(first, second) != "")
			str = check(first, second);
		else
		{
			int case1 = divide(first, second).length();
			int case2 = sub(first, second).length();
			int case3 = divide_sub(first, second).length();
			
			if (case1 < case2 && case1 < case3)
			{
				if(case1 > 0)
					str = divide(first, second);
				else
				{
					if (0 < case2 && case2 < case3)
						str = sub(first, second);
					else if (0 < case3 && case3 < case2)
						str = divide_sub(first, second);
				}
			}
			else if (case2 < case1 && case2 < case3)
			{
				if (case2 > 0)
					str = sub(first, second);
				else
				{
					if (0 < case1 && case1 < case3)
						str = divide(first, second);
					else if (0 < case3 && case3 < case1)
						str = divide_sub(first, second);
				}
			}
			else if (case3 < case1 && case3 < case2)
			{
				if (case3 > 0)
					str = divide_sub(first, second);
				else
				{
					if (0 < case1 && case1 < case2)
						str = divide(first, second);
					else if (0 < case2 && case2 < case1)
						str = sub(first, second);
				}
			}
		}
		cmd[i] = str;
	}
	for (int i = 0; i < test; i++)
		cout << cmd[i] << endl;

	delete[]cmd;
	return 0;
}

string check(int first, int second)
{
	int f1 = first / 1000;
	int f2 = (first - f1 * 1000) / 100;
	int f3 = (first - f1 * 1000 - f2 * 100) / 10;
	int f4 = first - f1 * 1000 - f2 * 100 - f3 * 10;
	int s1 = second / 1000;
	int s2 = (second - s1 * 1000) / 100;
	int s3 = (second - s1 * 1000 - s2 * 100) / 10;
	int s4 = second - s1 * 1000 - s2 * 100 - s3 * 10;
	
	int firstarr[4] = { f1, f2, f3, f4 };
	int secondarr[4] = { s1, s2, s3, s4 };
	string str;

	for (int i = 0; i < 4; i++)
	{
		int temp = firstarr[0];
		firstarr[0] = firstarr[3];
		firstarr[3] = firstarr[2];
		firstarr[2] = firstarr[1];
		firstarr[1] = temp;
		str += "R";
		if (firstarr[0] == secondarr[0] && firstarr[1] == secondarr[1] && firstarr[2] == secondarr[2] && firstarr[3] == secondarr[3])
		{
			if (i == 2)
				str = "L";
			return str;
		}
	}
	return "";
}

string divide(int first, int second)
{
	string str;
	if (second % 2 == 1)
		return "";
	while (first != second || first % 10000 != second)
	{
		first *= 2;
		str += "D";
	}
	return str;
}

string sub(int first, int second)
{
	string str;
	while (first != second)
	{
		if (first == 0)
			first = 10000;
		first--;
		str += "S";
	}
	return str;
}

string divide_sub(int first, int second)
{
	string str;
	while (first * 2 < second && (first * 2) % 10000 < second)
	{
		first *= 2;
		str += "D";
	}
	first *= 2;
	str += "D";
	while (first != second)
	{
		if (first == 0)
			first = 10000;
		first--;
		str += "S";
	}
	return str;
}
