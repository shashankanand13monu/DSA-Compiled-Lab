
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stklink.c"
#include "intopo.c"
#include "crtstack.c"
#include "hi.c"
#include "lnklst.c"
#define MAX_SIZE 100
int input();
void output(float);

void Tsearch(int a[],int x)
{
    int i;
    int z=x;
    int count=0;
    while(1)
    {
        for(i=0;i<5;i++)
        {
            if(a[i]==z)
            {
                z=z*3;
                count=0;
                break;
            }
            else
            {
                count =1;
            }
            
        }
        if(count==1)
        break;
        else
        i=0;
    }
    
    printf("%d is present -> %d is not present",x,z);
}

int LSsearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int BSbinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return BSbinarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return BSbinarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int elmntSrch(int arr[], int size, int x) {
    int rec;
 
    size--;
 
    if (size >= 0) {
        if (arr[size] == x)
            return size;
        else
            rec = elmntSrch(arr, size, x);
    }
    else
        return -1;
 
    return rec;
}

int findElement(int arr[], int n){

    
    int count = 1, max_ele = -1, temp = arr[0], ele, f=0;
     
    for(int i=1;i<n;i++)
    {

        if(temp==arr[i])
        {
            count++;
        }
        else
        {
            count = 1;
            temp = arr[i];
        }
        
        if(max_ele<count)
        {
            max_ele = count;
            ele = arr[i];
             
            if(max_ele>=(n/2))
            {
                f = 1;
                break;
            }
        }
    }
    return (f==1 ? ele : -1);
}

