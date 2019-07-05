#include <stdio.h>
#define pi 3.14159;

int main() {

    int n1,n2,n3,n;
    scanf("%i",&n);

    n1=0;
    n2=1;

    int x;
    for(x=0;x<=n;x++){

    n3=n1+n2;
    n1=n2;
    n2=n3;

    printf("%i ",n1);
    }



   return (0);
}
