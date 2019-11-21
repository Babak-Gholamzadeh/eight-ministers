#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int point(int);
int test(int);
void display(void);
char a[20][20];
int c;
int main()
{
	char ch;
	// randomize();
NewVazir:
	cout << "Enter the number for count vazir(4<=number):";
	cin >> c;
	if (c<4)
	{
		// clrscr();
		system("cls");
		cout << "Number not valid\n";
		goto NewVazir;
	}
	for (int i=0;i<c;i++)
		for (int j=0;j<c;j++)
			a[i][j]=' ';
	if (c==4 || c==6)
		a[1+rand()%(c-2)][0]='*';
	else
		a[rand()%c][0]='*';
	point(1);
	display();
	cout << "New?(Y/N):";
	ch=getch();
	if (ch=='y' || ch=='Y')
	{
		// clrscr();
		system("cls");
		goto NewVazir;
	}
	return 0;
}
int point(int n)
{
	char f;
	int i,j,p=0;
	for (int k=0;k<c;k++)
	{
		f='0';
		j=n-1;
		for (i=k-1;i>=0&&j>=0;i--)
		{
			if (a[i][j]=='*')
			{
				f='1';
				j=-1;
			}
			j--;
		}
		if (f=='1')
			continue;
		j=n-1;
		for (i=k+1;i<c&&j>=0;i++)
		{
			if (a[i][j]=='*')
			{
				f='1';
				j=-1;
			}
			j--;
		}
		if (f=='1')
			continue;
		for (i=0;i<n;i++)
			if (a[k][i]=='*')
			{
				f='1';
				break;
			}
		if (f=='1')
			continue;
		a[k][n]='.';
		p++;
	}
	if (p>0)
	{
		if (test(n)==1)
			return 1;
	}
	else
		return 0;
}
int test(int n)
{
	for (int i=0;i<c;i++)
	{
		if (a[i][n]=='.')
		{
			a[i][n]='*';
			if (n<c-1)
			{
				if (point(n+1)==1)
					return 1;
				else
					a[i][n]=' ';
			}
			else
				return 1;
		}
	}
	return 0;
}
void display()
{
	int i,j;
	// clrscr();
	system("cls");
	cout << " ";
	for (i=0;i<c;i++)
		if (i<9)
			cout << "     " << (i+1);
		else
			cout << "    " << (i+1);
	cout << "\n    ";
	for (i=0;i<c;i++)
		cout << "_____ ";
	for (i=0;i<c;i++)
	{
		if (i<9)
			cout << endl << (i+1) << "  |";
		else
			cout << endl << (i+1) << " |";
		for (j=0;j<c;j++)
		{
			if (a[i][j]!='*')
				cout << "     |";
			else
				cout << "  " << a[i][j] << "  |";
		}
		cout << "\n   |";
		for (j=0;j<c;j++)
			cout << "_____|";
	}
	cout << endl << endl;
}
