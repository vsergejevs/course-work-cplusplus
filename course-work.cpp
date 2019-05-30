/// This file contains the 'main' function. Program execution begins and ends there.

//including directives
#include "pch.h"
#include <iostream>
#pragma warning(disable: 4996)
#include <cstring>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

using namespace std;

//define number of constants - TODO: just a fancy way of declaring constants?
enum { CAR, SERV };
enum { BRAND, MODEL, OWNER };
enum { NAME, ADDR, PHONE };

//declaring a structure 'car' and 'service' a user defined data type
struct car
{
	char brand[50];
	char model[50];
	char owner[50];
};

struct service
{
	char name[50];
	char address[100];
	char phone[20];
};

//declaring structure variables
//setting amount for structure 'car' and 'service' members
struct car cars[MAX_SIZE];
struct service servs[MAX_SIZE];
//TODO: declaring these for...having counters? - identifikator/index etoi zapisi v massive
int num_cars = 0;
int num_servs = 0;


//declaring programm functions
void select(int);
void find_select(int);
void srt_select(int);
void del_select(int);
void append(int);
void print(int);
void find(int, int);
void srt(int, int);
void write_file(int);
void read_file(int);
void del(int, int);
bool word_num(char*);
bool phone(char*);

int main()
{

	char s[10];
	int n;
	for (;;) //endless for loop
	{
		cout << "Greetings human!" << endl;
		cout << "Please choose one of the following options to proceed:" << endl;
		cout << "1 - Choose to work with cars" << endl;
		cout << "2 - Choose to work with services" << endl;
		cout << "3 - Exit application" << "\n" << endl;


		cin.getline(s, 9); //TODO: I am writing 9 instead of 10 because...
		n = atoi(s); //transforming string to integer as switch did not read properly initial int
		switch (n)
		{
		case 1:
			select(CAR);
			break;
		case 2:
			select(SERV);
			break;
		case 3:
			return 0;
		default:
			return 0;
		}
	}
	return 0;
}

void select(int V)
{
	char buf[20];


	//using strcpy_s(dst, sizeof dst, src) because assigning a value produced errors and didn't work
	//TODO: change buf to something else
	if (V == CAR) strcpy_s(buf, 20, "cars");
	if (V == SERV)  strcpy_s(buf, 20, "services");


	cout << "1 - Add " << buf << endl;
	cout << "2 - Show " << buf << endl;
	cout << "3 - Find " << buf << endl;
	cout << "4 - Sort " << buf << endl;
	cout << "5 - Delete " << buf << endl;
	cout << "6 - Save to file " << buf << endl;
	cout << "7 - Load from file " << buf << endl;
	cout << "8 - Open main menu " << buf << "\n" << endl;

	char s[10];
	int n;
	cin.getline(s, 9); //TODO: I am writing 9 instead of 10 because...i have to save space for last null char inside string
	n = atoi(s); //transforming string to integer as switch did not work properly

	switch (n)
	{
	case 1:
		append(V);
		break;
	case 2:
		print(V);
		break;
	case 3:
		find_select(V);
		break;
	case 4:
		srt_select(V);
		break;
	case 5:
		del_select(V);
		break;
	case 6:
		write_file(V);
		break;
	case 7:
		read_file(V);
		break;
	case 8:
		main();
		break;
	}
}
//add new entries to structure
void append(int V)
{
	//clear input stream
	cin.clear();
	fflush(stdin);

	if (V == CAR)
	{
		cout << "Enter brand: ";
		cin.getline(cars[num_cars].brand, 50); //save new brand entries to structure cars

		while (!word_num(cars[num_cars].brand)) //check if user has entered forbidden characters
		{
			cout << "Forbidden character entered, please try again: ";
			cin.getline(cars[num_cars].brand, 50);
		}

		cout << "Enter model: ";
		cin.getline(cars[num_cars].model, 50); //save new model entries to structure cars

		while (!word_num(cars[num_cars].model))
		{
			cout << "Forbidden character entered, please try again: ";
			cin.getline(cars[num_cars].model, 50);
		}

		cout << "Enter owner: ";
		cin.getline(cars[num_cars].owner, 50); //save new owner entries to structure cars

		while (!word_num(cars[num_cars].owner))
		{
			cout << "Forbidden character entered, please try again: ";
			cin.getline(cars[num_cars].owner, 50);
		}

		num_cars++;
	}

	if (V == SERV)
	{
		cout << "Enter name: ";
		cin.getline(servs[num_servs].name, 50); //save new service entries to structure servs

		while (!word_num(servs[num_servs].name)) //check if user has entered forbidden characters
		{
			cout << "Forbidden character entered, please try again: ";
			cin.getline(servs[num_servs].name, 50);
		}

		cout << "Enter address: ";
		cin.getline(servs[num_servs].address, 50);

		while (!word_num(servs[num_servs].address))
		{
			cout << "Forbidden character entered, please try again: ";
			cin.getline(servs[num_servs].address, 50);
		}

		cout << "Enter phone: ";
		cin.getline(servs[num_servs].phone, 50);

		while (!phone(servs[num_servs].phone))
		{
			cout << "Forbidden character entered, please try again: ";
			cin.getline(servs[num_servs].phone, 50);
		}

		num_servs++;
	}
	cout << "\n";
}

