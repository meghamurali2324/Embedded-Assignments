#include <stdio.h>

//Arithmetic functions

float add(float a, float b){
    return a+b;
}
float sub(float a, float b){
    return a-b;
}
float mul(float a, float b){
    return a*b;
}
float div(float a, float b){
    if(b == 0){

        printf("Cannot divide by zero\n");
        return 0;
    }
    return a/b;
}

//func to perform arithematic operations 
float cal(float a, float b, char op){
    switch (op){
        case '+':
        return add(a,b);
        case '-':
        return sub(a,b);        
        case '*':
        return mul(a,b);        
        case '/':
        return div(a,b);        
        default:
        printf("Invalid operator\n");
        return 0;
    }
   
}
int main(){
    float num1, num2, ans;
    char op;


    //input from user
    printf("Enter first number:");
    scanf("%f", &num1);

    //input operator and second number
    printf("Enter an operator (+,-,*,/):");
    scanf(" %c", &op);
    printf("Enter second number:");
    scanf("%f", &num2);


    //perform calculations
    ans = cal(num1, num2, op);
    
    //output results
    if(!(op == '/' && num2 == 0)){
        printf("Answer: %.2f\n", ans);
    }
    return 0;

}

