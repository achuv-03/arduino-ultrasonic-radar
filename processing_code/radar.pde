import processing.serial.*;

Serial myPort;
String data;
int angle = 0;
int distance = 0;

void setup() {
  size(800, 600);
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  background(0);

  stroke(0,255,0);
  noFill();
  arc(width/2, height, width, width, PI, TWO_PI);

  float rad = radians(angle);
  float d = map(distance, 0, 200, 0, width/2);

  float x = width/2 + d*cos(rad);
  float y = height - d*sin(rad);

  fill(255,0,0);
  ellipse(x, y, 10, 10);
}

void serialEvent(Serial myPort) {
  data = myPort.readStringUntil('\n');
  if (data != null) {
    data = trim(data);
    String[] values = split(data, ',');

    if (values.length == 2) {
      angle = int(values[0]);
      distance = int(values[1]);
    }
  }
}
