#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp;
    fp = fopen("krzysztof.txt", "w");

    fprintf(fp, "700 600\n");
    int i = 1;
    int x = 350;
    int y = 300;
    int a = 5; //usta
    while (i < 101)
    {
        fprintf(fp, "%d %d\n", i, 20 + (i % 2) * 5);

        //tło białe i szara scena
        fprintf(fp, "KW %d %d %d\n", 160, 160, 160);
        fprintf(fp, "KP %d %d %d\n", 160, 160, 160);
        fprintf(fp, "PR %d %d %d %d %d\n", 0, 420, 700, 180, 1);

        //ciało - czarne
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 0, 0, 0);
        fprintf(fp, "kolor_piora %d %d %d\n", 0, 0, 0);

        //tłów
        fprintf(fp, "PR %d %d %d %d %d\n", x - 25, y - 80, 50, 160, 1);

        //nogi
        fprintf(fp, "rozmiar_piora %d\n", 20);
        fprintf(fp, "linia %d %d %d %d\n", x - 15, y + 80, x - 25, y + 220);
        fprintf(fp, "linia %d %d %d %d\n", x + 15, y + 80, x + 25, y + 220);

        //rece - prawa ruchoma
        fprintf(fp, "rozmiar_piora %d\n", 20);
        fprintf(fp, "linia %d %d %d %d\n", x - 25, y - 75, x - 50 - (i % 50), y);
        fprintf(fp, "linia %d %d %d %d\n", x - 50 - (i % 50), y, x - 70 + (i % 50), y - 50);

        //lewa
        fprintf(fp, "linia %d %d %d %d\n", x + 25, y - 75, x + 70, y);
        fprintf(fp, "linia %d %d %d %d\n", x + 70, y, x + 25, y + 40);

        //miktofon -zależny od prawej
        fprintf(fp, "rozmiar_piora %d\n", 10);
        fprintf(fp, "linia %d %d %d %d\n", x - 45, y + 220, x - 70 + (i % 50), y - 50);
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 64, 64, 64);
        fprintf(fp, "kolor_piora %d %d %d\n", 64, 64, 64);
        fprintf(fp, "elipsa %d %d %d %d %d\n", x - 75 + (i % 50), y - 60, 10, 30, 1);
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 96, 96, 96);
        fprintf(fp, "kolor_piora %d %d %d\n", 96, 96, 96);
        fprintf(fp, "elipsa %d %d %d %d %d\n", x - 75 + (i % 50), y - 60, 10, 10, 1);

        //koszula
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 255, 255, 255);
        fprintf(fp, "kolor_piora %d %d %d\n", 255, 255, 255);
        fprintf(fp, "trojkat %d %d %d %d %d %d\n", x - 25, y - 80, x + 25, y - 80, x, y - 50);

        //glowa
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 255, 204, 153);
        fprintf(fp, "kolor_piora %d %d %d\n", 255, 204, 153);
        fprintf(fp, "elipsa %d %d %d %d %d\n", x - 30, y - 150, 60, 70, 1);

        //usta - ruchome
        if (i % 5 == 0)
            a += 3;
        if (i % 7 == 0)
            a -= 2;
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 204, 0, 0);
        fprintf(fp, "kolor_piora %d %d %d\n", 204, 0, 0);
        fprintf(fp, "elipsa %d %d %d %d %d\n", x - 10, y - 100, 20, a, 1);

        //wąs
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 0, 0, 0);
        fprintf(fp, "kolor_piora %d %d %d\n", 0, 0, 0);
        fprintf(fp, "trojkat %d %d %d %d %d %d\n", x - 10, y - 100, x, y - 100, x - 5, y - 105); //1
        fprintf(fp, "trojkat %d %d %d %d %d %d\n", x + 10, y - 100, x, y - 100, x + 5, y - 105); //3
        fprintf(fp, "trojkat %d %d %d %d %d %d\n", x, y - 100, x - 5, y - 105, x + 5, y - 105);  //2

        //okulary
        fprintf(fp, "PR %d %d %d %d %d\n", x - 17, y - 125, 10, 5, 1);
        fprintf(fp, "PR %d %d %d %d %d\n", x + 7, y - 125, 10, 5, 1);

        //czapka
        fprintf(fp, "TG %d %d\n", x - 50, y - 200);

        fprintf(fp, "ST\n");
        i++;
    }

    fprintf(fp, "KONIEC\n");

    fclose(fp);

    return 0;
}