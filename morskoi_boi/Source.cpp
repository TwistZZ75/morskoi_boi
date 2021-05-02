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
//int x, y;//x-������� y-�������

void poleigroka(int Pole[10][10], int x, int y);

void polekompa(int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y);

//int proverka_matrici_vokrug();

//������ ��� ��������,�� �� ���������,�� ��������� ������� �������� �� ��� �� ��� �����������,�� �������� ����� ������ ��� ������� ����

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
	int o = 10;//���������� ��������
	int count;
	do
	{
		cout << "�������� ��� �������:\n������������:" << one << "\n������������:" << two << "\n������������:" << three << "\n���������������:" << four << "\n";
		cin >> tip;
		if (tip == 0)
		{
			o = 0;
		}
		if (tip == 1)
		{
			cout << "������ ��� �������:\n������������:" << one << "\n";
			do
			{
				count = 0;
				cout << "���������� �������:\n ";
				cin >> x;
				cout << "���������� ������:\n ";
				cin >> y;
				x = x - 1;
				y = y - 1;
				if (x < 10 && y < 10 && x >= 0 && y >= 0 && proverka_handmade_rasstanovki(Pole, tip, x, y, napravlenie) != 0)
				{
					Pole[x][y] = 1;
				}
				else if (proverka_handmade_rasstanovki(Pole, tip, x, y, napravlenie) == 0)
				{
					cout << "\n���� ������ ��������� �������!\n";
					count++;
				}
				else if (x > 10 && y > 10 && x <= 0 && y <= 0)
				{
					cout << "������� �������� ����������\n";
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
				cout << "������ ��� �������:\n������������:" << two << "\n";
			}
			if (tip == 3)
			{
				cout << "������ ��� �������:\n�����������:" << three << "\n";
			}
			if (tip == 4)
			{
				cout << "������ ��� �������:\n��������������:" << four << "\n";
			}
			do
			{
				count = 0;
				cout << "�������� ��������� ���������� �������: ";
				cin >> x >> y;
				x = x - 1;
				y = y - 1;
				cout << "�������� ��� ���������(�����������-V/�������������-G): ";
				cin >> pologenie;
				if (pologenie == 'G' || pologenie == 'g')
				{
					cout << "�������� �����������(����-L/�����-R): ";
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
							cout << "������� ������� ����������!\n";
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
							cout << "������� ������� ����������!\n";
							count++;
						}
					}
				}
				if (pologenie == 'V' || pologenie == 'v')
				{
					cout << "�������� �����������(�����-U/����-D): ";
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
							cout << "������� ������� ����������!\n";
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
							cout << "������� ������� ����������!\n";
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
	cout << "��� ������� �����������:)" << "\n";
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
			if (Pole[x][y] == 0)//���� � ������ ��� ������
			{
				cout << " |";
				cout << " ";
			}
			if (Pole[x][y] == 1)//���� � ������ ���� �������
			{
				cout << " |O| ";
			}
			if (Pole[x][y] == 2)//���� � ������� � ������ ������ ������
			{
				cout << " |X| ";
			}
			if (Pole[x][y] == 3)//������� �������� ����
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
				if (Pole_Comp[x][y] == 0)//���� � ������ ��� ������
				{
					//cout << " ";
					cout << " |";
					cout << " ";
				}
				if (Pole_Comp[x][y] == 1)//���� � ������ ���� �������
				{
					cout << " |O| ";
				}
				if (Pole_Comp[x][y] == 2)//���� � ������� � ������ ������ ������
				{
					cout << " |X| ";
				}
				if (Pole_Comp[x][y] == 3)//������� �������� ����
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
				if (Pole_Mask[x][y] == 0)//���� � ������ ��� ������
				{
					cout << " |";
					cout << " ";
				}
				if (Pole_Mask[x][y] == 3)
				{
					cout << " |-| ";
				}
				if (Pole_Mask[x][y] == 2 || Pole_Mask[x][y] == 4)//4 - ���� 
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

int moihod(int Pole[10][10], int Pole_Comp[10][10], int Pole_Mask[10][10], int x, int y)/*� ���� ��� ������ ��������� �-��� ����� �������� �� �������� �������(����� �� �������� ������� ������ ����� ��������)
			*/
{
	cout << "����� �����:\n";
	do
	{
		cout << "������� ����������:";
		cin >> x >> y;
		x = x - 1;
		y = y - 1;
		if (Pole_Comp[x][y] == 1)//&& ����������� �������� �� ��,��� ������ ���� ��� ������ � �������)
		{
			if (Pole_Mask[x][y] != 0)
			{
				cout << "���� ��� ��� ���������� �������!" << endl;
				continue;
			}
			Pole_Mask[x][y] = 2;
			cout << "�����!" << endl;
			polekompa(Pole_Comp, Pole_Mask, x, y);
			if (Pole_Comp[x][y] != 1 || Pole_Comp[x][y + 1] != 1 || Pole_Comp[x][y - 1] != 1 ||
				Pole_Comp[x + 1][y] != 1 || Pole_Comp[x + 1][y + 1] != 1 || Pole_Comp[x + 1][y - 1] != 1 ||
				Pole_Comp[x - 1][y] != 1 || Pole_Comp[x - 1][y + 1] != 1 || Pole_Comp[x - 1][y - 1] != 1)
			{
				Pole_Mask[x][y] = 4;
				cout << "����!" << endl;
			}
		}
		else if (Pole_Comp[x][y] == 0)//&& �� ����������� �������� �� ��,��� ������ ���� ��� ������ � �������)
		{
			if (Pole_Mask[x][y] != 0)
			{
				cout << "���� ��� ��� ���������� �������!" << endl;
				continue;
			}
			Pole_Mask[x][y] = 3;
			cout << "������!" << endl;
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

/*int hodkomp()
{

}*/
/*int proverkapobedi()
{
//������ ��������� ������� ������ �� ��������� ����� � � ������ ������ ������� �������� 20,��� � �������
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
	int x = 0, y = 0;//x-������� y-�������
	//int *pointer_x = &x;
	//int *pointer_y = &y;
	int tip = 0;
	int l;
	setlocale(LC_CTYPE, "rus");
	int p;
	cout << "�������� ����� �����������:\n1-������\n2-��������������\n";
	cin >> p;
	if (p == 1)
	{
		do
		{
			cout << "������ ��������� �������? 1-YES/2-NO\n ";
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
		moihod(Pole, Pole_Comp, Pole_Mask, x, y);
		cout << "Pole kompa: \n";
		polekompa(Pole_Comp, Pole_Mask, x, y);
	}
}