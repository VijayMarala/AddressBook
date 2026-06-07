/************************************************
 * Name:Marala vijaya kumar reddy
 * Date:08/04/2026
 * Description:Addressbook
 ***********************************************/
#include <stdio.h>
#include<stdlib.h>
#include "contact.h"
#include"file.h"
int main() {
	AddressBook var;
	var.contactcount=0;
	var.contacts=NULL;
	int *contacts=malloc(var.contactcount*sizeof(Contact));
	loadContactsFromFile(&var);          //Loading contacts from file
	int ch;
	do
	{
		printf(" Enter your option\n");
		printf("1.add contact\n");
		printf("2.delete contact\n");
		printf("3.search contact\n");
                printf("4.list all contact\n");
	        printf("5.Edit contact\n");
		printf("6.Save and exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			 case 1:
				printf("add contact\n");
				createContact(&var);            //To create one contact information
				break;
			 case 2:
                printf("delete contact\n");
				deleteContact(&var);            //To delete one existing contact
                break;
			 case 3:
                printf("search contact\n");
				searchContact(&var);            //searching contacts from file
                break;
			 case 4:
                printf("list all contacts\n");
				listContacts(&var);             //print all contacts available in file
                break;
			 case 5:
                printf("edit contact\n");
				editContact(&var);              //Edit existing contact
                break;
			 case 6:
                printf("save and Exit\n");
                saveContactsToFile(&var);       //Save contacts to file
				return 0;
			 default:
				printf("Enter correct option\n");
		}
	}
	while(ch!=6);
        return 0;
}
