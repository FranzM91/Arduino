#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Conexion Internet
#define WIFI_SSID "Wifi_Home"
#define WIFI_PASSWORD "asdfklmasdf123"

//Firebase
#define FIREBASE_HOST "arduino-serverless-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "secreto de la base de datos"

// Variables de entorno
byte ledP = B1;
byte soundP = A0;
byte thresshold = 200;

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print(".");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Se ha conectado con la ip: ");
  Serial.println(WiFi.localIP());

  //Conexion a Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  //Inicializacion IO
  pinMode(ledP, OUTPUT);
  pinMode(soundP, INPUT);
}

void loop() {
  int soundVal = analogRead(soundP);
  // Save
  Serial.print(soundVal);
  if (soundVal >= threshold) {
    Serial.print(soundVal);
    Firebase.set("/FirebaseDB/bigosund", soundVal);
    digitalWrite(ledP, HIGH);

    if(Firebase.failed()){
      Serial.print("Fallo la escritura en /bidSound");
      Serial.println(Firebaseerror());
    }
  } else {
    digitalWrite(ledP, LOW);
  }
  // Get
  Serial.print("El valos de bigsound es:");
  Serial.println(Firebase.getInt("/FirebaseDB/bigSound"));
  delay(1000);

  //Remove
  Firebase.remove("/FirebaseDB/bigSound");
}
