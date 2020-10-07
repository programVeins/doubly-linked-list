#include <stdio.h>
#include "dlist.h"

int main()
{
    int mainChoice, result;
    int tempData1, tempData2, tempData3, tempData4, tempData5, tempData6, tempData7, tempData8, tempData9;
    node* head;
    node* tempHead;
    while(1)
    {
        puts("\nEnter an option:");
        puts("1. Create a new list");
        puts("2. Insert data in the beginning");
        puts("3. Insert data in the end");
        puts("4. Insert data after a known data");
        puts("5. Insert data before a known data");
        puts("6. Delete a particular data");
        puts("7. Display the list");
        puts("8. Search a given data");
        puts("9. Exit\n");
        scanf("%d", &mainChoice);
        switch (mainChoice)
        {
        case 9:
            return 0;
        case 1:
            puts("\nEnter data for head:\n");
            scanf("%d",&tempData1);
            head = create(tempData1);
            break;
        case 2:
            if (head == NULL)
            {
                puts("Initialize a list first!");
                break;
            }
            puts("\nEnter data to be inserted in the beginning:\n");
            scanf("%d", &tempData2);
            head = insertBeginning(head,tempData2);
            break;
        case 3:
            if (head == NULL)
            {
                puts("Initialize a list first!");
                break;
            }
            puts("\nEnter data to be inserted at the end:\n");
            scanf("%d", &tempData3);
            insertEnding(head,tempData3);
            break;
        case 4:
            if (head == NULL)
            {
                puts("Initialize a list first!");
                break;
            }
            puts("\nEnter data to be inserted:\n");
            scanf("%d", &tempData4);
            printf("\nEnter data after which %d must be inserted?\n", tempData4);
            scanf("%d", &tempData5);
            result = insertAfter(head, tempData4, tempData5);
            if (result == -1)
                puts("\nEnter a known data element!\n");
            else
                puts("\nData successfully inserted!\n");
            break;
        case 5:
            if (head == NULL)
            {
                puts("Initialize a list first!");
                break;
            }
            puts("\nEnter data to be inserted:\n");
            scanf("%d", &tempData8);
            printf("\nEnter data before which %d must be inserted?\n", tempData8);
            scanf("%d", &tempData9);
            head = insertBefore(head, tempData8, tempData9);                
            break;
        case 6:
            if (head == NULL)
            {
                puts("Initialize a list first!");
                break;
            }
            puts("\nEnter data to be deleted:\n");
            scanf("%d", &tempData6);
            node * nodeToBeSearched = searchNode(head, tempData6);
            if (nodeToBeSearched == NULL)
            {
                puts("\nData not found in list\n");
            }
            else
            {
                head = deleteNode(head, nodeToBeSearched);
            }
            break;
        case 7:
            if(head == NULL)
            {
                puts("\nThere are no elements in the list!\n");
            }
            else {
                node* traverser = head;
                printf("\n");
                while(traverser->next != NULL)
                {
                    if(traverser == head)
                    {
                        printf("X <- [%d] ⇋ ",displayNode(traverser));
                    }
                    else
                    {
                        printf("[%d] ⇋ ",displayNode(traverser));
                    }
                    
                    traverser = traverser->next;
                }
                if(traverser->prev == NULL)
                {
                    printf("X <- [%d] -> X\n",displayNode(traverser));
                }
                else
                {
                    printf("[%d] -> X\n",displayNode(traverser));
                }
                
            }
            break;
        case 8:
            if (head == NULL)
            {
                puts("Initialize a list first!");
                break;
            }
            puts("\nEnter data to be searched for:\n");
            scanf("%d", &tempData7);
            node* result = searchNode(head, tempData7);
            if (result == NULL)
                puts("\nData not found in list!\n");
            else
                puts("\nData found in list!\n");
            break;
        default:
            break;
        }
        

    }
    return 0;
}