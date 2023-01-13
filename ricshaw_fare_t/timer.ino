
uint16_t time() {

  uint16_t systemOnTime = millis();
  minutes = systemOnTime / 1000;
  return minutes;
}
