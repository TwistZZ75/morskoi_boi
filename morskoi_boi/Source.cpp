#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<conio.h>
#include<clocale>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
#include<cmath>
#include<stdio.h>
#include<windows.h>

int Pole[10][10];
int x, y;
/*
можно сделать цикл в котором x и y будут <tip и будут уменьшать или увеличивать координаты на каждой иттерации в зависимости от выбранного направления
и присваивать на каждой иттерации Pole[x][y] значение 1
что-то вроде
for(x=0;x<tip;)
{
  for(y=0;y<tip;)
  {
  if(napravlenie==L)
  {
  Pole[x][y]=1;
  x--;
  }
  }
}
*/

int rasstanovka()
{
	int tip;
	char pologenie;
	char napravlenie;
	cout << "Выберите тип корабля: ";
	cin >> tip;
	/*cout << "Выберите начальную координату корабля: ";
	cin >> x >> y;
	cout << "Выберите его положение(вертикально-V/горизонтально-G): ";
	cin >> pologenie;
	if(pologenie=='G')
	{
	cout << "Выберите направление(лево-L/право-R): ";
	cin >> napravlenie;
	}
	if(pologenie=='V')
	{
	 cout << "Выберите направление(вверх-U/вниз-D): ";
	cin >> napravlenie;
	}*/

	if (tip == 1)
	{
		do
		{
			cout << "Установите координаты:\n ";
			cin >> x >> y;
			x = x - 1;
			y = y - 1;
			if (x < 10 && y < 10 && x>0 && y>0)
			{
				Pole[x][y] = 1;
			}
			else
			{
				cout << "Введены неверные координаты\n";
			}
		} while (Pole[x][y] != 1);
	}
	if (tip > 1 && tip <= 4)
	{
		cout << "Выберите начальную координату корабля: ";
		cin >> x >> y;
		x = x - 1;
		y = y - 1;
		cout << "Выберите его положение(вертикально-V/горизонтально-G): ";
		cin >> pologenie;
		if (pologenie == 'G' || pologenie == 'g')
		{
			cout << "Выберите направление(лево-L/право-R): ";
			cin >> napravlenie;
			if (napravlenie == 'L' || napravlenie == 'l')
			{
				for (int i = 0; i < tip; i++)
				{
					Pole[x][y] = 1;
					x--;
				}
			}
			if (napravlenie == 'R' || napravlenie == 'r')
			{
				for (int i = 0; i < tip; i++)
				{
					Pole[x][y] = 1;
					x++;
				}
			}
		}
		if (pologenie == 'V' || pologenie == 'v')
		{
			cout << "Выберите направление(вверх-U/вниз-D): ";
			cin >> napravlenie;
			if (napravlenie == 'U' || napravlenie == 'u')
			{
				for (int i = 0; i < tip; i++)
				{
					Pole[x][y] = 1;
					y--;
				}
			}
			if (napravlenie == 'D' || napravlenie == 'd')
			{
				for (int i = 0; i < tip; i++)
				{
					Pole[x][y] = 1;
					y++;
				}
			}
		}
	}
	return Pole[x][y];
}

void poleigroka()
{
	cout << "    a    b    c    d    e    f    g    h    i    j\n";
	cout << "  + - + - + - + - + - + - + - + - + - + - + - + - +\n";
	for (y = 0; y < 10; y++)
	{
		cout << y + 1 << " ";
		for (x = 0; x < 10; x++)
		{
			if (!(Pole[x][y]))
			{
				cout << " |";
			}
			if (Pole[x][y] == 0)//если в ячейке нет ничего
			{
				//cout << " ";
				cout << " |";
				cout << " ";
			}
			if (Pole[x][y] == 1)//если в ячейке есть корабль
			{
				cout << " |O| ";
			}
			if (Pole[x][y] == 2)//если в корабль в данной ячейке попали
			{
				cout << " |X| ";
			}
			if (Pole[x][y] == 3)//выстрел пришёлся мимо
			{
				cout << " |-| ";
			}
			if (x == 10)
			{
				cout << "|";
			}
		}
		cout << endl;
		cout << "  + - + - + - + - + - + - + - + - + - + - + - + - +\n";
	}
}
void polekompa()
{
	cout << "    a    b    c    d    e    f    g    h    i    j\n";
	cout << "  + - + - + - + - + - + - + - + - + - + - + - + - +\n";
	for (y = 0; y < 10; y++)
	{
		cout << y + 1 << " ";
		for (x = 0; x < 10; x++)
		{
			if (!(Pole[x][y]))
			{
				cout << " |";
			}
			if (Pole[x][y] == 0)//если в ячейке нет ничего
			{
				//cout << " ";
				cout << " |";
				cout << " ";
			}
			if (Pole[x][y] == 1)//если в ячейке есть корабль
			{
				cout << " | | ";
			}
			if (Pole[x][y] == 2)//если в корабль в данной ячейке попали
			{
				cout << " |X| ";
			}
			if (Pole[x][y] == 3)//выстрел пришёлся мимо
			{
				cout << " |-| ";
			}
			if (x == 10)
			{
				cout << "|";
			}
		}
		cout << endl;
		cout << "  + - + - + - + - + - + - + - + - + - + - + - + - +\n";
	}
}
/*int moihod()
{

}
int hodkomp()
{

}
int proverkapobedi()
{

}*/
/*int proverkapopadaniya()
{

}*/

/*int autorasstanovka()
{

}*/

int main()
{
	int l;
	setlocale(LC_CTYPE, "rus");
	cout << "Хотите поставить корабль?\n ";
	cin >> l;
	if (l == 1)
	{
		rasstanovka();
	}
	else
	{
		Pole[x][y] = 0;
	}
	//int proverkapopadaniya();
	cout << "Pole igroka: \n";
	poleigroka();
	cout << "\n";
	cout << "Pole kompa: \n";
	polekompa();
}