// Berkant_Matris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Berkant_Matris.h"
#include <time.h>

using namespace std;
#pragma once

int main()
{
	int matrisValue;
	int secenek;
	srand(time(NULL));
	//Matris deðeri alýnmýþtýr.
	cout << "Matris degeri giriniz: ";
	cin >> matrisValue;
	//Matris boyut kýsýtlarý tanýmlanmýþtýr.
	if (matrisValue < 5 || matrisValue > 25)
	{//Matris boyutu tekrar girilmesi için döngüye alýyoruz.
		do
		{
			cout << "Lutfen matris boyutunuzu 5 ve 25 arasinda seciniz\n";
			cout << "Matris degeri giriniz: ";
			cin >> matrisValue;

		} while (matrisValue < 5 || matrisValue >25);
	}
	int** matris = new int* [matrisValue];
	for (int i = 0; i < matrisValue; i++)
	{
		matris[i] = new int[matrisValue];
	}
	//matrisin içini random sayýlarla dolduruyoruz.
	for (int i = 0; i < matrisValue; i++)
	{
		for (int j = 0; j < matrisValue; j++)
		{
			matris[i][j] = rand() % 10;
			cout << matris[i][j] << " ";
		}
		cout << "\n";
	}
	//Her yapýlan doðru iþlemden veya yanlýþ iþlemden sonra menü gelmesi için döngü oluþturuyoruz.
	do {
		cout << "1-Sutun satir degistir\n";
		cout << "2-Tekleri basa al (satir)\n";
		cout << "3-Ters cevir (sutun)\n";
		cout << "4-Toplamlari yazdir\n";

		cin >> secenek;
		//Seçenekleri oluþturmak için switch case kullanýyoruz.
		switch (secenek) {
		case 1: {
			int satir, sutun;
			int* sutTemp = new int[matrisValue];
			int* satTemp = new int[matrisValue];
			int** temp = new int* [matrisValue];
			int toplam = 0;
			cout << "satir sutun:";
			cin >> satir >> sutun;
			//Kýsýtlar tanýmlandý ve eðer yanlýþsa switch den çýkacak
			if (satir <= 0 || satir > matrisValue || sutun <= 0 || sutun > matrisValue)
			{
				cout << "Lutfen boyutlari asmayiniz..\n";
				for (int i = 0; i < matrisValue; i++)
				{
					for (int j = 0; j < matrisValue; j++)
					{
						cout << matris[i][j] << " ";
					}
					cout << "\n";
				}
				break;
			}

			for (int i = 1; i < matrisValue + 1; i++)
			{
				for (int j = 1; j < matrisValue + 1; j++)
				{
					if (sutun == j)
					{
						sutTemp[i - 1] = matris[i - 1][j - 1];
					}
				}
				if (satir == i)
				{
					satTemp = matris[i - 1];
				}
			}

			toplam = (satTemp[satir - 1] + sutTemp[sutun - 1]);

			for (int i = 1; i < matrisValue + 1; i++)
			{
				if (satir == i)
				{
					matris[i - 1] = sutTemp;
				}
				for (int j = 1; j < matrisValue + 1; j++)
				{
					if ((i == satir && j == sutun))
					{
						matris[i - 1][j - 1] = toplam;
					}
					else if (sutun == j)
					{
						matris[i - 1][j - 1] = satTemp[i - 1];
					}
				}

			}
			for (int i = 0; i < matrisValue; i++)
			{
				for (int j = 0; j < matrisValue; j++)
				{
					cout << matris[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";

			break;
		}
		case 2: {
			int satir;
			int* tempMatris = new int[matrisValue];
			int temp;
			cout << "Satir numarasi giriniz: ";
			cin >> satir;
			if (satir <= 0 || satir > matrisValue)
			{
				cout << "Satir numarasi boyuttan buyuk olamaz... \n";
				for (int i = 0; i < matrisValue; i++)
				{
					for (int j = 0; j < matrisValue; j++)
					{
						cout << matris[i][j] << " ";
					}
					cout << "\n";
				}
				break;
			}
			for (int i = 1; i < matrisValue + 1; i++)
			{
				for (int j = 1; j < matrisValue + 1; j++)
				{
					if (satir == i)
					{
						tempMatris[j - 1] = matris[i - 1][j - 1];
					}
				}
			}

			for (int i = 0; i < matrisValue; i++) {
				if (tempMatris[i] % 2 == 0) {

					for (int j = i + 1; j < matrisValue; j++)
					{
						if (tempMatris[j] % 2 != 0)
						{
							temp = tempMatris[j];
							tempMatris[j] = tempMatris[i];
							tempMatris[i] = temp;
						}
					}
				}
			}
			for (int i = 1; i < matrisValue + 1; i++)
			{
				for (int j = 1; j < matrisValue + 1; j++)
				{
					if (satir == i)
					{
						matris[i - 1][j - 1] = tempMatris[j - 1];
					}
				}
			}
			for (int i = 1; i < matrisValue + 1; i++)
			{
				for (int j = 1; j < matrisValue + 1; j++)
				{
					cout << matris[i - 1][j - 1] << " ";
				}
				cout << "\n";
			}
			break;
		}
		case 3:
		{
			int sutun;
			int* tempMatris = new int[matrisValue];
			int temp = matrisValue;
			cout << "Sutun numarasi giriniz: ";
			cin >> sutun;

			if (sutun <= 0 || sutun > matrisValue)
			{
				cout << "Sutun numarasi boyuttan buyuk olamaz. \n";
				for (int i = 0; i < matrisValue; i++)
				{
					for (int j = 0; j < matrisValue; j++)
					{
						cout << matris[i][j] << " ";
					}
					cout << "\n";
				}
				break;
			}

			for (int i = 1; i < matrisValue + 1; i++)
			{
				for (int j = 1; j < matrisValue + 1; j++)
				{
					if (sutun == j)
						tempMatris[i - 1] = matris[i - 1][j - 1];
				}
			}
			for (int i = 1; i < matrisValue + 1; i++)
			{
				for (int j = 1; j < matrisValue + 1; j++)
				{
					if (sutun == j)
						matris[i - 1][j - 1] = tempMatris[temp - 1];
					cout << matris[i - 1][j - 1] << " ";
				}
				temp--;
				cout << "\n";
			}


			break;
		}
		case 4:
		{
			int toplam = 0;
			int temp = 0;
			int* tempMatris = new int[matrisValue * matrisValue];

			for (int i = 0; i < matrisValue; i++)
			{
				for (int j = 0; j < matrisValue; j++)
				{

					tempMatris[temp] = matris[i][j];
					toplam = toplam + matris[i][j];
					temp++;
				}

			}
			temp = 0;

			for (int i = 0; i < matrisValue; i++)
			{
				for (int j = 0; j < matrisValue; j++)
				{
					if (i == 0 && j == 0)
					{
						matris[i][j] = toplam;
						cout << matris[i][j] << " ";
					}
					else
					{
						toplam = toplam - tempMatris[temp + 1];
						matris[i][j] = toplam;
						cout << matris[i][j] << " ";
						temp++;
					}
				}
				cout << "\n";
			}

			break;
		}
		}
	} while (true);

}
