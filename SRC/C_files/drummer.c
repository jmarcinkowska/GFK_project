#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp;
    fp = fopen("perkusista.txt", "w");

    fprintf(fp, "700 600\n");
    int i = 0;

    while (i < 100)
    {
        fprintf(fp, "%d %d\n", i, 10);
        fprintf(fp, "KW %d %d %d\n", 255, 255, 255);
        fprintf(fp, "KP %d %d %d\n", 255, 255, 255);
        fprintf(fp, "PR %d %d %d %d %d\n", 0, 0, 700, 600, 1);

    //PODLOGA
        fprintf(fp, "KW %d %d %d\n", 160, 150, 140);
        fprintf(fp, "KP %d %d %d\n", 160, 150, 140);
        fprintf(fp, "PR %d %d %d %d %d\n", 0, 450, 700, 600, 1);


    //GLOWA
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 220, 190, 190);
        fprintf(fp, "kolor_piora %d %d %d\n", 220, 190, 190);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 280-i/5, 90, 80, 80, 1);

    //WLOSY
        fprintf(fp, "RP %d\n", 10);
        fprintf(fp, "kolor_piora %d %d %d\n", 80, 50, 5);
        fprintf(fp, "LN %d %d %d %d\n", 280-i/5, 120-i/5, 320-i/5, 90);
        fprintf(fp, "LN %d %d %d %d\n", 280-i/5, 110-i/5, 320-i/5, 80);
        fprintf(fp, "LN %d %d %d %d\n", 320-i/5, 90, 360-i/5, 120-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 320-i/5, 80, 360-i/5, 110-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 320-i/5, 80, 310-i/5, 110); //prawy dol
        fprintf(fp, "LN %d %d %d %d\n", 320-i/5, 80, 320-i/4, 110); //prawy dol
        fprintf(fp, "LN %d %d %d %d\n", 320-i/5, 80, 330-i/4, 110); //prawy dol
        fprintf(fp, "LN %d %d %d %d\n", 320-i/5, 80, 345-i/4, 115); //prawy dol
        fprintf(fp, "LN %d %d %d %d\n", 320-i/5, 80, 295-i/4, 115); //prawy dol


    //USTA
        fprintf(fp, "rozmiar_piora %d\n", 7);
        fprintf(fp, "kolor_piora %d %d %d\n", 200, 140, 120);
        fprintf(fp, "LN %d %d %d %d\n", 300-i/5, 150, 320-i/5, 155);
        fprintf(fp, "LN %d %d %d %d\n", 320-i/5, 155, 340-i/5, 150);

    //OCZY
        fprintf(fp, "kolor_piora %d %d %d\n", 120, 160, 220);
        fprintf(fp, "KW %d %d %d\n", 120, 160, 220);
        fprintf(fp, "EL %d %d %d %d\n", 300-i/5, 120, 10, 10, 1);
        fprintf(fp, "EL %d %d %d %d\n", 330-i/5, 120, 10, 10, 1);

    //JEZYK
        fprintf(fp, "kolor_piora %d %d %d\n", 200, 70, 70);
        fprintf(fp, "KW %d %d %d\n", 200, 70, 70);
        fprintf(fp, "EL %d %d %d %d\n", 335-i/5, 150, 8, 5, 1);

        fprintf(fp, "rozmiar_piora %d\n", 10);
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 220, 190, 190);
        fprintf(fp, "kolor_piora %d %d %d\n", 220, 190, 190);

    //NOGI
        //LEWA
        fprintf(fp, "LN %d %d %d %d\n", 320, 320, 250, 380); //GORA
        fprintf(fp, "LN %d %d %d %d\n", 250, 380, 250, 450); //DOL
        //PRAWA
        fprintf(fp, "linia %d %d %d %d\n", 320, 320, 390, 380);
        fprintf(fp, "LN %d %d %d %d\n", 390, 380, 390, 450);

    //PERKUSJA
        fprintf(fp, "TG %d %d\n", 140, 260);

    //TULOW
        fprintf(fp, "linia %d %d %d %d\n", 320-i/5, 170, 320, 305);

    if(i<70){
    //RECE
        fprintf(fp, "linia %d %d %d %d\n", 320-i/5, 190, 420, 220); //PRAWA GORA
        fprintf(fp, "linia %d %d %d %d\n", 320-i/5, 190, 220, 220); //LEWA GORA
        if((i%12)<6){
            fprintf(fp, "LN %d %d %d %d\n", 420, 220, 340, 220+(i%6)*10); //PRAWY DOL
            fprintf(fp, "LN %d %d %d %d\n", 220, 220, 300, 275-(i%6)*10); //LEWY DOL
        //PALKI
            fprintf(fp, "rozmiar_piora %d\n", 7);
            fprintf(fp, "kolor_piora %d %d %d\n", 0, 0, 0);
            fprintf(fp, "LN %d %d %d %d\n", 340, 255+(i%6)*10 ,335, 220+(i%6)*10); //PRAWA
            fprintf(fp, "LN %d %d %d %d\n", 315, 255-(i%6)*10, 300, 290-(i%6)*10); //LEWA
        }
        else{
            fprintf(fp, "LN %d %d %d %d\n", 420, 220, 340, 275-(i%6)*10); //PRAWY DOL
            fprintf(fp, "LN %d %d %d %d\n", 220, 220, 300, 220+(i%6)*10); //LEWY DOL
        //PALKI
            fprintf(fp, "rozmiar_piora %d\n", 7);
            fprintf(fp, "kolor_piora %d %d %d\n", 0, 0, 0);
            fprintf(fp, "LN %d %d %d %d\n", 340, 255-(i%6)*10 ,335, 290-(i%6)*10); //PRAWA
            fprintf(fp, "LN %d %d %d %d\n", 315, 255+(i%6)*10, 300, 220+(i%6)*10); //LEWA
        }
    }

    else{
    //RECE
        fprintf(fp, "linia %d %d %d %d\n", 320-i/5, 190, 350, 250); //PRAWA GORA
        fprintf(fp, "linia %d %d %d %d\n", 320-i/5, 190, 280, 250); //LEWA GORA
        if((i%12)<6){
            fprintf(fp, "LN %d %d %d %d\n", 350, 250, 280, 220+(i%6)*10); //PRAWY DOL
            fprintf(fp, "LN %d %d %d %d\n", 280, 250, 200, 275-(i%6)*10); //LEWY DOL
        //PALKI
            fprintf(fp, "rozmiar_piora %d\n", 7);
            fprintf(fp, "kolor_piora %d %d %d\n", 0, 0, 0);
            fprintf(fp, "LN %d %d %d %d\n", 280, 255+(i%6)*10 ,275, 220+(i%6)*10); //PRAWA
            fprintf(fp, "LN %d %d %d %d\n", 215, 255-(i%6)*10, 200, 290-(i%6)*10); //LEWA
        }
        else{
            fprintf(fp, "LN %d %d %d %d\n", 350, 250, 280, 275-(i%6)*10); //PRAWY DOL
            fprintf(fp, "LN %d %d %d %d\n", 280, 250, 200, 220+(i%6)*10); //LEWY DOL
        //PALKI
            fprintf(fp, "rozmiar_piora %d\n", 7);
            fprintf(fp, "kolor_piora %d %d %d\n", 0, 0, 0);
            fprintf(fp, "LN %d %d %d %d\n", 280, 255-(i%6)*10 ,275, 290-(i%6)*10); //PRAWA
            fprintf(fp, "LN %d %d %d %d\n", 215, 255+(i%6)*10, 200, 220+(i%6)*10); //LEWA
        }

    }

    //MUCHA
        fprintf(fp, "rozmiar_piora %d\n", 7);
        fprintf(fp, "kolor_piora %d %d %d\n", 60, 150, 70);
        fprintf(fp, "KW %d %d %d\n", 60, 150, 70);\
        fprintf(fp, "EL %d %d %d %d\n", 315-i/5, 175, 10, 10, 1);
        fprintf(fp, "trojkat %d %d %d %d %d %d\n", 310-i/5, 180, 305-i/5, 175, 305-i/5, 185);
        fprintf(fp, "trojkat %d %d %d %d %d %d\n", 330-i/5, 180, 335-i/5, 175, 335-i/5, 185);

        fprintf(fp, "ST\n");
        i++;
    }
    fprintf(fp, "KONIEC\n");
    fclose(fp);
    return 0;
}
