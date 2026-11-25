#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#define BUFFER_SIZE 100


//You are dynamically allocating memory for name.first and name.last here.
//Important note about our program, if the program takes redirected input throw the
//command line, it is undefined behavior and it is not our responsibility.
//It is only direct user input!
patient_t* new_patient(void){
    patient_t* patient1;
    int scanf_return;
    static int id = 0;
    if((patient1 = malloc(sizeof(patient_t))) == NULL)
        return NULL;

    patient1->id = ++id;

    char line_buffer[BUFFER_SIZE + 1];
    printf("Enter patient's first name: ");
    scanf("%100s", line_buffer);
    while(getchar() != '\n');

    patient1->name.first = malloc(strlen(line_buffer) + 1);
    if(patient1->name.first == NULL)
        return NULL;
    strcpy(patient1->name.first, line_buffer);

    memset(line_buffer, 0, sizeof(line_buffer));

    printf("Enter patient's last name: ");
    scanf("%100s", line_buffer);
    while(getchar() != '\n');

    patient1->name.last = malloc(strlen(line_buffer) + 1);
    if(patient1->name.last == NULL)
        return NULL;
    strcpy(patient1->name.last, line_buffer);

    printf("Enter patient's age: ");
    scanf("%d", &patient1->age);
    while(getchar() != '\n');

    sex_part:
    printf("Enter patient's sex: ");
    scanf(" %c", &patient1->sex);
    while(getchar() != '\n');
    if(patient1->sex != 'm' && patient1->sex != 'M' && patient1->sex != 'f' && patient1->sex != 'F'){
        fprintf(stderr, "Error: Invalid patient sex!\n");
        goto sex_part;
    }

    printf("Enter ");
    if(patient1->sex == 'm' || patient1->sex == 'M')
        printf("Mr. ");
    else if(patient1->sex == 'f' || patient1->sex == 'F')
        printf("Ms. ");
    printf("%s %s Telephone number in the forum(05XXXXXXXXX no space in between): ", patient1->name.first, patient1->name.last);
    scanf("%11s", line_buffer);
    strcpy(patient1->telephone, line_buffer);

    return patient1;
}

void print_patient_profile(node_t* head, int id){
    node_t* patient_temp = head;
    while(patient_temp != NULL && patient_temp->patient_profile->id != id)
        patient_temp = patient_temp->next;

    printf("ID: %d\n", patient_temp->patient_profile->id);

    printf("Full name: ");
    if(patient_temp->patient_profile->sex == 'm' || patient_temp->patient_profile->sex == 'M')
        printf("Mr. ");
    else if(patient_temp->patient_profile->sex == 'f' || patient_temp->patient_profile->sex == 'F')
        printf("Ms. ");
    printf("%s %s\n", patient_temp->patient_profile->name.first, patient_temp->patient_profile->name.last);

    printf("Age: %d\n", patient_temp->patient_profile->age);

    printf("Sex: %c\n", patient_temp->patient_profile->sex);

    printf("Telephone no: %s\n", patient_temp->patient_profile->telephone);

    return;
}

