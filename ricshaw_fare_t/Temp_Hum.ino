float tempHum() {

  float temperature, humidity;
  float sumT = 0;
  float sumAvg = 0;
  float sumH = 0;
  float sumAvg_h = 0;
  int price = 100;
  int price_h = 110;

  for (int i = 0; i < 100; i++) {

    temperature = dht.readTemperature();
    sumT = sumT + temperature;
  }
  sumAvg = sumT / 100;

  for (int j = 0; j < 100; j++) {
    humidity = dht.readHumidity();
    sumH = sumH + humidity;
  }
  sumAvg_h = sumH / 100;

  float x = sumAvg * price + sumAvg_h * price_h;

  return x;
}