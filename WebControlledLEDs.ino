
 


#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include "FastLED.h"

#define NUM_LEDS 48
CRGB leds[NUM_LEDS];
#define DATA_PIN 1
#define CHIPSET     WS2812
#define COLOR_ORDER GRB



//SETTINGS
String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
int l_brightness = 70;
int l_red = 100;
int l_green = 100;
int l_blue = 0;
String l_status = "OFF";


String request = "";
int LED_Pin = D1;
String effect = "null";

int counterSet = 0;
int counter = 0;


// change these values to match your network
char ssid[] = "TTU Res Halls";       //  your network SSID (name)
char pass[] = "scarletandblack";          //  your network password
 
WiFiServer server(80);

 

//String isOn = "false";




void setup() 
{
    //pinMode(LED_Pin, OUTPUT);     
    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    Serial.begin(115200);
    Serial.println();
    Serial.println("Serial started at 115200");
    Serial.println("WebControlledLEDs starting...");
    Serial.println();
    //pinMode(ledPin, OUTPUT);
     // digitalWrite(ledPin, LOW);
    // Connect to a WiFi network
    Serial.print(F("Connecting to "));  Serial.println(ssid);
    WiFi.begin(ssid, pass);
    for(int i=0; i<NUM_LEDS; i++){
                  leds[i] = CRGB( 0, 0, 0);
                  FastLED.show();
                }  
 
    while (WiFi.status() != WL_CONNECTED) 
    {
        Serial.print(".");
        delay(5000);
    }
      
    Serial.println("");
    Serial.println(F("[CONNECTED]"));
    Serial.print("[IP ");              
    Serial.print(WiFi.localIP()); 
    Serial.println("]");

    if (!MDNS.begin("esp8266"))   {  Serial.println("Error setting up MDNS responder!");  }
      else                          {  Serial.println("mDNS responder started");  }
 
 

    server.begin();
    Serial.println("Server started");
 
} 
 
 
 
