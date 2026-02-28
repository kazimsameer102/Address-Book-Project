#ifndef VALIDATE_H
#define VALIDATE_H

#include "contact.h"

int validate_name(char *name);
int validate_phone(char *phone);
int validate_mail(char *mail);
int phoneCompare(char *temp,AddressBook *addressBook);
int mailCompare(char *temp,AddressBook *addressBook);

#endif