void print(int V)
{
	int i;
	if (V == CAR)
	{
		cout << "brand\t" << "model\t" << "owner" << endl;
		for (i = 0; i < num_cars; i++)
			cout << cars[i].brand << "\t" << cars[i].model << "\t" << cars[i].owner << endl; //print to screen car entries
	}

	if (V == SERV)
	{
		cout << "name\t" << "address\t" << "phone" << endl;
		for (i = 0; i < num_servs; i++)
			cout << servs[i].name << "\t" << servs[i].address << "\t" << servs[i].phone << endl; //print to screen service entries
	}
}

//checks how to find cars or services and calls the appropriate function
void find_select(int V)
{
	char s[10];
	int n;
	if (V == CAR)
	{
		cout << "1 - find car by brand" << endl;
		cout << "2 - find car by model" << endl;
		cin.getline(s, 9);
		n = atoi(s);

		switch (n)
		{
		case 1:
			find(CAR, BRAND);
			break;
		case 2:
			find(CAR, MODEL);
			break;
		}
	}

	if (V == SERV)
	{
		cout << "find service by name" << endl;
		find(SERV, NAME);
	}
}

//checks how to sort cars or services and calls the appropriate function
void srt_select(int V)
{
	char s[10];
	int n;
	if (V == CAR)
	{
		cout << "1 - srt car by brand" << endl;
		cout << "2 - srt car by model" << endl;
		cin.getline(s, 9);
		n = atoi(s);

		switch (n)
		{
		case 1:
			srt(CAR, BRAND);
			break;
		case 2:
			srt(CAR, MODEL);
			break;
		}
	}

	if (V == SERV)
	{
		cout << "srt service by name" << endl;
		srt(SERV, NAME);
	}
}

//checks how to delete cars or services and calls the appropriate function
void del_select(int V)
{
	char s[10];
	int n;
	if (V == CAR)
	{
		cout << "1 - del car by brand" << endl;
		cout << "2 - del car by model" << endl;
		cin.getline(s, 9);
		n = atoi(s);

		switch (n)
		{
		case 1:
			del(CAR, BRAND);
			break;
		case 2:
			del(CAR, MODEL);
			break;
		}
	}

	if (V == SERV)
	{
		cout << "del service by name" << endl;
		del(SERV, NAME);
	}
}


