#include<iostream>
#include<string>
#include<cstring>
#include"Header.h"
using namespace std;

cricketteam::cricketteam()
{
	membernames = nullptr;
	no_of_members = -1;
	Rank = -1;
	captain = ' ';
	teamName = nullptr;
	for (int i = 0; i < 10; i++)
	{
		Scoreinlast10matches[i] = -1;
	}

}
void cricketteam::namesize(int size)
{
	teamName = new char[size + 1];
}
void cricketteam::totalmember(int size)
{
	membernames = new string[size];
}
char cricketteam::getteamName()
{
	return *teamName;
}
void cricketteam::setteamName(string name)
{
	if (teamName != nullptr)
	{
		delete teamName;
	}
	teamName = new char[name.length() + 1];
	strcpy(teamName, name.c_str());
}
int cricketteam::getRank()
{
	return Rank;
}
void cricketteam::setRank(int r)
{
	Rank = r;
}
string cricketteam::getcaptain()
{
	return captain;
}
void cricketteam::setcaptain(string cap)
{
	captain = cap;
}
int cricketteam::getno_of_members()
{
	return no_of_members;
}
void cricketteam::setno_of_members(int members)
{
	no_of_members = members;
}
cricketteam::cricketteam(string filepath)
{
	string name;
	filepath = "cricket.txt";
	ifstream fin(filepath.c_str());
	getline(cin, name);
	cout << name;
	getline(fin, name, ':');
	getline(fin, name, '\n');
	int a = name.length();
	for (int i = 0; i < a; i++)
	{
		teamName[i] = name[i];
	}
	cout << teamName;
	teamName = 0;
	getline(fin, name, ':');
	getline(fin, name, '\n');
	int b = stoi(name);
	no_of_members = b;
	for (int i = 0; i < no_of_members; i++)
	{
		getline(fin, name, '\n');
		membernames[i] =name ;
	}
	getline(fin, name, ':');
	getline(fin, name, '\0');
	Rank = stoi(name);
	getline(fin, name, ':');
	getline(fin, name, '\0');
	captain = name;
	for (int i = 0; i < 10; i++)
	{
		getline(fin, name , ',');
		Scoreinlast10matches[i] = stoi(name);
	}
}


void cricketteam::input(int size)
{
	cout << "Enter size of teamname:";
	int x; 
	cin >> x;
	namesize(x);
	cout << "Enter teamname:";
	cin>> teamName;
	cout << "Enter the size of team members:";
	cin >> size;
	totalmember(size);
	for (int i = 0; i < size; i++)
	{
		getline(cin, membernames[i]);
		if (i == size - 1)
			cout << "There is no place for new team member: \n";
	}
	cout << "Enter Rank of team:";
	cin >> Rank;
	cout << "Enter Name of Captain:";
	getline(cin, captain);
}
int cricketteam::avgscore()
{
	
	int average = 0,x=0;
	for (int i = 0; i < 10; i++)
	{
		x = x + Scoreinlast10matches[i];
	}
	average = x / 10;
	return average;
}
void cricketteam::print()
{
	cout << "Team Name";
	cout << teamName;
	cout << " Captain Name is ";
	cout << "Teamrank:";
		cout<< Rank ;
		if (no_of_members != -1)
		{
			cout << "Number of members:";
				cout<< no_of_members ;
		}
		cout << "Captain name:";
	cout<< captain ;
	if (Scoreinlast10matches[9] != -1)
	{
		cout << "Latest score:";
		cout << Scoreinlast10matches[9];
	}
}
void cricketteam::inputScoreonconsole(int &score)
{
	int *buff,size=11;
	buff = new int[size];
	for (int i = 2; i < size; i++)
	{
		buff[i - 1] = Scoreinlast10matches[i];
	}
	int i = 11;
	Scoreinlast10matches[i] = score;
	buff[i - 1] = Scoreinlast10matches[i];
}
cricketteam::~cricketteam()
{
	delete [] membernames;
	delete teamName;
}
