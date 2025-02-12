# Controle de Servo Motor com Raspberry Pi Pico

Este projeto demonstra o controle de um servo motor utilizando um Raspberry Pi Pico. O código configura o PWM no GPIO 22 para movimentar o servo entre 0° e 180°, realizando movimentos suaves.

## Características do Código
- Utiliza a biblioteca `pico/stdlib.h` para configurações básicas.
- Emprega `hardware/pwm.h` para controle do PWM.
- Define um ciclo de movimentação do servo entre 0° e 180°.
- Utiliza `sleep_ms()` para controlar o tempo de espera entre as posições do servo.

## Especificações do PWM
- **Frequência:** 50 Hz (período de 20 ms)
- **Ciclo de trabalho mínimo:** 500 µs (0°)
- **Ciclo de trabalho médio:** 1.470 µs (90°)
- **Ciclo de trabalho máximo:** 2.400 µs (180°)

## Como Usar
1. Clone este repositório:
   ```sh
   git clone <URL_DO_REPOSITORIO>
   ```
2. Compile e carregue o código no Raspberry Pi Pico utilizando o SDK do Raspberry Pi.
3. Conecte um servo motor ao GPIO 22 e observe a movimentação automática entre 0° e 180°.

## Simulação Online
Este projeto pode ser testado no Wokwi:

[🔗 Simular no Wokwi](https://wokwi.com/projects/422643555843130369)

## Vídeo explicativo
https://youtu.be/bGhRAPiqI2c

## Licença
Este projeto está disponível sob a licença MIT. Sinta-se à vontade para modificar e compartilhar!

