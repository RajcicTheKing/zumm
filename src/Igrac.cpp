#include "Igrac.h"
#include "main.h"

Igrac::Igrac()
{
    int usporenje = 1;
    int ukupno_usporenje = 120;
    poeni=0;
    pozicija_x=0;
    pozicija_y=0;
    energija_kretanja=-5;
    energija=200;
    energija=100;
}
void Igrac::kretanje_ai(void)
{


        if (target_x != pozicija_x)
        {
            usporenje++;
            if (usporenje >= ukupno_usporenje)
            {
                if (target_x < pozicija_x)
                {
                    pozicija_x--;
                    usporenje=0;
                }
                else if (target_x > pozicija_x)
                {
                    pozicija_x++;
                    usporenje=0;
                }
            }
        }
        if (target_y != pozicija_y)
        {
            usporenje++;
            if (usporenje >= ukupno_usporenje)
            {
                if (target_y < pozicija_y)
                {
                    pozicija_y--;
                    usporenje=0;
                }
                else if (target_y > pozicija_y)
                {
                    pozicija_y++;
                    usporenje=0;
                }
            }
        }
}
void Igrac::kretanje_igraca(int komanda)
{
    if(tip==ai)
    {
        kretanje_ai();
        return;
    }
    if(komanda==desno)
    {
        pozicija_x++;
    }
    if(komanda==levo)
    {
        pozicija_x--;
    }
    if(komanda==gore)
    {
        pozicija_y--;
    }
    if(komanda==dole)
    {
        pozicija_y++;
    }

    if(pozicija_x<0)
    {
        pozicija_x=xmax;
    }
    if(pozicija_x>xmax)
    {
        pozicija_x=0;
    }
    if(pozicija_y<0)
    {
        pozicija_y=ymax;
    }
    if(pozicija_y>ymax)
    {
        pozicija_y=0;
    }
    if(komanda!=nista && komanda != pucanj_desno && komanda != pucanj_dole && komanda != pucanj_gore && komanda != pucanj_levo)
    {
        energija=energija+energija_kretanja;
    }
}
Igrac::~Igrac()
{
    //dtor
}
