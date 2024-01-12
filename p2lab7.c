#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ProductDescription{

    char productName [25];
    float productPrice;
    float productWeight;

} Product;

// This function uses dynamic memory allocation to allocate enough memory to store the product list (array of products)
void CreateproductList(Product **productList, int size){// double pointer is needed as it points to an array of arrays

    *productList = (Product*) malloc (sizeof(Product)* size); // allocating using malloc

}

// This function uses dynamic memory allocation to resize an existing product list (e.g. increase the size or decrease the size)
void ResizeproductList(Product **productList, int newSize){

   *productList = (Product*) realloc(*productList, sizeof(Product)*newSize);
   printf("\nResized product list\n");
}

// This function allows the user to set the data for a single product It creates a variable of type product and allow the user to set the data for this product
Product SetProductInfo(){
    Product product;

    printf("\nPlease Enter the Product Name: ");
    scanf(" %[^\n]s", product.productName);

    printf("\nPlease Enter the Product Price: ");
    scanf(" %f", &product.productPrice);

    printf("\nPlease Enter the Product Weight: ");
    scanf(" %f", &product.productWeight);

    return product;

}

//This function allows the user to sort the product list based on a sort option; the sort option could be the product name, price, or weight.
void SortproductList(Product *productList, int size, char sortOption){

int i,j;
Product temp;

for (i = 0; i < size-1; i++){

	for (j = i+1; j < size; j++){

		if(sortOption == 'n'){

			if ( strcmp(productList[i].productName,productList[j].productName)> 0){

				temp = productList[i];

				productList[i] = productList[j];

				productList[j] = temp;

			}
		}

		if(sortOption == 'p'){

			if (productList[i].productPrice > productList[j].productPrice){

				temp = productList[i];

				productList[i] = productList[j];

				productList[j] = temp;

			}
		}

		if(sortOption == 'w'){

			if (productList[i].productWeight>productList[j].productWeight){

				temp = productList[i];

				productList[i] = productList[j];

				productList[j] = temp;

			}

		}

	}

}
}

//This function allows the user to create the product list
void AddProductToproductList(Product *productList, int size){

    for(int i=0; i< size; i++){

        printf("\nPlease enter product info for product %d: \n", i);
        *(productList+i) = SetProductInfo();
    }

}

//This function print on the screen the product list
void PrintproductList(Product *productList, int size){

    for(int i = 0; i < size; i++){

       printf("\n Product ID: %d Name:  %s", i, (productList+i)->productName);
       printf("\n Product ID: %d Price: %f", i, (productList+i)->productPrice);
       printf("\n Product ID: %d Weight: %f", i, (productList+i)->productWeight);
       printf("\n----------------------------------------------------------------\n");
    }

}

int main() {

    printf("\n");

    Product *list;

    int listSize;
    char sortOption;
    char resize;

    printf("Please Enter the size of the list: ");
    scanf("%d", &listSize);

    CreateproductList(&list, listSize );

    AddProductToproductList(list, listSize);

    PrintproductList(list, listSize);

    printf("\n\nTo sort the product list press: \n'p' to sort by price, or 'w' to sort by weight, or 'n' to sort by name  : ");

    scanf(" %c", &sortOption);

    SortproductList(list,listSize, sortOption);

    PrintproductList(list,listSize);
	
    printf("\n\nTo resize the product list press 'y' or any other key to escape: ");
    scanf(" %c", &resize);

    if(resize == 'y' || resize == 'Y'){
        printf("Please Enter the new size of the list: ");
        scanf("%d", &listSize);
        ResizeproductList(&list, listSize);
        PrintproductList(list, listSize);
    }




    return 0;
}