#include <stdio.h>

struct complex
{
    float real;
    float img;

};

struct  complex add(struct complex a, struct complex b)
{
    struct  complex sum;
    sum.real = a.real + b.real;
    sum.img = a.img + b.img;
    return sum;
}
   void display(struct  complex c)
   {
    printf("%.2f + %.2f\n", c.real, c.img);

   }

   int main()
   {
    struct complex n1, n2, res;

    printf("Enter real and imaginary parts of 1st complex number: \n");
    scanf("%f %f", &n1.real, &n1.img);

    printf("Enter real and imaginary parts of 2nd complex number:\n");
    scanf("%f %f", &n2.real, &n2.img);
    

    res = add(n1, n2);

    printf("Sum of complex numbers:\n");
    display(res);
    return 0;
   }
   