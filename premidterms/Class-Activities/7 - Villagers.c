#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int data;
    int month;
    int year;
} Date;

typedef struct
{
    char fName[50];
    char mName;
    char lName[50];
} Name;

typedef struct
{
    char brgy[50];
    char city[50];
    int zip;
} Address;

typedef struct
{
    Name resName;
    Date resDate;
    Address resAdd;
} Resident;

Resident createResident(Name n, Date d, Address a);
Date createDate(int data, int month, int year);
Name createName(char *fName, char mName, char *lName);
Address createAddress(char *brgy, char *city, int zip);
Name *getAllResidentsIn(Resident *residents, char *city);
void displayDate(Date d);
void displayName(Name n);
void displayAddress(Address a);
void displayAllResident(Resident *residents);

Resident y = {{"", '\0', ""}, {0, 0, 0}, {"", "", 0}}; // let y be the sentinel

int main()
{
    // array of struct ang villagers
    // let y as default chuchu for intital elements; maybe @ [0]
    // each resident ari
    Resident residents[2] = {
        {{"Alexis", 'B', "Monsi"},
         {31, 1, 1995},
         {"Tisa", "Cebu City", 6000}},
        y};
    displayAllResident(residents);

    return 0;
}

Resident createResident(Name n, Date d, Address a)
{
    Resident r;

    r.resName = n; // name
    r.resDate = d; // date
    r.resAdd = a;  // address

    return r;
}

Date createDate(int data, int month, int year)
{
    /*sample
    data = 31;
    month = 1;
    year = 1995;*/
    Date d;
    d.data = data;
    d.month = month;
    d.year = year;

    return d;
}

Name createName(char *fName, char mName, char *lName)
{
    /*
    strcpy(fName, "Alexis");
    strcpy(mName, "B");
    strcpy(lName, "Monsi");*/

    // one variable for this func
    Name n;
    strcpy(n.fName, fName);
    // strcpy(n.mName, mName);
    n.mName = mName;
    strcpy(n.lName, lName);

    return n;
}

Address createAddress(char *brgy, char *city, int zip)
{
    /*sample
    strcpy(brgy, "Tisa");
    strcpy(city, "Cebu City");
    zip = 6000;*/
    Address a;
    strcpy(a.brgy, brgy);
    strcpy(a.city, city);
    a.zip = zip;

    return a;
}

Name *getAllResidentsIn(Resident *residents, char *city)
{
}
void displayDate(Date d)
{

    char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("%s %d %d\n", month[d.month - 1], d.data, d.year);
}
void displayName(Name n)
{
    printf("%s %c %s\n", n.fName, n.mName, n.lName);
}
void displayAddress(Address a)
{
    printf("%s %s %d\n", a.brgy, a.city, a.zip);
}

void displayAllResident(Resident *residents)
{
    // printf("\t\tNAME\t\t|\t\tBIRTHDATE\t\t|\t\tADDRESS\n");
    printf("%-20s | %-20s | %-20s\n", "NAME", "BIRTHDATE", "ADDRESS"); //%20-<20 characters will be formatted

    char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    for (int i = 0;; i++)
    {
        // check for sentinel value
        if (strcmp(residents[i].resName.fName, y.resName.fName) == 0)
        {
            break;
        }

        char fullName[100];
        strcpy(fullName, residents[i].resName.fName);
        strcat(fullName, " ");                             // adds space obv
        strncat(fullName, &residents[i].resName.mName, 1); // 1 means limit copy to 1 only
        strcat(fullName, ". ");
        strcat(fullName, residents[i].resName.lName);

        char date[10];
        if (residents[i].resDate.data < 10)
        {
            date[0] = '0';
            date[1] = residents[i].resDate.data + '0';
            date[2] = '\0';
        }
        else
        {
            sprintf(date, "%d", residents[i].resDate.data);
        }
        strcat(date, "-");
        strcat(date, month[residents[i].resDate.month - 1]);

        char address[60];
        strcpy(address, residents[i].resAdd.brgy);
        strcat(address, ", ");
        strcat(address, residents[i].resAdd.city);
        strcat(address, " ");
        char zipc[6];
        sprintf(zipc, "%d", residents[i].resAdd.zip);
        strcat(address, zipc);

        printf("%-20s | %-15s | %-30s\n", fullName, date, address);
    }
    printf("\n");
}

/*trashcan:

 // check for sentinel value
        if (strcmp(residents[i].resName.fName, y.resName.fName) == 0 &&
            residents[i].resName.mName == y.resName.mName &&
            strcmp(residents[i].resName.lName, y.resName.lName) == 0 &&
            residents[i].resDate.data == y.resDate.data &&
            residents[i].resDate.month == y.resDate.month &&
            residents[i].resDate.year == y.resDate.year)

     printf("\t");
        displayName(residents[i].resName);
        printf("\t|\t");
        displayDate(residents[i].resDate);
        printf("\t|\t");
        displayAddress(residents[i].resAdd);
        printf("\n");



            */
