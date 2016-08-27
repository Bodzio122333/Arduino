#include <SimpleSDAudio.h>
void setup()
{ 
  // SdPlay.setSDCSPin(10); // Enable if your SD card CS-Pin is not at Pin 4... 
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
  SdPlay.setFile("EXAMPLE.AFM"); 
  SdPlay.play();
}
 
void loop(void) {
}
