#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void Contactcreate(AddressBook *addressBook);
void Contactsearch(AddressBook *addressBook);
void Contactedit(AddressBook *addressBook);
void Contactdelete(AddressBook *addressBook);
void Contactslist(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);

#endif
