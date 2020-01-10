# FPGALOACUFCG

Esta versão do simulador roda no navegador e funciona da seguinte maneira:
1. O usuário clica no botão pra compilar o código.
2. O código é enviado pro Backend.
3. O Backend compila seu código, gerando todas os estados da interface para todas as combinações possíveis dos botões. Isso dá 2^8 combinações.
4. Apenas os estados são enviados de volta pro Frontend, em texto plano.
5. Para qualquer combinação dos botões, o Frontend vai reagir de acordo com as combinações recebidas do Backend.

*Obs 1: Esta foi a primeira versão do simulador, eu ainda não tinha estudado os flip-flops, então eu descobri logo em seguida que apenas o `always_comb` funcionava! Não dava mais pra computar todas as combinações, agora temos o tempo envolvido :(

*Obs 2: Se alguém quiser fazer uma versão que funcione de verdade pra navegador, existem duas abordagens (e outras que eu não pensei) que deixariam possível:

  - Compilar o código do usuário e deixar ele rodando durante a sessão. Neste caso teria um ou mais códigos rodando simultaneamente para cada usuário acessando.
  - Dar um jeito de rodar System Verilog no navegador. O verilator não faz isso :(

O projeto continua em: https://github.com/Icaro-Lima/LabarcFPGASimulatorDesktop
