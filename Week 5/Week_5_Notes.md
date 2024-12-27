# Week 5: Data Structures

# [**Lecture 5**](https://cs50.harvard.edu/x/2024/notes/5/#lecture-5)

- [Welcome!](https://cs50.harvard.edu/x/2024/notes/5/#welcome)
- [Data Structures](https://cs50.harvard.edu/x/2024/notes/5/#data-structures)
- [Stacks and Queues](https://cs50.harvard.edu/x/2024/notes/5/#stacks-and-queues)
- [Jack Learns the Facts](https://cs50.harvard.edu/x/2024/notes/5/#jack-learns-the-facts)
- [Resizing Arrays](https://cs50.harvard.edu/x/2024/notes/5/#resizing-arrays)
- [Linked Lists](https://cs50.harvard.edu/x/2024/notes/5/#linked-lists)
- [Trees](https://cs50.harvard.edu/x/2024/notes/5/#trees)
- [Dictionaries](https://cs50.harvard.edu/x/2024/notes/5/#dictionaries)
- [Hashing and Hash Tables](https://cs50.harvard.edu/x/2024/notes/5/#hashing-and-hash-tables)
- [Tries](https://cs50.harvard.edu/x/2024/notes/5/#tries)
- [Summing Up](https://cs50.harvard.edu/x/2024/notes/5/#summing-up)

## [**Welcome!**](https://cs50.harvard.edu/x/2024/notes/5/#welcome)

- All the prior weeks have presented you with the fundamental building blocks of programming.
- All you have learned in C will enable you to implement these building blocks in higher-level programming languages such as Python.
- Today, we are going to talk about organizing data in memory and design possibilities that emerge from your growing knowledge.

## [**Data Structures**](https://cs50.harvard.edu/x/2024/notes/5/#data-structures)

- *Data structures* essentially are forms of organization in memory.
- There are many ways to organize data in memory.
- *Abstract data structures* are those that we can conceptually imagine. When learning about computer science, it’s often useful to begin with these conceptual data structures. Learning these will make it easier later to understand how to implement more concrete data structures.

## [**Stacks and Queues**](https://cs50.harvard.edu/x/2024/notes/5/#stacks-and-queues)

- *Queues* are one form of abstract data structure.
- Queues have specific properties. Namely, they are *FIFO* or “first in first out.” You can imagine yourself in a line for a ride at an amusement park. The first person in the line gets to go on the ride first. The last person gets to go on the ride last.
- Queues have specific actions associated with them. For example, an item can be *enqueued*; that is, the item can join the line or queue. Further, an item can be *dequeued* or leave the queue once it reaches the front of the line.
- Queues contrast a *stack*. Fundamentally, the properties of a stack are different than a queue. Specifically, it is *LIFO* or “last in first out.” Just like stacking trays in a cafeteria, a tray that is placed in a stack last is the first that may be picked up.
- Stacks have specific actions associated with them. For example, *push* places something on top of a stack. *Pop* is removing something from the top of the stack.
- 
    
    In code, you might imagine a stack as follows:
    
    ```c
    typedef struct
    {
        person people[CAPACITY];
        int size;
    }
    stack;
    ```
    
    Notice that an array called people is of type `person`. The `CAPACITY` is how high the stack could be. The integer `size` is how full the stack actually is, regardless of how much it *could* hold.
    
- You might imagine that the above code has a limitation. Since the capacity of the array is always predetermined in this code. Therefore, the stack may always be oversized. You might imagine only using one place in the stack out of 5000.
- It would be nice for our stack to be dynamic – able to grow as items are added to it.

## [**Jack Learns the Facts**](https://cs50.harvard.edu/x/2024/notes/5/#jack-learns-the-facts)

- We watched a video called [Jack Learns the Facts](https://www.youtube.com/watch?v=ItAG3s6KIEI) by Professor Shannon Duvall of Elon University.

## [**Resizing Arrays**](https://cs50.harvard.edu/x/2024/notes/5/#resizing-arrays)

- Rewinding to Week 2, we introduced you to your first data structure.
- An array is a block of contiguous memory.
- 
    
    You might imagine an array as follows:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide019.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide019.png)
    
- 
    
    In memory, there are other values being stored by other programs, functions, and variables. Many of these may be unused garbage values that were utilized at one point but are available now for use.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide022.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide022.png)
    
- 
    
    Imagine you wanted to store a fourth value `4` in our array? What would be needed is to allocate a new area of memory and move the old array to a new one. Initially, this new area of memory would be populated with garbage values.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide025.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide025.png)
    
- 
    
    As values are added to this new area of memory, old garbage values would be overwritten.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide026.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide026.png)
    
- 
    
    Eventually, all old garbage values would be overwritten with our new data.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide027.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide027.png)
    
- One of the drawbacks of this approach is that it’s bad design: Every time we add a number, we have to copy the array item by item.
- Wouldn’t it be nice if we were able to put the `4` somewhere else in memory? By definition, this would no longer be an array because `4` would no longer be in contiguous memory.
- 
    
    In your terminal, type `code list.c` and write code as follows:
    
    ```c
    *// Implements a list of numbers with an array of fixed size**#include*** *<stdio.h>*int **main**(void)
    {
        *// List of size 3*int list[3];
    
        *// Initialize list with numbers*list[0] **=** 1;
        list[1] **=** 2;
        list[2] **=** 3;
    
        *// Print list*for (int i **=** 0; i **<** 3; i**++**)
        {
            printf("%i\n", list[i]);
        }
    }
    ```
    
    Notice that the above is very much like what we learned earlier in this course. We have memory being preallocated for three items.
    
- 
    
    Building upon our knowledge obtained more recently, we can leverage our understanding of pointers to create a better design in this code. Modify your code as follows:
    
    ```c
    *// Implements a list of numbers with an array of dynamic size**#include*** *<stdio.h>
    **#include*** *<stdlib.h>*int **main**(void)
    {
        *// List of size 3*int *****list **=** malloc(3 ***** sizeof(int));
        if (list **==** NULL)
        {
            return 1;
        }
    
        *// Initialize list of size 3 with numbers*list[0] **=** 1;
        list[1] **=** 2;
        list[2] **=** 3;
    
        *// List of size 4*int *****tmp **=** malloc(4 ***** sizeof(int));
        if (tmp **==** NULL)
        {
            free(list);
            return 1;
        }
    
        *// Copy list of size 3 into list of size 4*for (int i **=** 0; i **<** 3; i**++**)
        {
            tmp[i] **=** list[i];
        }
    
        *// Add number to list of size 4*tmp[3] **=** 4;
    
        *// Free list of size 3*free(list);
    
        *// Remember list of size 4*list **=** tmp;
    
        *// Print list*for (int i **=** 0; i **<** 4; i**++**)
        {
            printf("%i\n", list[i]);
        }
    
        *// Free list*free(list);
        return 0;
    }
    ```
    
    Notice that a list of size three integers is created. Then, three memory addresses can be assigned the values `1`, `2`, and `3`. Then, a list of size four is created. Next, the list is copied from the first to the second. The value for the `4` is added to the `tmp` list. Since the block of memory that `list` points to is no longer used, it is freed using the command `free(list)`. Finally, the compiler is told to point `list` pointer now to the block of memory that `tmp` points to. The contents of `list` are printed and then freed.
    
- It’s useful to think about `list` and `tmp` as both signs that point at a chunk of memory. As in the example above, `list` at one point *pointed* to an array of size 3. By the end, `list` was told to point to a chunk of memory of size 4. Technically, by the end of the above code, `tmp` and `list` both pointed to the same block of memory.
- One may be tempted to allocate way more memory than required for the list, such as 30 items instead of the required 3 or 4. However, this is bad design as it taxes system resources when they are not potentially needed. Further, there is little guarantee that memory for more than 30 items will be needed eventually.

## [**Linked Lists**](https://cs50.harvard.edu/x/2024/notes/5/#linked-lists)

- In recent weeks, you have learned about three useful primitives. A `struct` is a data type that you can define yourself. A `.` in *dot notation* allows you to access variables inside that structure. The `` operator is used to declare a pointer or dereference a variable.
- Today, you are introduced to the `>` operator. It is an arrow. This operator goes to an address and looks inside of a structure.
- A *linked list* is one of the most powerful data structures within C. A linked list allows you to include values that are located at varying areas of memory. Further, they allow you to dynamically grow and shrink the list as you desire.
- 
    
    You might imagine three values stored at three different areas of memory as follows:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide036.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide036.png)
    
- How could one stitch together these values in a list?
- 
    
    We could imagine this data pictured above as follows:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide037.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide037.png)
    
- 
    
    We could utilize more memory to keep track of where the next item is.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide041.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide041.png)
    
    Notice that NULL is utilized to indicate that nothing else is *next* in the list.
    
- 
    
    By convention, we would keep one more element in memory, a pointer, that keeps track of the first item in the list.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide042.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide042.png)
    
- 
    
    Abstracting away the memory addresses, the list would appear as follows:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide043.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide043.png)
    
- 
    
    These boxes are called *nodes*. A *node* contains both an *item* and a pointer called *next*. In code, you can imagine a node as follows:
    
    ```c
    typedef struct node
    {
        int number;
        struct node *****next;
    }
    node;
    ```
    
    Notice that the item contained within this node is an integer called `number`. Second, a pointer to a node called `next` is included, which will point to another node somewhere in memory.
    
- 
    
    Conceptually, we can imagine the process of creating a linked list. First, `node *list` is declared, but it is of a garbage value.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide055.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide055.png)
    
- 
    
    Next, a node called `n` is allocated in memory.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide059.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide059.png)
    
