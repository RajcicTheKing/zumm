#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <main.h>
#include <Metak.h>
#include <Igrac.h>

using namespace std;

enum oruzje {pistolj,laser,nijedno};
enum result {res_reaktor, res_medic, res_normal};
const int reaktor = -20;
const int medic = 30;
const int pocetna_energija = 200;
//const int kretanje = -5;
const int maks_broj_reaktora = 400;
const int maks_broj_medica = 400;
Metak metak_objekat;
Igrac igrac_objekat_x;
Igrac igrac_objekat_o;
int pos_reaktor[maks_broj_reaktora * 2] = {1, 4};
int pos_medic[maks_broj_medica * 2] = {4, 1};
//int pos[2] = {0,0};
//int pos_m[2] = {xmax + 1, ymax + 1};
//int energija = 100000;
//int energija2 = 100;
//int score = 0;
int brojac_medic = 1;
int brojac_reaktor = 1;
//int pos_o[2] = {0,0};
int krajigre_promenljiva = 0;
int level=1;
char matrix[xmax+2][ymax+2];

struct igrac
{
    char tip;
    int energija;
    int energija_kretanja;
    int poeni;
    int pozicija[2];
    int brzina;
    int stanje;
    int oruzje;
    int pozicija_metka[2];
};
void print_screen(void);
void beep_igrica (int frenkvencija, int vreme)
{
    if (krajigre_promenljiva == 1)
    {
        pthread_exit(NULL);
    }
    else
    {
        Beep(frenkvencija, vreme);
    }
    return;
}
void *Muzika(void *threadid)
{

    while(1)
    {
            beep_igrica (330,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (392,100);Sleep(350);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (262,300);Sleep(150);
            beep_igrica (196,300);Sleep(150);
            beep_igrica (164,300);Sleep(150);
            beep_igrica (220,300);Sleep(50);
            beep_igrica (246,100);Sleep(150);
            beep_igrica (233,200);
            beep_igrica (220,100);Sleep(150);
            beep_igrica (196,100);Sleep(75);
            beep_igrica (330,100);Sleep(75);
            beep_igrica (392,100);Sleep(75);
            beep_igrica (440,100);Sleep(150);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (392,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(50);
            beep_igrica (247,100);Sleep(250);
            beep_igrica (262,300);Sleep(150);
            beep_igrica (196,300);Sleep(150);
            beep_igrica (164,300);Sleep(150);
            beep_igrica (220,300);Sleep(50);
            beep_igrica (246,100);Sleep(150);
            beep_igrica (233,200);
            beep_igrica (220,100);Sleep(150);
            beep_igrica (196,100);Sleep(75);
            beep_igrica (330,100);Sleep(75);
            beep_igrica (392,100);Sleep(75);
            beep_igrica (440,100);Sleep(150);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (392,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(50);
            beep_igrica (247,100);Sleep(450);
            beep_igrica (392,100);Sleep(50);
            beep_igrica (370,100);Sleep(50);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (311,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (207,100);Sleep(50);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(250);
            beep_igrica (392,100);Sleep(50);
            beep_igrica (370,100);Sleep(50);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (311,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (523,100);Sleep(150);
            beep_igrica (523,100);Sleep(50);
            beep_igrica (523,100);Sleep(550);
            beep_igrica (392,100);Sleep(50);
            beep_igrica (370,100);Sleep(50);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (311,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (207,100);Sleep(50);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(250);
            beep_igrica (311,300);Sleep(150);
            beep_igrica (296,300);Sleep(150);
            beep_igrica (262,300);Sleep(650);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(150);
            beep_igrica (330,200);Sleep(25);
            beep_igrica (262,200);Sleep(25);
            beep_igrica (220,200);Sleep(25);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(50);
            beep_igrica (330,100);Sleep(350);
            beep_igrica (440,100);Sleep(150);
            beep_igrica (392,100);Sleep(250);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(150);
            beep_igrica (330,200);Sleep(25);
            beep_igrica (262,200);Sleep(25);
            beep_igrica (220,200);Sleep(25);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (330,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (392,100);Sleep(350);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (196,100);Sleep(62);
            beep_igrica (262,100);Sleep(62);
            beep_igrica (330,100);Sleep(62);
            beep_igrica (392,100);Sleep(62);
            beep_igrica (523,100);Sleep(62);
            beep_igrica (660,100);Sleep(62);
            beep_igrica (784,100);Sleep(282);
            beep_igrica (660,100);Sleep(282);
            beep_igrica (207,100);Sleep(62);
            beep_igrica (262,100);Sleep(62);
            beep_igrica (311,100);Sleep(63);
            beep_igrica (415,100);Sleep(62);
            beep_igrica (523,100);Sleep(62);
            beep_igrica (622,100);Sleep(62);
            beep_igrica (830,100);Sleep(282);
            beep_igrica (622,100);Sleep(282);
            beep_igrica (233,100);Sleep(62);
            beep_igrica (294,100);Sleep(62);
            beep_igrica (349,100);Sleep(62);
            beep_igrica (466,100);Sleep(62);
            beep_igrica (587,100);Sleep(62);
            beep_igrica (698,100);Sleep(62);
            beep_igrica (932,100);Sleep(282);
            beep_igrica (932,100);Sleep(62);
            beep_igrica (932,100);Sleep(62);
            beep_igrica (932,100);Sleep(62);
            beep_igrica (1046,675);
    }

    pthread_exit(NULL);
 }
void ludzvuk (void)
{

    Beep(300, 10);
}
void dobarzvuk (void)
{

    Beep(3000, 10);
}
void gotoxy(int x, int y)
{

    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
void gameover (void)
{

    krajigre_promenljiva = 1;
    print_screen();
    gotoxy(0, ymax + 4);
    cout << "Game over, your score is " << igrac_objekat_x.poeni << ".";
    Beep(420, 200);
    Beep(400, 200);
    Beep(420, 200);
    Beep(400, 200);
    Beep(420, 200);
    Beep(315, 200);
    Beep(370, 200);
    Beep(335, 200);
    Beep(282, 600);

    pthread_exit(NULL);
}
char tipka(void)
{

    if (kbhit()!=0)
        return getch();
    else
        return 0;
}
void clear_console(void)
{
    system("CLS");
}
void clear_matrix(void)
{
    for(int i=0;i<xmax+2;i++)
    {
        for(int j=0;j<ymax+2;j++)
        {
            matrix[i][j]=' ';
        }
    }
}
void print_border(void)
{
    for(int i = xmax + 1; i>=0; i--)
    {
        //gotoxy(i, ymax + 1);
        matrix[i][ymax+1]='_';
    }
    for(int i = ymax + 1; i >= 0; i--)
    {
        //gotoxy(xmax+1,i);
        matrix[xmax+1][i]='|';
    }
}
void print_matrix(void)
{

    static char matrix_old[xmax+2][ymax+2];

    for(int i=0;i<xmax+2;i++)
    {
        for(int j=0;j<ymax+2;j++)
        {
            if(matrix_old[i][j]!=matrix[i][j])
            {
                gotoxy(i,j);
                cout<<matrix[i][j];
            }
        }
    }

    for(int i=0;i<xmax+2;i++)
    {
        for(int j=0;j<ymax+2;j++)
        {
            matrix_old[i][j]=matrix[i][j];
        }
    }

}
void print_screen(void)
{

    clear_matrix();
    print_border();
    for (int i = 0; i < brojac_reaktor; i++)
    {
        //gotoxy (pos_reaktor[i], pos_reaktor[i + 1]);
        matrix[pos_reaktor[i]][pos_reaktor[i+1]]='!';
    }
    for (int i = 0; i < brojac_medic; i++)
    {
        //gotoxy (pos_medic[i], pos_medic[i + 1]);
        matrix[pos_medic[i]][pos_medic[i+1]]='+';
    }
    //gotoxy(pos[0], pos[1]);
    matrix[igrac_objekat_x.pozicija_x][igrac_objekat_x.pozicija_y]='X';
    if (igrac_objekat_x.energija < 0)
    {
        igrac_objekat_x.energija = 0;
    }
    //gotoxy(pos_o[0], pos_o[1]);
    matrix[igrac_objekat_o.pozicija_x][igrac_objekat_o.pozicija_y]='O';
    gotoxy(xmax+3,0);
    cout << "Tvoja energija je: " << igrac_objekat_x.energija << "       " << endl;
    gotoxy(xmax+3, 1);
    cout << "Protivnikova energija je: " << igrac_objekat_o.energija << "       " << endl;
    gotoxy(xmax+3, 2);
    cout << "Score: " << igrac_objekat_x.poeni << "       " << endl;
    if(metak_objekat.u_kretanju==true)
    {
       matrix[metak_objekat.pozicija_x][metak_objekat.pozicija_y]='*';
    }
    gotoxy(xmax+3,3);
    cout<<"Level: "<<level<<endl;
    print_matrix();
    return;
}
int igrica (int komanda)
{
    igrac_objekat_x.kretanje_igraca(komanda);
    igrac_objekat_o.target_x=igrac_objekat_x.pozicija_x;
    igrac_objekat_o.target_y=igrac_objekat_x.pozicija_y;
    igrac_objekat_o.kretanje_igraca(nista);
    if(komanda==pucanj_desno || komanda==pucanj_dole || komanda==pucanj_gore || komanda==pucanj_levo)
    {
        metak_objekat.ispali(igrac_objekat_x.pozicija_x,igrac_objekat_x.pozicija_y,komanda);
    }
    metak_objekat.kretanje();
    for (int i = 0; i < brojac_reaktor; i++)
    {
        if ((igrac_objekat_x.pozicija_x == pos_reaktor[i]) && (igrac_objekat_x.pozicija_y == pos_reaktor[i + 1]))
        {
            igrac_objekat_x.energija = igrac_objekat_x.energija + reaktor;
            for (int j = 0; j < brojac_reaktor; j++)
            {
                pos_reaktor[j] = rand() % xmax + 1;
                pos_reaktor[j + 1] = rand() % ymax + 1;
            }
            brojac_reaktor++;
            return res_reaktor;
        }
    }
    for (int i = 0; i < brojac_reaktor; i++)
    {
        if ((igrac_objekat_o.pozicija_x == pos_reaktor[i]) && (igrac_objekat_o.pozicija_y == pos_reaktor[i + 1]))
        {
            igrac_objekat_o.energija = igrac_objekat_o.energija + reaktor;
            for (int j = 0; j < brojac_reaktor; j++)
            {
                pos_reaktor[j] = rand() % xmax + 1;
                pos_reaktor[j + 1] = rand() % ymax + 1;
            }
            brojac_reaktor++;
            return res_reaktor;
        }
    }
    for (int i = 0; i < brojac_medic; i++)
    {
        if ((igrac_objekat_x.pozicija_x == pos_medic[i]) && (igrac_objekat_x.pozicija_y == pos_medic[i + 1]))
        {
            igrac_objekat_x.energija = igrac_objekat_x.energija + medic;
            for (int j = 0; j < brojac_medic; j++)
            {
                pos_medic[j] = rand() % xmax + 1;
                pos_medic[j + 1] = rand() % ymax + 1;
            }
            brojac_medic++;
            return res_medic;
        }
    }
    for (int i = 0; i < brojac_medic; i++)
    {
        if ((igrac_objekat_o.pozicija_x == pos_medic[i]) && (igrac_objekat_o.pozicija_y == pos_medic[i + 1]))
        {
            igrac_objekat_o.energija = igrac_objekat_o.energija + medic;
            for (int j = 0; j < brojac_medic; j++)
            {
                pos_medic[j] = rand() % xmax + 1;
                pos_medic[j + 1] = rand() % ymax + 1;
            }
            brojac_medic++;
            return res_medic;
        }
    }
    if(igrac_objekat_o.energija<=0)
    {
        igrac_objekat_x.poeni=igrac_objekat_x.poeni+50;
        igrac_objekat_o.energija=100;
        level++;
        igrac_objekat_o.ukupno_usporenje=igrac_objekat_o.ukupno_usporenje-10;
        igrac_objekat_o.pozicija_x = rand() % xmax + 1;
        igrac_objekat_o.pozicija_y = rand() % ymax + 1;
    }

    if (metak_objekat.pozicija_x == igrac_objekat_o.pozicija_x && metak_objekat.pozicija_y == igrac_objekat_o.pozicija_y)
    {
        igrac_objekat_o.usporenje = -20;
        metak_objekat.u_kretanju=false;
        igrac_objekat_o.energija=igrac_objekat_o.energija-10;
        igrac_objekat_x.poeni = igrac_objekat_x.poeni + 10;
    }
    if (igrac_objekat_o.usporenje >= igrac_objekat_o.ukupno_usporenje)
    {
        igrac_objekat_o.usporenje = 0;
    }
    if (igrac_objekat_x.pozicija_x == igrac_objekat_o.pozicija_x && igrac_objekat_x.pozicija_y == igrac_objekat_o.pozicija_y)
    {
        gameover();
    }
    return res_normal;
}
int main (int argc, char *argv[])
{
    srand(time(NULL));
    igrac_objekat_x.izgled='X';
    igrac_objekat_o.izgled='O';
    igrac_objekat_x.energija=200;
    igrac_objekat_o.energija=100;
    igrac_objekat_x.pozicija_x=0;
    igrac_objekat_x.pozicija_y=0;
    igrac_objekat_o.pozicija_x= rand() % xmax + 1;
    igrac_objekat_o.pozicija_y= rand() % ymax + 1;
    igrac_objekat_x.tip=human;
    igrac_objekat_o.tip=ai;

    pos_reaktor[0] = rand() % xmax + 1;
    pos_reaktor[1] = rand() % ymax + 1;
    pos_medic[0] = rand() % xmax + 1;
    pos_medic[1] = rand() % ymax + 1;
    //pos_o[0] = rand() % xmax + 1;
    //pos_o[1] = rand() % ymax + 1;
    pthread_t threads;
    long t;
    pthread_create(&threads, NULL, Muzika, (void *)t);
    int stanje = 0;
    char c;
    print_screen();
    while(1)
    {
        c = tipka();
        if (c == 'w')
        {
            stanje = igrica(gore);
        }
        else if (c == 'a')
        {
            stanje = igrica(levo);
        }
        else if (c == 's')
        {
            stanje = igrica(dole);
        }
        else if (c == 'd')
        {
            stanje = igrica(desno);
        }
        else if (c == 'l')
        {
            stanje = igrica(pucanj_desno);
        }
        else if(c=='j')
        {
                stanje = igrica(pucanj_levo);
        }
        else if(c=='i')
        {
                stanje = igrica(pucanj_gore);
        }
        else if(c=='k')
        {
            stanje = igrica(pucanj_dole);
        }
        else
        {
            stanje = igrica(nista);
            igrica(nista);
            c = 0;
        }
        if (c != 0)
        {
            if (stanje == res_reaktor)
            {
                ludzvuk();
            }
            if (stanje == res_medic)
            {
                dobarzvuk();
            }
        }
        if (igrac_objekat_x.energija <= 0)
        {
            break;
        }
    }
    gameover();
    pthread_exit(NULL);
}

