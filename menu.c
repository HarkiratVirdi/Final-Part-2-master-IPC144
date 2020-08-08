#include "file_helper.h"

void clearKeyboard(void)
{
	while (getchar() != '\n');
	// empty execution code block on purpose
}

int getInt(void)
{
	char newline = 'x';
	int value = 0;
	while (newline != '\n')
	{
		scanf("%d%c", &value, &newline);
		if (newline != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &value, &newline);
		}
	}
	return value;
}

int displayMenu(struct SkierInfo* skiers, int size)
{
	int menu_option = 0;

	printf("************** X-Country Ski Race Reporting **************");
	printf("What would you like to do?");

	printf("0) Exit");
	printf("1) Print top 3 skiers in a category\n");
	printf("2) Print all skiers in a category\n");
	printf("3) Print last 3 skiers in a category\n");
	printf("4) Print winners in all categories\n");
	printf("Please select one of the option from above: ");
	menu_option = getIntInRange(0, 4);

	return menu_option;
}

	int menu(struct SkierInfo* skiers, int size)
	{
	int option = displayMenu();
	 
	 if(option==1){
	printTop3(skiers,size);
	}
	else if(option==2){
	printAll(skiers,size);
	}
	else if(option==3){
	printLast3(skiers,size);
	}
	else if(option==4){
	printWinners(skiers,size);
	}
    	return option;
	}
	

char getCategory() {

	printf("\nWhich category (S, M, L): ");
	char NewLine = 'x', c = '\0'; // default values 
	int value = 0;

	getchar();

	while (!value) {
		scanf("%c%c", &c, &NewLine);
		if (NewLine != '\n') { 		
			clearKeyboard();	
			printf("*** INVALID INPUT *** <Please enter a valid category (S, M, L)>: ");
			}
		else if (c != 'S' && c != 'L' &&
			c != 'M') {
			printf("*** INVALID INPUT *** <Please enter a valid category (S, M, L)>: ");
		}
		else {
			value = 1;
		}
	}

	return (c == 'S' || c == 'M' || c == 'L') ? 1 : 0; 
	}



void displayAgeGroup(const int age, char ageGroup)
{
	if (age >= 35) {
		strcpy(ageGroup, "Seniors");
	}
	else if (age >= 21 && age <= 34) {
		strcpy(ageGroup, "Adults");
	}
	else {
		strcpy(ageGroup, "Juniors");
	}
}

	void displayTime( double startTime, double finishTime, int withdrawn)
	{
		double timeDifference = finishTime - startTime;
		int hour;
		int minute;
		 if(withdrawn==1)
		 {
			 printf(" N/A");
		 }
		 //need to cast to convert decimal hours plus integer minutes
		 hour = (int)timeDifference;
		 minute = (int)(timeDifference * 60) % 60;
		 // does the character '0' should be included before minutes???? for HH:MM format???
		 if (minute < 10)
		 {
			 printf(" %d:0%d", hour, minute);
		 }
		 else if (minute >=10)
		 {
			 printf(" %d:%d", hour, minute);
		 }
	}