- 
    
    Next, the `number` of node is assigned the value `1`.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide064.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide064.png)
    
- 
    
    Next, the node’s `next` field is assigned `NULL`.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide066.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide066.png)
    
- 
    
    Next, `list` is pointed at the memory location to where `n` points. `n` and `list` now point to the same place.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide068.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide068.png)
    
- 
    
    A new node is then created. Both the `number` and `next` field are both filled with garbage values.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide073.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide073.png)
    
- 
    
    The `number` value of `n`’s node (the new node) is updated to `2`.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide075.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide075.png)
    
- 
    
    Also, the `next` field is updated as well.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide077.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide077.png)
    
- 
    
    Most important, we do not want to lose our connection to any of these nodes lest they be lost forever. Accordingly, `n`’s `next` field is pointed to the same memory location as `list`.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide084.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide084.png)
    
- 
    
    Finally, `list` is updated to point at `n`. We now have a linked list of two items.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide086.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide086.png)
    
- 
    
    To implement this in code, modify your code as follows:
    
    ```c
    *// Prepends numbers to a linked list, using while loop to print**#include*** *<cs50.h>
    **#include*** *<stdio.h>
    **#include*** *<stdlib.h>*typedef struct node
    {
        int number;
        struct node *****next;
    }
    node;
    
    int **main**(int argc, char *****argv[])
    {
        *// Memory for numbers*node *****list **=** NULL;
    
        *// For each command-line argument*for (int i **=** 1; i **<** argc; i**++**)
        {
            *// Convert argument to int*int number **=** atoi(argv[i]);
    
            *// Allocate node for number*node *****n **=** malloc(sizeof(node));
            if (n **==** NULL)
            {
                return 1;
            }
            n**->**number **=** number;
            n**->**next **=** NULL;
    
            *// Prepend node to list*n**->**next **=** list;
            list **=** n;
        }
    
        *// Print numbers*node *****ptr **=** list;
        while (ptr **!=** NULL)
        {
            printf("%i\n", ptr**->**number);
            ptr **=** ptr**->**next;
        }
    
        *// Free memory*ptr **=** list;
        while (ptr **!=** NULL)
        {
            node *****next **=** ptr**->**next;
            free(ptr);
            ptr **=** next;
        }
    }
    ```
    
    Notice that what the user inputs at the command line is put into the `number` field of a node called `n`, and then that node is added to the `list`. For example, `./list 1 2` will put the number `1` into the `number` field of a node called `n`, then put a pointer to `list` into the `next` field of the node, and then update `list` to point to `n`. That same process is repeated for `2`. Next, `node *ptr = list` creates a temporary variable that points at the same spot that `list` points to. The `while` prints what at the node `ptr` points to, and then updates `ptr` to point to the `next` node in the list. Finally, all the memory is freed.
    
