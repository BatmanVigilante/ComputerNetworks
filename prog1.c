#include <stdio.h>

int main()
{
    int a[40], b[40], i, c = 0, k = 0, j, r = 0;
    long int w;
    printf("Enter input: ");
    scanf("%ld", &w);

    // Extract digits from the number
   while(w>0){
        b[r++]=w%10;
        w/=10;
   }

    // Reverse the digits and store in array 'a'
    for(i=r-1;i>=0;i--){
        a[k++]=b[i];
    }

    // Bit stuffing process
    c=0;
    for(i=0;i<k;i++){
        if(a[i]==0){
            c=0;
        }else{
            c++;
        }
        if (c == 3)
        {
            // Shift elements to the right to make space for a new 0
            for (j = k; j > i; j--)
            {
                a[j] = a[j - 1];
            }
            a[i + 1] = 0; // Insert 0 after the 6 consecutive 1's
            k++;          // Increase size of the array
            c = 0;        // Reset count after stuffing
        }
    
    }

    // Print the result after bit stuffing
    printf("After bit stuffing: ");
    for (i = 0; i < k; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}