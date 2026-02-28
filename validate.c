#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "contact.h"

int validate_name(char *name)
{
    int i;
    if(name[0]==' ')    //if first index of name should not contain space
    {
        printf("First Letter should not Contain space. Enter valid name\n");
        return 0;
    }
    for(i=0;name[i]!='\0';i++)
    {
        //name should contain only alphabets and space
        if(!((name[i]>='A' && name[i]<='Z') || (name[i]>='a' && name[i]<='z') || name[i]==' '))
        {
            printf("Name must contain only letters, Enter valid name\n");
            return 0;
        }
    }
    return 1;
}
int validate_phone(char *n)
{
    int i;
    int l=strlen(n); //store the length of phone number to l variable 
    if(l!=10)
    {
        //phone number must contain 10 digits 
        printf("Phone number must contain only 10 digits letters, Enter valid phone number\n");
        return 0;
    }
    for(i=0;i<l;i++)
    {
        //phone number should contain only numbers
        if(!(n[i]>='0' && n[i]<='9'))
        {
            printf("Phone number must contain only 10 digits letters, Enter valid phone number\n");
            return 0;
        }
    }
    return 1;
}
int phoneCompare(char *temp,AddressBook *addressBook)
{
    int i,flag=1;
    for(i=0;i<addressBook->contactCount;i++)
    {
        //finding the same phone number is appear or not
        if(strcmp(addressBook->contacts[i].phone,temp)==0)
        {
            printf("Phone number already exists, Enter different phone number\n");
            return 0;
        }
    }
    return 1;
}
int validate_mail(char *mail)
{
    int i;
    int l=strlen(mail);    //length of email is stored to l variable
    for(i=0;i<l;i++)
    {
        //email should not contain space
        if(mail[i]==' ')
        {
            printf("email does not contain space, plese Enter email without space\n");
            return 0;
        }
    }
    int a=0,d=0,pos=-1;
    for(i=0;i<l;i++)
    {
        //finding the index of @ symbol 
        if(mail[i]=='@')
        {
            a++;
            pos=i;  //assign the @ symbol ith index to pos variable
            if(i==0 || i==l-1) 
            { 
                printf("'@' symbol does not contain starting and last position, Enter valid mail\n");
                return 0;
            }
        }
    }
    if(a==0)
    {
        printf("email id must contain 1 '@' symbol\n");
        return 0;
    }
    if(a!=1)  //email should exactly one @ symbol
    {
        printf("email does not contain more than 1 '@' symbol,  Please Enter valid mail\n");
        return 0;
    }
    for(i=0;i<l;i++)
    {
        //finding the index of dot symbol
        if(mail[i]=='.')
        {
            d=1;
            if(i==l-1)
            {
                printf("dot symbol does not contain last position, Enter valid mail\n");
                return 0;
            }
            break;
        }
    }
    if(d==0) 
    {
        printf("email should contain atleast one dot symbol, Enter valid mail\n");
        return 0;
    }
    char temp[]="gmail.com";   //create one temporary char array
    int templen=strlen(temp);   //store the length of temporary char array to templen
    int j=0;
    if(l-(pos+1)!=templen)  //compare the length of email and length of temporary char array
    {
        
        printf("Enter valid mail\n");
        return 0;
    }
    else
    {
        for(i=pos+1;i<l;i++)
        {
            if(mail[i]!=temp[j++])   //compare the email and temporary char array after @ symbol position
            {
                printf("Enter valid mail\n");
                return 0;
            }
        }
    }
    for(int i=0;mail[i]!='\0';i++)
    {
        if(!(isalpha(mail[i]) || isdigit(mail[i]) || mail[i]=='@' || mail[i]=='.' ))
        {
            printf("Email contain only letters, digits, '@' and '.'\n");
            return 0;
        }
    }
    for(i=0;mail[i]!='\0';i++)
    {
        mail[i]=tolower(mail[i]);  //convert lowercase when storing the email
    }
    return 1;
}
int mailCompare(char *temp,AddressBook *addressBook)
{
    int i;
    for(i=0;i<addressBook->contactCount;i++)
    {
        //finding the same email is appear or not
        if(strcmp(addressBook->contacts[i].email,temp)==0)
        {
            printf("Email already exists, Enter different email\n");
            return 0;
        }
    }
    return 1;
}