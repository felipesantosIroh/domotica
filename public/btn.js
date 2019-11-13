 $("#luzSala").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if ($(this).hasClass("btn-warning"))
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
    if ($(this).hasClass("btn-warning"))
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
    if ($(this).hasClass("btn-warning"))
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
    if ($(this).hasClass("btn-warning"))
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
    if ($(this).hasClass("btn-warning"))
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
    if ($(this).hasClass("btn-warning"))
        $(this).addClass("btn-success").removeClass("btn-warning");
    else
        $(this).addClass("btn-warning").removeClass("btn-success");
 });