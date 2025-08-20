# exe 4

![](func.gif)

> [!TIP]
> Note a diferença entre as boardas de subida e descida de cada botão.

Configure os botões com IRQs:

- Botão vermelho: Borda de descida (quando for pressionado)
- Botão verde: Borda de subida (quando for solto)

Toda vez que o botão vermelho for pressionado, inverta o estado do LED vermelho e toda vez que o botão verde for solto, inverta o estado do LED verde.

> [!WARNING]
> Nesse exercício você não pode fazer uso da func. `gpio_get`, deve conseguir resolver apenas com o uso de interrupção.
>
> Verificamos isso automaticamente no seu repositório do github!