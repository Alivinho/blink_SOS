#include <stdio.h>
#include "pico/stdlib.h"


int main(){
    stdio_init_all();

    uint led_pin = 12;
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    while (true){
        for (int i = 0; i < 3; i++) {
            blinkPonto(led_pin);
        }

        // Intervalo entre "S" e "O"
        sleep_ms(250);

        // Envia o "O" (3 traços)
        for (int i = 0; i < 3; i++) {
            blinkTraco(led_pin);
        }

        // Intervalo entre "O" e o segundo "S"
        sleep_ms(250);

        // Envia o segundo "S" (3 pontos)
        for (int i = 0; i < 3; i++) {
            blinkPonto(led_pin);
        }

        sleep_ms(3000);

       
    }

    return 0; 
   
}

void blinkPonto(uint pino){
    gpio_put(pino, 1);  
    sleep_ms(200);     
    gpio_put(pino, 0);  
    sleep_ms(125); 
}

void blinkTraco(uint pino){
    gpio_put(pino, 1);  
    sleep_ms(800);     
    gpio_put(pino, 0);  
    sleep_ms(125); 
}
