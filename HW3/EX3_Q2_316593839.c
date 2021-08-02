#include <stdio.h>
#include <ctype.h>
#define STRING_SIZE 150

int get_number_of_words(char input_string[]) 
{
    int counter = 0, i = 0, j = 1;
	for(i = 0, j = 1; input_string[j] != '\0' ; i++, j++)
	{
        int var1 = input_string[i], var2 = input_string[j];
		//Counting the words that followed by space 
        if (isalnum(var1) && !(isalnum(var2))) counter++;
	}
	// Counting only the last words before the end of the str
	if (isalnum(input_string[i])&& !isalnum(input_string[j])) counter++;
    return counter;
}

int main()
{
    char input_str[STRING_SIZE +1];
    int counter = 0;

    printf("Enter the string:\n");
	
    // Read the string from the user
    fgets(input_str, STRING_SIZE+1, stdin);
	
    printf("Number of words in given string are: %d\n", get_number_of_words(input_str));

    return 0;
}