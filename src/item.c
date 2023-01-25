#include "item.h"

void commandItemMenu(item** items) {
    
    int answer;
    int noOfItems = (sizeof(items)/sizeof(item*));

    system("cls");
    printItemMenu(items, noOfItems);
    printf("?: ");
    fflush(stdin);
    scanf("%d", &answer);
    puts("");

    int i = 0;

    // Have to use if-statement since we have a dynamic array
    while (i == 0) {
        if (answer == -1) {
            i = 1;
        }
        else if (answer >= 1 && answer <= noOfItems) {
            printItem(items[answer - 1]);
        }
        else {
            puts ("\nPlease enter a valid input!\n");
        }
        if (i == 0) {
            system("cls");
            printItemMenu(items, noOfItems);
            printf("?: ");
            fflush(stdin);
            scanf("%d", &answer); 
            puts("");
        }
    }
}

void printItemMenu(item** items, int num) {

    printf("What item would you like to examine?");
    for (int i = 1; i <= num; i++) {
        printf(i + ": ");
        printf(items[i]->name);
        puts("");
    }
}

void printItem(item* item) {
    // search for item name in item file and print its info
}