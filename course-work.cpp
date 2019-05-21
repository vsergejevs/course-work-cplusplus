
#include "pch.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "stdio.h"

#define MAX_SIZE 1000

using namespace std;

//define number of constants
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

//declaring max size for structure 'car' and 'service'
struct car cars[MAX_SIZE];
struct service servs[MAX_SIZE];
//
int num_cars = 0;
int num_servs = 0;

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
	for (;;)
	{
		cout << "Enter:" << endl;
		cout << "1 - select for car" << endl;
		cout << "2 - select for service" << endl;
		cout << "3 - exit program" << endl;

		cin.getline(s, 9);
		n = atoi(s);
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

// select atskiras
void select(int V)
{
	char buf[20];
	//char *buf;
	//if (V == CAR) buf = "cars";
	//if (V == SERV) buf = "services";

	if (V == CAR) strcpy_s(buf, 20, "cars");
	if (V == SERV)  strcpy_s(buf, 20, "services");


	cout << "1 - add " << buf << endl;
	cout << "2 - show " << buf << endl;
	cout << "3 - find " << buf << endl;
	cout << "4 - srt " << buf << endl;
	cout << "5 - del " << buf << endl;
	cout << "6 - save to file " << buf << endl;
	cout << "7 - load from file " << buf << endl;

	char s[10];
	int n;
	cin.getline(s, 9);
	n = atoi(s);

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
	}
}

// append ir vienadas
void append(int V)
{
	cin.clear(); // new code
	fflush(stdin);

	if (V == CAR)
	{
		cout << "Enter brand: ";
		cin.getline(cars[num_cars].brand, 50); //new code
		// TO DO accepts string max 50 symbols 
		//check getline built in function 

		while (!word_num(cars[num_cars].brand))
		{
			cout << "Wrong! Repeat: ";
			cin.getline(cars[num_cars].brand, 50); //new code
		}

		cout << "Enter model: ";
		cin.getline(cars[num_cars].model, 50);

		while (!word_num(cars[num_cars].model))
		{
			cout << "Wrong! Repeat: ";
			cin.getline(cars[num_cars].model, 50); //new code
		}

		cout << "Enter owner: ";
		cin.getline(cars[num_cars].owner, 50);

		while (!word_num(cars[num_cars].owner))
		{
			cout << "Wrong! Repeat: ";
			cin.getline(cars[num_cars].owner, 50); //new code
		}

		num_cars++;
	}

	if (V == SERV)
	{
		cout << "Enter name: ";
		cin.getline(servs[num_servs].name, 50);

		while (!word_num(servs[num_servs].name))
		{
			cout << "Wrong! Repeat: ";
			cin.getline(servs[num_servs].name, 50); //new code
		}

		cout << "Enter address: ";
		cin.getline(servs[num_servs].address, 50);

		while (!word_num(servs[num_servs].address))
		{
			cout << "Wrong! Repeat: ";
			cin.getline(servs[num_servs].address, 50); //new code
		}

		cout << "Enter phone: ";
		cin.getline(servs[num_servs].phone, 50);

		while (!phone(servs[num_servs].phone))
		{
			cout << "Wrong! Repeat: ";
			cin.getline(servs[num_servs].phone, 50); //new code
		}

		num_servs++;
	}
}

// print ir vienadas 
void print(int V)
{
	int i;
	if (V == CAR)
	{
		cout << "brand\t" << "model\t" << "owner" << endl;
		for (i = 0; i < num_cars; i++)
			cout << cars[i].brand << "\t" << cars[i].model << "\t" << cars[i].owner << endl;
	}

	if (V == SERV)
	{
		cout << "name\t" << "address\t" << "phone" << endl;
		for (i = 0; i < num_servs; i++)
			cout << servs[i].name << "\t" << servs[i].address << "\t" << servs[i].phone << endl;
	}
}

// find select ir vienadas
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

// srt select ir vienadas
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

// del select ir vienadas
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

// find ir vienadas
void find(int V1, int V2)
{
	int i;
	char buf[100];
	int count = 0;

	cin.clear(); // new code
	fflush(stdin);
	// TO DO - check cin and fflush built in function functions 
	// data stream - check wiki

	if (V1 == SERV && V2 == NAME)
	{
		cout << "Enter name for find: ";
		cin.getline(buf, 50);
		cout << "Name:\t" << "\t" << "Address:\t" << "Phone:" << endl;

		for (i = 0; i < num_servs; i++)
			if (!strcmp(servs[i].name, buf))
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

// del ir vienadas
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

// srt ir vienadas
void srt(int V1, int V2)
{
	int i, j, min_j;
	struct service smin, stmp;
	struct car cmin, ctmp;

	if (V1 == SERV && V2 == NAME)
	{
		for (i = 0; i < num_servs; i++)
		{
			min_j = i;
			smin = servs[i];

			for (j = i + 1; j < num_servs; j++)
				if (strcmp(servs[j].name, smin.name) < 0)
				{
					smin = servs[j];
					min_j = j;
				}

			stmp = servs[i];
			servs[i] = smin;
			servs[min_j] = stmp;
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

// write_files atskiras v4.cpp faila ir visual studio compiler compatible kodu
void write_file(int V)
{
	char fname[50];

	if (V == SERV)
	{
		cout << "Enter file name: ";
		cin >> fname;
		FILE * hfile;
		fopen_s(&hfile,fname,"w");
		fwrite(&servs[0], sizeof(struct service), num_servs, hfile);
		fclose(hfile);
	}

	if (V == CAR)
	{
		cout << "Enter file name: ";
		cin >> fname;
		FILE * hfile;
		fopen_s(&hfile,fname,"w");
		fwrite(&cars[0], sizeof(struct car), num_cars, hfile);
		fclose(hfile);
	}
}

// read_file atskiras no v4.cpp faila ar visual studio compiler compatible kodu
void read_file(int V)
{
	int i;
	char fname[50];

	if (V == SERV)
	{
		i = 0;
		cout << "Enter file name: ";
		cin >> fname;
		FILE * hfile;
		fopen_s(&hfile,fname,"w");
		while (fread(&servs[i], sizeof(struct service), 1, hfile))
			i++;
		num_servs = i;
		fclose(hfile);
	}

	if (V == CAR)
	{
		i = 0;
		cout << "Enter file name: ";
		cin >> fname;
		FILE * hfile;
		fopen_s(&hfile,fname,"w");
		while (fread(&cars[i], sizeof(struct car), 1, hfile))
			i++;
		num_cars = i;
		fclose(hfile);
	}
}

// ir vienadas
bool word_num(char* str)
{
	for (int i = 0; i < strlen(str); i++)
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'z') || str[i] == ' '))
			return false;
	return true;
}

// bool ir vienadas
bool phone(char* str)
{
	for (int i = 0; i < strlen(str); i++)
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'))
			return false;
	return true;
}
