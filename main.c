//A PROGRAM THAT SIMULATES A ONLINE BANK MENU

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 0

// Function wich outputs the balance
void ShowBalance(double Balance);

// Function that deposits the money in the bank
double Deposit();

// Function that withdraws the money from the bank
double Withdraw(double balance);

// Function that outputs the main menu
void Menu();

int main(){

    double balance = 0;
    char choice;

    do{
        system("cls");
        Menu();
        switch(choice = getch()){
            
            case '0': // case 0: exits the menu
                    exit(0);
            case '1': // case 1: is the case that shows the balance from your "bank account" 
                system("cls");
                ShowBalance(balance);
                printf("\n\n Press any key to return to the main menu!");
                getch();
                break;

            case '2': // case 2: is the case dealing with deposit in your "bank account" 
                system("cls");
                balance += Deposit();
                printf("Successful transaction!"
                    "Thank you for your trust!"
                    "\n\n Press any key to return to the main menu!");
                getch();
                break;

            case '3': // case 3: is the case dealing with withdrawing from your "bank account" 
                system("cls");
                balance -= Withdraw(balance);
                printf("Successful transaction!"
                    "Thank you for your trust!"
                    "\n\n Press any key to return to the main menu!");
                getch();
                break;
            
            default: // default case: is the case dealing with inappropriate inputs
                printf("Please enter a valid choice!");
                getch();
                break;
        }

    }while(choice != ESC);
    return 0;
}

void ShowBalance(double balance){
    printf("Your balance is: $%.2lf", balance);
}

double Deposit(){

    double amount = 0;

    printf("\nPlease enter the amount of"
    " money you would like to deposit\n:$ ");
    scanf("%lf", &amount);

    if(amount > 0)
        return amount;
    else
        printf("\nPlease enter a valid amount!");
}

double Withdraw(double balance){
    
    double amount = 0;

    printf("\nPlease enter the amount of"
    " money you would like to withdraw\n:$ ");
    scanf("%lf", &amount);

    if(amount > balance)
        printf("\nInsufficient funds!");
    else
            return amount;
}

void Menu(){
    printf("*****Welcome to your online bank!*****"
            "\n\nTo select one of the options below, "
            "please press the key corresponding to the "
            "number presented in the square brackets."
            "\n\n [1] Show Balance"
            "\n [2] Deposit Money"
            "\n [3] Withdraw Money"
            "\n [0] Exit"
            "\n");
}
