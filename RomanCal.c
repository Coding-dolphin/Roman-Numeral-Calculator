//#include <iostream>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10

char* convert_to_Roman(int num)
{
    int ct=0,i;
    int nums[7]={1,5,10,50,100,500,1000};
    char chars[8]="IVXLCDM";
    char* r = (char*)malloc(sizeof(char)*10);
    char* head = r;
    for(i=6;i>=0;i--){
        ct=num / nums[i];
        num %= nums[i];
        if(ct>0){
            if((nums[i]==5 || nums[i]==50 || nums[i]==500) && num/nums[i-1]*nums[i-1] == nums[i]-nums[i-1]){
                *r++ = chars[i-1];
                *r++ = chars[i+1];
                num = num % nums[--i];
            }else if((nums[i]==1 || nums[i]==10 || nums[i]==100) && ct*nums[i] == nums[i+1] - nums[i]){
                *r++ = chars[i];
                *r++ = chars[i+1];
            }else{
                int j;
                for(j=0;j<ct;j++)
                    *r++ = chars[i];
            }
        }
    }
    *r = '\0';
    return head;
}

int getVal(char c){
    switch(c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}

int convert_to_decimal(char* s) {
    int len = (int)strlen(s);
    int sum=0;
    for(int i=0;i<len;i++){
        if(i+1<len && getVal(s[i])<getVal(s[i+1])){
            sum += getVal(s[i+1]) - getVal(s[i]);
            i++;
        }else
            sum += getVal(s[i]);
    }
    return sum;
}

int calc_Romans(int num1, int num2, char oper)
{
    switch (oper)
    {
        case '+':
            return num1 + num2;
            break;
        case '-':
            return num1 - num2;
            break;
        case '*':
            return num1*num2;
            break;
        case '/':
            if (num2 != 0)
            {
                return num1 / num2;
            }
            else
                break;
    }
    return 0;
}

int main()
{
    char *romanResult;
    char romanOne[LENGTH], romanTwo[LENGTH];
    char oper;
    int num1, num2, numResult;
    printf("Enter the first roman number: ");
    scanf("%s", romanOne);
    printf("Enter the second roman number: ");
    scanf("%s", romanTwo);
    printf("Enter the operator: ");
    scanf(" %c", &oper);
    num1 = convert_to_decimal(romanOne);
    num2 = convert_to_decimal(romanTwo);
    numResult = calc_Romans(num1, num2, oper);
    romanResult = convert_to_Roman(numResult);
    printf("The ressult is: %s\n",romanResult);
    
}
