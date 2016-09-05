#include "Metak.h"
#include "main.h"

#include <windows.h>

Metak::Metak()
{
   u_kretanju=false;
   razorna_moc=10;
   pozicija_x=xmax+2;
   pozicija_y=ymax+2;
}
void Metak::zvuk_metka()
{
    Beep(5000,10);
}

void Metak::kretanje()
{
    int brzina = 2;
    static int brojac;
    if(u_kretanju==false)
    {
        pozicija_x=xmax+2;
        pozicija_y=ymax+2;
    }
    if(u_kretanju == true)
    {
        if ((brojac+1)%brzina==0)
        {
            if(smer==pucanj_desno)
            {
                if(pozicija_x<=xmax)
                {
                    pozicija_x++;
                }
            }
            if(smer==pucanj_levo)
            {
                if(pozicija_x>=0)
                {
                    pozicija_x--;
                }
            }
            if(smer==pucanj_gore)
            {
                if(pozicija_y>=0)
                {
                    pozicija_y--;
                }
            }
            if(smer==pucanj_dole)
            {
                if(pozicija_y<=ymax)
                {
                    pozicija_y++;
                }
            }
            if(pozicija_x>xmax || pozicija_x<0 || pozicija_y>ymax || pozicija_y<0)
            {
                u_kretanju=false;
            }
        }
        brojac++;
    }

}
void Metak::ispali(int x_igraca,int y_igraca,int komanda)
{

    if(u_kretanju==false)
    {
        zvuk_metka();
        u_kretanju=true;
        pozicija_x=x_igraca;
        pozicija_y=y_igraca;
        smer=komanda;
    }

}

Metak::~Metak()
{
    //dtor
}
