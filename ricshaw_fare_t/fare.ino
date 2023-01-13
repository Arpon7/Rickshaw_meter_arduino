float fare() {

  //multiples
  int priceWindSpeed;


  //part by part fares

  float fareAvgWindSpeed = new_avg_wind_speed * priceWindSpeed;

  //total fare
  float totalFare = fareAvgWindSpeed + new_tempHum + new_steepness;

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Total Fare: ");
  lcd.setCursor(0, 2);
  lcd.print(totalFare);
}