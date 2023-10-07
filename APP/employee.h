/*
 *File       : employee.h
 *Author     : Hossam Gamal
 *http       : https://www.linkedin.com/in/hossam-gamal-810b74220
 *Created on : sept 20 , 2023 , 9:30 PM
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

/*-->>>>>>>>>>>>>>>>> Includes <<<<<<<<<<<<<<<<<<-*/
#include "../SLL_T/linkList.h"

/*-->>>>>>>>>>>>>>>>> Data type declarations <<<<<<<<<<<<<<<<<<-*/
typedef enum
{
  ADD_EMPLOYEE = 1,
  DISPLAY_LIST,
  DISPLAY_EMPLOYEE_BY_SEARCH,
  MODIFY_EMPLOYEE,
  DELETE_EMPLOYEE,
  FILTER_EMPLOYEES,
  EXPLAIN_PROGRAM,
  EXIT,

}en_option_t;

/*->>>>>>>>>>>>>>>>> Software interfaces declarations APIs -<<<<<<<<<<<<<<<<<<-*/

/**
 * @brief print string slowly.
 * @param constant pointer of char 
 * @retval not return
  */

void slowPrint(const char *text);

/**
 * @brief print string quickly
 * @param constant pointer of char 
 * @retval not return
  */

void fastPrint(const char *text);

/**
 * @brief print the options to user
 * @param not inputs 
 * @retval not return
  */

void printfOptions_user();

/**
 * @brief enter data of new employee to new node
 * @param new employee type of data_t
 * @retval data of employee type of data_t
  */

data_t enter_new_employee(data_t newEmployee);

/**
 * @brief filter employees by there salaries by enter minimum salary of them
 * @param list of employees & minimum salary
 * @retval status of data
  */

En_sll_status_t filter_employees(sll_t *list,float32 min_salary);

/**
 * @brief print about program to help user to understand it.
 * @param not inputs.
 * @retval not return.
  */

void explainProgram();

/**
 * @brief print status of data
 * @param status type of En_sll_status_t
 * @retval not return.
  */

void handle_linked_list_status(En_sll_status_t status);

#endif //_EMPLOYEE_H