int main()
{
	float result;
	int choice, num,ch;
	hi();
    while (1)
    {
        /* code */
    
    
	printf("Press 1 For Array\n");
    printf("Press 2 For Linked List\n");
    printf("Press 3 For Stacks\n");
    printf("Press 4 For Searching\n");
    printf("Press 5 For Others\n");
    printf("Press 6 To Exit\n");
    printf("Enter your choice:\n");
    ch = input();
    
	switch (ch) {
	    case 1: {
	printf("Press 1 to find out the smallest and largest element stored in an array of n integers.\n");
	printf("Press 2 to reverse the contents of an array of n elements.\n");
	printf("Press 3 to search an element in an array of n numbers.\n");
	printf("Press 4 to exchange the biggest and smallest element into the array of n integers.\n");
	printf("Press 5 to Segregate 0s on left side and 1s on right side of the array. \n");
	printf("Press 6 to find and display the number of elements between two elements a and b (both inclusive).\n");
	printf("Press 7 to find out the kth smallest and kth largest element stored in a dynamic array of n integers \n");
	printf("Press 8 to find out the smallest and largest element stored in an array of n integers.\n");
    printf("Enter your choice:\n");
	choice = input();
	
	switch (choice) {
	case 1: {
		int a[50],i,n,large,small;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("\nInput the array elements : ");
    for(i=0;i<n;++i)
    scanf("%d",&a[i]);

    large=small=a[0];

    for(i=1;i<n;++i)
    {
    if(a[i]>large)
    large=a[i];

    if(a[i]<small)
    small=a[i];
    }

    printf("\nThe smallest element is %d\n",small);
    printf("\nThe largest element is %d\n",large);
		break;
	}
	case 2: {
		    int n;
		    printf("Enter Size : ");
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i = 0; i < n; i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("Reversed array is:\n");
    for(i = n-1; i >= 0; i--)
    {
    printf("%d\n",arr[i]);
    }
		break;
	}
	case 3: {
		int arr[MAX_SIZE];
    int size, i, toSearch, found;

    /* Input size of array */
    printf("Enter size of array: ");
    scanf("%d", &size);

    /* Input elements of array */
    printf("Enter elements in array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &toSearch);

    /* Assume that element does not exists in array */
    found = 0; 
    
    for(i=0; i<size; i++)
    {
        /* 
         * If element is found in array then raise found flag
         * and terminate from loop.
         */
        if(arr[i] == toSearch)
        {
            found = 1;
            break;
        }
    }

    /*
     * If element is not found in array
     */
    if(found == 1)
    {
        printf("\n%d is found at position %d", toSearch, i + 1);
    }
    else
    {
        printf("\n%d is not found in the array", toSearch);
    }
		break;
	}
	case 4:{
	    int n,max,min,large,small,i,temp,a[68];
	
	printf("Enter number of elements\n");
    scanf("%d", &n);
 
    printf("Enter %d the values \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
	max=a[0];
	min=a[0];
	large=0;
	small=0;
	for(i=1;i<5;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			large=i;
		}
		if(a[i]<min)
		{
			min=a[i];
			small=i;
		}
	}
	temp=a[large];
	a[large]=a[small];
	a[small]=temp;
	printf("After interchange array elements are: ");
	for(i=0;i<5;i++)
	{
	    	printf("%d ",a[i]);
	}
	break;
	}
	
	case 5:{
	    int arr[] = { 0, 1, 0, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0; // Counts the no of zeros in arr
 
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count++;
    }
 
    // Loop fills the arr with 0 until count
    for (int i = 0; i < count; i++)
        arr[i] = 0;
 
    // Loop fills remaining arr space with 1
    for (int i = count; i < n; i++)
        arr[i] = 1;
        
        for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
        
        break;
	}
	
	case 6:{
	    int arr1[] = { 1, 2, 2, 7, 5, 4 };
    size_t n = sizeof( arr1 ) / sizeof( *arr1 );
    
    int a = 2, b = 5;
    
    size_t count = 0;
    int lower_limit = 0, upper_limit = 0;
    
    for ( size_t i = 0; i < n; i++ )
    {
        if ( a <= arr1[i] && arr1[i] <= b )
        {
            ++count;
            lower_limit |= arr1[i] == a;
            upper_limit |= arr1[i] == b;
        }
    }
    
    count += !lower_limit + !upper_limit;
    
    printf( "Number of elements between %d and %d is %zu\nv", a, b, count );
    
    a = 6; b = 15;
    
    count = 0;
    lower_limit = 0; upper_limit = 0;
    
    for ( size_t i = 0; i < n; i++ )
    {
        if ( a <= arr1[i] && arr1[i] <= b )
        {
            ++count;
            lower_limit |= arr1[i] == a;
            upper_limit |= arr1[i] == b;
        }
    }
    
    count += !lower_limit + !upper_limit;
    
    printf( "Number of elements between %d and %d is %zu\n", a, b, count );
    break;
	}
	
	case 7: {
	    
	    int n;
    printf("Enter No. of  element\n");
    scanf("%d",&n);

int arr[n];
 printf("Enter each element\n");
for( int i = 0 ; i<n ; i++)
{
    scanf("%d",&arr[i]);
}
int k;
printf("Enter Value of  K\n");
scanf("%d",&k);

for (int i= 0; i < (n-1); i++) { 
    for (int j = 0; j < n - i-1; j++) { 
      if (arr[j] > arr[j + 1]) {

        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  
printf("%d th smallest is %d\n %d th largest element is ",k,arr[k-1],arr[n-k]);

	    break;
	}
	
    case 8:
    {
       int a[50],i,n,l,s;
printf("\nEnter the number of elements : ");
scanf("%d",&n);
printf("\nInput the array elements : ");
for(i=0;i<n;++i){

scanf("%d",&a[i]);
l=s=a[0];
}

for(i=1;i<n;++i)
{
if(a[i]>l)
l=a[i];

if(a[i]<s)
s=a[i];
}

printf("\nThe smallest element is %d\n",s);
printf("\nThe largest element is %d\n",l);
        break;
    }
	default:
		printf("wrong Input\n");
	}
	return 0;

break;
}


	
    case 2:
    {
     lnklst();
    break;
    }

    case 3:
    {
    
    printf("Press 1 to Create Stack Using  Array \n");
    printf("Press 2 to Create Stack Using Linked List\n");
    printf("Press 3 to reverse a stack\n");
    printf("Press 4 to Converst Infinix Expression to Postfix Expression\n");
    printf("Enter your choice:\n");
    choice = input();
    switch(choice)
    {
        case 1 : 
        {
            crtstack();
            break;
        }

        case 2:
        {
            stklink();
            break;
        }

        case 3:
        {
            #include "revstack.c"
            revstack();
            break;
        }

        case 4:
        {
            intopo();
            break;
        }

    }
    break;
    }

    case 4:
    {
    printf("Press 1  to find whether hunt element is present in container or not. If present, then triple the value of hunt and search again. Repeat these steps until hunt is not found. Finally return the value of hunt.\n");
    printf("Press 2  to do Linear Search \n");
    printf("Press 3  to do Binary Search\n");
    printf("Press 4  to do Linear Search Recursively\n");
    printf("Press 5  to find the number in array that appears more than or equal to n/2 times.\n");

    choice = input();
	switch (choice) 
    {
	case 1: 
    {
    int a[5]={36,4,6,12,16};
    Tsearch(a,4);
    break;
    }
    case 2: 
    {
    //    int arr[] = { 2, 3, 4, 10, 40 };
    int x ;
    // int n = sizeof(arr) / sizeof(arr[0]);
    int values[5];

  printf("Enter 5 integers: ");

  // taking input and storing it in an array
  for(int i = 0; i < 5; ++i) {
     scanf("%d", &values[i]);
  }

  printf("Displaying integers: ");

  // printing elements of an array
  for(int i = 0; i < 5; ++i) {
     printf("%d\n", values[i]);
  }
   printf("Enter Element To Search : ");
   scanf("%d",&x);
    // Function call
    int result = LSsearch(values, 5, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);

        break;
    }
    
    case 3:
    {
    //     int arr[] = { 2, 3, 4, 10, 40 };
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int x = 10;
    int x ;
    // int n = sizeof(arr) / sizeof(arr[0]);
    int values[5];

  printf("Enter 5 integers: ");

  // taking input and storing it in an array
  for(int i = 0; i < 5; ++i) {
     scanf("%d", &values[i]);
  }

  printf("Displaying integers: ");

  // printing elements of an array
  for(int i = 0; i < 5; ++i) {
     printf("%d\n", values[i]);
  }
   printf("Enter Element To Search : ");
   scanf("%d",&x);
    int result = BSbinarySearch(values, 0, 5, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",
                            result);
        break;
    }

    case 4:
    {
    //      int arr[] = {12, 34, 54, 2, 3};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int x = 3;
    int x ;
    // int n = sizeof(arr) / sizeof(arr[0]);
    int values[5];

  printf("Enter 5 integers: ");

  // taking input and storing it in an array
  for(int i = 0; i < 5; ++i) {
     scanf("%d", &values[i]);
  }

  printf("Displaying integers: ");

  // printing elements of an array
  for(int i = 0; i < 5; ++i) {
     printf("%d\n", values[i]);
  }
   printf("Enter Element To Search : ");
   scanf("%d",&x);
    int indx;
 
    indx = elmntSrch(values, 5, x);
 
    if (indx != -1)
        printf("Element %d is present at index %d", x, indx);
    else
        printf("Element %d is not present", x);

        break;
    }

    case 5:
    {
        int n;
    printf("Enter the value for n\n");
    scanf("%d",&n);
    int arr[n];
    for( int i=0 ; i<n ; i++)
    scanf("%d",&arr[i]);

    printf("%d \n",findElement(arr, n));
        break;
    }

    default:
		printf("wrong - Input\n");
	}
	return 0;

    break;
    }
    
    case 5:
    {
        printf("Press 1 to store n employee's data such as employee name," 
        "gender,designation, department, basic pay. Calculate the gross pay of each employees \n");
        printf("Press 2 to add two distances (in km-meter) by passing structure to a function\n");
        printf("Press 3 to perform the following operations in a single linked list by using suitable user defined functions for each case.\n");
        printf(" --> a)Create a list and display the list.\n") ;
        printf(" -->b) Check if the list is empty.\n");
        printf("Enter Choice : \n");


        choice = input();
	    switch (choice) 
        {
           case 1:
           { 
            #include "hrsal.c"
            emp();
            break;

           }
           case 2:
           {
               #include "km.c"
               km();
               break;
           }
           case 3:
           {
               #include "list.c"
               list();
               break;
           }
           default :
           printf("wrong Input\n");

        }
    }

    case 6:
    {   
        // printf("------> Thanks For Using <-------")
        exit(1);
        break;
    }

    default:
		printf("wrong Input\n");
}
	
		
    }
return 0;

} // Change Menu-Driven




int input()
{
	int number;
	scanf("%d", &number);
	return (number);
}

void output(float number)
{
	printf("%f", number);
}