- In this example, inserting into the list is always in the order of , as it only takes a very small number of steps to insert at the front of a list.
    
    O(1)
    
- Considering the amount of time required to search this list, it is in the order of , as in the worst case the entire list must always be searched to find an item. The time complexity for adding a new element to the list will depend on where that element is added. This is illustrated in the examples below.
    
    O(n)
    
- Linked lists are not stored in a contiguous block of memory. They can grow as large as you wish, provided that enough system resources exist. The downside, however, is that more memory is required to keep track of the list instead of an array. This is because for each element, you must store not just the value of the element, but also a pointer to the next node. Further, linked lists cannot be indexed into like is possible in an array because we need to pass through the first  elements to find the location of the th element. Because of this, the list pictured above must be linearly searched. Binary search, therefore, is not possible in a list constructed as above.
    
    n−1
    
    n
    
- 
    
    Further, you could place numbers at the end of the list as illustrated in this code:
    
    ```c
    *// Implements a list of numbers using a linked list**#include*** *<cs50.h>
    **#include*** *<stdio.h>
    **#include*** *<stdlib.h>*typedef struct node
    {
        int number;
        struct node *****next;
    }
    node;
    
    int **main**(int argc, char *****argv[])
    {
        *// Memory for numbers*node *****list **=** NULL;
    
        *// For each command-line argument*for (int i **=** 1; i **<** argc; i**++**)
        {
            *// Convert argument to int*int number **=** atoi(argv[i]);
    
            *// Allocate node for number*node *****n **=** malloc(sizeof(node));
            if (n **==** NULL)
            {
                return 1;
            }
            n**->**number **=** number;
            n**->**next **=** NULL;
    
            *// If list is empty*if (list **==** NULL)
            {
                *// This node is the whole list*list **=** n;
            }
    
            *// If list has numbers already*else
            {
                *// Iterate over nodes in list*for (node *****ptr **=** list; ptr **!=** NULL; ptr **=** ptr**->**next)
                {
                    *// If at end of list*if (ptr**->**next **==** NULL)
                    {
                        *// Append node*ptr**->**next **=** n;
                        break;
                    }
                }
            }
        }
    
        *// Print numbers*for (node *****ptr **=** list; ptr **!=** NULL; ptr **=** ptr**->**next)
        {
            printf("%i\n", ptr**->**number);
        }
    
        *// Free memory*node *****ptr **=** list;
        while (ptr **!=** NULL)
        {
            node *****next **=** ptr**->**next;
            free(ptr);
            ptr **=** next;
        }
    }
    ```
    
    Notice how this code *walks down* this list to find the end. When appending an element, (adding to the end of the list) our code will run in O(n), as we have to go through our entire list before we can add the final element.
    
