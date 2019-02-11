#include<iostream>
#include"Header.h"
using namespace std;
int main()
{
	cricketteam team;
	string path = "file.txt";
	int size = 0;
	team.input(size);
	team.print();
	team.print();
	team.avgscore();
	system("pause");
	
}