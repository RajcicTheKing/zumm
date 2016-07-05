#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum komande {levo, desno, gore, dole, nista, pucanj_desno, pucanj_levo, pucanj_dole, pucanj_gore};
enum result {res_reaktor, res_medic, res_normal};
const int reaktor = -20;
const int medic = 30;
const int pocetna_energija = 200;
const int kretanje = -5;
const int maks_broj_reaktora = 400;
const int maks_broj_medica = 400;
const int xmax = 20;
const int ymax = 20;
int pos_reaktor[maks_broj_reaktora * 2] = {1, 4};
int pos_medic[maks_broj_medica * 2] = {4, 1};
int pos[2] = {0,0};
int pos_m[2] = {xmax + 1, ymax + 1};
int energija = 100000;
int energija2 = 100;
int score = 0;
int brojac_medic = 1;
int brojac_reaktor = 1;
int pos_o[2] = {0,0};
int krajigre_promenljiva = 0;
int level=1;

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
    cout << "Game over, your score is " << score << ".";
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
void print_border(void)
{
    for(int i = xmax + 1; i>=0; i--)
    {
        gotoxy(i, ymax + 1);
        cout << "_";
    }
    for(int i = ymax + 1; i >= 0; i--)
    {
        gotoxy(xmax+1,i);
        cout << "|";
    }
}
void print_screen(void)
{
    clear_console();
    print_border();
    for (int i = 0; i < brojac_reaktor; i++)
    {
        gotoxy (pos_reaktor[i], pos_reaktor[i + 1]);
        cout << "!";
    }
    for (int i = 0; i < brojac_medic; i++)
    {
        gotoxy (pos_medic[i], pos_medic[i + 1]);
        cout << "+";
    }
    gotoxy(pos[0], pos[1]);
    cout << "X";
    if (energija < 0)
    {
        energija = 0;
    }
    gotoxy(pos_o[0], pos_o[1]);
    cout << "O";
    gotoxy(0, ymax + 2);
    cout << "Tvoja energija je: " << energija << endl;
    gotoxy(0, ymax + 3);
    cout << "Protivnikova energija je: " << energija2 << endl;
    gotoxy(0, ymax + 4);
    cout << "Score: " << score << endl;
    if (pos_m[0] <= xmax && pos_m[1] <= ymax && pos_m[0]>=0 && pos_m[1]>=0)
    {
        gotoxy(pos_m[0], pos_m[1]);
        cout << "*";
    }
    gotoxy(xmax+2,0);
    cout<<"Level: "<<level<<endl;
    return;
}

