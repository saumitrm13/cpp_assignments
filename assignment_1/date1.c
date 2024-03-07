#include<stdio.h>
#include<string.h>
struct Date{
    char day[3];
    char month[3];
    char year[5];
};

void initDate(struct Date *datePtr){
    strcpy(datePtr->day, "01");
    strcpy(datePtr->month, "01");
    strcpy(datePtr->year, "2001");
    printf("Date Created\n");
}

void printDateOnConsole(struct Date *datePtr){
    printf("Date : %s/%s/%s\n", datePtr->day, datePtr->month, datePtr->year);
}

void acceptDateFromConsole(struct Date *datePtr){
    int validDate = 0;
    while(validDate == 0){
        printf("Enter date in DD(enter)MM(enter)YYYY(enter) format : \n");
        scanf("%s %s %s", datePtr->day, datePtr->month, datePtr->year);
        if(strlen(datePtr->day)==2 && strlen(datePtr->month)==2 && strlen(datePtr->year)==4){
            validDate = 1;
        }
        else{
            printf("Enter a valid date\n");
        }
    }
}
int menu(){
    int choice; 
    
    printf("\nMenu:\n");
    printf("1. Create Date\n");
    printf("2. Accept Date From Console\n");
    printf("3. Print Date On Console\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if(choice == 0){
        printf("Program Exit\n");
    }
    
    return choice;
}

int main(){
    struct Date date;
    int choice;
    
    while((choice=menu())!=0){
        switch(choice) {
            case 1:
                initDate(&date);
                break;
            case 2:
                acceptDateFromConsole(&date);
                break;
            case 3:
                printDateOnConsole(&date);
                break;
            default:
                printf("Invalid choice. Enter a choice from 0 to 3.\n");
        }
    } 
    
    return 0;
}