void find(int V1, int V2)
{
	int i;
	char buf[100];
	int count = 0;
	cin.clear();  // clears data stream
	fflush(stdin);


	if (V1 == SERV && V2 == NAME)
	{
		cout << "Enter name for find: ";
		cin.getline(buf, 50);
		cout << "Name:\t" << "\t" << "Address:\t" << "Phone:" << endl;

		for (i = 0; i < num_servs; i++)
			if (!strcmp(servs[i].name, buf)) //TODO: does this says "if not false (if is true) then execute cout servs[i].name ?" - I can write this in a differrent way - strcmp(servs[i].name, buf) == 0
			{
				cout << servs[i].name << "\t" << servs[i].address << "\t" << "\t" << servs[i].phone << endl;
				count++;
			}
		cout << "Count of result = " << count << endl << endl;
	}

	if (V1 == CAR && V2 == BRAND)
	{
		cout << "Enter brand for find: ";
		cin.getline(buf, 50);
		cout << "Brand:\t" << "Model:\t" << "Owner:" << endl;

		for (i = 0; i < num_cars; i++)
			if (!strcmp(cars[i].brand, buf))
			{
				cout << cars[i].brand << "\t" << cars[i].model << "\t" << cars[i].owner << endl;
				count++;
			}
		cout << "Count of result = " << count << endl << endl;
	}

	if (V1 == CAR && V2 == MODEL)
	{
		cout << "Enter model for find: ";
		cin.getline(buf, 50);
		cout << "Brand:\t" << "Model:\t" << "Owner" << endl;

		for (i = 0; i < num_cars; i++)
			if (!strcmp(cars[i].model, buf))
			{
				cout << cars[i].brand << "\t" << cars[i].model << "\t" << cars[i].owner << endl;
				count++;
			}
		cout << "Count of result = " << count << endl << endl;
	}
}


void del(int V1, int V2)
{
	int i;
	char buf[100];
	int count = 0;

	cin.clear(); // new code
	fflush(stdin);

	if (V1 == SERV && V2 == NAME)
	{
		cout << "Enter name for find: ";
		cin.getline(buf, 50);

		for (i = 0; i < num_servs; i++)
			if (!strcmp(servs[i].name, buf))
			{
				memcpy(&servs[i], &servs[i + 1], (num_servs - i - 1) * sizeof(struct service));
				//TODO: onto the first one I am copying the second one and the third operation is how much bytes i have to copy
				//
				num_servs--;
				count++;
			}
		cout << "Count of result = " << count << endl << endl;
	}

	if (V1 == CAR && V2 == BRAND)
	{
		cout << "Enter brand for find: ";
		cin.getline(buf, 50);

		for (i = 0; i < num_cars; i++)
			if (!strcmp(cars[i].brand, buf))
			{
				memcpy(&cars[i], &cars[i + 1], (num_cars - i - 1) * sizeof(struct car));
				num_cars--;
				count++;
			}
		cout << "Count of result = " << count << endl << endl;
	}

	if (V1 == CAR && V2 == MODEL)
	{
		cout << "Enter model for find: ";
		cin.getline(buf, 50);

		for (i = 0; i < num_cars; i++)
			if (!strcmp(cars[i].model, buf))
			{
				memcpy(&cars[i], &cars[i + 1], (num_cars - i - 1) * sizeof(struct car));
				num_cars--;
				count++;
			}
		cout << "Count of result = " << count << endl << endl;
	}
}


