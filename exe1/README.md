# exe 1

![](func.gif)

O código fornecido configura a interrupção no pino do botão e, toda vez que ele for pressionado, imprime `fall` no terminal; e quando ele é solto, imprime `rise`. O código funciona, mas possui **um erro de qualidade de código!** Não devemos usar `printf` dentro de interrupções!
    
Modifique o código adicionando uma flag e realize o `printf` na função `main`. O comportamento deve ser o mesmo, mas a forma como lidaremos com o evento é diferente!

- Teste: Verifica se os dois LEDs mudam de estado.

### Dica

Não sabe o que tem que fazer? Leia a teoria em `RP2040/GPIO IRQ` especificamente a parte do *IRQ - Keep it short and simple*, se não ajudar tente [esta explicação link](https://www.techtarget.com/whatis/definition/IRQ-interrupt-request)
    
> [!WARNING]
> Nesse exercício você não pode fazer uso da func. `gpio_get`, deve conseguir resolver apenas com o uso de interrupção.
>
> Verificamos isso automaticamente no seu repositório do github!