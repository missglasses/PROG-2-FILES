#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int data;
    int month;
    int year;
}Date;

typedef struct {
    char *fName;
    char *mName;
    char *lName;
}Name;

typedef struct{
    char *brgy;
    char *city;
    int zip;
}Address;

typedef struct {
    Name *resName;
    Date *resDate;
    Address *resAdd;
}Resident;


Resident createResident(Name n, Date d, Address a);
Date createDate (int data, int month, int year);
Name createName (char *fName, char *mName, char *lName);
Address createAddress(char *brgy, char *city, int zip);
Name *getAllResidentsIn(Resident *residents, char *city);
void displayDate(Date d);
void displayName(Name n);
void displayAddress(Address a);
void displayAllResident(Resident *residents);

int main (){

    char months [12] ={"Jan", "Feb", "Mar", "Apr", "Jun", "Jul" ,"Aug", "Sep", "Oct", "Nov", "Dec"}; //idk pa how to apply from month to index+1

    //array of struct ang villagers
    //let y as default chuchu for intital elements; maybe @ [0]
    //each resident ari
    Resident resident[1] = {{"Alexis", 'B', "Monsi"}, {31,1,1995}, {"Tisa", "Cebu City", 6000}};




    return 0;
}

Resident createResident(Name n, Date d, Address a){
    Resident r;

    r.n = n;     //name
    r.d =d;     //date
    r.a = a;     //address

    return r;

}

Date createDate (int data, int month, int year){
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

Name createName (char *fName, char *mName, char *lName){
    /*
    strcpy(fName, "Alexis");
    strcpy(mName, "B");
    strcpy(lName, "Monsi");*/

    //one variable for this func
    Name n;
    strcpy(n.fName, fName);
    strcpy(n.mName, mName); 
    strcpy(n.lName, lName);

    return n;

}

Address createAddress(char *brgy, char *city, int zip){
    /*sample
    strcpy(brgy, "Tisa");
    strcpy(city, "Cebu City");
    zip = 6000;*/
    Address a;
    strcpy(a.brgy, brgy);
    strcpy(a.city, city);
    a.zip= zip;

    return a;
    
}

Name *getAllResidentsIn(Resident *residents, char *city){

}
void displayDate(Date d){
    printf("%s %d %d\n", d.month, d.data, d.year);
}
void displayName(Name n){
    printf("%s %s %s\n", n.fName, n.mName, n.lName);
}
void displayAddress(Address a){
    printf("%s %s %d\n", a.brgy,  a.city, a.zip);
}

void displayAllResident(Resident *residents){
    printf("\t\tNAME\t\t|\t\tBIRTHDATE\t\t|\t\tADDRESS\n");
    //    printf("\t\t%s %s %s\t\t", residents->resName->fName,residents->resName->mName, residents->resName->lName);
    //    printf("\t\t%s %s %s\t\t", residents->resName->fName,residents->resName->mName, residents->resName->lName);
    printf("\t\t\t\tNAME\t\t\t\t|\t\t\tBIRTHDATE\t\t|\t\tADDRESS\t\t\n");
    printf("\t\t\t%s %s %s\t\t", residents->resName->fName,residents->resName->mName, residents->resName->lName);
    printf("\t\t\t%s %d %d\t", residents->resDate->month, residents->resDate->data, residents->resDate->year);
    printf("\t\t%s %s %d\t\t", residents->resAdd->brgy, residents->resAdd->city, residents->resAdd->zip);
    printf("\n");
}
