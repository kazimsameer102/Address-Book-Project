#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp=fopen("contacts.csv","w");   //open the file as write mode
    if(fp==NULL)  //check the file is empty or not
    {
        printf("No contacts in the file\n");
        return;
    }
    fprintf(fp,"#%d\n",addressBook->contactCount);  //print the contactCount of addressBook
    for(int i=0;i<addressBook->contactCount;i++)
    {
        //print the name,phone number and email of contacts of addressBook
        fprintf(fp,"%s",addressBook->contacts[i].name);
        fprintf(fp,"%c",',');
        fprintf(fp,"%s",addressBook->contacts[i].phone);
        fprintf(fp,"%c",',');
        fprintf(fp,"%s",addressBook->contacts[i].email);
        fprintf(fp,"\n");
        
    }
    fclose(fp); //close the file
    printf("Contacts Saved Successfully\n");
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp=fopen("contacts.csv","r");  //open the file as read mode
    if(fp==NULL)  //checking the file is empty or not
    {
        printf("No Contacts in this file\n");
        return;
    }
    rewind(fp);
    fscanf(fp,"#%d\n",&addressBook->contactCount);  //take the contactCount of addressBook
    for(int i=0;i<addressBook->contactCount;i++)
    {
        //take the name,phone number and email of contacts of addressBook
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);   //close the file
    printf("Loaded Successfully\n");
}
