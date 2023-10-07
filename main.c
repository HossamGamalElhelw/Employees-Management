/*
 *File       : main.c
 *Author     : Hossam Gamal
 *http       : https://www.linkedin.com/in/hossam-gamal-810b74220
 *Created on : sept 20 , 2023 , 9.30 PM
*/

/*->>>>>>>>>>>>>>>>>>> Includes <<<<<<<<<<<<<<<<<<<<<<<-*/
#include "APP/employee.h"  

void main()
{
  /* Initialize variables and data structures.*/
  
  // Create a singly linked list.
  sll_t *newList = create_sll(); 
  
  // Initialize node pointers.
  node_t *newNode = NULL;         
  node_t *searchNode = NULL;
  
  // Initialize data structures.
  data_t newEmployee;        
  data_t searchEmployee;
  data_t newData;

  // Status variable for error checking.
  En_sll_status_t retStatus;      
  // User's menu choice.
  uint8 option;                   
  // Minimum salary for filtering.
  float32 min_salary;            

  //options by enum
  en_option_t options;

  // Clear the console screen.
  system("cls");  

  // Start the main program loop.
  do
  {
    // Display user menu options.
    printfOptions_user();  
    // Read user's choice.
    scanf("%i", &option);  
    // Clear the console screen.
    system("cls");         
    // Process the user's choice using a switch statement.
    switch (option)
    {
    case ADD_EMPLOYEE:
      system("cls");
      // Enter new employee data.
      newEmployee = enter_new_employee(newEmployee);
      system("cls");
      // Append the new employee to the linked list.
      retStatus = append_node(newList, newEmployee);
      // handle error
      handle_linked_list_status(retStatus);
      Sleep(3000);  // Pause for 3 seconds.
      system("cls");
      break;
    case DISPLAY_LIST:
      system("cls");
      // Display all employees in the linked list.
      retStatus = display_sll(newList);
      handle_linked_list_status(retStatus);
      Sleep(2000);  // Pause for 2 seconds.
      break;
    case DISPLAY_EMPLOYEE_BY_SEARCH:
      system("cls");
      slowPrint("Enter ID of employee : ");
      scanf("%i", &searchEmployee.id);
      // Search for an employee by ID and display their information.
      searchNode = search_node_sll(newList, searchEmployee);
      retStatus = display_node_sll(searchNode);
      // handle error
      handle_linked_list_status(retStatus);
      Sleep(3000);  // Pause for 3 seconds.
      break;
    case MODIFY_EMPLOYEE:
      system("cls");
      slowPrint("Enter ID of employee : ");
      scanf("%i", &searchEmployee.id);
      system("cls");
      // Enter new data for an existing employee.
      newData = enter_new_employee(newData);
      system("cls");
      // Modify the information of an employee.
      retStatus = modify_list_sll(newList, searchEmployee, newData);
      // handle error
      handle_linked_list_status(retStatus);
      // Pause for 2 seconds.
      Sleep(2000);  
      system("cls");
      break;
    case DELETE_EMPLOYEE:
      system("cls");
      slowPrint("Enter ID of employee : ");
      scanf("%i", &searchEmployee.id);
      searchNode = search_node_sll(newList, searchEmployee);
      if (searchNode == NULL)
      {
        slowPrint("<<<<<<<<---- an employee is not found ---->>>>>>>>>\n");
        // Pause for 2 seconds.
        Sleep(2000);  
        system("cls");
        break;
      }
      // Delete an employee by ID.
      retStatus = delete_byValue_sll(newList, searchEmployee);
      // handle error
      handle_linked_list_status(retStatus);
      Sleep(2000);  // Pause for 2 seconds.
      system("cls");
      break;
    case FILTER_EMPLOYEES:
      system("cls");
      slowPrint("Enter the Lowest salary : ");
      scanf("%f", &min_salary);
      system("cls");
      slowPrint("Filter employees by salary:\n");
      // Filter employees by salary and display the results.
      retStatus = filter_employees(newList, min_salary);
      handle_linked_list_status(retStatus);
      Sleep(3000);  // Pause for 3 seconds.
      break;
    case EXPLAIN_PROGRAM:
      system("cls");
      // Display an explanation of the program.
      explainProgram();
      // Pause for 2 seconds.
      Sleep(2000);  
      break;
    default:
      if (EXIT != option)
      { 
        slowPrint("Please Enter correct options.\n");
      }
      break;
    }
  } while (option != EXIT);
  // Exit message.
  slowPrint("the program is Exit.\nThanks!\n"); 
  // Free memory allocated for the linked list.
  retStatus = free_sll(newList);  
}
