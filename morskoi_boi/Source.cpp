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
int ship_id = 1;
int ship_idH = 1;

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
		if (Pole[save_x][save_y] >= 1 || Pole[save_x][save_y + 1] >= 1 || Pole[save_x][save_y - 1] >= 1 ||
			Pole[save_x + 1][save_y] >= 1 || Pole[save_x + 1][save_y + 1] >= 1 || Pole[save_x + 1][save_y - 1] >= 1 ||
			Pole[save_x - 1][save_y] >= 1 || Pole[save_x - 1][save_y + 1] >= 1 || Pole[save_x - 1][save_y - 1] >= 1)
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

int rasstanovka(int Pole[10][10], int tip, int x, int y, int ships_human[11])
{
	char napravlenie;
	int one = 4, two = 3, three = 2, four = 1;
	int o = 10;//количество кораблей
	int count;
	do
	{
		cout << "Выберите тип корабля:\nОднопалубный:" << one << "\nДвухпалубный:" << two << "\nТрехпалубный:" << three << "\nЧетырехпалубный:" << four << "\n";
		cin >> tip;
		if (tip == 4 && four < 1)
		{
			cout << "Корабли данного типа закончились!" << endl;
			continue;
		}
		if (tip == 3 && three < 1)
		{
			cout << "Корабли данного типа закончились!" << endl;
			continue;
		}
		if (tip == 2 && two < 1)
		{
			cout << "Корабли данного типа закончились!" << endl;
			continue;
		}
		if (tip == 1 && one < 1)
		{
			cout << "Корабли данного типа закончились!" << endl;
			continue;
		}
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
					Pole[x][y] = ship_idH;
					ships_human[ship_idH] = tip;
					ship_idH++;
					one--;
					o--;
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
				cout << "Выберите направление(L-влево/R-вправо/U-вверх/D-вниз):";
				cin >> napravlenie;
				if (napravlenie == 'L' || napravlenie == 'l')
				{
					napravlenie = 'L';
				}
				else if (napravlenie == 'R' || napravlenie == 'r')
				{
					napravlenie = 'R';
				}
				else if (napravlenie == 'U' || napravlenie == 'u')
				{
					napravlenie = 'U';
				}
				else if (napravlenie == 'D' || napravlenie == 'd')
				{
					napravlenie = 'D';
				}
				else continue;

				if (proverka_handmade_rasstanovki(Pole, tip, x, y, napravlenie) == 1)
				{
					for (int ship = 0; ship < tip; ship++)
					{
						Pole[x][y] = ship_idH;
						switch (napravlenie)
						{
						case 'L':
							x--;
							break;
						case 'R':
							x++;
							break;
						case 'U':
							y--;
							break;
						case 'D':
							y++;
							break;
						}
					}
					if (tip == 4)
					{
						four--;
					}
					else if (tip == 3)
					{
						three--;
					}
					else if (tip == 2)
					{
						two--;
					}
					o--;
				}
				else
				{
					cout << "Неверно выбраны координаты!\n";
					count++;
				}
			} while (count != 0);
		}
		poleigroka(Pole, x, y);
	} while (o != 0);
	return Pole[x][y];
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
			if (Pole[x][y] >= 1)//если в ячейке есть корабль
			{
				cout << " |O| ";
			}
			if (Pole[x][y] == -2)//если в корабль в данной ячейке попали
			{
				cout << " |X| ";
			}
			if (Pole[x][y] == -3)//выстрел пришёлся мимо
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
			/*if (Pole_Mask[x][y] == 1)
			{*/
				if (!(Pole_Comp[x][y]))
				{
					cout << " |";
				}
				if (Pole_Comp[x][y] == 0)//если в ячейке нет ничего
				{
					cout << " |";
					cout << " ";
				}
				if (Pole_Comp[x][y] >= 1)//если в ячейке есть корабль
				{
					cout << " |O| ";
				}
				if (Pole_Comp[x][y] == -2)//если в корабль в данной ячейке попали
				{
					cout << " |X| ";
				}
				if (Pole_Comp[x][y] == -3)//выстрел пришёлся мимо
				{
					cout << " |-| ";
				}
				if (x == 10)
				{
					cout << "|";
				}
			//}
			//else if (Pole_Mask[x][y] != 1)
			//{
			//	if (!(Pole_Mask[x][y]))
			//	{
			//		cout << " |";
			//	}
			//	if (Pole_Mask[x][y] == 0)//если в ячейке нет ничего
			//	{
			//		cout << " |";
			//		cout << " ";
			//	}
			//	if (Pole_Mask[x][y] == -3)
			//	{
			//		cout << " |-| ";
			//	}
			//	if (Pole_Mask[x][y] == -2 || Pole_Mask[x][y] == -4)//4 - убил 
			//	{
			//		cout << " |X| ";
			//	}
			//	if (x == 10)
			//	{
			//		cout << "|";
			//	}
			//}
		}
		cout << endl;
		cout << "  + - + - + - + - + - + - + - + - + - + - + - + - +\n";
	}
}

