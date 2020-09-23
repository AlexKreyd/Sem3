#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* push(struct node* head, int new_value);
int pop(struct node** phead);
void print_stack(struct node* head);

int main(void){
  struct node* head = NULL;
  int choice;
  do{
    printf("\nMenu:\n");
    printf("1 - add new element\n");
    printf("2 - delete the top element\n");
    printf("3 - print stack\n");
    printf("4 - exit\n");
    scanf("%d",&choice);
    if(choice == 1){
      int el;
      printf("\nPrint an element to add: ");
      scanf("%d",&el);
      head = push(head,el);
      printf("A new element has been added\n");
    }
    else if(choice == 2){
      if(head == NULL){
        printf("\nThe stack is empty\n");
        continue;
      }
      int delete_el = pop(&head);
      printf("\nA top element = %d has been deleted\n", delete_el);
    }
    else if(choice == 3){
      if(head == NULL){
        printf("\nThe stack is empty\n");
        continue;
      }
      printf("Printing stack: ");
      print_stack(head);
      printf("\n");
    }
    else if(choice == 4){
      printf("The end of the program\n");
    }
  }while (choice != 4);

  return 0;
}

struct node* push(struct node* head, int new_value){
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  if(new_node == NULL){
    printf("\nNo memory, end of the program\n");
    exit(1);
  }
  new_node->data = new_value;
  new_node->next = head;

  return new_node;
}

int pop(struct node** phead){
  if(*phead == NULL) exit(1);
  int del_value = 0;
  struct node *tmp =(*phead);

  del_value = tmp->data;
  (*phead) = tmp->next;
  free(tmp);
  return del_value;
}

void print_stack(struct node* head){
  if(head == NULL) return;
  else{
     printf("%d ",head->data);
     print_stack(head->next);
   }
   return;
}
