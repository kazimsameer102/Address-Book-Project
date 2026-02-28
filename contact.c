#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "validate.h"

void Contactslist(AddressBook *addressBook) 
{
    if(addressBook->contactCount==0)  //check if address book is empty or not
    {
        printf("No contacts available\n");
        return;   //if no contacts, exit the function
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        //print name,phone number and email of all contacts
        printf("Name: %s\n",addressBook->contacts[i].name);
        printf("Phone Number: %s\n",addressBook->contacts[i].phone);
        printf("Email: %s\n",addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void Contactcreate(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char name[20];   //declare temporary name as char array
    int i,res;

    //Name Validation
    printf("Enter the name:\n");
    //we execute atleast once thats why we take do-while loop
    do
    {
        scanf(" %[^\n]",name);   //get the name from the user
        res=validate_name(name);   //function calls for Name validation
    }while(res==0);  
    //Phone number validation
    char phn[15];  //declare char array for phone number
    int comp;
    printf("Enter the phone number\n");
    do
    {
        scanf(" %[^\n]",phn); 
        res=validate_phone(phn);    //function calls for Phone Number Validation
        comp=phoneCompare(phn,addressBook);  //function calls for compare the phone number 
    }while(res==0 || comp==0);
    //email validation
    char mail[100];  //declare char array for email
    printf("Enter the email id\n");
    do
    {
        scanf("%s",mail);      
        res=validate_mail(mail);   //function calls for email validation
        comp=mailCompare(mail,addressBook);
    } while (res==0 || comp==0);
    //copy the name,phone number and email to contacts of addressBook
    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phn);
    strcpy(addressBook->contacts[addressBook->contactCount].email,mail);
    addressBook->contactCount++;   //increment the contactCount of addressBook
    printf("Contact created successfully\n");
}

void Contactsearch(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int index,res,i;  
    char temp[20];
    printf("Search by\n");
    printf("1. Name\n2. Phone No\n3. Mail\n4. Exit\n");
    scanf("%d",&index); 
    //execute depends on the user given using switch case
    switch(index)   
    {
        case 1:
        for(int i=0;i<addressBook->contactCount;i++)  //list names of all contacts
        {
            printf("%s\n",addressBook->contacts[i].name);
        }
        printf("Enter the name:\n");
        do
        {
            scanf(" %[^\n]",temp);
            res=validate_name(temp);    //function calls for name validation
        } while (res==0);
        int flag=1;
        for(i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].name,temp)==0) //compare the two names
            {
                //if temporary name is inside the contacts of addressBook print name,phone number and email
                printf("Contact found\n");
                printf("Name: %s\n",addressBook->contacts[i].name);
                printf("Phone Number: %s\n",addressBook->contacts[i].phone);
                printf("Email ID: %s\n",addressBook->contacts[i].email);
                flag=0;  //flag reset
                break; //come out from for loop
            }
        }
        if(flag==1)   
        {
            //if temporary name is not inside the contacts of addressBook, print contact not found
            printf("No Contact found\n");
        }
        break;  //come out from switch case
        case 2:
        for(int i=0;i<addressBook->contactCount;i++) //list phone number of all contacts
        {
            printf("%s\n",addressBook->contacts[i].phone);
        }
        printf("Enter the Phone Number\n");
        do
        {
            scanf(" %[^\n]",temp);  //get the phone number from user
            res=validate_phone(temp);  //function calls for phone validation
        } while (res==0);
        flag=1;
        for(i=0;i<addressBook->contactCount;i++) 
        {
            if(strcmp(addressBook->contacts[i].phone,temp)==0) //compare the two phone number
            {
            //if temporary phone number is inside the contacts of addressBook print name,phone number and email
                printf("Contact found\n");
                printf("Name: %s\n",addressBook->contacts[i].name);
                printf("Phone Number: %s\n",addressBook->contacts[i].phone);
                printf("Email: %s\n",addressBook->contacts[i].email);
                flag=0; //flag reset
                break;  //come out from for loop
            }
        }
        if(flag==1)
        {
        //if temporary phone number is not inside the contacts of addressBook print contact not found
            printf("No Contact found\n");
        }
        break; //come out from switch case
        case 3:
        for(int i=0;i<addressBook->contactCount;i++)
        {
            printf("%s\n",addressBook->contacts[i].email); //list email of all contacts
        }
        //char temp[30];
        printf("Enter the email ID\n");
        do
        {
            scanf(" %[^\n]",temp);  // get the email from user
            res=validate_mail(temp); //function calls for email validation
        } while (res==0);
        flag=1;
        for(i=0;i<addressBook->contactCount;i++)  //compare two emails
        {
            if(strcmp(addressBook->contacts[i].email,temp)==0)
            {
            //if temporary email is inside the contacts of addressBook print name,phone number and email
                printf("Contact found\n");
                printf("Name: %s\n",addressBook->contacts[i].name);
                printf("Phone Number: %s\n",addressBook->contacts[i].phone);
                printf("Email: %s\n",addressBook->contacts[i].email);
                flag=0; //flag reset
                break;  //come out from for loop
            }
        }
        if(flag==1)
        {
        //if temporary email is not inside the contacts of addressBook print contact not found
            printf("No Contact found\n");
        }
        break;  //come out from switch case
        case 4:
        printf("Existing...\n");
        break;   //come out from switch case
        default:
        printf("Enter correct choice\n");
    }
}
void Contactedit(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    char temp[50];
    int choice,res;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%s\n",addressBook->contacts[i].phone); //list phone numbers of all contact
    }
    printf("Enter the phone number of contact\n");
    do
    {
        scanf(" %[^\n]",temp);   //get the phone number from user
        res=validate_phone(temp); //function calls for phone number validation
    } while (res==0);
    int index=-1;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone,temp)==0) //compare the two phone numbers
        {
            index=i;  //if phone numbers found assign the position to index variable
            break; //come out from the for loop
        }
    }
    if(index<0)
    {
        //if phone numbsers is not inside the contacts of addressBook print contact not found
        printf("No Contact found\n");
        return; //come out from the function
    }
    //list details of given phone number
    printf("Details of given Phone Number\n");
    printf("Name: %s\n",addressBook->contacts[index].name);
    printf("Phone Number: %s\n",addressBook->contacts[index].phone);
    printf("Email: %s\n",addressBook->contacts[index].email);
    printf("What you want to edit of this contact\n");
    printf("1. Name\n2. Phone Number\n3. Mail\n4. Exit\n");
    scanf("%d",&choice); //get the choice from user
    switch(choice)
    {
        case 1:  //if choice is 1, edit the name
        printf("Enter New Name\n");
        do
        {
            scanf(" %[^\n]",temp);  //get the name from user
            res=validate_name(temp);  //function calls for name validation
        }while (res==0);
        if(res) //check the value is 1 or not
        {
            strcpy(addressBook->contacts[index].name,temp); //copy the edited name to addressBook
            printf("Name Edited Successfully\n");
        }
        break;   //come out from switch case
        case 2:
        printf("Enter New Phone Number\n");
        do
        {
            scanf(" %[^\n]",temp);  //get the phone number from user
            res=validate_phone(temp); //function calls for phone validation
        }while (res==0);
        if(res)  //check the res value is 1 or not
        {
            strcpy(addressBook->contacts[index].phone,temp);  //copy the phone number to addressBook
            printf("Phone Number Edited Successfully\n");
        }
        break;  //come out from the switch case
        case 3:
        printf("Enter New email ID\n");
        do
        {
            scanf(" %[^\n]",temp);   //get the email from the user
            res=validate_mail(temp);   //function calls for email validation
        }while (res==0);
        if(res)  //check res value is 1 or not
        {
            strcpy(addressBook->contacts[index].email,temp);  //copy the email to addressBook
            printf("Email ID Edited Successfully\n");
        }
        break;  //come out from switch case
        case 4:
        printf("Existing...\n");
        break;  //come out from switch case
        default:
        printf("Enter Valid Choice\n");
    }
}

