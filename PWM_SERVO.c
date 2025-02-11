#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22          // GPIO 22 para o servo
#define LED_PIN 12            // GPIO 12 para o LED RGB
#define DIV 100.0             // Divisor de Clock
#define WRAP 24999            // Variável WRAP - Número de Contagem / Ciclo
#define DELAY_MS 5000         // Tempo de espera entre mudanças de posição

// Posições do servo
uint16_t pos_0 = 625;    // 500 µs
uint16_t pos_90 = 1838;  // 1.470 µs
uint16_t pos_180 = 3000; // 2.400 µs

// Função para configurar o PWM
void pwm_setup(uint gpio_pin, uint16_t wrap_value, float clkdiv) {
    gpio_set_function(gpio_pin, GPIO_FUNC_PWM);  // Configura o pino para PWM
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin);  // Obtém o slice associado ao pino
    pwm_set_clkdiv(slice_num, clkdiv);  // Define o divisor de clock
    pwm_set_wrap(slice_num, wrap_value);  // Define o valor de wrap
    pwm_set_enabled(slice_num, true);  // Habilita o PWM
}

// Função para definir a posição do servo
void set_servo_position(uint gpio_pin, uint16_t position) {
    pwm_set_gpio_level(gpio_pin, position);
}

int main() {

    stdio_init_all();
       
    pwm_setup(SERVO_PIN, WRAP, DIV);  // Configura PWM SERVO
    pwm_setup(LED_PIN, WRAP, DIV);    // Configura PWM LED

    // Movimentação inicial (executa uma vez)
    set_servo_position(SERVO_PIN, pos_180);  // Posição 180°
    pwm_set_gpio_level(LED_PIN, pos_180);    // LED mais Intenso
    sleep_ms(5000);

    set_servo_position(SERVO_PIN, pos_90);   // Posição 90°
    pwm_set_gpio_level(LED_PIN, pos_90);     // LED Médio
    sleep_ms(5000);

    set_servo_position(SERVO_PIN, pos_0);    // Posição 0°
    pwm_set_gpio_level(LED_PIN, pos_0);      // LED quase apagado
    sleep_ms(5000);

    // Movimentação constante (laço infinito)
    while (true) {
        // Movimentação suave de 0° a 180°
        for (uint16_t i = pos_0; i <= pos_180; i += 5) {
            set_servo_position(SERVO_PIN, i);
            pwm_set_gpio_level(LED_PIN, i); 
            sleep_ms(10);
        }

        // Movimentação suave de 180° a 0°
        for (uint16_t i = pos_180; i >= pos_0; i -= 5) {
            set_servo_position(SERVO_PIN, i);
            pwm_set_gpio_level(LED_PIN, i);  
            sleep_ms(10);
        }
    }
}
