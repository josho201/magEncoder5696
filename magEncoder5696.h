class magEncoder5696 {
public:
  magEncoder5696(int sensorPin, int sensorPin2);
  void begin();
  double getPosition();
  double getAngle();
private:
  int pin;
  int pin2;
  double desplazamiento = 0;
  double vueltas;
  float lastangle = 0.0;
  bool first_run = true;
};

magEncoder5696::magEncoder5696(int sensorPin, int sensorPin2) {
  pin = sensorPin;
  pin2 = sensorPin2;
}

void magEncoder5696::begin() {
}

double magEncoder5696::getAngle() {
  float sensorValue1 = (((analogRead(pin) - 175) / 691.0) * 2) - 1;   // mapear de -1 a 1
  float sensorValue2 = (((analogRead(pin2) - 175) / 691.0) * 2) - 1;  // mapear de -1 a 1

  // calcular el angulo en radianes y convertirlo a grados
  float angle = atan2(sensorValue1, sensorValue2) * (180 / PI) + 180;

  return angle;
}

double magEncoder5696::getPosition(){

  double angle = getAngle();
  if (first_run) {
    vueltas = angle / 360.0;
    first_run = false;
  }

  if (abs(lastangle - angle) > .1) {

    double desplazamientoinmediato = angle - lastangle;

    if (abs(desplazamientoinmediato) < 330) {
      desplazamiento += desplazamientoinmediato;
      vueltas = desplazamiento / 360.0;
    }
    lastangle = angle;
  }

  return vueltas;
}