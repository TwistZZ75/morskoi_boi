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
int x, y;//x-������� y-�������

void poleigroka();

void polekompa();

int proverka_matrici_vokrug();

//������ ��� ��������,�� �� ���������,�� ��������� ������� �������� �� ��� �� ��� �����������,�� �������� ����� ������ ��� ������� ����
int proverka_rasstanovki(int tip)
{
	int k = 1;//���� �� ������ �����������
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
		if (x == 0 && y>=0 && y<10)
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
					for (stroka = y - tip; stroka < y ; stroka++)
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
				for (stolbec = x-1; stolbec < x + 2; stolbec++)
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
						for (stroka = y - (tip + 1); stroka < y + 1 ; stroka++)
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
		}
	}
	return k;
}

int rasstanovka(int tip)
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
				if (x < 10 && y < 10 && x >= 0 && y >= 0 && proverka_rasstanovki(tip) != 0)
				{
					Pole[x][y] = 1;
				}
				else if (proverka_rasstanovki(tip) == 0)
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
							cout << "������� ������� ����������!\n";
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
							cout << "������� ������� ����������!\n";
							count++;
						}
					}
					if (napravlenie == 'D' || napravlenie == 'd')
					{
						if (proverka_rasstanovki_vertical(tip, napravlenie) != 0)
						{
							Pole[x][y] = 1;
							if(tip==2)
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

		poleigroka();
	} while (o != 0);
	cout << "��� ������� �����������:)" << "\n";
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
			if (Pole_Comp[x][y] == 0)//���� � ������ ��� ������
			{
				//cout << " ";
				cout << " |";
				cout << " ";
			}
			if (Pole_Comp[x][y] == 1)//���� � ������ ���� �������
			{
				cout << " | | ";
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
		cout << endl;
		cout << "  + - + - + - + - + - + - + - + - + - + - + - + - +\n";
	}
}

int moihod()/*� ���� ��� ������ ��������� �-��� ����� �������� �� �������� �������(����� �� �������� ������� ������ ����� ��������)
			*/
{
	cout << "����� �����:\n";
	do
	{
		cout << "������� ����������:";
		cin >> x >> y;
		x = x - 1;
		y = y - 1;
		if (Pole[x][y] == 1)//&& ����������� �������� �� ��,��� ������ ���� ��� ������ � �������)
		{
			Pole[x][y] = 2;
			cout << "�����!";
			/*if(����������� ��������) cout<<"����!";*/
		}
		else if (Pole[x][y] == 0)//&& �� ����������� �������� �� ��,��� ������ ���� ��� ������ � �������)
		{
			Pole[x][y] = 3;
			break;
		}
	} while (Pole[x][y] != 3);
	return Pole[x][y];
}

int auto_rasstanovka(int x, int y,int tip)
{
	int autostroka, autostolbec;
	srand(time(0));
	autostroka = rand() % 10;
	autostolbec = rand() % 10;
	if (autostolbec == 0 && autostroka > 0 && autostroka < 9)
	{
		for (int i = autostroka-1;i<autostroka+1+x;i++)
		{

		}
	}
	return Pole_Comp[x][y];
}


/*int hodkomp()
{

}*/
/*int proverkapobedi()
{
	//������ ��������� ������� ������ �� ��������� ����� � � ������ ������ ������� �������� 20,��� � �������
}*/

int autorasstanovka()
{
	srand(time(0));
	int tip;
	int o = 10;
	int one = 4, two = 3, three = 2, four = 1;
		do
		{
			int random;
				do
				{
					tip = 1;
					auto_rasstanovka(0, 1, tip);
					one--;
				} while (one != 0);
				do
				{
					random = rand() % 2 + 1;
					tip = 2;
					switch (random)
					{
					case 1:
						auto_rasstanovka(x, y, tip);
						two--;
						break;
					case 2:
						auto_rasstanovka(x, y, tip);
						two--;
						break;
					default:
						break;
					}
				} while (two != 0);
				do
				{
					random = rand() % 2 + 1;
					tip = 3;
					switch (random)
					{
					case 1:
						auto_rasstanovka(x, y, tip);
						three--;
						break;
					case 2:
						auto_rasstanovka(x, y, tip);
						three--;
						break;
					default:
						break;
					}
				} while (three != 0);
				do
				{
					random = rand() % 2 + 1;
					tip = 4;
					switch (random)
					{
					case 1:
						auto_rasstanovka(x, y, tip);
						four--;
						break;
					case 2:
						auto_rasstanovka(x, y, tip);
						four--;
						break;
					default:
						break;
					}
				} while (four != 0);
		} while (o != 0);
	return o;
}

int proverka_matrici_vokrug()
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
}

int main()
{
	int tip=0;
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
				rasstanovka(tip);
		}
		else
		{
			Pole[x][y] = 0;
		}
	}
	/*else
	{
		autorasstanovka();
	}*/
	//int proverkapopadaniya();
	cout << "Pole igroka: \n";
	poleigroka();
	cout << "\n";
	cout << "Pole kompa: \n";
	polekompa();
}