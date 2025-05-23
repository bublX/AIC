#include "functions.h"
#include "structs.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

#define NAME "binfile20129.bin"
#define TIME "timefile.txt"

#define MASSIV
#ifdef MASSIVE
int main()  //main в котором объ€вл€ем массив структур на этапе инициализации
{
    flypas  HUMAN[21];

        strcpy(HUMAN[0].NUMfl, "123");
        strcpy(HUMAN[0].Fly, "01/09/2003");
        strcpy(HUMAN[0].FIO.F, "O'Neal");
        strcpy(HUMAN[0].FIO.I, "Shaquille");
        strcpy(HUMAN[0].FIO.O, "Rashaun");
        strcpy(HUMAN[0].NUMpl, "A01");
        strcpy(HUMAN[0].weight, "2");

        strcpy(HUMAN[1].NUMfl, "163");
        strcpy(HUMAN[1].Fly, "18/12/2019");
        strcpy(HUMAN[1].FIO.F, "Malkin");
        strcpy(HUMAN[1].FIO.I, "Evgeniy");
        strcpy(HUMAN[1].FIO.O, "Vladimirovich");
        strcpy(HUMAN[1].NUMpl, "A02");
        strcpy(HUMAN[1].weight, "15");

        strcpy(HUMAN[2].NUMfl, "164");
        strcpy(HUMAN[2].Fly, "20/12/2019");
        strcpy(HUMAN[2].FIO.F, "Buzova");
        strcpy(HUMAN[2].FIO.I, "Olga");
        strcpy(HUMAN[2].FIO.O, "Igorevna");
        strcpy(HUMAN[2].NUMpl, "B03");
        strcpy(HUMAN[2].weight, "20");

        strcpy(HUMAN[3].NUMfl, "165");
        strcpy(HUMAN[3].Fly, "22/12/2019");
        strcpy(HUMAN[3].FIO.F, "Nagiev");
        strcpy(HUMAN[3].FIO.I, "Dmitry");
        strcpy(HUMAN[3].FIO.O, "Vladimirovich");
        strcpy(HUMAN[3].NUMpl, "C04");
        strcpy(HUMAN[3].weight, "18");

        strcpy(HUMAN[4].NUMfl, "166");
        strcpy(HUMAN[4].Fly, "24/12/2019");
        strcpy(HUMAN[4].FIO.F, "Artemev");
        strcpy(HUMAN[4].FIO.I, "Nikita");
        strcpy(HUMAN[4].FIO.O, "Konstantinovich");
        strcpy(HUMAN[4].NUMpl, "D05");
        strcpy(HUMAN[4].weight, "22");

        strcpy(HUMAN[5].NUMfl, "167");
        strcpy(HUMAN[5].Fly, "26/12/2019");
        strcpy(HUMAN[5].FIO.F, "Agokosaskaya");
        strcpy(HUMAN[5].FIO.I, "Veranichka");
        strcpy(HUMAN[5].FIO.O, "Konstantinovnadadada");
        strcpy(HUMAN[5].NUMpl, "E06");
        strcpy(HUMAN[5].weight, "25");

        strcpy(HUMAN[5].NUMfl, "167");
        strcpy(HUMAN[5].Fly, "26/12/2019");
        strcpy(HUMAN[5].FIO.F, "Agokosaskaya");
        strcpy(HUMAN[5].FIO.I, "Veranichka");
        strcpy(HUMAN[5].FIO.O, "Konstantinovnadadada");
        strcpy(HUMAN[5].NUMpl, "E06");
        strcpy(HUMAN[5].weight, "25");

        strcpy(HUMAN[7].NUMfl, "168");
        strcpy(HUMAN[7].Fly, "27/12/2024");
        strcpy(HUMAN[7].FIO.F, "Ivanov");
        strcpy(HUMAN[7].FIO.I, "Ivan");
        strcpy(HUMAN[7].FIO.O, "Ivanovich");
        strcpy(HUMAN[7].NUMpl, "B04");
        strcpy(HUMAN[7].weight, "10");

        strcpy(HUMAN[8].NUMfl, "169");
        strcpy(HUMAN[8].Fly, "28/12/2024");
        strcpy(HUMAN[8].FIO.F, "Petrov");
        strcpy(HUMAN[8].FIO.I, "Petr");
        strcpy(HUMAN[8].FIO.O, "Petrovich");
        strcpy(HUMAN[8].NUMpl, "C05");
        strcpy(HUMAN[8].weight, "12");

        strcpy(HUMAN[9].NUMfl, "170");
        strcpy(HUMAN[9].Fly, "29/12/2024");
        strcpy(HUMAN[9].FIO.F, "Sidorov");
        strcpy(HUMAN[9].FIO.I, "Sidor");
        strcpy(HUMAN[9].FIO.O, "Sidorovich");
        strcpy(HUMAN[9].NUMpl, "D06");
        strcpy(HUMAN[9].weight, "14");

        strcpy(HUMAN[10].NUMfl, "171");
        strcpy(HUMAN[10].Fly, "30/12/2024");
        strcpy(HUMAN[10].FIO.F, "Kuznetsov");
        strcpy(HUMAN[10].FIO.I, "Alexey");
        strcpy(HUMAN[10].FIO.O, "Sergeevich");
        strcpy(HUMAN[10].NUMpl, "E07");
        strcpy(HUMAN[10].weight, "16");

        strcpy(HUMAN[11].NUMfl, "172");
        strcpy(HUMAN[11].Fly, "31/12/2024");
        strcpy(HUMAN[11].FIO.F, "Smirnov");
        strcpy(HUMAN[11].FIO.I, "Dmitry");
        strcpy(HUMAN[11].FIO.O, "Andreevich");
        strcpy(HUMAN[11].NUMpl, "F08");
        strcpy(HUMAN[11].weight, "18");

        strcpy(HUMAN[12].NUMfl, "173");
        strcpy(HUMAN[12].Fly, "01/01/2025");
        strcpy(HUMAN[12].FIO.F, "Popov");
        strcpy(HUMAN[12].FIO.I, "Sergey");
        strcpy(HUMAN[12].FIO.O, "Viktorovich");
        strcpy(HUMAN[12].NUMpl, "G09");
        strcpy(HUMAN[12].weight, "20");

        strcpy(HUMAN[13].NUMfl, "174");
        strcpy(HUMAN[13].Fly, "02/01/2025");
        strcpy(HUMAN[13].FIO.F, "Volkov");
        strcpy(HUMAN[13].FIO.I, "Andrey");
        strcpy(HUMAN[13].FIO.O, "Nikolaevich");
        strcpy(HUMAN[13].NUMpl, "H10");
        strcpy(HUMAN[13].weight, "22");

        strcpy(HUMAN[14].NUMfl, "175");
        strcpy(HUMAN[14].Fly, "03/01/2025");
        strcpy(HUMAN[14].FIO.F, "Kozlov");
        strcpy(HUMAN[14].FIO.I, "Vladimir");
        strcpy(HUMAN[14].FIO.O, "Alexandrovich");
        strcpy(HUMAN[14].NUMpl, "I11");
        strcpy(HUMAN[14].weight, "24");

        strcpy(HUMAN[15].NUMfl, "176");
        strcpy(HUMAN[15].Fly, "04/01/2025");
        strcpy(HUMAN[15].FIO.F, "Lebedev");
        strcpy(HUMAN[15].FIO.I, "Pavel");
        strcpy(HUMAN[15].FIO.O, "Dmitrievich");
        strcpy(HUMAN[15].NUMpl, "J12");
        strcpy(HUMAN[15].weight, "26");

        strcpy(HUMAN[16].NUMfl, "177");
        strcpy(HUMAN[16].Fly, "05/01/2025");
        strcpy(HUMAN[16].FIO.F, "Sokolov");
        strcpy(HUMAN[16].FIO.I, "Alexander");
        strcpy(HUMAN[16].FIO.O, "Pavlovich");
        strcpy(HUMAN[16].NUMpl, "K13");
        strcpy(HUMAN[16].weight, "28");

        strcpy(HUMAN[17].NUMfl, "178");
        strcpy(HUMAN[17].Fly, "06/01/2025");
        strcpy(HUMAN[17].FIO.F, "Novikov");
        strcpy(HUMAN[17].FIO.I, "Nikolay");
        strcpy(HUMAN[17].FIO.O, "Sergeevich");
        strcpy(HUMAN[17].NUMpl, "L14");
        strcpy(HUMAN[17].weight, "30");

        strcpy(HUMAN[18].NUMfl, "179");
        strcpy(HUMAN[18].Fly, "07/01/2025");
        strcpy(HUMAN[18].FIO.F, "Morozov");
        strcpy(HUMAN[18].FIO.I, "Viktor");
        strcpy(HUMAN[18].FIO.O, "Ivanovich");
        strcpy(HUMAN[18].NUMpl, "M15");
        strcpy(HUMAN[18].weight, "32");

        strcpy(HUMAN[18].NUMfl, "179");
        strcpy(HUMAN[18].Fly, "07/01/2025");
        strcpy(HUMAN[18].FIO.F, "Morozov");
        strcpy(HUMAN[18].FIO.I, "Viktor");
        strcpy(HUMAN[18].FIO.O, "Ivanovich");
        strcpy(HUMAN[18].NUMpl, "M15");
        strcpy(HUMAN[18].weight, "32");

        strcpy(HUMAN[20].NUMfl, "181");
        strcpy(HUMAN[20].Fly, "09/01/2025");
        strcpy(HUMAN[20].FIO.F, "Golubev");
        strcpy(HUMAN[20].FIO.I, "Roman");
        strcpy(HUMAN[20].FIO.O, "Alexeevich");
        strcpy(HUMAN[20].NUMpl, "O17");
        strcpy(HUMAN[20].weight, "36");



    FillMassive(HUMAN, NAME, sizeof(HUMAN)/sizeof(*HUMAN));
    menu(NAME);
    return 0;
}
#else
int main() //main в котором пользуемс€ функци€ми заполнени€ файла
{
    menu(NAME, TIME);
    return 0;
}
#endif
