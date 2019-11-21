#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int point(int);
int test(int);
const int c=8;
void display(void);
char a[c][c];
int main()
{
	char ch;
	// randomize();
NewVazir:
	for (int i=0;i<c;i++)
		for (int j=0;j<c;j++)
			a[i][j]=' ';
	a[rand()%c][0]='*';
	point(1);
	display();
	cout << "New?(Y/N):";
	ch=getch();
	if (ch=='y' || ch=='Y')
		goto NewVazir;
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
		cout << "     " << (i+1);
	cout << "\n    ";
	for (i=0;i<c;i++)
		cout << "_____ ";
	for (i=0;i<c;i++)
	{
		cout << endl << (i+1) << "  |";
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
