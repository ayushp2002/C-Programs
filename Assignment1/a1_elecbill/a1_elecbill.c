#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int LIMITS[] = {1, 0, 1000, 5000,
                2, 0, 5000, 10000,
                3, 0, 100, 300, 600,
                -1};
const double PRICEMAP[] = {1, 5.5, 7.75, 9.75,
                     2, 6.5, 11.75, 13.25,
                     3, 0, 3.5, 4.75, 6.0,
                     -1};
const char *CATEGNAME[] = {"Institution", "Company", "Domestic"};
const char *NUMWORD[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

int printBill(char*, char*, int, int);
char *numtowords(int);

int main(int argc, char const *argv[]) {
    char cname[80], cnumb[10];
    int preread, curread, ccateg;

    printf("Customer Name: ");scanf("%s", &cname);
    printf("Customer Number: ");scanf("%s", &cnumb);
    printf("Customer category:\n[1]Institution\n[2]Company\n[3]Domestic\n>> ");scanf("%d", &ccateg);
    printf("Previous reading: ");scanf("%d", &preread);
    printf("Current reading: ");scanf("%d", &curread);
    
    printBill(cname, cnumb, ccateg, curread);
    return 0;
}

int printBill(char *custname, char *custnumb, int custcateg, int reading) {
    int categlimpos;
    int readtemp = reading;
    double totalprice = 0;

    /* Find the position of current category in the limits list */
    for (int i = 0; i < sizeof(LIMITS)/sizeof(LIMITS[0]); i++)
        if (LIMITS[i] == custcateg) {categlimpos = i;break;}

    printf("____________________________________________________________\n");
    printf("\t\t\tElectricity Bill\n");
    printf("____________________________________________________________\n");
    printf("Customer Name: %s\tCustomer Number: %s\nCustomer Category: %s\tUnits Consumed: %d", 
            custname, custnumb, CATEGNAME[categlimpos-1], reading);
    printf("\n____________________________________________________________\nAmount Details:");

    for (int i = categlimpos + 1; LIMITS[i]%10 == 0; i++) {
        double cost;
        if (reading > LIMITS[i+1] && LIMITS[i+1] % 10 == 0) {
            readtemp -= (LIMITS[i+1] - LIMITS[i]);
            if (custcateg == 3 && LIMITS[i] == 0) cost = 200;   // Special condition for Domestic
            else cost = PRICEMAP[i] * (LIMITS[i+1] - LIMITS[i]);
            
        } else { cost = PRICEMAP[i] * readtemp; readtemp = 0;}

        totalprice += cost;
        printf("\n\tBetween: %d - %d\t- %.2f", LIMITS[i]+1, LIMITS[i+1]%10==0?LIMITS[i+1]:reading, cost);
    }
    
    printf("\nTotal Amount\t\t\t- %.2f", totalprice);
    printf("\nAmount in words: \t\t- %s", numtowords((int)totalprice));
    printf("\n____________________________________________________________");
    return 0;
}

char *numtowords(int num) {
    int wordindexlist[10], numlen = 0, wordslen = 0, numtemp = num;
    for (int i = 0; num > 0; i++) {
        wordindexlist[i] = num%10;
        numlen++;
        wordslen += strlen(NUMWORD[num%10]) + 1;
        num /= 10;
    }
    char *str = NULL;
    str = malloc(wordslen);
    strcpy(str, "Rupees");   // Initialize with the first word
    for (int i = numlen-1; i >= 0; i--) { strcat(str, " ");strcat(str, NUMWORD[wordindexlist[i]]); }
    strcat(str, " Only");
    return str;
}