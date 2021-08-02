#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM_PRODUCTS 20
#define MAX_PRODUCT_NAME_LENGTH 20
#define MAX_CATEGORY_LENGTH 10
#define BARCODE_LENGTH 12

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * main_interface = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"\
"Welcome to CORONA market!\n"\
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"\
"Manage market menu :\n"\
"	1. Add product\n"\
"	2. Remove product\n"\
"	3. Check which products are expired\n"\
"	4. Print all the products\n"\
"	5. Update product\n"\
"	6. EXIT SYSTEM\n"\
"Please choose operation[1-6]:";

//operation 1 constant strings

const char *  adding_product_barcode = "Please enter product barcode:";
const char * barcode_already_exist = "This product already exist, please enter the number of products to add:";
const char * too_much_products = "Can't add more products, not enough space";
const char * adding_product_name = "Please enter product name:";
const char * adding_product_category = "Please enter product category:";
const char * adding_product_number = "Please enter number of products to add:";
const char * adding_product_price = "Please enter the price of the product:";
const char * adding_product_date = "Please enter expiration date of the product[dd/mm/yy]:";

//operation 2 constant strings
const char * store_empty = "The store is empty!";
const char * delete_barcode = "Please enter product barcode you want to delete:";
const char * delete_barcode_cant_find = "Couldn't find the product barcode, try again...";
const char * delete_barcode_succeed = "The product deleted successfully!";


//operation 3 constant strings
const char * expired_date_check = "What date you want to check[dd/mm/yy]:";
const char * expired_products = "~~~~~~~~~~~~~~~Expired Products~~~~~~~~~~~~~~~\n";
const char * expired_product_name = "Product name: ";
const char * expired_product_barcode = "Product barcode: ";
const char * expired_product_date = "Product expiration date: ";


//operation 4 constant strings
const char * print_products_head = "~~~~~~~~~~~~~~~All Products~~~~~~~~~~~~~~~\n";
const char * print_no_products = "No products in the store!\n";
const char * print_products = "----------";
const char * print_product_name = "Product name: ";
const char * print_product_barcode = "Product barcode: ";
const char * print_product_category = "Product category: ";
const char * print_product_number = "Product available quantity: ";
const char * print_product_price = "Product price: ";
const char * print_product_expireDate = "Product expiration date: ";
const char * print_total_number = "Total number of products: ";

//operation 5 constant strings
const char * update_barcode = "Please enter product barcode you want to update:";
const char * update_barcode_notFound = "Couldn't find the product barcode, try again...";
const char * update_interface_string = ("What do you want to update?\n"\
	"	1. Product name\n"\
	"	2. Product category\n"\
	"	3. Product quantity\n"\
	"	4. Product price\n"\
	"	5. Product expiration date\n"\
	"Please choose operation [1-5]:");
const char * update_product_name = "Please enter new product name:";
const char * update_product_category = "Please enter new product category:";
const char * update_product_number = "Please enter new product quantity:";
const char * update_product_price = "Please enter new product price:";
const char * update_product_date = "Please enter new product expiration date[dd/mm/yy]:";

//operation 6 constant strings
const char * exitProgram = "exit...";


typedef struct date {
	int year, month, day;
} date;

typedef struct product {
	char* product_name;
	char* product_category;
	char* barcode;
	int available;
	double price;
	date* expire_date;
} Product;

typedef struct super_market {
	Product** product_list;
	int number_of_products;
} Super_market;

// General
//*Input:None, Return parameter: None, Function functionality: printing menu ;-)*/ 
void print_menu() 
{
	printf("%s", main_interface);
}

//*Input:None, Return parameter: int, Function functionality:getiing the user choice*/
int get_option() { 
	int option;
	scanf_s("%d", &option);
	return option;
}

//operation 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*Input:the product list(of product pointers) from the super, barcode str , copy of num of products from super. 
Return parameter: int, 
Function functionality:checks if the bacode exists in the system, if exists return 0 and updating the num of the product, 1 if not */
int check_if_product_in_market(Product** product_list, char* barcode, int number_of_products)

