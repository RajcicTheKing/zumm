#ifndef IGRAC_H
#define IGRAC_H


class Igrac
{
    public:
        int target_x;
        int target_y;
        int pozicija_x;
        int pozicija_y;
        char izgled;
        int tip;
        int poeni;
        int energija_kretanja;
        void kretanje_igraca(int);
        int energija;
        int ukupno_usporenje;
        int usporenje;




        Igrac();
        virtual ~Igrac();

    protected:

    private:
        void kretanje_ai(void);

};

#endif // IGRAC_H
