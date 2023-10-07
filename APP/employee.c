/*
 *File       : employee.c
 *Author     : Hossam Gamal
 *http       : https://www.linkedin.com/in/hossam-gamal-810b74220
 *Created on : sept 20 , 2023 , 9.30 PM
*/

#include "employee.h"

/*->>>>>>>>>>>>>> helper functions declaration <<<<<<<<<<<<<<<<-*/

/**
 * @brief check phone number length is 12 number or not
 * @param data_t newEmployee.
 * @retval value of data_t.
  */

static data_t check_phone_number(data_t newEmployee);
/**
 * @brief check email is end @gmail.com or not.
 * @param data_t newEmployee.
 * @retval value of data_t.
  */

static data_t check_email(data_t newEmployee);
/**
 * @brief print string slowly.
 * @param constant pointer of char. 
 * @retval not return.
  */

/*->>>>>>>>>>>>>> End helper function declaration <<<<<<<<<<<<<<<<-*/

/*->>>>>>>>>>>>>> APIs definations <<<<<<<<<<<<<<<<-*/

void slowPrint(const char *text)
{
  for (int i = 0; text[i] != '\0'; i++)
  {
    putchar(text[i]);
    fflush(stdout);
    // Delay for 20 milliseconds.
    Sleep(20); 
  }
}

/**
 * @brief print string quickly.
 * @param constant pointer of char. 
 * @retval not return.
  */

void fastPrint(const char *text)
{
  for (int i = 0; text[i] != '\0'; i++)
  {
    putchar(text[i]);
    fflush(stdout);
    // Delay for 10 milliseconds
    Sleep(10);
  }
}

/**
 * @brief print the options to user.
 * @param not inputs.
 * @retval not return.
  */

void printfOptions_user()
{
  fastPrint("options \n");
  fastPrint("1. Add a New Employee to the List \n");
  fastPrint("2. View the List of all Employees \n");
  fastPrint("3. Search Data of Employee        \n");
  fastPrint("4. Edit Data of Employee          \n");
  fastPrint("5. Delete Data Employee from List \n");
  fastPrint("6. Filer Employees                \n");
  fastPrint("7. About Program                  \n");
  fastPrint("8. Exit                           \n");
  fflush(stdin);
  fastPrint("Select an option :   ");
}

/**
 * @brief enter data of new employee to new node
 * @param new employee type of data_t
 * @retval data of employee type of data_t
  */

data_t enter_new_employee(data_t newEmployee)
{
  fflush(stdin);
  slowPrint("Enter employee name   : ");
  gets(newEmployee.name);
  fflush(stdin);
  slowPrint("Enter employee title  : ");
  gets(newEmployee.title);
  fflush(stdin);
  slowPrint("Enter employee id     : ");
  scanf("%i",&newEmployee.id);
  fflush(stdin);
  slowPrint("Enter employee age    : ");
  scanf("%i", &newEmployee.age);
  fflush(stdin);
  /* ->>>>>>>>>>>>> Check phone number length<<<<<<<<<<<<- */
  newEmployee = check_phone_number(newEmployee);
  /* ->>>>>>>>>>>>>>>>>> Check Email<<<<<<<<<<<<<<<<<<- */
  newEmployee = check_email(newEmployee);
  /*continue data after check email. */
  slowPrint("Enter employee salary : ");
  scanf("%f", &newEmployee.salary);
  return newEmployee;
}
/*->>>>>>>>>>>>>> Start helper function definations <<<<<<<<<<<<<<<<-*/
/**
 * @brief check phone number length is 12 number or not
 * @param data_t newEmployee.
 * @retval value of data_t.
  */

static data_t check_phone_number(data_t newEmployee)
{
  do
  {
    slowPrint("Enter employee Phone  : ");
    fflush(stdin);
    gets(newEmployee.phoneNumber);
    fflush(stdin);
    if (strlen(newEmployee.phoneNumber) < 11 || strlen(newEmployee.phoneNumber) > 12)
    {
      slowPrint("Invalid phone number.\nPlease enter a 12 Numbers\n");
    }
    else
    {
      return newEmployee;
      break;
    }
  } while (1);
}

/**
 * @brief check email is end @gmail.com or not.
 * @param data_t newEmployee.
 * @retval value of data_t.
  */

