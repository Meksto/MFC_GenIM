#include "pch.h"
#include "Krutki.h"
#include <iostream>
#include <string>

using namespace std;

Krutki::Krutki(int& haveGems, int& haveKrutok, int& pil, int& already, bool& coinflip)
{
	//cout << "���������� ��������� ���������� �� ������ ������: ";
	this->haveGems = haveGems;
	//cout << "���������� ��������� ����� ������ �� ������ ������: ";
	this->haveKrutok = haveKrutok;
	//cout << "���������� ������� ����: ";
	this->pil = pil;
	//cout << "��� ���������: ";
	this->already = already;
	/*cout << "������� 5* ��� �������� �� �������?(0-No/1-Yes)" << endl;*/
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
		return "�����";
	else
		return "������";
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



	// �������� ���� ���������� �����, ����� ���������� ���� ���� ��� ����������
	//����� ����� �� ����� �� ������� �������� � �����������??
	// 
	//cout << " ����� ������: " << haveKrutok << endl;
	//cout << " ������� ���������� ������ �� ������������: " << avg << endl;
	



	cfstat = new bool[((haveKrutok + already + pil / 5) / avg) + 1];
	krstat = new unsigned int[((haveKrutok + already + pil / 5) / avg) + 1];
	int i = 0;
	int j = 0;
	int sum = haveKrutok + already + (pil / 5);
	while (sum > avg)
	{
		pil = pil + 14;
		krstat[j++] = haveKrutok = sum = haveKrutok + already + (pil / 5) - avg; // ������ - ������
		pil = pil - ((pil / 5) * 5);
		already = 0;
		if (coinflip) // ���� ������� ��� 5* (true)
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


	//cout << " ����������� ����������: " << fiveStar << endl;
	//cout << " �������� ��������: " << musor << " | " << "���-�� ������ �� �������: " << garant << endl;

	//cout << " ��������� " << endl;
	// 
	// 
				//for (int i = 0; i < fiveStar; i++)
				//{
					//cout << "#" << i + 1;
					//cout << " " + isMusor(i);
					//cout << "| �������� ������: ";
					//cout << getKrstat(i) << endl;
				//}
				// 
				// 
	//cout << " �������� ������: " << haveKrutok << endl;
	//cout << " ������� �����: " << ostatok << endl;
	//cout << " �������� ����: " << pil << endl;

}