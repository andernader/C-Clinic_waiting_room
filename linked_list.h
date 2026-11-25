#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "struct.h"

node_t* create_appointment(node_t** head, patient_t* patient1);
node_t* delete_appointment(node_t** head, int id);
void print_list(node_t* head);

#endif // LINKED_LIST_H
