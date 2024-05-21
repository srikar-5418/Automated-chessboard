#define step1 5
#define dir1 4
#define step2 3
#define dir2 2
#define magnet 6
int c=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(step1,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(step2,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(magnet,OUTPUT);

}
//dir HIGH- clockwise, LOW- anti-clockwise

//Horizontal Right- dir1-HIGH dir2-HIGH
//Horizontal Left - dir1-LOW  dir2-LOW
//Vertical top    - dir1-LOW  dir2-HIGH
//Vertical bottom - dir1-HIGH dir2-LOW
//Top Right       - dir1-LOW
//Bottom Left     - dir1-HIGH
//Top Left        -           dir2-HIGH
//Bottom Right    -           dir2-LOW


void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    c=Serial.readString().toInt();
    Serial.println(c);
  

  switch(c)
  {
    //Pawn
    case 1:
    {
      digitalWrite(magnet,HIGH);
      //The Pawn piece will be placed at the top right corner of the table 
      //The first step will be to move the magnet to the top and then move it to right
      //If it's not possible to place the pieces and retrieve them then comment out the code from here
      int pawnloc=600;//The steps is assumed as 800 but we can change it as per practical conditions 
      //Top movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(pawnloc);
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(pawnloc);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(pawnloc);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(pawnloc);
      //This is the end of retrieving the piece from its initial location if not possible you can comment from above till here
      //From now on it's the actual movement of the pawn
      //Pawn has a single move which is to move forward 
      int pm=200;//you can change the distance as per requirements
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(pm);
      delay(300);

      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(pm);
      delay(300);

      //This is the end of pawn movement
      //From here is putting the pawn back in it's original position
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(pawnloc);
      delay(300);

      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(pawnloc);
      digitalWrite(magnet,LOW);
      delay(300);

      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(pawnloc);
      delay(300);

      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(pawnloc);
      delay(300);

      //This is the end of pawn movement
      break;
    }
    case 2:
    {
      digitalWrite(magnet,HIGH);
      //Second piece is the Rook which is placed on the end of Horizontal Right
      //From here is getting the piece
      int rookloc=600;
      //Right Move6ment
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(rookloc);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(rookloc);
      //From here on it's the movement of Rook
      int rm=500;
      //First is Horizontal Right
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(rm);
      delay(300);

      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(rm);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(rm);
      delay(300);

      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(rm);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(rm);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(rm);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(rm);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(rm);
      //This is the end of movement of Rook now putting it back in it's initial position
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(rookloc);
      digitalWrite(magnet,LOW);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(rookloc);

      break;

    }
    case 3:
    {
      //Third is Bishop
      digitalWrite(magnet,HIGH);
      //It is located at bottom right
      int bisloc=600;
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(bisloc);
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(bisloc);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(bisloc);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(bisloc);
      //End of Getting the piece
      //Top Right
      int bm=650;
      digitalWrite(dir1,LOW);
      for(int x = 0; x < bm; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      delay(1000);
      //Bottom Left
      digitalWrite(dir1,HIGH);
      for(int x = 0; x < bm; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      delay(1000);
      //Bottom Left
      digitalWrite(dir1,HIGH);
      for(int x = 0; x < bm; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      delay(1000);
      //Top Right
      digitalWrite(dir1,LOW);
      for(int x = 0; x < bm; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      //Bottom Right
      digitalWrite(dir2,LOW);
      for(int x = 0; x < bm; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      delay(1000);
      //Top Left
      digitalWrite(dir2,HIGH);
      for(int x = 0; x < bm; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      delay(1000);
      //Top Left
      digitalWrite(dir2,HIGH);
      for(int x = 0; x < bm; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      delay(1000);
      //Bottom Right
      digitalWrite(dir2,LOW);
      for(int x = 0; x < bm; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      //Puttin piece back
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(bisloc);
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(bisloc);

      digitalWrite(magnet,LOW);

      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(bisloc);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(bisloc);

      break;

    }
    case 4:
    {
      //Fourth is Knight
      digitalWrite(magnet,HIGH);
      //Getting piece
      int kniloc=600;
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(kniloc);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(kniloc);
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(kniloc);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(kniloc);
      //movements
      int fm=400; int sm=200;
      //Left
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(fm);
      //Bottom
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(sm);
      //Top
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(sm);
      //Right
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(fm);
      //second movement
      //Bottom
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(fm);
      //Right
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(sm);
      //Left
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(sm);
      //Top
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(fm);
      //Third Movement
      //Right
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(fm);
      //Top
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(sm);
      //Bottom
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(sm);
      //Left
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(fm);
      //Fourth Movement
      //Top
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(fm);
      //Left
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(sm);
      //Right
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(sm);
      //Bottom
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(fm);
      //Puttin the piece back
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(kniloc);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(kniloc);

      digitalWrite(magnet,LOW);

      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(kniloc);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(kniloc);
      
      break;

    }
    case 5:
    {
      //Fifth piece is queen
      //Quuen is placed at the end of Horizontal Left
      digitalWrite(magnet,HIGH);
      int queloc=600;
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(queloc);
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(queloc);
      //Now the First move is horizontal and veritical ie Rook
      //First is Horizontal Right
      int qm=500;
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(qm);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(qm);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(qm);
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(qm);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(qm);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(qm);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(qm);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(qm);
      //Next is Bishop Movement
      int qm2=600;
      //Top Right
      int bm=600;
      digitalWrite(dir1,LOW);
      for(int x = 0; x < qm2; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      delay(1000);
      //Bottom Left
      digitalWrite(dir1,HIGH);
      for(int x = 0; x < qm2; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      delay(1000);
      //Bottom Left
      digitalWrite(dir1,HIGH);
      for(int x = 0; x < qm2; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      //delay(1000);
      //Top Right
      digitalWrite(dir1,LOW);
      for(int x = 0; x < qm2; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      //Bottom Right
      digitalWrite(dir2,LOW);
      for(int x = 0; x < qm2; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      //delay(1000);
      //Top Left
      digitalWrite(dir2,HIGH);
      for(int x = 0; x < qm2; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      //delay(1000);
      //Top Left
      digitalWrite(dir2,HIGH);
      for(int x = 0; x < qm2; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      //delay(1000);
      //Bottom Right
      digitalWrite(dir2,LOW);
      for(int x = 0; x < qm2; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      //Now puttin piece back
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(queloc);
      digitalWrite(magnet,LOW);

      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(queloc);

      break;/*
      digitalWrite(magnet,HIGH);
      //Second piece is the Rook which is placed on the end of Horizontal Right
      //From here is getting the piece
      int rookloc=600;
      //Right Move6ment
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(rookloc);
      //Left Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(rookloc);
      //From here on it's the movement of Rook
      int rm=500;
      //First is Horizontal Right
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(rm);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(rm);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(rm);
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(rm);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(rm);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(rm);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(rm);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(rm);
      //This is the end of movement of Rook now putting it back in it's initial position
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(rookloc);
      digitalWrite(magnet,LOW);
      //Left Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(rookloc);

      break;*/

    }
    case 6:
    {
      //Last is Kinng
      digitalWrite(magnet,HIGH);
      //King is placed at top left
      int kingloc=600;
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(kingloc);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(kingloc);
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(kingloc);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(kingloc);
      //Main movement
      //Now the First move is horizontal and veritical ie Rook
      //First is Horizontal Right
      int km=200;
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(km);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(km);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(km);
      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(km);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(km);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(km);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(km);
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(km);
      //Next is Bishop Movement
      int km2=300;
      //Top Right
      digitalWrite(dir1,LOW);
      for(int x = 0; x < km2; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      //delay(1000);
      //Bottom Left
      digitalWrite(dir1,HIGH);
      for(int x = 0; x < km2; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      delay(1000);
      //Bottom Left
      digitalWrite(dir1,HIGH);
      for(int x = 0; x < km2; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      //delay(1000);
      //Top Right
      digitalWrite(dir1,LOW);
      for(int x = 0; x < km2; x++) {
        digitalWrite(step1,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        delayMicroseconds(1000); 
      }
      //Bottom Right
      digitalWrite(dir2,LOW);
      for(int x = 0; x < km2; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      //delay(1000);
      //Top Left
      digitalWrite(dir2,HIGH);
      for(int x = 0; x < km2; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      //delay(1000);
      //Top Left
      digitalWrite(dir2,HIGH);
      for(int x = 0; x < km2; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      //delay(1000);
      //Bottom Right
      digitalWrite(dir2,LOW);
      for(int x = 0; x < km2; x++) {
        digitalWrite(step2,HIGH);
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step2,LOW);
        delayMicroseconds(1000); 
      }
      //Putting piece back
      //Top Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      move(kingloc);
      //Left Movement
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      move(kingloc);

      digitalWrite(magnet,LOW);

      //Right Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      move(kingloc);
      //Bottom Movement
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      move(kingloc);

      break;
    }
    default:
    {
      break;
    }
  }
}
}

void move(int l)
{
  for(int x = 0; x < l; x++) {
        digitalWrite(step1,HIGH);
        digitalWrite(step2,LOW); 
        delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(step1,LOW);
        digitalWrite(step2,HIGH); 
        delayMicroseconds(1000); 
      }
      //delay(300);
}
