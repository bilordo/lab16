Inform.16lab.speedsort.cpp
СВОЙСТВА
ИСТОРИЯ
 Inform.16lab.speedsort.cpp
Параметры общего доступа
Без общего доступа
Общая информация
Тип
C++
Размер
1 КБ (1 162 байта)
Использовано
1 КБ (1 162 байта)
Расположение
16 lab
Владелец
я
Изменено
мной 14:38
Открыто
мной 14:39
Создано
14:38 в приложении Google Drive Web
Описание
Добавить описание
Права на загрузку
Читателям разрешено скачивать файл

#include <iostream>
#include <conio.h>
using namespace std;
int a[100];
void quickSort(int l, int r)
{
	int x = a[l + (r - l) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i<r)
		quickSort(i, r);

	if (l<j)
		quickSort(l, j);
}
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
	int n;
	cout << "Enter size of array: ";
	n = getNumber();
	cout << "Enter array: " << endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = getNumber();
	}
	cout << "Your array: " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	quickSort(0, n - 1);
	cout << "Sorted array: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
