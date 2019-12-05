const socketzinho = io();
var arr;
var pir;
var contador = 0;
var tempDHT22;
var tempDHT11;
var guardaTemp22;
var guardaTemp11;

socketzinho.on('serial:data', function(dataSerial){
    console.log(dataSerial);
    arr = dataSerial.value.split(" ");
    console.log(arr);
    pir = arr[2];
    console.log(pir);
    if(pir == 1){ 
        alert("Sensor detectou presença!");
        $('.alert').alert()
        $('#pirCard').text('MOVIMENTO DETECTADO!!!');
        $("#pirCard").addClass("alert-danger").removeClas("alert-success");
    }
    
    arr[0] = arr[0].substring(1);
    tempDHT22 = arr[0];
    tempDHT11 = arr[1];

    //guarda a primeira leitura
    var i = 1;
    if(i == 1){
        guardaTemp22 = tempDHT22;
        guardaTemp11 = tempDHT11;
        i = 0;
    }

    contador = contador + 2;

    const call = io();
    if(tempDHT22 > 54){
        alert("Temperatura muito alta, risco de incendio!");
        $('.alert').alert()
        $('#temp22Card').text('Temperatura ALTA!! ALERTA!');
        $("#temp22Card").addClass("alert-danger").removeClas("alert-success");
    }

    if(tempDHT11 > 54){
        alert("Temperatura muito alta, risco de incendio!");
        $('.alert').alert()
        $('#temp11Card').text('Temperatura ALTA!! ALERTA!');
        $("#temp11Card").addClass("alert-danger").removeClas("alert-success");
    }

    if(contador >= 30){
        if((tempDHT22 - guardaTemp22) > 5){
            alert("Temperatura aumetou drasticamente, risco de incendio!");
            $('.alert').alert()
            $('#temp22Card').text('Temperatura ALTA!! ALERTA!');
            $("#temp22Card").addClass("alert-danger").removeClas("alert-success");
        }
        contador = 0;
    }
    
    if(contador >= 30){
        if((tempDHT11 - guardaTemp11) > 5){
            alert("Temperatura aumetou drasticamente, risco de incendio!");
            $('.alert').alert()
            $('#temp11Card').text('Temperatura ALTA!! ALERTA!');
            $("#temp11Card").addClass("alert-danger").removeClas("alert-success");
            contador = 0;
        }
    }
});

