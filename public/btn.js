const socket = io();
var arr;
var a;
var b;
var c;
var d;
var e;
var f;

socket.on('serial:data', function(dataSerial){
    console.log(dataSerial);
    arr = dataSerial.value.split(" ");
        console.log(arr);
        a = arr[3];
        b = arr[4];
        c = arr[5];
        d = arr[6];
        e = arr[7];
        f = arr[8];
        if (a == 0)
            $("#luzSala").addClass("btn-warning").removeClass("btn-success");
        else
            $("#luzSala").addClass("btn-success").removeClass("btn-warning");
        
        if (b == 0)
            $("#luzQuarto").addClass("btn-warning").removeClass("btn-success");
        else
            $("#luzQuarto").addClass("btn-success").removeClass("btn-warning");

        if (c == 0)
            $("#luzCozinha").addClass("btn-warning").removeClass("btn-success");
        else
            $("#luzCozinha").addClass("btn-success").removeClass("btn-warning");

        if (d == 0)
            $("#luzGaragem").addClass("btn-warning").removeClass("btn-success");
        else
            $("#luzGaragem").addClass("btn-success").removeClass("btn-warning");

        if (e == 0)
            $("#luzBanheiro").addClass("btn-warning").removeClass("btn-success");
        else
            $("#luzBanheiro").addClass("btn-success").removeClass("btn-warning");

        if (f == 0)
            $("#luzCorredor").addClass("btn-warning").removeClass("btn-success");
        else
            $("#luzCorredor").addClass("btn-success").removeClass("btn-warning");
});

    

$("#luzSala").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if (a == 0)
        $(this).addClass("btn-success").removeClass("btn-warning");
    else
        $(this).addClass("btn-warning").removeClass("btn-success");
 });

 $("#luzQuarto").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if (b == 0)
        $(this).addClass("btn-success").removeClass("btn-warning");
    else
        $(this).addClass("btn-warning").removeClass("btn-success");    
 });

 $("#luzCozinha").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if (c == 0)
        $(this).addClass("btn-success").removeClass("btn-warning");
    else
        $(this).addClass("btn-warning").removeClass("btn-success");    
 });

 $("#luzGaragem").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if (d == 0)
        $(this).addClass("btn-success").removeClass("btn-warning");
    else
        $(this).addClass("btn-warning").removeClass("btn-success");
 });

 $("#luzBanheiro").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if (e == 0)
        $(this).addClass("btn-success").removeClass("btn-warning");
    else
        $(this).addClass("btn-warning").removeClass("btn-success");
 });

 $("#luzCorredor").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if (f == 0)
        $(this).addClass("btn-success").removeClass("btn-warning");
    else
        $(this).addClass("btn-warning").removeClass("btn-success");
 });