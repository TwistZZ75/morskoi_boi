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
int x, y;//x-������� y-�������
void poleigroka();
void polekompa();
//������ ��� ��������,�� �� ���������,�� ��������� ������� �������� �� ��� �� ��� �����������,�� �������� ����� ������ ��� ������� ����
int provarkarasstanovki(int tip)
{
	int k = 1;//���� �� ������ �����������
	if (tip==1)
	{
		//��� ������ �1
		if (x == 0 and y == 0)
		{
			for (int i = x; i < x + 2; i++)
			{
				for (int j = y; j < y + 2 ; j++)
				{
					if (Pole[i][j] == 0)
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
			for (int i = x; i < x - 2; i++)
			{
				for (int j = y; j < y + 2; j++)
				{
					if (Pole[i][j] == 0)
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
			for (int i = x; i < x + 2; i++)
			{
				for (int j = y; j < y - 2; j++)
				{
					if (Pole[i][j] == 0)
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
			for (int i = x; i < x - 2; i++)
			{
				for (int j = y; j < y - 2; j++)
				{
					if (Pole[i][j] == 0)
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
				for (int i = x-1; i < x + 2; i++)
				{
					for (int j = y-1 ; j < y + 2; j++)
					{
						if (Pole[i][j] == 0)
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
	if (tip == 2)
	{
		//��� ������ �1
		if (x == 0 and y == 0)
		{
			for (int i = x; i < x + 3; i++)
			{
				for (int j = y; j < y + 3; j++)
				{
					if (Pole[i][j] == 0)
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
			for (int i = x; i < x - 3; i++)
			{
				for (int j = y; j < y + 3; j++)
				{
					if (Pole[i][j] == 0)
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
			for (int i = x; i < x + 3; i++)
			{
				for (int j = y; j < y - 3; j++)
				{
					if (Pole[i][j] == 0)
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
			for (int i = x; i < x - 3; i++)
			{
				for (int j = y; j < y - 3; j++)
				{
					if (Pole[i][j] == 0)
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
				for (int i = x - 2; i < x + 3; i++)
				{
					for (int j = y - 2; j < y + 3; j++)
					{
						if (Pole[i][j] == 0)
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

int rasstanovka()
{
	int tip;
	char pologenie;
	char napravlenie;
	int m = 4,n = 3,b = 2,v = 1;
	int o = 10;//����� ���������� ��������
	do
	{
		cout << "�������� ��� �������:\n������������:"<<m<<"\n������������:"<<n<<"\n������������:"<<b<<"\n���������������:"<<v<<"\n";
		cin >> tip;
			if (tip == 1)
			{
				cout << "������ ��� �������:\n������������:" << m<<"\n";
				do
				{
					cout << "���������� �������:\n ";
					cin >> x;
					cout << "���������� ������:\n ";
					cin >> y;
					x = x - 1;
					y = y - 1;
					if (x < 10 && y < 10 && x>=0 && y>=0 && provarkarasstanovki(tip) != 0)
					{
							Pole[x][y] = 1;
					}
					else if(provarkarasstanovki(tip) == 0)
					{
						cout << "\n���� ������ ��������� �������!\n";
						Pole[x][y] = 0;
					}
					else if(x > 10 && y > 10 && x <= 0 && y <= 0)
					{
						cout << "������� �������� ����������\n";
					}
					
				} while (Pole[x][y] != 1);
				m--;
				o--;
			}
			do
			{
				if (tip > 1 && tip <= 4)
				{
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
							for (int i = 0; i < tip; i++)
							{
								if (provarkarasstanovki(tip) != 0)
								{
									Pole[x][y] = 1;
									x--;
								}
								else
								{
									cout << "������� ������� ����������!";
									Pole[x][y] = 0;
								}
							}
						}
						if (napravlenie == 'R' || napravlenie == 'r')
						{
							for (int i = 0; i < tip; i++)
							{
								if (provarkarasstanovki(tip) != 0)
								{
									Pole[x][y] = 1;
									x++;
								}
								else
								{
									cout << "������� ������� ����������!";
									Pole[x][y] = 0;
								}
							}
						}
					}
					if (pologenie == 'V' || pologenie == 'v')
					{
						cout << "�������� �����������(�����-U/����-D): ";
						cin >> napravlenie;
						if (napravlenie == 'U' || napravlenie == 'u')
						{
							for (int i = 0; i < tip; i++)
							{
								if (provarkarasstanovki(tip) != 0)
								{
									Pole[x][y] = 1;
									y--;
								}
								else
								{
									cout << "������� ������� ����������!";
									Pole[x][y] = 0;
								}
							}
						}
						if (napravlenie == 'D' || napravlenie == 'd')
						{
							for (int i = 0; i < tip; i++)
							{
								if (provarkarasstanovki(tip) != 0)
								{
									Pole[x][y] = 1;
									y++;
								}
								else
								{
									cout << "������� ������� ����������!";
									Pole[x][y] = 0;
								}
							}
						}
					}
				}
			} while (Pole[x][y] != 1);
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
				//cout << " ";
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
			if (!(Pole[x][y]))
			{
				cout << " |";
			}
			if (Pole[x][y] == 0)//���� � ������ ��� ������
			{
				//cout << " ";
				cout << " |";
				cout << " ";
			}
			if (Pole[x][y] == 1)//���� � ������ ���� �������
			{
				cout << " | | ";
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
/*int hodkomp()
{

}*/
/*int proverkapobedi()
{
	//������ ��������� ������� ������ �� ��������� ����� � � ������ ������ ������� �������� 20,��� � �������
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
	cout << "������ ��������� �������?\n ";
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