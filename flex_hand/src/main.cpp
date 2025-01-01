#include "common_data.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>

void generateCoords(Subject subject, int coords[SERVOS_SIZE])
{
    srand(time(NULL)); // Инициализация генератора случайных чисел
    for(unsigned servo = 0; servo < SERVOS_SIZE; ++servo)
    {

        if(subject == SUBJECT_UNDEFINED)
        {
            coords[servo] = 100;    
        } else {
            const int coord = g_subjectPositions[subject][servo];

            const int min = coord - g_eps < 0 ? 0 : coord - g_eps;
            const int max = coord + g_eps > 180 ? 180 : coord + g_eps; 

            coords[servo] = min + rand() % (max - min + 1);
        } 
    }
}

unsigned writeCoords(const int outputCoords[SERVOS_SIZE])
{
  std::ofstream out{g_filepath};       // поток для записи
  if(!out.is_open())
  {
    std::cout << "Failed to write output coords\n";
    return 1;
  }
  for(unsigned servo = 0; servo < SERVOS_SIZE; ++servo)
  {
    out << outputCoords[servo] << "\n";
  }
  return 0;
}

unsigned play(Subject subject)
{
    int coords[SERVOS_SIZE];
    generateCoords(subject, coords);
    return writeCoords(coords);
}

int main(int argc, char *argv[])
{
    unsigned retCode = 1;
    if(argc > 1)
    {
        Subject subject = (Subject)std::stoi(argv[1]); 
        if(subject < SUBJECT_SIZE+1)
        {
            retCode = play(subject);
        } else {
            std::cout << "Wrong argument passed";
        }
    }
    return retCode;
}