void srt(int V1, int V2) //Mazakie cipari/vertibas uzpeld uz augsu
{
	int i, j, min_j;            //initializing indexing
	struct service smin, stmp; //declaring structure variables
	struct car cmin, ctmp;     //declaring structure variables

	if (V1 == SERV && V2 == NAME)
	{
		for (i = 0; i < num_servs; i++) //looping through the num_servs counter
		{
			min_j = i; //TODO: min_j piešķiru i indeksa skaitli
			smin = servs[i]; //TODO: smin iekšā pieglabāju servs[i] vardu/ciparu, to kas tur ir pieglabats uz to bridi
			//tas ir vienlidzigs ciparam 5, kas ir pirmais no cipariem
			//standart algoritma sortirovki
			
			cout << "min_j vertiba sobrid ir: " << min_j << endl;
			cout << "smin struktura sobrid pieglaba " << smin.name << endl << endl;

			for (j = i + 1; j < num_servs; j++) //TODO: what is happening here
				print(SERV);
				if (strcmp(servs[j].name, smin.name) < 0) //salidzinu vai 8 ir vienads ar 5
					//ja vini ir vienadi tad funkcija atgriezis nulli 0
					//ja servs[j].name pirmais nesakrītošais burts pec alfabeta ar smin.name burtu ir priekšā tam (piemērs a un z) tad funkcija atgriež, ka ir mazāks par nulli < 0
					//ja strcmp() ir mazāks par nulli tad smin piešķir servs[j] vērtību, t.i. skaitli 8
					//un min_j kļūst par skaitli 1
					//servs[j].name < smin.name 5
					//ishem minimalnij element
					
				{
					cout << "si ir otra iteracija numur " << j << endl;
					cout << "servs[j].name " << servs[j].name << " ir jabut prieksa smin.name " << smin.name << " pec alfabeta" << endl << endl;
					smin = servs[j]; //TODO: smin iekšā pieglabāju servs[j] ierakstu, tas vienmēr būs nākamais ieraksts aiz servs, pirmā iterācijā tas ir 8
					min_j = j; //TODO: min_j pieglabaju j indeksu/skaititaju
					
					
				}

			stmp = servs[i]; //TODO: menjajut mestami dva elementa massiva eti tri stroki
			servs[i] = smin; //TODO: swap function in c++ - check it out
			servs[min_j] = stmp; //TODO: what is happening here
			//swap(servs[i], servs[min_j]);
			//video par burbula metodi
			cout << "si ir pirma iteracija numur " << i << endl;
			
		}
		print(SERV);
	}

	if (V1 == CAR && V2 == BRAND)
	{
		for (i = 0; i < num_cars; i++)
		{
			min_j = i;
			cmin = cars[i];

			for (j = i + 1; j < num_cars; j++)
				if (strcmp(cars[j].brand, cmin.brand) < 0)
				{
					cmin = cars[j];
					min_j = j;
				}

			ctmp = cars[i];
			cars[i] = cmin;
			cars[min_j] = ctmp;
		}
		print(CAR);
	}


	if (V1 == CAR && V2 == MODEL)
	{
		int i, j, min_j;
		struct car cmin, tmp;
		for (i = 0; i < num_cars; i++)
		{
			min_j = i;
			cmin = cars[i];

			for (j = i + 1; j < num_cars; j++)
				if (strcmp(cars[j].model, cmin.model) < 0)
				{
					cmin = cars[j];
					min_j = j;
				}

			ctmp = cars[i];
			cars[i] = cmin;
			cars[min_j] = ctmp;
		}
		print(CAR);
	}
}


void write_file(int V)
{
	char fname[50];

	if (V == SERV)
	{
		cout << "Enter file name: ";
		cin.getline(fname, 50);
		FILE* hfile = fopen(fname, "w"); //Open the file, create new if necessary
		fwrite(&servs[0], sizeof(struct service), num_servs, hfile); //TODO: What happens here lidzigs memcpy 1. njemam jecheikas adresi atmina 2. njemam strukturas izmeru baitos 3. berem razmer skolko u nas zapisi 4. kopiruem v file hfile
		fclose(hfile); //Closing the opened/created file
	}

	if (V == CAR)
	{
		cout << "Enter file name: ";
		cin.getline(fname, 50);
		FILE* hfile = fopen(fname, "w");
		fwrite(&cars[0], sizeof(struct car), num_cars, hfile);
		fclose(hfile);
	}
}


void read_file(int V)
{
	int i;
	char fname[50];

	if (V == SERV)
	{
		i = 0;
		cout << "Enter file name: ";
		cin.getline(fname, 50);
		FILE* hfile = fopen(fname, "r");
		while (fread(&servs[i], sizeof(struct service), 1, hfile))
			i++;
		num_servs = i;
		fclose(hfile);
	}

	if (V == CAR)
	{
		i = 0;
		cout << "Enter file name: ";
		cin.getline(fname, 50);
		FILE* hfile = fopen(fname, "r");
		while (fread(&cars[i], sizeof(struct car), 1, hfile))
			i++;
		num_cars = i;
		fclose(hfile);
	}
}


bool word_num(char* str) //compares each string character so it contains letters, numbers or spaces
{
	for (int i = 0; i < strlen(str); i++)
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'z') || str[i] == ' '))
			return false;
	return true;
}


bool phone(char* str) //compares each string character so it contains numbers, minus or a plus sign
{
	for (int i = 0; i < strlen(str); i++)
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'))
			return false;
	return true;
}
