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
int Pole_Comp[10][10];
int x, y;//x-столбик y-строчка

void poleigroka();

void polekompa();

//int proverka_matrici_vokrug();

//теперь она работает,но не полностью,по диагонали корабли ставятся всё так же без ограничений,но возможно нужны просто доп условия ниже
int proverka_rasstanovki(int tip)
{
	int k = 1;//флаг на ошибку расстановки
	if (tip == 1)
	{
		if (x == 0 && y > 0 && y < 10)
		{
			for (int stolbec = x; stolbec < x + 2; stolbec++)
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
		if (x == 9 && y > 0 && y < 10)
		{
			for (int stolbec = x - 1; stolbec <= x; stolbec++)
			{
				for (int stroka = y - 1; stroka <= y; stroka++)
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
		for (int i = 1; i < 9; i++)
		{
			if (x == i && y > 0 && y < 10)
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

int proverka_rasstanovki_vertical(int tip, char napravlenie)
{
	int k = 1;
	int stolbec;
	int stroka;
	if (tip >= 2)
	{
		if (x == 0 && y >= 0 && y < 10)
		{
			for (stolbec = x; stolbec < x + 2; stolbec++)
			{
				if (napravlenie == 'D' || napravlenie == 'd')
				{
					for (stroka = y; stroka < y + tip; stroka++)
					{
						if (stroka >= 0 && stroka < 10)
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
						else k = 0;
					}
				}
				else if (napravlenie == 'U' || napravlenie == 'u')
				{
					for (stroka = y - tip; stroka < y; stroka++)
					{
						if (stroka > 0 && stroka < 10)
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
						else k = 0;
					}
					if (k == 0)
					{
						break;
					}
				}
			}
		}
		if (x == 9 && y >= 0 && y < 10)
		{
			for (stolbec = x - 1; stolbec <= x; stolbec++)
			{
				if (napravlenie == 'D' || napravlenie == 'd')
				{
					for (stroka = y; stroka < y + tip; stroka++)
					{
						if (stroka >= 0 && stroka < 10)
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
						else k = 0;
					}
				}
				else if (napravlenie == 'U' || napravlenie == 'u')
				{
					for (stroka = y - tip; stroka < y; stroka++)
					{
						if (stroka > 0 && stroka < 10)
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
						else k = 0;
					}
					if (k == 0)
					{
						break;
					}
				}
			}
		}
		for (int i = 1; i < 9; i++)
		{
			if (x == i && y >= 0 && y < 10)
			{
				for (stolbec = x - 1; stolbec < x + 2; stolbec++)
				{
					if (napravlenie == 'D' || napravlenie == 'd')
					{
						for (stroka = y - 1; stroka < y + tip + 1; stroka++)
						{
							if (stroka >= 0 && stroka < 10)
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
							else k = 0;
						}
						if (k == 0)
						{
							break;
						}
					}
					else if (napravlenie == 'U' || napravlenie == 'u')
					{
						for (stroka = y - (tip + 1); stroka < y + 1; stroka++)
						{
							if (stroka > 0 && stroka < 10)
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
							else k = 0;
						}
						if (k == 0)
						{
							break;
						}
					}
				}
			}
			else break;
		}
	}
	return k;
}

int proverka_rasstanovki_gorizontal(int tip, char napravlenie)
{
	int k = 1;
	int stroka, stolbec;
	if (tip >= 2)
	{
		if (y == 0 && x >= 0 && x < 10)
		{
			for (stroka = y; stroka < y + 1; stroka++)
			{
				if (napravlenie == 'R' || napravlenie == 'r')
				{
					for (stolbec = x - 1; stolbec < x + tip + 1; stolbec++)
					{
						if (stolbec >= 0 && stolbec < 10)
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
						else k = 0;
					}
				}
				else if (napravlenie == 'L' || napravlenie == 'l')
				{
					for (stolbec = x - tip - 1; stolbec < x; stolbec++)
					{
						if (stolbec >= 0 && stolbec < 10)
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
						else k = 0;
					}

				}
			}
		}
		if (y == 9 && x >= 0 && x < 10)
		{
			for (stroka = y - 1; stroka <= y; stroka++)
			{
				if (napravlenie == 'R' || napravlenie == 'r')
				{
					for (stolbec = x; stolbec < x + tip; stolbec++)
					{
						if (stolbec >= 0 && stolbec < 10)
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
						else k = 0;
					}
				}
				else if (napravlenie == 'L' || napravlenie == 'l')
				{
					for (stolbec = x - tip; stolbec < x; stolbec++)
					{
						if (stolbec >= 0 && stolbec < 10)
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
						else k = 0;
					}
				}
			}
		}
		for (int i = 1; i < 9; i++)
		{
			if (y == i && x >= 0 && x < 10)
			{
				for (stroka = y; stroka < y + tip; stroka++)
				{
					if (napravlenie == 'L' || napravlenie == 'l')
					{
						for (stolbec = x - tip; stolbec < x; stolbec++)
						{
							if (stolbec >= 0 && stolbec < 10)
							{
								if (stroka >= 0 && stroka < 10)
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
								else k = 0;
							}
							else k = 0;
						}
						if (k == 0)
						{
							break;
						}
					}
					else if (napravlenie == 'R' || napravlenie == 'r')
					{
						for (stolbec = x; stolbec < x + tip; stolbec++)
						{
							if (stolbec >= 0 && stolbec < 10)
							{
								if (stroka >= 0 && stroka < 10)
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
								else k = 0;
							}
							else k = 0;
						}
						if (k == 0)
						{
							break;
						}
					}
				}
			}
			else break;
		}
	}
	return k;
}

int rasstanovka(int tip)
{
	char pologenie;
	char napravlenie;
	int one = 4, two = 3, three = 2, four = 1;
	int o = 10;//количество кораблей
	int count;
	do
	{
		cout << "Выберите тип корабля:\nОднопалубный:" << one << "\nДвухпалубный:" << two << "\nТрехпалубный:" << three << "\nЧетырехпалубный:" << four << "\n";
		cin >> tip;
		if (tip == 0)
		{
			o = 0;
		}
		if (tip == 1)
		{
			cout << "Выбран тип корабля:\nОднопалубный:" << one << "\n";
			do
			{
				count = 0;
				cout << "Установите столбец:\n ";
				cin >> x;
				cout << "Установите строку:\n ";
				cin >> y;
				x = x - 1;
				y = y - 1;
				if (x < 10 && y < 10 && x >= 0 && y >= 0 && proverka_rasstanovki(tip) != 0)
				{
					Pole[x][y] = 1;
				}
				else if (proverka_rasstanovki(tip) == 0)
				{
					cout << "\nСюда нельзя поставить корабль!\n";
					count++;
				}
				else if (x > 10 && y > 10 && x <= 0 && y <= 0)
				{
					cout << "Введены неверные координаты\n";
					count++;
				}
			} while (count != 0);
			one--;
			o--;
		}
		if (tip > 1 && tip <= 4)
		{
			if (tip == 2)
			{
				cout << "Выбран тип корабля:\nДвухпалубный:" << two << "\n";
			}
			if (tip == 3)
			{
				cout << "Выбран тип корабля:\nТрёхпалубный:" << three << "\n";
			}
			if (tip == 4)
			{
				cout << "Выбран тип корабля:\nЧетырёхпалубный:" << four << "\n";
			}
			do
			{
				count = 0;
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
						if (proverka_rasstanovki_gorizontal(tip, napravlenie) != 0)
						{
							Pole[x][y] = 1;
							if (tip == 2)
							{
								Pole[x - 1][y] = 1;
							}
							if (tip == 3)
							{
								Pole[x - 1][y] = 1;
								Pole[x - 2][y] = 1;
							}
							if (tip == 4)
							{
								Pole[x - 1][y] = 1;
								Pole[x - 2][y] = 1;
								Pole[x - 3][y] = 1;
							}
						}
						else
						{
							cout << "Неверно выбраны координаты!\n";
							count++;
						}
					}
					if (napravlenie == 'R' || napravlenie == 'r')
					{
						if (proverka_rasstanovki_gorizontal(tip, napravlenie) != 0)
						{
							Pole[x][y] = 1;
							if (tip == 2)
							{
								Pole[x + 1][y] = 1;
							}
							if (tip == 3)
							{
								Pole[x + 1][y] = 1;
								Pole[x + 2][y] = 1;
							}
							if (tip == 4)
							{
								Pole[x + 1][y] = 1;
								Pole[x + 2][y] = 1;
								Pole[x + 3][y] = 1;
							}
						}
						else
						{
							cout << "Неверно выбраны координаты!\n";
							count++;
						}
					}
				}
				if (pologenie == 'V' || pologenie == 'v')
				{
					cout << "Выберите направление(вверх-U/вниз-D): ";
					cin >> napravlenie;
					if (napravlenie == 'U' || napravlenie == 'u')
					{
						if (proverka_rasstanovki_vertical(tip, napravlenie) != 0)
						{
							Pole[x][y] = 1;
							if (tip == 2)
								Pole[x][y - 1] = 1;
							if (tip == 3)
							{
								Pole[x][y - 1] = 1;
								Pole[x][y - 2] = 1;
							}
							if (tip == 4)
							{
								Pole[x][y - 1] = 1;
								Pole[x][y - 2] = 1;
								Pole[x][y - 3] = 1;
							}
							break;
						}
						else
						{
							cout << "Неверно выбраны координаты!\n";
							count++;
						}
					}
					if (napravlenie == 'D' || napravlenie == 'd')
					{
						if (proverka_rasstanovki_vertical(tip, napravlenie) != 0)
						{
							Pole[x][y] = 1;
							if (tip == 2)
								Pole[x][y + 1] = 2;
							if (tip == 3)
							{
								Pole[x][y + 1] = 1;
								Pole[x][y + 2] = 1;
							}
							if (tip == 4)
							{
								Pole[x][y + 1] = 1;
								Pole[x][y + 2] = 1;
								Pole[x][y + 3] = 1;
							}
							break;
						}
						else
						{
							cout << "Неверно выбраны координаты!\n";
							count++;
						}
					}
				}
			} while (count != 0);
		}
		if (tip == 2)
		{
			two--;
			o--;
		}

		if (tip == 3)
		{
			three--;
			o--;
		}
		if (tip == 4)
		{
			four--;
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
			if (!(Pole_Comp[x][y]))
			{
				cout << " |";
			}
			if (Pole_Comp[x][y] == 0)//если в ячейке нет ничего
			{
				//cout << " ";
				cout << " |";
				cout << " ";
			}
			if (Pole_Comp[x][y] == 1)//если в ячейке есть корабль
			{
				cout << " |O| ";
			}
			if (Pole_Comp[x][y] == 2)//если в корабль в данной ячейке попали
			{
				cout << " |X| ";
			}
			if (Pole_Comp[x][y] == 3)//выстрел пришёлся мимо
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

int auto_rasstanovka(int tipv, int tipg)
{
	int autostroka, autostolbec;
	int count_1 = 0;
	do
	{
		srand(time(0));
		autostroka = rand() % 10;
		autostolbec = rand() % 10;
		int count_2 = 0;
		if (autostolbec == 0 && autostroka >= 0 && autostroka < 10)
		{
			for (int i = autostolbec; i < autostolbec + 2 + tipg; i++)
			{
				for (int j = autostroka; j < autostroka + 2 + tipv; j++)
				{
					if (autostroka >= 0 && autostroka < 10)
					{
						if (autostolbec >= 0 && autostolbec < 10)
						{
							if (Pole_Comp[autostolbec][autostroka] == 0)
							{
								count_1++;
							}
							else
							{
								count_1 = 0;
								break;
							}
						}
						else
						{
							count_1 = 0;
							break;
						}
					}
					else
					{
						count_1 = 0;
						break;
					}
					if (count_1 == 0)
					{
						break;
					}
				}
			}
		}
		if (autostolbec == 9 && autostroka >= 0 && autostroka < 10)
		{
			for (int i = autostolbec - 1; i < autostolbec + 2 + tipg; i++)
			{
				for (int j = autostroka - 1; j < autostroka + 2 + tipv; j++)
				{
					if (autostroka >= 0 && autostroka < 10)
					{
						if (autostolbec >= 0 && autostolbec < 10)
						{
							if (Pole_Comp[autostolbec][autostroka] == 0)
							{
								count_1++;
							}
							else
							{
								count_1 = 0;
								break;
							}
						}
						else
						{
							count_1 = 0;
							break;
						}
					}
					else
					{
						count_1 = 0;
						break;
					}
					if (count_1 == 0)
					{
						break;
					}
				}
			}
		}
		for (int i = 1; i < 9; i++)
		{
			if (autostolbec == i && autostroka >= 0 && autostroka < 10)
			{
				for (int stolb = autostolbec - 1; stolb < autostolbec + 2 + tipg; stolb++)
				{
					for (int strok = autostroka - 1; strok < autostroka + 2 + tipv; strok++)
					{
						if (stolb >= 0 && stolb < 10)
						{
							if (strok >= 0 && strok < 10)
							{
								if (Pole_Comp[stolb][strok] == 0)
								{
									count_1++;
								}
								else
								{
									count_1 = 0;
									break;
								}
							}
							else
							{
								count_1 = 0;
								break;
							}
						}
						else
						{
							count_1 = 0;
							break;
						}
						if (count_1 == 0)
						{
							break;
						}
					}
				}
			}
		}
		if (count_1 != 0)
		{
			do
			{
				if (tipg == 0)
				{
					if (tipv == 0)
					{
						Pole_Comp[autostolbec][autostroka] = 1;
						count_2 = 1;
					}
					if (tipv == 1)
					{
						for (int gor = autostroka; gor < autostroka + 2; gor++)
						{
							Pole_Comp[autostolbec][gor] = 1;
						}
						count_2 = 1;
					}
					if (tipv == 2)
					{
						for (int gor = autostroka; gor < autostroka + 3; gor++)
						{
							Pole_Comp[autostolbec][gor] = 1;
						}
						count_2 = 1;
					}
					if (tipv == 3)
					{
						for (int gor = autostroka; gor < autostroka + 4; gor++)
						{
							Pole_Comp[autostolbec][gor] = 1;
						}
						count_2 = 1;
					}
				}
				else
				{
					if (tipg == 1)
					{
						for (int ver = autostroka; ver < autostroka + 2; ver++)
						{
							Pole_Comp[ver][autostroka] = 1;
						}
						count_2 = 1;
					}
					if (tipg == 2)
					{
						for (int ver = autostroka; ver < autostroka + 3; ver++)
						{
							Pole_Comp[ver][autostroka] = 1;
						}
						count_2 = 1;
					}
					if (tipg == 3)
					{
						for (int ver = autostroka; ver < autostroka + 4; ver++)
						{
							Pole_Comp[ver][autostroka] = 1;
						}
						count_2 = 1;
					}
				}
			} while (count_2 == 0);
		}
		if (count_2 == 1) count_1 = -1;
	} while (count_1 == -1);
	polekompa();
	return 0;
}


/*int hodkomp()
{

}*/
/*int proverkapobedi()
{
//просто проверяем сколько клеток со значением ранил и у какого игрока быстрее наберётся 20,тот и победил
}*/

int autorasstanovka()
{
	srand(time(0));
	int o = 10;
	int one = 4, two = 3, three = 2, four = 1;
	do
	{
		int tipv = 0, tipg = 0;
		int random;
		do
		{
			tipv = 0;
			auto_rasstanovka(tipv, tipg);
			one--;
			o--;
		} while (one != 0);
		do
		{
			random = rand() % 2 + 1;
			switch (random)
			{
			case 1:
				tipv = 1;
				auto_rasstanovka(tipv, tipg);//vertical
				two--;
				o--;
				break;
			case 2:
				tipg = 1;
				auto_rasstanovka(tipv, tipg);//gorizontal
				two--;
				o--;
				break;
			default:
				break;
			}
		} while (two != 0);
		do
		{
			random = rand() % 2 + 1;
			switch (random)
			{
			case 1:
				tipv = 2;
				auto_rasstanovka(tipv, tipg);
				three--;
				o--;
				break;
			case 2:
				tipg = 2;
				auto_rasstanovka(tipv, tipg);
				three--;
				o--;
				break;
			default:
				break;
			}
		} while (three != 0);
		do
		{
			random = rand() % 2 + 1;
			switch (random)
			{
			case 1:
				tipv = 3;
				auto_rasstanovka(tipv, tipg);
				four--;
				o--;
				break;
			case 2:
				tipg = 3;
				auto_rasstanovka(tipv, tipg);
				four--;
				o--;
				break;
			default:
				break;
			}
		} while (four != 0);
	} while (o != 0);
	return Pole_Comp[x][y];
}

/*int proverka_matrici_vokrug()//возможно для стрельбы
{
int l = 1;
if (x == 0 && y > 0 && y < 10)
{
for (int stolbec = x; stolbec < x + 2; stolbec++)
{
for (int stroka = y - 1; stroka < y + 2; stroka++)
{
if (Pole[stolbec][stroka] == 0)
{
l++;
}
else
{
l = 0;
break;
}
}
if (l == 0)
{
break;
}
}
}
if (x == 9 && y > 0 && y < 10)
{
for (int stolbec = x - 1; stolbec <= x; stolbec++)
{
for (int stroka = y - 1; stroka <= y; stroka++)
{
if (Pole[stolbec][stroka] == 0)
{
l++;
}
else
{
l = 0;
break;
}
}
if (l == 0)
{
break;
}
}
}
for (int i = 1; i < 9; i++)
{
if (x == i && y > 0 && y < 10)
{
for (int stolbec = x - 1; stolbec < x + 2; stolbec++)
{
for (int stroka = y - 1; stroka < y + 2; stroka++)
{
if (Pole[stolbec][stroka] == 0)
{
l++;
}
else
{
l = 0;
break;
}
}
if (l == 0)
{
break;
}
}
}
}
return l;
}*/

int main()
{
	int tip = 0;
	int l;
	setlocale(LC_CTYPE, "rus");
	int p;
	cout << "Выберите метод расстановки:\n1-Ручная\n2-Автоматическая\n";
	cin >> p;
	if (p == 1)
	{
		do
		{
			cout << "Хотите поставить корабль? 1-YES/2-NO\n ";
			cin >> l;
		} while (l < 1 || l>2);

		if (l == 1)
		{
			rasstanovka(tip);
		}
		else
		{
			Pole[x][y] = 0;
		}
	}
	else
	{
	autorasstanovka();
	}
	//int proverkapopadaniya();
	cout << "Pole igroka: \n";
	poleigroka();
	cout << "\n";
	cout << "Pole kompa: \n";
	polekompa();
}