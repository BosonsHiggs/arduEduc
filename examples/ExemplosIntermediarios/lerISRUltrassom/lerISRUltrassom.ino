const byte trig = 8;
const byte echo = 9;
volatile unsigned long distancia = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(echo), ultrassom_frente, HIGH);
}

void distanciaExibir(int dist)
{
     float dist_ = float(dist)/58.0;
      Serial.println(dist_);
}

int distanciaUltra()
{
     delayMicroseconds(5);
     digitalWrite(trig, HIGH);
     delayMicroseconds(10);
     digitalWrite(trig, LOW);
     
     distancia = pulseIn(echo, HIGH); //microsegundos
}

void ultrassom_frente()
{
  if (distanciaUltra() > 0) distanciaExibir(distancia);
}

void loop() {}