void loop() 
{
    // Check if a client has connected

  if(counter >= 1){
     counter--;
    }
    
    WiFiClient client = server.available();
//     if (client)  { 
//      effect = "null";
//      }
//    
    if (!client)  { 
      if(effect != "null"){
        if(effect == "rainbow"){
          rainbowCycle(20);
          } 
      }
      else{
        return;
        }
      }
 
    // Read the first line of the request
    
    //Serial.print("TEST: "); Serial.println(request.substring(6,10));

  request = client.readStringUntil('\r');

    Serial.print("request: "); Serial.println(request); 
    if       ( request.indexOf("LEDON") > 0 )  
             { 
//                digitalWrite(LED_Pin, HIGH);  
                for(int i=0; i<NUM_LEDS; i++){
                  leds[i] = CRGB( l_red, l_green, l_blue);
                  FastLED.setBrightness(l_brightness);
                  FastLED.show();
                }
                effect = "null";
                l_status = "ON";
                client.print( header );
                client.print( "LED is on" );             
             }
    else if  ( request.indexOf("LEDOFF") > 0 ) 
             { 
                //digitalWrite(LED_Pin, LOW);
                for(int i=0; i<NUM_LEDS; i++){
                  FastLED.setBrightness(l_brightness);
                  leds[i] = CRGB::Black;
                  FastLED.show();
                }   
                effect = "null";
                l_status = "OFF";
                client.print( header );
                client.print( "LED is off" ); 
             }

        else if  ( request.substring(5,11) =="Bright"  ) 
             { 
              int raw_bright = (request.substring(12,15)).toInt();
              int pro_bright = map(raw_bright, 100, 355, 0, 255);
              
                //digitalWrite(LED_Pin, LOW);
                //for(int i=0; i<NUM_LEDS; i++){
                l_brightness = pro_bright;
                  FastLED.setBrightness(l_brightness);
                 // leds[i] = CRGB::Green;
                  FastLED.show();
                //}   
                effect = "null";
                client.print( header );
                client.print( pro_bright ); 
                counter = counterSet;
                //delay(50);
             }


          else if  ( request.substring(5,8) =="Red"  ) 
             { 
              int raw_level = (request.substring(9,12)).toInt();
              int pro_level = map(raw_level, 100, 355, 0, 255);
              l_red = pro_level;
              for(int i=0; i<NUM_LEDS; i++){
                  leds[i] = CRGB( l_red, l_green, l_blue);
                  FastLED.setBrightness(l_brightness);
                  FastLED.show();
                }   
              effect = "null";
              client.print( header );
              client.print( pro_level ); 
              counter = counterSet;
              //delay(50);
             }
             
          else if  ( request.substring(5,9) =="Blue"  ) 
             { 
              int raw_level = (request.substring(10,13)).toInt();
              int pro_level = map(raw_level, 100, 355, 0, 255);
              l_blue = pro_level;
              for(int i=0; i<NUM_LEDS; i++){
                  leds[i] = CRGB( l_red, l_green, l_blue);
                  FastLED.setBrightness(l_brightness);
                  FastLED.show();
                }   
              effect = "null";
              client.print( header );
              client.print( pro_level ); 
              counter = counterSet;
             // delay(50);
             }


           else if  ( request.substring(5,10) =="Green"  ) 
             { 
              int raw_level = (request.substring(11,14)).toInt();
              int pro_level = map(raw_level, 100, 355, 0, 255);
              l_green = pro_level;
              for(int i=0; i<NUM_LEDS; i++){
                  leds[i] = CRGB( l_red, l_green, l_blue);
                  FastLED.setBrightness(l_brightness);
                  FastLED.show();
                }   
              effect = "null";
              client.print( header );
              client.print( pro_level ); 
              counter = counterSet;
              //delay(50);
             }  

             

           else if  ( request.substring(5,12) =="Rainbow"  ) 
             { 
              effect = "rainbow";
              client.print( header );
              client.print( "Rainbow Effect" ); 
             }  


            

  else if  ( request.substring(6,10) =="HTTP" ) {
     client.flush();
        client.print( header );
        String rawHtml= htmlGet();
//        int l_red = 100;
//        int l_green = 100;
//        int l_blue = 100;
//map(raw_level, 100, 355, 0, 255);
//<input type="button" id = "LED_button" onclick="switchLED()" value="OFF" class=""  /> 
        int m_bright = map(l_brightness, 0, 255, 100, 355);
        int m_red = map(l_red, 0, 255, 100, 355);
        int m_green = map(l_green, 0, 255, 100, 355);
        int m_blue = map(l_blue, 0, 255, 100, 355);
        

        rawHtml.replace("<input type='button' id = 'LED_button' onclick='switchLED()' value='OFF' class=''  /> ","<input type='button' id = 'LED_button' onclick='switchLED()' value='"+l_status+"' class=''  /> ");
        rawHtml.replace( "<input type='range' id='sliderBrightness' name='Bright_Slider' min='100' max='355' value='250' style='width: 60vw' oninput='changeBrightness(this.value)'>" , "<input type='range' id='sliderBrightness' name='Bright_Slider' min='100' max='355' value='"+String(m_bright)+"' style='width: 60vw' oninput='changeBrightness(this.value)'>" ); 
        rawHtml.replace( "<input type='range' id='Red_Slider' name='Red_Slider' min='100' max='355' value='250' style='width: 60vw' oninput='changeRed(this.value)'>" , "<input type='range' id='Red_Slider' name='Red_Slider' min='100' max='355' value='"+String(m_red)+"' style='width: 60vw' oninput='changeRed(this.value)'>" ); 
        rawHtml.replace( "<input type='range' id='Green_Slider' name='Green_Slider' min='100' max='355' value='250' style='width: 60vw' oninput='changeGreen(this.value)'>" , "<input type='range' id='Green_Slider' name='Green_Slider' min='100' max='355' value='"+String(m_green)+"' style='width: 60vw' oninput='changeGreen(this.value)'>" ); 
        rawHtml.replace( "<input type='range' id='Blue_Slider' name='Blue_Slider' min='100' max='355' value='250' style='width: 60vw' oninput='changeBlue(this.value)'>" , "<input type='range' id='Blue_Slider' name='Blue_Slider' min='100' max='355' value='"+String(m_blue)+"' style='width: 60vw' oninput='changeBlue(this.value)'>" ); 
        client.print( rawHtml );    
        delay(5);
    }

    else
    {
//        client.flush();
//        client.print( header );
//        client.print( html_1 );    
//        delay(5);
    }
 
 
 
  
  // The client will actually be disconnected when the function returns and 'client' object is detroyed
} // void loop()


void setColorRGB(byte r, byte g, byte b) {
  // create a new RGB color
  CRGB color = CRGB(r, g, b);

  // use FastLED to set the color of all LEDs in the strip to the same color
  fill_solid(leds, NUM_LEDS, color);
}


void rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< NUM_LEDS; i++) {
      c=Wheel(((i * 256 / NUM_LEDS) + j) & 255);
      setPixel(i, *c, *(c+1), *(c+2));        
    }
    showStrip();
    WiFiClient client = server.available();
    
      if(client) {
        Serial.println("Test");
        request = client.readStringUntil('\r');
        if  ( request.substring(5,12) =="Rainbow"  || request.substring(6,10) =="HTTP") 
             { 
              Serial.println("RAINBOW BREAK");
              effect = "null";
              
              if(l_status=="ON"){
                for(int i=0; i<NUM_LEDS; i++){
                   leds[i] = CRGB( l_red, l_green, l_blue);
                   FastLED.setBrightness(l_brightness);
                   FastLED.show();
                }   
              }
              if(l_status=="OFF"){
                for(int i=0; i<NUM_LEDS; i++){
                   leds[i] = CRGB( l_red, l_green, l_blue);
                   FastLED.setBrightness(0);
                   FastLED.show();
                } 
                }

              //loop();
             // continue;
//              break;
//              //i = NUM_LEDS;
//              //j = 1280;
              }
        }
    delay(SpeedDelay);
  }
}

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

byte * Wheel(byte WheelPos) {
  static byte c[3];
  
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  return c;
}









