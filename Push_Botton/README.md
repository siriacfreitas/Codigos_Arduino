# 🔘 Controle de LED com Botão (Debounce Simples)

Este projeto permite **alternar o estado de um LED** (liga/desliga) sempre que um **botão físico é pressionado e solto**. A lógica implementa uma forma básica de *debounce* via software para garantir que o LED só mude de estado **após um clique completo (pressionar e liberar)**.

## 📦 Funcionalidades

* Detecta a mudança de estado do botão (pressionado → liberado).
* Alterna entre ligar e desligar o LED a cada clique completo.
* Lógica simples de debounce com duas variáveis (`bntclicado` e `bntliberado`).

## 🧰 Componentes Utilizados

| Componente | Pino Arduino | Função                       |
| ---------- | ------------ | ---------------------------- |
| LED        | 5            | Saída digital (liga/desliga) |
| Botão      | 3            | Entrada digital              |

> 💡 *O botão deve estar conectado com um resistor de pull-down (ou usar o pull-up interno com ajustes no código).*

## 🧠 Lógica de Funcionamento

1. O botão é monitorado constantemente.
2. Quando o botão é **pressionado**, o programa registra `bntclicado = 1`.
3. Quando o botão é **solto**, ele registra `bntliberado = 1`.
4. Se ambos os eventos ocorreram (um clique completo), o LED alterna seu estado.
5. As variáveis são resetadas para aguardar o próximo clique.

## 🚀 Como Usar

1. Conecte um LED no pino digital 5, com resistor limitador (220–330Ω).
2. Conecte um botão no pino digital 3.
3. Faça upload do código para a placa Arduino.
4. Pressione e solte o botão — o LED alterna entre ligado e desligado a cada clique.

## 📋 Código Fonte

```cpp
int led = 5;
int bnt = 3;
int bntclicado = 0;
int bntliberado = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(bnt, INPUT);
}

void troca_led() {
  if (digitalRead(led)) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}

void bntestado() {
  if (bntclicado == 1 && bntliberado == 1) {
    bntclicado = 0;
    bntliberado = 0;
    troca_led();
  }
}

void loop() {
  if (digitalRead(bnt)) {
    bntclicado = 1;
    bntliberado = 0;
  } else {
    bntliberado = 1;
  }
  bntestado();
}
```

## 🛠️ Possíveis Melhorias

* Usar `INPUT_PULLUP` e lógica invertida para eliminar o resistor externo.
* Implementar debounce com `millis()` para maior robustez.
* Adicionar feedback sonoro ou visual adicional (ex: buzzer ou display).

---
