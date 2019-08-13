#ifndef _CONTACT_H_
#define _CONTACT_H_

#include<stdio.h>
#include<stdlib.h>

typedef Contact* Contact;

typedef struct {
	char name[32];
	char sex;
	char age;
	char phonenum[13];
	char address[256];
}Contact;


#endif // !_CONTACT_H_

