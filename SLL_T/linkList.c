/*
 *File       : linkList.c
 *Author     : Hossam Gamal
 *http       : https://www.linkedin.com/in/hossam-gamal-810b74220
 *Created on : sept 10 , 2023 , 6:30 PM
*/

#include "linkList.h"

/*->>>>>>>>>>>>>>>>>>> APIs definations <<<<<<<<<<<<<<<<<-*/
/**
 * @brief Create list
 * @param not enter value
 * @retval pointer to single linked list "sll_t"
  */

sll_t *create_sll()
{
  sll_t *newList = (sll_t *)malloc(1*sizeof(sll_t));
  /* check if list is created or not . */
  if(NULL == newList)
  {
    return NULL;
  }
  newList->head = NULL;
  newList->size = 0;

  return newList;
}

/**
 * @brief create node
 * @param  integer value store in node
 * @retval pointer to node_t
  */

node_t * create_node(data_t value)
{
  node_t * newNode = malloc(1*sizeof(node_t));
  /*check node is created or not .*/
  if(newNode ==NULL)
  {
      return NULL; 
  }
  newNode->data = value; 
  newNode->next = NULL;

  return newNode; 
}

/**
 * @brief free list
 * @param pointer of list
 * @retval not return
  */

En_sll_status_t free_sll(sll_t *list)
{
  /* Check if the list is not created. */
  if (NULL == list)
  {
    return LINKED_LIST_NULL_POINTER;
  }
  /* Check if the list is empty or not. */
  if (NULL == list->head)
  {
    free(list);
    return LINKED_LIST_EMPTY;
  }
  /* Create node to loop in the list. */
  node_t *current = list->head;
  while (current != NULL)
  {
    // Store the current node.
    node_t *temp = current; 
    // Move to the next node.
    current = current->next; 
    // Free the stored node.
    free(temp); 
  }
  free(list); // Finally, free the list itself.
  return LINKED_LIST_OK;
}


/**
 * @brief add new node in the end of list
 * @param pointer of list and value 
 * @retval return En_sll_status_t
  */


En_sll_status_t append_node(sll_t *list, data_t value)
{
  /*check list is not created .*/
  if(NULL == list)
  {
    return LINKED_LIST_NULL_POINTER;
  }
  //check id is repeated or not.//
  if(search_node_sll(list,value))
  {
    printf("Data is not Append.\nID is used before.\nPlease try again.\n");
    return ID_IS_USED_BEFORE;
  }
  /*create newNode*/
  node_t *newNode = create_node(value);
  if(NULL == newNode)
  {
    return LINKED_LIST_NODE_NOT_CREATE;
  }
  //create current 
  node_t * current = list->head;
  /* list is empty. */
  if(NULL == list->head)
  {
    list->head = newNode;
  }
  else
  {
    while (NULL != current->next)
    {
      current = current->next;
    }
    // now current points at the last node in the list
    current->next = newNode;
  }
  (list->size)++;
  return LINKED_LIST_NODE_CREATE;
}


/**
 * @brief display list
 * @param pointer of list 
 * @retval return En_sll_status_t
  */


En_sll_status_t display_sll(sll_t *list)
{
  uint8 counter = 1;
  /*check list is not created .*/
  if(NULL == list)
  {
    return LINKED_LIST_NULL_POINTER;
  }
  if(NULL == list->head)
  /*check list is empty .*/
  {
    return LINKED_LIST_EMPTY;
  }
  /*create node current to loop in list*/
  node_t *current = list->head;
  while (NULL != current)
  {
    printf("Employee Number [%i] : \n",counter);
    printf("======================\n");
    printf("employee name  : %s \n",current->data.name);
    printf("employee title : %s \n",current->data.title);
    printf("employee id    : %i \n",current->data.id);
    printf("employee age   : %i \n",current->data.age);
    printf("employee Phone : %s \n",current->data.phoneNumber);
    printf("employee Email : %s \n",current->data.email);
    printf("employee salary: %0.2f $\n",current->data.salary);
    current = current->next;
    counter++;
    printf("======================\n");
    printf("\n");
  }
  printf("\n");
  return LINKED_LIST_OK;
}

/**
 * @brief display list
 * @param pointer of list 
 * @retval return En_data_status_t
  */
En_sll_status_t display_node_sll(node_t *node)
{
  /*check list is not created .*/
  if(NULL == node)
  {
    return LINKED_LIST_NULL_POINTER;
  }
  else
  {
    printf("employee name   : %s \n", node->data.name);
    printf("employee title  : %s \n", node->data.title);
    printf("employee id     : %i \n", node->data.id);
    printf("employee age    : %i \n", node->data.age);
    printf("employee Phone  : %s \n", node->data.phoneNumber);
    printf("employee Email  : %s \n", node->data.email);
    printf("employee salary : %0.2f \n", node->data.salary);
  }
  return LINKED_LIST_OK;
}

/**
 * @brief search node
 * @param pointer of list and value
 * @retval return postion of node value
  */


