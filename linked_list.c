#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

node_t* create_appointment(node_t** head, patient_t* patient1){ //check return type.
    node_t* new_appointment;
    node_t* temp = *head;
    if((new_appointment = malloc(sizeof(node_t))) == NULL)
        return NULL;

    new_appointment->patient_profile = patient1;

    if(*head == NULL)
        *head = new_appointment;
    else if(*head != NULL){
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_appointment;
    }
    new_appointment->next = NULL;
    return new_appointment;
}

node_t* delete_appointment(node_t** head, int id){
    node_t *cur, *prev;
    for(prev = NULL, cur = *head; cur != NULL && cur->patient_profile->id != id; prev = cur, cur = cur->next)
        ;
    if(cur == NULL)
        return *head;
    if(prev == NULL){
        *head = (*head)->next;
        free(cur->patient_profile->name.first);
        free(cur->patient_profile->name.last);
        free(cur->patient_profile);
        free(cur);
    }

    else{
        prev->next = cur->next;
        free(cur->patient_profile->name.first);
        free(cur->patient_profile->name.last);
        free(cur->patient_profile);
        free(cur);
    }
    return *head;
}

void print_list(node_t* head){
    if(head == NULL){
        printf("No appointments set!\n");
        return;
    }

    node_t* temp = head;
    while(temp != NULL){
        printf("%d. ", temp->patient_profile->id);

        if(temp->patient_profile->sex == 'm' || temp->patient_profile->sex == 'M')
            printf("Mr. ");
        else if(temp->patient_profile->sex == 'f' || temp->patient_profile->sex == 'F')
            printf("Ms. ");
        printf("%s %s\n", temp->patient_profile->name.first, temp->patient_profile->name.last);
        temp = temp->next;
    }
    return;
}
