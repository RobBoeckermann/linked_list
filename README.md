# Stax Coding Challenge

## Prompt
Create a C++ program that implements a linked list. The linked list should be a doubly linked list, allowing movement forward and backward. This program should allow you to add and remove nodes from the list. Each node should contain a reference to application data. The program does not have to provide user interaction. Please include units tests for the program. The program can be submitted by including a link to your solution in Github.

## Running in Dev Container
1. Start VS Code, run the Dev Containers: Open Folder in Container... command from the Command Palette (F1) or quick actions Status bar item, and select the project folder you would like to set up the container for.
More info at: https://code.visualstudio.com/docs/devcontainers/containers

## Design Decisions
* The `Node` class utilizes a template to allow the class to be utilized to store pointers to any type of application data.
* The `DoublyLinkedList` class is implemented with a head AND tail to allow for faster access to nodes within the list. The overhead of determining whether to search from the head or the tail requires a bit more processing than just searching front-to-back always, but, considering a doubly linked list was requested, I expect the linked lists to be long enough to benefit from the overheard of determining which end to start searching from. The overhead is likely negligible, even for small lists, but this would need to be verified through performance tests comparing the two approaches (especially if this code will be used in a hot path of the software).
* The length of the linked list is stored in an `unsigned short` int because it only uses 2 bytes and can reach a max value of 65,535. It's unlikely a linked list would exceed this many nodes because that would be inefficient for accessing, adding, or removing nodes far from the head or tail. The data type could be changed to utilize a larger data type that would ensure the linked list continues functioning properly during the edge case of length > 65,535. The extra 2 bytes are likely insignificant in non-embedded applications, so an `unsigned int` would be more appropriate in most cases, but I made this decision to demonstrate the need to consider the size of data types in situations where memory could be limited.
* The indexes of the `DoublyLinkedList` begin at 0 (head = index 0). 

## Future Considerations
* Add `DoublyLinkedList` member functions for searching for a specific data value within the list by iterating and returning an index (which could be used for removing nodes by their data contents).
* Have "pop" functions return the data of the node being removed so that it can be optionally captured. This mirrors the implementations of similar data structures.
* Add a member function for altering the date within a node. Since nodes contain a pointer to application data, changing the value in this way is equivalent to changing the source data, which could be advantageous depending on the use-case and dangerous if used incorrectly/inadvertently.
* Replace the use of `New` and `delete` with a smart pointer implementation such as `std::unique_ptr` to reduce the risk of memory leaks from forgetting to deallocate memory.
* Run the tests using tools such as Address Sanitizer or Valgrind to check for any existing memory leaks.
* Document functions extensively using Doxygen comments.
* Add proper error handling for invalid attempted operations (eg. pushing to an invalid index). These operations are currently ignored without alerting that there was something wrong with the request. In the case of `get_data_at_index()`, the "error" return is `nullptr`, which is a problem because `nullptr` could be a valid value for a node's data pointer.
