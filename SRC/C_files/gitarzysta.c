#include <stdio.h>

#include <math.h>
int main()
{

    FILE *fp;
    fp = fopen("gitarzysta.txt", "w");

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
        fprintf(fp, "PR %d %d %d %d %d\n", 0, 400, 700, 600, 1);

        if(i<70){
    //GITARA
        fprintf(fp, "TG %d %d\n", 280, 150);

    //GLOWA
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 220, 190, 190);
        fprintf(fp, "kolor_piora %d %d %d\n", 220, 190, 190);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 280+i/4, 90, 80, 80, 1);

    //TULOW
        fprintf(fp, "linia %d %d %d %d\n", 320+i/4, 170, 320, 261);

    //WLOSY
        fprintf(fp, "RP %d\n", 10);
        fprintf(fp, "kolor_piora %d %d %d\n", 15, 225, 15);
        fprintf(fp, "LN %d %d %d %d\n", 290+i/4, 115, 305+i/2, 180-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 295+i/4, 115, 320+i/2, 175-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 300+i/4, 115, 340+i/2, 170-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 300+i/4, 110, 370+i/2, 155-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 300+i/4, 105, 365+i/2, 155-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 305+i/4, 95, 375+i/2, 140-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 300+i/4, 95, 360+i/2, 160-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 320+i/4, 90, 395+i/2, 110-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 310+i/4, 90, 385+i/2, 120-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 310+i/4, 90, 375+i/2, 130-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 290+i/4, 110, 280+i/2, 180-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 290+i/4, 115, 260+i/2, 180-i/5);

        fprintf(fp, "rozmiar_piora %d\n", 10);
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 220, 190, 190);
        fprintf(fp, "kolor_piora %d %d %d\n", 220, 190, 190);

    //NOGI
        //LEWA
        fprintf(fp, "LN %d %d %d %d\n", 300, 330, 290+i/5, 400+i/5); //GORA
        fprintf(fp, "LN %d %d %d %d\n", 290+i/5, 400+i/5, 250, 450); //DOL
        //PRAWA
        fprintf(fp, "LN %d %d %d %d\n", 350, 320, 390, 380); //GORA
        fprintf(fp, "LN %d %d %d %d\n", 390, 380, 390, 450); //DOL

    //RECE
        //PRAWA
        fprintf(fp, "linia %d %d %d %d\n", 320+i/4, 190, 360+i/5, 240-i/5); //CZESC I
        fprintf(fp, "linia %d %d %d %d\n", 372+i/5, 253-i/5, 380+i/5, 260-i/5); //CZESC II
        fprintf(fp, "linia %d %d %d %d\n", 380+i/5, 260-i/5, 400+i/5, 220-i/5); //CZESC III
        fprintf(fp, "linia %d %d %d %d\n", 400+i/5, 220-i/5, 395+i/5, 215-i/5); //CZESC IV
        //LEWA
        fprintf(fp, "linia %d %d %d %d\n", 320+i/4, 190, 270, 255); //GORA
        if((i%12)<6){
            fprintf(fp, "LN %d %d %d %d\n", 270, 255, 320, 300-(i%6)*5); //DOL
        }
        else{
            fprintf(fp, "LN %d %d %d %d\n", 270, 255, 320, 255+(i%6)*5); //DOL
        }
        }

    //NA KOLANACH
        else{
    //GITARA
        fprintf(fp, "TG %d %d\n", 280, 180);

    //GLOWA
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 220, 190, 190);
        fprintf(fp, "kolor_piora %d %d %d\n", 220, 190, 190);
        fprintf(fp, "elipsa %d %d %d %d %d\n", 280-i/4, 120, 80, 80, 1);

    //WLOSY
        fprintf(fp, "RP %d\n", 10);
        fprintf(fp, "kolor_piora %d %d %d\n", 15, 225, 15);
        fprintf(fp, "LN %d %d %d %d\n", 290-i/4, 145, 305-i/4, 210-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 295-i/4, 145, 320-i/4, 205-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 300-i/4, 145, 340-i/4, 200-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 300-i/4, 140, 370-i/4, 185-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 300-i/4, 135, 365-i/4, 185-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 305-i/4, 125, 375-i/4, 170-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 300-i/4, 125, 360-i/4, 190-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 320-i/4, 120, 395-i/4, 140-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 310-i/4, 120, 385-i/4, 150-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 310-i/4, 120, 375-i/4, 160-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 290-i/4, 130, 280-i/4, 210-i/5);
        fprintf(fp, "LN %d %d %d %d\n", 290-i/4, 135, 260-i/4, 210-i/5);


        fprintf(fp, "rozmiar_piora %d\n", 10);
        fprintf(fp, "kolor_wypelnienia %d %d %d\n", 220, 190, 190);
        fprintf(fp, "kolor_piora %d %d %d\n", 220, 190, 190);
    //NOGI
        //LEWA
        fprintf(fp, "LN %d %d %d %d\n", 300, 360, 290, 460); //GORA
        fprintf(fp, "LN %d %d %d %d\n", 290, 460, 250, 460); //DOL
        //PRAWA
        fprintf(fp, "LN %d %d %d %d\n", 350, 350, 390, 440); //GORA
        fprintf(fp, "LN %d %d %d %d\n", 390, 440, 350, 440); //DOL

    //TULOW
        fprintf(fp, "linia %d %d %d %d\n", 320-i/4, 200, 320, 291);

    //RECE
        //PRAWA
        fprintf(fp, "linia %d %d %d %d\n", 320-i/4, 220, 360+i/5, 270-i/5); //CZESC I
        fprintf(fp, "linia %d %d %d %d\n", 372+i/5, 283-i/5, 380+i/5, 290-i/5); //CZESC II
        fprintf(fp, "linia %d %d %d %d\n", 380+i/5, 290-i/5, 400+i/5, 250-i/5); //CZESC III
        fprintf(fp, "linia %d %d %d %d\n", 400+i/5, 250-i/5, 395+i/5, 245-i/5); //CZESC IV
        //LEWA
        fprintf(fp, "linia %d %d %d %d\n", 320-i/4, 220, 270, 285); //GORA
        if((i%12)<6){
            fprintf(fp, "LN %d %d %d %d\n", 270, 285, 300, 320); //DOL CZESC I
            fprintf(fp, "LN %d %d %d %d\n", 300, 320, 315, 320+(i%6)*2); //DOL CZESC II
        }
        else{
            fprintf(fp, "LN %d %d %d %d\n", 270, 285, 300, 320); //DOL CZESC I
            fprintf(fp, "LN %d %d %d %d\n", 300, 320, 315, 320-(i%6)*2); //DOL CZESC II
        }
        }

        fprintf(fp, "ST\n");
        i++;
    }
    fprintf(fp, "KONIEC\n");
    fclose(fp);
    return 0;
}
