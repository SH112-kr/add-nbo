#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(){
    FILE * thous;
    FILE * five;
    thous = fopen("/home/kali/add-nbo/thousand.bin","r");
    five = fopen("/home/kali/add-nbo/five-hundred.bin","r");

    if (thous == NULL || five == NULL) //exception error
    {
        printf("NULL FILE");
                exit(1);
    }

    uint32_t result1;
    uint32_t result2;

    fread(&result1,4,1,thous);
    fread(&result2,4,1,five);

    result1 = ntohl(result1);
    result2 = ntohl(result2);
    int result3 = result1 + result2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",result1,result1,result2,result2,result3,result3);
            return 0;
}