/*int obvodka(int Pole[10][10], int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y);
{

}*/

int proverka_humanmade_rasstanovki(int Pole[10][10], int size_ship, int stolb, int strok, char human_napravlenie)
{
	int save_stolb = stolb;
	int save_strok = strok;
	int	human_setting_possible = 1;
	for (int ship = 0; ship < size_ship; ship++)
	{
		if (save_stolb < 0 || save_strok < 0 || save_stolb >= 10 || save_strok >= 10)
		{
			human_setting_possible = 0;
			break;
		}
		if (Pole[save_stolb][save_strok] >= 1 || Pole[save_stolb][save_strok + 1] >= 1 || Pole[save_stolb][save_strok - 1] >= 1 ||
			Pole[save_stolb + 1][save_strok] >= 1 || Pole[save_stolb + 1][save_strok + 1] >= 1 || Pole[save_stolb + 1][save_strok - 1] >= 1 ||
			Pole[save_stolb - 1][save_strok] >= 1 || Pole[save_stolb - 1][save_strok + 1] >= 1 || Pole[save_stolb - 1][save_strok - 1] >= 1)
		{
			human_setting_possible = 0;
			break;
		}
		switch (human_napravlenie)
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
	return human_setting_possible;
}

int human_autorasstanovka(int Pole[10][10], int x, int y, int size_ship, int ship_idH)
{
	srand(time(NULL));
	int stolb, strok;
	char human_napravlenie = 'R';
	int count_ship = 0;
	int o = 10;
	int human_rand;
	while (count_ship < 1)
	{
		stolb = rand() % 10;
		strok = rand() % 10;

		human_rand = rand() % 4 + 1;
		switch (human_rand)
		{
		case 1:
			human_napravlenie = 'L';
			break;
		case 2:
			human_napravlenie = 'R';
			break;
		case 3:
			human_napravlenie = 'U';
			break;
		case 4:
			human_napravlenie = 'D';
			break;
		}
		if (proverka_humanmade_rasstanovki(Pole, size_ship, stolb, strok, human_napravlenie) == 1)
		{
			for (int ship = 0; ship < size_ship; ship++)
			{
				Pole[stolb][strok] = ship_idH;
				switch (human_napravlenie)
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
	return Pole[x][y];
}

int moihod(int Pole[10][10], int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y, int ships[11])/*в этой или другой созданной ф-ции нужна проверка на убийство корабля(опять же проверка матрицы вокруг точки выстрела)
			*/
{
	cout << "Ходит игрок:\n";
	polekompa(Pole_Comp, Pole_Mask, x, y);
	do
	{
		cout << "Введите координаты:";
		cin >> x >> y;
		x = x - 1;
		y = y - 1;
		if (Pole_Comp[x][y] >= 1)
		{
			ships[Pole_Comp[x][y]]--;
			if (Pole_Mask[x][y] != 0)
			{
				cout << "Сюда уже был произведен выстрел!" << endl;
				continue;
			}
			if (ships[Pole_Comp[x][y]] != 0)
			{
				Pole_Mask[x][y] = -2;
				cout << "Ранил!" << endl;
			}
			polekompa(Pole_Comp, Pole_Mask, x, y);
		}
		if (Pole_Comp[x][y] >= 1 && ships[Pole_Comp[x][y]] == 0)
		{
			Pole_Mask[x][y] = -2;
			cout << "Убил!" << endl;
			polekompa(Pole_Comp, Pole_Mask, x, y);
		}
		else if (Pole_Comp[x][y] == 0)
		{
			if (Pole_Mask[x][y] != 0)
			{
				cout << "Сюда уже был произведен выстрел!" << endl;
				continue;
			}
			Pole_Mask[x][y] = -3;
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
		if (Pole_Comp[save_stolb][save_strok] >= 1 || Pole_Comp[save_stolb][save_strok + 1] >= 1 || Pole_Comp[save_stolb][save_strok - 1] >= 1 ||
			Pole_Comp[save_stolb + 1][save_strok] >= 1 || Pole_Comp[save_stolb + 1][save_strok + 1] >= 1 || Pole_Comp[save_stolb + 1][save_strok - 1] >= 1 ||
			Pole_Comp[save_stolb - 1][save_strok] >= 1 || Pole_Comp[save_stolb - 1][save_strok + 1] >= 1 || Pole_Comp[save_stolb - 1][save_strok - 1] >= 1)
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

int hodkomp(int Pole[10][10], int x, int y, int ships_human[10])
{
	//srand(time(0));
	int count_shoot_x = 0;
	int count_shoot_y = 0;
	int one_shot;
	cout << "Ходит компьютер: " << endl;
	poleigroka(Pole, x, y);
	int mode_shoot = 0;
	int direction = 0;
	int o = 10;
	do
	{
		x = rand() % 10;
		y = rand() % 10;

		count_shoot_x = x;
		count_shoot_y = y;
		if (Pole[x][y] >= 1)
		{
			one_shot = ships_human[Pole[x][y]];
			one_shot--;
			if (Pole[x][y] != 0 && Pole[x][y] < 1)
			{
				continue;
			}
			Pole[x][y] = -2;
			mode_shoot = 1;
			cout << "Ранил!" << endl;
			Sleep(1000);
			if (mode_shoot == 1)
			{
				do
				{
					if (direction == 0)//лево
					{
						if (count_shoot_x > 0)
						{
							count_shoot_x--;
						}
						else
						{
							direction = 1;
							count_shoot_x = x + 1;
						}
					}
					else if (direction == 1)//право
					{
						if (count_shoot_x < 9)
						{
							count_shoot_x++;
						}
						else
						{
							direction = 2;
							count_shoot_x = x;
						}
					}
					else if (direction == 2)//низ
					{
						if (count_shoot_y > 0)
						{
							count_shoot_y++;
						}
						else
						{
							direction = 3;
							count_shoot_y = y + 1;
						}
					}
					else if (direction == 3)//верх
					{
						if (count_shoot_y < 9)
						{
							count_shoot_y--;
						}
					}
					if (Pole[count_shoot_x][count_shoot_y] >= 1)
					{
						Pole[count_shoot_x][count_shoot_y] = -2;
						cout << "Ранил!" << endl;
						Sleep(1000);
					}
					if (one_shot == 0)
					{
						cout << "Убил!" << endl;
						mode_shoot = 0;
						o--;
						Sleep(1000);
					}
					else if (Pole[count_shoot_x][count_shoot_y] == 0)
					{
						Pole[count_shoot_x][count_shoot_y] = -3;
						//cout << "Промах!456" << endl;
						if (direction == 0)
							direction = 1;
						if (direction == 1)
							direction = 2;
						if (direction == 2)
							direction = 3;

						count_shoot_x = x;
						break;
					}
				} while (mode_shoot != 0 || Pole[count_shoot_x][count_shoot_y] == -3);
				poleigroka(Pole, x, y);

			}
		}
		else if (Pole[x][y] == 0 || Pole[count_shoot_x][count_shoot_y] == -3)
		{
			if (Pole[x][y] != 0)
			{
				continue;
			}
			Pole[x][y] = -3;
			cout << "Промах!" << endl;
			Sleep(1000);
			break;
		}
	} while (Pole[x][y] != -3);
	return Pole[x][y];
	//return Pole[count_shoot_x][count_shoot_y];
}
int proverkapobedi_comp(int Pole[10][10])
{
	int count_ships = 0;
	int count_ships_comp = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Pole[i][j] == -2)
			{
				count_ships++;
			}
		}
	}
	return count_ships;
}

int proverkapobedi_human(int Pole_Mask[10][10])
{
	int count_ships_comp = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Pole_Mask[i][j] == -2)
			{
				count_ships_comp++;
			}
		}
	}
	return count_ships_comp;
}

int autorasstanovka(int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y, int size_ship, int ship_id)
{
	srand(time(NULL));
	int stolb, strok;
	char comp_napravlenie = 'R';
	int count_ship = 0;
	int o = 10;
	int comp_rand;
	while (count_ship < 1)
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
				Pole_Comp[stolb][strok] = ship_id;
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
	int ships[11] = { 0, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
	int ships_human[11] = { 0, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
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
			rasstanovka(Pole, tip, x, y, ships_human);
		}
		else
		{
			Pole[x][y] = 0;
		}
	}
	else
	{
		for (int i = 1; i < 11; i++)
		{
			human_autorasstanovka(Pole, x, y, ships_human[i], i);
		}
	}
	cout << "Расставляет компьютер. " << endl;
	for (int i = 1; i < 11; i++)
	{
		autorasstanovka(Pole_Comp, Pole_Mask,  x, y, ships[i], i);
	}
	cout << "Поле игрока: \n";
	poleigroka(Pole, x, y);
	cout << "\n";
	cout << "Поле компьютера: \n";
	polekompa(Pole_Comp, Pole_Mask, x, y);
	while (true)
	{
		Sleep(1000);
		moihod(Pole, Pole_Comp, Pole_Mask, x, y, ships);
		cout << "Поле компьютера: \n";
		//polekompa(Pole_Comp, Pole_Mask, x, y);
		if (proverkapobedi_human(Pole_Mask) == 20)
		{
			cout << "Победил игрок" << endl;
			break;
		}
		Sleep(3000);
		hodkomp(Pole, x, y, ships_human);
		if (proverkapobedi_comp(Pole) == 20)
		{
			cout << "Победил компьютер" << endl;
			break;
		}
		cout << "Поле игрока: \n";
		//poleigroka(Pole, x, y);
	}
}