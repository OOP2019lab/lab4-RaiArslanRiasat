#pragma once
#include <string>
using namespace std;

class cricketteam
{
	string * membernames;
	int no_of_members;
	char *teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;
public:
	cricketteam();
	void namesize(int size);
	void totalmember(int size);
	char getteamName();
	void setteamName(string name);
	int getRank();
	void setRank(int r);
	int getno_of_members();
	void setno_of_members(int members);
	string getcaptain();
	void setcaptain(string cap);
	cricketteam(string filepath);
	void input(int size);
	int avgscore();
	void print();
	void inputScoreonconsole(int &score);

	~cricketteam();
	
};
