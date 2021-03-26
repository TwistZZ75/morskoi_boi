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
int x, y;//x-столбик y-строчка
void poleigroka();
void polekompa();
//теперь она работает,но не полностью,по диагонали корабли ставятся всё так же без ограничений,но возможно нужны просто доп условия ниже
int provarkarasstanovki(int tip)
{
	int k = 1;//флаг на ошибку расстановки
	if (tip == 1)
	{
		//для клетки а1
		if (x == 0 and y == 0)
		{
			for (int stolbec = x; stolbec < x + 2; stolbec++)
			{
				for (int stroka = y; stroka < y + 2; stroka++)
				{
					if (Pole[stolbec][stroka] == 0)
					{
						k++;
					}
					else
					{
						k = 0;
						break;
					}
				}
				if (k == 0)
				{
					break;
				}
			}
		}
		if (x == 10 and y == 0)
		{
			for (int stolbec = x; stolbec < x - 2; stolbec++)
			{
				for (int stroka = y; stroka < y + 2; stroka++)
				{
					if (Pole[stolbec][stroka] == 0)
					{
						k++;
					}
					else
					{
						k = 0;
						break;
					}
				}
				if (k == 0)
				{
					break;
				}
			}
		}
		if (x == 0 and y == 10)
		{
			for (int stolbec = x; stolbec < x + 2; stolbec++)
			{
				for (int stroka = y; stroka < y - 2; stroka++)
				{
					if (Pole[stolbec][stroka] == 0)
					{
						k++;
					}
					else
					{
						k = 0;
						break;
					}
				}
				if (k == 0)
				{
					break;
				}
			}
		}
		if (x == 10 and y == 10)
		{
			for (int stolbec = x; stolbec < x - 2; stolbec++)
			{
				for (int stroka = y; stroka < y - 2; stroka++)
				{
					if (Pole[stolbec][stroka] == 0)
					{
						k++;
					}
					else
					{
						k = 0;
						break;
					}
				}
				if (k == 0)
				{
					break;
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (x == i && y >= 0 && y < 10)
			{
				for (int stolbec = x - 1; stolbec < x + 2; stolbec++)
				{
					for (int stroka = y - 1; stroka < y + 2; stroka++)
					{
						if (Pole[stolbec][stroka] == 0)
						{
							k++;
						}
						else
						{
							k = 0;
							break;
						}
					}
					if (k == 0)
					{
						break;
					}
				}
			}
		}
	}
	
	return k;
}
int proverkarasstanovki_vertical(int tip, char napravlenie)
{
	int k = 1;
	if (tip >= 2)
	{
		//для клетки а1
		if (x == 0 and y == 0)
		{
			for (int stolbec = x; stolbec < x + tip; stolbec++)
			{
				for (int stroka = y; stroka < y + tip; stroka++)
				{
					if (Pole[stolbec][stroka] == 0)
					{
						k++;
					}
					else
					{
						k = 0;
						break;
					}
				}
				if (k == 0)
				{
					break;
				}
			}
		}
		if (x == 10 and y == 0)
		{
			for (int stolbec = x; stolbec < x - tip; stolbec++)
			{
				for (int stroka = y; stroka < y + tip + 1; stroka++)
				{
					if (Pole[stolbec][stroka] == 0)
					{
						k++;
					}
					else
					{
						k = 0;
						break;
					}
				}
				if (k == 0)
				{
					break;
				}
			}
		}
		if (x == 0 and y == 10)
		{
			for (int stolbec = x; stolbec < x + tip; stolbec++)
			{
				for (int stroka = y; stroka < y - tip - 1; stroka++)
				{
					if (Pole[stolbec][stroka] == 0)
					{
						k++;
					}
					else
					{
						k = 0;
						break;
					}
				}
				if (k == 0)
				{
					break;
				}
			}
		}
		if (x == 10 and y == 10)
		{
			for (int stolbec = x; stolbec < x - tip; stolbec++)
			{
				for (int stroka = y; stroka < y - tip - 1; stroka++)
				{
					if (Pole[stolbec][stroka] == 0)
					{
						k++;
					}
					else
					{
						k = 0;
						break;
					}
				}
				if (k == 0)
				{
					break;
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (x == i && y > 0 && y < 10)
			{
				for (int stolbec = x; stolbec < x + tip; stolbec++)
				{
					if (napravlenie == 'D' || napravlenie == 'd')
					{
						for (int stroka = y; stroka < y + tip; stroka++)
						{
							if (Pole[stolbec][stroka] == 0)
							{
								k++;
							}
							else
							{
								k = 0;
								break;
							}
						}
						if (k == 0)
						{
							break;
						}
					}
					else if (napravlenie == 'U' || napravlenie == 'u')
					{
						for (int stroka = y; stroka < y - tip; stroka++)
						{
							if (Pole[stolbec][stroka] == 0)
							{
								k++;
							}
							else
							{
								k = 0;
								break;
							}
						}
						if (k == 0)
						{
							break;
						}
					}
				}
			}
		}
	}
	return k;
}
int provarkarasstanovki_gorizontal(int tip, char napravlenie)
{
	int k=0;
	return k;
}

int rasstanovka()
{
	int tip;
	char pologenie;
	char napravlenie;
	int q;//переменная в которой будет изменяться у
	int m = 4, n = 3, b = 2, v = 1;
	int o = 10;//общее количество кораблей
	do
	{
		cout << "Выберите тип корабля:\nОднопалубный:" << m << "\nДвухпалубный:" << n << "\nТрехпалубный:" << b << "\nЧетырехпалубный:" << v << "\n";
		cin >> tip;
		if (tip == 1)
		{
			cout << "Выбран тип корабля:\nОднопалубный:" << m << "\n";
			do
			{
				cout << "Установите столбец:\n ";
				cin >> x;
				cout << "Установите строку:\n ";
				cin >> y;
				x = x - 1;
				y = y - 1;
				if (x < 10 && y < 10 && x >= 0 && y >= 0 && provarkarasstanovki(tip) != 0)
				{
					Pole[x][y] = 1;
				}
				else if (provarkarasstanovki(tip) == 0)
				{
					cout << "\nСюда нельзя поставить корабль!\n";
					Pole[x][y] = 0;
				}
				else if (x > 10 && y > 10 && x <= 0 && y <= 0)
				{
					cout << "Введены неверные координаты\n";
				}

			} while (Pole[x][y] != 1);
			m--;
			o--;
		}
		//if
		if (tip > 1 && tip <= 4)
		{
			do
			{
				//

				cout << "Выберите начальную координату корабля: ";
				cin >> x >> y;
				x = x - 1;
				y = y - 1;
				q = y;
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
							if (provarkarasstanovki_gorizontal(tip, napravlenie) != 0)
							{
								Pole[x][y] = 1;
								x--;
							}
							else
							{
								cout << "Неверно выбраны координаты!";
								Pole[x][y] = 0;
							}
						}
					}
					if (napravlenie == 'R' || napravlenie == 'r')
					{
						for (int i = 0; i < tip; i++)
						{
							if (provarkarasstanovki_gorizontal(tip, napravlenie) != 0)
							{
								Pole[x][y] = 1;
								x++;
							}
							else
							{
								cout << "Неверно выбраны координаты!";
								Pole[x][y] = 0;
							}
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
							if (proverkarasstanovki_vertical(tip, napravlenie) != 0)
							{
								Pole[x][y] = 1;
								y--;
							}
							else
							{
								cout << "Неверно выбраны координаты!";
								Pole[x][y] = 0;
							}
						}
					}
					if (napravlenie == 'D' || napravlenie == 'd')
					{
						for (int i = 0; i < tip; i++)
						{
							if (proverkarasstanovki_vertical(tip, napravlenie) != 0)
							{
								/*
								можно ввести переменную запоминающую значение у и менять ее в этом цикле,а в do while оставить у
								*/
								Pole[x][y] = 1;
								y++;
							}
							else
							{
								cout << "Неверно выбраны координаты!\n";
								Pole[x][y] = 0;
							}
						}

					}
				}

			} while (Pole[x][q] != 1);
		}
		if (tip == 2)
		{
			n--;
			o--;
		}

		if (tip == 3)
		{
			b--;
			o--;
		}
		if (tip == 4)
		{
			v--;
			o--;
		}

		poleigroka();
	} while (o != 0);
	cout << "Все корабли расставлены:)" << "\n";
	return Pole[x][y];
	return o;
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
int moihod()/*в этой или другой созданной ф-ции нужна проверка на убийство корабля(опять же проверка матрицы вокруг точки выстрела)
			*/
{
	cout << "Ходит игрок:\n";
	do
	{
		cout << "Введите координаты:";
		cin >> x >> y;
		x = x - 1;
		y = y - 1;
		if (Pole[x][y] == 1)//&& выполняется проверка на то,что вокруг есть ещё клетка с кораблём)
		{
			Pole[x][y] = 2;
			cout << "Ранил!";
			/*if(выполняется проверка) cout<<"Убил!";*/
		}
		else if (Pole[x][y] == 0)//&& не выполняется проверка на то,что вокруг есть ещё клетка с кораблём)
		{
			Pole[x][y] = 3;
			break;
		}
	} while (Pole[x][y] != 3);
	return Pole[x][y];
}
/*int hodkomp()
{

}*/
/*int proverkapobedi()
{
	//просто проверяем сколько клеток со значением ранил и у какого игрока быстрее наберётся 20,тот и победил
}*/


/*int autorasstanovka(int x,int y)
{
	x = rand() % 10;
	y = rand() % 10;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Pole[i][j] == 1)
			{

			}
		}
	}
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