static data_t check_email(data_t newEmployee) 
{
  char checkMail[11] = "@gmail.com";
  do 
  {
    fflush(stdin);
    slowPrint("Enter employee Email  : ");
    gets(newEmployee.email);
    uint8 *compared_str = newEmployee.email + (strlen(newEmployee.email) - 10);
    
    if (strcmp(checkMail, compared_str) != 0) {
      printf("Email should end with @gmail.com.\n");
    } else {
      break;
    }
  } while (1);

  return newEmployee;
}
/*->>>>>>>>>>>>>> end helper function definations <<<<<<<<<<<<<<<<-*/

/*->>>>>>>>>>>>>> continue APIs definations <<<<<<<<<<<<<<<<-*/

/**
 * @brief filter employees by there salaries by enter minimum salary of them
 * @param list of employees & minimum salary
 * @retval status of data
  */

En_sll_status_t filter_employees(sll_t *list, float32 min_salary)
{
  En_sll_status_t retStatus = LINKED_LIST_OK;

  /*check if list is empty .*/
  if (NULL == list)
  {
    return LINKED_LIST_NULL_POINTER;
  }
  /* create node current to loop in list. */
  node_t *current = list->head;
  uint8 foundFlag = 0; 
  /*create counter to count the employees. */
  uint8 counter   = 1;

  /*loop in list. */
  while (NULL != current)
  {
    /*if data of node is true. */
    if (current->data.salary >= min_salary)
    {
      /*print counter of employee. */
      printf("Employee Number [%i] : \n",counter);
      printf("========================\n");
      /*display current node if it true. */
      retStatus = display_node_sll(current);
      foundFlag = 1; 
      counter++;
      printf("========================\n");
    }
    current = current->next;
  }
  if (!foundFlag)
  {
    slowPrint("No employee's salary is equal or greater than this salary.\n");
  }
  return retStatus;
}

/**
 * @brief print about program to help user to understand it.
 * @param not inputs.
 * @retval not return.
  */

void explainProgram() {
  slowPrint("->>>>>>>>>>>>> Welcome <<<<<<<<<<<<<<-\n");
  slowPrint("Employee Management System\n");
  slowPrint("This program allows you to manage a list of employees.\n");
  slowPrint("You can perform the following options:\n");
  slowPrint("1. Add a new employee to the list.\n");
  slowPrint("2. View the list of all employees.\n");
  slowPrint("3. Search Employee Data: Find and display information about a specific employee.\n");
  slowPrint("4. Edit Employee Data: Modify the data of employee.\n");
  slowPrint("5. Delete Employee Data: Remove an employee from the list.\n");
  slowPrint("6. Filter Employees by Salary: View employees with a salary above a specified minimum.\n");
  slowPrint("7. Exit: Quit the program.\n");
  slowPrint("->>>>>>>>>>>>> Thanks! <<<<<<<<<<<<<<-\n");
}

/**
 * @brief print status of data
 * @param status type of En_sll_status_t
 * @retval not return.
  */

void handle_linked_list_status(En_sll_status_t status) {
  switch (status) {
    case LINKED_LIST_OK:
      printf("<<<<<<<<<<----- operation successful ----->>>>>>>>>> \n");
      break;
    case LINKED_LIST_NOK:
      printf("<<<<<<<<<<<<-----  operation failed ----->>>>>>>>>>>>\n");
      break;
    case LINKED_LIST_NULL_POINTER:
      printf("<<<<<<<<<<----- employee is not found ----->>>>>>>>>>\n");
      break;
    case LINKED_LIST_EMPTY:
      printf("<<<<<<<<----- list of employees is empty----->>>>>>>>\n");
      break;
    case LINKED_LIST_FULL:
      printf("<<<<<<<<<<<<<<----- list is Full ------>>>>>>>>>>>>>>\n");
      break;
    case LINKED_LIST_NODE_NOT_CREATE:
      printf("<<<<<<<<<<<----- Node creation failed----->>>>>>>>>>>\n");
      break;
    case LINKED_LIST_NODE_CREATE:
      printf("<<<<<<<<<<<<----- Add is successful ----->>>>>>>>>>>>\n");
      break;
    case LINKED_LIST_NODE_NOT_FOUND:
      printf("<<<<<<<--- an employee is not found in list --->>>>>>>\n");
      break;
    case LINKED_LIST_APPEND_FLAG:
      printf("<<<<<<<<----- Append operation flag set ----->>>>>>>>\n");
      break;
    case ID_IS_USED_BEFORE:
      printf("<<<<<<<<<<<----- ID is used before  ----->>>>>>>>>>>>\n");
      break;
    default:
      printf("Unknown status code.\n");
      break;
  }
}