#include <string>

enum Servos
{
  LITTLE = 0, //Мизинец
  NAMELESS = 1, //Безымянный
  MIDDLE = 2, //Средний
  POINTING = 3, //Указательный
  BIG = 4 //Большой
};

enum Subject
{
  STONE = 0, //Камень
  SCISSORS = 1, //Ножницы
  PAPER = 2, //Бумага
  SUBJECT_UNDEFINED = 3
};

typedef enum Subject Subject;

#define SUBJECT_SIZE 3
#define SERVOS_SIZE 5 

inline const int g_subjectPositions[SUBJECT_SIZE][SERVOS_SIZE] = {{180, 180, 180, 180, 180},
                                                                        {180, 180, 0, 0, 180},
                                                                        {0, 0, 0, 0, 0}};

inline const std::string g_filepath = "/home/esharipov/esharipov/workspace/progects/servo_hand_emulator/servo_coords.txt";
inline const int g_eps = 30;
inline const char* g_subjectNames[SUBJECT_SIZE+1] = {"Stone", "Scissors", "Paper"};     