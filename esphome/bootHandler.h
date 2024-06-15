#include <esphome.h>


namespace BootAnimation {
    
      
    void animateMeter(uint8_t pin, uint8_t min, uint8_t max) {
          uint8_t v;
          for (v = min; v <= max; v++) {
            analogWrite(pin, v);
            delay(2);
          }
          delay(100);
          for (v = max; v >= min; v--) {
            analogWrite(pin, v);
            delay(2);
          }
          delay(100);
}


    void startSequence() {
      
      animateMeter(id(HOUR_PIN), id(MINIMUM_PWM_VALUE_HR), id(MAXIMUM_PWM_VALUE_HR));
      animateMeter(id(MINUTE_PIN), id(MINIMUM_PWM_VALUE_MIN), id(MAXIMUM_PWM_VALUE_MIN));
      animateMeter(id(SECOND_PIN), id(MINIMUM_PWM_VALUE_SEC), id(MAXIMUM_PWM_VALUE_SEC));
      
      analogWrite( id(HOUR_PIN), 0);
      analogWrite( id(MINUTE_PIN), 0);
      analogWrite( id(SECOND_PIN), 0);
    }

}