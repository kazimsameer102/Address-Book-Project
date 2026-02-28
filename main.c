/*
    1.  Name: KAZIM

    2.  Register No: 25031_164

    3.  Project Title: Address Book

    4.  Description: The Address Book is designed using C program. It maintains and manage the personal 
                     contact information include name, phone number and email id.

    5.  Sample Input: Address Book Menu:
                      1. Create contact
                      2. Search contact
                      3. Edit contact
                      4. Delete contact
                      5. List all contacts
                      6. Save contacts
                      7. Exit
                      Enter your choice: 1
                      Enter the name: Deepak
                      Enter the phone number: 7094818524
                      Enter the email ID: deepak25@gmail.com

    6.  Sample Output: Contact Created Successfully

    7.  Project Submission Date: 12/12/2025
*/

#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book
    int sortChoice=0;
    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                Contactcreate(&addressBook);
                break;
            case 2:
                Contactsearch(&addressBook);
                break;
            case 3:
                Contactedit(&addressBook);
                break;
            case 4:
                Contactdelete(&addressBook);
                break;
            case 5:          
                Contactslist(&addressBook);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
       return 0;
}
