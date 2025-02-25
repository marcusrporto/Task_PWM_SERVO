﻿# Task_PWM_SERVO

  Com o emprego do módulo PWM (do inglês, Pulse Width Modulation),
presente no microcontrolador RP2040, projete um sistema com a
ferramenta Pico SDK para simular o controle do ângulo de um
servomotor. Esta simulação contemplará o motor micro servo
padrão, presente no simulador de eletrônica online Wokwi. Para
condução desta prática, será necessário simular os componentes
listados abaixo. A configuração sugerida está presente na Figura 1.
1) Microcontrolador Raspberry Pi Pico W.
2) Servomotor – motor micro servo padrão – Wokwi.

 ![image](https://github.com/user-attachments/assets/132702ff-a2fc-4c6a-903a-095eea5b5934)
Figura 1

# Os requisitos para a realização desta atividade são:

1) Considerando a GPIO 22, defina a sua frequência de PWM para,
aproximadamente, 50Hz – período de 20ms. 
2) Defina o ciclo ativo do módulo PWM para 2.400µs
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto
ajustará a flange (braço) do servomotor para a posição de,
aproximadamente, 180 graus. Aguarde 05 segundos nesta
posição. Figura abaixo.
4) Defina o ciclo ativo do módulo PWM para 1.470µs
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%.
Isto ajustará a flange do servomotor para a posição de,
aproximadamente, 90 graus. Aguarde 05 segundos nesta
posição. Figura abaixo.
5) Defina o ciclo ativo do módulo PWM para 500µs
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%.
Isto ajustará a flange do servomotor para a posição de,
aproximadamente, 0 graus. Aguarde 05 segundos nesta
posição. Figura abaixo.
7) Após a realização das proposições anteriores, crie uma rotina
para movimentação periódica do braço do servomotor entre os
ângulos de 0 e 180 graus. Obs.: a movimentação da flange deve
ser suave, recomenda-se o incremento de ciclo ativo de ±5µs,
com um atraso de ajuste de 10ms. 
8) Com o emprego da Ferramenta Educacional BitDogLab, foi feito
um experimento com o código deste exercício utilizando o LED
RGB – GPIO 12. O que o discente observou no comportamento
da iluminação do referido LED?

O LED começa com brilho alto/moderado na posição 180º, onde o Duty Cycle é maior e consequentemente a tensão tende a ser maior. Alterna para a posção 90º depois de 5s e tem sua luminosidade reduzida. Na posição 0º, Ele tem a intensidade mais baixa. Porém, quando entra no loop de alternância entre 0 e 180, oscila mais lentamente, mas é possivel ver o efeito fading.  
Link Vídeo:

https://drive.google.com/file/d/1zgLPiVS4UmYZe42XP-1zWleuptvLqVTd/view?usp=sharing
