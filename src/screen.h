#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>

class Screen {
    public:
        Screen();
        ~Screen();

        void init();
        void showTemperature(float temperature);
        void showOn();
        void showOff();

    private:


        int toggle1 = 18;
        int toggle2 = 16;
        int toggle3 = 17;

        int ledA = 7;
        int ledB = 9;
        int ledC = 10;
        int ledD = 15;
        int ledE = 14;
        int ledF = 13;
        int ledG = 12;
        int dotLed = 11;
        int groundedbutton = 6;
        
        std::vector<std::vector<int>> ledNumbers;
        std::vector<int> ledRow;

        void showNumber(int display, int numberToShow, int enableDot);
};

#endif// SCREEN_H