node_t *search_node_sll(sll_t *list , data_t value)
{
  En_sll_status_t retPtr = LINKED_LIST_NOK;
  /*check list is not created .*/
  if(NULL == list)
  {
    retPtr = LINKED_LIST_NULL_POINTER;
    return NULL;
  }
  /*check list is empty .*/
  if(NULL == list->head)
  {
    retPtr = LINKED_LIST_EMPTY;
    return NULL;
  }
  /*create node current to loop in list.*/
  node_t *current = list->head;

  while (NULL != current)
  {
    /*if id of user equal id of employee*/
    if(value.id == current->data.id)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}


/**
 * @brief modify old value by new value
 * @param pointer of list and old value and new value
 * @retval return En_sll_status_t
  */


En_sll_status_t modify_list_sll(sll_t *list, data_t oldVal, data_t newVal)
{
  /*check list is not created .*/
  if(NULL == list)
  {
    return LINKED_LIST_NULL_POINTER;
  }
  /*check list is empty .*/
  if(NULL == list->head)
  {
    return LINKED_LIST_EMPTY;
  }
  /*check id is found or not.*/
  if(search_node_sll(list,newVal))
  {
    printf("Data not Edit.\nNew ID is used before.\nPlease try again.\n");
    return ID_IS_USED_BEFORE;
  }
  /*create node current to check value*/
  node_t *current = search_node_sll(list,oldVal);
  if(NULL == current)
  {
    return LINKED_LIST_NODE_NOT_FOUND;
  }
  /*current node become new value*/
  current->data = newVal;

  return LINKED_LIST_OK;
}


/**
 * @brief delete node by value
 * @param pointer of list and value
 * @retval return En_sll_status_t
  */


En_sll_status_t delete_byValue_sll(sll_t *list, data_t value)
{
  /*check list is not created .*/
  if(NULL == list)
  {
    return LINKED_LIST_NULL_POINTER;
  }
  node_t *current = list->head,*prev;
  /*value is not found .*/
  if(NULL == current)
  {
    return LINKED_LIST_NODE_NOT_FOUND;
  }
  /*if id is found in the head .*/
  if(value.id == list->head->data.id)
  {
    /*new head will be next node.*/
    list->head = list->head->next;
    /*delete current node.*/
    free(current);
    /*decrease the of list. */
    (list->size)--;
    return LINKED_LIST_OK;
  }
  /*if id is found .*/
  while (NULL != current)
  {
    if(value.id == current->data.id)
    {
      break;
    }
    prev = current;
    current = current->next;
  }
  /*previous node become current*/
  prev->next = current->next;
  /*delete current node. */
  free(current);
  /*decrease size of list. */
  (list->size)--; 
  
  return LINKED_LIST_OK;
}


/**
 * @brief delete node by postion
 * @param pointer of list and postion
 * @retval return En_sll_status_t
  */


En_sll_status_t delete_byPostion_sll(sll_t *list, uint32 pos)
{
  /*check list is not created .*/
  if(NULL == list)
  {
    return LINKED_LIST_NULL_POINTER;
  }
  /*check list is empty .*/
  if(NULL == list->head)
  {
    return LINKED_LIST_EMPTY;
  }
  /*create current node and previous node. */
  node_t *current = list->head, *prev;
  if(NULL == current)
  {
    return LINKED_LIST_NODE_NOT_FOUND;
  }
  /*postion is not found. */
  if(pos >= list->size)
  {
    printf("invalid postion\n");
    return LINKED_LIST_NOK;
  }
  /*postion is head of list. */
  if(ZERO == pos)
  {
    /*head will be next node .*/
    list->head = list->head->next;
    /*delete current node. */
    free(current);
    /*decrease size of list. */
    (list->size)--;
    return LINKED_LIST_OK;
  }
  for(int i = 0 ; i < pos && current != NULL ; i++)
  {
    prev = current;
    current = current->next;
  }
  if(NULL == current)
  {
    return LINKED_LIST_NOK;
  }
  /*current node equal current next. */  
  prev->next = current->next;
  /*delete current node. */
  free(current);
  /*decrease size of list. */
  (list->size)--;
  return LINKED_LIST_OK;
}


/**
 * @brief insert node by postion
 * @param pointer of list ,value and postion
 * @retval return En_sll_status_t
  */


En_sll_status_t insert_node_byPostion_sll(sll_t *list, data_t value , uint32 pos)
{
  /*check list is not created .*/
  if(NULL == list)
  {
    return LINKED_LIST_NULL_POINTER;
  }
  /*if postion is greater than or equal size of list.*/
  if(pos >= list->size)
  {
    append_node(list,value);
    return LINKED_LIST_APPEND_FLAG;
  }
  /*create pointer newNode equal address of newNode.*/
  node_t *newNode = create_node(value);
  /*if postion is the first node in list. */
  if(ZERO == pos)
  {
    newNode->next = list->head;
    /*head of list is become in newNode. */
    list->head = newNode;
    /*increase size of list by one .*/
    (list->size)++;
    return LINKED_LIST_OK;
  }
  /*create pointer previous node*/
  node_t *prev = list->head;
  for(int i = 0 ; i < pos - 1 ; i++)
  {
    prev = prev->next;
  }
  newNode->next = prev->next;
  prev->next    = newNode;
  /*increase size of list by one .*/
  (list->size)++;
  return LINKED_LIST_OK;
}


/**
 * @brief reverse list
 * @param pointer of list
 * @retval return En_sll_status_t
  */


En_sll_status_t reverse_sll(sll_t *list)
{
  /*check list is not created .*/
  if(NULL == list)
  {
    return LINKED_LIST_NOK;
  }
  /*check list empty .*/
  if(NULL == list->head)
  {
    printf("sll is empty \n");
    return LINKED_LIST_EMPTY;
  }
  /*create current node , previous node and next node*/
  node_t *current = list->head, *prev = NULL , *next = NULL;
  while (NULL != current)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  /*head will be in previous node. */
  list->head = prev;

  return LINKED_LIST_OK;
}
