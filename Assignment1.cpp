#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

/*Struct that contains the array of 20 char pointers
and the integer array with 20 elements.*/
struct Struct
{
    long int intArray[20];
    char *charPtrs[20];
};

/*This function will initialize the integer array
depending on the size of the */
int recursiveFunction(int i)
{
    if(i == 0)
    {
        return 2700;
    }
    else
    {
        return (2700 * pow(2, i));
    }
}

char letters[26] = { 'A' , 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

/*This function will generate the random letters that
will be used to initialize the elements of the charPtrs array.
A random letter will be selected and returned.*/
char randomLetter()
{
	int randomIndex = rand() % sizeof(letters);
	char randomSelection = letters[randomIndex];

	return randomSelection; //will return a random letter
}

/*The following function will initialize the integer array with values,
 allocate memory to each element in the arrays, and also initialize random
 letters into each element in the charPtrs array.*/
void initArrays(struct Struct &s)
{

    /*The following for loop will pass in values to each array
    element, by calling the recursiveFunction.*/
    for(int i=0; i < 20; i++)

    {
        s.intArray[i] = recursiveFunction(i);
    }

    /*Memory will be allocated to each element in the char arrays
     according to the size of the integer array.*/
    for(int i=0; i < 20; i++)
    {
        s.charPtrs[i] = new(nothrow) char[s.intArray[i]]; //

        /*randomLetter function is called and the elements of the charPtrs
         are initialized with random upper case letters*/
        for(int j=0; j < s.intArray[i]; j++)
        {
            s.charPtrs[i][j] = randomLetter();
        }
    }

}

int main()
{
	Struct s1; //declaring the integer array and the array of char pointers
	initArrays(s1); //passing the integer array and the array of char pointers to be initialized

	int mainMenuChoice = 0;
	int subMenuChoice = 0;
	int arrayIndex = 0;

	cout << "------- MAIN MENU -------" << endl;
	cout << "1. Access a pointer" << endl;
	cout << "2. List deallocated memory (index)" << endl;
	cout << "3. Deallocate all memory" << endl;
	cout << "4. Exit program" << endl;
	cin >> mainMenuChoice;

	while (mainMenuChoice != 4)
	{
		if (mainMenuChoice == 1)
		{
			cout << endl;
			cout << "Which index of the array would you like to access?" << endl;
			cin >> arrayIndex;

			cout << endl;
			cout << "------ SUB MENU ------" << endl;
			cout << "1. Print first 10 chars in the chosen array" << endl;
			cout << "2. Delete all the chars associated with this pointer" << endl;
			cout << "3. Return to Main Menu" << endl;
			cin >> subMenuChoice;

			while (subMenuChoice != 3)
			{
			    /*If loop will only run if the index that has been selected
			    has not been deallocated. If it is not empty the 10 random
			    letters will be printed*/
				if (subMenuChoice == 1)
				{
					if (s1.charPtrs[arrayIndex] != NULL)
					{
						/*The first 10 letters will be printed.*/
						cout << endl;
						cout << "Index being accessed: " << arrayIndex << endl;
						long int arrayLength = s1.intArray[arrayIndex];
						if (arrayLength < 10)
						{
							for (long int i = 0; i < arrayLength; i++)
							{
								cout << s1.charPtrs[arrayIndex][i] << " ";
							}
						}
						else if (arrayLength > 10)
						{
							for (long int i = 0; i < 10; i++)
							{
								cout << s1.charPtrs[arrayIndex][i] << " ";
							}
						}
						cout << endl;
					}
					/*If the selected index has already been deallocated and is empty
					then the user will be notified and the index will be reallocated
					with random letters again.*/
					else if (s1.charPtrs[arrayIndex] == NULL)
					{
						cout << endl;
						cout << "This index has been deallocated and is empty\n";
						cout << endl;
						cout << "Memory will be allocated again\n";

						/*Memory will be reallocated and random letters will be initialized*/
						s1.charPtrs[arrayIndex] = new char[s1.intArray[arrayIndex]];
						for (long int j = 0; j < s1.intArray[arrayIndex]; j++)
						{
							s1.charPtrs[arrayIndex][j] = randomLetter();
						}
						cout << endl;
					}
				}
				else if (subMenuChoice == 2)
				{
					cout << endl;
					cout << "The following index will now be deallocated: " << arrayIndex << endl;
					/*The memory in the index will now be deallocated
					and the pointer will be set to null.*/
					delete s1.charPtrs[arrayIndex];
					s1.charPtrs[arrayIndex] = NULL;
				}

				cout << endl;
				cout << "------- SUB MENU ------"<< endl;
				cout << "1. Print first 10 chars in the chosen array" << endl;
				cout << "2. Delete all the chars associated with this pointer" << endl;
				cout << "3. Return to Main Menu" << endl;
				cin >> subMenuChoice;
			}//end of while loop for SubMenu

		}//end of if statement for choice #1 from Main Menu

		else if (mainMenuChoice == 2)
		{
			cout << endl;
			cout << "These are the following indexes with deallocated memory: "<< endl;

			/*This for loop will display the indexes
			that do not have any allocated memory*/
			for (int i = 0; i < 20; i++)
			{
				if (s1.charPtrs[i] == NULL)
					cout << i << " ";
			}
			cout << endl;
		}//end of else if statement for choice #2 from Main Menu

		else if (mainMenuChoice == 3)
		{
			cout << endl;
			cout << "Memory will be deallocated for all indexes"<< endl;

			/*For loop will go through each pointer
			and deallocate all the memory, leaving
			each one empty*/
			for (int i = 0; i < 20; i++)
			{
				if (s1.charPtrs[i] != NULL)
				{
					delete s1.charPtrs[i];
					s1.charPtrs[i] = NULL;
				}
			}
		}//end of else if statement for choice #3 from Main Menu

		else
		{
			/*If the user decides to quit the program
			all the indexes will be deallocated and the
			program will exit.*/
			for (int i = 0; i < 20; i++)
			{
				if (s1.charPtrs[i] != NULL)
				{
					delete s1.charPtrs[i];
					s1.charPtrs[i] = NULL;
				}
			}
			return 0;
		}//end of else statement for choice #4 from Main Menu

		cout << endl;
		cout << "------ MAIN MENU ------" << endl;
		cout << "1. Access a pointer" << endl;
		cout << "2. List deallocated memory (index)" << endl;
		cout << "3. Deallocate all memory" << endl;
		cout << "4. Exit program" << endl;
		cin >> mainMenuChoice;

	}//end of while loop for MainMenu
	return 0;

}//end of int main
