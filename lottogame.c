/*    DT228-1 Programming Assignment #2
        Author: Oscar Mangan - C17486986
        Due Date: March 11th, 11:59pm
        Compiler: Borland
        Program which plays a lotto game in a modular system utilising functions to do so, allowing users
        to input 6 numbers they pick, and letting them do various tasks with this
*/
#include<stdio.h>
#define NUM 6
#define ZERO 0
#define BONUS_num 42

//Prototype
void input(int[]);
void displaynum(int[]);
void bubblesort(int[]);
void compare_Numbers(int[]);
void freq_count(int[], int[]);
int terminate();

int main()
{
    //Declaring variables
    int menu_option;
    int my_lotto [NUM];
    int completion = ZERO;
    int zero_array[BONUS_num] =  {0};
    
    //User menu to select options
    do
    {
    printf("\n\n*Option 1* - Input your 6 numbers");
    printf("\n*Option 2* - Diplay your numbers");
    printf("\n*Option 3* - Sort your numbers in increasing order");
    printf("\n*Option 4* - Check if you won a prize");
    printf("\n*Option 5* - Display the frequency of the numbers entered");
    printf("\n*Option 6* - Exit Program\n\n");
    printf("Enter key 1 to 6 to select option: ");
        
    scanf("%d", &menu_option);
    flushall();
        
        switch(menu_option)
        {
            //Default used to error check answer is between 1 and 6
            default:
                printf("You must choose an input in between 1 and 6\n\n");
            break;
        
            //Option 1 Choosing lotto numbers
            case 1:
                input(my_lotto);
                completion = 1;
            break;
        
            //Option 2 - Displaying chosen numbers.
            case 2:
                if (completion != 1)
                {
                    printf("You must complete option 1 before accessing other parts of the game!");
                }
                else
                {
                displaynum(my_lotto);
                }
            break;
                
            //Option 3 - Sorting the numbers into increasing order
            case 3:
                if (completion != 1)
                {
                    printf("You must complete option 1 before accessing other parts of the game!");
                }
                else
                {
                bubblesort(my_lotto);
                }
            break;

            //Option 4 - Comparing user numbers to winning numbers and checking for prizes
            case 4:
                if (completion != 1)
                {
                    printf("You must complete Option 1 before accessing other parts of the game!");
                }
                else
                {
                compare_Numbers(my_lotto);
                }
            break;

            //Option 4 - Comparing user numbers to winning numbers and checking for prizes
            case 5:
                if (completion != 1)
                {
                    printf("You must complete Option 1 before accessing other parts of the game!");
                }
                else
                {
                freq_count(my_lotto, zero_array);
                }
            break;

            //Option 6 - Exit the program
            case 6:
                menu_option = terminate();
            break;
        }
    }while (menu_option != 6); 
    flushall();
}

/*Option 1, inputting desired lotto numbers. Uses a scanf and pointer notation to assign each input to an element of the array.
It also error checks if the user has input a number outside the range of 1 to 42, or if they have inputted the same number twice.
*/
void input(int mynums[])
{
    int i, j;
    printf("Please input 6 numbers, each number must be different, and in the range of 1 to 42\n\n");
    for (i = ZERO; i < NUM; i++)
    {
        scanf("%d", & *(mynums + i));
        for (j = ZERO; j < i; j++)
        {
            //Error checking for if the number has already been entered before
            if(*(mynums + j) == (*(mynums + i)))
            {
                printf("Number already entered\n");
                //allows the user to retry that specific element, instead of having to input the entire array again
                i--;
            }
        }
        //Error checking if the number is outside the range specified
        if (*(mynums + i) < 1 || *(mynums + i) > 42)
        {
            printf("Number is out of range\n\n");
        i--;
        }
    }
}//end function 1

/*Option 2 function, displaying the current numbers selected. By using a for loop to go through each element of the array 
and print each element. This is unsorted at first, but after 3, is sorted.
*/
void displaynum(int myarray[])
{
    int i;
    printf("The numbers you have selected are: ");
    for (i = ZERO; i < NUM; i++)
    {
        printf("%d ", *(myarray + i));
    }
}

