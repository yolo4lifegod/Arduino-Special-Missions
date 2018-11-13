char solve = 0;

void setup() {
  int fin, a, b, c, d, e, f, g, h, i, j, k, l = 0;
  Serial.begin(9600);
  
  Serial.println("|a b c| |x|   |j|");
  Serial.println("|d e f| |y| = |k|");
  Serial.println("|g h i| |z|   |l|");
  
  Serial.println("a = ");
  a = Serial.read();
  Serial.print(a);
  Serial.println("b = ");
  b = Serial.read();
  Serial.print(b);
  Serial.println("c = ");
  c = Serial.read();
  Serial.print(c);
  Serial.println("d = ");
  d = Serial.read();
  Serial.print(d);
  Serial.println("e = ");
  e = Serial.read();
  Serial.print(e);
  Serial.println("f = ");
  f = Serial.read();
  Serial.print(f);
  Serial.println("g = ");
  g = Serial.read();
  Serial.print(g);
  Serial.println("h = ");
  h = Serial.read();
  Serial.print(h);
  Serial.println("i = ");
  i = Serial.read();
  Serial.print(i);
  Serial.println("j = ");
  j = Serial.read();
  Serial.print(j);
  Serial.println("k = ");
  k = Serial.read();
  Serial.print(k);
  Serial.println("l = ");
  l = Serial.read();
  Serial.print(l);
  
  Serial.println("What would you like to solve for? (x, y, or z)");
  String solve = Serial.readString();

  delay(1000);
  Serial.write(12);

  if(solve == "x"){
    Serial.print("Solving for Determinant of: ");
    Serial.println("|j b c|");
    Serial.println("|k e f|  or");
    Serial.println("|l h i|");
    Serial.println(" ");
    
    Serial.println("|");    // Line 1
    Serial.print(j);
    Serial.print(" ");
    Serial.print(b);
    Serial.print(" ");
    Serial.print(c);
    Serial.print("|");

    Serial.println("|");    // Line 2
    Serial.print(k);
    Serial.print(" ");
    Serial.print(e);
    Serial.print(" ");
    Serial.print(f);
    Serial.print("|");

    Serial.println("|");    // Line 3
    Serial.print(l);
    Serial.print(" ");
    Serial.print(h);
    Serial.print(" ");
    Serial.print(i);
    Serial.print("|");

    Serial.println(" ");
    Serial.println("Rendering...");
    Serial.println(" ");
    delay(1000);
    
    fin = ((j*e*i)+(b*f*l)+(c*k*h)) - ((c*e*l)+(b*k*i)+(j*f*h));

    Serial.println("x = ");
    Serial.print(fin);
  }
}

void loop() {
  
}
