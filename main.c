/****************************************************************
 * Name  : C-Clinic_waiting_room                                *
 * About : A program, that uses structures, dynamic memory      *
 *        allocation and linked lists, to store and manage the  *
 *        order and data of patients and their appointments     *
 *        time and order.                                       *
 * Date  : 24.11.2026                                           *
 * Author: Ammar MULLAOGLU                                      *
 ****************************************************************/

 /***************************************************************
  * Plan : 1. Build a struct to store the patients data in it   *
  *        2. Have patients data stored dynamically with allo-  *
  *           cation.                                           *
  *        3. Connect them throw linked lists.                  *
  *        4. Have the ability to remove, add nodes, like a     *
  *           stack.                                            *
  *        5. Show the appointments and have the ability to     *
  *           check next patient.                               *
  ***************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "functions.h"
#include "linked_list.h"

int main()
{
    char temp_char;
    node_t* head = NULL;
    patient_t* patient_temp;

    int id;

    system("title C-Clinic_waiting_room v0.1");
    printf("%40s\n", "C-Clinic_waiting_room v0.1");
    printf("%30s\n\n", __DATE__);

    printf("\n\nEnter:\n");
    printf("n for new appointment.\n");
    printf("d for deleting appointment.\n");

    while(1){
        printf("\nEnter op code: ");
        scanf(" %c", &temp_char);
        while(getchar() != '\n');
        printf("\n");

        switch(temp_char){
        case 'n':
            patient_temp = new_patient();
            if(patient_temp == NULL){
                fprintf(stderr, "Error: Malloc function failed!\n");
                return -1;
            }

            if(create_appointment(&head, patient_temp) == NULL){
                fprintf(stderr, "Error: Malloc function failed!\n");
                return -1;
            }
            break;
            //

        case 'd':
            printf("Enter patient's ID number to delete: ");
            scanf("%d", &id);
            while(getchar() != '\n');
            delete_appointment(&head, id);
            break;
        case 'p':
            printf("Enter patient's ID to print his profile info: ");
            scanf("%d", &id);
            while(getchar() != '\n');
            print_patient_profile(head, id);
            break;
        case 'l':
            print_list(head);
            break;
        case 'q':
            return 0;
        default:
            printf("Error: Invalid op code!\n");
            break;
        }
    }
}
