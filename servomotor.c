#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definições
#define SERVO_PIN 22          // GPIO 22 para controle do servo
#define PWM_FREQ 50           // Frequência de 50 Hz (período de 20 ms)
#define CLOCK_DIV 64          // Divisor de clock para gerar 50 Hz
#define WRAP_VALUE 39062      // Valor de wrap para 50 Hz (25.000.000 / 50 / 64)

// Função para configurar o PWM
void setup_pwm(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM); // Configura o pino para função PWM
    uint slice_num = pwm_gpio_to_slice_num(pin); // Obtém o slice do PWM
    pwm_set_clkdiv_int_frac(slice_num, CLOCK_DIV, 0); // Define o divisor de clock
    pwm_set_wrap(slice_num, WRAP_VALUE);  // Define o valor de wrap
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(pin), 0); // Inicia com duty cycle 0
    pwm_set_enabled(slice_num, true);     // Habilita o PWM
}

// Função para definir o ciclo ativo (duty cycle) em microssegundos
void set_servo_position(uint pin, uint pulse_width_us) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    uint channel = pwm_gpio_to_channel(pin);
    uint16_t level = (pulse_width_us * WRAP_VALUE) / 20000; // Converte para nível PWM
    pwm_set_chan_level(slice_num, channel, level);
}

// Função principal
int main() {
    stdio_init_all(); // Inicializa a comunicação serial (para depuração)

    setup_pwm(SERVO_PIN); // Configura o PWM no pino do servo

    // 1) Posição de 180 graus (2.400 μs)
    set_servo_position(SERVO_PIN, 2400);
    sleep_ms(5000); // Aguarda 5 segundos

    // 2) Posição de 90 graus (1.470 μs)
    set_servo_position(SERVO_PIN, 1470);
    sleep_ms(5000); // Aguarda 5 segundos

    // 3) Posição de 0 graus (500 μs)
    set_servo_position(SERVO_PIN, 500);
    sleep_ms(5000); // Aguarda 5 segundos

    // 4) Movimentação periódica entre 0 e 180 graus em loop
    while (true) {
        // Movimento de 0° a 180°
        for (int pulse_width = 500; pulse_width <= 2400; pulse_width += 5) {
            set_servo_position(SERVO_PIN, pulse_width);
            sleep_ms(10); // Atraso de 10 ms para movimentação suave
        }

        // Movimento de 180° a 0°
        for (int pulse_width = 2400; pulse_width >= 500; pulse_width -= 5) {
            set_servo_position(SERVO_PIN, pulse_width);
            sleep_ms(10); // Atraso de 10 ms para movimentação suave
        }
    }

    return 0;
}