// #include <stdio.h>

struct Distance {
   int km;
   float mt;
} d1, d2, result;

int km() 
{
   printf("Enter 1st distance\n");
   printf("Enter in km: ");
   scanf("%d", &d1.km);
   printf("Enter in meter: ");
   scanf("%f", &d1.mt);
 
   
   printf("\nEnter 2nd distance\n");
   printf("Enter in km: ");
   scanf("%d", &d2.km);
   printf("Enter in meter: ");
   scanf("%f", &d2.mt);
   
   
   result.km = d1.km + d2.km;
   result.mt = d1.mt + d2.mt;
   
   printf("\nSum of distances = %dkm %.0fmeter", result.km, result.mt);
   return 0;
}