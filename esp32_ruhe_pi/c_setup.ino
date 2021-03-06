void setup()
{
  Wire.begin(21,22) // Wire.begin(SDA,SCL), set i2c to joy-it nodemcu i2c labeled pins, may fix IMU errors with non-adafruit boards
  Serial.begin(256000);
  /* Initialise the sensor */
  Serial.println(F("Adafruit AHRS Fusion Example")); Serial.println("");
  // Initialize the sensors.
  if (!gyro.begin())
  {
    /* There was a problem detecting the gyro ... check your connections */
    Serial.println("Ooops, no gyro detected ... Check your wiring!");
    while (1);
  }
  if (!accelmag.begin(ACCEL_RANGE_2G))
  {
    Serial.println("Ooops, no FXOS8700 detected ... Check your wiring!");
    while (1);
  }
  filter.begin(300);
  delay(300);
  ledcSetup(ledChannel, freq, resolution);   // configure LED PWM functionalitites
  ledcAttachPin(motorPin, ledChannel);   // attach the channel to the GPIO to be controlled
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW); // initialize controller off
  ledcWrite(ledChannel, nullPWM); // escon requires 10% PWM signal to activate
  ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  ads.begin();
  adc1_config_width(ADC_WIDTH_BIT_11);   //Range 0-2048
  adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11); //ADC_ATTEN_DB_11 = 0-3,6V
}