{
	int i = 0, num_product_to_add = 0;

	for (i = 0; i < number_of_products; i++)
	{
		if (product_list[i] != NULL)
		{
			if (strcmp(barcode, product_list[i]->barcode) == 0) // if the barcode is already in the sys 
			{
				printf("%s ", barcode_already_exist);
				scanf("%d", &num_product_to_add); //updating the num of the product
				product_list[i]->available += num_product_to_add;
				printf("Additional %d products of %s added\n", num_product_to_add, product_list[i]->product_name);
				return 0;
			}
		}
	}
	return 1; //if the barcode is not in the system
}

/*Input: pointer to the supermarket we created, pointer to the product, barcode of product.
Return parameter: None.
Function functionality:adds a new product, with all its elements, entered by the user to the supermarket we built. */

void add_product(Super_market* super_market, Product* product, char* barcode)
{
	char product_name[MAX_PRODUCT_NAME_LENGTH], product_category[MAX_CATEGORY_LENGTH], str_price[20];
	int num_of_products, day, month, year;
	double price;

	strcpy(product->barcode, barcode);

	printf("%s", adding_product_name);
	scanf("\n%[^\n]s", product_name);
	strcpy(product->product_name, product_name);

	printf("%s", adding_product_category);
	scanf("\n%[^\n]s", product_category);
	strcpy(product->product_category, product_category);

	printf("%s", adding_product_number);
	scanf("%d", &product->available);

	printf("%s", adding_product_price);
	scanf("%lf", &product->price);

	printf("%s", adding_product_date);
	scanf("%d/%d/%d", &product->expire_date->day, &product->expire_date->month, &product->expire_date->year);

	super_market->product_list[super_market->number_of_products] = product;
	super_market->number_of_products++;
	printf("The product %s -barcode:%s ,added successfully\n", product_name, barcode);
}
/*Input: None.
Return parameter: pointer to a Product.
Function functionality: returns a pointer to a product and allocate mem to the fields */
Product* make_product()
{
	Product* product = malloc(sizeof(Product));
	if (NULL == product) {
		printf("Fatal error: memory allocation failed!\n");
		return NULL;
	}
	product->barcode = malloc(BARCODE_LENGTH + 1);
	if (NULL == product->barcode) {
		free(product);
		printf("Fatal error: memory allocation failed!\n");
		return NULL;
	}
	product->product_name = malloc(MAX_PRODUCT_NAME_LENGTH + 1);
	if (NULL == product->product_name) {
		free(product->barcode);
		free(product);
		printf("Fatal error: memory allocation failed!\n");
		return NULL;
	}
	product->product_category = malloc(MAX_CATEGORY_LENGTH + 1);
	if (NULL == product->product_category) {
		free(product->barcode);
		free(product->product_name);
		free(product);
		printf("Fatal error: memory allocation failed!\n");
		return NULL;
	}
	product->expire_date = malloc(sizeof(date));
	if (NULL == product->expire_date) {
		free(product->barcode);
		free(product->product_name);
		free(product->product_category);
		free(product);
		printf("Fatal error: memory allocation failed!\n");
		return NULL;
	}
	return product;
}

//operation 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*Input: the list of products in the supermarket, the index of the wanted product in the list.
Return parameter: None.
Function functionality: frees all fields' allocated memory of the wanted product including itself  */

void free_func(Product** product_list, int i)// a function to free memory
{
	free(product_list[i]->barcode);
	free(product_list[i]->product_name);
	free(product_list[i]->product_category);
	free(product_list[i]->expire_date);
	free(*(product_list + i));
}
/*Input: the list of products in the supermarket, pointer to the number of products currently in the supermarket.
Return parameter: None.
Function functionality: removing the wanted product with the specific barcode whilst freeing all related memory,
followed by changing the list's memory size */

