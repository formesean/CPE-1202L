#include <stdio.h>

typedef struct{
	char name[50];
	int age;
} team;

void displayTeam(team t){
	printf("\nTeam Name: %s" , t.name);
	printf("\nTeam Age: %d", t.age);
}

int main(){
	team teams[3];
	int choice;

	strcpy(teams[0].name, "Team A");
	teams[0].age = 10;
	strcpy(teams[1].name, "Team B");
	teams[0].age = 5;
	strcpy(teams[2].name, "Team C");
	teams[0].age = 15;
	
	printf("Select Team (1-3): ");
	scanf("%d", &choice);
	
	displayTeam(teams[choice-1]);
	
	return 0;
}

