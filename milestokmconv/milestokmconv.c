#include <stdio.h>
#include <stdlib.h>
#define KM_PER_MILE 1.609
#define BUFFSIZE 6

int main(int argc, char const *argv[])
{
    double miles, kms;
    if (argc > 1)
    {
        printf("COMMAND LINE ARG FOUND, WORKING WITH FILE.\n");
        char buff[BUFFSIZE];
        FILE *fp = fopen(argv[1], "r");
        if (fp != NULL)
        {
            printf("READING FILE\n");
            while (fgets(buff, BUFFSIZE, fp) != NULL)
            {
                miles = atof(buff);
                printf("Miles = %lf\n", miles);
            }
        }
        else
        {
            printf("UNABLE TO OPEN FILE\n");
        }
        fclose(fp);
    }
    else
    {
        printf("NO COMMAND LINE ARG FOUND, WORKING IN INTERACTIVE MODE.\n");
        printf("Miles = ");
        scanf("%lf", &miles);
        // printf("Miles = %f", miles);
    }

    kms = miles * KM_PER_MILE;
    printf("\nKilometers = %f", kms);

    printf("\n");
    return 0;
}
