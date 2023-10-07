/*
 *File       : linkList.h
 *Author     : Hossam Gamal
 *http       : https://www.linkedin.com/in/hossam-gamal-810b74220
 *Created on : sept 10 , 2023 , 6:30 PM
*/

#ifndef _linkList_H
#define _linkList_H

/*->>>>>>>>>>>>>>>>>>> Includes <<<<<<<<<<<<<<<<<<<<<<<-*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "Platform_Types.h"

/*->>>>>>>>>>>>>>>>>>> macro Declarations <<<<<<<<<<<<<<<<<<<<<<<-*/
#define ZERO 0

/*->>>>>>>>>>>>>>>>>>> Data type declarations <<<<<<<<<<<<<<<<<<<<<<<-*/
typedef struct data
{
  uint8 name[50];
  uint8 title[50];
  sint32 age;
  float32 salary;
  uint8 id;
  uint8 phoneNumber[50];
  uint8 email[100];
}data_t;

typedef struct node
{
  data_t data;
  struct node *next;
}node_t;

typedef struct single_linked_list
{
  uint16 size;
  node_t *head;
  node_t *tail; // optional to double
}sll_t;


typedef enum
{
  LINKED_LIST_OK,
  LINKED_LIST_NOK,
  LINKED_LIST_NULL_POINTER,
  LINKED_LIST_EMPTY,
  LINKED_LIST_FULL,
  LINKED_LIST_NODE_NOT_CREATE,
  LINKED_LIST_NODE_CREATE,
  LINKED_LIST_NODE_NOT_FOUND,
  LINKED_LIST_APPEND_FLAG,
  ID_IS_USED_BEFORE,
}En_sll_status_t;

/*->>>>>>>>>>>>>>>>>>> Software interfaces declarations APIs <<<<<<<<<<<<<<<<<<<<<<<-*/

/**
 * @brief Create list
 * @param not enter value
 * @retval pointer to single linked list "sll_t"
  */
sll_t * create_sll();

/**
 * @brief create node
 * @param unsigned integer value store in node
 * @retval pointer to node_t
  */

node_t *create_node(data_t value);

/**
 * @brief free list
 * @param pointer of list
 * @retval return En_sll_status_t
  */
En_sll_status_t free_sll(sll_t *list);

/**
 * @brief add new node in the end of list
 * @param pointer of list and value 
 * @retval return En_sll_status_t
  */

En_sll_status_t append_node(sll_t *list, data_t value);

/**
 * @brief display list
 * @param pointer of list 
 * @retval return En_sll_status_t
  */

En_sll_status_t display_sll(sll_t *list);

/**
 * @brief display list
 * @param pointer of list 
 * @retval return En_data_status_t
  */

En_sll_status_t display_node_sll(node_t *node);

/**
 * @brief search node
 * @param pointer of list and value
 * @retval return postion of node value
  */

node_t *search_node_sll(sll_t *list , data_t value);

/**
 * @brief modify old value by new value
 * @param pointer of list and old value and new value
 * @retval return En_sll_status_t
  */
En_sll_status_t modify_list_sll(sll_t *list, data_t oldVal, data_t newVal);

/**
 * @brief delete node by value
 * @param pointer of list and value
 * @retval return En_sll_status_t
  */
En_sll_status_t delete_byValue_sll(sll_t *list, data_t value);

/**
 * @brief delete node by postion
 * @param pointer of list and postion
 * @retval return En_sll_status_t
  */
En_sll_status_t delete_byPostion_sll(sll_t *list, uint32 pos);

/**
 * @brief delete node by postion
 * @param pointer of list and postion
 * @retval return En_sll_status_t
  */
En_sll_status_t delete_byPostion_sll(sll_t *list, uint32 pos);

/**
 * @brief insert node by postion
 * @param pointer of list ,value and postion
 * @retval return En_sll_status_t
  */
En_sll_status_t insert_node_byPostion_sll(sll_t *list, data_t value , uint32 pos);

/**
 * @brief reverse list
 * @param pointer of list
 * @retval return En_sll_status_t
  */
En_sll_status_t reverse_sll(sll_t *list);

#endif