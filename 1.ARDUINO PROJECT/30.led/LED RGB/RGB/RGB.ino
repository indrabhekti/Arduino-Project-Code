int red_light_pin = 11;
int green_light_pin = 10;
int blue_light_pin = 9;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
void loop() {
  RGB_color(255, 0, 0); // Red
  delay(1000);
  RGB_color(255, 125, 0); // orange
  delay(1000);
  RGB_color(255, 225, 0); // yellow
  delay(1000);
  RGB_color(125, 255, 0); // spring green
  delay(1000);
  RGB_color(0, 255, 0); // green
  delay(1000);
  RGB_color(0, 255, 125); // turquoise
  delay(1000);
  RGB_color(0, 255, 255); // cyan
  delay(1000);
  RGB_color(0, 125, 125); // ocean
  delay(1000);
  RGB_color(0, 0, 255); // blue
  delay(1000);
  RGB_color(125, 0, 255); // violet
  delay(1000);
  RGB_color(255, 0, 255); // magenta
  delay(1000);
  RGB_color(255, 0, 125); // raspberry
  delay(1000);


}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