- 
    
    Further, you could sort your list as items are added:
    
    ```c
    *// Implements a sorted list of numbers using a linked list**#include*** *<cs50.h>
    **#include*** *<stdio.h>
    **#include*** *<stdlib.h>*typedef struct node
    {
        int number;
        struct node *****next;
    }
    node;
    
    int **main**(int argc, char *****argv[])
    {
        *// Memory for numbers*node *****list **=** NULL;
    
        *// For each command-line argument*for (int i **=** 1; i **<** argc; i**++**)
        {
            *// Convert argument to int*int number **=** atoi(argv[i]);
    
            *// Allocate node for number*node *****n **=** malloc(sizeof(node));
            if (n **==** NULL)
            {
                return 1;
            }
            n**->**number **=** number;
            n**->**next **=** NULL;
    
            *// If list is empty*if (list **==** NULL)
            {
                list **=** n;
            }
    
            *// If number belongs at beginning of list*else if (n**->**number **<** list**->**number)
            {
                n**->**next **=** list;
                list **=** n; 
            }
    
            *// If number belongs later in list*else
            {
                *// Iterate over nodes in list*for (node *****ptr **=** list; ptr **!=** NULL; ptr **=** ptr**->**next)
                {
                    *// If at end of list*if (ptr**->**next **==** NULL)
                    {
                        *// Append node*ptr**->**next **=** n;
                        break;
                    }
    
                    *// If in middle of list*if (n**->**number **<** ptr**->**next**->**number)
                    {
                        n**->**next **=** ptr**->**next;
                        ptr**->**next **=** n;
                        break;
                    }
                }
            }
        }
    
        *// Print numbers*for (node *****ptr **=** list; ptr **!=** NULL; ptr **=** ptr**->**next)
        {
            printf("%i\n", ptr**->**number);
        }
    
        *// Free memory*node *****ptr **=** list;
        while (ptr **!=** NULL)
        {
            node *****next **=** ptr**->**next;
            free(ptr);
            ptr **=** next;
        }
    }
    ```
    
    Notice how this list is sorted as it is built. To insert an element in this specific order, our code will still run in O(n) for each insertion, as in the worst case we will have to look through all current elements.
    