/*Option 3 function, sorting the array in increasing order. This function declares to indexs, and uses 
the bubble sort algorithm to sort the elements of the array in increasing. Notifies the user that their
numbers have been sorted and returns to the menu
*/
void bubblesort(int unsorted_array[])
{
    //each index is used for each individual loop within the Bubble Sort algorithm
    int x, y;

    //First 'for' loop to go through each element of the array
    for(x = ZERO; x < NUM; x++)
    {
        //Second for loop to compare each element and sort accordingly
        for(y = ZERO; y < NUM - 1; y++)
        {
            if(*(unsorted_array + y) > *(unsorted_array + y + 1))
            {
                //using temp to calculate and sort
                int temp = *(unsorted_array + y + 1);
                *(unsorted_array + y + 1) = *(unsorted_array + y);
                *(unsorted_array + y) = temp;
            }
        }
    }
    printf("Your numbers have now been sorted!\n");
}//end function 3

/*Option 4 function, checks the users numbers against the winning numbers that have been selected. It uses two for loops similar to the Bubble Sort algorithm
by taking elements from each array and seeing if they match accordingly. Using a switch statement, it checks to see if the user has won a prize, and tells them 
which prize they have won.
*/
void compare_Numbers(int user_array[])
{
    int i, j;
    int winning_num[NUM] = {1,3,5,7,9,11};
    int match_score = ZERO;
    int bonus_check;

    //First 'for' loop checks the elements from the users inputted numbers/array.
    for(i = 0; i < NUM; i++)
    {
        for(j = ZERO; j < NUM; j++)
        {
            if(*(user_array + i) == *(winning_num + j))
            {
                match_score = match_score + 1;
            }
            
            if(*(user_array + i) == BONUS_num)
            {
                bonus_check = 1;
            }
        }
    }

    //Switch statement to check for prizes / jackpot won
    switch(match_score)
    {   
        //default is used as a standard answer for if the user won nothing.
        default:
            printf("You did not win anything");
        break;
        
        //Cases are used to check how many numbers they matched against the winning numbers
        case 3:
            //If statement checks if the user had the bonus number
            if(bonus_check == 1)
            {
                printf("Congratulations, you won a cinema ticket!");
            }
            else
            {
                printf("You did not win anything");
            }
        break;
        case 4:
            if(bonus_check == 1)
            {
                printf("Congratulations, you won a weekend away!");
            }
            else
            {
                printf("Congratulations, you won a night out!");
            }
        break;
        case 5:
            if(bonus_check == 1)
            {
                printf("Congratulations, you won a new car!");
            }
            else
            {
                printf("Congratulations, you won a holiday!");
            }
        break;
        case 6:
                printf("Congratulations, you won the jackpot!");
        break;
    }//end switch
}//end function 4
    
/*Option 5,  this function uses two arrays, and checks the users inputted numbers with one of them. It then goes to the matching element of the second array, and increments the value of that
element by 1 each time the number has appeared in the users inputs.
*/
void freq_count(int array[], int range_zero[])
{
    //Array which acts as the range of possible values the user could have chosen, with 2 indexes for use in the for loops
    int lotto_range[BONUS_num] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42};
    int temp1 = ZERO;
    int temp2 = ZERO;
    
    for(temp1 = ZERO; temp1 < NUM; temp1++)
    {
        //For loop to check the users inputted numbers against the range of values 1 to 42 in the possible numbers to be selected.
        for(temp2 = ZERO; temp2 < BONUS_num; temp2++)
        {
            //If statement checking if the element of the 42 element range matches the current element of the users inputted array
            if(*(lotto_range + temp2) == (*(array + temp1)))
            {
                //Incrementing the value of this element by 1, this acts as a counter in the program.
                *(range_zero + temp2) = *(range_zero + temp2) + 1;
            }
        }
    }//end for
    //For loop to run through the array where it checks to see the element of the array full of 0's, and sees where there is a value higher than 0, what that value is
    for(temp1 = ZERO; temp1 < BONUS_num; temp1++)
    {
        //If the value of this element is not greater than 0, it is ignored, only displaying which numbers have been entered at least once.
        if(*(range_zero + temp1) > 0)
        {   
            //Displays which number appeared how many times each number appeared
            printf("%d appeared %d times\n", *(lotto_range + temp1), *(range_zero + temp1));
        }
    }
}//end of function 6

/*Option 6 function, to exit the program. The function also asks the user to confirm if they would like to exit
the program using an if statement and Y/N for the answer given.
*/
int terminate()
{
    //char used for Y and N or y and n.
    char confirm;
    printf("Are you sure you want to exit? Press 'Y' to exit, or Press 'N' to stay.\n\n");
    scanf("%s", &confirm);
    if (confirm == 'Y' || confirm == 'y')
    {
        return 6;
    }
    else
    {
        return 0;
    }
}// end function 6