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

//int Pole[10][10];
//int Pole_Comp[10][10];
//int x, y;//x-столбик y-строчка

void poleigroka(int Pole[10][10], int x, int y);

void polekompa(int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y);

//int proverka_matrici_vokrug();

//теперь она работает,но не полностью,по диагонали корабли ставятся всё так же без ограничений,но возможно нужны просто доп условия ниже

int proverka_handmade_rasstanovki(int Pole[10][10], int tip, int x, int y, char napravlenie)
{
	int save_x = x;
	int save_y = y;
	int	setting_possible = 1;
	for (int ship = 0; ship < tip; ship++)
	{
		if (save_x < 0 || save_y < 0 || save_x >= 10 || save_y >= 10)
		{
			setting_possible = 0;
			break;
		}
		if (Pole[save_x][save_y] != 0 || Pole[save_x][save_y + 1] != 0 || Pole[save_x][save_y - 1] != 0 ||
			Pole[save_x + 1][save_y] != 0 || Pole[save_x + 1][save_y + 1] != 0 || Pole[save_x + 1][save_y - 1] != 0 ||
			Pole[save_x - 1][save_y] != 0 || Pole[save_x - 1][save_y + 1] != 0 || Pole[save_x - 1][save_y - 1] != 0)
		{
			setting_possible = 0;
			break;
		}
		switch (napravlenie)
		{
		case 'L':
			save_x--;
			break;
		case 'R':
			save_x++;
			break;
		case 'U':
			save_y--;
			break;
		case 'D':
			save_y++;
			break;
		}
	}
	return setting_possible;
}

int rasstanovka(int Pole[10][10], int tip, int x, int y)
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
				if (x < 10 && y < 10 && x >= 0 && y >= 0 && proverka_handmade_rasstanovki(Pole, tip, x, y, napravlenie) != 0)
				{
					Pole[x][y] = 1;
				}
				else if (proverka_handmade_rasstanovki(Pole, tip, x, y, napravlenie) == 0)
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
						napravlenie = 'L';
						if (proverka_handmade_rasstanovki(Pole, tip, x, y, napravlenie) != 0)
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
						napravlenie = 'R';
						if (proverka_handmade_rasstanovki(Pole, tip, x, y, napravlenie) != 0)
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
						napravlenie = 'U';
						if (proverka_handmade_rasstanovki(Pole, tip, x, y, napravlenie) != 0)
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
						napravlenie = 'D';
						if (proverka_handmade_rasstanovki(Pole, tip, x, y, napravlenie) != 0)
						{
							Pole[x][y] = 1;
							if (tip == 2)
								Pole[x][y + 1] = 1;
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

		poleigroka(Pole, x, y);
	} while (o != 0);
	cout << "Все корабли расставлены:)" << "\n";
	return Pole[x][y];
	return o;
}

void poleigroka(int Pole[10][10], int x, int y)
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

void polekompa(int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y)
{
	cout << "    a    b    c    d    e    f    g    h    i    j\n";
	cout << "  + - + - + - + - + - + - + - + - + - + - + - + - +\n";
	for (y = 0; y < 10; y++)
	{
		cout << y + 1 << " ";
		for (x = 0; x < 10; x++)
		{
			if (Pole_Mask[x][y] == 1)
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
			else if (Pole_Mask[x][y] != 1)
			{
				if (!(Pole_Mask[x][y]))
				{
					cout << " |";
				}
				if (Pole_Mask[x][y] == 0)//если в ячейке нет ничего
				{
					cout << " |";
					cout << " ";
				}
				if (Pole_Mask[x][y] == 3)
				{
					cout << " |-| ";
				}
				if (Pole_Mask[x][y] == 2 || Pole_Mask[x][y] == 4)//4 - убил 
				{
					cout << " |X| ";
				}
				if (x == 10)
				{
					cout << "|";
				}
			}
		}
		cout << endl;
		cout << "  + - + - + - + - + - + - + - + - + - + - + - + - +\n";
	}
}

/*int obvodka(int Pole[10][10], int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y);
{

}*/

int moihod(int Pole[10][10], int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y)/*в этой или другой созданной ф-ции нужна проверка на убийство корабля(опять же проверка матрицы вокруг точки выстрела)
			*/
{
	cout << "Ходит игрок:\n";
	do
	{
		cout << "Введите координаты:";
		cin >> x >> y;
		x = x - 1;
		y = y - 1;
		if (Pole_Comp[x][y] == 1)
		{
			if (Pole_Mask[x][y] != 0)
			{
				cout << "Сюда уже был произведен выстрел!" << endl;
				continue;
			}
			Pole_Mask[x][y] = 2;
			cout << "Ранил!" << endl;
			polekompa(Pole_Comp, Pole_Mask, x, y);
			if (Pole_Comp[x][y] != 1 || Pole_Comp[x][y + 1] != 1 || Pole_Comp[x][y - 1] != 1 ||
				Pole_Comp[x + 1][y] != 1 || Pole_Comp[x + 1][y + 1] != 1 || Pole_Comp[x + 1][y - 1] != 1 ||
				Pole_Comp[x - 1][y] != 1 || Pole_Comp[x - 1][y + 1] != 1 || Pole_Comp[x - 1][y - 1] != 1)
			{
				Pole_Mask[x][y] = 4;
				cout << "Убил!" << endl;
			}
		}
		else if (Pole_Comp[x][y] == 0)
		{
			if (Pole_Mask[x][y] != 0)
			{
				cout << "Сюда уже был произведен выстрел!" << endl;
				continue;
			}
			Pole_Mask[x][y] = 3;
			cout << "Промах!" << endl;
			break;
		}
	} while (Pole_Mask[x][y] != 1);
	return Pole_Mask[x][y];
}