void remove_product(Product** product_list, int* number_of_products) {
	int i, j, index = 1;
	char barcode_to_del[BARCODE_LENGTH];

	if (*number_of_products == 0)
	{
		printf("%s \n", store_empty);
		return;
	}
	do
	{
		printf("%s", delete_barcode);// here we ask to put in the barcode we would like to remove.
		scanf("\n%[^\n]s", barcode_to_del);
		for (i = 0; i < *number_of_products; i++)
		{
			if (product_list[i] != NULL)
			{
				if (strcmp(barcode_to_del, product_list[i]->barcode) == 0) // if the product is in the system.
				{
					free_func(product_list, i);
					for (i, j = i + 1; j < *number_of_products; i++, j++)
					{
						product_list[i] = product_list[j];
					}
					*number_of_products = *number_of_products - 1;
					if (*number_of_products > 0)
					{
						product_list = realloc(product_list, sizeof(Product*) * (*number_of_products));
						if(product_list == NULL)
						{
							printf("Fatal error: memory allocation failed!\n");
							return;
						}
					} 
					else
					{
						product_list = NULL;
					}
					printf("%s\n", delete_barcode_succeed);
					return;
				}
			}
		}
		printf("%s\n", delete_barcode_cant_find);
	} while (index);// a loop to return itself until the user enters a barcode that's in the system
}

//operation 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*Input: the list of products in the supermarket, pointer to the number of products currently in the supermarket.
Return parameter: None.
Function functionality: prints all product with expire dates smaller than the date put by the user  */
void check_which_product_expired(Product** product_list, int* number_of_products) {
	int expire_day, expire_month, expire_year;
	int i;

	printf("%s", expired_date_check);
	scanf("%d/%d/%d", &expire_day, &expire_month, &expire_year);
	printf("%s", expired_products); // headline of expired products and then we print them.

	for (i = 0; i < *number_of_products; i++) 
	{
		if (product_list[i]->expire_date->year <= expire_year) 
		{
			if (product_list[i]->expire_date->month <= expire_month) 
			{
				if (product_list[i]->expire_date->day < expire_day)
				{
					printf("%s%s\n", expired_product_name, product_list[i]->product_name);
					printf("%s%s\n", expired_product_barcode, product_list[i]->barcode);
					printf("%s%d/%d/%d\n", expired_product_date, product_list[i]->expire_date->day, product_list[i]->expire_date->month, product_list[i]->expire_date->year);

				}
			}
		}
	}
}

//operation 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*Input: the list of products in the supermarket, pointer to the number of products currently in the supermarket.
Return parameter: None.
Function functionality: prints all product currently in the supermarket  */
void print_all_the_products(Product** product_list, int* number_of_products) {
	int i;
	double price;
	if (*number_of_products == 0)
	{
		printf("%s", print_no_products);
		return;
	}
	printf("~~~~~~~~~~~~~~~All Products~~~~~~~~~~~~~~~\n");
	for (i = 0; i < *number_of_products; i++)
	{
		printf("%s\n", print_products);
		printf("%s%s\n", print_product_name, product_list[i]->product_name);
		printf("%s%s\n", print_product_barcode, product_list[i]->barcode);
		printf("%s%s\n", print_product_category, product_list[i]->product_category);
		printf("%s%d\n", print_product_number, product_list[i]->available);
		printf("%s%g\n", print_product_price, product_list[i]->price);
		printf("%s%d/%d/%d\n", print_product_expireDate, product_list[i]->expire_date->day, product_list[i]->expire_date->month, product_list[i]->expire_date->year);
	}
	printf("%s%d\n", print_total_number, *number_of_products);
}

