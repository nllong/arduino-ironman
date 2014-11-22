// Author: Nicholas Long

// Simple program to flash the lights upon a button push. Also glows a
// glass cube at random intervals.


// Initialize the pins
const int BUTTON_PIN = 2;
const int TESSA_BLUE_PIN = 3;
const int TESSA_RED_PIN = 5;
const int TESSA_GREEN_PIN = 6;
const int IM_BLUE_PIN = 9;
const int IM_RED_PIN = 10;
const int IM_GREEN_PIN = 11;

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(TESSA_RED_PIN, OUTPUT);
  pinMode(TESSA_GREEN_PIN, OUTPUT);
  pinMode(TESSA_BLUE_PIN, OUTPUT);
  pinMode(IM_RED_PIN, OUTPUT);
  pinMode(IM_GREEN_PIN, OUTPUT);
  pinMode(IM_BLUE_PIN, OUTPUT);
}

void loop()
{
  int buttonState;

  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH)
  {
    //  int buttonState;
    int x;
    int greenColor;
    int x_init;
    int x_final;
    int delay_init;
    int delay_final;
    int whiteAmount;
    int fadeIn;

    // Over 2 seconds fade in the Iron Man eyes
    for (x = 100; x < 1; x--){
      fadeIn = ((100 - x) / 100);
      analogWrite(IM_RED_PIN, 255 * fadeIn);
      analogWrite(IM_GREEN_PIN, 255 * fadeIn);
      analogWrite(IM_BLUE_PIN, 35 * fadeIn);
      delay(20);
    }

    analogWrite(IM_RED_PIN, 255);
    analogWrite(IM_GREEN_PIN, 255);
    analogWrite(IM_BLUE_PIN, 35);

    analogWrite(TESSA_RED_PIN, 0);
    analogWrite(TESSA_GREEN_PIN, 0);
    analogWrite(TESSA_BLUE_PIN, 255);

    x_init = random(10,200);
    delay_init = random(1,8);
    whiteAmount = random(0,100);
    for (x = x_init; x < 255; x++){
      analogWrite(TESSA_RED_PIN, whiteAmount);
      analogWrite(TESSA_GREEN_PIN, whiteAmount);
      analogWrite(TESSA_BLUE_PIN, x);
      delay(delay_init);
    }
    delay_final = random(1,8);
    x_final = random(10,200);
    for (x = 255; x > x_final; x--){
      analogWrite(TESSA_RED_PIN, whiteAmount);
      analogWrite(TESSA_GREEN_PIN, whiteAmount);
      analogWrite(TESSA_BLUE_PIN, x);
      delay(delay_final);
    }


    //    for (x = 0; x < 255; x++){
    //      analogWrite(TESSA_BLUE_PIN, 0);
    //      analogWrite(TESSA_RED_PIN, x);
    //      greenColor = 255 - x;
    //      analogWrite(TESSA_GREEN_PIN, greenColor);
    //      delay(10);
    //    }
    //    delay(1000);
  }
  else
  {
    //flashIronMan(0);
    flashIronMan(1);
  }
}

void flashIronMan(int object)
{
  int r;
  int g;
  int b;
  int flashDelay;
  int x;

  if (object == 0) {
    r = TESSA_RED_PIN;
    g = TESSA_GREEN_PIN;
    b = TESSA_BLUE_PIN;
  }
  else {
    r = IM_RED_PIN;
    g = IM_GREEN_PIN;
    b = IM_BLUE_PIN;
  }


  flashDelay = 200;

  for (x = 0; x < 5; x++) {
    analogWrite(r, 0);
    analogWrite(g, 0);
    analogWrite(b, 255);
    delay(flashDelay);
    analogWrite(r, 255);
    analogWrite(g, 0);
    analogWrite(b, 0);
    delay(flashDelay);
  }
}
