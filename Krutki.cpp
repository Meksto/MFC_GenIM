#include "pch.h"
#include "Krutki.h"
#include <iostream>
#include <string>

using namespace std;

Krutki::Krutki(int& haveGems, int& haveKrutok, int& pil, int& already, bool& coinflip)
{
	//cout << "Количество имеющихся примогемов на данный момент: ";
	this->haveGems = haveGems;
	//cout << "Количество имеющихся целых круток на данный момент: ";
	this->haveKrutok = haveKrutok;
	//cout << "Количество звёздной пыли: ";
	this->pil = pil;
	//cout << "Уже откручено: ";
	this->already = already;
	/*cout << "Прошлым 5* был персонаж из баннера?(0-No/1-Yes)" << endl;*/
	this->coinflip = coinflip;
}

Krutki::~Krutki()
{
	delete[] cfstat;
	delete[] krstat;
}

string Krutki::isMusor(int i)
{
	if (cfstat[i] == false)
		return "Мусор";
	else
		return "Гарант";
}

string Krutki::getKrstat(int i)
{
	return to_string(krstat[i]); 
}

string Krutki::getfiveStar()
{
	return to_string(fiveStar);
}

string Krutki::getmusor()
{
	return to_string(musor);
}

string Krutki::getgarant()
{
	return to_string(garant);
}

int Krutki::gethaveKritok()
{
	return haveKrutok;
}

int Krutki::getostatok()
{
	return ostatok;
}

int Krutki::getpil()
{
	return pil;
}

void Krutki::GetAll()
{
	ostatok = haveGems - ((haveGems / 160) * 160);
	haveKrutok += (haveGems / 160) + (pil / 5);
	pil = pil - ((pil / 5) * 5);



	// ЗНАЧЕНИЯ ВЫШЕ ПЕРЕПИСАТЬ СРАЗУ, ПОСЛЕ ВЫПОЛНЕНИЯ КОДА НИЖЕ ОНИ ЗАТИРАЮТСЯ
	//Может стоит их взять на моменте передачи в конструктор??
	// 
	//cout << " Всего круток: " << haveKrutok << endl;
	//cout << " Среднее количество круток до легендарного: " << avg << endl;
	



	cfstat = new bool[((haveKrutok + already + pil / 5) / avg) + 1];
	krstat = new unsigned int[((haveKrutok + already + pil / 5) / avg) + 1];
	int i = 0;
	int j = 0;
	int sum = haveKrutok + already + (pil / 5);
	while (sum > avg)
	{
		pil = pil + 14;
		krstat[j++] = haveKrutok = sum = haveKrutok + already + (pil / 5) - avg; // крутки - гарант
		pil = pil - ((pil / 5) * 5);
		already = 0;
		if (coinflip) // если прошлый был 5* (true)
		{
			musor++;
			cfstat[i++] = false;
			coinflip = false;
		}
		else
		{
			garant++;
			cfstat[i++] = true;
			coinflip = true;
		}

		fiveStar++;

	}


	//cout << " Легендарных персонажей: " << fiveStar << endl;
	//cout << " Возможно мусорных: " << musor << " | " << "Кол-во персов из баннера: " << garant << endl;

	//cout << " ПОДОРОБНО " << endl;
	// 
	// 
				//for (int i = 0; i < fiveStar; i++)
				//{
					//cout << "#" << i + 1;
					//cout << " " + isMusor(i);
					//cout << "| Осталось круток: ";
					//cout << getKrstat(i) << endl;
				//}
				// 
				// 
	//cout << " Осталось круток: " << haveKrutok << endl;
	//cout << " Остаток гемов: " << ostatok << endl;
	//cout << " Осталось пыли: " << pil << endl;

}