// AUTHOR: GUILLERMO PEREZ GUILLEN

#include <Arduino.h>
  #include <WiFi.h>
  #define LED_BUILTIN 2 // define the GPIO 2 as LED_BUILTIN  
  #define RELAY_PIN_1 15  // LAMP 1 
  #define RELAY_PIN_2 16  // LAMP 2 
  #define RELAY_PIN_3 17  // LAMP 3 
  #define RELAY_PIN_4 18  // LAMP 4
  #define RELAY_PIN_5 19  // LAMP 5 
  #define RELAY_PIN_6 21  // LAMP 6        

#include <fauxmoESP.h>
#define SERIAL_BAUDRATE 115200
#define WIFI_SSID "*********"
#define WIFI_PASS "************"
#define LAMP_1 "box" // 
#define LAMP_2 "breadboard" // 
#define LAMP_3 "bottle" // 
//#define LAMP_4 "lamp four" // 

fauxmoESP fauxmo;

// Wi-Fi Connection
void wifiSetup() {
  // Set WIFI module to STA mode
  WiFi.mode(WIFI_STA);

  // Connect
  Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // Wait
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  // Connected!
  Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}

void setup() {

  // Init serial port and clean garbage
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println();

  // Wi-Fi connection
  wifiSetup();

  // LED

  pinMode(LED_BUILTIN, OUTPUT); // initialize GPIO pin 2 LED_BUILTIN as an output.
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
  
  pinMode(RELAY_PIN_1, OUTPUT);
  digitalWrite(RELAY_PIN_1, LOW);

  pinMode(RELAY_PIN_2, OUTPUT);
  digitalWrite(RELAY_PIN_2, LOW);

  pinMode(RELAY_PIN_3, OUTPUT); 
  digitalWrite(RELAY_PIN_3, LOW); 
  
  pinMode(RELAY_PIN_4, OUTPUT); 
  digitalWrite(RELAY_PIN_4, LOW);

  pinMode(RELAY_PIN_5, OUTPUT); 
  digitalWrite(RELAY_PIN_5, LOW);

  pinMode(RELAY_PIN_6, OUTPUT); 
  digitalWrite(RELAY_PIN_6, LOW);      
  
  // By default, fauxmoESP creates it's own webserver on the defined port
  // The TCP port must be 80 for gen3 devices (default is 1901)
  // This has to be done before the call to enable()
  fauxmo.createServer(true); // not needed, this is the default value
  fauxmo.setPort(80); // This is required for gen3 devices

  // You have to call enable(true) once you have a WiFi connection
  // You can enable or disable the library at any moment
  // Disabling it will prevent the devices from being discovered and switched
  fauxmo.enable(true);

  // Add virtual devices
  fauxmo.addDevice(LAMP_1);
  fauxmo.addDevice(LAMP_2);
  fauxmo.addDevice(LAMP_3); 
//  fauxmo.addDevice(LAMP_4);

  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
    // Callback when a command from Alexa is received. 
    // You can use device_id or device_name to choose the element to perform an action onto (relay, LED,...)
    // State is a boolean (ON/OFF) and value a number from 0 to 255 (if you say "set kitchen light to 50%" you will receive a 128 here).
    // Just remember not to delay too much here, this is a callback, exit as soon as possible.
    // If you have to do something more involved here set a flag and process it in your main loop.
        
    Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);

////////// MOVE THE BOX //////////
    if ( (strcmp(device_name, LAMP_1) == 0) ) {
      Serial.println("RELAY 1 switched by Alexa");
      if (state) {
        digitalWrite(RELAY_PIN_1, HIGH);
        delay(1000);
        digitalWrite(RELAY_PIN_1, LOW);
      } else {
        digitalWrite(RELAY_PIN_2, HIGH);
        delay(1000);
        digitalWrite(RELAY_PIN_2, LOW);
      }
    }

////////// MOVE THE BOARD //////////    
    if ( (strcmp(device_name, LAMP_2) == 0) ) {
      Serial.println("RELAY 2 switched by Alexa");
      if (state) {
        digitalWrite(RELAY_PIN_3, HIGH);
        delay(1000);
        digitalWrite(RELAY_PIN_3, LOW);
      } else {
        digitalWrite(RELAY_PIN_4, HIGH);
        delay(1000);
        digitalWrite(RELAY_PIN_4, LOW); 
      }
    }

////////// MOVE THE BOTTLE WITH WATER //////////
    if ( (strcmp(device_name, LAMP_3) == 0) ) {
      Serial.println("RELAY 3 switched by Alexa");
      if (state) {
        digitalWrite(RELAY_PIN_5, HIGH);
        delay(1000);
        digitalWrite(RELAY_PIN_5, LOW);
      } else {
        digitalWrite(RELAY_PIN_6, HIGH);
        delay(1000);
        digitalWrite(RELAY_PIN_6, LOW);
      }
    }   
  });
}

void loop() {
  // fauxmoESP uses an async TCP server but a sync UDP server
  // Therefore, we have to manually poll for UDP packets
  fauxmo.handle();

  static unsigned long last = millis();
  if (millis() - last > 5000) {
    last = millis();
    Serial.printf("[MAIN] Free heap: %d bytes\n", ESP.getFreeHeap());
  }    
}
