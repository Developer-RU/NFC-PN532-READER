#include "nfc.h"

NFC_Module nfc;

int serNum0, serNum1, serNum2, serNum3, serNum4, serNum5, serNum6, serNum7;

int ch = 0;
String val = "";


void setup()
{
    Serial.begin(115200);
    nfc.begin();
    nfc.SAMConfiguration();
}

void loop(void)
{
    while(1)
    {                  
        u8 buf[16],sta;
        sta = nfc.InListPassiveTarget(buf);
            
        if(sta && buf[0] == 7)
        {
            if (buf[0] != serNum0 || buf[1] != serNum1 || buf[2] != serNum2 || buf[3] != serNum3 || buf[4] != serNum4 || buf[5] != serNum5 || buf[6] != serNum6 || buf[7] != serNum7)
            {
                serNum0 = buf[0];
                serNum1 = buf[1];
                serNum2 = buf[2];
                serNum3 = buf[3];
                serNum4 = buf[4];
                serNum5 = buf[5];
                serNum6 = buf[6];
                serNum7 = buf[7];

                Serial.print("UID: ");
                
                Serial.print(serNum0,DEC);
                Serial.print(serNum1,DEC);
                Serial.print(serNum2,DEC);
                Serial.print(serNum3,DEC);
                Serial.print(serNum4,DEC);
                Serial.print(serNum5,DEC);
                Serial.print(serNum6,DEC);
                Serial.println(serNum7,DEC);

                Serial.println("");
            }
        }
    }
}
