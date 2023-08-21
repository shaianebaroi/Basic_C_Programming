#include <stdio.h>

struct paratha
{
    int quantity;
    int unitprice;
};

struct vegetable
{
    int quantity;
    int unitprice;
};

struct water
{
    int quantity;
    int unitprice;
};

int main()
{
    
    //FOR PARATHA
    struct paratha p;
 
 	//ENTERING QUANTITY 
 	printf("Quantity of Paratha: ");
    scanf("%d", &p.quantity);
 
 	//ENTERING UNIT PRICE
 	printf("Unit Price: ");
    scanf("%d", &p.unitprice);
    
    //FOR VEGETABLE
    struct vegetable v;
 
 	//ENTERING QUANTITY 
 	printf("Quantity of Vegetable: ");
    scanf("%d", &v.quantity);
 
 	//ENTERING UNIT PRICE
 	printf("Unit Price: ");
    scanf("%d", &v.unitprice);
    
    //FOR MINERAL WATER
    struct water w;
 
 	//ENTERING QUANTITY 
 	printf("Quantity of Mineral Water: ");
    scanf("%d", &w.quantity);
 
 	//ENTERING UNIT PRICE
 	printf("Unit Price: ");
    scanf("%d", &w.unitprice);
    
    //ENTERING THE NUMBER OF PEOPLE
    int people;
    printf("Number of People: ");
    scanf("%d", &people);
    
    float total;
    total = ((p.quantity * p.unitprice) + (v.quantity * v.unitprice) + (w.quantity * w.unitprice));
    
    float each;
    each = total / people;
    printf("Individual people will pay: %f taka \n", each);
    
    
    return 0;
}