## [**Trees**](https://cs50.harvard.edu/x/2024/notes/5/#trees)

- *Binary search trees* are another data structure that can be used to store data more efficiently such that it can be searched and retrieved.
- 
    
    You can imagine a sorted sequence of numbers.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide118.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide118.png)
    
- 
    
    Imagine then that the center value becomes the top of a tree. Those that are less than this value are placed to the left. Those values that are more than this value are to the right.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide119.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide119.png)
    
- 
    
    Pointers can then be used to point to the correct location of each area of memory such that each of these nodes can be connected.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide120.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide120.png)
    
- 
    
    In code, this can be implemented as follows.
    
    ```c
    *// Implements a list of numbers as a binary search tree**#include*** *<stdio.h>
    **#include*** *<stdlib.h>// Represents a node*typedef struct node
    {
        int number;
        struct node *****left;
        struct node *****right;
    }
    node;
    
    void **free_tree**(node *****root);
    void **print_tree**(node *****root);
    
    int **main**(void)
    {
        *// Tree of size 0*node *****tree **=** NULL;
    
        *// Add number to list*node *****n **=** malloc(sizeof(node));
        if (n **==** NULL)
        {
            return 1;
        }
        n**->**number **=** 2;
        n**->**left **=** NULL;
        n**->**right **=** NULL;
        tree **=** n;
    
        *// Add number to list*n **=** malloc(sizeof(node));
        if (n **==** NULL)
        {
            free_tree(tree);
            return 1;
        }
        n**->**number **=** 1;
        n**->**left **=** NULL;
        n**->**right **=** NULL;
        tree**->**left **=** n;
    
        *// Add number to list*n **=** malloc(sizeof(node));
        if (n **==** NULL)
        {
            free_tree(tree);
            return 1;
        }
        n**->**number **=** 3;
        n**->**left **=** NULL;
        n**->**right **=** NULL;
        tree**->**right **=** n;
    
        *// Print tree*print_tree(tree);
    
        *// Free tree*free_tree(tree);
        return 0;
    }
    
    void **free_tree**(node *****root)
    {
        if (root **==** NULL)
        {
            return;
        }
        free_tree(root**->**left);
        free_tree(root**->**right);
        free(root);
    }
    
    void **print_tree**(node *****root)
    {
        if (root **==** NULL)
        {
            return;
        }
        print_tree(root**->**left);
        printf("%i\n", root**->**number);
        print_tree(root**->**right);
    }
    ```
    
    Notice this search function begins by going to the location of `tree`. Then, it uses recursion to search for `number`. The `free_tree` function recursively frees the tree. `print_tree` recursively prints the tree.
    
- A tree like the above offers dynamism that an array does not offer. It can grow and shrink as we wish.
- Further, this structure offers a search time of .
    
    O(logn)
    

## [**Dictionaries**](https://cs50.harvard.edu/x/2024/notes/5/#dictionaries)

- *Dictionaries* are another data structure.
- Dictionaries, like actual book-form dictionaries that have a word and a definition, have a *key* and a *value*.
- 
    
    The *holy grail* of algorithmic time complexity is O(1) or *constant time*. That is, the ultimate is for access to be instantaneous.
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide151.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide151.png)
    
- Dictionaries can offer this speed of access through hashing.

## [**Hashing and Hash Tables**](https://cs50.harvard.edu/x/2024/notes/5/#hashing-and-hash-tables)

