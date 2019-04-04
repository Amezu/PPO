#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

//n – numberOfStudents

//dodaje studenta do listy
void AddStudent(int* n, char*** namesList, char*** surnamesList, int** yearsList, const char* firstName, const char* secondName, const char* surname, int year)
{
	if(*namesList == NULL) //lista pusta
	{
		//przydziela pamięć
		*yearsList = (int*)malloc(sizeof(int));
		*namesList = (char**)malloc(sizeof(char*));
		*surnamesList = (char**)malloc(sizeof(char*));

		//łączenie imion
		char *name = (char*)malloc(100*sizeof(char));
		strcpy(name, firstName);
		strcat(name, " ");
		strcat(name, secondName);

		//przypisywanie wartości
		(*yearsList)[*n] = year;
		(*surnamesList)[*n] = (char*)surname;
		(*namesList)[*n] = name;
	}
	else //lista niepusta
	{
		//przydziela pamięć
		*yearsList = (int*)realloc(*yearsList, (*n+1)*sizeof(int));
		*namesList = (char**)realloc(*namesList, (*n+1)*sizeof(char*));
		*surnamesList = (char**)realloc(*surnamesList, (*n+1)*sizeof(char*));
		
		//łączenie imion
		char *name = (char*)malloc(100*sizeof(char));
		strcpy(name, firstName);
		strcat(name, " ");
		strcat(name, secondName);

		//przypisywanie wartości
		(*yearsList)[*n] = year;
		(*surnamesList)[*n] = (char*)surname;
		(*namesList)[*n] = name;
	}
	(*n)++;
}

//wypisuje imiona lub nazwiska (ciągi znaków)
void PrintListContent(int n, char** List)
{
	for(int x=0; x<n; x++)
		std::cout<<List[x]<<std::endl;
}

//wypisuje lata (liczby)
void PrintListContent(int n, int* List)
{
	for(int x=0; x<n; x++)
		std::cout<<List[x]<<std::endl;
}

//wypisuje wszystko
void PrintListContent(int n, char** namesList, char** surnamesList, int* yearsList)
{
	for(int x=0; x<n; x++)
		printf("%s, %s - year %d\n", surnamesList[x], namesList[x], yearsList[x]);
}

//zmienia imię studenta
void RenameStudent(char*** namesList, const char* firstName, const char* secondName, int ID)
{
	//łączenie imion
	char *name = (char*)malloc(200*sizeof(char*));
	strcpy(name, firstName);
	strcat(name, " ");
	strcat(name, secondName);

	//zamiana imienia
	(*namesList)[ID-1] = name;
}

//usuwa studenta
void DeleteStudent(int* n, char*** namesList, char*** surnamesList, int** yearsList, int ID)
{
	//przesuwa wartości w tablicach
	for(int x=ID-1; x<*n-1; x++)
	{
		(*yearsList)[x] = (*yearsList)[x+1];
		(*surnamesList)[x] = (*surnamesList)[x+1];
		(*namesList)[x] = (*namesList)[x+1];
	}

	//aktualizuje liczbę studentów
	*n=*n-1;

	//zmienia rozmiar tablic
	*yearsList = (int*)realloc(*yearsList, (*n)*sizeof(int));
	*namesList = (char**)realloc(*namesList, (*n)*sizeof(char*));
	*surnamesList = (char**)realloc(*surnamesList, (*n)*sizeof(char*));
}

//kasuje listę studentów
void ClearStudents(int* n, char*** namesList, char*** surnamesList, int** yearsList)
{
	for(int x=0; x<*n; x++)
		free((*namesList)[x]);
	
	//zwalnianie pamięci
	free(*namesList);
	free(*surnamesList);
	free(*yearsList);

	//aktualizowanie liczby studentów
	*n=0;
}