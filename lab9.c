#include <stdio.h>
#include <stdbool.h>

float balance;
float amount;
int transNum;

float getAmount() {
    for (int x=1; x>0; x++) {
        printf("Enter amount (>0): ");
        scanf("%f", &amount);
        if (amount>0) {
            break;
        }
        printf("The amount should be greater than 0!\n");
    }
}

void initBalance(float amount) {
    balance=amount;
}

int displayMenu() {
    int cmd;
    for (int x=1;x>0;x++) {
        printf("Commands: 1=credit, 2=debit, 3=balance, 4=exit\n");
        scanf("%d",&cmd);
        if (cmd>0 && cmd<5) {
            break;
        }
        printf("Invalid Command!\n");
    }
    return cmd;
}

void creditMoney(float credit) {
    balance+=credit;
}

bool debitMoney(float debit) {
    if (debit<balance) {
        balance-=debit;
        countTransaction();
    } else {
        printf("Sorry, you don't have enough credit.\n");
    }
}

int countTransaction() {
    ++transNum;
 }

int main(){
    
    int cmd;
    float credit, debit;

    printf("Please enter initial balance.\n");
    initBalance(getAmount());
    while(1)    {
        
        cmd = displayMenu();
       
        switch (cmd) {
            case 1: credit=getAmount();
                    creditMoney(credit);
                    countTransaction();
                    break;
            case 2: debit=getAmount();
                    debitMoney(debit);
                    break;
            case 3: printf("Current balance: %.2f\n", balance);
                    break;
            case 4: printf("Final balance: %.2f\n", balance);
                    printf("Bye.\n");
                    transNum=6;
                    break;
        }
        if (transNum==5) {
            printf("Final balance: %.2f\n", balance);
            printf("You cannot have more than five transactions! Bye.\n");
            break;
        } else if (transNum>5) {
            break;
        }
    }

    return 0;
}