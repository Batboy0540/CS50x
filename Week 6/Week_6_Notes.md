# Week 6: Python

# [**Lecture 6**](https://cs50.harvard.edu/x/2024/notes/6/#lecture-6)

- [Welcome!](https://cs50.harvard.edu/x/2024/notes/6/#welcome)
- [Python](https://cs50.harvard.edu/x/2024/notes/6/#python)
- [Hello](https://cs50.harvard.edu/x/2024/notes/6/#hello)
- [Speller](https://cs50.harvard.edu/x/2024/notes/6/#speller)
- [Filter](https://cs50.harvard.edu/x/2024/notes/6/#filter)
- [CS50 Library](https://cs50.harvard.edu/x/2024/notes/6/#cs50-library)
- [Strings](https://cs50.harvard.edu/x/2024/notes/6/#strings)
- [Variables](https://cs50.harvard.edu/x/2024/notes/6/#variables)
- [Types](https://cs50.harvard.edu/x/2024/notes/6/#types)
- [Calculator](https://cs50.harvard.edu/x/2024/notes/6/#calculator)
- [Conditionals](https://cs50.harvard.edu/x/2024/notes/6/#conditionals)
- [Object-Oriented Programming](https://cs50.harvard.edu/x/2024/notes/6/#object-oriented-programming)
- [Loops](https://cs50.harvard.edu/x/2024/notes/6/#loops)
- [Abstraction](https://cs50.harvard.edu/x/2024/notes/6/#abstraction)
- [Truncation and Floating Point Imprecision](https://cs50.harvard.edu/x/2024/notes/6/#truncation-and-floating-point-imprecision)
- [Exceptions](https://cs50.harvard.edu/x/2024/notes/6/#exceptions)
- [Mario](https://cs50.harvard.edu/x/2024/notes/6/#mario)
- [Lists](https://cs50.harvard.edu/x/2024/notes/6/#lists)
- [Searching and Dictionaries](https://cs50.harvard.edu/x/2024/notes/6/#searching-and-dictionaries)
- [Command-Line Arguments](https://cs50.harvard.edu/x/2024/notes/6/#command-line-arguments)
- [Exit Status](https://cs50.harvard.edu/x/2024/notes/6/#exit-status)
- [Third-Party Libraries](https://cs50.harvard.edu/x/2024/notes/6/#third-party-libraries)
- [Summing Up](https://cs50.harvard.edu/x/2024/notes/6/#summing-up)

## [**Welcome!**](https://cs50.harvard.edu/x/2024/notes/6/#welcome)

- In previous weeks, you were introduced to the fundamental building blocks of programming.
- You learned about programming in a lower-level programming language called C.
- Today, we are going to work with a higher-level programming language called *Python*.
- As you learn this new language, you’re going to find that you are going to be more able to teach yourself new programming languages.

## [**Python**](https://cs50.harvard.edu/x/2024/notes/6/#python)

- Humans, over the decades, have seen how previous design decisions could be improved upon.
- Python is a programming language that builds upon what you have already learned in C.
- Unlike in C, Python is an interpreted language, where you need not separately compile your program. Instead, you run your program in the *Python Interpreter*.

## [**Hello**](https://cs50.harvard.edu/x/2024/notes/6/#hello)

- 
    
    Up until this point, the code has looked like this:
    
    ```python
    *// A program that says hello to the world**#include*** *<stdio.h>*int **main**(void)
    {
        printf("hello, world\n");
    }
    ```
    
- Today, you’ll find that the process of writing and compiling code has been simplified.
- 
    
    For example, the above code will be rendered in Python as:
    
    ```python
    *# A program that says hello to the world*
    **print**("hello, world")
    ```
    
    Notice that the semicolon is gone and that no library is needed.
    
- Python notably can implement what was quite complicated in C with relative simplicity.

## [**Speller**](https://cs50.harvard.edu/x/2024/notes/6/#speller)

- 
    
    To illustrate this simplicity, let’s type ‘code dictionary.py’ in the terminal window and write code as follows:
    
    ```python
    *# Words in dictionary*
    words **=** **set**()
    
    def **check**(word):
        """Return true if word is in dictionary else false"""
        return word.**lower**() **in** words
    
    def **load**(dictionary):
        """Load dictionary into memory, returning true if successful else false"""
        with **open**(dictionary) as file:
            words.**update**(file.**read**().**splitlines**())
        return True
    
    def **size**():
        """Returns number of words in dictionary if loaded else 0 if not yet loaded"""
        return **len**(words)
    
    def **unload**():
        """Unloads dictionary from memory, returning true if successful else false"""
        return True
    ```
    
    Notice that there are four functions above. In the `check` function, if a `word` is in `words`, it returns `True`. So much easier than an implementation in C! Similarly, in the `load` function the dictionary file is opened. For each line in that file, we add that line to `words`. Using `rstrip`, the trailing new line is removed from the added word. `size` simply returns the `len` or length of `words`. `unload` only needs to return `True` because Python handles memory management on its own.
    
- The above code illustrates why higher-level languages exist: To simplify and allow you to write code more easily.
- However, speed is a tradeoff. Because C allows you, the programmer, to make decisions about memory management, it may run faster than Python – depending on your code. While C only runs your lines of code, Python runs all the code that comes under the hood with it when you call Python’s built-in functions.
- You can learn more about functions in the [Python documentation](https://docs.python.org/3/library/functions.html)

## [**Filter**](https://cs50.harvard.edu/x/2024/notes/6/#filter)

- 
    
    To further illustrate this simplicity, create a new file by typing `code blur.py` in your terminal window and write code as follows:
    
    ```python
    *# Blurs an image*
    from PIL import Image, ImageFilter
    
    *# Blur image*
    before **=** Image.**open**("bridge.bmp")
    after **=** before.**filter**(ImageFilter.**BoxBlur**(1))
    after.**save**("out.bmp")
    ```
    
    Notice that this program imports modules `Image` and `ImageFilter` from a library called `PIL`. This takes an input file and creates and output file.
    
- 
    
    Further, you can create a new file called `edges.py` as follows:
    
    ```python
    *# Finds edges in an image*
    from PIL import Image, ImageFilter
    
    *# Find edges*
    before **=** Image.**open**("bridge.bmp")
    after **=** before.**filter**(ImageFilter.FIND_EDGES)
    after.**save**("out.bmp")
    ```
    
    Notice that this code is a small adjustment to your `blur` code, but produces a dramatically different result.
    
- 
    
    Finally, you can even do face detection as follows:
    
    ```python
    *# Find faces in picture
    # https://github.com/ageitgey/face_recognition/blob/master/examples/find_faces_in_picture.py*
    from PIL import Image
    import face_recognition
    
    *# Load the jpg file into a numpy array*
    image **=** face_recognition.**load_image_file**("office.jpg")
    
    *# Find all the faces in the image using the default HOG-based model.
    # This method is fairly accurate, but not as accurate as the CNN model and not GPU accelerated.
    # See also: find_faces_in_picture_cnn.py*
    face_locations **=** face_recognition.**face_locations**(image)
    
    for face_location **in** face_locations:
    
        *# Print the location of each face in this image*
        top, right, bottom, left **=** face_location
    
        *# You can access the actual face itself like this:*
        face_image **=** image[top:bottom, left:right]
        pil_image **=** Image.**fromarray**(face_image)
        pil_image.**show**()
    ```
    
    Notice how this file uses a third-party library called face_recognition. This is enabled by running `pip install face_recognition` in one’s terminal window.
    
- 
    
    Python allows you to abstract away programming that would be much more complicated within C and other *lower-level* programming languages.
    

## [**CS50 Library**](https://cs50.harvard.edu/x/2024/notes/6/#cs50-library)

- As with C, the CS50 library can be utilized within Python.
- 
    
    The following functions will be of particular use:
    
    ```python
      get_float
      get_int
      get_string
    ```
    
- 
    
    You also have the option of importing only specific functions from the CS50 library as follows:
    
    ```python
    from CS50 import get_float, get_int, get_string
    ```
    

## [**Strings**](https://cs50.harvard.edu/x/2024/notes/6/#strings)

- 
    
    In C, you might remember this code:
    
    ```python
    *// get_string and printf with %s**#include*** *<cs50.h>
    **#include*** *<stdio.h>*int **main**(void)
    {
        string answer **=** get_string("What's your name? ");
        printf("hello, %s\n", answer);
    }
    ```
    
- 
    
    This code is transformed in Python to:
    
    ```python
    *# get_string and print, with concatenation*
    from cs50 import get_string
    
    answer **=** **get_string**("What's your name? ")
    **print**("hello, " **+** answer)
    ```
    
    You can write this code by executing `code hello.py` in the terminal window. Then, you can execute this code by running `python hello.py`. Notice how the `+` sign concatenates `"hello, "` and `answer`.
    
- 
    
    Similarly, you could implement the above code as:
    
    `*# get_string and print, with format strings*
    from cs50 import get_string
    
    answer **=** **get_string**("What's your name? ")
    **print**(f"hello, {answer}")`
    
    Notice how the curly braces allow for the `print` function to interpolate the `answer` such that `answer` appears within. The `f` is required to include the `answer` properly formatting.
    

## [**Variables**](https://cs50.harvard.edu/x/2024/notes/6/#variables)

- Variable declaration is simplified too. In C, you might have `int counter = 0;`. In Python, this same line would read `counter = 0`. You need not declare the type of the variable.
- Python favors `counter += 1` to increment by one, losing the ability found in C to type `counter++`.

## [**Types**](https://cs50.harvard.edu/x/2024/notes/6/#types)

- Data types in Python do not need to be explicitly declared. For example, you saw how `answer` above is a string, but we did not have to tell the interpreter this was the case: It knew on its own.
- 
    
    In Python, commonly used types include:
    
    ```python
      bool
      float
      int
      str
    ```
    
    Notice that `long` and `double` are missing. Python will handle what data type should be used for larger and smaller numbers.
    
- 
    
    Some other data types in Python include:
    
    ```python
      range
      list
      tuple
      dict
      set
    ```
    
- Each of these data types can be implemented in C, but in Python they can be implemented more simply.

## [**Calculator**](https://cs50.harvard.edu/x/2024/notes/6/#calculator)

- 
    
    You might recall `calculator.c` from earlier in the course:
    
    ```python
    *// Addition with int**#include*** *<cs50.h>
    **#include*** *<stdio.h>*int **main**(void)
    {
        *// Prompt user for x*int x **=** get_int("x: ");
    
        *// Prompt user for y*int y **=** get_int("y: ");
    
        *// Perform addition*printf("%i\n", x **+** y);
    }
    ```
    
- 
    
    We can implement a simple calculator just as we did within C. Type `code calculator.py` into the terminal window and write code as follows:
    
    ```python
    *# Addition with int [using get_int]*
    from cs50 import get_int
    
    *# Prompt user for x*
    x **=** **get_int**("x: ")
    
    *# Prompt user for y*
    y **=** **get_int**("y: ")
    
    *# Perform addition*
    **print**(x **+** y)
    ```
    
    Notice how the CS50 library is imported. Then, `x` and `y` are gathered from the user. Finally, the result is printed. Notice that the `main` function that would have been seen in a C program is gone entirely! While one could utilize a `main` function, it is not required.
    
- 
    
    It’s possible for one to remove the training wheels of the CS50 library. Modify your code as follows:
    
    ```python
    *# Addition with int [using input]
    # Prompt user for x*
    x **=** **input**("x: ")
    
    *# Prompt user for y*
    y **=** **input**("y: ")
    
    *# Perform addition*
    **print**(x **+** y)
    ```
    
    Notice how executing the above code results in strange program behavior. Why might this be so?
    
- 
    
    You may have guessed that the interpreter understood `x` and `y` to be strings. You can fix your code by employing the `int` function as follows:
    
    ```python
    *# Addition with int [using input]
    # Prompt user for x*
    x **=** **int**(**input**("x: "))
    
    *# Prompt user for y*
    y **=** **int**(**input**("y: "))
    
    *# Perform addition*
    **print**(x **+** y)
    ```
    
    Notice how the input for `x` and `y` is passed to the `int` function which converts it to an integer. Without converting `x` and `y` to be integers, the characters will concatenate.
    

## [**Conditionals**](https://cs50.harvard.edu/x/2024/notes/6/#conditionals)

- 
    
    In C, you might remember a program like this:
    
    ```python
    *// Conditionals, Boolean expressions, relational operators**#include*** *<cs50.h>
    **#include*** *<stdio.h>*int **main**(void)
    {
        *// Prompt user for integers*int x **=** get_int("What's x? ");
        int y **=** get_int("What's y? ");
    
        *// Compare integers*if (x **<** y)
        {
            printf("x is less than y\n");
        }
        else if (x **>** y)
        {
            printf("x is greater than y\n");
        }
        else
        {
            printf("x is equal to y\n");
        }
    }
    ```
    
- 
    
    In Python, it would appear as follows:
    
    ```python
    *# Conditionals, Boolean expressions, relational operators*
    from cs50 import get_int
    
    *# Prompt user for integers*
    x **=** **get_int**("What's x? ")
    y **=** **get_int**("What's y? ")
    
    *# Compare integers*
    if x **<** y:
        **print**("x is less than y")
    elif x **>** y:
        **print**("x is greater than y")
    else:
        **print**("x is equal to y")
    ```
    
    Notice that there are no more curly braces. Instead, indentations are utilized. Second, a colon is utilized in the `if` statement. Further, `elif` replaces `else if`. Parentheses are also no longer required in the `if` and `elif` statements.
    
- 
    
    In C, we faced challenges when we wanted to compare two values. Consider the following code:
    
    ```python
    *// Conditionals, Boolean expressions, relational operators**#include*** *<cs50.h>
    **#include*** *<stdio.h>*int **main**(void)
    {
        *// Prompt user for integers*int x **=** get_int("What's x? ");
        int y **=** get_int("What's y? ");
    
        *// Compare integers*if (x **<** y)
        {
            printf("x is less than y\n");
        }
        else if (x **>** y)
        {
            printf("x is greater than y\n");
        }
        else
        {
            printf("x is equal to y\n");
        }
    }
    ```
    
- 
    
    In Python, we can execute the above as follows:
    
    ```python
    *# Conditionals, Boolean expressions, relational operators*
    from cs50 import get_int
    
    *# Prompt user for integers*
    x **=** **get_int**("What's x? ")
    y **=** **get_int**("What's y? ")
    
    *# Compare integers*
    if x **<** y:
        **print**("x is less than y")
    elif x **>** y:
        **print**("x is greater than y")
    else:
        **print**("x is equal to y")
    ```
    
    Notice that the CS50 library is imported. Further, minor changes exist in the `if` statement.
    
- 
    
    Further looking at comparisons, consider the following code in C:
    
    ```python
    *// Logical operators**#include*** *<cs50.h>
    **#include*** *<stdio.h>*int **main**(void)
    {
        *// Prompt user to agree*char c **=** get_char("Do you agree? ");
    
        *// Check whether agreed*if (c **==** 'Y' **||** c **==** 'y')
        {
            printf("Agreed.\n");
        }
        else if (c **==** 'N' **||** c **==** 'n')
        {
            printf("Not agreed.\n");
        }
    }
    ```
    
- 
    
    The above can be implemented as follows:
    
    ```python
    *# Logical operators*
    from cs50 import get_string
    
    *# Prompt user to agree*
    s **=** **get_string**("Do you agree? ")
    
    *# Check whether agreed*
    if s **==** "Y" **or** s **==** "y":
        **print**("Agreed.")
    elif s **==** "N" **or** s **==** "n":
        **print**("Not agreed.")
    ```
    
    Notice that the two vertical bars utilized in C is replaced with `or`. Indeed, people often enjoy Python because it is more readable by humans. Also, notice that `char` does not exist in Python. Instead, `str`s are utilized.
    
- 
    
    Another approach to this same code could be as follows using *lists*:
    
    ```python
    *# Logical operators, using lists*
    from cs50 import get_string
    
    *# Prompt user to agree*
    s **=** **get_string**("Do you agree? ")
    
    *# Check whether agreed*
    if s **in** ["y", "yes"]:
        **print**("Agreed.")
    elif s **in** ["n", "no"]:
        **print**("Not agreed.")
    ```
    
    Notice how we are able to express multiple keywords like `y` and `yes` in a `list`.
    

## [**Object-Oriented Programming**](https://cs50.harvard.edu/x/2024/notes/6/#object-oriented-programming)

- Up until this point, our programs in this course have been linear: sequential.
- It’s possible to have certain types of values not only have properties or attributes inside of them but have functions as well. In Python, these values are known as *objects*
- In C, we could create a `struct` where you could associate multiple variables inside a single self-created data type. In Python, we can do this and also include functions in a self-created data type. When a function belongs to a specific *object*, it is known as a *method*.
- 
    
    For example, `strs` in Python have a built-in *methods*. Therefore, you could modify your code as follows:
    
    ```python
    *# Logical operators, using lists*
    from cs50 import get_string
    
    *# Prompt user to agree*
    s **=** **get_string**("Do you agree? ").**lower**()
    
    *# Check whether agreed*
    if s.**lower**() **in** ["y", "yes"]:
        **print**("Agreed.")
    elif s.**lower**() **in** ["n", "no"]:
        **print**("Not agreed.")
    ```
    
    Notice how the old value of `s` is overwritten with the result of `s.lower()`, a built-in method of `strs`.
    
- In this class, we will only scratch the surface of Python. Therefore, the [Python documentation](https://docs.python.org/) will be of particular importance as you continue.
- You can learn more about string methods in the [Python documentation](https://docs.python.org/3/library/stdtypes.html#string-methods)

## [**Loops**](https://cs50.harvard.edu/x/2024/notes/6/#loops)

- 
    
    Loops in Python are very similar to C. You may recall the following code in C:
    
    ```python
    *// Demonstrates while loop**#include*** *<stdio.h>*int **main**(void)
    {
        int i **=** 0;
        while (i **<** 3)
        {
            printf("meow\n");
            i**++**;
        }
    }
    ```
    
- 
    
    In Python, this code appears as:
    
    ```python
    *# Demonstrates while loop*
    i **=** 0
    while i **<** 3:
        **print**("meow")
        i **+=** 1
    ```
    
- 
    
    `for` loops can be implemented in Python as follows:
    
    ```python
    *# Better design*
    for i **in** **range**(3):
        **print**("meow")
    ```
    
    Notice that `i` is never explicitly used. However, Python will increment the value of `i`.
    
- 
    
    Similarly, one could express the above code as:
    
    ```python
    *# Abstraction with parameterization*
    def **main**():
        **meow**(3)
    
    *# Meow some number of times*
    def **meow**(n):
        for i **in** **range**(n):
            **print**("meow")
    
    **main**()
    ```
    
    Notice that a function is utilized to abstract away the meowing.
    
- 
    
    Finally, a `while` loop could be implemented as follows:
    
    ```python
    *# Demonstrates while loop*
    i **=** 0
    while i **<** 3:
        **print**("meow")
        i **+=** 1
    ```
    
- 
    
    To further our understanding of loops and iteration in Python, let’s create a new file called `uppercase.py` as follows:
    
    ```python
    *# Uppercases string one character at a time*
    before **=** **input**("Before: ")
    **print**("After:  ", end**=**"")
    for c **in** before:
        **print**(c.**upper**(), end**=**"")
    **print**()
    ```
    
    Notice how `end=` is used to pass a parameter to the `print` function that continues the line without a line ending. This code passes one string at a time.
    
- 
    
    Reading the documentation, we discover that Python has methods that can be implemented upon the entire string as follows:
    
    ```python
    *# Uppercases string all at once*
    before **=** **input**("Before: ")
    after **=** before.**upper**()
    **print**(f"After:  {after}")
    ```
    
    Notice how `.upper` is applied to the entire string.
    

## [**Abstraction**](https://cs50.harvard.edu/x/2024/notes/6/#abstraction)

- 
    
    As we hinted at earlier today, you can further improve upon our code using functions and abstracting away various code into functions. Modify your earlier-created `meow.py` code as follows:
    
    ```python
    *# Abstraction*
    def **main**():
        for i **in** **range**(3):
            **meow**()
    
    *# Meow once*
    def **meow**():
        **print**("meow")
    
    **main**()
    ```
    
    Notice that the `meow` function abstracts away the `print` statement. Further, notice that the `main` function appears at the top of the file. At the bottom of the file, the `main` function is called. By convention, it’s expected that you create a `main` function in Python.
    
- 
    
    Indeed, we can pass variables between our functions as follows:
    
    ```python
    *# Abstraction with parameterization*
    def **main**():
        **meow**(3)
    
    *# Meow some number of times*
    def **meow**(n):
        for i **in** **range**(n):
            **print**("meow")
    
    **main**()
    ```
    
    Notice how `meow` now takes a variable `n`. In the `main` function, you can call `meow` and pass a value like `3` to it. Then, `meow` utilizes the value of `n` in the `for` loop.
    
- 
    
    Reading the above code, notice how you, as a C programmer, are able to quite easily make sense of the above code. While some conventions are different, the building blocks you previously learned are very apparent in this new programming language.
    

## [**Truncation and Floating Point Imprecision**](https://cs50.harvard.edu/x/2024/notes/6/#truncation-and-floating-point-imprecision)

- Recall that in C, we experienced truncation where one integer being divided by another could result in an inprecise result.
- 
    
    You can see how Python handles such division as follows by modifying your code for `calculator.py`:
    
    ```python
    *# Division with integers, demonstration lack of truncation
    # Prompt user for x*
    x **=** **int**(**input**("x: "))
    
    *# Prompt user for y*
    y **=** **int**(**input**("y: "))
    
    *# Divide x by y*
    z **=** x **/** y
    **print**(z)
    ```
    
    Notice that executing this code results in a value, but that if you were to see more digits after `.333333` you’d see that we are faced with *floating-point imprecision*. Truncation does not occur.
    
- 
    
    We can reveal this imprecision by modifying our codes slightly:
    
    ```python
    *# Floating-point imprecision
    # Prompt user for x*
    x **=** **int**(**input**("x: "))
    
    *# Prompt user for y*
    y **=** **int**(**input**("y: "))
    
    *# Divide x by y*
    z **=** x **/** y
    **print**(f"{z:.50f}")
    ```
    
    Notice that this code reveals the imprecision. Python still faces this issue, just as C does.
    

## [**Exceptions**](https://cs50.harvard.edu/x/2024/notes/6/#exceptions)

- Let’s explore more about exceptions that can occur when we run Python code.
- 
    
    Modify `calculator.py` as follows:
    
    ```python
    *# Implements get_int*
    def **get_int**(prompt):
        return **int**(**input**(prompt))
    
    def **main**():
    
        *# Prompt user for x*
        x **=** **get_int**("x: ")
    
        *# Prompt user for y*
        y **=** **get_int**("y: ")
    
        *# Perform addition*
        **print**(x **+** y)
    
    **main**()
    ```
    
    Notice that inputting the wrong data could result in an error.
    
- 
    
    We can `try` to handle and *catch* potential exceptions by modifying our code as follows:
    
    ```python
    *# Implements get_int with a loop*
    def **get_int**(prompt):
        while True:
            try:
                return **int**(**input**(prompt))
            except ValueError:
                **print**("Not an integer")
    
    def **main**():
    
        *# Prompt user for x*
        x **=** **get_int**("x: ")
    
        *# Prompt user for y*
        y **=** **get_int**("y: ")
    
        *# Perform addition*
        **print**(x **+** y)
    
    **main**()
    ```
    
    Notice that the above code repeatedly tries to get the correct type of data, providing additional prompts when needed.
    

## [**Mario**](https://cs50.harvard.edu/x/2024/notes/6/#mario)

- 
    
    Recall a few weeks ago our challenge of building three blocks on top of one another, like in Mario.
    
    ![https://cs50.harvard.edu/x/2024/notes/6/cs50Week6Slide073.png](https://cs50.harvard.edu/x/2024/notes/6/cs50Week6Slide073.png)
    
- 
    
    In Python, we can implement something akin to this as follows:
    
    ```python
    *# Prints a column of 3 bricks with a loop*
    for i **in** **range**(3):
        **print**("#")
    ```
    
- 
    
    In C, we had the advantage of a `do-while` loop. However, in Python it is convention to utilize a `while` loop, as Python does not have a `do while` loop. You can write code as follows in a file called `mario.py`:
    
    ```python
    *# Prints a column of n bricks with a loop*
    from cs50 import get_int
    
    while True:
        n **=** **get_int**("Height: ")
        if n **>** 0:
            break
    
    for i **in** **range**(n):
        **print**("#")
    ```
    
    Notice how the while loop is used to obtain the height. Once a height greater than zero is inputted, the loop breaks.
    
- 
    
    Consider the following image:
    
    ![https://cs50.harvard.edu/x/2024/notes/6/cs50Week6Slide075.png](https://cs50.harvard.edu/x/2024/notes/6/cs50Week6Slide075.png)
    
- 
    
    In Python, we could implement by modifying your code as follows:
    
    ```python
    *# Prints a row of 4 question marks with a loop*
    for i **in** **range**(4):
        **print**("?", end**=**"")
    **print**()
    ```
    
    Notice that you can override the behavior of the `print` function to stay on the same line as the previous print.
    
- 
    
    Similar in spirit to previous iterations, we can further simplify this program:
    
    ```python
    *# Prints a row of 4 question marks without a loop*
    **print**("?" ***** 4)
    ```
    
    Notice that we can utilize `*` to multiply the print statement to repeat `4` times.
    
- 
    
    What about a large block of bricks?
    
    ![https://cs50.harvard.edu/x/2024/notes/6/cs50Week6Slide078.png](https://cs50.harvard.edu/x/2024/notes/6/cs50Week6Slide078.png)
    
- 
    
    To implement the above, you can modify your code as follows:
    
    ```python
    *# Prints a 3-by-3 grid of bricks with loops*
    for i **in** **range**(3):
        for j **in** **range**(3):
            **print**("#", end**=**"")
        **print**()
    ```
    
    Notice how one `for` loop exists inside another. The `print` statement adds a new line at the end of each row of bricks.
    
- 
    
    You can learn more about the `print` function in the [Python documentation](https://docs.python.org/3/library/functions.html#print)
    

## [**Lists**](https://cs50.harvard.edu/x/2024/notes/6/#lists)

- `list`s are a data structure within Python.
- `list`s have built in methods or functions within them.
- 
    
    For example, consider the following code:
    
    ```python
    *# Averages three numbers using a list
    # Scores*
    scores **=** [72, 73, 33]
    
    *# Print average*
    average **=** **sum**(scores) **/** **len**(scores)
    **print**(f"Average: {average}")
    ```
    
    Notice that you can use the built-in `sum` method to calculate the average.
    
- 
    
    You can even utilize the following syntax to get values from the user:
    
    ```python
    *# Averages three numbers using a list and a loop*
    from cs50 import get_int
    
    *# Get scores*
    scores **=** []
    for i **in** **range**(3):
        score **=** **get_int**("Score: ")
        scores.**append**(score)
    
    *# Print average*
    average **=** **sum**(scores) **/** **len**(scores)
    **print**(f"Average: {average}")
    ```
    
    Notice that this code utilizes the built-in `append` method for lists.
    
- You can learn more about lists in the [Python documentation](https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range)
- You can also learn more about `len` in the [Python documentation](https://docs.python.org/3/library/functions.html#len)

## [**Searching and Dictionaries**](https://cs50.harvard.edu/x/2024/notes/6/#searching-and-dictionaries)

- We can also search within a data structure.
- 
    
    Consider a program called `phonebook.py` as follows:
    
    ```python
    *# Implements linear search for names using loop
    # A list of names*
    names **=** ["Carter", "David", "John"]
    
    *# Ask for name*
    name **=** **input**("Name: ")
    
    *# Search for name*
    for n **in** names:
        if name **==** n:
            **print**("Found")
            break
    else:
        **print**("Not found")
    ```
    
    Notice how this implements linear search for each name.
    
- 
    
    However, we don’t need to iterate through a list. In Python, we can execute linear search as follows:
    
    ```python
    *# Implements linear search for names using `in`
    # A list of names*
    names **=** ["Carter", "David", "John"]
    
    *# Ask for name*
    name **=** **input**("Name: ")
    
    *# Search for name*
    if name **in** names:
        **print**("Found")
    else:
        **print**("Not found")
    ```
    
    Notice how `in` is used to implement linear search.
    
- Still, this code could be improved.
- Recall that a *dictionary* or `dict` is a collection of *key* and *value* pairs.
- 
    
    You can implement a dictionary in Python as follows:
    
    ```python
    *# Implements a phone book as a list of dictionaries, without a variable*
    from cs50 import get_string
    
    people **=** [
        {"name": "Carter", "number": "+1-617-495-1000"},
        {"name": "David", "number": "+1-617-495-1000"},
        {"name": "John", "number": "+1-949-468-2750"},
    ]
    
    *# Search for name*
    name **=** **get_string**("Name: ")
    for person **in** people:
        if person["name"] **==** name:
            **print**(f"Found {person['number']}")
            break
    else:
        **print**("Not found")
    ```
    
    Notice that the dictionary is implemented having both `name` and `number` for each entry.
    
- 
    
    Even better, strictly speaking, we don’t need both a `name` and a `number`. We can simplify this code as follows:
    
    ```python
    *# Implements a phone book using a dictionary*
    from cs50 import get_string
    
    people **=** {
        "Carter": "+1-617-495-1000",
        "David": "+1-617-495-1000",
        "John": "+1-949-468-2750",
    }
    
    *# Search for name*
    name **=** **get_string**("Name: ")
    if name **in** people:
        **print**(f"Number: {people[name]}")
    else:
        **print**("Not found")
    ```
    
    Notice that the dictionary is implemented using curly braces. Then, the statement `if name in people` searches to see if the `name` is in the `people` dictionary. Further, notice how, in the `print` statement, we can index into the people dictionary using the value of `name`. Very useful!
    
- Python has done their best to get to *constant time* using their built-in searches.
- You can learn more about dictionaries in the [Python documentation](https://docs.python.org/3/library/stdtypes.html#dict)

## [**Command-Line Arguments**](https://cs50.harvard.edu/x/2024/notes/6/#command-line-arguments)

- 
    
    As with C, you can also utilize command-line arguments. Consider the following code:
    
    ```python
    *# Prints a command-line argument*
    from sys import argv
    
    if **len**(argv) **==** 2:
        **print**(f"hello, {argv[1]}")
    else:
        **print**("hello, world")
    ```
    
    Notice that `argv[1]` is printed using a *formatted string*, noted by the `f` present in the `print` statement.
    
- 
    
    You can print all the arguments in `argv` as follows:
    
    ```python
    *# Printing command-line arguments, indexing into argv*
    from sys import argv
    
    for i **in** **range**(**len**(argv)):
        **print**(argv[i])
    ```
    
    Notice that the above will not present the word `python` if executed, and the first argument will be the name of the file you are running. You can think of the word `python` as being analogous to `./` when we were running programs in C.
    
- 
    
    You can slice pieces of lists away. Consider the following code:
    
    ```python
    *# Printing command-line arguments*
    from sys import argv
    
    for arg **in** argv:
        **print**(arg)
    ```
    
    Notice that executing this code will result in the name of the file you are running being sliced away.
    
- 
    
    You can learn more about the `sys` library in the [Python documentation](https://docs.python.org/3/library/sys.html)
    

## [**Exit Status**](https://cs50.harvard.edu/x/2024/notes/6/#exit-status)

- 
    
    The `sys` library also has built-in methods. We can use `sys.exit(i)` to exit the program with a specific exit code:
    
    ```python
    *# Exits with explicit value, importing sys*
    import sys
    
    if **len**(sys.argv) **!=** 2:
        **print**("Missing command-line argument")
        sys.**exit**(1)
    
    **print**(f"hello, {sys.argv[1]}")
    sys.**exit**(0)
    ```
    
    Notice that dot-notation is used to utilize the built-in functions of `sys`.
    

## [**Third-Party Libraries**](https://cs50.harvard.edu/x/2024/notes/6/#third-party-libraries)

- One of the advantages of Python is its massive user-base and similarly large number of third-party libraries.
- For example, David demoed the use of `cowsay` and `qrcode` libraries.

## [**Summing Up**](https://cs50.harvard.edu/x/2024/notes/6/#summing-up)

In this lesson, you learned how the building blocks of programming from prior lessons can be implemented within Python. Further, you learned about how Python allowed for more simplified code. Also, you learned how to utilize various Python libraries. In the end, you learned that your skills as a programmer are not limited to a single programming language. Already, you are seeing how you are discovering a new way of learning through this course that could serve you in any programming language – and, perhaps, in nearly any avenue of learning! Specifically, we discussed…

- Python
- Variables
- Conditionals
- Loops
- Types
- Object-Oriented programming
- Truncation and floating point imprecision
- Exceptions
- Dictionaries
- Command-line arguments
- Third-Party libraries

See you next time!

[Python](https://www.notion.so/Python-15060895bd36809bb5c1fc63715f9985?pvs=21)

[Section](https://www.notion.so/Section-15060895bd368061ae20c15441586da6?pvs=21)

[Problem Set 6](https://www.notion.so/Problem-Set-6-15060895bd3680dd9976d5624e0095d5?pvs=21)