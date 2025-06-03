# 💈 Barbeiro Sonolento (Sleeping Barber Problem)

Este projeto implementa o clássico problema da Barbeiro Sonolento utilizando C, pthreads e semáforos POSIX. O objetivo é simular o funcionamento de uma barbearia com número limitado de cadeiras, controlando a concorrência entre múltiplas threads de clientes e um barbeiro.

## 👥 Alunos

- Guilherme Miranda de Araújo (2021019643)
- Luiz Gustavo Dall'Agnol Cavalcante (2021000632)

## 🧠 Conceito

- 1 barbeiro
- Várias threads de clientes
- Sala de espera com número limitado de cadeiras
- Uso de semáforos para controle de sincronização

O barbeiro dorme quando não há clientes, e acorda quando um cliente chega. Se a sala estiver cheia, o cliente vai embora.

## 🛠️ Tecnologias

- Linguagem C
- POSIX Threads (pthreads)
- Semáforos (sem_t)
- Compilador: GCC

## 📁 Estrutura

- `main.c` → Código-fonte principal
- `README.md` → Documentação básica
- `Slide.pdf` → Apresentação de slides

## ▶️ Como compilar e executar

1. Compile o código com suporte a pthread:

```bash
gcc -pthread main.c -o main
```

2. Execute o programa:

```bash
./main
```

3. Para interromper a execução (infinita), use:

```bash
Ctrl + C
```

## ⚙️ Configurações

- O número de cadeiras é definido pela constante `CHAIRS` no início do código.
- Os clientes chegam a cada 1 segundo (modificável no `sleep(1)`).
- O barbeiro leva 3 segundos para cortar o cabelo (`cut_hair()`).