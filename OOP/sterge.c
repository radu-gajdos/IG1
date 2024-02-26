#include <stdio.h>
#include <stdlib.h>

long long power(int base, int exponent) {
    long long result = 1;
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    return result;
}

long long convert_integer_part(long long num, int old_base, int new_base) {
    long long decimal = 0;
    int i = 0;

    // convert the number to decimal
    while (num > 0) {
        decimal += (num % 10) * power(old_base, i);
        i++;
        num /= 10;
    }

    // convert the decimal number to the new base
    long long new_num = 0, power_of_new_base = 1;
    while (decimal > 0) {
        new_num += (decimal % new_base) * power_of_new_base;
        power_of_new_base *= 10;
        decimal /= new_base;
    }

    return new_num;
}

long long convert_fractional_part(double num, int new_base) {
    long long new_num = 0;
    int i = 0;

    // convert the decimal fraction to the new base
    while (num > 0 && i < 15) {
        num *= new_base;
        new_num = new_num * 10 + (int)num;
        num -= (int)num;
        i++;
    }

    return new_num;
}

long long convert_base(double num, int old_base, int new_base) {
    // split the number into its integer and fractional parts
    long long integer_part = (long long)num;
    

    // convert the integer and fractional parts separately
    long long new_integer_part = convert_integer_part(integer_part, old_base, new_base);

    // combine the new integer and fractional parts into the new number
    return new_integer_part * power(10, 15);
}

int main() {
    double num;
    int old_base, new_base;

    // get the number and its old and new bases
    printf("Enter the number: ");
    scanf("%lf", &num);
    printf("Enter the old base: ");
    scanf("%d", &old_base);
    printf("Enter the new base: ");
    scanf("%d", &new_base);

    // convert the number to the new base
    long long new_num = convert_base(num, old_base, new_base);

    long long integer_part = (long long)num;
    double fractional_part = num - integer_part;;

    long long new_fractional_part = convert_fractional_part(fractional_part, new_base);


    // print the new number
    printf("%lld\n", new_num);

    return 0;
}
