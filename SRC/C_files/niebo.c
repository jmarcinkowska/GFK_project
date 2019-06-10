#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp;
    fp = fopen("animacja.txt", "w");

    fprintf(fp, "700 600\n");
    int i = 0;
    int polozeniex = 0;

    while (i < 200)
    {
        fprintf(fp, "%d %d\n", i, 15);

        //niebo
        fprintf(fp, "KW %d %d %d\n", 176, 196, 222);
        fprintf(fp, "KP %d %d %d\n", 176, 196, 222);
        fprintf(fp, "prostokat %d %d %d %d %d\n", 0, 0, 700, 600, 1);

        //słońce
        fprintf(fp, "KW %d %d %d\n", 255, 215, 0);
        fprintf(fp, "KP %d %d %d\n", 255, 215, 0);
        fprintf(fp, "EL %d %d %d %d %d\n", 500, 100, 190, 190, 1);

        //ptak
        fprintf(fp, "TG %d %d\n", 4 * i, 400);

        fprintf(fp, "KW %d %d %d\n", 245, 245, 245);
        fprintf(fp, "KP %d %d %d\n", 245, 245, 245);

        fprintf(fp, "EL %d %d %d %d %d\n", 6 * i, 100, 80, 80, 1);
        fprintf(fp, "EL %d %d %d %d %d\n", 50 + 6 * i, 100, 150, 100, 1);
        fprintf(fp, "EL %d %d %d %d %d\n", 170 + 6 * i, 90, 50, 50, 1);

        fprintf(fp, "EL %d %d %d %d %d\n", 700 - 4 * i, 250, 90, 90, 1);
        fprintf(fp, "EL %d %d %d %d %d\n", 750 - 4 * i, 250, 150, 120, 1);
        fprintf(fp, "EL %d %d %d %d %d\n", 878 - 4 * i, 280, 70, 70, 1);

        fprintf(fp, "KW %d %d %d\n", 105, 105, 105);
        fprintf(fp, "KP %d %d %d\n", 105, 105, 105);

        fprintf(fp, "ST\n");
        i++;
    }
    fprintf(fp, "KONIEC\n");
    fclose(fp);
    return 0;
}