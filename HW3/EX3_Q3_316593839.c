#include <stdio.h>
#define STRING_SIZE 5

void read_str(char arr[])
{
    int a;
    fgets(arr, STRING_SIZE +1, stdin); // Getting input
    fseek(stdin, 0, SEEK_END); // Cleaning the extra chars over the cap
}

int str_len(char arr[]) // Len of given array
{
    int len = 0;
    for (len = 0; arr[len] != '\n' && arr[len] != '\0'; len++);
	return len;
}


int first_id_diff_str(char arr1[],char arr2[], int len1,int len2) // Finds the first index of substring in main if there is any.
{
    int i, j = 0;

    if (len2 == 0) return -1;
	for (i = 0; i < len1; i++)
	{
        if (len2 == j) return (i - j);
        if (arr1[i] == arr2[j]) j++;
        else j = 0;
	}
    if (len2 == j) return (i - j); // For the case the substring is in the end
    return -1; // Return -1 if can't found the substring
}

void str_remove(int id, char str1[], char result_string[], int len1, int len2)
{
    int i, j;
    for (i = 0; i < id; i++) result_string[i] = str1[i]; // Copy the chars until id
	for (j = id, i = id + len2; i < len1; i++, j++) result_string[j] = str1[i]; // Copy the chars after end of substring
    result_string[j] = '\0';
	
    for (i = 0; i < j+1; i++) str1[i] = result_string[i];
}


int main() {
    char result_string[STRING_SIZE];
    char str1[STRING_SIZE+1];
    char str2[STRING_SIZE+1];
    int id;

	
    printf("Please enter the main string..\n");
    // Your function call here..
    read_str(str1);
    printf("Please enter the pattern string to find..\n");
    // Your function call here..
    read_str(str2);

    int len1 = str_len(str1);
    int len2 = str_len(str2);
    do
    {
    	id = first_id_diff_str(str1, str2, len1, len2);
        if(id != -1) str_remove(id, str1, result_string, len1, len2);
    } while (id != -1);
	
	

	
    int is_stripped = 0; // Your function call here..
    // Store the result in the result_string if it exists
    if (len1 != str_len(str1)) is_stripped = 1;

	printf("> ");
    printf(is_stripped ? result_string : "Cannot find the pattern in the string!");
    return 0;
}