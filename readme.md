# Arduino MQTT Client for Tago.io


**Descrição do Projeto**

Este projeto tem como objetivo criar uma solução de monitoramento do ambiente de uma adega para garantir a qualidade dos vinhos lá armazenados. Os dados coletados são enviados a cada 5 segundos para um servidor, para que o cliente possa acessar os dados a partir de um computador com acesso aos Dashboards do Tago.io.

**Requisitos**

- Placa Arduino compatível 
- Sensor de temperatura e umidade 
- Sensor de luminosidade 
- Acesso à plataforma Tago.io
- Bibliotecas Arduino necessárias: ArduinoJson, EspMQTTClient, DHT


**Configuração**

- Conecte os sensores de temperatura, umidade e luminosidade ao seu Arduino conforme necessário. Certifique-se de ajustar os pinos no código, se necessário.

- Crie uma conta no Tago.io em https://admin.tago.io/ se você ainda não tiver uma.

***No Tago.io:***

- Crie um dispositivo.
- Gere um token de acesso para autenticação e guarde para uso futuro
- Configure a integração MQTT com os tópicos desejados.
Abra o código Arduino e ajuste as seguintes configurações:

- Configurações de rede Wi-Fi (SSID e senha).
- Informações do servidor MQTT do Tago.io (endereço, usuário e token gerado anteriormente).


**Uso**

- Carregue o código no seu Arduino usando a IDE do Arduino ou a plataforma preferida.

- O Arduino começará a enviar dados para o servidor MQTT do Tago.io a cada 5 segundos.

***No Tago.io:***

- Crie um painel para visualizar os dados.
- Adicione widgets (nesse caso, gráficos de linha) para exibir os valores enviados pelo Arduino.

---------------------------------------------------------------


Nome dos componentes – 1ESPX - Hello World

Gabriel Pacheco – RM550191

Gustavo Veríssimo de Paulo Alves – RM551244

Maitê Savicius – RM98435

Murilo Henrique – RM99855