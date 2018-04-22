// Egor.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#define Bufsz 512
#define Max 100
using namespace std;

int percntr = 1;

struct Person{
	int Id;
	int Status;
	int FNum;
}Persons[Max];

void stringreader(char* string);

int findend(char* string, int index);

int getval(int beginval, int stopval, char* string);

bool checkin(int index, int status);

int addperson(int tmp, char* string, int status);

int numberff(void);

int main() {


	int NFr;
	scanf("%d", &NFr);

	for (int i = 0; i < Max; i++){
		Persons[i].Id = 0;
		Persons[i].FNum = 0;
		Persons[i].Status = 0;
	}

	char buf[Bufsz];
	for (int i = 0; i < Bufsz; i++)
	{
		buf[i] = 0;
	}

	for (int i = 0; i < NFr; i++){
		std::cin.getline(buf, 512);
		if (buf[0] == '\0') i--;
		stringreader(buf);
	}

	int FF = numberff();

	printf("%i", FF);
	getchar();
	return 0;
}


void stringreader(char* string){
	int i = 0;
	int flag = 0;
	int ffnum = 0;
	int counter = 0;
	if (string[i] == '\0') return;
	while (string[i] != '\0')//ïîêà íå ïåðåâîä ñòðîêè
	{
		if (string[i] == '\0')return;
		if (string[i] == ' ') i++;
		switch (flag)
		{
		case 0:{
				   int stop = addperson(i, string, 0);
				   i = stop + 1;
				   flag = 1;
				   break;
		}
		case 1:{
				   int beginval = i;
				   int stopval = findend(string, i);
				   ffnum = getval(beginval, stopval, string);
				   i = stopval + 1;
				   flag = 2;
				   break;
		}
		case 2:{
				   if (counter< ffnum){
					   int stop = addperson(i, string, 1);
					   i = stop + 1;
					   counter++;
				   }
				   else {
					   counter = 0;
					   flag = 3;
				   }
				   break;
		}
		case 3:{i++; }break;
		}
	}
	return;
}


int findend(char* string, int index){
	while (string[index] != ' ' && string[index] != '\0'){
		index++;
	}
	return index;
}

int getval(int beginval, int stopval, char* string){

	int len = stopval - beginval;

	char* tmpstr = new char[len];

	int i = 0;
	for (int j = beginval; j < stopval; j++){
		tmpstr[i] = string[j];
		i++;
	}
	int numb = atoi(tmpstr);
	delete tmpstr;
	return numb;
}

bool checkin(int index, int status){
	int i = 1;
	while (Persons[i].Id != 0)
	{
		if (index == Persons[i].Id)
		{
			if (Persons[i].Status != status && Persons[i].Status > status){
				Persons[i].Status = status;
			}
			return false;
		}
		i++;
	}
	return true;
}

int numberff(void){
	int val = 0;
	int i = 1;
	while (Persons[i].Id != 0)
	{
		if (Persons[i].Status == 1) val++;
		i++;
	}
	return val;
}

int addperson(int tmp, char* string, int status){
	int beginval = tmp;
	int stopval = findend(string, tmp);
	int index = getval(beginval, stopval, string);
	if (checkin(index, status) == true){
		Persons[percntr].Id = index;
		Persons[percntr].Status = status;
		Persons[percntr].FNum = percntr;
		percntr++;
	}
	return stopval;
}