//operation 5 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*Input: the list of products in the supermarket, pointer to the number of products currently in the supermarket.
Return parameter: None.
Function functionality: lets the user decide which product to update by entering a barcode, 
then choosing the field in the product struct to update  */
void update_product(Product** product_list, int* number_of_products) {
	int option, new_number;
	int i, index;
	char barcode[BARCODE_LENGTH];

	if (*number_of_products == 0)
	{
		printf("%s", print_no_products);
		return;
	}

	printf("%s", update_barcode);
	scanf("\n%[^\n]s", &barcode);

	for (i = 0; i < *number_of_products; i++) 
	{
		if (strcmp(barcode, product_list[i]->barcode) == 0) 
		{
			printf("%s", update_interface_string);
			scanf("%d", &option);
			switch (option) {
			case 1:
				printf("%s", update_product_name);
				scanf("\n%[^\n]s", product_list[i]->product_name);
				return;

			case 2:
				printf("%s", update_product_category);
				scanf("\n%[^\n]s", product_list[i]->product_category);
				return;
			case 3:
				printf("%s", update_product_number);
				scanf("%d", &product_list[i]->available);
				return;
			case 4:
				printf("%s", update_product_price);
				scanf("%lf", &product_list[i]->price);
				return;
			case 5:
				printf("%s", update_product_date);
				scanf("%d/%d/%d", &product_list[i]->expire_date->day, &product_list[i]->expire_date->month, &product_list[i]->expire_date->year);
				return;
			}
		}
	}
	printf("%s\n", update_barcode_notFound);
	update_product(product_list, number_of_products);
}

//operation 6 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*Input: the list of products in the supermarket, pointer to the number of products currently in the supermarket.
Return parameter: None.
Function functionality: frees all memory allocated since starting to run the program until this moment.  */
void exit_system(Product** product_list, int* number_of_products)
{
	int i;
	for (i = 0; i < *number_of_products; i++)
	{
		free_func(product_list, i);
	}
	free(product_list);
	printf("%s", exitProgram);
	exit(0);
}

int main()
{
	int option;
	char barcode[BARCODE_LENGTH];
	Super_market supersal = {NULL, 0};
	Product* ptr;

	do
	{
		print_menu();
		option = get_option();
		while (option < 1 || option >6)
		{
			printf("Invalid option was chosen!!!\n");
			print_menu();
			option = get_option(); // Getting input
		}
		switch (option)
		{
			case 1: // Adding new product to the super_market
				printf("%s", adding_product_barcode);
				scanf("\n%[^\n]s", barcode);
				if (supersal.number_of_products < MAX_NUM_PRODUCTS)
				{

					if (check_if_product_in_market(supersal.product_list, barcode, supersal.number_of_products))// the fun return 1 if product not found, 0 if found
					{
						if (supersal.number_of_products == 0)
						{
							supersal.product_list = malloc(sizeof(Product*)); 
							if (supersal.product_list == NULL)
							{
								printf("Fatal error: memory allocation failed!\n");
								break; // break and to back to the loop
							}
						}
						else
						{
							supersal.product_list = realloc(supersal.product_list, sizeof(Product*) * (supersal.number_of_products + 1));
							if (supersal.product_list == NULL)
							{
								printf("Fatal error: memory allocation failed!\n");
								break; // break and to back to the loop
							}
						}
						ptr = make_product(); // pointer to new product 
						if(ptr == NULL) break; // break and to back to the loop
						add_product(&supersal, ptr, barcode);
					}
				}
				else
				{
					if (check_if_product_in_market(supersal.product_list, barcode, supersal.number_of_products)) /* if you have the maxnum of products then you check if the product
																												 exists if yes then update the num of product avilable if not then 
																												 print there is no room*/
					{
						printf("%s\n", too_much_products);
					}
				}
				break;
			case 2:
				remove_product(supersal.product_list, &supersal.number_of_products);
				break;
			case 3:
				check_which_product_expired(supersal.product_list, &supersal.number_of_products);
				break;
			case 4:
				print_all_the_products(supersal.product_list, &supersal.number_of_products);
				break;
			case 5:
				update_product(supersal.product_list, &supersal.number_of_products);
				break;
			case 6:
				exit_system(supersal.product_list, &supersal.number_of_products);
		}
	} while (option != 6);

	return 0;
}