int igrica (int komanda)
{
    static int usporenje = 0;
    static int ukupno_usporenje = 8;
    static int metak_ispaljen_desno= 0;
    static int metak_ispaljen_levo=0;
    static int metak_ispaljen_dole=0;
    static int metak_ispaljen_gore=0;
    if (komanda == levo)
    {
        pos[0] -= 1;
        energija = energija + kretanje;
        print_screen();
    }
    if (komanda == desno)
    {
        pos[0] += 1;
        energija = energija + kretanje;
        print_screen();
    }
    if (komanda == gore)
    {
        pos[1] -= 1;
        energija = energija + kretanje;
        print_screen();
    }
    if (komanda == dole)
    {
        pos[1] += 1;
        energija = energija + kretanje;
        print_screen();
    }
    if (komanda == pucanj_desno)
    {
        metak_ispaljen_desno = 1;
        metak_ispaljen_dole=0;
        metak_ispaljen_gore=0;
        metak_ispaljen_levo=0;
    }
    if(komanda == pucanj_levo)
    {
        metak_ispaljen_levo=1;
        metak_ispaljen_desno=0;
        metak_ispaljen_gore=0;
        metak_ispaljen_dole=0;
    }
    if(komanda == pucanj_gore)
    {
        metak_ispaljen_gore=1;
        metak_ispaljen_desno=0;
        metak_ispaljen_dole=0;
        metak_ispaljen_levo=0;
    }
    if(komanda == pucanj_dole)
    {
        metak_ispaljen_dole=1;
        metak_ispaljen_desno=0;
        metak_ispaljen_gore=0;
        metak_ispaljen_levo=0;
    }
    if (metak_ispaljen_desno == 1)
    {
        pos_m[0]++;
    }
    if(metak_ispaljen_levo==1)
    {
        pos_m[0]--;
    }
    if(metak_ispaljen_dole==1)
    {
        pos_m[1]++;
    }
    if(metak_ispaljen_gore==1)
    {
        pos_m[1]--;
    }
    for (int i = 0; i < brojac_reaktor; i++)
    {
        if ((pos[0] == pos_reaktor[i]) && (pos[1] == pos_reaktor[i + 1]))
        {
            energija = energija + reaktor;
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
        if ((pos_o[0] == pos_reaktor[i]) && (pos_o[1] == pos_reaktor[i + 1]))
        {
            energija2 = energija2 + reaktor;
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
        if ((pos[0] == pos_medic[i]) && (pos[1] == pos_medic[i + 1]))
        {
            energija = energija + medic;
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
        if ((pos_o[0] == pos_medic[i]) && (pos_o[1] == pos_medic[i + 1]))
        {
            energija2 = energija2 + medic;
            for (int j = 0; j < brojac_medic; j++)
            {
                pos_medic[j] = rand() % xmax + 1;
                pos_medic[j + 1] = rand() % ymax + 1;
            }
            brojac_medic++;
            return res_medic;
        }
    }
    if(energija2<=0)
    {
        score=score+50;
        energija2=100;
        level++;
        ukupno_usporenje--;
        pos_o[0] = rand() % xmax + 1;
        pos_o[1] = rand() % ymax + 1;
    }
    if (pos[0] > xmax)
    {
        pos[0] = 0;
        print_screen();
    }
    if (pos[0] < 0)
    {
        pos[0] = xmax;
        print_screen();
    }
    if (pos[1] > ymax)
    {
        pos[1] = 0;
        print_screen();
    }
    if (pos[1] < 0)
    {
        pos[1] = ymax;
        print_screen();
    }
    if (pos_m[0] == pos_o[0] && pos_m[1] == pos_o[1])
    {
        usporenje = -20;
        metak_ispaljen_desno = 0;
        metak_ispaljen_dole=0;
        metak_ispaljen_gore=0;
        metak_ispaljen_levo=0;
        pos_m[0] = xmax + 1;
        pos_m[1] = ymax + 1;
        score = score + 10;
    }
    if (pos[0] != pos_o[0])
    {
        usporenje++;
        if (usporenje >= ukupno_usporenje)
        {
            if (pos[0] < pos_o[0])
            {
                pos_o[0]--;
            }
            else if (pos[0] > pos_o[0])
            {
                pos_o[0]++;
            }
        }
        print_screen();
    }
    if (pos[1] != pos_o[1])
    {
        usporenje++;
        if (usporenje >= ukupno_usporenje)
        {
            if (pos[1] < pos_o[1])
            {
                pos_o[1]--;
            }
            else if (pos[1] > pos_o[1])
            {
                pos_o[1]++;
            }
        }
        print_screen();

    }
    if (usporenje >= ukupno_usporenje)
    {
        usporenje = 0;
    }
    if (pos[0] == pos_o[0] && pos[1] == pos_o[1])
    {
        gameover();
    }
    return res_normal;
}

int main (int argc, char *argv[])
{
    srand(time(NULL));
    pos_reaktor[0] = rand() % xmax + 1;
    pos_reaktor[1] = rand() % ymax + 1;
    pos_medic[0] = rand() % xmax + 1;
    pos_medic[1] = rand() % ymax + 1;
    pos_o[0] = rand() % xmax + 1;
    pos_o[1] = rand() % ymax + 1;
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
            pos_m[0] = pos[0] + 1;
            pos_m[1] = pos[1];
            stanje = igrica(pucanj_desno);
        }
        else if(c=='j')
        {
            pos_m[0] = pos[0] - 1;
            pos_m[1] = pos[1];
            stanje = igrica(pucanj_levo);
        }
        else if(c=='i')
        {
            pos_m[0] = pos[0];
            pos_m[1] = pos[1]+1;
            stanje = igrica(pucanj_gore);
        }
        else if(c=='k')
        {
            pos_m[0] = pos[0];
            pos_m[1] = pos[1]-1;
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
            if (stanje == res_normal)
            {
                Beep(1000, 20);
            }
            if (stanje == res_reaktor)
            {
                ludzvuk();
            }
            if (stanje == res_medic)
            {
                dobarzvuk();
            }
            score++;
        }
        if (energija <= 0)
        {
            break;
        }
    }
    gameover();
    pthread_exit(NULL);
}

