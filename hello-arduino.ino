int ledToggleTime;

void setup() {
  /* Initialize digital pin LED_BUILTIN as an output. */
  pinMode(LED_BUILTIN, OUTPUT);
  
  /* Configure serial port for 9600 bits/second. */
  Serial.begin(9600);

  /* Output program info and its menu. */
  Serial.println("|**************************************|");
  Serial.println("|**        Serial port demo          **|");
  Serial.println("|**************************************|");
  Serial.println("");
  Serial.println("  Enter LED toggle time:");
  Serial.println("");
  Serial.println("    1: 100 milliseconds");
  Serial.println("    2: 500 milliseconds");  
  Serial.println("");
  Serial.print("> ");

  /* Obtain user input. */
  bool entryValid = false;
  while (!entryValid) {
    /* Wait for reception of new data from the serial port. */
    while(!Serial.available()) { 
      ; 
    }
    /* Read out the received data as an integer value. */
    int option = Serial.parseInt();
    /* Process received menu option. */
    switch(option) {
      case 1:
        Serial.println(option);
        ledToggleTime = 100;
        entryValid = true;
        break;
      case 2:
        Serial.println(option);
        ledToggleTime = 500;
        entryValid = true;
        break;
    }
  }
}

void loop() {
  /* Toggle the LED with the selected time. */
  digitalWrite(LED_BUILTIN, HIGH);
  delay(ledToggleTime);
  digitalWrite(LED_BUILTIN, LOW);
  delay(ledToggleTime);
}