- *Hashing* is the idea of taking a value and being able to output a value that becomes a shortcut to it later.
- For example, hashing *apple* may hash as a value of `1`, and *berry* may be hashed as `2`. Therefore, finding *apple* is as easy as asking the *hash* algorithm where *apple* is stored. While not ideal in terms of design, ultimately, putting all *a*’s in one bucket and *b*’s in another, this concept of *bucketizing* hashed values illustrates how you can use this concept: a hashed value can be used to shortcut finding such a value.
- A *hash function* is an algorithm that reduces a larger value to something small and predictable. Generally, this function takes in an item you wish to add to your hash table, and returns an integer representing the array index in which the item should be placed.
- A *hash table* is a fantastic combination of both arrays and linked lists. When implemented in code, a hash table is an *array* of *pointers* to *node*s.
- 
    
    A hash table could be imagined as follows:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide157.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide157.png)
    
    Notice that this is an array that is assigned each value of the alphabet.
    
- 
    
    Then, at each location of the array, a linked list is used to track each value being stored there:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide169.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide169.png)
    
- *Collisions* are when you add values to the hash table, and something already exists at the hashed location. In the above, collisions are simply appended to the end of the list.
- 
    
    Collisions can be reduced by better programming your hash table and hash algorithm. You can imagine an improvement upon the above as follows:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide184.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide184.png)
    
- 
    
    Consider the following example of a hash algorithm:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide173.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide173.png)
    
- 
    
    This could be implemented in code as:
    
    ```c
    ***#include*** *<ctype.h>*unsigned int **hash**(const char *****word)
    {
        return toupper(word[0]) **-** 'A';
    }
    ```
    
    Notice how the hash function returns the value of `toupper(word[0]) - 'A'`.
    
- You, as the programmer, have to make a decision about the advantages of using more memory to have a large hash table and potentially reducing search time or using less memory and potentially increasing search time.

## [**Tries**](https://cs50.harvard.edu/x/2024/notes/5/#tries)

- *Tries* are another form of data structure.
- *Tries* are always searchable in constant time.
- One downside to *Tries* is that they tend to take up a large amount of memory. Notice that we need  `node`s just to store *Toad*!
    
    26×4=104
    
- 
    
    *Toad* would be stored as follows:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide207.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide207.png)
    
- 
    
    *Tom* would then be stored as follows:
    
    ![https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide209.png](https://cs50.harvard.edu/x/2024/notes/5/cs50Week5Slide209.png)
    
- The downside of this structure is how many resources are required to use it.

## [**Summing Up**](https://cs50.harvard.edu/x/2024/notes/5/#summing-up)

In this lesson, you learned about using pointers to build new data structures. Specifically, we delved into…

- Data structures
- Stacks and queues
- Resizing arrays
- Linked lists
- Dictionaries
- Tries

See you next time!

[1. Data Structures](https://www.notion.so/1-Data-Structures-15060895bd36809aa03dcb9bc99666db?pvs=21)

[2. Structures](https://www.notion.so/2-Structures-15060895bd3680319575c1e4cdb18e28?pvs=21)

[3. Singly-Linked Lists](https://www.notion.so/3-Singly-Linked-Lists-15060895bd3680a8a4d3fc07990948d8?pvs=21)

[4. Doubly-Linked Lists](https://www.notion.so/4-Doubly-Linked-Lists-15060895bd36807ea5e3f31550133ce6?pvs=21)

[5. Hash Tables](https://www.notion.so/5-Hash-Tables-15060895bd3680a2ae89ee8875504730?pvs=21)

[6. Tries](https://www.notion.so/6-Tries-15060895bd36802c8b82f6662453e14d?pvs=21)

[7. Queues](https://www.notion.so/7-Queues-15060895bd3680d59c54c4afc62e1343?pvs=21)

[8. Stacks](https://www.notion.so/8-Stacks-15060895bd368028bf7ffcdc02d29d94?pvs=21)

[Section](https://www.notion.so/Section-15060895bd36808d9e16eab309fa7ad9?pvs=21)

[Problem Set 5](https://www.notion.so/Problem-Set-5-15060895bd3680ecb816d29c917a018d?pvs=21)