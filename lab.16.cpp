#include <iostream>
#include <conio.h>
using namespace std;

bool test(char ch, const char *keys, unsigned int size)
{
	for (int i = 0; i<size; i++)
		if (keys[i] == ch) return true;
	return false;
}
int getNumber()
{
	char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	string n;
	char ch;

	while ((ch = _getch()) != '\r')
		//if (ch == 8) break;//enter
		if (test(ch, numbers, 10))
		{
			n += ch;
			cout << ch;
		}

	cout << endl;
	return atoi(n.c_str());
}
int main()
{
	cout << "Enter the size: ";
	int size, min_3, max_4;
	size = getNumber();
	if ((size < 4) || (size > 200))
	{
		cout << "Size should be more then 4 and less then 200. Try again" << endl;
		system("pause");
		return 1;
	}
	int * mass = new int[size];
	cout << "Enter your array: " << endl;
	for (int i = 0; i < size; i++)
	{
		mass[i] = getNumber();
	}
	int tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
			}
		}
	}
	cout << "Sorted arrray: ";
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	int count = 1;
	for (int i = 0; i < size - 1; i++)
	{
		if (mass[i] < mass[i + 1])
		{
			count = count + 1;
		}
	}
	int * mass2 = new int[count];
	if (count == 1)
	{
		mass2[0] = mass[0];
	}
	int k = mass[0];
	for (int j = 0; j < count - 1; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (k < mass[i + 1])
			{
				mass2[j] = mass[i];
				mass2[j + 1] = mass[i + 1];
				k = mass[i + 1];
				break;
			}
		}
	}
	delete[] mass;
	cout << "Array without reply: ";
	for (int i = 0; i < count; i++)
	{
		cout << mass2[i] << " ";
	}
	cout << endl;
	if (count > 3)
	{
		min_3 = mass2[2];
		max_4 = mass2[count - 4];
		cout << "Third minimum " << min_3 << endl;
		cout << "Fourth maximum " << max_4 << endl;
	}
	else
	{
		cout << "Enter up to 4 different numbers. Try again" << endl;
		system("pause");
		return 1;
	}
	delete[] mass2;
	system("pause");
	return 0;
}
