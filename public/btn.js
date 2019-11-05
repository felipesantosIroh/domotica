 $("#luzSala").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
 });

 $("#luzQuarto").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
 });

 $("#luzCozinha").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
 });

 $("#luzGaragem").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
 });

 $("#luzBanheiro").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
 });

 $("#luzCorredor").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
 });