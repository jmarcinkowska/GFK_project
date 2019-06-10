#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *plik;
    plik = fopen("start.txt", "w");
    fprintf(plik, "%d %d\n", 600, 500); //size

    int i = 1;
    while (i < 100)
    {
        fprintf(plik, "%d %d\n", i, 100); //klatka i czas

        //Niebieskie tło
        fprintf(plik, "KW %d %d %d\n", 51, 51, 255);             //kolor wypelnienia
        fprintf(plik, "KP %d %d %d\n", 51, 51, 255);             //kolńor piora
        fprintf(plik, "PR %d %d %d %d %d\n", 0, 0, 600, 500, 1); //prostokąt

        //gwiazdy

        fprintf(plik, "RP %d\n", 300);               //rozmiar piora
        fprintf(plik, "KP %d %d %d\n", 255, 255, 0); //kolor piora
        for (int j = 0; j < 100; j++)
            fprintf(plik, "PT %d %d\n", rand() % 600, rand() % 500); //punkty

        //tekst
        fprintf(plik, "TT %d %d\n", 100, 500 - (i * 7) % 500); //tekst

        fprintf(plik, "ST\n"); //koniec klatki
        i++;
    }

    fprintf(plik, "KONIEC\n"); //koniec pliku
    fclose(plik);

    return 0;
}