void Contactdelete(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char temp[50];  //declare temporary char array
    int choice,res,count=0,index=-1,option; //declare variables
    printf("what do you want to delete by?...\n");
    printf("1. Name\n2. Phone Number\n3. Email\n4. Exit\n");
    scanf("%d",&choice);  //get the choice from user for delete contact
    switch(choice)
    {
        case 1:  //if choice is 1, go to 1st case
        printf("Enter the Name you want to delete?\n");
        do
        {
            scanf(" %[^\n]",temp);    //get the name from user
            res=validate_name(temp);  //function calls for name validation
        } while(res==0);
        int pos[100],count=0;  
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].name,temp)==0) //compare two names
            {
                pos[count]=i;   //if name found assign the ith index to pos array
                count++;
            }
        }
        if(count==0)    //if name not found print Contact not found
        {
            printf("Contact Not found\n");
            break;
        }
        if(count>1)   
        {
            printf("Here, Multiple Same name with different phone number and emails\n");
            for(int i=0;i<count;i++)
            {
                int index=pos[i];
                printf("%d Name: %s\nPhone Number: %s\nEmail: %s\n",i+1,addressBook->contacts[index].name,addressBook->contacts[index].phone,addressBook->contacts[index].email);
            }
            printf("Enter which name of index do you want to delete (1 - %d)\n",count);
            int opt;
            scanf("%d",&opt);
            if(opt<1 || opt>count)  //check the option is valid or not
            {
                printf("Invalid option\n");
                break;
            }
            index=pos[opt-1];   //assign the option of pos array to index
        }
        else
        {
            index=pos[0];   //if count is 1 then assigth 0th position array to index
        }
        printf("Details of given Name\n");
        printf("Name: %s\n",addressBook->contacts[index].name);  //print the contact name
        printf("Phone Number: %s\n",addressBook->contacts[index].phone);  //print the contact phone number
        printf("Email: %s\n",addressBook->contacts[index].email); //print the contact email
        printf("Are you sure to delete this Contact? 1(Yes) or 0(No)\n");
        scanf("%d",&option); //get the option from user for confirming the delete contact
        if(option==1)
        {
            //if choice is 1, delete the contact
            for(int i=index;i<addressBook->contactCount-1;i++)
            {
                //contacts are shift left to fill deleted position
                addressBook->contacts[i]=addressBook->contacts[i+1];
            }
            addressBook->contactCount--;  //decrement the contactCount of addressBook
            printf("Deleted Successfully\n");
        }
        else
        {
            //if choice is 0 then print Not Deleted
            printf("Not Deleted\n");
        }
        break; //come out from the switch case
        case 2: //if choice is 2 go to 2nd case
        printf("Enter Phone Number you want to delete\n");
        do
        {
            scanf(" %[^\n]",temp);   //get the phone number from user
            res=validate_phone(temp);  //function calls for phone number validation
        } while(res==0);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].phone,temp)==0) //compare two phone numbers
            {
                index=i;  //if name found, assign the ith position to index
                break;   //come out from for loop
            }
        }
        if(index<0)  //if index is less than 0 then print contact not found
        {
            printf("No Contact found\n");
        }
        printf("Details of given Phone Numer\n");
        printf("Name: %s\n",addressBook->contacts[index].name);  //print the delete contact name
        printf("Phone Number: %s\n",addressBook->contacts[index].phone); //print the delete contact phone number
        printf("Email: %s\n",addressBook->contacts[index].email);  //print the delete contact email
        printf("Are you sure to delete this Contact? 1(Yes) or 0(No)\n");
        scanf("%d",&option); //confirm the contact is delete or not
        if(option==1)
        {
            //if choice is 1, delete the contact
            for(int i=index;i<addressBook->contactCount-1;i++)
            {
                //contacts are shift left to fill deleted position
                addressBook->contacts[i]=addressBook->contacts[i+1];
            }
            addressBook->contactCount--;  //decrement the contactCount of addressBook
            printf("Deleted Successfully\n");
        }
        else
        {
            //if option is 0 then print not deleted
            printf("Not Deleted\n");
        }
        break;  //come out from the switch case
        case 3:  //if choice is 3 go to 3rd case
        printf("Enter email id you want to delete\n");
        do
        {
            scanf(" %[^\n]",temp);  //get the email from user
            res=validate_mail(temp);   //function calls for email validation
        } while(res==0);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].email,temp)==0)  //compare two emails
            {
                index=i;  //if email found assign the ith position to index
                break;  //come out from the for loop
            }
        }
        if(index<0) 
        {
            //if index less than 0 print contact not found
            printf("Contact not found\n");
        }
        printf("Details of given email id\n");
        printf("Name: %s\n",addressBook->contacts[index].name);  //print the delete contact name
        printf("Phone Number: %s\n",addressBook->contacts[index].phone); //print the delete contact phone number
        printf("Email: %s\n",addressBook->contacts[index].email);  //print the delete contact email
        printf("Are you sure to delete this Contact? 1(Yes) or 0(No)\n");
        scanf("%d",&option);  //confirm the contact is delete or not
        if(option==1)
        {
            //if choice is 1 delete the contact
            for(int i=index;i<addressBook->contactCount-1;i++)
            {
                //contacts are shift left to fill deleted position
                addressBook->contacts[i]=addressBook->contacts[i+1];
            }
            addressBook->contactCount--;  //decrement the contactCount of addressBook
            printf("Deleted Successfully\n");
        }
        else
        {
            //if option is 0 print not deleted
            printf("Not Deleted\n");
        }
        break;          //come out from the switch case
        case 4:     //if choice is 4 go to 4th case
        printf("Exiting...\n");
        break;     //come out from swith case
        default:
        printf("Enter Valid Choice\n");
    }
}
