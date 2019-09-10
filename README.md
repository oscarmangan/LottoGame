# C Lotto Game

This game is a C language game I made in early 2018. A project I made as part of our C programming tuition. Although simple, and using
solely the command line window as an interface, it was fun to make and I was pleased with the result.

### How it works

The winning numbers are set to be 1,3,5,7,9,11. A bonus number of 42 is also included. The game gives the user 6 options with a menu
based interface through the use of functions being called in a switch statement.

Option 1 calls a function which allows the user to input their own numbers into the system. These numbers are saved into an array and 
error checked to make sure the no number is repeated and that the number falls in the range of 1 to 42. If the user enters the same
number twice or a number outside the range, it will prompt the user to try again. Option 1 also must be completed before Options 2-5 are
allowed to be performed.

Option 2 displays the numbers that user entered in Option 1, very simple

Option 3 sorts the numbers in ascending order. For this, I implemented a Bubble Sort algorithm as it's very simple, easy to understand, 
and because the list has only 6 elements, it's efficient. If the list had more elements, I might have chosen Quick Sort or something else.

Option 4 compares the users numbers against the winning numbers and bonus numbers. This is done using for loops and switch statements and
will tell the user what kind of prize they won, or if they didn't win anything.

Option 5 will display to the user how many times a number was selected each time a user enters a new set of numbers without exiting the
program. 

Option 6 if pressed will close the program, but not before asking the user are they sure they want to close it? With a Y or N option. The
switch statement menu is inside a while loop, where if exit function returns a six, it closes the program.

### Conclusion

Please try it! It was fun to make, and I particularly enjoyed being able to implement a sorting algorithm into the program, along with 
coding the rest of the game.
