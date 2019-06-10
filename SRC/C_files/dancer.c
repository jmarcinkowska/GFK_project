#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp;
    fp = fopen("dancer.txt", "w");

    fprintf(fp, "700 600\n");
    int i = 0;
    int polozeniex = 0;

    while (i < 100)
    {
        int czas = i * i % 10 + 5;
        polozeniex += i * 2;
        fprintf(fp, "%d %d\n", i, 10);
        fprintf(fp, "KW %d %d %d\n", 0, 0, 0);
        fprintf(fp, "KP %d %d %d\n", 0, 0, 0);
        fprintf(fp, "PR %d %d %d %d %d\n", 0, 0, 700, 600, 1);

        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 255, 255, 255);
        fprintf(fp, "kolor_piora %d %d %d\n", 255, 255, 255);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 280, 90, 80, 80, 1);

        fprintf(fp, "rozmiar_piora %d", 15);
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 255, 255, 255);
        fprintf(fp, "kolor_piora %d %d %d\n", 255, 255, 255);
        fprintf(fp, "linia %d %d %d %d\n", 320, 170, 400 - i, 350 - i / 10);

        fprintf(fp, "LN %d %d %d %d\n", 400 - i, 350 - i / 10, 300, 400);
        fprintf(fp, "LN %d %d %d %d\n", 300, 400, 290, 480);
        fprintf(fp, "linia %d %d %d %d\n", 400 - i, 350 - i / 10, 360, 400);
        fprintf(fp, "LN %d %d %d %d\n", 360, 400, 370, 480);

        fprintf(fp, "linia %d %d %d %d\n", 320, 170, 340 + i, 260 + i / 15);
        fprintf(fp, "LN %d %d %d %d\n", 340 + i, 260 + i / 15, 350 - i, 300 - i);

        fprintf(fp, "linia %d %d %d %d\n", 320, 170, 290 - i / 2, 260 - i / 10);
        fprintf(fp, "LN %d %d %d %d\n", 290 - i / 2, 260 - i / 10, 250 + i / 20, 270 - i / 10);

        fprintf(fp, "ST\n");
        i++;
    }
    fprintf(fp, "KONIEC\n");
    fclose(fp);
    return 0;
}