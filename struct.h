#ifndef STRUCT_H
#define STRUCT_H

#define TELEPHONE_LEN 11

struct name{
    char* first;
    char* last;
};

struct patient{
    int id;
    struct name name;
    int age;
    char sex;
    char telephone[TELEPHONE_LEN + 1];
};

typedef struct patient patient_t;

struct node{
    patient_t* patient_profile;
    struct node* next;
};

typedef struct node node_t;

#endif // STRUCT_H
