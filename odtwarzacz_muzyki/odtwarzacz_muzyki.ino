#include <SimpleSDAudio.h>
#define buttonPin 2

int aktualna = 1;
int aktualna1 = 1;

void setup()
{
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
  attachInterrupt(0, przerwanie, FALLING);
}

void przerwanie() {
  switch (aktualna) {
    case 1:
      aktualna = 2;
      break;
    case 2:
      aktualna = 3;
      break;
    case 3:
      aktualna = 4;
      break;
    case 4:
      aktualna = 5;
      break;
    case 5:
      aktualna = 1;
      break;
  }
  aktualna1 = aktualna;
  SdPlay.stop();
}

void loop(void) {
  if (aktualna1 != 0) {
    SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
  }
  switch (aktualna1) {
    case 1:
      SdPlay.setFile("1.AFM"); SdPlay.play();
      aktualna1 = 0;
      break;
    case 2:
      SdPlay.setFile("2.AFM"); SdPlay.play();
      aktualna1 = 0;
      break;
    case 3:
      SdPlay.setFile("3.AFM"); SdPlay.play();
      aktualna1 = 0;
      break;
    case 4:
      SdPlay.setFile("4.AFM"); SdPlay.play();
      aktualna1 = 0;
      break;
    case 5:
      SdPlay.setFile("5.AFM"); SdPlay.play();
      aktualna1 = 0;
      break;
  }
  
}
