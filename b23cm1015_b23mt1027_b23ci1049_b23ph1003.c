#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <time.h>

int main();

long long int check()
{
    long long int bal;
	scanf("%lld",&bal);
    if(bal>10000000)
    {
        printf("Account Limit Exceeded!!\nAccount can not have more than 1 crore rupees\nEnter:");
        return check();
    }

    else return bal;
}

int pincheck(int pin, int i)
{
    int input, x;

    if(i<4)
    {
        scanf("%d", &input);
        if(pin != input)
        {
            printf("Your pin is incorrect\nTry again (try %d/3):", i);
            pincheck(pin, i+1);
        }
        else
        {
            x = 1;
            return x;
        }
    }
    else
    {
        printf("\nTransaction failed due to multiple failure\n");
        x = 0;
        return x;
    }   
}

int pin() 
{
    int input;
    scanf("%d", &input);
    if(input<=999 || input>=10000)
    {
        printf("Enter valid 4 digit pin:");
        pin(1);
    }
    else
    {
        return input;
    }
}

void addaccount()
{
    system("cls");

    int ac_pin;
    printf("Enter your desired pin:");
	ac_pin = pin(1);

    long long int bal;
    printf("Enter the amount of money in your bank account:");
    bal = check();

	srand(time(0));
    int i = (rand())%(899999) + 100000;

    char new_file[20];

    sprintf(new_file,"%d",i);
    strcat(new_file,".txt");

	FILE *fptr=fopen(new_file,"w");
	fprintf(fptr, "%d %lld",ac_pin, bal);
	fclose(fptr);

    printf("Your account is successfully made!!!\nYour account number is %d\n",i);
    fflush(stdin);
    printf("Press Enter to continue\n");
    getchar();
    
}

void checkbalance()
{
    system("cls");

    int accno, pin; 
    long long int bal;
    printf("Enter your account number:");
    scanf("%d", &accno);

    char acc[20];
    sprintf(acc, "%d", accno);
    strcat(acc, ".txt");

    FILE* fptr = fopen(acc, "r");

    if(fptr==NULL)
    {
        printf("The account number is incorrect\n");
        return;
    }

    {
        fscanf(fptr, "%d", &pin);
        fscanf(fptr, "%lld", &bal);

        printf("Enter your pin:");

        int i = pincheck(pin, 1);
        if(i==1)
        {  
            printf("Your account balance is %d\n", bal);
        }
    }
    fclose(fptr);
    fflush(stdin);
    printf("Press Enter to continue\n");
    getchar();
    main();
}

void deposit()
{
    system("cls");

    int accno, pin, amount,no_use; 
    long long int bal;
    printf("Enter your account number:");
    scanf("%d", &accno);

    char acc[20];
    sprintf(acc, "%d", accno);
    strcat(acc, ".txt");

    FILE* fptr = fopen(acc, "r");    
    
    if(fptr==NULL)
    {
        printf("The account number is incorrect\n");
        fflush(stdin);
        printf("Press Enter to continue\n");
        getchar();
        return;
    }

        fscanf(fptr, "%d", &pin);
        fscanf(fptr, "%lld", &bal);

        printf("Enter your pin:");

    int i = pincheck(pin, 1);
    if(i==1)
    {  
        printf("Enter the amount you want to deposit in your account: ");
        scanf("%d", &amount);
        if(amount<0)
        {
            printf("Invalid amount\n");
            fflush(stdin);
            printf("Press Enter to continue\n");
            getchar();
            return;
        }

        {
            fscanf(fptr, "%d", &pin);
            fscanf(fptr, "%d", &bal);
        }
        fclose(fptr);

        bal = bal + amount;

        printf("Your new balance is %d \n",bal);

        FILE* f = fopen(acc, "w");
        {
            fprintf(f, "%d %d", pin, bal);
        }
        fclose(f);
    }

    fflush(stdin);
    printf("Press Enter to continue\n");
    getchar();
    main();
}

void withdraw()
{
    system("cls");

    int accno, pin, amount; 
    long long int bal;
    printf("Enter your account number:");
    scanf("%d", &accno);

    char acc[20];
    sprintf(acc, "%d", accno);
    strcat(acc, ".txt");

     FILE* fptr = fopen(acc, "r");

    if(fptr==NULL)
    {
        printf("This account number is invalid\n");
        fflush(stdin);
        printf("Press Enter to continue\n");
        getchar();
        return;
    }

        fscanf(fptr, "%d", &pin);
        fscanf(fptr, "%lld", &bal);

    printf("Enter your pin:");

    int i = pincheck(pin, 1);
    if(i==1)
    {
        printf("Enter the amount you want to withdraw from your account:");
        scanf("%d", &amount);
        if(amount<0)
        {
            printf("Invalid amount\n");
            fflush(stdin);
            printf("Press Enter to continue\n");
            getchar();
            return;
        }
    
        {
            fscanf(fptr, "%d", &pin);
            fscanf(fptr, "%d", &bal);
        }
        fclose(fptr);
        
        int ac_bal=bal;
        
        if(amount>ac_bal) 
        {
            printf("Not enough balance \n");
            fflush(stdin);
            printf("Press Enter to continue\n");
            getchar();
            return;
        }

        else
        {
            bal = bal - amount;
            printf("Your new balance is %d \n",bal);
        }

        printf("Your new balance is %d \n",bal);

        FILE* f = fopen(acc, "w");
        {
            fprintf(f, "%d %d", pin, bal);
        }
        fclose(f);
        fflush(stdin);
        printf("Press Enter to continue\n");
        getchar();
        main();
    }    
}

void menu()
{
    system("cls");

    int x;
    printf("If you want to check current balance in your account press 1\nIf you want to deposit some money press 2\nIf you want to withdraw some moeny press 3\nPress 9 to quit\nEnter:");
    scanf("%d", &x);

    system("cls");

    while(1)
    {
        if(x==1)
        {
            checkbalance(1);
            return;
        }
        else if(x==2)
        {
            deposit(1);
            break;
        }
        else if(x==3)
        {
            withdraw(1);
            break;
        }
        else if(x==9)
        {
            // withdraw(1);
            // break;
            printf("Thank You\n");
          //  *y=9;
            break;
        }
        else
        {
            printf("Enter Valid Input\n");
            menu(&x);
            break;
        }
    }
}

int main()
{
    int x, y;

    while(x!=9)
    {
        system("cls");
        
        printf("Welcome user\nPress 1 to continue\nPress 9 to quit\nEnter:");
        scanf("%d", &x);
        
        system("cls");

        if(x==1)
        {
            printf("If you want to make an account press 1\nIf you already have an account press 2\nEnter:");
            scanf("%d", &y);

            system("cls");

            
            if(y==1)
            {
                addaccount(1);
                menu(&x);
                x = 9;
                break;
            }
            if(y==2)
            {
                menu(&x);
                x = 9;
                break;
            }
            else printf("Enter Valid Input");
        }
    }
}