/* 
 * Project classroom_ecosystem
 * Author: Ronald G. Romo
 * Date: 03/03/2026
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "Adafruit_GFX.h"
#include "neopixel.h" //
#include "Adafruit_SSD1306.h"//
#include "Adafruit_BME280.h"//
#include "IoTClassroom_CNM.h"//
#include "Encoder.h"//

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(DISABLED);


const int MYWEMO=2;
const int BME = 0x76;
const int PIXELCOUNT = 46;
const int OLED_RESET = -1;
const int DISP = 0X3C;
const int BRIGHTNESS = 100;
const int BUTTONPIN = D3;
const int PINA = D8;
const int PINB = D9;

bool status;
float tempF,fan,lava_lamp;

//objects
Adafruit_NeoPixel pixel(PIXELCOUNT, SPI1,WS2812B);
// proximitySensor();
Encoder blueThunder(PINA, PINB);
Button button(D3);
Adafruit_SSD1306 display(OLED_RESET); 
Adafruit_BME280 bme;

void pixelFill(int startPixel,int endPixel,int hex);

void setup() {
    //programing tool
    //turn on my serial monitor
    Serial.begin(9600);
    waitFor(Serial.isConnected,15000);
 
    //turn on my display
    display.begin(SSD1306_SWITCHCAPVCC, DISP);
    display.clearDisplay();//clears the screen and buffer

    //turn on my BME280
    status = bme.begin(BME);

    if(status == false){
      Serial.printf("bme failed to start");
     }else{
       Serial.printf("ready");
    }

    //turn on my neopixels
    pixel.begin();
    pixel.setBrightness(BRIGHTNESS);
}

void loop() {
    
}