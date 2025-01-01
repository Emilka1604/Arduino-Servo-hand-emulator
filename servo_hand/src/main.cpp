#include <math.h>
#include <iostream>
#include <fstream>
#include <unistd.h> // Для usleep
#include "common_data.h"                                                 

Subject detectSubject(const int positions[SERVOS_SIZE])
{
  for(unsigned subject = 0; subject < SUBJECT_SIZE; ++subject)
  {
    unsigned isSubject = 1;
    for(unsigned servo = 0; servo < SERVOS_SIZE; ++servo)
    {
        if(abs(positions[servo] - g_subjectPositions[subject][servo]) > g_eps)
        {
            isSubject = 0;
            break;
        }
    }
    if(isSubject == 1)
    {
        return (Subject)subject;
    }
  }
  return SUBJECT_UNDEFINED;
}    

unsigned readCoords(int inputCoords[SERVOS_SIZE])
{
  std::ifstream in{g_filepath};       // поток для чтения
  if(!in.is_open())
  {
    std::cout << "Failed to read input coords";
    return 1;
  }
  for(unsigned servo = 0; servo < SERVOS_SIZE; ++servo)
  {
      in >> inputCoords[servo];
  }
  return 0;
}

void writeCords(const int outputCoords[SERVOS_SIZE])
{
  for(unsigned servo = 0; servo < SERVOS_SIZE; ++servo)
  {
      std::cout << outputCoords[servo] << " ";
  }
  std::cout << "\n";
}

void play()
{
  srand(time(NULL)); // Инициализация генератора случайных чисел

  const unsigned subject = rand() % SUBJECT_SIZE;

  std::cout << "Servo hand answer: " << g_subjectNames[subject] << "\n";

  writeCords(g_subjectPositions[subject]);

}

void loop()
{
  unsigned delay = 100000; //microsec

  int inputCoords[SERVOS_SIZE];

  Subject lastSubject = SUBJECT_UNDEFINED;

  while(readCoords(inputCoords) == 0)
  {
    Subject subject = detectSubject(inputCoords);

    if(subject != lastSubject)
    {
      if(subject == SUBJECT_UNDEFINED)
      {
        writeCords(inputCoords);
      } else {
        std::cout << "Flex hand: " << g_subjectNames[subject] << "\n";
        play();
      }
      lastSubject = subject;
      std::cout << "\n\n";
    }

    usleep(delay);
  }
}

int main()
{
    loop();
    return 0;
}