int proverka_compmade_rasstanovki(int Pole_Comp[10][10], int size_ship, int stolb, int strok, char comp_napravlenie)
{
	int save_stolb = stolb;
	int save_strok = strok;
	int	comp_setting_possible = 1;
	for (int ship = 0; ship < size_ship; ship++)
	{
		if (save_stolb < 0 || save_strok < 0 || save_stolb >= 10 || save_strok >= 10)
		{
			comp_setting_possible = 0;
			break;
		}
		if (Pole_Comp[save_stolb][save_strok] != 0 || Pole_Comp[save_stolb][save_strok + 1] != 0 || Pole_Comp[save_stolb][save_strok - 1] != 0 ||
			Pole_Comp[save_stolb + 1][save_strok] != 0 || Pole_Comp[save_stolb + 1][save_strok + 1] != 0 || Pole_Comp[save_stolb + 1][save_strok - 1] != 0 ||
			Pole_Comp[save_stolb - 1][save_strok] != 0 || Pole_Comp[save_stolb - 1][save_strok + 1] != 0 || Pole_Comp[save_stolb - 1][save_strok - 1] != 0)
		{
			comp_setting_possible = 0;
			break;
		}
		switch (comp_napravlenie)
		{
		case 'L':
			save_stolb--;
			break;
		case 'R':
			save_stolb++;
			break;
		case 'U':
			save_strok--;
			break;
		case 'D':
			save_strok++;
			break;
		}
	}
	return comp_setting_possible;
}

int hodkomp(int Pole[10][10], int x, int y)
{
	int count_shoot = 0;
	cout << "Ходит компьютер: " << endl;
	int mode_shoot = 0;
	do
	{
		x = rand() % 10;
		y = rand() % 10;
		if (Pole [x][y] == 1)
		{
			if (Pole [x][y] != 0 && Pole [x][y] != 1)
			{
				cout << "Сюда уже был произведен выстрел!" << endl;
				continue;
			}
			Pole [x][y] = 2;
			cout << "Ранил!" << endl;
			poleigroka(Pole, x, y);
			if (Pole [x][y] != 1 || Pole [x][y + 1] != 1 || Pole [x][y - 1] != 1 ||
				Pole [x + 1][y] != 1 || Pole [x + 1][y + 1] != 1 || Pole [x + 1][y - 1] != 1 ||
				Pole [x - 1][y] != 1 || Pole [x - 1][y + 1] != 1 || Pole [x - 1][y - 1] != 1)
			{
				Pole[x][y] = 2;
				cout << "Убил!" << endl;
			}
		}
		else if (Pole[x][y] == 0)
		{
			if (Pole[x][y] != 0)
			{
				cout << "Сюда уже был произведен выстрел!" << endl;
				continue;
			}
			Pole[x][y] = 3;
			cout << "Промах!" << endl;
			break;
		}
	} while (Pole[x][y] != 1);
	return Pole[x][y];
}
/*int proverkapobedi()
{

}*/

int autorasstanovka(int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y, int size_ship, int num_ship)
{
	srand(time(0));
	int stolb, strok;
	char comp_napravlenie = 'R';
	int count_ship = 0;
	int o = 10;
	int comp_rand;
	while (count_ship < num_ship)
	{
		stolb = rand() % 10;
		strok = rand() % 10;

		comp_rand = rand() % 4 + 1;
		switch (comp_rand)
		{
		case 1:
			comp_napravlenie = 'L';
			break;
		case 2:
			comp_napravlenie = 'R';
			break;
		case 3:
			comp_napravlenie = 'U';
			break;
		case 4:
			comp_napravlenie = 'D';
			break;
		}
		if (proverka_compmade_rasstanovki(Pole_Comp, size_ship, stolb, strok, comp_napravlenie) == 1)
		{
			for (int ship = 0; ship < size_ship; ship++)
			{
				Pole_Comp[stolb][strok] = 1;
				switch (comp_napravlenie)
				{
				case 'L':
					stolb--;
					break;
				case 'R':
					stolb++;
					break;
				case 'U':
					strok--;
					break;
				case 'D':
					strok++;
					break;
				}
			}
			count_ship++;

		}
	}
	return Pole_Comp[x][y];
}

int main()
{
	int Pole[10][10] = { 0 };
	int Pole_Comp[10][10] = { 0 };
	int Pole_Mask[10][10] = { 0 };
	int x = 0, y = 0;//x-столбик y-строчка
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
			rasstanovka(Pole, tip, x, y);
		}
		else
		{
			Pole[x][y] = 0;
		}
	}
	else
	{
		autorasstanovka(Pole_Comp, Pole_Mask, x, y, 4, 1);
		autorasstanovka(Pole_Comp, Pole_Mask, x, y, 3, 2);
		autorasstanovka(Pole_Comp, Pole_Mask, x, y, 2, 3);
		autorasstanovka(Pole_Comp, Pole_Mask, x, y, 1, 4);
		polekompa(Pole_Comp, Pole_Mask, x, y);
	}
	//int proverkapopadaniya();
	cout << "Pole igroka: \n";
	poleigroka(Pole, x, y);
	cout << "\n";
	cout << "Pole kompa: \n";
	polekompa(Pole_Comp, Pole_Mask, x, y);
	while (true)
	{
		/*moihod(Pole, Pole_Comp, Pole_Mask, x, y);
		cout << "Pole kompa: \n";
		polekompa(Pole_Comp, Pole_Mask, x, y);*/
		hodkomp(Pole, x, y);
		cout << "Pole igroka: \n";
		poleigroka(Pole, x, y); 
	}
}