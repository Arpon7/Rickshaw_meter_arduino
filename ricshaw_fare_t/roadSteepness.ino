
float roadsteepness() {


  float steepnessFare;
  int priceSteepness = 100;

  float sum = 0;

  for (int i = 0; i < 100; i++) {
    mpu6050.update();

    float angle_x = mpu6050.getAngleX();

    float angle_y = mpu6050.getAngleY();

    float angle_z = mpu6050.getAngleZ();

    float steepness = sqrt(angle_x + angle_y + angle_z);


    sum = sum + steepness;

    delay(100);
  }

  float steepAvg = sum / 100;

  steepnessFare = steepAvg * priceSteepness;

  return steepnessFare;
}
