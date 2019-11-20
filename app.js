//Bibliotecas
const SerialPort = require('serialport');
const express = require('express');
const socketIo = require('socket.io');
const http = require('http');

//Server
const app = express();
const server = http.createServer(app);

app.use(express.static('public')); //Adiciona os arquivos estaticos

app.get('/' , (req, res, next) =>{
    res.sendFile(__dirname + '/public/index.html')
});

server.listen(3000, () => {
    console.log('Porta 10.34.139.149:%d', server.address().port);
});

const io = socketIo.listen(server);

//Configuração de serial
const Readline = SerialPort.parsers.Readline;
const parser = new Readline({delimiter: '\n'});
const mySerial = new SerialPort("COM5", {
    baudRate: 9600,
});

mySerial.pipe(parser);

//recebendo dados do serial e passando para a web
mySerial.on('open', function(){
    console.log("Conexão iniciada");
    parser.on('data', function (data){
        console.log(data);
        io.emit('serial:data', {
            value: data.toString()
        });
    });
});

//recebendo dados da web e passando para a serial
io.sockets.on('connection', function(socket){
    console.log('Um novo no foi conectado');

    socket.on('btnAction', function(btn){
        var dado_web = btn.value;
        console.log(dado_web);
        mySerial.write(dado_web);
        console.log('Enviando " ' + dado_web + ' " para serial');
    });
});