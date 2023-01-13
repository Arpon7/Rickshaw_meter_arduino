
float windSpeed() {

  int rotation_count = 0;  // variable to store the number of rotations


  float wind_speed = 0;
  float sum = 0;
  int val = 0;

  if (digitalRead(IR_sensor_pin) == LOW) {  // if the IR sensor detects an object
    rotation_count++;                       // increase the rotation count by 1
  }

  // Calculate the wind speed in km/h using the following formula:
  // wind_speed = (rotation_count * circumference of the object * 0.62137) / (time elapsed * 0.0036)


  for (val = 0; val <= 100; val++) {
    wind_speed = (rotation_count * 3.14 * 2 * 0.62137) / (millis() * 0.0036);
    sum = sum + wind_speed;
  }

  float avg_wind_speed = sum / 100;
  return avg_wind_speed;
}
