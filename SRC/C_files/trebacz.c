#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp;
    fp = fopen("trebacz.txt", "w");

    fprintf(fp, "600 600\n");
    int i = 0;
    int polozeniex = 0;

    while (i < 100)
    {
        int czas = i * i % 10 + 5;
        polozeniex += i * 2;
        fprintf(fp, "%d %d\n", i, 10);

        fprintf(fp, "KP %d %d %d\n", 240, 128, 128);
        fprintf(fp, "KW %d %d %d\n", 240, 128, 128);
        fprintf(fp, "PR %d %d %d %d %d\n", 0, 300, 600, 200, 1);

        //ręka z tyłu
        fprintf(fp, "RP %d", 8);
        fprintf(fp, "KP %d %d %d\n", 0, 0, 0);
        fprintf(fp, "KW %d %d %d\n", 0, 0, 0);
        fprintf(fp, "LN %d %d %d %d\n", 340 - i, 190, 395 - i, 220 - i / 5);
        fprintf(fp, "linia %d %d %d %d\n", 395 - i, 220 - i / 5, 420 - i, 180 - i);

        //rysunek
        fprintf(fp, "TG %d %d\n", 375 - i, 31 + i / 8);

        //noga z tyłu
        fprintf(fp, "RP %d", 9);
        fprintf(fp, "KP %d %d %d\n", 245, 222, 179);
        fprintf(fp, "KW %d %d %d\n", 245, 222, 179);
        fprintf(fp, "LN %d %d %d %d\n", 365 - i, 335, 300 - i / 20, 420 + i / 10);

        //tułów
        fprintf(fp, "KP %d %d %d\n", 70, 130, 180);
        fprintf(fp, "KW %d %d %d\n", 70, 130, 180);
        fprintf(fp, "EL %d %d %d %d %d\n", 310 - i, 180, 100, 190, 1);

        //noga z przodu
        fprintf(fp, "RP %d\n", 11);
        fprintf(fp, "linia %d %d %f %d\n", 355 - i, 335, 375 - i * 1.5, 430 - i / 10);

        //głowa
        fprintf(fp, "KP %d %d %d\n", 255, 235, 205);
        fprintf(fp, "KW %d %d %d\n", 255, 235, 205);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 280 - i, 120, 80, 80, 1);

        //oczy
        fprintf(fp, "KW %d %d %d\n", 255, 255, 255);
        fprintf(fp, "KP %d %d %d\n", 255, 255, 255);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 310 - i, 160, 7, 7, 1);

        //drugie oko
        fprintf(fp, "KW %d %d %d\n", 255, 255, 255);
        fprintf(fp, "KP %d %d %d\n", 255, 255, 255);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 335 - i, 140, 6, 6, 1);

        //jedna źrenica
        fprintf(fp, "KW %d %d %d\n", 0, 0, 0);
        fprintf(fp, "KP %d %d %d\n", 0, 0, 0);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 315 - i, 165, 4, 4, 1);

        //druga źrenica
        fprintf(fp, "KP %d %d %d\n", 0, 0, 0);
        fprintf(fp, "KW %d %d %d\n", 0, 0, 0);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 340 - i, 145, 3, 3, 1);

        //usta
        fprintf(fp, "KP %d %d %d\n", 255, 0, 0);
        fprintf(fp, "KW %d %d %d\n", 255, 0, 0);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 350 - i, 170, 4 + (i % 3), 4 + (i % 3), 1);

        //ręka z przodu
        fprintf(fp, "RP %d\n", 8);
        fprintf(fp, "linia %d %d %d %d\n", 355 - i, 220, 405 - i, 195 + i / 20);      //reka
        fprintf(fp, "LN %d %d %d %d\n", 405 - i, 195 + i / 20, 420 - i, 123 + i / 8); //reka

        fprintf(fp, "ST\n");
        i++;
    }
    fprintf(fp, "KONIEC\n");
    fclose(fp);
    return 0;
}