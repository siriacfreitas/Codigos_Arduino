# 🔠 Tradutor de Código Morse com Arduino

Este projeto converte palavras digitadas via **monitor serial** em **código Morse**, reproduzido com **LEDs** e um **buzzer**. O sistema aguarda o clique de um botão antes de iniciar a leitura da palavra e, em seguida, emite o código Morse correspondente a cada caractere.

## 📦 Funcionalidades

* ✍️ Leitura de uma palavra via porta serial.
* ⏳ Ativação por botão físico (debounce simples com lógica).
* 💡 LEDs piscando para representar pontos (.) e traços (-) do código Morse.
* 🔊 Sinais sonoros para cada ponto e traço via buzzer.
* 🔁 Possibilidade de digitar novas palavras após o término da tradução.

## 🧰 Componentes Utilizados

| Componente       | Pino Arduino | Função                    |
| ---------------- | ------------ | ------------------------- |
| Botão            | 10           | Inicia leitura da palavra |
| LED 1            | 8            | Representa ponto/traço    |
| LED 2            | 9            | Representa traço          |
| LED interno (13) | 13           | Indica botão pressionado  |
| Buzzer           | 11           | Som para ponto/traço      |

## 🚀 Como Funciona

1. Ao iniciar o código, o Arduino imprime no monitor serial: `Digite uma palavra:`
2. O sistema fica esperando o usuário pressionar o botão.
3. Após o botão ser pressionado e liberado (debounce com `btnclick` e `btnfree`), a próxima entrada serial é lida.
4. Cada letra da palavra digitada é convertida para código Morse.
5. Para cada caractere:

   * `.` gera um **piscar curto** no LED1 e som rápido.
   * `-` gera um **piscar longo** nos LEDs 1 e 2 e som prolongado.
6. Ao final da palavra, o sistema solicita uma nova entrada.

## 📡 Exemplo de Funcionamento

**Entrada Serial:**

```
HELLO
```

**Saída no monitor serial (um caractere por linha):**

```
H
E
L
L
O
Digite outra palavra:
```

**Sinais Morse emitidos com LEDs e buzzer:**

```
H -> ....
E -> .
L -> .-..
L -> .-..
O -> ---
```

## 📋 Requisitos

* Placa Arduino (UNO, Mega, etc.)
* Arduino IDE
* Cabos jumpers
* Protoboard
* LEDs, botão e buzzer

## 🛠️ Instalação

1. Copie o código para a IDE do Arduino.
2. Faça as conexões conforme descrito na tabela de pinos.
3. Conecte a placa e selecione a porta correta.
4. Faça o upload.
5. Abra o monitor serial e defina **baudrate 9600**.
6. Pressione o botão e digite a palavra desejada!

## 🧠 Possíveis Melhorias

* Adicionar suporte a espaço entre palavras.
* Exibir visualmente o código Morse no serial (`.-`, `--`, etc.).
* Permitir uso contínuo do botão para envio de múltiplas palavras sem reiniciar o Arduino.
* Adicionar visualização com display LCD ou OLED.

## 📚 Sobre o Código Morse

O Código Morse é um sistema de codificação de texto onde cada letra ou número é representado por uma combinação única de pontos `.` e traços `-`.

---

Se quiser, posso gerar o `.md` formatado para colocar direto no GitHub. Quer que eu faça isso?
