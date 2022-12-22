#pragma once
#include <iostream>
#include <string>
using namespace std;
class Krutki
{
public:

	Krutki(int& haveGems, int& haveKrutok, int& pil, int& already, bool& coinflip);
	~Krutki();


	void GetAll();
	string isMusor(int i);
	string getKrstat(int i);

	string getfiveStar();
	string getmusor();
	string getgarant();
	int gethaveKritok();
	int getostatok();
	int getpil();

protected:
	

protected:
	unsigned int pil = 0;
	unsigned int ostatok = 0;
	unsigned int amountKrutok = 0;
	unsigned int fiveStar = 0;
	unsigned int already = 0;
	bool coinflip = true;
	unsigned int haveGems = 0;
	unsigned int haveKrutok = 0;
	unsigned int avg = 73;
	unsigned short int musor = 0;
	unsigned short int garant = 0;
	unsigned int ostatok_after = 0;
	bool* cfstat = nullptr;
	unsigned int* krstat = nullptr;
};

