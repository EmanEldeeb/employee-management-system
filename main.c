#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void textattr(int );
void gotoxy(int , int );
void addEmployee(void );
void searchById(void);
void displayAllEmp(void);
void editEmp(void);
void deleteEmp(void);


struct Employee {
    char name[50];
    char age[5];
    char id[10];
    char salary[20];
    char bonus[20];
};
int employeeCount = 0;
 struct Employee employees[100];
void main() {
    int choice = 0;



    while (1) {
        system("cls");
        textattr(0x07);
        printf("Main Menu\n");

         if (choice == 0) {
            textattr(0x0E);
            printf("> New\n");
            textattr(0x07);
            printf("  DisplayID\n");
            printf("  DisplayAll\n");
            printf("  edit\n");
            printf("  Delete\n");
            printf("  Exit\n");

        } else if (choice == 1) {
               textattr(0x07);
            printf("  New\n");
            textattr(0x0E);
            printf("> DisplayID\n");
            textattr(0x07);
            printf("  DisplayAll\n");
             printf("  edit\n");
            printf("  Delete\n");
            printf("  Exit\n");
        } else if (choice == 2) {
            textattr(0x07);
            printf("  New\n");
            printf("  DisplayID\n");
            textattr(0x0E);
            printf("> DisplayAll\n");
               textattr(0x07);
                printf("  edit\n");
            printf("  Delete\n");
            printf("  Exit\n");
        }
        else if (choice == 3) {
            textattr(0x07);
            printf("  New\n");
            printf("  DisplayID\n");
            printf("  DisplayAll\n");
            textattr(0x0E);
            printf("> edit\n");
            textattr(0x07);
            printf("  Delete\n");
            printf("  Exit\n");

        }else if (choice == 4) {
            textattr(0x07);
            printf("  New\n");
            printf("  DisplayID\n");
            printf("  DisplayAll\n");
            printf("  edit\n");
            textattr(0x0E);
            printf("> Delete\n");
            textattr(0x07);
            printf("  Exit\n");
        }else if (choice == 5) {
            textattr(0x07);
            printf("  New\n");
               printf("  DisplayID\n");
            printf("  DisplayAll\n");
             printf("  edit\n");
            printf("  Delete\n");
            textattr(0x0E);
            printf("> Exit\n");
        }

        char ch = getch();
        if (ch == -32) {
            ch = getch(); // Extended key

            if(ch==77){
                break;
            }else if(ch==75){
            choice=0;}

            if (ch == 72) { // Up arrow
                if(choice==0){
                    choice=5;
                }else  choice--;}
            else if (ch == 80) { // Down arrow
                    if(choice==5){
                    choice=0;
                }
                else  choice++;}}

            //enter
            else if (ch == 13) {
              if (choice == 0) {
                 addEmployee();

            }
           else if (choice == 1) {
                searchById();
                getch(); // Wait for a key press
            }
            else if (choice == 2) {
                    displayAllEmp();
                    getch(); // Wait for a key press

            }
            else if (choice == 3){
                    editEmp();


                    }
            else if(choice==4){
                  deleteEmp();
                    }

            else if (choice == 5) {

                break;
            }
        }
    }

}

void addEmployee(void ){
    system("cls");
                   gotoxy(0, 2);
                    printf("Name: ");

                    gotoxy(20, 2);
                    printf("Age: ");

                    gotoxy(10, 0);
                    printf("Id: ");

                    gotoxy(0, 4);
                    printf("Salary: ");

                    gotoxy(20, 4);
                    printf("Bonus: ");

                    gotoxy(14, 0);
                    scanf("%s",  employees[employeeCount].id);
                    gotoxy(5, 2);
                    scanf("%s", employees[employeeCount].name);
                    gotoxy(25, 2);
                    scanf("%s", employees[employeeCount].age);

                    gotoxy(8, 4);
                    scanf("%s",  employees[employeeCount].salary);
                    gotoxy(26, 4);
                    scanf("%s", employees[employeeCount].bonus);

                    employeeCount++;
}
//////
void searchById(void){
                  // Display by ID
                system("cls");
                printf("Enter Employee ID: ");
                char searchId[10];
                scanf("%s", searchId);
                int found = 0;
                for (int i = 0; i < employeeCount; i++) {
                    if (strcmp(employees[i].id, searchId) == 0) {
                        printf("#############Employee Found#############\n");
                        printf("Name: %s\n", employees[i].name);
                        printf("Age: %s\n", employees[i].age);
                        printf("ID: %s\n", employees[i].id);
                        printf("Salary: %s\n", employees[i].salary);
                        printf("Bonus: %s\n", employees[i].bonus);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Employee with ID %s not found.\n", searchId);
                }
}

//////////
void displayAllEmp(void){

          system("cls");
          for (int i = 0; i < employeeCount; i++) {
              printf("Employee %d:\n", i + 1);
              printf("Name: %s\n", employees[i].name);
              printf("Age: %s\n", employees[i].age);
              printf("Id: %s\n", employees[i].id);
              printf("Salary: %s\n", employees[i].salary);
              printf("Bonus: %s\n", employees[i].bonus);
              printf("\n");
    }
}


void editEmp(void){

                system("cls");
                int eCount;
                printf("Enter Employee ID:  ");
                char searchId[10];
                scanf("%s", searchId);
                printf("\n\n");
                int found = 0;
                for (int i = 0; i < employeeCount; i++) {
                    if (strcmp(employees[i].id, searchId) == 0) {
                        eCount=i;
                        gotoxy(0, 2);
                        printf("Name: %s", employees[i].name);
                        gotoxy(20, 2);
                        printf("Age: %s\n", employees[i].age);
                         gotoxy(10, 1);
                        printf("ID: %s\n", employees[i].id);
                        gotoxy(0, 4);
                        printf("Salary: %s\n", employees[i].salary);
                        gotoxy(20, 4);
                        printf("Bonus: %s\n", employees[i].bonus);
                        found = 1;
                        break;
                    }
                }

                    gotoxy(14, 1);
                    scanf("%s",  employees[eCount].id);
                    gotoxy(5, 2);
                    scanf("%s", employees[eCount].name);
                    gotoxy(25, 2);
                    scanf("%s", employees[eCount].age);

                    gotoxy(8, 4);
                    scanf("%s",  employees[eCount].salary);
                    gotoxy(26, 4);
                    scanf("%s", employees[eCount].bonus);
                if (!found) {
                    printf("Employee with ID %s not found.\n", searchId);
                }
};

void deleteEmp(void){
            system("cls");
            int demp;
            printf("Enter Employee ID: ");
            char searchId[10];
            scanf("%s", searchId);
            int found = 0;

            for (int i = 0; i < employeeCount; i++) {
                if (strcmp(employees[i].id, searchId) == 0) {
                    demp = i;
                    found = 1;
                    break;
                }
            }

            if (found) {
                for (int i = demp; i < employeeCount - 1; i++) {
                    employees[i] = employees[i + 1];
                }
                employeeCount--; // Decrement the employee count
                printf("Employee with ID %s has been deleted.\n", searchId);
            } else {
                printf("Employee with ID %s not found.\n", searchId);
            }
}

void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
