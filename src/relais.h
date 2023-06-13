#ifndef RELAIS_H
#define RELAIS_H

class Relais {
    public:
        Relais();
        ~Relais();

        void init();
        void setState(int state);

    private:
        int relaisPin = 5;
        
};

#endif// RELAIS_H