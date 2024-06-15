#include <esphome.h>

namespace WritePinValue {
    
    const int HOUR_LOOKUP[] ={0,1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11};
    const int HOUR_NEEDLE[] ={234,12,34,54,74,94,113,132,152,172,191,211,234,12,34,54,74,94,113,132,152,172,191,211};
    const int SECOND_NEEDLE[] ={10,13,15,18,22,25,28,31,35,39,42,46,50,53,56,60,64,67,70,73,77,81,84,88,91,95,97,100,104,107,110,113,116,119,123,126,129,132,135,138,141,144,147,151,155,158,161,164,167,171,174,177,181,184,188,191,195,200,204,208,212};
    const int MINUTE_NEEDLE[] ={14,17,20,23,26,30,34,37,41,45,48,52,56,60,64,66,70,74,78,82,84,89,92,95,98,103,107,110,113,116,120,124,127,130,133,137,141,144,147,150,154,158,161,164,167,171,174,177,180,183,186,191,194,197,201,206,210,214,218,221,225};

    void HourHandle(int pin, time_t hour) {  
        char str[30];
        char tm[30];
        time_t currTime = id(esptime).now().timestamp;
        strftime(str, sizeof(str), "%H", localtime(&currTime));
        strftime(tm, sizeof(tm), "%Y-%m-%d %X", localtime(&currTime));

         if (HOUR_LOOKUP[hour] == 1){
          
          for (size_t i = id(MAXIMUM_PWM_VALUE_HR); i < id(MINIMUM_PWM_VALUE_HR); i--)
          {
            analogWrite( pin, i);
            delay(50);
          }
                };
        
        if(id(AVERAGE)){
          analogWrite( pin, map(HOUR_LOOKUP[hour], 0, 12, id(MINIMUM_PWM_VALUE_HR), id(MAXIMUM_PWM_VALUE_HR)));
          if(id(DEBUG_ON)){
          ESP_LOGD("custom", "Average Hour");
          ESP_LOGD("custom", "Current Time: %s", tm);  
          ESP_LOGD("custom", "Current Hour: %s", str);
          ESP_LOGD("custom", "Current Hour lookup: %d", HOUR_LOOKUP[hour]);   
          ESP_LOGD("custom", "Current Hour needle lookup: %d", map(HOUR_LOOKUP[hour], 0, 12, id(MINIMUM_PWM_VALUE_HR), id(MAXIMUM_PWM_VALUE_HR)));   
          }
        }
        else{
          analogWrite( pin, HOUR_NEEDLE[HOUR_LOOKUP[hour]]);
          if(id(DEBUG_ON)){
          ESP_LOGD("custom", "Current Hour: %s", str);
          ESP_LOGD("custom", "Current Hour lookup: %d", HOUR_LOOKUP[hour]);   
          ESP_LOGD("custom", "Current Hour needle lookup: %d", HOUR_NEEDLE[HOUR_LOOKUP[hour]]);   
          }
        }
        
    }

    void MinuteHandle(int pin, time_t minute) {       
        char str[30];
        time_t currTime = id(esptime).now().timestamp;
        strftime(str, sizeof(str), "%M", localtime(&currTime));
        
        if (minute == 0){
             for (size_t i = id(MAXIMUM_PWM_VALUE_MIN); i < id(MINIMUM_PWM_VALUE_MIN); i--)
          {
            analogWrite( pin, i);
            delay(50);
          }
                };

        if(id(AVERAGE)){ 
          analogWrite( pin, map(minute, 0, 60, id(MINIMUM_PWM_VALUE_MIN), id(MAXIMUM_PWM_VALUE_MIN)));
          if(id(DEBUG_ON)){
          ESP_LOGD("custom", "Average Minute"); 
          ESP_LOGD("custom", "Current Minute: %s", str);  
          ESP_LOGD("custom", "Current Minute value: %d", map(minute, 0, 60, id(MINIMUM_PWM_VALUE_MIN), id(MAXIMUM_PWM_VALUE_MIN)));
          }
        }
        else{
          analogWrite( pin, MINUTE_NEEDLE[minute]);
          if(id(DEBUG_ON)){
          ESP_LOGD("custom", "Current Minute: %s", str);  
          ESP_LOGD("custom", "Current Minute value: %d",MINUTE_NEEDLE[minute]);
          }
        }
    }

    void SecondHandle(int pin, time_t second) { 
        char str[30];
        time_t currTime = id(esptime).now().timestamp;
        strftime(str, sizeof(str), "%S", localtime(&currTime));
        if (second == 0){
         for (size_t i = id(MAXIMUM_PWM_VALUE_SEC); i < id(MINIMUM_PWM_VALUE_SEC); i--)
          {
            delay(8);
            analogWrite( pin, i);
            delay(8);
          }
                };
        
        if(id(AVERAGE)){
          analogWrite( pin, map(second, 0, 60, id(MINIMUM_PWM_VALUE_SEC), id(MAXIMUM_PWM_VALUE_SEC)));
           if(id(DEBUG_SECOND_ON)){      
          ESP_LOGD("custom", "Average Second");
          ESP_LOGD("custom", "Current Second: %s", str);  
          ESP_LOGD("custom", "Current Second value: %d",map(second, 0, 60, id(MINIMUM_PWM_VALUE_SEC), id(MAXIMUM_PWM_VALUE_SEC)));
          }
        }
        else{
          analogWrite( pin, SECOND_NEEDLE[second]);
          if(id(DEBUG_SECOND_ON)){
          ESP_LOGD("custom", "Current Second: %s", str);  
          ESP_LOGD("custom", "Current Second value: %d",SECOND_NEEDLE[second]);
          }
        }
    }


}