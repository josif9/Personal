#include "pitches.h"

#define BUZZER_PIN 9

int melody[] = {
NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_C5, 
NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_B4, 
NOTE_A4, NOTE_G4, NOTE_E4, NOTE_B3, NOTE_C4, NOTE_B4, 

NOTE_A4, NOTE_G4, 
NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_C5, 
NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_B4, 
NOTE_A4, NOTE_G4, NOTE_F4, NOTE_CS4, NOTE_D4, NOTE_B4,
NOTE_A4, NOTE_G4, REST, 

NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_C5,
NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_B4,
NOTE_A4, NOTE_G4, NOTE_E4, NOTE_B3, NOTE_C4, NOTE_C5,
NOTE_C5,

NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_C5, 
NOTE_D5, NOTE_D5, NOTE_C5, NOTE_G4,
NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_C5,
NOTE_D5, NOTE_D5, NOTE_C5, NOTE_E5, NOTE_D5, 

NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_C5,
NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_B4, 
NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4,
NOTE_C5, REST, 
REST, REST, REST, REST
};

int durations[] = {
3, 8, 8, 8, 8, 8, 
3, 8, 8, 8, 8, 8, 
3, 8, 8, 8, 8, 8, 

2, 2,
3, 8, 8, 8, 8, 8,
3, 8, 8, 8, 8, 8, 
3, 8, 8, 8, 8, 8, 
2, 3, 4, 

3, 8, 8, 8, 8, 8, 
3, 8, 8, 8, 8, 8, 
3, 8, 8, 8, 8, 8, 
1,

8, 4, 8, 8, 4, 8, 
8, 4, 8, 2, 
8, 4, 8, 8, 4, 8, 
8, 4, 8, 4, 4, 

3, 8, 8, 8, 8, 8, 
3, 8, 8, 8, 8, 8, 
3, 8, 4, 4, 
2, 2,
2, 2, 2, 2
};

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 2000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.50;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}
